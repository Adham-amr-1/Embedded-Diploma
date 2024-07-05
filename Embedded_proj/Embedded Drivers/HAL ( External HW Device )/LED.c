#include "DIO.h"

void LED_Intial(unsigned char port, unsigned char pin){
	DIO_SetPinDir(port,pin,1);
}
void LED_ON(unsigned char port, unsigned char pin){
	DIO_WritePin(port,pin,1);
}
void LED_OFF(unsigned char port, unsigned char pin){
	DIO_WritePin(port,pin,0);
}
void LED_Toggle(unsigned char port, unsigned char pin){
	DIO_TogglePin(port,pin);
}
unsigned char LED_ReadStatus(unsigned char port, unsigned char pin){
	return DIO_u8ReadPin(port,pin);
}
//-------------------------------------------------------------------
// ****** HAL Driver ******\\
// -- Second Driver Done -- \\