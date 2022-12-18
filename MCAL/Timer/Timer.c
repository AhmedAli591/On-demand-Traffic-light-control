/* 
 * Timer.c
 * Author: Ahmed Ali Abd Al-Kaream
 
 * Drive the Delay at ATmega32A
 
 * There is a Tow function in this driver
 *	void timer_int(void)
 *	void delay_ms (uint32_t counter)
 */

#include "Timer.h"

void timer_int(void)
{
	// Normal Mode Counter 
	T0_CONTROL = 0x00;
	// Intial Value = 0;
	T0_COUNTER = 0x00;
}

void delay_ms (uint32_t counter)
{
	// Timer initialization 
	timer_int();
	
	while (counter > 0)
	{
		// Save counter value for testing
		uint8_t hold = counter;
		
		// Set The Intial Value To 131;
		T0_COUNTER = 131;
		
		// Set The Prescaling to 8
		T0_CONTROL |= (1<<1);
		
		// wait to the over flow
		while (((T0_FLAG & (1<<0)) == 0))
		{
			// To solve the multi-call problem
			if (T0_COUNTER < 131)
			{
				// If Counter initial value is = Time2 exit the delay after the interrupt 
				if (hold == Time2)
					counter = 1;
				break;
			}
		}
		
		// timer off
		T0_CONTROL = 0x00;
		
		// clear Flag
		T0_FLAG |= (1<<0);
		
		counter--;
	} 
}