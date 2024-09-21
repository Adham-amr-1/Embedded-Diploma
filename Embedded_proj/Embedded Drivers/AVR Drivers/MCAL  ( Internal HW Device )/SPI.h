/*
 * SPI.h
 *
 *  Created on: Sep 1, 2024
 *      Author: ADHam
 */
#define F_CPU 8000000UL
#include "DIO.h"
#include "STD_Macros.h"
#include "STD_Types.h"
#include "Registers.h"
#include <avr/delay.h>

// SPI Data Send
#define LSB_FIRST 1
#define MSB_FIRST 0
// SPI CLK
#define DIVIDE_BY_4   0
#define DIVIDE_BY_16  1
#define DIVIDE_BY_64  0
#define DIVIDE_BY_128 0
#define DIVIDE_BY_2   0
#define DIVIDE_BY_8   0
#define DIVIDE_BY_32  0
// SPI CLK Polarity
#define IDLE_LOW  1
#define IDLE_HIGH 0
// SPI CLK Phase
#define TX_ON_RISING  1
#define TX_ON_FALLING 0

#ifndef SPI_H_
#define SPI_H_

/*
	Function Name        : SPI_Set_CLK
	Function Returns     : void
	Function Arguments   : void
	Function Description : Set the SPI Communication CLK.
*/
void SPI_Set_CLK();

/*
	Function Name        : SPI_MasterInit
	Function Returns     : void
	Function Arguments   : void
	Function Description : Set the SPI In Master Controller.
*/
void SPI_MasterInit();

/*
	Function Name        : SPI_SlaveInit
	Function Returns     : void
	Function Arguments   : void
	Function Description : Set the SPI In Slave Controller.
*/
void SPI_SlaveInit();

/*
	Function Name        : SPI_Master_Transmit_Data
	Function Returns     : u8
	Function Arguments   : u8 DATA
	Function Description : Exchange Data with the Slave MC .
*/
u8 SPI_Master_Transmit_Data(u8 DATA);

/*
	Function Name        : SPI_Slave_Recieve_Data
	Function Returns     : u8
	Function Arguments   : u8 DATA
	Function Description : Exchange Data with the Master MC.
*/
u8 SPI_Slave_Recieve_Data(u8 DATA);

/*
	Function Name        : SPI_Master_Send_String
	Function Returns     : void
	Function Arguments   : u8* DATA
	Function Description : Send String to Slave.
*/
void SPI_Master_Send_String(u8* DATA);

/*
	Function Name        : SPI_Slave_SelectInit
	Function Returns     : void
	Function Arguments   : u8 PORT, u8 PIN
	Function Description : Set The pin where the Slave SS is connected to.
*/
void SPI_Slave_SelectInit(u8 PORT, u8 PIN);

/*
	Function Name        : SPI_Exchange_With
	Function Returns     : void
	Function Arguments   : u8 PORT, u8 PIN
	Function Description : Set The pin LOW to select the desire Slave MC to exchange data with.
*/
void SPI_Exchange_With(u8 PORT, u8 PIN);

/*
	Function Name        : SPI_Master_Transmit_Data_To
	Function Returns     : void
	Function Arguments   : u8 PORT, u8 PIN, u8 DATA
	Function Description : Exchange data with the selected Slave MC .
*/
u8 SPI_Master_Transmit_Data_To(u8 PORT, u8 PIN, u8 DATA);

/*
	Function Name        : SPI_Master_Send_String_To
	Function Returns     : void
	Function Arguments   : u8 PORT, u8 PIN, u8 *DATA
	Function Description : Send String to the selected Slave MC .
*/
void SPI_Master_Send_String_To(u8 PORT, u8 PIN, u8* DATA);

/*
	Function Name        : SPI_Interrupt_Enable
	Function Returns     : void
	Function Arguments   : void
	Function Description : Enable SPI Interrupt .
*/
void SPI_Interrupt_Enable();

/*
	Function Name        : SPI_Stop_Comm_With_SS
	Function Returns     : void
	Function Arguments   : void
	Function Description : Set HIGH To the SS Pin to Stop Communicate With .
*/
void SPI_Stop_Comm_With_SS();

/*
	Function Name        : SPI_Stop_Comm_With
	Function Returns     : void
	Function Arguments   : u8 PORT, u8 PIN
	Function Description : Set HIGH To the Pin that connected to the SS Of the Slave to Stop Communicate With .
*/
void SPI_Stop_Comm_With(u8 PORT, u8 PIN);

/*
	Function Name        : SPI_ReCommunicate_With_SS
	Function Returns     : void
	Function Arguments   : void
	Function Description : Set HIGH To the SS Pin to Re-Communicate With .
*/
void SPI_ReCommunicate_With_SS();

/*
	Function Name        : SPI_ReCommunicate_With
	Function Returns     : void
	Function Arguments   : u8 PORT, u8 PIN
	Function Description : Set HIGH To the Pin that connected to the SS Of the Slave to Re-Communicate With .
*/
void SPI_ReCommunicate_With(u8 PORT, u8 PIN);



#endif /* SPI_H_ */
