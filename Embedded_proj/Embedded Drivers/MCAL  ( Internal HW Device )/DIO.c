#include <avr/io.h>
#include "std_macros.h"
//-------------------------------------------------------------------
/*
Controlling on One Pin
*/
/* Set Direction of pins { input ( 0 ) or Output ( 1 ) }  */
void DIO_SetPinDir(unsigned char port,unsigned char pin,unsigned char dir){
	switch (port){
		case 'A':
		case 'a':
			if (dir == 1)
			{
				SET_BIT(DDRA,pin); // Set Pin Output
			}
			else{
				CLEAR_BIT(DDRA,pin); // Set Pin Input
			}
			break;
		case 'B':
		case 'b':
			if (dir == 1)
			{
				SET_BIT(DDRB,pin); // Set Pin Output
			}
			else{
				CLEAR_BIT(DDRB,pin); // Set Pin Input
			}
			break;
		case 'C':
		case 'c':
			if (dir == 1)
			{
				SET_BIT(DDRC,pin); // Set Pin Output
			}
			else{
				CLEAR_BIT(DDRC,pin); // Set Pin Input
			}
			break;
		case 'D':
		case 'd':
			if (dir == 1)
			{
				SET_BIT(DDRD,pin); // Set Pin Output
			}
			else{
				CLEAR_BIT(DDRD,pin); // Set Pin Input
			}
			break;
		default:
			break;
	}
}
// If The Pin Is Output set it out { High ( 1 ) or Low ( 0 ) }
void DIO_WritePin(unsigned char port,unsigned char pin,unsigned char outputvalue){
	switch (port){
		case 'A':
		case 'a':
			if (outputvalue == 1)
			{
				SET_BIT(PORTA,pin); // Set Pin High
			}
			else{
				CLEAR_BIT(PORTA,pin); // Set Pin Low
			}
			break;
		case 'B':
		case 'b':
			if (outputvalue == 1)
			{
				SET_BIT(PORTB,pin); // Set Pin High
			}
			else{
				CLEAR_BIT(PORTB,pin); // Set Pin Low
			}
			break;
		case 'C':
		case 'c':
			if (outputvalue == 1)
				{
					SET_BIT(PORTC,pin); // Set Pin High
				}
				else{
					CLEAR_BIT(PORTC,pin); // Set Pin Low
				}
				break;
		case 'D':
		case 'd':
			if (outputvalue == 1)
			{
				SET_BIT(PORTD,pin); // Set Pin High
			}
			else{
				CLEAR_BIT(PORTD,pin); // Set Pin Low
			}
			break;
		default:
			break;
	}
}
// Change pin case from 1 to 0 and vice verse
void DIO_TogglePin(unsigned char port,unsigned char pin){
	switch (port){
		case 'A':
		case 'a':
			TOGGLE_BIT(PORTA,pin);
			break;
		case 'B':
		case 'b':
			TOGGLE_BIT(PORTB,pin);
			break;
		case 'C':
		case 'c':
			TOGGLE_BIT(PORTC,pin);
			break;
		case 'D':
		case 'd':
			TOGGLE_BIT(PORTD,pin);
			break;
		default:
			break;
	}
}
// Check the I/P Device state
unsigned char DIO_u8ReadPin(unsigned char port, unsigned char pin){
		unsigned char returnVal = 0;
		switch (port){
			case 'A':
			case 'a':
				returnVal = READ_BIT(PINA,pin);
				break;
			case 'B':
			case 'b':
				returnVal = READ_BIT(PINB,pin);
				break;
			case 'C':
			case 'c':
				returnVal = READ_BIT(PINC,pin);
				break;
			case 'D':
			case 'd':
				returnVal = READ_BIT(PIND,pin);
				break;
			default:
				break;
		}
		return returnVal;
}
//-------------------------------------------------------------------
/*
Controlling on Full Port
*/
// Set All Port 
void DIO_SetPortDir(unsigned char port, unsigned char dir){
	 switch(port){
		 case 'A':
		 case 'a':
			DDRA = dir;
			break;
		 case 'B':
		 case 'b':
			 DDRB = dir;
			 break;
		 case 'C':
		 case 'c':
			 DDRC = dir;
			 break;
		 case 'D':
		 case 'd':
			 DDRD = dir;
			 break;
		default:
			break;
	 }
 }
 // Write on All Port
