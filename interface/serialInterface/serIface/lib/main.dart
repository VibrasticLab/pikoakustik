import 'package:flutter/material.dart';
import 'dart:typed_data';
import 'dart:convert';
import 'dart:async';
import 'dart:math';
import 'package:usb_serial/usb_serial.dart';
import 'package:usb_serial/transaction.dart';
import 'package:flutter_plot/flutter_plot.dart';

void main() {
  runApp(MyApp());
}

class DataJSON {
  String tester;
  double ch0F0f, ch1F0f;
  List<dynamic> ch0F0r, ch1F0r;

  DataJSON(this.tester, this.ch0F0f, this.ch1F0f, this.ch0F0r, this.ch1F0r);

  DataJSON.fromJson(Map<String, dynamic> jsonIN)
      : tester = jsonIN['tester'],
        ch0F0f = jsonIN['ch_0']['freq_0']['freq'] * 400,
        ch0F0r = jsonIN['ch_0']['freq_0']['record'],
        ch1F0f = jsonIN['ch_1']['freq_0']['freq'] * 400,
        ch1F0r = jsonIN['ch_1']['freq_0']['record'];
}

class MyApp extends StatefulWidget {
  @override
  _MyAppState createState() => _MyAppState();
}

class _MyAppState extends State<MyApp> {
  UsbPort _port;
  String _status = "Idle";
  List<Widget> _ports = [];
  List<Widget> _serialData = [];
  StreamSubscription<String> _subscription;
  Transaction<String> _transaction;
  int _deviceId;
  TextEditingController _textController = TextEditingController();

  int _isGetJSON = 0;
  TextEditingController _textViewSaved = TextEditingController();
  var _dataJson;

  List<Point> _dataPlotL = [Point(0, 0)];
  List<Point> _dataPlotR = [Point(0, 0)];

  double _scaleToDB(double freq, int scale) {
    double spl;
    if (freq == 500) {
      spl = 34.15 +
          (0.09 * scale) +
          (0.93 * pow(scale, 2)) -
          (0.05 * pow(scale, 3));
    } else if (freq == 1000) {
      spl = 36.69 +
          (1.72 * scale) +
          (0.69 * pow(scale, 2)) -
          (0.04 * pow(scale, 3));
    } else if (freq == 2000) {
      spl = 37.22 -
          (1.58 * scale) +
          (1.15 * pow(scale, 2)) -
          (0.06 * pow(scale, 3));
    }

    return double.parse((spl).toStringAsFixed(2)); //2 decimals only
  }

  Future<bool> _connectTo(device) async {
    _serialData.clear();

    if (_subscription != null) {
      _subscription.cancel();
      _subscription = null;
    }

    if (_transaction != null) {
      _transaction.dispose();
      _transaction = null;
    }

    if (_port != null) {
      _port.close();
      _port = null;
    }

    if (device == null) {
      _deviceId = null;

      setState(() {
        _status = "Disconnected";
      });
      return true;
    }

    _port = await device.create();
    if (!await _port.open()) {
      setState(() {
        _status = "Open Failed";
      });
      return false;
    }

    _deviceId = device.deviceId;
    await _port.setDTR(false);
    await _port.setRTS(false);
    await _port.setPortParameters(
        9600, UsbPort.DATABITS_8, UsbPort.STOPBITS_1, UsbPort.PARITY_NONE);

    _transaction = Transaction.stringTerminated(
        _port.inputStream, Uint8List.fromList([13, 10]));

    _subscription = _transaction.stream.listen((String line) {
      setState(() {
        print(line);

        if (_isGetJSON == 1) {
          _isGetJSON = 0;
          Map<String, dynamic> dataMap = jsonDecode(line);
          _dataJson = DataJSON.fromJson(dataMap);

          _serialData.add(Text('Unit Name: ${_dataJson.tester}'));

          _dataPlotL = [
            Point(0, _scaleToDB(_dataJson.ch0F0f, _dataJson.ch0F0r[0]))
          ];
          _dataPlotR = [
            Point(0, _scaleToDB(_dataJson.ch0F0f, _dataJson.ch1F0r[0]))
          ];
          for (var i = 1; i < 24; i++) {
            _dataPlotL.add(
                Point(i, _scaleToDB(_dataJson.ch0F0f, _dataJson.ch0F0r[i])));
            _dataPlotR.add(
                Point(i, _scaleToDB(_dataJson.ch1F0f, _dataJson.ch1F0r[i])));
          }
        } else {
          _serialData.add(Text(line));
          if (_serialData.length > 3) {
            _serialData.removeAt(0);
          }
        }
      });
    });

    setState(() {
      _status = "Connected";
    });
    return true;
  }

