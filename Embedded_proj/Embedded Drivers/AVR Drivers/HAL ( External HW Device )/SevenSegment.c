#include "SevenSegment.h"

void SevenSeg_vinit(u8 PORT_NO){
	DIO_Set_Port_Direction(PORT_NO,FULL_PORT_OUTPUT);
}
void SevenSeg_write(u8 PORT_NO, u8 NUMBER){
	#if defined COMMON_CATHODE
	u8 ARRAY_OF_NUMBERS[] = {ZERO_SEG_K,ONE_SEG_K,TWO_SEG_K,THREE_SEG_K,FOUR_SEG_K,FIVE_SEG_K,SIX_SEG_K,SEVEN_SEG_K,EIGHT_SEG_K,NINE_SEG_K};
	#elif defined COMMON_ANODE
	u8 ARRAY_OF_NUMBERS[] = {ZERO_SEG_A,ONE_SEG_A,TWO_SEG_A,THREE_SEG_A,FOUR_SEG_A,FIVE_SEG_A,SIX_SEG_A,SEVEN_SEG_A,EIGHT_SEG_A,NINE_SEG_A};
	#endif // _Checking If The Seven Segment Is CC or CA
	
	DIO_WritePort(PORT_NO, ARRAY_OF_NUMBERS[NUMBER]);
}
//----------------------------------------------------------------------------
// Using BCD Decoder
void SevenSegBCD_vinit(u8 PORT_NO, u8 NIBBLE){
	switch(NIBBLE)
	{
		case LOW:
			DIO_Set_Low_Nibble_Direction(PORT_NO,OUTPUT);
			break;
		case HIGH:
			DIO_Set_High_Nibble_Direction(PORT_NO,OUTPUT);
			break;
	}
	
}
void SevenSegBCD_write(u8 PORT_NO,u8 OUTPUT_VALUE,u8 NIBBLE){
	switch(NIBBLE)
	{
		case LOW:
			DIO_Write_Low_Nibble(PORT_NO,OUTPUT_VALUE);
			break;
		case HIGH:
			DIO_Write_High_Nibble(PORT_NO,OUTPUT_VALUE);
			break;
	}
}

//-------------------------------------------------------------------
// ****** HAL Driver ******
// -- Fifth Driver Done -- \\