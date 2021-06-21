import 'package:flutter/material.dart';
import 'dart:typed_data';
import 'dart:convert';
import 'dart:async';
import 'package:usb_serial/usb_serial.dart';
import 'package:usb_serial/transaction.dart';

void main() {
  runApp(MyApp());
}

class DataJSON {
  String tester;

  DataJSON(this.tester);

  DataJSON.fromJson(Map<String, dynamic> json) : tester = json['tester'];
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

  int isGetJSON = 0;
  TextEditingController _textViewSaved = TextEditingController();

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

        if (isGetJSON == 1) {
          Map<String, dynamic> dataMap = jsonDecode(line);
          var dataJson = DataJSON.fromJson(dataMap);

          _serialData.add(Text('${dataJson.tester}'));
          isGetJSON = 0;
        } else {
          _serialData.add(Text(line));
          if (_serialData.length > 20) {
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
    isGetJSON = 1;
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
          title: const Text('USB Serial'),
        ),
        body: Center(
          child: Column(
            children: <Widget>[
              Text(
                _ports.length > 0 ? "Serial Available" : "No USB Serial",
                style: Theme.of(context).textTheme.headline6,
              ),
              ..._ports,
              Text('Status: $_status\n'),
              ListTile(
                title: TextField(
                    controller: _textController,
                    decoration: InputDecoration(
                        border: OutlineInputBorder(),
                        labelText: 'Text To Send')),
                trailing: ElevatedButton(
                  child: Text("Send"),
                  onPressed: _port == null
                      ? null
                      : () {
                          _sendText(_textController.text);
                        },
                ),
              ),
              ListTile(
                title: TextField(
                    controller: _textViewSaved,
                    decoration: InputDecoration(
                        border: OutlineInputBorder(),
                        labelText: 'Number to View')),
                trailing: ElevatedButton(
                  child: Text("GetJSON"),
                  onPressed: _port == null
                      ? null
                      : () {
                          _getJSON(_textViewSaved.text);
                        },
                ),
              ),
              ListTile(
                leading: ElevatedButton(
                  child: Text("Info"),
                  onPressed: _port == null
                      ? null
                      : () {
                          _sendText("info");
                        },
                ),
                title: ElevatedButton(
                  child: Text("List Files"),
                  onPressed: _port == null
                      ? null
                      : () {
                          _sendText("ls");
                        },
                ),
                trailing: ElevatedButton(
                  child: Text("Test Audio"),
                  onPressed: _port == null
                      ? null
                      : () {
                          _sendText("test");
                        },
                ),
              ),
              Text(
                "Result",
                style: Theme.of(context).textTheme.headline6,
              ),
              ..._serialData,
            ],
          ),
        ),
      ),
    );
  }
}
