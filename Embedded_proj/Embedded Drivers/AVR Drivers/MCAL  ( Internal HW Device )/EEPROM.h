/*
 * EEPROM.h
 *
 * Created: 6 / 18 / 2024 6:36:16 PM
 *  Author: Adham Amr
 */
#include "Registers.h"
#include "STD_Macros.h"
#include "STD_Types.h"

#ifndef EEPROM_H_
#define EEPROM_H_
/*
	Function Name        : EEPROM_Write
	Function Returns     : void
	Function Arguments   : u16 ADDRESS , u8 DATA
	Function Description : Write One Byte Data On EEPROM.
*/
void EEPROM_Write(u16 ADDRESS , u8 DATA);

/*
	Function Name        : EEPROM_Read
	Function Returns     : unsigned char
	Function Arguments   : const u16 ADDRESS 
	Function Description : Read One Byte Data From EEPROM and returns The Data.
*/
unsigned char EEPROM_Read(const u16 ADDRESS);

#endif /* EEPROM_H_ */