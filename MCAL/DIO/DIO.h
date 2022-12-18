/* 
 * DIO.h
 * Author: Ahmed Ali Abd Al-Kaream
 
 * Drive the Ports of a ATmega32A
 
 * There is on enum 
 *	EN_dioError_t
 
 * There is two micros
 *	HIGH -> 1
 *	LOW -> 0
 
 * There is a three function in this driver
 *	setPinMode (uint8_t, uint8_t, uint8_t)
 *	gtPinValue (uint8_t, uint8_t, uint8_t*)
 *	setPinValue (uint8_t, uint8_t, uint8_t)
 *	togglePin (uint8_t , uint8_t)
 */

#ifndef DIO_H
#define	DIO_H

// include library and '.h' files  
#include "../../Utilities/STD_Type.h"
#include "../../Utilities/Regester.h"

// define the Error State ENUM 
typedef enum EN_dioError_t
{
	OK_DIO, 
	ERROR_Name,
	ERROR_Val
}EN_dioError_t;

// Micros	
#define HIGH 1
#define LOW 0

// function prototype 
EN_dioError_t setPinMode (uint8_t Port_Name, uint8_t Pin_Num, uint8_t Pin_Mode);	// set the direction of the port
EN_dioError_t getPinValue (uint8_t Port_Name, uint8_t Pin_Num, uint8_t* val);	// read the value of the port
EN_dioError_t setPinValue (uint8_t Port_Name, uint8_t Pin_Num, uint8_t Pin_Value);	 // set the value of the port
EN_dioError_t togglePin (uint8_t Port_Name, uint8_t Pin_Num);	// Toggle pin value


#endif /* DIO_H */

