MCU=atmega328p
PART=m328p
F_CPU=1000000
CC=avr-gcc
OBJCOPY=avr-objcopy
CFLAGS=-std=c99 -Wall -g -Os -mmcu=${MCU} -DF_CPU=${F_CPU} -I.
TARGET=main
SRCS=main.c libs/ADC.c libs/TIMER.c libs/USART.c libs/GPIO.c libs/foo.c
PROGRAMMER=usbasp

all:
	${CC} ${CFLAGS} -o ${TARGET}.bin ${SRCS}
	${OBJCOPY} -j .text -j .data -O ihex ${TARGET}.bin ${TARGET}.hex

flash:
	avrdude -p ${PART} -c ${PROGRAMMER} -U flash:w:${TARGET}.hex:i