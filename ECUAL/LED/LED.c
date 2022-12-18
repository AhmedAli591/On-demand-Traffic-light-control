/* 
 * LED.c
 * Author: Ahmed Ali Abd Al-Kareem
 
 * Drive the LED
 
 * There is a Four function in this driver
 *	led_int (uint8_t, uint8_t)
 *	Len_on (uint8_t, uint8_t)
 *	Len_off (uint8_t, uint8_t)
 *	Led_toggle (uint8_t, uint8_t)
 */

#include "LED.h"

EN_ledError_t led_int (uint8_t Port_Name, uint8_t Pin_Num)	//initialize the led port
{
	EN_dioError_t DioState = OK_DIO;
	EN_ledError_t LedState = OK_LED;
	
	DioState = setPinMode(Port_Name,Pin_Num,'O');	// make port as output
	
	if (DioState != OK_DIO)	// Test For Error
	{
		LedState = ERROR;
	}
	return LedState;
}

EN_ledError_t Led_on (uint8_t Port_Name, uint8_t Pin_Num)	//turn led on
{
		EN_dioError_t DioState = OK_DIO;
		EN_ledError_t LedState = OK_LED;
		
		DioState = setPinValue(Port_Name,Pin_Num,HIGH); // Led on
		
		if (DioState != OK_DIO)	// Test For Error
		{
			LedState = ERROR;
		}
		return LedState;
}

EN_ledError_t Led_off (uint8_t Port_Name, uint8_t Pin_Num)	//turn led off
{
	EN_dioError_t DioState = OK_DIO;
	EN_ledError_t LedState = OK_LED;
	
	DioState = setPinValue(Port_Name,Pin_Num,LOW); // Led off
	
	if (DioState != OK_DIO)	// Test For Error
	{
		LedState = ERROR;
	}
	return LedState;
}

EN_ledError_t Led_toggle (uint8_t Port_Name, uint8_t Pin_Num)	//Toggle every Time2 sec
{
		EN_dioError_t State_dio = OK_DIO;	// State Variable for DIO return
		EN_ledError_t State = OK_LED;
		
		State_dio = Led_on(Port_Name,Pin_Num);	//on
		delay_ms(Time2);
		
		State_dio = Led_off(Port_Name,Pin_Num);	//off
		delay_ms(Time2);
		
		if (State_dio != OK_DIO)
		{
			State = ERROR;
		}
		return State;
}