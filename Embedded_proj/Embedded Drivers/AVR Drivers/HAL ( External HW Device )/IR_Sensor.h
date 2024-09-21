/*
 * IR_Sensor.h
 *
 *  Created on: Aug 24, 2024
 *      Author: ADHam
 */
#include "DIO.h"
#include "STD_Types.h"
#ifndef IR_SENSOR_H_
#define IR_SENSOR_H_

/*
Function Name        : IR_Sensor_vInit
Function Returns     : void
Function Arguments   : u8 SENSOR_PORT, u8 SENSOR_PIN
Function Description : Initialize IR Pin to be input
*/
void IR_Sensor_vInit(u8 SENSOR_PORT, u8 SENSOR_PIN);

/*
Function Name        : IR_Sensor_u8Read
Function Returns     : u8
Function Arguments   : u8 SENSOR_PORT, u8 SENSOR_PIN
Function Description : return the reading of ir sensor
*/
u8 IR_Sensor_u8Read(u8 SENSOR_PORT, u8 SENSOR_PIN);
#endif /* HAL___EXTERNAL_HW_DEVICE___IR_SENSOR_H_ */
