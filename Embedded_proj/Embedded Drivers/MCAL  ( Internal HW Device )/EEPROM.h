/*
 * EEPROM.h
 *
 * Created: 6 / 18 / 2024 6:36:16 PM
 *  Author: Adham Amr
 */ 
#ifndef EEPROM_H_
#define EEPROM_H_

/*
	Function Name        : EEPROM_Write
	Function Returns     : void
	Function Arguments   : unsigned short address ,unsigned char data
	Function Description : Write One Byte Data On EEPROM.
*/
void EEPROM_Write(unsigned short address , unsigned char data);

/*
	Function Name        : EEPROM_Read
	Function Returns     : unsigned char
	Function Arguments   : const unsigned short address 
	Function Description : Read One Byte Data From EEPROM and returns The Data.
*/
unsigned char EEPROM_Read(const unsigned short address);

#endif /* EEPROM_H_ */