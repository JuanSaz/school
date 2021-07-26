#include <avr/io.h>
#include "I2C.h"

void I2C_Init(void) {
    
    TWBR = TWBR_VALUE;
    TWCR = 0x04;                        // TWCR = 0x04 = 0b00000100

}

void I2C_Wait(void) {
    
    while (!(TWCR & 0x80));             //TWCR & 0x80 = 0b10000000
    
}

void I2C_Start(void) {
    

    TWCR |= (1<<TWSTA);
    I2C_Wait();
}

void I2C_Stop(void) {
    
    TWCR |= (1<<TWSTO);

}

void I2C_SendData(uint8_t data) {
    
    I2C_Wait();
    TWDR = data;
    TWCR |= (1<<TWINT);                             // Clear del flag
 
}

uint8_t I2C_ReadDataAck(void) {
    
    I2C_Wait();
    TWCR |= (1<<TWEA);                  // Hay Acknowledge                 
    return TWDR;                    
}

uint8_t I2C_ReadDataNotAck(void) {

    I2C_Wait();             
    return TWDR;                        // No hay Acknowledge

}

void I2C_SendSlaveAddress(uint8_t address, uint8_t readWriteMode) {
    
    TWDR = (address<<1) | readWriteMode;

}

uint8_t I2C_GetStatus(void) {
    return TWSR;                            // Devuelvo Status
}