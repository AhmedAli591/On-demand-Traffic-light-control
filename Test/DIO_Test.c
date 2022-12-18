/*
 * DIO_Test.c
 *
 * Created: 12/7/2022 6:48:54 PM
 *  Author: Ahmed Ali
 */ 

#include "Test.h"

void DIO_Test (void)
{
	EN_dioError_t Stat = OK_DIO;
	uint8_t val = 0;
	
	Stat = setPinMode('A',0,'O');
	Stat = setPinMode('A',1,'O');
	Stat = setPinMode('A',2,'O');
	Stat = setPinMode('A',3,'O');
	
	Stat = setPinMode('A',0,'I');
	Stat = setPinMode('A',1,'I');
	
	Stat = setPinValue('A',2,HIGH);
	Stat = setPinValue('A',3,LOW);
	
	Stat = togglePin('A',2);
	Stat = togglePin('A',3);
	
	Stat = getPinValue('A',0,&val);
	Stat = getPinValue('A',1,&val);
}