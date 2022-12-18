/* 
 * DIO.c
 * Author: Ahmed Ali Abd Al-Kaream
 
 * Drive the Ports of a ATmega32A
 
 * There is a three function in this driver
 *	setPinMode (uint8_t, uint8_t, uint8_t)
 *	gtPinValue (uint8_t, uint8_t, uint8_t*)
 *	setPinValue (uint8_t, uint8_t, uint8_t)
 *	togglePin (uint8_t , uint8_t)
 */

#include "DIO.h"

EN_dioError_t setPinMode (uint8_t Port_Name, uint8_t Pin_Num, uint8_t Pin_Mode)	// set the direction of the port
{
	EN_dioError_t State = OK_DIO;	// for return the State of the function
	volatile uint8_t *Reg;	// to hold the register address
	
	switch (Port_Name)	// select port register
	{
		case 'A':
		case 'a':
			Reg = &DDRA;	// for port A
		break;
		
		case 'B':
		case 'b':
			Reg = &DDRB;	// for port B
		break;
		
		case 'D':
		case 'd':
			Reg = &DDRD;	// for port D
		break;
		
		default:
			State = ERROR_Name;
	}
	
	if (State == ERROR_Name);
	
	else if (Pin_Mode == 'I' || Pin_Mode == 'i')	//Enter 'I' for an Input
	{
		*Reg &= ~(1<<Pin_Num);
	}
	else if (Pin_Mode == 'O' || Pin_Mode == 'o')	//Enter 'O' for an Output 
	{
		*Reg |= (1<<Pin_Num);
	}
	else 
	{
		State = ERROR_Val;
	}
	return State;
}



EN_dioError_t getPinValue (uint8_t Port_Name, uint8_t Pin_Num, uint8_t* val)	// read the value of the port
{
    EN_dioError_t State = OK_DIO;	// for return the State of the function
    	
    switch (Port_Name)	// select port register
    {
	    case 'A':
	    case 'a':
			*val = PinA;	// for port A
	    break;
	    	
	    case 'B':
	    case 'b':
			*val = PinB;	// for port B
	    break;
		
		case 'D':
		case 'd':
			*val = PinD;	// for port D
		break;
	    	
	    default:
	    State = ERROR_Name;
    }
	
	if (State == ERROR_Name);
	
	else
	{
	*val &= (1<<Pin_Num);	// To Find Bit Value
	*val = (*val >> Pin_Num);	// Sift the bit value to bit0
	}
	
	return State;
}



EN_dioError_t setPinValue (uint8_t Port_Name, uint8_t Pin_Num, uint8_t Pin_Value)
{
    EN_dioError_t State = OK_DIO;	// for return the State of the function
    volatile uint8_t *Reg;	// to hold the register address

    switch (Port_Name)	// select port register
    {
	    case 'A':
	    case 'a':
			Reg = &PortA;	// for port A
	    break;
	    
	    case 'B':
	    case 'b':
			Reg = &PortB;	// for port B
	    break;
		
		case 'D':
		case 'd':
			Reg = &PortD;	// for port D
		break;
	    
	    default:
	    State = ERROR_Name;
    }
	
	if (State == ERROR_Name);
	
	else if (Pin_Value == LOW)
	{
		*Reg &= ~(1 << Pin_Num); //To Clear Bit
	}
	else if (Pin_Value == HIGH)
	{
		*Reg |= 1 << Pin_Num; //To Set Bit
	}
    return State;
}



EN_dioError_t togglePin (uint8_t Port_Name, uint8_t Pin_Num)
{
	EN_dioError_t State = OK_DIO;	// for return the State of the function
	volatile uint8_t *Reg;	// to hold the register address

	switch (Port_Name)	// select port register
	{
		case 'A':
		case 'a':
		Reg = &PortA;	// for port A
		break;
		
		case 'B':
		case 'b':
		Reg = &PortB;	// for port B
		break;
		
		case 'D':
		case 'd':
		Reg = &PortD;	// for port D
		break;
		
		default:
		State = ERROR_Name;
	}
	
	if (State == ERROR_Name);
	
	else
	{
		*Reg ^= (1 << Pin_Num); //To Toggle Bit
	}
	return State;
}