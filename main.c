
#include "defines.h"

void main(void)
{
    pin_manager_t PinManager;
    PinManager.init = init_pin;
    PinManager.write = write_pin;
    PinManager.init(PORT_C, PIN_0,OUTPUT);
    while(1)
    {
        PinManager.write(PORT_C,PIN_0,HIGH);
        delay_s(1);
        PinManager.write(PORT_C,PIN_0,LOW);
        delay_s(1);
    }
}