/*
 * LCD.h
 *
 * Created: 6 / 28 / 2024 10:36:16 AM
 *  Author: Adham Amr
 */ 


#ifndef LCD_H_
#define	LCD_H_
#include "LCD_CONFIG.h"
#include "DIO.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#define CLR_SCREEN 0x01
#define RETURN_HOME 0x02
#define ENTRY_MODE 0x06
#define DISPLAYON_CURSORON 0x0E
#define DISPLAYON_CURSOROFF 0x0C
#define DISPLAYON_CURSORBLINK 0x0F
#define CURSOR_TO_LEFT 0x14
#define CURSOR_TO_RIGHT 0x10
#define WRITING_TO_LEFT 0X04
#define SHIFT_DISPLAY_TO_RIGHT 0x1C 
#define SHIFT_DISPLAY_TO_LEFT 0x18

#ifndef status
#define status
#define High_NIBBLE 
#endif

#define CONTROL_PORT 'B'
#define DATA_PORT 'A'
#define EN 0
#define RS 1
#define RW 2

#if defined Four_Bit_Mode#define FOUR_BITS_1 0x02#define FOUR_BITS_2 0x28#elif defined Eight_Bit_Mode#define EIGHT_BITS 0x38#endif


/*
Function Name        : enable
Function Returns     : static void
Function Arguments   : unsigned char port,unsigned char pin
Function Description : Sending Pulse with 2 m sec Width to Tell The LCD to take the data from data pins as input
*/
void enable();

/*
Function Name        : DataRegisterSEL
Function Returns     : static void
Function Arguments   : No Arguments
Function Description : Select The place where The data that came from MC as Data to be stored in Data Register to display it
*/
void DataRegisterSEL();

/*
Function Name        : CmdRegisterSEL
Function Returns     : static void
Function Arguments   : No Arguments
Function Description : Select The place where The data that came from MC as Command to be stored in Instruction Register to do it 
*/
void CmdRegisterSEL();

/*
Function Name        : LCD_DataDir
Function Returns     : void
Function Arguments   : unsigned char Dir
Function Description : Set The data Direction ( Reading from LCD or Writing on LCD ) 
*/
void LCD_DataDir(unsigned char Dir);

/*
Function Name        : LCD_SendCmd
Function Returns     : void
Function Arguments   : unsigned char cmd
Function Description : Send Command To LCD To do it 
*/
void LCD_SendCmd(unsigned char cmd);

/*
Function Name        : LCD_ClearScreen
Function Returns     : void
Function Arguments   : No Arguments
Function Description : Clear LCD Screen
*/
void LCD_ClearScreen();

/*
Function Name        : LCD_ReturnHome
Function Returns     : void
Function Arguments   : No Argument
Function Description : Return the cursor at the beginning of LCD
*/
void LCD_ReturnHome();

/*
Function Name        : EntryMode
Function Returns     : static void
Function Arguments   : No Argument
Function Description : Used In Initialization
*/
void EntryMode();

/*
Function Name        : LCD_DiplayON_CursorOn
Function Returns     : void
Function Arguments   : No Argument
Function Description : Set The Display ON and Cursor ON
*/
void LCD_DiplayON_CursorON();
/*

Some CMDS Will Be Defined Here


*/

/*
Function Name        : LCD_MoveCursor
Function Returns     : void
Function Arguments   : unsigned char row, unsigned char col
Function Description : Used In Initialization
*/
void LCD_MoveCursor(unsigned char row, unsigned char col);

/*
Function Name        : LCD_vSendChar
Function Returns     : void
Function Arguments   : unsigned char data
Function Description : Send a character to LCD To display it
*/
void LCD_vSendChar(unsigned char data);

/*
Function Name        : LCD_vSendString
Function Returns     : void
Function Arguments   : unsigned char *data
Function Description : Send a String to LCD To display it
*/
void LCD_vSendString(char *data);

/*
Function Name        : LCD_vInit
Function Returns     : void
Function Arguments   : No Arguments
Function Description : Initialize the LCD To Be Ready For Use
*/
void LCD_vInit();




/*
Function Name        : LCD_DiplayON_CursorOff
Function Returns     : void
Function Arguments   : No Arguments
Function Description : Display the Character , Hide the Cursor
*/
void LCD_DiplayON_CursorOff();

/*
Function Name        : LCD_DiplayON_CursorBlink
Function Returns     : void
Function Arguments   : No Arguments
Function Description : Display the Character , Blinking the Cursor
*/
void LCD_DiplayON_CursorBlink();

/*
Function Name        : LCD_ShiftDisplayRight
Function Returns     : void
Function Arguments   : No Arguments
Function Description : Move The Whole Display to Right ( 2 Rows )
*/
void LCD_ShiftDisplayRight();

/*
Function Name        : LCD_ShiftDisplayLeft
Function Returns     : void
Function Arguments   : No Arguments
Function Description : Move The Whole Display to Left ( 2 Rows )
*/
void LCD_ShiftDisplayLeft();

/*
Function Name        : LCD_CursorToRight
Function Returns     : void
Function Arguments   : No Arguments
Function Description : Move Cursor To Right Without Typing
*/
void LCD_CursorToRight();

/*
Function Name        : LCD_CursorToLeft
Function Returns     : void
Function Arguments   : No Arguments
Function Description : Move Cursor To Left Without Typing
*/
void LCD_CursorToLeft();

/*
Function Name        : LCD_WritingToLeft
Function Returns     : void
Function Arguments   : No Arguments
Function Description : Set Cursor To Move Left When typing A char
*/
void LCD_WritingToLeft();

/*
Function Name        : LCD_IntegerToString
Function Returns     : void
Function Arguments   : int data
Function Description : Take Integer Number And Turn it Into String and Display it
*/
void LCD_IntegerToString(int data);


#endif /* LCD_H_ */
