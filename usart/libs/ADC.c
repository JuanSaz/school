#include "ADC.h"
#include "foo.h"

int volatile adc = 0;

/****************************************************
	Inicializacion del ADC para dispararse con el
	COMPARE MATCH A del TIMER0
****************************************************/

void ADC_Init (void) {
	
	ADMUX = 0x20;	// Justificado a la izquierda
	ADCSRA = 0xA8;	// ADC, ISR and Auto trigger disabled
	ADCSRB = 0x03;	// Trigger source TIMER0 CMP MATCH A
}

/***************************************************
	Inicializa una lectura en el canal determinado
	y devuelve el valor como un uint16
***************************************************/

int ADC_Read (char canal) {
	
	ADC_SetChannel(canal);
	ADC_Start();
	while (ADC_Busy());
	ADC_Clear();
	return ADC >> 6;
}

/**************************************************
	Servicio de interrupcion del ADC Conversion
	Complete. Guarda el valor del data register
	en una variable y cambia de canal
**************************************************/

ISR (ADC_vect) {  

	adc = ADC >> 6;	// Armo el dato de 10 bits a partir de uno de 16 bits
	ADMUX ^= 1;		// Cambio de canal
}