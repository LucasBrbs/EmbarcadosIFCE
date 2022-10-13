/* 
 * File:   defines.h
 * Author: jontz
 *
 * Created on 12 de Outubro de 2022, 15:54
 */

#ifndef DEFINES_H
#define	DEFINES_H

#define _XTAL_FREQ 8000000
#pragma config	WDT = OFF
#define SAIDA 0
#define ENTRADA 1
#define Transmissor PORTCbits.RC0
#define Receptor PORTCbits.RC1

typedef void (*fn_callback_init_t)(void);
typedef void (*fn_callback_write_t)(char);
typedef void (*fn_callback_write_bytes_t)(const char *);
typedef char (*fn_callback_read_t)(void);
typedef void (*fn_callback_wait_t)(void);
typedef char*(*fn_callback_read_bytes_t)(void);

typedef struct
{
    fn_callback_init_t init;
    fn_callback_write_t write;
    fn_callback_write_bytes_t write_bytes;
    fn_callback_read_t read;
    fn_callback_wait_t wait;
    fn_callback_read_bytes_t read_bytes;
}uart_conf_t;



void inicializarPic(void);
void delayWait(void);
void transmiteByte(char byte);
char readByte(void);
void transmiteBytes(const char *bytes);
char *readBytes(void);

extern uart_conf_t Uart;
#endif	/* DEFINES_H */