  void _getPorts() async {
    _ports = [];

    List<UsbDevice> devices = await UsbSerial.listDevices();
    print(devices);

    devices.forEach((device) {
      _ports.add(ListTile(
        leading: Icon(Icons.usb),
        title: Text(device.productName),
        subtitle: Text(device.manufacturerName),
        trailing: ElevatedButton(
          child: Text(_deviceId == device.deviceId ? "Disconnect" : "Connect"),
          onPressed: () {
            _connectTo(_deviceId == device.deviceId ? null : device)
                .then((res) {
              _getPorts();
            });
          },
        ),
      ));
    });

    setState(() {
      print(_ports);
    });
  }

  void _sendText(String strReq) async {
    if (_port == null) {
      return;
    }

    _serialData.clear();
    String strData = strReq + "\r\n";
    await _port.write(Uint8List.fromList(strData.codeUnits));

    _textController.text = "";
  }

  void _getJSON(String strReq) async {
    if (_port == null) {
      return;
    }
    int numReq = int.parse(strReq);

    _serialData.clear();
    _isGetJSON = 1;
    String strData = "cat " + numReq.toString() + "\r\n";
    await _port.write(Uint8List.fromList(strData.codeUnits));

    _textViewSaved.text = "";
  }

  @override
  void initState() {
    super.initState();

    UsbSerial.usbEventStream.listen((UsbEvent event) {
      _getPorts();
    });

    _getPorts();
  }

  @override
  void dispose() {
    super.dispose();
    _connectTo(null);
  }

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(
          title: const Text('Audiometri Data Viewer'),
        ),
        body: Center(
          child: Column(
            children: <Widget>[
              ..._ports,
              Text('Status: $_status\n'),
              ListTile(
                leading: ElevatedButton(
                  child: Text("List Files"),
                  onPressed: _port == null
                      ? null
                      : () {
                          _sendText("lsnum");
                        },
                ),
                title: TextField(
                  controller: _textViewSaved,
                  decoration: InputDecoration(
                      border: OutlineInputBorder(),
                      labelText: 'Number to View'),
                ),
                trailing: ElevatedButton(
                  child: Text("GetData"),
                  onPressed: _port == null
                      ? null
                      : () {
                          _getJSON(_textViewSaved.text);
                        },
                ),
              ),
              Text("Result: ", style: TextStyle(fontWeight: FontWeight.bold)),
              ..._serialData,
              Container(
                child: new Plot(
                  height: 200,
                  data: _dataPlotL,
                  gridSize: new Offset(1, 20),
                  padding: const EdgeInsets.fromLTRB(40, 15, 15, 40),
                  xTitle: 'Tone Number',
                  yTitle: 'Left dB (SPL)',
                  style: new PlotStyle(
                      pointRadius: 3,
                      outlineRadius: 1,
                      primary: Colors.white,
                      secondary: Colors.orange,
                      trace: true,
                      showCoordinates: false,
                      trailingZeros: false,
                      textStyle: new TextStyle(
                          fontSize: 8,
                          color: Colors.blueGrey,
                          fontWeight: FontWeight.bold),
                      axis: Colors.blueGrey[600],
                      gridline: Colors.blueGrey[100]),
                ),
              ),
              Container(
                child: new Plot(
                  height: 200,
                  data: _dataPlotR,
                  gridSize: new Offset(1, 20),
                  padding: const EdgeInsets.fromLTRB(40, 15, 15, 40),
                  xTitle: 'Tone Number',
                  yTitle: 'Right dB (SPL)',
                  style: new PlotStyle(
                      pointRadius: 3,
                      outlineRadius: 1,
                      primary: Colors.white,
                      secondary: Colors.orange,
                      trace: true,
                      showCoordinates: false,
                      trailingZeros: false,
                      textStyle: new TextStyle(
                          fontSize: 8,
                          color: Colors.blueGrey,
                          fontWeight: FontWeight.bold),
                      axis: Colors.blueGrey[600],
                      gridline: Colors.blueGrey[100]),
                ),
              ),
            ],
          ),
        ),
      ),
    );
  }
}
