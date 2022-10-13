#include <xc.h>
#include "defines.h"
#include <string.h>

void inicializarPic(void) {
  OSCCONbits.IRCF = 0b111;
  OSCTUNEbits.PLLEN = 0b1;
  TRISCbits.RC0 = SAIDA;
  TRISCbits.RC1 = ENTRADA;
  Transmissor = 1;
}

void delayWait(void) 
{
    __delay_ms(30);
   // __delay_ms(1000);
}

 
void transmiteByte(char byte) 
{
  unsigned int i = 0;
  unsigned char mascara = 0b00000001;
  unsigned char valor = 0;

  Transmissor = 1;
  __delay_us(833);
  Transmissor = 0;
  __delay_us(833);
  for(i = 0; i < 8; i++) 
  {
    if (byte & mascara<<i) 
    {
        valor = 1;
    }
    else
    {
        valor = 0;
    }
    Transmissor = valor;
    __delay_us(833);
  }
  Transmissor = 1;
  __delay_us(833);
}


void transmiteBytes(const char *bytes)
{
  unsigned int i = 0;
  unsigned int j = 0;
  unsigned char mascara = 0b00000001;
  unsigned char valor = 0;
  unsigned int data_len = strlen(bytes);
  
  for(j = 0; j< data_len ; j++)
  {
        Transmissor = 1;
        __delay_us(833);
        Transmissor = 0;
        __delay_us(833);
        for(i = 0; i < 8; i++) 
        {
          if (bytes[j] & mascara<<i) 
          {
              valor = 1;
          }
          else
          {
              valor = 0;
          }
          Transmissor = valor;
          __delay_us(833);
        }
  }
       
  Transmissor = 1;
  __delay_us(833);
}

char readByte(void)
{
    unsigned int i = 0;
    char dado = 0b00000000;
    int valor = 0;

    while(Receptor) {} 
    __delay_us(416);
    if(Receptor) {
      return 0xff;
    }

    __delay_us(833);
    for(i = 0; i < 8; i++) 
    {
      valor = (int) Receptor;
      dado = dado | valor<<i;
       __delay_us(833);
    }
    return dado;
}


char * readBytes(void)
{
    unsigned int i = 0;
    char dado = 0b00000000;
    int valor = 0;

    while(Receptor) {} 
    __delay_us(416);
    if(Receptor) {
      return 0xff;
    }

    __delay_us(833);
    for(i = 0; i < 8; i++) 
    {
      valor = (int) Receptor;
      dado = dado | valor<<i;
       __delay_us(833);
    }
    return dado;
}

uart_conf_t Uart =
{
    .init = inicializarPic,
    .write = transmiteByte,
    .wait  = delayWait,
    .read = readByte,
    .write_bytes = transmiteBytes        
};