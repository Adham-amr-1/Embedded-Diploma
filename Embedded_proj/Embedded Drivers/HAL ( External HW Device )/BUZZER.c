#include "DIO.h"

void Buzzer_Intial(unsigned char port, unsigned char pin){
	DIO_SetPinDir(port,pin,1);
}
void Buzzer_ON(unsigned char port, unsigned char pin){
	DIO_WritePin(port,pin,1);
}
void Buzzer_OFF(unsigned char port, unsigned char pin){
	DIO_WritePin(port,pin,0);
}
void Buzzer_Toggle(unsigned char port, unsigned char pin){
	DIO_TogglePin(port,pin);
}
void Buzzer_Flashing(unsigned char port,unsigned char pin, int FlashingTime){
	DIO_WritePin(port,pin,1);
	_delay_ms(FlashingTime/4);
	DIO_WritePin(port,pin,0);
	_delay_ms(FlashingTime/4);
	DIO_WritePin(port,pin,1);
	_delay_ms(FlashingTime/4);
	DIO_WritePin(port,pin,0);
	_delay_ms(FlashingTime/4);
}
//-------------------------------------------------------------------
// ****** HAL Driver *****\\
// -- Third Driver Done -- \\