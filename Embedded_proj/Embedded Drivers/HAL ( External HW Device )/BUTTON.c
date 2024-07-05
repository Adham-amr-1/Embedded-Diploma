/*
 *	BUTTON.c
 *
 * Created: 4 / 8 / 2024 2:36:16 AM
 *  Author: Adham Amr
 */ 
#include "DIO.h"

void Button_Intial(unsigned char port, unsigned char pin){
	DIO_SetPinDir(port,pin,0);
}
unsigned char Button_u8read(unsigned char port, unsigned char pin){
	return DIO_u8ReadPin(port,pin);
}
//-------------------------------------------------------------------
// ****** HAL Driver ******\\
// -- Forth Driver Done -- \\