#ifndef ADC_H

#include <avr/io.h>
#include <avr/interrupt.h>

/*  Macros  */

#define ADC0	0
#define ADC1	1
#define ADC2	2
#define ADC3	3
#define ADC4	4
#define ADC5	5

#define ADC_Start()			ADCSRA |= 1 << ADSC
#define ADC_Busy()			!(ADCSRA & (1 << ADIF))
#define ADC_Clear()			ADCSRA |= 1 << ADIF
#define ADC_SetChannel(ch)  ADMUX = (ADMUX & 0xf0) | ch

/*  Prototipos de funciones  */
void ADC_Init (void);
int	ADC_Read (char canal);

#endif