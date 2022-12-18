/* 
 * Interrupt.h
 * Author: Ahmed Ali Abd Al-Kaream
 
 * Drive the Interrupt at ATmega32A
 
 * There is a Tow function in this driver
 *	void timer_int(void)
 *	void delay_ms (uint32_t counter)
 */


#ifndef INTERRUPT_H
#define INTERRUPT_H

//Library include
#include "../Timer/Timer.h"
#include "../../ECUAL/LED/LED.h"

// Extern Interrupt Request 0
#define EXT_INT_0 __vector_1

// Micro define the ISR
#define ISR(INT_VECT) void INT_VECT(void) __attribute__ ((signal,used));\
void INT_VECT(void)

// Micro Number Bit
#define GIE 7	// Global INT Enable - Bit 7
#define ISC00 0	// Sense Mode - Bit 0
#define ISC01 1 // Sense Mode - Bit 1
#define INT0 6	// INT0 Enable - Bit 6

#define car_red 0		// PORTA - 0
#define car_yellow 1	// PORTA - 1
#define car_green 2		// PORTA - 2

#define pas_red 0		// PORTB - 0
#define pas_yellow 1	// PORTB - 1
#define pas_green 2		// PORTB - 2


// define the Error State ENUM
typedef enum EN_intError_t
{
	OK_int,
	ERROR_int
}EN_intError_t;

// Function Prototype
EN_intError_t INT_intialize (void);
void yellow_toggle_int ();											// Toggle all yellow 
void yellow_toggle_one (uint8_t Port_Name, uint8_t Pin_Num);		// Toggle on port


#define Test 0	// 0 For Normal, 1 For Test


#endif /* INTERRUPT_H */