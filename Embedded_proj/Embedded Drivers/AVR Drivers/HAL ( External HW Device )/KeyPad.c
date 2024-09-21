#include "KeyPad.h"

void Keypad_vinit(){
	// Keypad Rows
	DIO_Set_Low_Nibble_Direction(USED_PORT,OUTPUT);
	// Keypad Columns
	DIO_Set_High_Nibble_Direction(USED_PORT,INPUT);
	// Set Pull up
	DIO_PullUp_Active(USED_PORT,PIN_NO_4);
	DIO_PullUp_Active(USED_PORT,PIN_NO_5);
	DIO_PullUp_Active(USED_PORT,PIN_NO_6);
	DIO_PullUp_Active(USED_PORT,PIN_NO_7);
}
u8 Keypad_u8Read(){
	// KeyPad Matrix ( Change Depending on the HW Matrix )
	u8 arr[ROWS][COLUMNS] = {{'7','8','9','A'},
							 {'4','5','6','B'},
							 {'1','2','3','C'},
							 {'*','0','#','D'}};
	u8 ROW, COLUMN, RETURN_VALUE = NOT_PRESSED;
	for (ROW = 0; ROW < ROWS; ROW++)
	{
		// All Rows is Written by 1
		DIO_Write_Low_Nibble(USED_PORT,0x0f);
		DIO_Write_Pin(USED_PORT,ROW,ZERO);
		for(COLUMN = 0; COLUMN < COLUMNS ; COLUMN++){
			if(DIO_u8ReadPin(USED_PORT,COLUMN+4) == ZERO){
				RETURN_VALUE = arr[ROW][COLUMN];
				break;
			}
		}
		if (RETURN_VALUE != NOT_PRESSED)
		{
			break;
		}
	}
	
	return RETURN_VALUE;
}
