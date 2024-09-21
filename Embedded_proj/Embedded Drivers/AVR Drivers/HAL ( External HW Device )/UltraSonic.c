#include "UltraSonic.h"

void UltraSonic_vint(u8 TRIGGER_PORT, u8 TRIGGER_PIN){
	DIO_Set_Pin_Direction(TRIGGER_PORT, TRIGGER_PIN, OUTPUT);
}
void Trigger(u8 TRIGGER_PORT, u8 TRIGGER_PIN){
	DIO_Write_Pin(TRIGGER_PORT, TRIGGER_PIN, HIGH);
	_delay_us(50);
	DIO_Write_Pin(TRIGGER_PORT, TRIGGER_PIN, LOW);
}

u16 UltraSonic_ICR_Read(u8 TRIGGER_PORT, u8 TRIGGER_PIN){
	u16 Distance;
	u16 High;
	Timer1_Set_OverFlow_Mode();
	Clear_ICF1_BIT();
	Trigger(TRIGGER_PORT, TRIGGER_PIN);
	Timer1_Set_ICU_Rising_Edge();
	while(READ_BIT(TIFR,ICF1) == 0);
	u16 a = ICR1;
	Clear_ICF1_BIT();
	Timer1_Set_ICU_Falling_Edge();
	while(READ_BIT(TIFR,ICF1) == 0);
	u16 b = ICR1;
	Clear_ICF1_BIT();
	TCNT1 = 0;
	TCCR1B = 0;
	High = b - a;
	Distance = High * 2.2144;

	return Distance;
}
