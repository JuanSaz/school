#include "GPIO.h"
#include "TIMER.h"
#include "ADC.h"
#include "USART.h"

/*  Macros  */

#define COOL_ON()           PWM1_OFF(); \
                            PWM2_ON()   
                    

#define HEAT_ON()           PWM2_OFF(); \
                            PWM1_ON()

#define OFF()               PWM_OFF()

#define HEAT(dT)            PWM2_OFF();     \
                            PWM1_ON();      \
                            PWM1_RAW(dT*K);

#define COOL(dT)            PWM1_OFF();     \
                            PWM2_ON();      \
                            PWM2_RAW(dT*K);  

/*  Prototipos de funciones  */
void MCU_Init(void);
void ADC_conversion(void);
void PWM(float temp, float set);