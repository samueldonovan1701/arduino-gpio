# arduino-gpio
A faster way to manipulate Arduino GPIO pins

## Usage

To use the library, copy the files (except for `GPIO.ino`) in your project folder, and
```c
#include "samsGPIO.h"
```

#### Constructor
```c
GPIO led = GPIO(B, 7);
```
Will assign `led` to a `GPIO` instance tied to PORTB/PINB, bit 7. Which physical pin this corresponds to on your board will vary between boards.

Using a bit number larger than 7 will have no affect.

Using a port that does not exist will cause a compile-time error.

#### SetMode(OUTPUT/INPUT) / AsOutput() / AsInput()
```c
GPIO13.SetMode(OUTPUT); 
GPIO13.AsOutput();

GPIO13.SetMode(INPUT);
GPIO13.AsInput();
```
Anything not `INPUT` (0) is considered `OUTPUT` (1)
#### Write(HIGH/LOW) / High() / Low()
```c
GPIO13.Write(HIGH);
GPIO13.High();

GPIO13.Write(LOW);
GPIO13.Low();
```
Anything not `LOW` (0) is considered `HIGH` (1)

#### Read()
```c
uint8_t b = GPIO13.Read();
```
Returns `HIGH` (1) or `LOW` (0)

### Supported Boards
On supported boards, pins are predefined and can be accessed via `GPIOXX` where `XX` is the on-board pin number. For example:
```c
GPIO13.Write(HIGH);
```

Currently, the following boards are supported:
- ATMEGA2560
 
Feel free to contribute your own board's pin definitons. 
 
## Limitations
- Only digital input/output is supported
- Not all boards will have pin definitions, although they can be added manually
- Limited run time resolution options
- Pin mode is not checked before attempting to `Read()` or `Write()`, this is left to the user
