#include "defines.h"

void main(void) 
{
    Uart.init();
    while(1) 
    {
      Uart.write(Uart.read());  
      Uart.wait();
    }
}



