/*
 * Interrupt_Test.c
 *
 * Created: 12/7/2022 6:49:39 PM
 *  Author: Ahmed Ali
 */ 


#include "Test.h"

void Interrupt_Test (void)
{
	EN_intError_t Stat = OK_int;
	
	Stat = INT_intialize();
	
	delay_ms(500);
}

#if (Test == 1)

ISR (EXT_INT_0)
{
	EN_dioError_t Stat = OK_DIO;
	Stat = setPinMode('A',0,'O');
	Stat = setPinValue('A',2,HIGH);
	delay_ms(1000);
	Stat = setPinValue('A',3,LOW);
}

#endif
