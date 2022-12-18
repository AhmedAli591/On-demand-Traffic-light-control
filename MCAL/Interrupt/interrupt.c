/* 
 * Interrupt.c
 * Author: Ahmed Ali Abd Al-Kaream
 
 * Drive the Interrupt at ATmega32A
 
 * There is a Tow function in this driver
 *	EN_intError_t INT_intialize (void)
 *	ISR (EXT_INT_0)
 */

#include "interrupt.h"


EN_intError_t INT_intialize (void)
{	
	EN_intError_t State = OK_int;		//State Variable for INT return
	EN_dioError_t State_dio = OK_DIO;	// State Variable for DIO return
	SREG |= (1 << GIE);	// Set the Global Interrupt Enable
	
	// The rising edge of INT0 generates an interrupt request.
	MCUCR |= (1 << ISC00); // Set the ISC00 
	MCUCR |= (1 << ISC01); // Set the ISC01
	
	// External Interrupt Request 0 Enable
	GICR |= (1 << INT0); // Enable INT0
	
	// Set PORTD - 2 AS INPUT
	State_dio = setPinMode('D',2,'I');
	
	if (State_dio != OK_DIO)
	{
		State = ERROR_int;
	}
	
	return State;
}


#if (Test == 0)

ISR (EXT_INT_0)
{
	uint8_t val[3] = {0};
	
	EN_dioError_t State_dio = OK_DIO;	// State Variable for DIO return
	
	// Get car led values	
	State_dio = getPinValue('A',car_red,&val[0]);
	State_dio = getPinValue('A',car_green,&val[1]);
	State_dio = getPinValue('A',car_yellow,&val[2]);
		
	if (val[0] == HIGH && val[2] == LOW)		// Red is HIGH
	{
		// Nothing happened
	}
	
	else if (val[1] == HIGH && val[2] == LOW)	// Green is HIGH
	{
		// car yellow Toggle = 1
		yellow_toggle_int();
				
		State_dio = setPinValue('A',car_red,HIGH);		//car red = 1
		State_dio = setPinValue('B',pas_red,LOW);		//pas red = 0
		State_dio = setPinValue('B',pas_green,HIGH);	//Pas Green = 1
		State_dio = setPinValue('A',car_green,LOW);		//car green = 0
		delay_ms(Time1);
				
		yellow_toggle_int();							// Yellow Toggle				

		State_dio = setPinValue('B',pas_red,HIGH);		//Pas red = 1
		State_dio = setPinValue('A',car_green,HIGH);    //car green = 1
		State_dio = setPinValue('A',car_red,LOW);       //car red = 0
		State_dio = setPinValue('B',pas_green,LOW);     //Pas Green = 0
	}
	else										//yellow is on
	{
		uint8_t test = 0;
		State_dio = getPinValue('A',car_green,&test);
		
		yellow_toggle_int();							// Yellow Toggle
		
		State_dio = setPinValue('A',car_green,LOW);		// car green = 0
		State_dio = setPinValue('A',car_red,HIGH);		// car red = 1
		State_dio = setPinValue('B',pas_red,LOW);		// car red = 1
		State_dio = setPinValue('B',pas_green,HIGH);	// Pas Green = 1
		
		delay_ms(Time1);
		
		yellow_toggle_int();							// Yellow Toggle
		
		State_dio = setPinValue('B',pas_green,LOW);		// Pas Green = 0
	
		State_dio = setPinValue('B',pas_red,HIGH);		// Pas Red = 1
		
		if (test == HIGH)	// if the green is high
		{
			State_dio = setPinValue('A',car_red,LOW);
			State_dio = setPinValue('A',car_green,HIGH);
			delay_ms(Time1);
			yellow_toggle_int();
			State_dio = setPinValue('A',car_green,LOW);
		}
	}	
}
#endif

void yellow_toggle_int ()		// Toggle all yellow 
{
	
	EN_dioError_t State_dio = OK_DIO;	// State Variable for DIO return
	uint8_t counter = 5;
	while (counter > 0)
	{
		State_dio = setPinValue ('A',car_yellow,HIGH);
		State_dio = setPinValue ('B',pas_yellow,HIGH);
		delay_ms(Time2);
		
		State_dio = setPinValue ('A',car_yellow,LOW);
		State_dio = setPinValue ('B',pas_yellow,LOW);
		delay_ms(Time2);
		
		counter --;
	}
}

void yellow_toggle_one (uint8_t Port_Name, uint8_t Pin_Num)			// Toggle on port
{
	
	EN_ledError_t (*Led_toggle_sec) (uint8_t, uint8_t) = Led_toggle;	// Pointer to function
	EN_ledError_t State;
	uint8_t counter = 5;
	while (counter > 0)
	{
		State = Led_toggle_sec (Port_Name,Pin_Num);
		counter-- ;
	}
}