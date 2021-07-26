#ifndef _USART_H_
#define _USART_H_

#include <stdlib.h>
#include <avr/io.h>
#include <avr/interrupt.h>

/*  Macros  */
#define RX_ISR      0
#define TX_ISR      1
#define UDRE_ISR    2

/*  Prototipos de funciones  */
void USART_Init(uint32_t baud);
void USART_Putc(uint8_t c);
void USART_Prints(const char *str);
void USART_Printf(double var);

#endif /* _USART_H_ */