/*
 * ADC.h
 *
 * Created: 7 / 6 / 2024 6:36:16 PM
 *  Author: Adham Amr
 */ 

#include "Registers.h"
#include "STD_Macros.h"
#include "STD_Types.h"
/* ------------------------------------------------ */
// Set if the ACCURACY is important or not
#define ACCURACY LOW
/* ------------------------------------------------ */
// to select the Vref of the ADC
// Connect VCC of MC to ARef pin directly
#define  VREF_FROM_AREF_PIN HIGH
// Internal Vref will be accessed
#define VREF_IS_INTERNAL LOW
// connect Cap to ARef pin and GND
#define VCC_AND_CAP LOW
/* ------------------------------------------------ */
// To select the CLK
// Divide the MC CLK By Division factor to set the ADC CLK
#define DIVISON_BY_2   LOW
#define DIVISON_BY_4   LOW
#define DIVISON_BY_8   LOW
#define DIVISON_BY_16  LOW
#define DIVISON_BY_32  LOW
// By Default i will work with one of this two Divisions
#define DIVISON_BY_64  HIGH
#define DIVISON_BY_128 LOW

#ifndef ADC_H_
#define ADC_H_

/* ------------------------------------------------ */
/*
	Function Name        : ADC_vInit
	Function Returns     : void
	Function Arguments   :  void
	Function Description : Initialize the ADC ( CLK , Vref , Enable ADC )
*/
void ADC_vInit();

/*
	Function Name        : ADC_u16Read
	Function Returns     : unsigned char
	Function Arguments   : void 
	Function Description : Read Data From ADC and returns The Data to variable with size 2 byte.
*/
u16 ADC_u16Read();

/*
	Function Name        : ADC_CLK
	Function Returns     : void 
	Function Arguments   : void 
	Function Description : Set The ADC clock signal
*/
void ADC_CLK();

/*
	Function Name        : ADC_Interrupt
	Function Returns     : void
	Function Arguments   : void 
	Function Description : Enable ADC Interrupt
*/
void ADC_Interrupt();

/*
	Function Name        : ADC_PinRead
	Function Returns     : void 
	Function Arguments   : unsigned char pin 
	Function Description : Select the pin where the sensor ( the analog input signal ) exist
*/
void ADC_PinRead(u8 PIN_NO);

/*
	Function Name        : ADC_Vref
	Function Returns     : void 
	Function Arguments   : void 
	Function Description : Set The ADC Vref ( Maximum voltage ) 
*/
void ADC_Vref();

#endif /* ADC_H_ */