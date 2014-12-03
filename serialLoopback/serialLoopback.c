// serialLoopback.c
/* A simple test of serial functionality */

#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>
#include "USART.h"


int main(void){
	char serialCharacter;

	DDRB = 0xff;
	initUSART();

	printString("Hello Worlds!\r\n");
	PORTB |= 0x01;
	_delay_ms(300);
	PORTB &= 0x00;

	while(1){
		serialCharacter = receiveByte();
		transmitByte(serialCharacter);
	}
}