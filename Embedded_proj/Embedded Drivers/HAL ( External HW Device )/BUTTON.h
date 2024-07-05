/*
 * BUTTON.h
 *
 * Created: 4 / 8 / 2024 2:36:16 AM
 *  Author: Adham Amr
 */ 


#ifndef BUTTON_H_
#define	BUTTON_H_

/*
Function Name        : Button_Intial
Function Returns     : void
Function Arguments   : unsigned char port,unsigned char pin
Function Description : define the given pin in the given port as input pin
*/
void Button_Intial(unsigned char port, unsigned char pin);

/*
Function Name        : Button_u8read
Function Returns     : unsigned char
Function Arguments   : unsigned char port,unsigned char pin
Function Description : Returns 0 or 1 depend on the status of the button(pressed or not) and the type of connection (pull up or pull down)
*/
unsigned char Button_u8read(unsigned char port, unsigned char pin);


#endif /* BUTTON_H_ */
