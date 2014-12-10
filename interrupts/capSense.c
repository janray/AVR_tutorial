// Capacitive touch sensor demo


#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/power.h>
#include "USART.h"


#define SENSE_TIME	50
#define THRESHOLD	12000


// --- Global variables --- //
volatile uint16_t chargeCycleCount;

// ---- Functions ---- //
void initPinChangeInterrupt(void){
	PCICR |= (1 << PCIE1);		// enable Pin-change interrupts 1 (bank C)
	PCMSK1 |= (1 << PC1);
}

ISR(PCINT1_vect){
	chargeCycleCount++;		// count this change
	DDRC |= (1 << PC3);
	_delay_us(1);

	DDRC &= ~(1 << PC3);
	PCIFR |= (1 << PCIF1);
}

int main(void){
	// --- Inits --- //
	clock_prescale_set(clock_div_1);
	initUSART();
	printString("==[ Cap Sensor ]==\r\n\r\n");

	DDRB = 0xff;
	MCUCR |= (1 << PUD);
	PORTC |= (1 << PC3);

	initPinChangeInterrupt();

	// --- Event loop --- //
	while(1){
		chargeCycleCount = 0;
		DDRC |= (1 << PC3);
		sei();
		_delay_ms(SENSE_TIME);
		cli();
	}

}