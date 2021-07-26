#ifndef I2C_I2C_H
#define I2C_I2C_H

#include <avr/io.h>

#ifndef F_I2C
#warning "F_I2C is not defined. Using default frequency: 100kHz"
#define F_I2C 50000UL
#endif

#define TWBR_VALUE (((F_CPU) / (F_I2C) - 16) / 2)

#if ((TWBR_VALUE > 255) || (TWBR_VALUE == 0))
#error "Invalid TWBR value"
#endif

typedef enum {
    i2c_write,
    i2c_read   
} i2c_mode;

typedef enum {
    start_transmitted = 0x08,
    repeated_start_transmitted = 0x10,
    arbitration_lost = 0x38
} i2c_status_codes;

typedef enum {
    write_address_ack_received = 0x18,
    write_address_ack_not_received = 0x20,
    write_data_ack_received = 0x28,
    write_data_ack_not_received = 0x30
} i2c_master_transmitter_status;

typedef enum {
    read_address_ack_sent = 0x40,
    read_address_ack_not_sent = 0x48,
    read_data_ack_sent = 0x50,
    read_data_ack_not_sent = 0x58
} i2c_master_receiver_status;

typedef enum {
    prescaler_1,
    prescaler_4,
    prescaler_16,
    prescaler_64
} i2c_prescaler;

/* Function prototypes */
void I2C_Init(void);
void I2C_Start(void);
void I2C_Stop(void);
void I2C_SendSlaveAddress(uint8_t address, i2c_mode readWriteMode);
void I2C_SendData(uint8_t data);
uint8_t I2C_ReadDataAck(void);
uint8_t I2C_ReadDataNotAck(void);
uint8_t I2C_GetStatus(void);

#endif /* _I2C_H_ */