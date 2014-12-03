// Slow-scope

// --- Preamble -- //
#include <avr/io.h>
#include <util/delay.h>
#include "USART.h"

#define LED_PORT	PORTB
#define LED_DDR		DDRB

#define SAMPLE_DELAY 20  //in ms, controls the scroll speed of the Slow-scope


// --- functions --- //
static inline void initFreerunningADC(void){
	ADMUX |= (1 << REFS0);		// reference voltage on AVCC
	ADCSRA |= (1 << ADPS1) | (1 << ADPS0);  // ADC clock prescaler /8 //
	ADMUX |= (1 << ADLAR);		// left-adjust result, return only 8 bits

	ADCSRA |= (1 << ADEN);		// enable ADC
	ADCSRA |= (1 << ADATE);		// auto-trigger enable
	ADCSRA |= (1 << ADSC); 		// start first conversion

}


int main(void){
	initUSART();
	initFreerunningADC();

	while(1){
		transmitByte(ADCH);		// transmit the high byte, left-adjusted
		_delay_ms(SAMPLE_DELAY);
	}
	return 0;
}