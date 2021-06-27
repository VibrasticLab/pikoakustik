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
  double ch0F0f, ch0F1f, ch0F2f, ch1F0f, ch1F1f, ch1F2f;
  List<dynamic> ch0F0r, ch0F1r, ch0F2r, ch1F0r, ch1F1r, ch1F2r;

  DataJSON(
    this.tester,
    // Frequency
    this.ch0F0f,
    this.ch0F1f,
    this.ch0F2f,
    this.ch1F0f,
    this.ch1F1f,
    this.ch1F2f,
    // Record
    this.ch0F0r,
    this.ch0F1r,
    this.ch0F2r,
    this.ch1F0r,
    this.ch1F1r,
    this.ch1F2r,
  );

  DataJSON.fromJson(Map<String, dynamic> jsonIN)
      : tester = jsonIN['tester'],
        //left channel
        ch0F0f = jsonIN['ch_0']['freq_0']['freq'] * 400,
        ch0F0r = jsonIN['ch_0']['freq_0']['record'],
        ch0F1f = jsonIN['ch_0']['freq_1']['freq'] * 400,
        ch0F1r = jsonIN['ch_0']['freq_1']['record'],
        ch0F2f = jsonIN['ch_0']['freq_2']['freq'] * 400,
        ch0F2r = jsonIN['ch_0']['freq_2']['record'],
        //right channel
        ch1F0f = jsonIN['ch_1']['freq_0']['freq'] * 400,
        ch1F0r = jsonIN['ch_1']['freq_0']['record'],
        ch1F1f = jsonIN['ch_1']['freq_1']['freq'] * 400,
        ch1F1r = jsonIN['ch_1']['freq_1']['record'],
        ch1F2f = jsonIN['ch_1']['freq_2']['freq'] * 400,
        ch1F2r = jsonIN['ch_1']['freq_2']['record'];
}

class MyApp extends StatefulWidget {
  @override
  _MyAppState createState() => _MyAppState();
}

class _MyAppState extends State<MyApp> {
  UsbPort _port;
  List<Widget> _ports = [];
  List<Widget> _serialData = [];
  StreamSubscription<String> _subscription;
  Transaction<String> _transaction;
  int _deviceId;

  int _isGetStatus = 0;
  int _isGetFList = 1;
  int _isGetJSON = 2;

  TextEditingController _textViewSaved = TextEditingController();
  var _dataJson;
  List<int> _fnum = [];

  List<Point> _dataPlotL = [Point(0, 0)];
  List<Point> _dataPlotR = [Point(0, 0)];

  int _freqChoiceL = 500;
  int _freqChoiceR = 500;

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

  void _choicePlotL(int freq) {
    if (freq == 500) {
      _dataPlotL = [
        Point(0, _scaleToDB(_dataJson.ch0F0f, _dataJson.ch0F0r[0]))
      ];
      for (var i = 1; i < 24; i++) {
        _dataPlotL
            .add(Point(i, _scaleToDB(_dataJson.ch0F0f, _dataJson.ch0F0r[i])));
      }
    } else if (freq == 1000) {
      _dataPlotL = [
        Point(0, _scaleToDB(_dataJson.ch0F1f, _dataJson.ch0F1r[0]))
      ];
      for (var i = 1; i < 24; i++) {
        _dataPlotL
            .add(Point(i, _scaleToDB(_dataJson.ch0F1f, _dataJson.ch0F1r[i])));
      }
    } else if (freq == 2000) {
      _dataPlotL = [
        Point(0, _scaleToDB(_dataJson.ch0F2f, _dataJson.ch0F2r[0]))
      ];
      for (var i = 1; i < 24; i++) {
        _dataPlotL
            .add(Point(i, _scaleToDB(_dataJson.ch0F2f, _dataJson.ch0F2r[i])));
      }
    } else {
      _dataPlotL = [Point(0, 0)];
    }
  }

