/*
 * External_Interrupt.h 
 *
 * Created: 6 / 18 / 2024 6:36:16 PM
 *  Author: Adham Amr
 */ 
#ifndef EXTERN_INTERRUPT_H_
#define EXTERN_INTERRUPT_H_
#define Rise 0x03
#define Fall 0x02
#define LowVolt 0x00
#define AnyChange 0x01
/*
	Function Name        : Set_Interrupt
	Function Returns     : void
	Function Arguments   : No Argument
	Function Description : Enable Interrupt
*/

void Set_Interrupt();
/*
	Function Name        : Clear_Interrupt
	Function Returns     : void
	Function Arguments   : No Arguments
	Function Description : Disable Interrupt
*/
void Clear_Interrupt();


/*
	Function Name        : INT0_INIT
	Function Returns     : void
	Function Arguments   : unsigned char mode
	Function Description : Initialize the Interrupt if INT0 and it's sensing for interrupt
*/
void INT0_INIT(unsigned char mode);

/*
	Function Name        : INT1_INIT
	Function Returns     : void
	Function Arguments   : unsigned char mode
	Function Description : Initialize the Interrupt if INT1 and it's sensing for interrupt
*/
void INT1_INIT(unsigned char mode);

/*
	Function Name        : INT2_INIT
	Function Returns     : void
	Function Arguments   : unsigned char mode
	Function Description : Initialize the Interrupt if INT2 and it's sensing for interrupt
*/
void INT2_INIT(unsigned char mode);
/* Extra Function */
/*
	Function Name        : CheckIRQ0
	Function Returns     : unsigned char
	Function Arguments   : No Argument
	Function Description : Check if there's interrupt happen or not
*/
unsigned char CheckIRQ0();

/*
	Function Name        : CheckIRQ1
	Function Returns     : unsigned char
	Function Arguments   : No Argument
	Function Description : Check if there's interrupt happen or not
*/
unsigned char CheckIRQ1();

/*
	Function Name        : CheckIRQ2
	Function Returns     : unsigned char
	Function Arguments   : No Argument
	Function Description : Check if there's interrupt happen or not
*/
unsigned char CheckIRQ2();

/* Needed Functions For Applying the Nested Interrupt */

/*
	Function Name        : SET_ENINT0
	Function Returns     : Void
	Function Arguments   : No Argument
	Function Description : Set Enable bit of INT0 
*/
void SET_ENINT0();

/*
	Function Name        : SET_ENINT1
	Function Returns     : Void
	Function Arguments   : No Argument
	Function Description : Set Enable bit of INT1
*/
void SET_ENINT1();

/*
	Function Name        : SET_ENINT2
	Function Returns     : Void
	Function Arguments   : No Argument
	Function Description : Set Enable bit of INT2
*/
void SET_ENINT2();

/*
	Function Name        : Clear_ENINT0
	Function Returns     : Void
	Function Arguments   : No Argument
	Function Description : Clear Enable bit of INT0
*/
void Clear_ENINT0();

/*
	Function Name        : Clear_ENINT1
	Function Returns     : Void
	Function Arguments   : No Argument
	Function Description : Clear Enable bit of INT1
*/
void Clear_ENINT1();

/*
	Function Name        : Clear_ENINT2
	Function Returns     : Void
	Function Arguments   : No Argument
	Function Description : Clear Enable bit of INT2
*/
void Clear_ENINT2();

/*
To Apply Nested Interrupt Back To IVT In Data Sheet
ISR Code Steps
1- Enable Interrupt
2- Disable Low Priority Interrupts ( to make the interrupt comes from the High Priority Interrupts Only )
3- Write Interrupt code 
4- Enable Low Priority Interrupts
*/
#endif /* EXTERN_INTERRUPT_H_ */