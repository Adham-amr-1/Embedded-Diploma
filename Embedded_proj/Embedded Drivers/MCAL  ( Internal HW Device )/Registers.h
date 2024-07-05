/*
 * Registers.h
 *
 * Created: 11/3/2023 1:03:58 PM
 *  Author: Adham Amr
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_

//DIO

#define PORTA *((volatile unsigned char *)0x3B)
#define PINA *((volatile unsigned char *)0x39)
#define DDRA *((volatile unsigned char *)0x3A)
#define PORTB *((volatile unsigned char *)0x38)
#define PINB *((volatile unsigned char *)0x36)
#define DDRB *((volatile unsigned char *)0x37)
#define PORTC *((volatile unsigned char *)0x35)
#define PINC *((volatile unsigned char *)0x33)
#define DDRC *((volatile unsigned char *)0x34)
#define PORTD *((volatile unsigned char *)0x32)
#define PIND *((volatile unsigned char *)0x30)
#define DDRD *((volatile unsigned char *)0x31)

//**********************************************


//INTERRUPTS

//MCUCR  MCU Control Register
#define MCUCR *((volatile unsigned char*)0x55)
//MCUCSR MCU Control and Status Register
#define MCUCSR *((volatile unsigned char*)0x54)
//General Interrupt Control Register � GICR
#define GICR *((volatile unsigned char*)0x5B)
//General Interrupt Flag Register � GIFR
#define GIFR *((volatile unsigned char*)0x5A)
// Global Interrupt Register SREG
//we deal with I-Bit to enable or disable global interrupt enable
#define SREG *((volatile unsigned char*)0x5F)

//*******************************