  void _choicePlotR(int freq) {
    if (freq == 500) {
      _dataPlotR = [
        Point(0, _scaleToDB(_dataJson.ch1F0f, _dataJson.ch1F0r[0]))
      ];
      for (var i = 1; i < 24; i++) {
        _dataPlotR
            .add(Point(i, _scaleToDB(_dataJson.ch1F0f, _dataJson.ch1F0r[i])));
      }
    } else if (freq == 1000) {
      _dataPlotR = [
        Point(0, _scaleToDB(_dataJson.ch1F1f, _dataJson.ch1F1r[0]))
      ];
      for (var i = 1; i < 24; i++) {
        _dataPlotR
            .add(Point(i, _scaleToDB(_dataJson.ch1F1f, _dataJson.ch1F1r[i])));
      }
    } else if (freq == 2000) {
      _dataPlotR = [
        Point(0, _scaleToDB(_dataJson.ch1F2f, _dataJson.ch1F2r[0]))
      ];
      for (var i = 1; i < 24; i++) {
        _dataPlotR
            .add(Point(i, _scaleToDB(_dataJson.ch1F2f, _dataJson.ch1F2r[i])));
      }
    } else {
      _dataPlotR = [Point(0, 0)];
    }
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
      return true;
    }

    _port = await device.create();
    if (!await _port.open()) {
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

        if (_isGetStatus == _isGetJSON) {
          Map<String, dynamic> dataMap = jsonDecode(line);
          _dataJson = DataJSON.fromJson(dataMap);

          _serialData.add(Text('Loaded Unit Name: ${_dataJson.tester}'));
          _choicePlotL(_freqChoiceL);
          _choicePlotR(_freqChoiceR);
        } else if (_isGetStatus == _isGetFList) {
          List<String> _arrLine = line.split(',');
          int _lenLine = _arrLine.length - 1;

          for (var i = 0; i < _lenLine; i++) {
            _fnum.add(int.parse(_arrLine[i]));
          }
          _fnum.sort();

          for (var i = 0; i < _lenLine; i++) {
            _serialData.add(Text(_fnum[i].toString()));
          }
        } else {
          _serialData.add(Text(line));
          if (_serialData.length > 2) {
            _serialData.removeAt(0);
          }
        }

        _isGetStatus = 0;
      });
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

  void _getFList() async {
    if (_port == null) {
      return;
    }

    _serialData.clear();
    _isGetStatus = _isGetFList;
    _fnum.clear();
    String strData = "lsnum\r\n";
    await _port.write(Uint8List.fromList(strData.codeUnits));
  }

  void _getJSON(String strReq) async {
    if (_port == null) {
      return;
    }
    int numReq = int.parse(strReq);

    _serialData.clear();
    _isGetStatus = _isGetJSON;
    String strData = "cat " + numReq.toString() + "\r\n";
    await _port.write(Uint8List.fromList(strData.codeUnits));
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
              ListTile(
                leading: Container(
                    child: new DropdownButton<String>(
                        value: _freqChoiceL.toString(),
                        items: <String>['500', '1000', '2000']
                            .map<DropdownMenuItem<String>>((String value) {
                          return DropdownMenuItem<String>(
                            value: value,
                            child: Text(value),
                          );
                        }).toList(),
                        onChanged: (String newValue) {
                          setState(() {
                            _freqChoiceL = int.parse(newValue);
                          });
                        })),
                title:
                    Text('L     Freq(Hz)     R', textAlign: TextAlign.center),
                trailing: Container(
                    child: new DropdownButton<String>(
                        value: _freqChoiceR.toString(),
                        items: <String>['500', '1000', '2000']
                            .map<DropdownMenuItem<String>>((String value) {
                          return DropdownMenuItem<String>(
                            value: value,
                            child: Text(value),
                          );
                        }).toList(),
                        onChanged: (String newValue) {
                          setState(() {
                            _freqChoiceR = int.parse(newValue);
                          });
                        })),
              ),
              ListTile(
                leading: ElevatedButton(
                  child: Text("List Files"),
                  onPressed: _port == null
                      ? null
                      : () {
                          _getFList();
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
