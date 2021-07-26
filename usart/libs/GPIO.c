#include "GPIO.h"

/*
 *  Function: GPIO_Init
 *  -------------------------------------------------------
 *  @brief: Inicializa los puertos digitales para el PWM
 *  y para usar una interrupcion externa
 */

void GPIO_Init(void) {

    DDRB |= 1 << PB1 | 1 << PB2;    // Pines de PWM como salida
}
