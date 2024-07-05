#include "LCD.h"
// Sending Pulse with 2 m sec Width To make the LCD take the data and store it or take the command and do it
void enable(){
	DIO_WritePin(CONTROL_PORT,EN,1);
	_delay_ms(2);
	DIO_WritePin(CONTROL_PORT,EN,0);
	_delay_ms(2);
}
// Write on Data Register ( Receive from data pins as a data to print )
void DataRegisterSEL(){
	DIO_WritePin(CONTROL_PORT,RS,1);
}
// // Write on Instruction Register ( Receive from data pins as a CMD to do )
void CmdRegisterSEL(){
	DIO_WritePin(CONTROL_PORT,RS,0);
}
// Set the Direction of data ( Read == 1 ) ( Write == 0 ) ( Pin 5 in LCD ) ( In case of connecting R/W With MC )
void LCD_DataDir(unsigned char Dir){
	DIO_WritePin(CONTROL_PORT,RW,Dir);
}
// Send Command to LCD to do
void LCD_SendCmd(unsigned char cmd){
	CmdRegisterSEL();
	#if defined Eight_Bit_Mode
	DIO_WritePort(DATA_PORT,cmd);
	enable();
	#elif defined Four_Bit_Mode
	#if defined High_NIBBLE
	DIO_WriteHighNibble(DATA_PORT,cmd>>4);
	enable();
	DIO_WriteHighNibble(DATA_PORT,cmd);
	enable();
	#elif defined Low_NIBBLE
	DIO_WriteLowNibble(DATA_PORT,cmd>>4);
	enable();
	DIO_WriteLowNibble(DATA_PORT,cmd);
	enable();
	#endif // for Nibble
	#endif // For Mode
}
// Clear LCD Screen
void LCD_ClearScreen(){
	LCD_SendCmd(CLR_SCREEN);
	_delay_ms(10);
}
//Return The Cursor at the beginning of LCD
void LCD_ReturnHome(){
	LCD_SendCmd(RETURN_HOME);
	_delay_ms(10);
}
// Make the cursor Move Right After writing a Char in the place where the Cursor stand
void EntryMode(){
	LCD_SendCmd(ENTRY_MODE);
	_delay_ms(1);
}
void LCD_DiplayON_CursorON(){
	LCD_SendCmd(DISPLAYON_CURSORON);
	_delay_ms(1);
}


void LCD_DiplayON_CursorOff(){
	LCD_SendCmd(DISPLAYON_CURSOROFF);
	_delay_ms(1);
}
void LCD_DiplayON_CursorBlink(){
	LCD_SendCmd(DISPLAYON_CURSORBLINK);
	_delay_ms(1);
}
void LCD_CursorToLeft(){
	LCD_SendCmd(CURSOR_TO_LEFT);
}
void LCD_CursorToRight(){
	LCD_SendCmd(CURSOR_TO_RIGHT);
}
void LCD_WritingToLeft(){
	LCD_SendCmd(WRITING_TO_LEFT);
	_delay_ms(1);
}
void LCD_ShiftDisplayRight(){
	LCD_SendCmd(SHIFT_DISPLAY_TO_RIGHT);
}
void LCD_ShiftDisplayLeft(){
	LCD_SendCmd(SHIFT_DISPLAY_TO_LEFT);
}

void LCD_MoveCursor(unsigned char row, unsigned char col){
	unsigned char cmd = 0x80;
	if (row > 2 || row < 1 || col > 16 || col < 1)
	{
		LCD_SendCmd(cmd);
	}
	else if (row == 1)
	{
		cmd = 0x80 + (col - 1);
		LCD_SendCmd(cmd);
	}
	else if (row == 2)
	{
		cmd = 0xC0 + (col - 1);
		LCD_SendCmd(cmd);
	}
	
}
// Send character to LCD To display it
void LCD_vSendChar(unsigned char data){
	DataRegisterSEL();
	#if defined Eight_Bit_Mode
	DIO_WritePort(DATA_PORT,data);
	enable();
	#elif defined Four_Bit_Mode
	#if defined High_NIBBLE
	DIO_WriteHighNibble(DATA_PORT,data>>4);
	enable();
	DIO_WriteHighNibble(DATA_PORT,data);
	enable();
	#elif defined Low_NIBBLE
	DIO_WriteLowNibble(DATA_PORT,data>>4);
	enable();
	DIO_WriteLowNibble(DATA_PORT,data);
	enable();
	#endif // for Nibble
	#endif // for Mode
}
// Send String To Print It
void LCD_vSendString(char *data){
	while ((*data) != 0)
	{
		LCD_vSendChar(*data);
		data++;
	}
}
//Initializing LCD
void LCD_vInit(){
	_delay_ms(200);
	#if defined Eight_Bit_Mode
	DIO_SetPortDir(DATA_PORT,1);
	DIO_SetPinDir(CONTROL_PORT,RS,1);
	DIO_SetPinDir(CONTROL_PORT,RW,1);
	DIO_SetPinDir(CONTROL_PORT,EN,1);
	LCD_DataDir(0);
	LCD_SendCmd(EIGHT_BITS);
	_delay_ms(1);
	LCD_ReturnHome();
	LCD_DiplayON_CursorON();
	LCD_ClearScreen();
	EntryMode();
	#elif defined Four_Bit_Mode
	#if defined High_NIBBLE
	DIO_SetHighNibbleDir(DATA_PORT,1);
	#elif defined Low_NIBBLE
	DIO_SetLowNibbleDir(DATA_PORT,1);
	#endif // For Nibble
	DIO_SetPinDir(CONTROL_PORT,RS,1);
	DIO_SetPinDir(CONTROL_PORT,RW,1);
	DIO_SetPinDir(CONTROL_PORT,EN,1);
	LCD_DataDir(0);
	LCD_SendCmd(FOUR_BITS_1);
	_delay_ms(1);
	LCD_SendCmd(FOUR_BITS_2);
	_delay_ms(1);
	LCD_ReturnHome();
	LCD_DiplayON_CursorON();
	LCD_ClearScreen();
	EntryMode();
	#endif // For Mode
}
void LCD_IntegerToString(int data)
{
	char buff[16]; /* String to hold the ascii result */
	itoa(data,buff,10); /* Use itoa C function to convert the data to its corresponding ASCII value, 10 for decimal */
	LCD_vSendString(buff); /* Display the string */
}