/*
* std_macros.h
*
* Created 3/10/2024 10:17:05
* Author: Adham Amr
*/
#define REGISTER_SIZE 8
#define SET_BIT(reg,bit)       reg|=(1<<bit)
#define CLEAR_BIT(reg,bit)     reg&=(~(1<<bit))
#define TOGGLE_BIT(reg,bit)    reg^=(1<<bit)
#define READ_BIT(reg,bit)    ((reg&(1<<bit))>>bit)
#define IS_BIT_SET(reg,bit)  ((reg&(1<<bit))>>bit)
#define IS_BIT_CLR(reg,bit) !((reg&(1<<bit))>>bit)
#define ROR(reg,num)           reg = (reg<<(REGISTER_SIZE-num)) | (reg>>num)
#define ROL(reg,num)           reg = (reg>>(REGISTER_SIZE-num)) | (reg<<num)