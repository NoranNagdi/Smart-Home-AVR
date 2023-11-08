/*
 * PUSHBUTTON_program.c
 *
 * Created: 10/20/2023 2:49:55 PM
 *  Author: DELL
 */ 
#define F_CPU 16000000
#include "../MCAL/DIO_interface.h"
#include "../HAL/PUSHBUTTON_interface.h"
#include "../HAL/PUSHBUTTON_cfg.h"
#include <util/delay.h>


uint8 buttonIsPressed(uint8 PORTID, uint8 PINID)
{
	DIO_voidSetPinDirection(PORTID,PINID,INPUT_PIN);
	if(DIO_voidGetPinValue(PORTID,PINID))
	{
		_delay_ms(PUSH_BUTTON_DEBOUNCING_TIME);
		if(DIO_voidGetPinValue(PORTID,PINID))
		{
		return LOGIC_LOW;
		}
		while(DIO_voidGetPinValue(PORTID,PINID));
	}
	else
	{
		return LOGIC_HIGH;
	}
}
