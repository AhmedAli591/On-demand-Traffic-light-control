/* 
 * App.h
 * Author: Ahmed Ali Abd Al-Kaream
 
 * Drive the App-run at ATmega32A
 
 * There is a Three function in this driver
 *	void App_int ()
 *	void APP_Start ()
 */


#ifndef APP_H_
#define APP_H_

//Library include
#include "../../MCAL/Interrupt/interrupt.h"

// function prototype
void App_int ();	// Initialization Modules
void APP_Start ();
EN_ledError_t Red_Mode (uint8_t Mode);
EN_ledError_t Green_Mode (uint8_t Mode);
void yellow_toggle ();	// Handel Call in yellow mode



#endif /* APP_H_ */