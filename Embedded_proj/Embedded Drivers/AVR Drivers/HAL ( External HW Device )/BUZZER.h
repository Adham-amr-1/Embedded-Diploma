/*
 * LED.h
 *
 * Created: 4 / 7 / 2024 10:36:16 PM
 *  Author: Adham Amr
 */ 
#define F_CPU 8000000UL
#include "DIO.h"
#include "STD_Macros.h"
#include "STD_Types.h"
#include "Registers.h"
#include <util/delay.h>
#ifndef BUZZER_H_
#define BUZZER_H_

/*
	Function Name        : Buzzer_Intial
	Function Returns     : void
	Function Arguments   : u8 PORT_NO, u8 PIN_NO
	Function Description : Initialize the pin as an output pin to connect the Buzzer.
*/
void Buzzer_Intial(u8 PORT_NO, u8 PIN_NO);

/*
	Function Name        : Buzzer_ON
	Function Returns     : void
	Function Arguments   : u8 PORT_NO, u8 PIN_NO
	Function Description : Turn on the Buzzer connected to the given pin and port.
*/
void Buzzer_ON(u8 PORT_NO, u8 PIN_NO);

/*
	Function Name        : Buzzer_OFF
	Function Returns     : void
	Function Arguments   : u8 PORT_NO, u8 PIN_NO
	Function Description : Turn off the Buzzer connected to the given pin and port.
*/
void Buzzer_OFF(u8 PORT_NO, u8 PIN_NO);

/*
	Function Name        : Buzzer_Toggle
	Function Returns     : void
	Function Arguments   : u8 PORT_NO, u8 PIN_NO
	Function Description : Toggle the Buzzer connected to the given pin and port.
*/
void Buzzer_Toggle(u8 PORT_NO, u8 PIN_NO);

/*
	Function Name        : Buzzer_Flashing
	Function Returns     : void
	Function Arguments   : u8 PORT_NO, u8 PIN_NO, uint32 FlashingTime
	Function Description : Flashing buzzer for time ( FlashingTime ) as an alarm
*/
void Buzzer_Flashing(u8 PORT_NO, u8 PIN_NO, uint32 FlashingTime);

#endif /* BUZZER_H_ */
