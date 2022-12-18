/*
 * Led_Test.c
 *
 * Created: 12/7/2022 6:49:56 PM
 *  Author: Ahmed Ali
 */ 

#include "Test.h"

void Led_Test (void)
{
	EN_ledError_t Stat = OK_LED;
	
	Stat = led_int('A',0);
	Stat = led_int('A',1);
	Stat = led_int('A',2);
	
	Stat = Led_on('A',0);
	Stat = Led_on('A',1);

	Stat = Led_off('A',0);
	Stat = Led_off('A',1);
	
	Stat = Led_toggle('A',2);
	Stat = Led_toggle('A',1);
}