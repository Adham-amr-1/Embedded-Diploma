#include "IR_Sensor.h"

void IR_Sensor_vInit(u8 SENSOR_PORT, u8 SENSOR_PIN){
	DIO_Set_Pin_Direction(SENSOR_PORT, SENSOR_PIN, INPUT);
}
u8 IR_Sensor_u8Read(u8 SENSOR_PORT, u8 SENSOR_PIN){
	return DIO_u8ReadPin(SENSOR_PORT, SENSOR_PIN);
}
