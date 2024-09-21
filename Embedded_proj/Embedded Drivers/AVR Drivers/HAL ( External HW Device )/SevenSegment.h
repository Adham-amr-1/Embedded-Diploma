/*
* SevenSegment.h
*
* Created: 4 / 8 / 2024 2:36:16 AM
*  Author: Adham Amr
*/
#include "DIO.h"
#include "STD_Macros.h"
#include "STD_Types.h"
#include "Registers.h"
#define COMMON_CATHODE // Ba3dl Feh in case lw hasta3ml 7 Segment Common Anode bs


#ifndef SEVEN_SEGMENT_H_
#define	SEVEN_SEGMENT_H_


/*
Function Name        : SevenSeg_vinit
Function Returns     : void
Function Arguments   : u8 PORT_NO
Function Description : define the given Port as Output Port
*/
void SevenSeg_vinit(u8 PORT_NO);

/*
Function Name        : SevenSeg_write
Function Returns     : void
Function Arguments   : u8 PORT_NO, u8 NUMBERr
Function Description : Print out the given number on the Seven Segment Port
*/
void SevenSeg_write(u8 PORT_NO, u8 NUMBER);

//---------------------------------------------------------------------------
//Using BCD Decoder

/*
Function Name        : SevenSegBCD_vinit
Function Returns     : void
Function Arguments   : u8 PORT_NO, u8 NIBBLE
Function Description : define the 4 pins output to BCD ,( Lownibble = 1 { Connected on pins from 0 to 3 }  , Lownibble = 0 { Connected on pins from 4 to 7 } )
*/
void SevenSegBCD_vinit(u8 PORT_NO, u8 NIBBLE);

/*
Function Name        : SevenSegBCD_write
Function Returns     : void
Function Arguments   : u8 PORT_NO,u8 OUTPUT_VALUE,u8 NIBBLE
Function Description : Write the given value on the 4 pins output to BCD,( Lownibble = 1 { Write on pins from 0 to 3 }  , Lownibble = 0 { Write on pins from 4 to 7 } )
*/
void SevenSegBCD_write(u8 PORT_NO,u8 OUTPUT_VALUE,u8 NIBBLE);

#endif /* SEVEN_SEGMENT_H_ */