void DIO_WritePort(unsigned char port, unsigned char outputvalue){
	switch(port){
		case 'A':
		case 'a':
			PORTA = outputvalue;
			break;
		case 'B':
		case 'b':
			PORTB = outputvalue;
			break;
		case 'C':
		case 'c':
			PORTC = outputvalue;
			break;
		case 'D':
		case 'd':
			PORTD = outputvalue;
			break;
		default:
			break;
	}
}
 // Read Status of The Port
unsigned char DIO_ReadPort(unsigned char port){
	 unsigned char returnVal = 0;
	  switch(port){
		  case 'A':
		  case 'a':
			  returnVal = PINA;
			  break;
		  case 'B':
		  case 'b':
			  returnVal = PINB;
			  break;
		  case 'C':
		  case 'c':
			  returnVal = PINC;
			  break;
		  case 'D':
		  case 'd':
			  returnVal = PIND;
			  break;
		  default:
			  break;
	  }
	  return returnVal;
  }
// Toggle Ports 1 to 0 and vice versa
void DIO_TogglePort(unsigned char port){
	switch(port){
		case 'A':
		case 'a':
			PORTA =~PORTA;
			break;
		case 'B':
		case 'b':
			PORTB =~PORTB;
			break;
		case 'C':
		case 'c':
			PORTC =~PORTC;
			break;
		case 'D':
		case 'd':
			PORTD =~PORTD;
			break;
		default:
			break;
	}
}
// Active The Pull Up Resistance
void DIO_PullUpActive(unsigned char port, unsigned char pin){
	switch (port){
		case 'A':
		case 'a':
			SET_BIT(PORTA,pin); // Set Pin High
			break;
		case 'B':
		case 'b':
			SET_BIT(PORTB,pin); // Set Pin High
			break;
		case 'C':
		case 'c':
			SET_BIT(PORTC,pin); // Set Pin High
			break;
		case 'D':
		case 'd':
			SET_BIT(PORTD,pin); // Set Pin High
			break;
		default:
		break;
	}
}
// DeActive The Pull Up Resistance
void DIO_PullUpDeActive(unsigned char port, unsigned char pin){
	switch (port){
		case 'A':
		case 'a':
			CLEAR_BIT(PORTA,pin); // Set Pin Low
			break;
		case 'B':
		case 'b':
			CLEAR_BIT(PORTB,pin); // Set Pin Low
			break;
		case 'C':
		case 'c':
			CLEAR_BIT(PORTC,pin); // Set Pin Low
			break;
		case 'D':
		case 'd':
			CLEAR_BIT(PORTD,pin); // Set Pin Low
			break;
		default:
		break;
	}
}
// Write on Bits from 0 to 3
void DIO_WriteLowNibble(unsigned char port, unsigned char value){
	value&=0x0f;
	switch (port){
		case 'A':
		case 'a':
		PORTA&=0xf0;
		PORTA|=value;
		break;
		case 'B':
		case 'b':
		PORTB&=0xf0;
		PORTB|=value;
		break;
		case 'C':
		case 'c':
		PORTC&=0xf0;
		PORTC|=value;
		break;
		case 'D':
		case 'd':
		PORTD&=0xf0;
		PORTD|=value;
		break;
		default:
		break;
	}
}
// Write on Bits from 4 to 7
void DIO_WriteHighNibble(unsigned char port, unsigned char value){
	value<<=4;
	switch (port){
		case 'A':
		case 'a':
			PORTA&=0x0f;
			PORTA|=value;
			break;
		case 'B':
		case 'b':
			PORTB&=0x0f;
			PORTB|=value;
			break;
		case 'C':
		case 'c':
			PORTC&=0x0f;
			PORTC|=value;
			break;
		case 'D':
		case 'd':
			PORTD&=0x0f;
			PORTD|=value;
			break;
		default:
			break;
	}
}

void DIO_SetHighNibbleDir(unsigned char port, unsigned char dir){ // dir = 1 -> output , dir = 0 -> input
	DIO_SetPinDir(port,4,dir);
	DIO_SetPinDir(port,5,dir);
	DIO_SetPinDir(port,6,dir);
	DIO_SetPinDir(port,7,dir);
}
void DIO_SetLowNibbleDir(unsigned char port, unsigned char dir){ // dir = 1 -> output , dir = 0 -> input
	DIO_SetPinDir(port,0,dir);
	DIO_SetPinDir(port,1,dir);
	DIO_SetPinDir(port,2,dir);
	DIO_SetPinDir(port,3,dir);
}
//-------------------------------------------------------------------
// ***** MCAL Driver *****
// -- First Driver Done -- \\