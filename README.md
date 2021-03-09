# DTS

### Usage
[TODO]


### dot init configuration

crete or copy file `application.ini` to  `C:/Users/yourusername/.dts/`

example file application.ini
```
FULLSCREEN=false
SERIAL_PORT=COM2
SERIAL_SPEED=115200
```


### example receive data from serial

kind : for distinguish where the data came from

```
{"kind":"A","ft":17,"et":54,"rt":24,"spd":29}
{"kind":"A","status":"open"}
{"kind":"A","status":"close"}
```

```
{"kind":"B","ft":54,"et":65,"rt":14,"spd":1}
{"kind":"B","status":"open"}
{"kind":"B","status":"close"}
```

### example send to serial

abort command 
```
{"kind":"A","command":"abort"}
{"kind":"B","command":"abort"}
```

setup command
```
{"command":"setup","delay_tree":500,"kind":"A","tree_type":"FULL"}
{"command":"setup","delay_tree":500,"kind":"B","tree_type":"FULL"}
{"command":"setup","delay_tree":500,"kind":"AB","tree_type":"FULL"}
```