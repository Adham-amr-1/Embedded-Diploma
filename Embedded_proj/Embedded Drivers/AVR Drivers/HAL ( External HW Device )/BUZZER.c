#include "BUZZER.h"

void Buzzer_vintial(u8 PORT_NO, u8 PIN_NO){
	DIO_Set_Pin_Direction(PORT_NO,PIN_NO,OUTPUT);
}
void Buzzer_ON(u8 PORT_NO, u8 PIN_NO){
	DIO_Set_Pin_Direction(PORT_NO,PIN_NO,BUZZER_ON);
}
void Buzzer_OFF(u8 PORT_NO, u8 PIN_NO){
	DIO_Set_Pin_Direction(PORT_NO,PIN_NO,BUZZER_OFF);
}
void Buzzer_Toggle(u8 PORT_NO, u8 PIN_NO){
	DIO_TogglePin(PORT_NO,PIN_NO);
}
void Buzzer_Flashing(u8 PORT_NO, u8 PIN_NO, uint32 FlashingTime){
	DIO_Set_Pin_Direction(PORT_NO,PIN_NO,BUZZER_ON);
	_delay_ms(FlashingTime/4);
	DIO_Set_Pin_Direction(PORT_NO,PIN_NO,BUZZER_OFF);
	_delay_ms(FlashingTime/4);
	DIO_Set_Pin_Direction(PORT_NO,PIN_NO,BUZZER_ON);
	_delay_ms(FlashingTime/4);
	DIO_Set_Pin_Direction(PORT_NO,PIN_NO,BUZZER_OFF);
	_delay_ms(FlashingTime/4);
}
//-------------------------------------------------------------------
// ****** HAL Driver *****\\
// -- Third Driver Done -- \\
