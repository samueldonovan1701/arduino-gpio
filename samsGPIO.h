#ifndef SAMS_GPIO
#define SAMS_GPIO

typedef uint8_t byte;
typedef volatile uint8_t reg;

class GPIO
{
private:
	reg* DDR;
    reg* PORT_OUT;
    reg* PORT_IN;
    byte PIN;  


public:
    GPIO(reg* DDR, reg* PORT_OUT, reg* PORT_IN, byte PIN)
    {
		this->DDR = DDR;
		this->PORT_OUT = PORT_OUT;
		this->PORT_IN = PORT_IN;
		this->PIN = PIN;
	};
    #define GPIO(X,P) GPIO(&DDR##X, &PORT##X, &PORT##X, P)

    
    #ifndef INPUT
    #define INPUT 0
    #endif
    #ifndef OUTPUT
    #define OUTPUT 1
    #endif
    void SetMode(byte mode)
    {
		if(mode == INPUT)
			AsInput();
		else
			AsOutput();
	};
    void AsInput()
    {
    	*DDR &= ~(1 << PIN);
	};
    void AsOutput()
	{
    	*DDR |= 1 << this->PIN; 
	};

    #ifndef LOW
    #define LOW 0
    #endif
    #ifndef HIGH
    #define HIGH 1
    #endif
    void Write(byte state)
    {
  		if(state == LOW)
    		this->Low();
  		else
    		this->High();
	};
    void High()
    {
  		*PORT_OUT |= 1 << PIN;
	};
    void Low()
	{
		*PORT_OUT &= ~(1 << PIN);
	};

    byte Read()
	{
		return (*PORT_IN >> PIN) & 1;
	};
};

    #if defined(ARDUINO_AVR_MEGA2560)
        #include "pins/mega.h"
    #else
        #error "samsGPIO.h: Board unsupported"
    #endif

#endif
