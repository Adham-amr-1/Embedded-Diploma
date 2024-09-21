#include "DIO.h"
void SevenSegBCD_init(unsigned char port, unsigned char Lownibble){
	if (Lownibble == 1) {
		DIO_SetPinDir(port,0,1);
		DIO_SetPinDir(port,1,1);
		DIO_SetPinDir(port,2,1);
		DIO_SetPinDir(port,3,1);
	}
	else{
		DIO_SetPinDir(port,4,1);
		DIO_SetPinDir(port,5,1);
		DIO_SetPinDir(port,6,1);
		DIO_SetPinDir(port,7,1);
	}
}
void SevenSegBCD_write(unsigned char port,unsigned char value,unsigned char Lownibble){
	if (Lownibble == 1)
	{
		DIO_WriteLowNibble(port,value);
	}
	else{
		DIO_WriteHighNibble(port,value);
	}
}


	
