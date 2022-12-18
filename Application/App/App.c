/* 
 * App.c
 * Author: Ahmed Ali Abd Al-Kaream
 
 * Drive the App-run at ATmega32A
 
 * There is a Three function in this driver
 *	void App_int ()
 *	void APP_Start ()
 */

#include "App.h"

void App_int ()	// Initialization Modules
{
	// for ERROR Return
	EN_ledError_t St_LED = OK_LED;
	EN_intError_t St_INT = OK_int;
	
	// Initialization
	St_LED = led_int('A',car_red);		// Car Red
	
	St_LED = led_int('A',car_green);	// Car Green

	St_LED = led_int('A',car_yellow);	// Car Yellow
	
	St_LED = led_int('B',pas_red);		// Pas Red

	St_LED = led_int('B',pas_green);	//Pas Green

	St_LED = led_int('B',pas_yellow);	//Pas Yellow
	
	// INT0
	St_INT = INT_intialize();			
	
}

void APP_Start ()
{
	// for ERROR Return
	EN_ledError_t St_LED = OK_LED;
	
	while (St_LED == OK_LED)
	{
		
		St_LED = Led_on ('A',car_red);			// Car Red on
		St_LED = Led_on('B',pas_green);
		
		delay_ms(Time1);
		
		yellow_toggle ();
		
		St_LED = Led_off ('A',car_red);			// Car Red off
		St_LED = Led_on ('A',car_green);		// Car green on
		
		St_LED = Led_off('B',pas_green);		// pas green off
		St_LED = Led_on('B',pas_red);			// pas red on
		
		delay_ms(Time1);
		
		yellow_toggle ();

		St_LED = Led_off ('A',car_green);		// Car green off
		St_LED = Led_off('B',pas_red);			// pas red off
	}

}

void yellow_toggle ()	// Handel Call in yellow mode
{
	
	SREG &= ~(1<<GIE);
	
	EN_ledError_t State;
	
	uint8_t counter = 5;
	
	while (counter > 0)
	{
		if (GIFR & (1<<6))
		{
			State = Led_on('A',car_yellow);
			SREG |= (1<<GIE);
			break;
		}
	
		State = Led_on ('A',car_yellow);
		State = Led_on ('B',pas_yellow);
		delay_ms(Time2);
		State = Led_off ('A',car_yellow);
		State = Led_off ('B',pas_yellow);
		
		delay_ms(Time2);
		counter-- ;
	}
	SREG |= (1<<GIE);

}
