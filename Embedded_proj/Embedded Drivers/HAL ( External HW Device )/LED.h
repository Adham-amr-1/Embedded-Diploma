/*
 * LED.h
 *
 * Created: 4 / 7 / 2024 10:36:16 PM
 *  Author: Adham Amr
 */ 


#ifndef LED_H_
#define LED_H_

/*
	Function Name        : LED_Intial
	Function Returns     : void
	Function Arguments   : unsigned char port,unsigned char pin
	Function Description : Initialize the pin as an output pin to connect the led.
*/
void LED_Intial(unsigned char port, unsigned char pin);

/*
	Function Name        : LED_ON
	Function Returns     : void
	Function Arguments   : unsigned char port,unsigned char pin
	Function Description : Turn on the led connected to the given pin and port.
*/
void LED_ON(unsigned char port, unsigned char pin);

/*
	Function Name        : LED_OFF
	Function Returns     : void
	Function Arguments   : unsigned char port,unsigned char pin
	Function Description : Turn off the led connected to the given pin and port.
*/
void LED_OFF(unsigned char port, unsigned char pin);

/*
	Function Name        : LED_Toggle
	Function Returns     : void
	Function Arguments   : unsigned char port,unsigned char pin
	Function Description : Toggle the led connected to the given pin and port.
*/
void LED_Toggle(unsigned char port, unsigned char pin);

/*
	Function Name        : LED_ReadStatus
	Function Returns     : unsigned char
	Function Arguments   : unsigned char port,unsigned char pin
	Function Description : Return the status of LED ( ON { 1 } or OFF { 0 } ).
*/
unsigned char LED_ReadStatus(unsigned char port, unsigned char pin);
#endif /* LED_H_ */