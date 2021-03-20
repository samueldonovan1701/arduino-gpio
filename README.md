# avr-gpio
A simple way to manipulate AVR GPIO pins at the register level

## Usage

To use the library, clone or download the repository into your project folder. After that, you can
```c
#include "avr-gpio/GPIO.h"
```

### Functions

<table>
	<tr>
		<th>Signature</th>
		<th>Description</th>
	</tr>
	<tr>
		<td><code>GPIO(X, byte)</code></td>
		<td>
			<p>A macro for constructing a new <code>GPIO</code> instance</p>
			<p><code>X</code> is the Port (e.g. A,B,C) (NOT A STRING)</p>
			<p><code>byte</code> is the bit number (0-7)</p>
		</td>
	</tr>
	<tr>
		<th>Mode Commands</th>
		<th></th>
	</tr>
	<tr>
		<td><code>void SetMode(byte)</code></td>
		<td>Sets the pin to be an <code>INPUT</code> or <code>OUTPUT</code></td>
	</tr>
	<tr>
		<td><code>AsInput()</code></td>
		<td>Sets the pin to be an input</td>
	</tr>
	<tr>
		<td><code>AsOutput()</code></td>
		<td>Sets the pin to be an output</td>
	</tr>
	<tr>
		<th>Write Commands</th>
		<th>Pin must be set to <code>OUTPUT</code> mode</th>
	</tr>
	<tr>
		<td><code>Write(byte)</code></td>
		<td>Sets the pin's state <code>HIGH</code> or <code>LOW</code></td>
	</tr>
	<tr>
		<td><code>Low()</code></td>
		<td>Sets the pin's state <code>LOW</code> (must be in <code>OUTPUT</code> mode)</td>
	</tr>
	<tr>
		<td><code>High()</code></td>
		<td>Sets the pin's state <code>HIGH</code> (must be in <code>OUTPUT</code> mode)</td>
	</tr>
	<tr>
		<th>Read Commands</th>
		<th>Pin must be set to <code>INPUT</code> mode</th>
	</tr>
	<tr>
		<td><code>byte Read()</code></td>
		<td>Reads the pin's state</td>
	</tr>
	<tr>
		<td><code>bool isHigh()</code></td>
		<td>Returns <code>true</code> if the pin is <code>HIGH</code></td>
	</tr>
	<tr>
		<td><code>bool isLow()</code></td>
		<td>Returns <code>true</code> if the pin is <code>LOW</code></td>
	</tr>
</table>

## Supported Boards
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
- Pin mode is not checked before attempting to `Read()` or `Write()`: this is left to the user
