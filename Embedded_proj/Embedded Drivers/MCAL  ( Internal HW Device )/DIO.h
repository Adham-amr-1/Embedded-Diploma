/*
 * DIO.h
 *
 * Created: 4 / 6 / 2024 11:36:16 PM
 *  Author: Adham Amr
 */ 


#ifndef DIO_H_
#define DIO_H_
/*
	Function Name        : DIO_SetPinDir
	Function Returns     : void
	Function Arguments   : unsigned char port,unsigned char pin,unsigned char dir
	Function Description : Set the direction of the given pin in the given port (dir 0 = input : 1 = output)
*/
void DIO_SetPinDir(unsigned char port,unsigned char pin,unsigned char dir);

/*
	Function Name        : DIO_WritePin
	Function Returns     : void
	Function Arguments   : unsigned char port,unsigned char pin,unsigned char output
	Function Description : Set the value of the given pin in the given port (output 0 = low : 1 = high) 
*/
void DIO_WritePin(unsigned char port,unsigned char pin,unsigned char output);

/*
	Function Name        : DIO_u8ReadPin
	Function Returns     : unsigned char
	Function Arguments   : unsigned char port,unsigned char pin
	Function Description : Returns 1 if the value of the given pin is high and zero if the value is low
*/
unsigned char DIO_u8ReadPin(unsigned char port, unsigned char pin);

/*
	Function Name        : DIO_TogglePin
	Function Returns     : void
	Function Arguments   : unsigned char port,unsigned char pin
	Function Description : Reverse the value of the given pin in the given port.
*/
void DIO_TogglePin(unsigned char port,unsigned char pin);

/*
	Function Name        : DIO_SetPortDir
	Function Returns     : void
	Function Arguments   : unsigned char port,unsigned char dir
	Function Description : set the direction of whole port .
*/

void DIO_SetPortDir(unsigned char port, unsigned char dir);

/*
	Function Name        : DIO_WritePort
	Function Returns     : void
	Function Arguments   : unsigned char port,unsigned char outputvalue
	Function Description : Write the value to all port pins.
*/

void DIO_WritePort(unsigned char port, unsigned char outputvalue);

/*
	Function Name        : DIO_ReadPort
	Function Returns     : unsigned char
	Function Arguments   : unsigned char port
	Function Description : read the value of the port .
*/
unsigned char DIO_ReadPort(unsigned char port);

/*
	Function Name        : DIO_TogglePort
	Function Returns     : void
	Function Arguments   : unsigned char port
	Function Description : toggle the value of the port .
*/
void DIO_TogglePort(unsigned char port);

/*
	Function Name        : DIO_PullUpActive
	Function Returns     : void
	Function Arguments   : unsigned char port,unsigned char pin
	Function Description : Active the Internal Pull Up Resistance .
*/
void DIO_PullUpActive(unsigned char port, unsigned char pin);

/*
	Function Name        : DIO_PullUpDeActive
	Function Returns     : void
	Function Arguments   : unsigned char port,unsigned char pin
	Function Description : DisActive the Internal Pull Up Resistance .
*/
void DIO_PullUpDeActive(unsigned char port, unsigned char pin);

/*
	Function Name        : DIO_WriteLowNibble
	Function Returns     : void
	Function Arguments   : unsigned char port,unsigned char value
	Function Description :   Write on the Pins from 0 to 3
*/
void DIO_WriteLowNibble(unsigned char port, unsigned char value);

/*
	Function Name        : DIO_WriteHighNibble
	Function Returns     : void
	Function Arguments   : unsigned char port,unsigned char value
	Function Description : Write on the Pins from 4 to 7
*/
void DIO_WriteHighNibble(unsigned char port, unsigned char value);


/*
	Function Name        : DIO_SetHighNibbleDir
	Function Returns     : void
	Function Arguments   : unsigned char port,unsigned char dir
	Function Description : Set Direction of the Pins from 4 to 7
*/
void DIO_SetHighNibbleDir(unsigned char port, unsigned char dir);

/*
	Function Name        : DIO_SetLowNibbleDir
	Function Returns     : void
	Function Arguments   : unsigned char port,unsigned char value
	Function Description : Set Direction of the Pins from 0 to 3
*/
void DIO_SetLowNibbleDir(unsigned char port, unsigned char dir);
#endif /* DIO_H_ */
