/*
 * Test.h
 *
 * Created: 12/7/2022 7:01:02 PM
 *  Author: Ahmed Ali
 */ 


#ifndef TEST_H_
#define TEST_H_

#include "../ECUAL/LED/LED.h"
#include "../MCAL/Interrupt/interrupt.h"


void Led_Test (void);
void Interrupt_Test (void);
ISR (EXT_INT_0);
//void Timer_Test (void);
void DIO_Test (void);




#endif /* TEST_H_ */