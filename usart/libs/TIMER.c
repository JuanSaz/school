#include "TIMER.h"
#include "ADC.h"

/******************************************************
    Inicializacion del TIMER0 para disparar el ADC
    cada 100 ms aproximadamente con la interrupcion
    de COMPARE MATCH A
******************************************************/

void TIMER0_Init(void) {

    TCCR0A = 1 << WGM01;    // CTC mode
    TCCR0B = 0x04;          // Prescaler 256
    OCR0A = TOP0;           // Top para interrupciones de 100 ms aprox
    TIMSK0 |= 1 << OCIE0A;  // Interrupcion por Compare Match A activada
}

/******************************************************
    Inicializacion del TIMER1 para generar un PWM con 
    frecuencia de 50 Hz
******************************************************/

void TIMER1_Init(void) {
    
    TCCR1A = 0xA2;      // Fast PWM, TOP en ICR1
    TCCR1B = 0x19;      // Fast PWM, TOP en ICR1, no prescaler
    ICR1 = TOP1;        // TOP para 20 ms de periodo
}

/****************************************************
    Interrupcion de COMPARE MATCH A.
    Esta funcion tiene que ejecutarse
    para poder limpiar el flag de COMPARE MATCH A 
    del TIMER0, pero no hacemos nada dentro
    de la interrupcion 
****************************************************/

ISR(TIMER0_COMPA_vect) {}