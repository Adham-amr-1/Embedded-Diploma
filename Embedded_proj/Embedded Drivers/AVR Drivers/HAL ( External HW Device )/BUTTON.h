/*
 * BUTTON.h
 *
 * Created: 4 / 8 / 2024 2:36:16 AM
 *  Author: Adham Amr
 */ 
#include "DIO.h"
#include "STD_Macros.h"
#include "STD_Types.h"
#include "Registers.h"

#ifndef BUTTON_H_
#define	BUTTON_H_

/*
Function Name        : Button_vintial
Function Returns     : void
Function Arguments   : u8 PORT_NO, u8 PIN_NO
Function Description : define the given pin in the given port as input pin
*/
void Button_vintial(u8 PORT_NO, u8 PIN_NO);

/*
Function Name        : Button_u8read
Function Returns     : unsigned char
Function Arguments   : u8 PORT_NO, u8 PIN_NO
Function Description : Returns 0 or 1 depend on the status of the button(pressed or not) and the type of connection (pull up or pull down)
*/
unsigned char Button_u8read(u8 PORT_NO, u8 PIN_NO);


#endif /* BUTTON_H_ */
