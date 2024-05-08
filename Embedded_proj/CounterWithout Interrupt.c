/*
 * GccApplication3.c
 *
 * Created: 3/20/2024 9:28:11 PM
 * Author : Adham
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>
#include "DIO.h"
#include "BUTTON.h"
#include "SevenSegment.h"
#include "BUZZER.h"
int main(void)
{
	// Initializing Seven Segments
	SevenSegBCD_init('D',1);
	SevenSegBCD_init('D',0);
	// Initial Case
	SevenSegBCD_write('D',0,0);
	SevenSegBCD_write('D',0,1);
	// Initializing Buttons 
	Button_Intial('A',0);
	Button_Intial('A',1);
	Button_Intial('A',2);
	// Initializing Buzzer / LED 
	Buzzer_Intial('A',3);
	// Pull Up Activation
	DIO_PullUpActive('A',0);
	DIO_PullUpActive('A',1);
	DIO_PullUpActive('A',2);
	// Buttons
	unsigned char RSButton ;    // Reset Button 
	unsigned char STRButton;   //  Resume & Start Button
	unsigned char SPButton ;  //  Stop Button
	// Start Counter Check
	unsigned char count = 0;
	unsigned char BuzON = 0;
	// Counting on Seven Segment
	unsigned char Rcount = 0;
	unsigned char Lcount = 0;
    while (1) 
    {
		STRButton = Button_u8read('A',0);
		RSButton = Button_u8read('A',2);
		if(STRButton == 0){
			count = 1;
		}
		while(count){
			SPButton = Button_u8read('A', 1);
            if (SPButton == 0)
            {
                count = 0; // Exiting the inner loop
                break;     // Exiting the outer loop
            }
			Rcount++;
			SevenSegBCD_write('D',Rcount,0);
			_delay_ms(1000);
			if (Rcount == 9)
			{
				Rcount = 0;
				Lcount++;
				if (Lcount == 6)
				{
					BuzON = 1;
					Lcount = 0;
					Rcount = 0;
				}
				SevenSegBCD_write('D',Rcount,0);
				SevenSegBCD_write('D',Lcount,1);
				if (BuzON)
				{
					Buzzer_ON('A',3);
					_delay_ms(500);
					Buzzer_OFF('A',3);
					_delay_ms(500);
				}
				else{
					_delay_ms(1000);
				}
			}
		}
		if (RSButton == 0)
		{
			Lcount = 0;
			Rcount = 0;
			SevenSegBCD_write('D',Rcount,0);
			SevenSegBCD_write('D',Lcount,1);
		}
	}	
}


