#include <avr/io.h>
#include "USART.h"
#include <util/setbaud.h>

void initUSART(void){
	UBRR0H = UBRRH_VALUE;
	UBRR0L = UBRRL_VALUE;

	#if USE_2X
		UCSR0A |= (1 << U2X0);
	#else
		UCSR0A &= ~(1 << U2X0);
	#endif

	// Enable USART TRX
	UCSR0B = (1 << TXEN0) | (1 << RXEN0);
	// Configure USART for 8 data bits, 1 stop bit
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

void transmitByte(uint8_t data){
	// Wait for empty transmit buffer
	loop_until_bit_is_set(UCSR0A, UDRE0);

	// Send data
	UDR0 = data;
}

uint8_t receiveByte(void){
	loop_until_bit_is_set(UCSR0A, RXC0);
	return UDR0;
}

void printString(const char myString[]){
	uint8_t i = 0;
	while(myString[i]){
		transmitByte(myString[i]);
		i++;
	}
}

void readString(char myString[], uint8_t maxLength){
	char response;
	uint8_t i;
	i = 0;
	while(i < (maxLength -1)){
		response = receiveByte();
		transmitByte(response);
		if(response == '\r'){
			break;
		}
		else {
			myString[i] = response;
			i ++;
		}
	}
	myString[i] = 0;
}