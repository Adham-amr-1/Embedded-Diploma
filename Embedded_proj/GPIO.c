/*
 * GccApplication3.c
 *
 * Created: 3/20/2024 9:28:11 PM
 * Author : Adham
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

// GPIO Macros
#define MY_DDRA *(volatile unsigned char*)(0x003A)
#define MY_PORTA *(volatile unsigned char*)(0x003B)

// SET / CLEAR Bits
#define SET_BIT(reg,bit) reg|=(1<<bit)
#define CLEAR_BIT(reg,bit) reg&=~(1<<bit)

int main(void)
{
    // Set Bits ( Output Pins )
	MY_DDRA = 0xff; // All Bits are 1's (1111 1111)
	
    while (1) 
    {
	// Project 1
	/*
		for(int i = 0;i <8;i++){
			SET_BIT(MY_PORTA,i);
			_delay_ms(100);
			CLEAR_BIT(MY_PORTA,i);
		}*/


	// Project 2
			/*for(int i = 0;i <8;i++){
				SET_BIT(MY_PORTA,i);
				_delay_ms(100);
				CLEAR_BIT(MY_PORTA,i);
			}
			for(int i = 7;i>=0;i--){
				SET_BIT(MY_PORTA,i);
				_delay_ms(100);
				CLEAR_BIT(MY_PORTA,i);
			}*/
	
	// Project 3
			for(int i = 0;i <8;i++){
				SET_BIT(MY_PORTA,i);
				_delay_ms(90);
			}
			for(int i = 7;i>=0;i--){
				CLEAR_BIT(MY_PORTA,i);
				_delay_ms(90);
			}
    }
}

