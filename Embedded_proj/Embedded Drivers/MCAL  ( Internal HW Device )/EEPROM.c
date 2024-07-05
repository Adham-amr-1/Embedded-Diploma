#include <avr/io.h>
#include "std_macros.h"

void EEPROM_Write(unsigned short address , unsigned char data){
	/* Set Up Address Register */
	EEARL = (char) address; 
	EEARH = (char) (address>>8); 
	/* Set Up Data */
	EEDR = data;
	/* Write Logical one To EEMWE */
	SET_BIT(EECR,EEMWE);
	/* Start To Write On EEPROM by Setting EEWE */
	SET_BIT(EECR,EEWE);
	/* Wait For Completion of writing operation */
	while(READ_BIT(EECR,EEWE)==1);
}

unsigned char EEPROM_Read(const unsigned short address){
	/* Set Up Address Register */
	EEARL = (char) address;
	EEARH = (char) (address>>8);
	/* Start To Read On EEPROM by Setting EERE */
	SET_BIT(EECR,EERE);
	/* Return Data From data register */
	return EEDR;
}