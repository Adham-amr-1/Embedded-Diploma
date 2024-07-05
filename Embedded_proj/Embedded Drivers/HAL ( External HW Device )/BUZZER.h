/*
 * LED.h
 *
 * Created: 4 / 7 / 2024 10:36:16 PM
 *  Author: Adham Amr
 */ 


#ifndef BUZZER_H_
#define BUZZER_H_

/*
	Function Name        : Buzzer_Intial
	Function Returns     : void
	Function Arguments   : unsigned char port,unsigned char pin
	Function Description : Initialize the pin as an output pin to connect the Buzzer.
*/
void Buzzer_Intial(unsigned char port, unsigned char pin);

/*
	Function Name        : Buzzer_ON
	Function Returns     : void
	Function Arguments   : unsigned char port,unsigned char pin
	Function Description : Turn on the Buzzer connected to the given pin and port.
*/
void Buzzer_ON(unsigned char port, unsigned char pin);

/*
	Function Name        : Buzzer_OFF
	Function Returns     : void
	Function Arguments   : unsigned char port,unsigned char pin
	Function Description : Turn off the Buzzer connected to the given pin and port.
*/
void Buzzer_OFF(unsigned char port, unsigned char pin);

/*
	Function Name        : Buzzer_Toggle
	Function Returns     : void
	Function Arguments   : unsigned char port,unsigned char pin
	Function Description : Toggle the Buzzer connected to the given pin and port.
*/
void Buzzer_Toggle(unsigned char port, unsigned char pin);

/*
	Function Name        : Buzzer_Flashing
	Function Returns     : void
	Function Arguments   : unsigned char port,unsigned char pin,int FlashingTime
	Function Description : Flashing buzzer for time ( FlashingTime ) as an alarm
*/
void Buzzer_Flashing(unsigned char port,unsigned char pin, int FlashingTime);

#endif /* BUZZER_H_ */