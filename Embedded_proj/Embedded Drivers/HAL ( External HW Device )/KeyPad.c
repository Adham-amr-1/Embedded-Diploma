#include "KeyPad.h"

void Keypad_Init(){
	// Keypad Rows
	DIO_SetLowNibbleDir(USED_PORT,1);
	// Keypad Columns
	DIO_SetHighNibbleDir(USED_PORT,0);
	// Set Pull up
	DIO_PullUpActive(USED_PORT,4);
	DIO_PullUpActive(USED_PORT,5);
	DIO_PullUpActive(USED_PORT,6);
	DIO_PullUpActive(USED_PORT,7);
}
unsigned char Keypad_u8Read(){
	// HW KeyPad Matrix
	unsigned char arr[4][4] = {{'7','8','9','A'},
							   {'4','5','6','B'},
							   {'1','2','3','C'},
							   {'*','0','#','D'}};
	unsigned char row, col, return_val = NOTPRESSED;
	for (row = 0; row < 4; row++)
	{
		// All Rows is Written by 1
		DIO_WriteLowNibble(USED_PORT,0x0f);
		DIO_WritePin(USED_PORT,row,0);
		for(col = 0; col < 4 ; col++){
			if(DIO_u8ReadPin(USED_PORT,col+4)==0){
				return_val = arr[row][col];
				break;
			}
		}
		if (return_val != NOTPRESSED)
		{
			break;
		}
	}
	
	return return_val;
}