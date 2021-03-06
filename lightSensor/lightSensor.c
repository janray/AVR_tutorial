// Quick Demo of light sensor

// ------- Preamble -------- //
#include <avr/io.h>
#include <util/delay.h>
#include "USART.h"

#define LED_PORT   PORTB
#define LED_DDR	   DDRB

// ---- Functions ---- //
static inline void initADC0(void){
	ADMUX |= (1 << REFS0);					/* reference voltage on AVCC */
	ADCSRA |= (1 << ADPS1) | (1 << ADPS0);  /* ADC clock prescaler /8 */
	ADCSRA |= (1 << ADEN);					/* enable ADC */
}

int main(void){

	uint8_t ledValue;
	uint16_t adcValue;
	uint8_t i;

	initUSART();
	initADC0();
	LED_DDR = 0xff;

	printString("Hello");
	// --- Event loop --- //
	while(1){
		ADCSRA |= (1 << ADSC);  // Start ADC conversion
		loop_until_bit_is_clear(ADCSRA, ADSC);	// wait until done
		adcValue = ADC; // read ADC in


		// Have 10 bits, want 3 because we have eight LEDS ((2^3) == 8 )
		ledValue = (adcValue >> 7);

		// Light up all LEDs up to ledValue
		LED_PORT = 0;
		for(i = 0; i <= ledValue; i++){
			LED_PORT |= (1 << i);
		}
		_delay_ms(50);
	}
	return 0;
}