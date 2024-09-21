#include "DIO.h"
#include "STD_Macros.h"
#include "STD_Types.h"
#include "Registers.h"
#define USED_PORT 'D'
#define ROWS 4
#define COLUMNS 4

#ifndef KEYPAD_H_
#define KEYPAD_H_
/*
	Function Name        : Keypad_vinit
	Function Returns     : void
	Function Arguments   : void
	Function Description : Initialize the Keypad pins
*/
void Keypad_vinit();

/*
	Function Name        : Keypad_u8Read
	Function Returns     : u8
	Function Arguments   : void
	Function Description : Check if there's button pressed or not
*/
u8 Keypad_u8Read();
#endif /* KEYPAD_H_ */
