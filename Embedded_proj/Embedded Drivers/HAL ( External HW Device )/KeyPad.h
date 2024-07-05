#include "DIO.h"
#define NOTPRESSED 0xff
#define USED_PORT 'D'


#ifndef KEYPAD_H_
#define KEYPAD_H_
/*
	Function Name        : Keypad_Init
	Function Returns     : void
	Function Arguments   :	void
	Function Description : Initialize the Keypad pins
*/
void Keypad_Init();

/*
	Function Name        : Keypad_u8Read
	Function Returns     : unsigned char
	Function Arguments   :	void
	Function Description : Check if there's button pressed or not
*/
unsigned char Keypad_u8Read();
#endif /* KEYPAD_H_ */
