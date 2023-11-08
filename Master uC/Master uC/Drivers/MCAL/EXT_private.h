/*
 * EXT_private.h
 *
 * Created: 10/22/2023 2:04:52 PM
 *  Author: DELL
 */ 


#ifndef EXT_PRIVATE_H_
#define EXT_PRIVATE_H_

#include "../MCAL/DIO_interface.h"

#define GICR   *((volatile uint8*)(0x5B))
#define GIFR   *((volatile uint8*)(0x5A))
#define MCUCR  *((volatile uint8*)(0x55))
#define MCUCSR *((volatile uint8*)(0x54))

#define ISC11 3
#define ISC10 2

#define ISC01 1
#define ISC00 0

#define ISC2  6

#define INT1_EN 7
#define INT0_EN 6
#define INT2_EN 5


#define EXT_0_PORT_ID  PORTD_ID
#define EXT_0_PIN_ID   PIN2_ID

#define EXT_1_PORT_ID  PORTD_ID
#define EXT_1_PIN_ID   PIN3_ID

#define EXT_2_PORT_ID  PORTB_ID
#define EXT_2_PIN_ID   PIN2_ID


#endif /* EXT_PRIVATE_H_ */