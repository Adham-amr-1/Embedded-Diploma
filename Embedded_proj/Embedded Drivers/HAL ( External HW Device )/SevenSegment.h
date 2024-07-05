/*
* SevenSegment.h
*
* Created: 4 / 8 / 2024 2:36:16 AM
*  Author: Adham Amr
*/

#ifndef SEVEN_SEGMENT_H_
#define	SEVEN_SEGMENT_H_
/*
Function Name        : SevenSeg_init
Function Returns     : void
Function Arguments   : unsigned char port
Function Description : define the given Port as Output Port
*/
void SevenSeg_init(unsigned char port);

/*
Function Name        : SevenSeg_write
Function Returns     : void
Function Arguments   : unsigned char port, unsigned char number
Function Description : Print out the given number on the Seven Segment Port
*/
void SevenSeg_write(unsigned char port, unsigned char number);

//---------------------------------------------------------------------------
//Using BCD Decoder

/*
Function Name        : SevenSegBCD_init
Function Returns     : void
Function Arguments   : unsigned char port,unsigned char Lownibble
Function Description : define the 4 pins output to BCD ,( Lownibble = 1 { Connected on pins from 0 to 3 }  , Lownibble = 0 { Connected on pins from 4 to 7 } )
*/
void SevenSegBCD_init(unsigned char port, unsigned char Lnibble);

/*
Function Name        : SevenSegBCD_write
Function Returns     : void
Function Arguments   : unsigned char port,unsigned char value, unsigned char Lownibble
Function Description : Write the given value on the 4 pins output to BCD,( Lownibble = 1 { Write on pins from 0 to 3 }  , Lownibble = 0 { Write on pins from 4 to 7 } )
*/
void SevenSegBCD_write(unsigned char port,unsigned char value,unsigned char Lownibble);

#endif /* SEVEN_SEGMENT_H_ */