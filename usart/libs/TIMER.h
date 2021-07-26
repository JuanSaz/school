#include <avr/io.h>
#include <avr/interrupt.h>

/*  Macros  */

#define TOP0    195
#define TOP1    20000
#define K       2000        // TOP1 / 10

#define PWM1_RAW(RAW)       OCR1A = RAW
#define PWM2_RAW(RAW)       OCR1B = RAW

#define PWM1_OFF()          TCCR1A &= ~(1 << COM1A1)
#define PWM2_OFF()          TCCR1A &= ~(1 << COM1B1)

#define PWM1_ON()           TCCR1A |= 1 << COM1A1
#define PWM2_ON()           TCCR1A |= 1 << COM1B1

#define PWM_OFF()           TCCR1A &= ~(1 << COM1A1 | 1 << COM1B1)

/*  Prototipos de funciones  */
void TIMER0_Init(void);
void TIMER1_Init(void);
