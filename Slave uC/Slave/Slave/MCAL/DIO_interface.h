/*
 * DIO_interface.h
 *
 * Created: 10/20/2023 10:59:37 AM
 *  Author: DELL
 */ 

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include"../Std_Types.h"
#include"../Common_Macros.h"


#define OUTPUT_PIN 1
#define INPUT_PIN  0

#define NO_OF_PORTS 4
#define NO_OF_PINS 8


typedef enum{
	PORTA_ID,PORTB_ID,PORTC_ID,PORTD_ID
	}PORTID;
	
typedef enum{
	PIN0_ID,PIN1_ID,PIN2_ID,PIN3_ID,PIN4_ID,PIN5_ID,PIN6_ID,PIN7_ID
	}PINID;

void DIO_voidSetPortDirection(uint8 copy_u8PortID, uint8 copy_u8PortDir);
void DIO_voidSetPortValue(uint8 copy_u8PortID, uint8 copy_u8PortVal);

void DIO_voidSetPinDirection(uint8 copy_u8PortID,uint8 copy_u8PinID, uint8 copy_u8PinDir);
void DIO_voidSetPinValue(uint8 copy_u8PortID,uint8 copy_u8PinID, uint8 copy_u8PinValue);

uint8 DIO_voidGetPinValue(uint8 copy_u8PortID, uint8 copy_PinID);
uint8 DIO_voidGetPortValue(uint8 copy_u8PortID);

void DIO_TogglePin(uint8 copy_u8PortID, uint8 copy_PinID);

#endif /* DIO_INTERFACE_H_ */