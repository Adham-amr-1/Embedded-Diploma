#include "SPI.h"

void SPI_Set_DORD(){
	#if LSB_FIRST
	SET_BIT(SPCR,DORD);
	#elif MSB_FIRST
	CLEAR_BIT(SPCR,DORD);
	#endif
}
void Master_Select(){
	SET_BIT(SPCR,MSTR);
}
void Slave_Select(){
	CLEAR_BIT(SPCR,MSTR);
}
void Set_CLK_Polarity(){
	#if IDLE_LOW
	CLEAR_BIT(SPCR,CPOL);
	#elif IDLE_HIGH
	SET_BIT(SPCR,CPOL);
	#endif
}
void Set_Clk_Phase(){
	#if TX_ON_RISING
	CLEAR_BIT(SPCR,CPHA);
	#elif TX_ON_FALLING
	SET_BIT(SPCR,CPHA);
	#endif
}
u8 SPI_Check_Collision(){
	return READ_BIT(SPSR,WCOL);
}
void SPI_Set_CLK(){
	#if DIVIDE_BY_4
	CLEAR_BIT(SPCR,SPR0);
	CLEAR_BIT(SPCR,SPR1);
	CLEAR_BIT(SPSR,SPI2X);
	#elif DIVIDE_BY_16
	SET_BIT(SPCR,SPR0);
	CLEAR_BIT(SPCR,SPR1);
	CLEAR_BIT(SPSR,SPI2X);
	#elif DIVIDE_BY_64
	CLEAR_BIT(SPCR,SPR0);
	SET_BIT(SPCR,SPR1);
	CLEAR_BIT(SPSR,SPI2X);
	#elif DIVIDE_BY_128
	SET_BIT(SPCR,SPR0);
	SET_BIT(SPCR,SPR1);
	CLEAR_BIT(SPSR,SPI2X);
	#elif DIVIDE_BY_2
	CLEAR_BIT(SPCR,SPR0);
	CLEAR_BIT(SPCR,SPR1);
	SET_BIT(SPSR,SPI2X);
	#elif DIVIDE_BY_8
	SET_BIT(SPCR,SPR0);
	CLEAR_BIT(SPCR,SPR1);
	SET_BIT(SPSR,SPI2X);
	#elif DIVIDE_BY_32
	CLEAR_BIT(SPCR,SPR0);
	SET_BIT(SPCR,SPR1);
	SET_BIT(SPSR,SPI2X);
	#endif
}
void SPI_MasterInit(){
	// Set Master Pins
	DIO_Set_Pin_Direction(PORT_B, PIN_NO_4, OUTPUT);
	DIO_Set_Pin_Direction(PORT_B, PIN_NO_5, OUTPUT);
	DIO_Set_Pin_Direction(PORT_B, PIN_NO_6, INPUT);
	DIO_Set_Pin_Direction(PORT_B, PIN_NO_7, OUTPUT);
	// Enable SPI Communication
	SET_BIT(SPCR,SPE);
	// Set the MC As Master
	Master_Select();
	// Set the MC Send Bits
	SPI_Set_DORD();
	// Set Master CLK
	SPI_Set_CLK();
	// Set Polarity
	Set_CLK_Polarity();
	// Set Phase
	Set_Clk_Phase();
	// Set SS to HIGH
	DIO_Write_Pin(PORT_B, PIN_NO_4, HIGH);
}
void SPI_SlaveInit(){
	// Set Slave Pins
	DIO_Set_Pin_Direction(PORT_B, PIN_NO_4, INPUT);
	DIO_Set_Pin_Direction(PORT_B, PIN_NO_5, INPUT);
	DIO_Set_Pin_Direction(PORT_B, PIN_NO_6, OUTPUT);
	DIO_Set_Pin_Direction(PORT_B, PIN_NO_7, INPUT);
	// Enable SPI Communication
	SET_BIT(SPCR,SPE);
	// Set the MC As Slave
	Slave_Select();
	// Set Polarity
	Set_CLK_Polarity();
	// Set the MC Send Bits
	SPI_Set_DORD();
	// Set Phase
	Set_Clk_Phase();
}
// Master SS Connected to Slave SS
u8 SPI_Master_Transmit_Data(u8 DATA){
	// Clear the Required SS
	DIO_Write_Pin(PORT_B, PIN_NO_4, LOW);
	// Load Data in SPDR
	SPDR = DATA;
	// Check that the Data exchange Successfuly
	while(READ_BIT(SPSR,SPIF) == 0);
	// Return the Exchanged data
	return SPDR;
}
u8 SPI_Slave_Recieve_Data(u8 DATA){
	// Load Data in SPDR
	SPDR = DATA;
	// Check that the Data exchange Successfuly
	while(READ_BIT(SPSR,SPIF) == 0);
	// Return the Exchanged data
	return SPDR;
}
void SPI_Master_Send_String(u8* DATA){
	while(*DATA != 0){
		SPI_Master_Transmit_Data(*DATA);
		_delay_ms(300);
		DATA++;
	}
}
//**************************************************************************************
// If i use more than one Slave ( To Control the pin ) ( Write it at Master MC )
void SPI_Slave_SelectInit(u8 PORT, u8 PIN){
	DIO_Set_Pin_Direction(PORT, PIN, OUTPUT);
	DIO_Write_Pin(PORT, PIN, HIGH);
}
void SPI_Exchange_With(u8 PORT, u8 PIN){
	DIO_Write_Pin(PORT, PIN, LOW);
}
// Using Multiple Slaves
u8 SPI_Master_Transmit_Data_To(u8 PORT, u8 PIN, u8 DATA){
	// Clear the Required SS
	SPI_Exchange_With(PORT, PIN);
	// Load Data in SPDR
	SPDR = DATA;
	// Check that the Data exchange Successfuly
	while(READ_BIT(SPSR,SPIF) == 0);
	// Return the Exchanged data
	return SPDR;
}
void SPI_Master_Send_String_To(u8 PORT, u8 PIN, u8* DATA){
	while(*DATA != 0){
		SPI_Master_Transmit_Data_To(PORT, PIN,*DATA);
		_delay_ms(300);
		DATA++;
	}
}
//**************************************************************************************
void SPI_Interrupt_Enable(){
	SET_BIT(SPCR,SPIE);
}

void SPI_Stop_Comm_With_SS(){
	DIO_Write_Pin(PORT_B, PIN_NO_4, HIGH);
}
void SPI_Stop_Comm_With(u8 PORT, u8 PIN){
	DIO_Write_Pin(PORT, PIN, HIGH);
}
void SPI_ReCommunicate_With(u8 PORT, u8 PIN){
	DIO_Write_Pin(PORT, PIN, LOW);
}
void SPI_ReCommunicate_With_SS(){
	DIO_Write_Pin(PORT_B, PIN_NO_4, LOW);
}




