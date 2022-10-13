# 1 "main.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "/opt/microchip/mplabx/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8/pic/include/language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "main.c" 2
# 1 "./defines.h" 1
# 12 "./defines.h"
#pragma config WDT = OFF





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
# 2 "main.c" 2

void main(void)
{
    Uart.init();
    while(1)
    {
      Uart.write(Uart.read());
      Uart.wait();
    }
}
