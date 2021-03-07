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
{"kind":"A","ft":100,"timestamp":1615131559}
{"kind":"A","et":100,"timestamp":1615131559}
{"kind":"A","rt":100,"timestamp":1615131559}
{"kind":"A","spd":100,"timestamp":1615131559}
{"kind":"A","status":"open","timestamp":1615131559}
{"kind":"A","status":"close","timestamp":1615131559}
```

```
{"kind":"B","ft":100,"timestamp":1615131559}
{"kind":"B","et":100,"timestamp":1615131559}
{"kind":"B","rt":100,"timestamp":1615131559}
{"kind":"B","spd":100,"timestamp":1615131559}
{"kind":"B","status":"open","timestamp":1615131559}
{"kind":"B","status":"close","timestamp":1615131559}
```

### example send to serial

abort command 
```
{"kind":"A","command":"abort","timestamp":1615131559}
{"kind":"B","command":"abort","timestamp":1615131559}
```

setup command
```
{"delay_tree":500,"kind":"A","timestamp":1615131559,"tree_type":"FULL"}
{"delay_tree":500,"kind":"B","timestamp":1615131559,"tree_type":"FULL"}
{"delay_tree":500,"kind":"AB","timestamp":1615131559,"tree_type":"FULL"}
```