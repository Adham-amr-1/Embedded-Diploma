#include <avr/interrupt.h>
#include "std_macros.h"
#include "External_Interrupt.h"

/* Enable Global Interrupt */

void Set_Interrupt(){
	SET_BIT(SREG,7); // Enable Interrupt 
}

/* Disable Global Interrupt */

void Clear_Interrupt(){
	CLEAR_BIT(SREG,7); // Disable Interrupt
}

/* Initialize External INT0 */

void INT0_INIT(unsigned char mode){ 
	CLEAR_BIT(DDRD,2); // Set Pin As Input to sense the interrupt
	MCUCR |= mode; // Set the pin to sense the interrupt as there's 4 ways to sense
	SET_BIT(GICR,6); // Enable the INT0 To Interrupt the MC  ( 6 Is the location of it in GICR ) ( Open The Data Sheet )
}

/* Initialize External INT1 */

void INT1_INIT(unsigned char mode){ 
	CLEAR_BIT(DDRD,3); // Set Pin As Input to sense the interrupt
	MCUCR |= (mode<<2); // Set the pin to sense the interrupt as there's 4 ways to sense
	SET_BIT(GICR,7); // Enable the INT1 To Interrupt the MC ( 7 Is the location of it in GICR ) ( Open The Data Sheet )
}

/* Initialize External INT2 */

void INT2_INIT(unsigned char mode){
	CLEAR_BIT(DDRB,2); // Set Pin As Input to sense the interrupt
	if(mode == Rise){
		SET_BIT(MCUCSR,6); // Set The Sense of interrupt as Rising edge
	}
	if(mode == Fall){
		CLEAR_BIT(MCUCSR,6); // Set The Sense of interrupt as Falling edge
	}
	SET_BIT(GICR,5); // Enable the INT2 To Interrupt the MC ( 5 Is the location of it in GICR ) ( Open The Data Sheet )
}

/* Extra Function */
/* Check Interrupt Request of INT0 */ /* I Can Read It from Watching Window In Proteus */ 

unsigned char CheckIRQ0(){
	return READ_BIT(GIFR,6);
}

/* Check Interrupt Request of INT1 */

unsigned char CheckIRQ1(){
	return READ_BIT(GIFR,7);
}

/* Check Interrupt Request of INT2 */

unsigned char CheckIRQ2(){
	return READ_BIT(GIFR,5);
}

/* Needed Functions For Applying the Nested Interrupt */

/* Set the INT0 Enable bit */

void SET_ENINT0(){
	SET_BIT(GICR,6);
}

/* Set the INT1 Enable bit */

void SET_ENINT1(){
	SET_BIT(GICR,7);
}

/* Set the INT2 Enable bit */

void SET_ENINT2(){
	SET_BIT(GICR,5);
}

/* Clear the INT0 Enable bit */

void Clear_ENINT0(){
	CLEAR_BIT(GICR,6);
}

/* Clear the INT1 Enable bit */

void Clear_ENINT1(){
	CLEAR_BIT(GICR,7);
}

/* Clear the INT2 Enable bit */

void Clear_ENINT2(){
	CLEAR_BIT(GICR,5);
}