#include "LCD.h"
#include "DIO.h"
#include "BUTTON.h"
#define F_CPU 8000000UL
#include <util/delay.h>
int main(void)
{
	LCD_vInit();
	LCD_DiplayON_CursorOff();
	LCD_MoveCursor(1,3);
	LCD_vSendString("Welcome To");
	LCD_MoveCursor(2,2);
	LCD_vSendString("Voting Machine");
	_delay_ms(2000);
	LCD_ClearScreen();
	// Set Voting Pins
	DIO_SetPinDir('D',0,1); // For A
	DIO_SetPinDir('D',1,1); // For B
	DIO_SetPinDir('D',2,1); // For C
	DIO_SetPinDir('D',3,1); // For D
	DIO_SetPinDir('D',4,1); // For RESET
	// Pull Up To set Buttons HIGH
	DIO_PullUpActive('D',0);
	DIO_PullUpActive('D',1);
	DIO_PullUpActive('D',2);
	DIO_PullUpActive('D',3);
	DIO_PullUpActive('D',4);
	// For Voting ( Assuming the Max Vote is 255 for each )
	unsigned char A = 0;
	unsigned char B = 0;
	unsigned char C = 0;
	unsigned char D = 0;
	// Writing the initialize of each vote
	LCD_vSendString("A = ");
	LCD_IntegerToString(A);
	LCD_MoveCursor(1,9);
	LCD_vSendString("B = ");
	LCD_IntegerToString(B);
	LCD_MoveCursor(2,1);
	LCD_vSendString("C = ");
	LCD_IntegerToString(C);
	LCD_MoveCursor(2,9);
	LCD_vSendString("D = ");
	LCD_IntegerToString(D);

    while (1) 
    {
		if (DIO_u8ReadPin('D',0) == 0)
		{
			LCD_MoveCursor(1,5);
			LCD_IntegerToString(++A);
		}
		else if (DIO_u8ReadPin('D',1) == 0)
		{
			LCD_MoveCursor(1,13);
			LCD_IntegerToString(++B);
		}
		else if (DIO_u8ReadPin('D',2) == 0)
		{
			LCD_MoveCursor(2,5);
			LCD_IntegerToString(++C);
		}
		else if (DIO_u8ReadPin('D',3) == 0)
		{
			LCD_MoveCursor(2,13);
			LCD_IntegerToString(++D);
		}
		else if (DIO_u8ReadPin('D',4) == 0)
		{
			if (A > 9 || B > 9 || C > 9 || D > 9)
			{
				LCD_MoveCursor(1,14);
				LCD_vSendString("  ");
				LCD_MoveCursor(1,6);
				LCD_vSendString("  ");
				LCD_MoveCursor(2,6);
				LCD_vSendString("  ");
				LCD_MoveCursor(2,14);
				LCD_vSendString("  ");
			}
			A = B = C = D = 0;
			LCD_MoveCursor(1,5);
			LCD_IntegerToString(A);
			LCD_MoveCursor(1,13);
			LCD_IntegerToString(B);
			LCD_MoveCursor(2,5);
			LCD_IntegerToString(C);
			LCD_MoveCursor(2,13);
			LCD_IntegerToString(D);
			
			
		}
		_delay_ms(200);
    }
}

