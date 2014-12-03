// Demo using interrupts


#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


ISR(INT0_vect){
	/*if(bit_is_set(PIND, PD2)){
		PORTB |= (1 << 1);
	}*/
	if (PIND & (1 << PD2)){
		PORTB |= (1 << 1);
	}
	else {
		PORTB &= ~(1 << 1);
	}
}


void initInterrupt0(void){
	EIMSK |= (1 << INT0);		// enable INT0
	EICRA |= (1 << ISC00);		// trigger when button changes
	sei();						// set (global) interrupt enable bit
}


int main(void){

	DDRB = 0xff;
	PORTD |= (1 << PD2);
	initInterrupt0();


	while(1){
		_delay_ms(200);
		PORTB ^= (1 << 0);
	}
	return 0;
}