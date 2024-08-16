/*
 * RealTimeClock.c
 *
 *  Created on: Aug 15, 2024
 *      Author: ADHam
 */
/*======= Included Libraries =======*/
#include <avr/interrupt.h>
#include "DIO.h"
#include "Timers.h"
#include "LCD.h"
#include "Keypad.h"
#include "STD_Types.h"
/*======= Global Variables =======*/
volatile u8 Seconds = 0;
u8 Minutes = 0;
u8 Hours = 0;
u8 value;
u8 tens_digit;
u8 ones_digit;
/*======= Main Program =======*/
int main(void)
{
	// Assume ( 1 FOR AM, 2 FOR PM )
	/*======= Pins Initialization  =======*/
	Timer2_Set_OverFlow_Mode();
	LCD_vInit();
	Keypad_vinit();
	DIO_Set_Port_Direction(PORT_C,0x3F);
	SevenSeg_vinit(PORT_D);
	LCD_Move_Cursor(1,5);
	LCD_vSendString("Press 1");
	LCD_Move_Cursor(2,4);
	LCD_vSendString("To Set Clk");
	/* Replace with your application code */
	while (1)
    {
		value = Keypad_u8Read();
		_delay_ms(18);
		if(value != NOT_PRESSED){
			if(value == '1'){
				/* Set Hours */
			hours:
				LCD_Clear_Screen();
				LCD_vSendString("Set Hours = --");
				LCD_Move_Cursor(1,13);
				do{
					tens_digit = Keypad_u8Read();
				}while(tens_digit == NOT_PRESSED);
				LCD_vSendChar(tens_digit);
				_delay_ms(500);
				do{
					ones_digit = Keypad_u8Read();
				}while(ones_digit == NOT_PRESSED);
				LCD_vSendChar(ones_digit);
				_delay_ms(500);
				Hours = 10 * (tens_digit - 48)+(ones_digit - 48);
				if(Hours > 24){
					LCD_Clear_Screen();
					LCD_vSendString("It's not avaliable");
					_delay_ms(1000);
					LCD_Clear_Screen();
					LCD_vSendString("Set Again");
					_delay_ms(1000);
					goto hours;
				}
				/* Set Minutes */
			minutes:
				LCD_Clear_Screen();
				LCD_vSendString("Set Minutes = --");
				LCD_Move_Cursor(1,15);
				do{
					tens_digit = Keypad_u8Read();
				}while(tens_digit == NOT_PRESSED);
				LCD_vSendChar(tens_digit);
				_delay_ms(500);
				do{
					ones_digit = Keypad_u8Read();
				}while(ones_digit == NOT_PRESSED);
				LCD_vSendChar(ones_digit);
				_delay_ms(500);
				Minutes = 10 * (tens_digit - 48)+(ones_digit - 48);
				if(Minutes > 60){
					LCD_Clear_Screen();
					_delay_ms(1000);
					LCD_vSendString("It's not avaliable");
					LCD_Clear_Screen();
					_delay_ms(1000);
					LCD_vSendString("Set Again");
					goto minutes;
				}
				/* Set Seconds */
			seconds:
				LCD_Clear_Screen();
				LCD_vSendString("Set Seconds = --");
				LCD_Move_Cursor(1,15);
				do{
					tens_digit = Keypad_u8Read();
				}while(tens_digit == NOT_PRESSED);
				LCD_vSendChar(tens_digit);
				_delay_ms(500);
				do{
					ones_digit = Keypad_u8Read();
				}while(ones_digit == NOT_PRESSED);
				LCD_vSendChar(ones_digit);
				_delay_ms(500);
				Seconds = 10 * (tens_digit - 48) + (ones_digit - 48);
				if(Seconds > 60){
					LCD_Clear_Screen();
					LCD_vSendString("It's not avaliable");
					_delay_ms(1000);
					LCD_Clear_Screen();
					LCD_vSendString("Set Again");
					_delay_ms(1000);
					goto seconds;
				}
				// Clk is set successfully
				LCD_Clear_Screen();
				LCD_vSendString("Time Set");
				_delay_ms(500);
				LCD_Clear_Screen();
				LCD_Move_Cursor(1,5);
				LCD_vSendString("Press 1");
				LCD_Move_Cursor(2,4);
				LCD_vSendString("To Set Clk");
			}
			else{
				LCD_Clear_Screen();
				LCD_Move_Cursor(1,3);
				LCD_vSendString("Wrong Choice");
				_delay_ms(1000);
				LCD_Clear_Screen();
				LCD_Move_Cursor(1,5);
				LCD_vSendString("Press 1");
				LCD_Move_Cursor(2,4);
				LCD_vSendString("To Set Clk");
			}
		}
		DIO_WritePort(PORT_C,0X3F);
		DIO_Write_Pin(PORT_A, PIN_NO_2, ONE);
		DIO_Write_Pin(PORT_A, PIN_NO_3, ZERO);
		DIO_WritePort(PORT_D, 0X73);
		_delay_ms(2);
		// Seconds Display
		DIO_WritePort(PORT_C,0X3E);
		SevenSeg_write(PORT_D,Seconds%10);
		_delay_ms(2);
		DIO_WritePort(PORT_C,0X3D);
		SevenSeg_write(PORT_D,Seconds/10);
		_delay_ms(2);
		// Minutes Display
		DIO_WritePort(PORT_C,0X3B);
		SevenSeg_write(PORT_D,Minutes%10);
		_delay_ms(2);
		DIO_WritePort(PORT_C,0X37);
		SevenSeg_write(PORT_D,Minutes/10);
		_delay_ms(2);
		// Hours Display
		DIO_WritePort(PORT_C,0X2F);
		SevenSeg_write(PORT_D,Hours%10);
		_delay_ms(2);
		DIO_WritePort(PORT_C,0X1F);
		SevenSeg_write(PORT_D,Hours/10);
		_delay_ms(2);
		if(Seconds >= 60){
			Minutes++;
			Seconds = 0;
		}
		if(Minutes >= 60){
			Hours++;
			Minutes = 0;
		}
		if(Hours >= 24){
			Hours = 0;
		}
    }
}
ISR(TIMER2_OVF_vect){
	Seconds++;
}
