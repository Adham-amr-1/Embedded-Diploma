/*
* SevenSegment.c
*
* Created: 4 / 17 / 2024 7:36:16 AM
*  Author: Adham Amr
*/

#include "DIO.h"
#define COMMONCATHODE // Ba3dl Feh in case lw hasta3ml 7 Segment Common Anode bs
void SevenSeg_init(unsigned char port){
	DIO_SetPortDir(port,0xff);
}
void SevenSeg_write(unsigned char port, unsigned char number){
	#if defined COMMONCATHODE
	unsigned char arr[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x47,0x7f,0x6f};
	#else
	unsigned char arr[] = {~0x3f, ~0x06, ~0x5b, ~0x4f, ~0x66, ~0x6d, ~0x7d, ~0x47, ~0x7f, ~0x6f};
	#endif // _Checking If The Seven Segment Is CC or CA
	
	DIO_WritePort(port, arr[number]);
}
//----------------------------------------------------------------------------
// Using BCD Decoder
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

//-------------------------------------------------------------------
// ****** HAL Driver ******
// -- Fifth Driver Done -- \\