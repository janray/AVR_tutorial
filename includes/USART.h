#ifndef __USART_H
#define __USART_H

#ifndef BAUD
#define BAUD	9600
#endif


#define   USART_HAS_DATA   bit_is_set(UCSR0A, RXC0)
#define   USART_READY      bit_is_set(UCSR0A, UDRE0)


/* Takes the defined BAUD and F_CPU,
	calculates the bit-clock multiplier,
	and configures the hardware USART
*/

void initUSART(void);

/* Blocking transmit and receive functions.
   When you call receiveByte() your program will hang until
   data comes through. We'll improve on this later */

void transmitByte(uint8_t data);
uint8_t receiveByte(void);

void printString(const char myString[]); /* Utility function to transmit an entire string from RAM */

// Define a string variable, pass it to this function.
// The string will contain whatever you typed over serial
void readString(char myString[], uint8_t maxLength); 

// Prints a byte out as its 30digit ascii equivalent
void printByte(uint8_t byte);

// Prints a word (16 bits) out as its 5-digit ascii equivalent
void printWord(uint16_t word);

// Prints a byte out in 1s and 0s
char nibbleToHex(uint8_t);

// Prints a byte out in hexadecimal
void printHexByte(uint8_t);

// Takes in up to three digit ascii digits,
// converts them to a byte when press enter
uint8_t getNumber(void);

#endif


// http://edn.com/electronics-blogs/designcon-central-/4435495/10-tips-for-writing-a-great-conference-paper
// https://github.com/adamcaudill/Psychson
// http://dangerousprototypes.com/2014/10/02/derbycon-video-making-badusb-work-for-you/
// https://srlabs.de/badusb/
// http://itdc.up.edu.ph/wp-content/uploads/2013/02/Syllabus-Short-Course-Python.pdf


// Haxing
/*
http://www.offensive-security.com/metasploit-unleashed/Filesystem_And_Libraries
http://www.offensive-security.com/metasploit-unleashed/Main_Page
https://evilzone.org/tutorials/(official)-tutorial-index/
http://www.breakthesecurity.com/
http://www.hacking-tutorial.com/category/hacking-tutorial/#sthash.E2fvtBRG.dpbs
https://www.hackthissite.org/ --scaenixblackh0l3007YaRnAj!007
http://www.hackerhighschool.org/
https://evilzone.org/hacking-and-security/where-to-start-with-hacking/
http://www.techgrey.com/2014/10/best-hidden-android-secret-codes.html

*/

/*
http://scandalshack.com/2014/08/rewind-rihanna-goes-braless-in-gq-magazine-hq/
*/

/*
http://www.wired.com/2014/10/on-learning-by-doing/
*/

/* 
http://www.instructables.com/id/Self-Balancing-Robot/step2/Phisics/
http://www.instructables.com/id/Accelerometer-Gyro-Tutorial/
http://www.instructables.com/id/Guide-to-gyro-and-accelerometer-with-Arduino-inclu/
http://www.pieter-jan.com/node/11
http://www.intorobotics.com/accelerometer-gyroscope-and-imu-sensors-tutorials/
*/


/*
----This is for engineering education----
http://www.embedded.com/electronics-blogs/cole-bin/4437476/Educating-embedded-engineers-for-21st-Century-challenges?_mc=sm_emb
http://blogs.scientificamerican.com/guest-blog/2014/11/07/technology-revitalizes-hands-on-education-in-classrooms/
*/