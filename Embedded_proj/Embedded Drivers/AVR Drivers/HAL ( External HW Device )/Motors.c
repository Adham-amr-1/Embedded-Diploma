#include "Motors.h"

void Motors_vInit(u8 MOTORS_PORT, u8 NIBBLE){
	switch(NIBBLE){
	case HIGH:
		DIO_Set_High_Nibble_Direction(MOTORS_PORT, OUTPUT);
		break;
	case LOW:
		DIO_Set_Low_Nibble_Direction(MOTORS_PORT, OUTPUT);
		break;
	}
}

void Move_Forward(u8 MOTORS_PORT, u8 NIBBLE){
	switch(NIBBLE){
	case HIGH:
		DIO_Write_Pin(MOTORS_PORT, 4, HIGH);
		DIO_Write_Pin(MOTORS_PORT, 5, LOW);
		DIO_Write_Pin(MOTORS_PORT, 6, HIGH);
		DIO_Write_Pin(MOTORS_PORT, 7, LOW);
		break;
	case LOW:
		DIO_Write_Pin(MOTORS_PORT, 0, HIGH);
		DIO_Write_Pin(MOTORS_PORT, 1, LOW);
		DIO_Write_Pin(MOTORS_PORT, 2, HIGH);
		DIO_Write_Pin(MOTORS_PORT, 3, LOW);
		break;
	}
}

void Move_Backward(u8 MOTORS_PORT, u8 NIBBLE){
	switch(NIBBLE){
	case HIGH:
		DIO_Write_Pin(MOTORS_PORT, 4, LOW);
		DIO_Write_Pin(MOTORS_PORT, 5, HIGH);
		DIO_Write_Pin(MOTORS_PORT, 6, LOW);
		DIO_Write_Pin(MOTORS_PORT, 7, HIGH);
		break;
	case LOW:
		DIO_Write_Pin(MOTORS_PORT, 0, LOW);
		DIO_Write_Pin(MOTORS_PORT, 1, HIGH);
		DIO_Write_Pin(MOTORS_PORT, 2, LOW);
		DIO_Write_Pin(MOTORS_PORT, 3, HIGH);
		break;
	}
}

void Move_Left(u8 MOTORS_PORT, u8 NIBBLE){
	switch(NIBBLE){
	case HIGH:
		DIO_Write_Pin(MOTORS_PORT, 4, HIGH);
		DIO_Write_Pin(MOTORS_PORT, 5, LOW);
		DIO_Write_Pin(MOTORS_PORT, 6, LOW);
		DIO_Write_Pin(MOTORS_PORT, 7, HIGH);
		break;
	case LOW:
		DIO_Write_Pin(MOTORS_PORT, 0, HIGH);
		DIO_Write_Pin(MOTORS_PORT, 1, LOW);
		DIO_Write_Pin(MOTORS_PORT, 2, LOW);
		DIO_Write_Pin(MOTORS_PORT, 3, HIGH);
		break;
	}
}

void Move_Right(u8 MOTORS_PORT, u8 NIBBLE){
	switch(NIBBLE){
	case HIGH:
		DIO_Write_Pin(MOTORS_PORT, 4, LOW);
		DIO_Write_Pin(MOTORS_PORT, 5, HIGH);
		DIO_Write_Pin(MOTORS_PORT, 6, HIGH);
		DIO_Write_Pin(MOTORS_PORT, 7, LOW);
		break;
	case LOW:
		DIO_Write_Pin(MOTORS_PORT, 0, LOW);
		DIO_Write_Pin(MOTORS_PORT, 1, HIGH);
		DIO_Write_Pin(MOTORS_PORT, 2, HIGH);
		DIO_Write_Pin(MOTORS_PORT, 3, LOW);
		break;
	}
}

void Servo_vInit(){
	DIO_Set_Pin_Direction(PORT_D, PIN_NO_5, OUTPUT);
}

void Servo_Direction(double DEGREE){
    /* select fast PWM mode */
    SET_BIT(TCCR1A, WGM11);
    SET_BIT(TCCR1B, WGM12);
    SET_BIT(TCCR1B, WGM13);

    /* load a value in OCR1A, ICR1 */
    OCR1A = 1000 + (DEGREE*1000)/180;
    ICR1 = 19999;

    /* select timer clock, no prescaling */
    SET_BIT(TCCR1B, CS10);

    /* clear OC1A on compare match, set OC1A at BOTTOM (non-inverting mode) */
    CLEAR_BIT(TCCR1A, COM1A0);
    SET_BIT(TCCR1A, COM1A1);

}

