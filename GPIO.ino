
#include "samsGPIO.h"
#include <util/delay.h>

int main()
{  
    GPIO13.AsOutput();
    
    while(1)
    {
        GPIO13.High(); 
        _delay_ms(1000);
        GPIO13.Low();
        _delay_ms(1000);
    }
    
    return 0;
}
