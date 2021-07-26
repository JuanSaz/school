#include "foo.h"

extern volatile int adc;
float temp = 0, sp = 0;

/***********************************************
    Inicializa los modulos que vamos a usar
    llamando a los init que haga falta
***********************************************/

void MCU_Init(void) {

    GPIO_Init();                    // Inicializo los puertos digitales
    ADC_Init();                     // Inicializo el ADC
    TIMER0_Init();                  // TIMER0 para disparar el ADC 
    TIMER1_Init();                  // TIMER1 para hacer PWM
    USART_Init(9600);                // Inicializacion del UART
    sei();                          // Habilita las interrupciones
}

/***********************************************
    Determina el canal que se leyo y hace
    la conversion de unidades correspondiente
***********************************************/

void ADC_conversion(void) {

    switch ( ADMUX & (1 << MUX0) )  // Miro el bit MUX0 para saber el canal 
    {
        case ADC0:  sp = (float) adc * 35 / 1023;
        break;
        
        case ADC1:  temp = (float) adc * 5 / 1023 * 100;
        break;
    }
}

/************************************************
    Ve la diferencia entre temperaturas y saca
    un PWM con un ciclo de trabajo proporcional
    a la diferencia entre ellas.
************************************************/

void PWM(float temp, float set) {

    // Ignoro los decimales para comparar
    int dif = (int)temp - (int)set; 

    // Si son iguales, se apaga todo
    if (!dif) { OFF(); }

    // Si lLa temperatura esta muy por arriba, hay que enfriar
    else if (dif > 10) { COOL(10); }

    // Si la temperatura esta muy por debajo, hay que calentar
    else if (dif < -10) { HEAT(10); }
    
    // Si la diferencia de temperatura no es tan grande, hago
    // un PWM proporcional
    else {
        if (dif > 0) { COOL(dif); }
        else { HEAT(-1*dif); }
    }
}