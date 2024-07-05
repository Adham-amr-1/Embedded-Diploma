#include "LCD.h"
#include "KeyPad.h"
#include "EEPROM.h"
#define F_CPU 8000000UL
#include <util/delay.h>
// Set The Address where the password will saved in it
#define EEPROM_STATUS 0x20
#define EEPROM_PASS1 0X21
#define EEPROM_PASS2 0X22
#define EEPROM_PASS3 0X23
#define EEPROM_PASS4 0X24
#define EEPROM_PASS5 0X25
#define MAX_TRIES 3

// Entered Password
unsigned char arr[5]= {NOTPRESSED,NOTPRESSED,NOTPRESSED,NOTPRESSED,NOTPRESSED};
// Reset Code
unsigned char reset_code[5] = {'0' ,'0' ,'0' ,'0' ,'0'};
// indicate if the pass is correct 
unsigned char flag;
int main(void)
{
	LCD_vInit();
	Keypad_Init();
	unsigned char value = NOTPRESSED ,i;
	// Max tries to open the safe
	unsigned char tries = MAX_TRIES;
	
	
	
    while (1) 
    {
		// Set the password at first time of running the project
		if (EEPROM_Read(EEPROM_STATUS) == NOTPRESSED)
		{
			LCD_vSendString("Set Password : ");
			LCD_MoveCursor(2,6);
			for(i = 0; i < 5; i++){
				do {
					value = Keypad_u8Read();
					_delay_ms(100);
				}while (value == NOTPRESSED);
				LCD_vSendChar(value);
				_delay_ms(100);
				LCD_MoveCursor(2,6+i);
				LCD_vSendChar('*');	
				EEPROM_Write(EEPROM_PASS1+i,value);
			}
			EEPROM_Write(EEPROM_STATUS,0x00);
			LCD_ClearScreen();
			flag = 0;
		}
		while (flag == 0)
		{
			LCD_vSendString("Enter Password :");
			LCD_MoveCursor(2,6);
			for(i = 0; i < 5; i++){
				do {
					arr[i] = Keypad_u8Read();
					_delay_ms(100);
				}while (arr[i] == NOTPRESSED);
				LCD_vSendChar(arr[i]);
				_delay_ms(100);
				LCD_MoveCursor(2,6+i);
				LCD_vSendChar('*');
			}
			if (EEPROM_Read(EEPROM_PASS1) == arr[0] && EEPROM_Read(EEPROM_PASS2) == arr[1] && EEPROM_Read(EEPROM_PASS3) == arr[2] && EEPROM_Read(EEPROM_PASS4) == arr[3] && EEPROM_Read(EEPROM_PASS5) == arr[4])
			{
				LCD_ClearScreen();
				LCD_vSendString("Correct password");
				LCD_MoveCursor(2,1);
				LCD_vSendString("Safe Is Open");
				flag = 1;
			}
			else if (arr[0] == reset_code[0] && arr[1] == reset_code[1] && arr[2] == reset_code[2] && arr[3] == reset_code[3] && arr[4] == reset_code[4])
			{
				EEPROM_Write(EEPROM_STATUS,NOTPRESSED);
				LCD_ClearScreen();
				LCD_vSendString("Reset Password");
				_delay_ms(1000);
				LCD_ClearScreen();
				tries = MAX_TRIES;
				LCD_vSendString("Tries is rest");
				LCD_MoveCursor(2,1);
				LCD_vSendString("Tries = ");
				LCD_IntegerToString(tries);
				_delay_ms(1000);
				LCD_ClearScreen();
				flag = 1;
			}
			else{
				if (tries > 0)
				{
					LCD_ClearScreen();
					LCD_vSendString("Wrong Password");
					LCD_MoveCursor(2,1);
					LCD_vSendString("Tries Left : ");
					LCD_IntegerToString(--tries);
					_delay_ms(1000);
					LCD_ClearScreen();
				}
				else{
					LCD_ClearScreen();
					LCD_vSendString("Wrong Password");
					LCD_MoveCursor(2,1);
					LCD_vSendString("No Tries Left");
					_delay_ms(1000);
					LCD_ClearScreen();
					LCD_vSendString("Safe Is Closed");
					flag = 1;
				}
			}
		}
    }
}

