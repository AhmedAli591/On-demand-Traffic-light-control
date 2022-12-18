/* 
 * Timer.h
 * Author: Ahmed Ali Abd Al-Kaream
 
 * Drive the Delay at ATmega32A
 
 * There is a Tow function in this driver
 *	void timer_int(void)
 *	void delay_ms (uint32_t counter)
 */


#ifndef TIMER_H_
#define TIMER_H_

// Library include
#include "../DIO/DIO.h"

// Micro
#define Time1 5000	// Time for red-green
#define  Time2 500	// Time for the Toggle 

// Function Prototype
void timer_int(void);
void delay_ms (uint32_t counter);


#endif /* TIMER_H_ */