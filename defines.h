//relogio digitalde 6 digitos,7 segmentos,BCD
//requisitos:
/**
requisitos:
- alarme
- botão de modo 
- 2 botões de ajustesw para hora e minutos 
- saida de alarme buzzer;
- 

    botão de modo 
    - alternar entreo modo de ajuste de horas e ajuste de alarme;
    -ser acionado somenmte se pressionado por 2;
*/
#ifndef DEFINE_H
#define DEFINE_H
#include "p18f4520.h"

#define cont_ms 100

typedef enum{OUTPUT,INPUT}direction_t;
typedef enum{LOW,HIGH}pin_level_t;
typedef enum{PORT_A,PORT_B,PORT_C,PORT_MAX}port_t;
typedef enum{PIN_0,PIN_1,PIN_2,PIN_3,PIN_4,PIN_5,PIN_6,PIN_7,PIN_MAX}pin_t;

void init_pin(port_t port, pin_t pin, direction_t direction);
void write_pin(port_t port, pin_t pin, pin_level_t level);
pin_level_t read(port_t port, pin_t pin);

typedef void (*fn_callback_init)(port_t port, pin_t pin, direction_t direction);
typedef void (*fn_callback_write)(port_t port, pin_t pin, pin_level_t level);

typedef struct
{
    fn_callback_init init;
    fn_callback_write write;   
}pin_manager_t;

void delay_s (int segundos);
void delay_ms (int ms);
#endif /* DEFINE_H */