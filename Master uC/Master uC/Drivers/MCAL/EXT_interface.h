/*
 * EXT_interface.h
 *
 * Created: 10/22/2023 2:05:07 PM
 *  Author: DELL
 */ 


#ifndef EXT_INTERFACE_H_
#define EXT_INTERFACE_H_

#include "../Std_Types.h"

#define LOW_LEVEL      0
#define LOGICAL_CHANGE 1
#define FALLING        2
#define RISING         3

#define EXT_0   0
#define EXT_1   1
#define EXT_2   2


void EXT_init(uint8 EXT_num, uint8 EXT_sense);

void EXT_callback(uint8 EXT_num, void (*ptr)(void));

#endif /* EXT_INTERFACE_H_ */