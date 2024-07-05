/*
* SevenSegment.c
*
* Created: 4 / 18 / 2024 8:36:16 AM
*  Author: Adham Amr
*/
#ifndef BCD_SEVEN_SEGMENT_H_
#define	BCD_SEVEN_SEGMENT_H_

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

#endif /* BCD_SEVEN_SEGMENT_H_ */