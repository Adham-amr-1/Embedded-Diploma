/*
 * Motors.h
 *
 *  Created on: Aug 24, 2024
 *      Author: ADHam
 */
#include "DIO.h"
#include "Timers.h"
#include "STD_Types.h"
#define F_CPU 8000000UL
#include <avr/delay.h>
#ifndef MOTORS_H_
#define MOTORS_H_

/*
	Function Name        : Motors_vInit
	Function Returns     : void
	Function Arguments   : u8 MOTORS_PORT, u8 NIBBLE
	Function Description : Set Up Motor Pins.
*/
void Motors_vInit(u8 MOTORS_PORT, u8 NIBBLE);

/*
	Function Name        : Move_Forward
	Function Returns     : void
	Function Arguments   : u8 MOTORS_PORT, u8 NIBBLE
	Function Description : Move Motors forward.
*/
void Move_Forward(u8 MOTORS_PORT, u8 NIBBLE);

/*
	Function Name        : Move_Backward
	Function Returns     : void
	Function Arguments   : u8 MOTORS_PORT, u8 NIBBLE
	Function Description : Move Motors backward.
*/
void Move_Backward(u8 MOTORS_PORT, u8 NIBBLE);

/*
	Function Name        : Move_Left
	Function Returns     : void
	Function Arguments   : u8 MOTORS_PORT, u8 NIBBLE
	Function Description : Move Motors Left.
*/
void Move_Left(u8 MOTORS_PORT, u8 NIBBLE);

/*
	Function Name        : Move_Right
	Function Returns     : void
	Function Arguments   : u8 MOTORS_PORT, u8 NIBBLE
	Function Description : Move Motors right.
*/
void Move_Right(u8 MOTORS_PORT, u8 NIBBLE);

/*
	Function Name        : Servo_vInit
	Function Returns     : void
	Function Arguments   : void
	Function Description : Set servo pin ( OCR1A )
*/
void Servo_vInit();

/*
	Function Name        : Servo_Direction
	Function Returns     : void
	Function Arguments   : u8 DEGREE
	Function Description : Move the servo to the degree that entered.
*/
void Servo_Direction(double DEGREE);
#endif /* MOTORS_H_ */
