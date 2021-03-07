# DTS

### dot init configuration

crete or copy file `application.ini` to  `C:/Users/yourusername/.dts/`

example file application.ini
```
FULLSCREEN=false
SERIAL_PORT=COM2
SERIAL_SPEED=115200
```


### example making data serial

kind : for distinguish where the data came from

```
{"kind":"A","ft":100,"timestamp":123123}
{"kind":"A","et":100,"timestamp":123123}
{"kind":"A","rt":100,"timestamp":123123}
{"kind":"A","spd":100,"timestamp":123123}
{"kind":"A","status":"open","timestamp":123123}
{"kind":"A","status":"close","timestamp":123123}
```

```
{"kind":"B","ft":100,"timestamp":123123}
{"kind":"B","et":100,"timestamp":123123}
{"kind":"B","rt":100,"timestamp":123123}
{"kind":"B","spd":100,"timestamp":123123}
{"kind":"B","status":"open","timestamp":123123}
{"kind":"B","status":"close","timestamp":123123}
```