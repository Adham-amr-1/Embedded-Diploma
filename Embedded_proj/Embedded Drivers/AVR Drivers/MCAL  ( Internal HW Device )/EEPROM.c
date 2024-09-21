#include "EEPROM.h"

void EEPROM_Write(u16 ADDRESS , u8 DATA){
	/* Set Up Address Register */
	EEARL = (u8) ADDRESS; 
	EEARH = (u8) (ADDRESS>>EIGHT); 
	/* Set Up Data */
	EEDR = DATA;
	/* Write Logical one To EEMWE */
	SET_BIT(EECR,EEMWE);
	/* Start To Write On EEPROM by Setting EEWE */
	SET_BIT(EECR,EEWE);
	/* Wait For Completion of writing operation */
	while(READ_BIT(EECR,EEWE)==HIGH);
}

u8 EEPROM_Read(const u16 ADDRESS){
	/* Set Up Address Register */
	EEARL = (u8) ADDRESS;
	EEARH = (u8) (ADDRESS>>EIGHT);
	/* Start To Read On EEPROM by Setting EERE */
	SET_BIT(EECR,EERE);
	/* Return Data From data register */
	return EEDR;
}