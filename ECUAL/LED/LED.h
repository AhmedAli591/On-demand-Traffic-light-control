/* 
 * LED.h
 * Author: Ahmed Ali Abd Al-Kaream
 
 * Drive the LED
 
 * There is on enum 
 *	EN_ledError_t
 
 * There is a Four function in this driver
 *	led_int (uint8_t, uint8_t) 
 *	Len_on (uint8_t, uint8_t)
 *	Len_off (uint8_t, uint8_t)
 *	Led_toggle (uint8_t, uint8_t)
 */


#ifndef LED_H
#define LED_H

#include "../../MCAL/Timer/Timer.h"

// define the Error State ENUM
typedef enum EN_ledError_t
{
	OK_LED,
	ERROR
}EN_ledError_t;

// function prototype
EN_ledError_t led_int (uint8_t Port_Name, uint8_t Pin_Num);	//initialize the led port
EN_ledError_t Led_on (uint8_t Port_Name, uint8_t Pin_Num);	//turn led on
EN_ledError_t Led_off (uint8_t Port_Name, uint8_t Pin_Num);	//turn led off
EN_ledError_t Led_toggle (uint8_t Port_Name, uint8_t Pin_Num);	//Toggle every Time2 sec

#endif /* LED_H */