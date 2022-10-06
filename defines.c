#include "defines.h"

void init_pin(port_t port, pin_t pin, direction_t direction)
{
   if(port == PORT_A)
   {
        switch(pin)
        {
            case PIN_0:
                TRISAbits.RA0 = direction;
                break;
            case PIN_1:
                TRISAbits.RA1 = direction;
                break;
            case PIN_2:
                TRISAbits.RA2 = direction;
                break;
            case PIN_3:
                TRISAbits.RA3 = direction;
                break;
            case PIN_4:
                TRISAbits.RA4 = direction;
                break;
            case PIN_5:
                TRISAbits.RA5 = direction;
                break;
            case PIN_6: 
                TRISAbits.RA6 = direction;
                break;
            case PIN_7:
                TRISAbits.RA7 = direction;
                break;
        }
   }    
   else if(port == PORT_B)
   {
        switch(pin)
        {
            case PIN_0:
                    TRISBbits.RB0 = direction;
                    break;
                case PIN_1:
                    TRISBbits.RB1 = direction;
                    break;
                case PIN_2:
                    TRISBbits.RB2 = direction;
                    break;
                case PIN_3:
                    TRISBbits.RB3 = direction;
                    break;
                case PIN_4:
                    TRISBbits.RB4 = direction;
                    break;
                case PIN_5:
                    TRISBbits.RB5 = direction;
                    break;
                case PIN_6: 
                    TRISBbits.RB6 = direction;
                    break;
                case PIN_7:
                    TRISBbits.RB7 = direction;
                    break;
        }
   }
   else if(port == PORT_C)
   {
            switch(pin)
            {
                case PIN_0:
                    TRISCbits.RC0 = direction;
                    break;
                case PIN_1:
                    TRISCbits.RC1 = direction;
                    break;
                case PIN_2:
                    TRISCbits.RC2 = direction;
                    break;
                case PIN_3:
                    TRISCbits.RC3 = direction;
                    break;
                case PIN_4:
                    TRISCbits.RC4 = direction;
                    break;
                case PIN_5:
                    TRISCbits.RC5 = direction;
                    break;
                case PIN_6: 
                    TRISCbits.RC6 = direction;
                    break;
                case PIN_7:
                    TRISCbits.RC7 = direction;
                    break;
            }
    }
}

void write_pin(port_t port, pin_t pin, pin_level_t level)
{
    if(port == PORT_A)
    {
        switch(pin)
        {
            case PIN_0:
               LATAbits.LATA0 = level;
                break;
            case PIN_1:
               LATAbits.LATA1 = level;
                break;
            case PIN_2:
               LATAbits.LATA2 = level;
                break;
            case PIN_3:
               LATAbits.LATA3 = level;
                break;
            case PIN_4:
               LATAbits.LATA4 = level;
                break;
            case PIN_5:
               LATAbits.LATA5 = level;
                break;
            case PIN_6: 
               LATAbits.LATA6 = level;
                break;
            case PIN_7:
               LATAbits.LATA7 = level;
                break;
        }
   }    
   else if(port == PORT_B)
   {
        switch(pin)
        {
            case PIN_0:
               LATBbits.LATB0 = level;
                break;
            case PIN_1:
               LATBbits.LATB1 = level;
                break;
            case PIN_2:
               LATBbits.LATB2 = level;
                break;
            case PIN_3:
               LATBbits.LATB3 = level;
                break;
            case PIN_4:
               LATBbits.LATB4 = level;
                break;
            case PIN_5:
               LATBbits.LATB5 = level;
                break;
            case PIN_6: 
               LATBbits.LATB6 = level;
                break;
            case PIN_7:
               LATBbits.LATB7 = level;
                break;
        }
   }
   else if(port == PORT_C)
   {
        switch(pin)
        {
            case PIN_0:
               LATCbits.LATC0 = level;
                break;
            case PIN_1:
               LATCbits.LATC1 = level;
                break;
            case PIN_2:
               LATCbits.LATC2 = level;
                break;
            case PIN_3:
               LATCbits.LATC3 = level;
                break;
            case PIN_4:
               LATCbits.LATC4 = level;
                break;
            case PIN_5:
               LATCbits.LATC5 = level;
                break;
            case PIN_6: 
               LATCbits.LATC6 = level;
                break;
            case PIN_7:
               LATCbits.LATC7 = level;
                break;
        }
   }
}


void write_clock(port_t port, int value)
{
    char vet_clock[10] = {0b0000,0b0001,0b0010,0b0011,0b0100,0b0101,0b0110,0b0111,0b1000};
    char vet_clock_test[10] = {0b00000000,0b00001000,0b00000100, 0b00001100,0b00000010,0b00001010, 0b00000110, 0b00001110,0b00000001,0b00001001};
    if(port == PORT_A)
    {
        LATA= vet_clock_test[value]; 
    }
     if(port == PORT_B)
    {
        LATB= vet_clock_test[value]; 
    }
     if(port == PORT_C)
    {
        LATC= vet_clock_test[value]; 
    }
}


void delay_s (int segundos)
{
	unsigned long int i;
	for (;segundos>0;segundos--)
	{
		for (i=0;i<83333;i++) 
        {

        }
	}
}

void delay_ms (int ms)
{
	unsigned long int i;
	for (;ms>0;ms--)
	{
		for (i=0;i<80;i++) 
        {

        }
	}
}
