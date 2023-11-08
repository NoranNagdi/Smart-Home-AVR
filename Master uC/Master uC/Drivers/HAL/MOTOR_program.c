/*
 * MOTOR_program.c
 *
 * Created: 11/8/2023 5:44:12 PM
 *  Author: DELL
 */ 

#include "../HAL/MOTOR_interface.h"
#include "../HAL/MOTOR_cfg.h"
#include "../MCAL/TIMER_interface.h"


void DcMotor_init(void)
{
	DIO_voidSetPinDirection(DC_MOTOR_INPUT_PORT_ID,DC_MOTOR_INPUT1_PIN_ID,OUTPUT_PIN);
	DIO_voidSetPinDirection(DC_MOTOR_INPUT_PORT_ID,DC_MOTOR_INPUT2_PIN_ID,OUTPUT_PIN);

	DIO_voidSetPinValue(DC_MOTOR_INPUT_PORT_ID,DC_MOTOR_INPUT1_PIN_ID,LOGIC_LOW);
	DIO_voidSetPinValue(DC_MOTOR_INPUT_PORT_ID,DC_MOTOR_INPUT2_PIN_ID,LOGIC_LOW);
}


void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{
	set_OCR(speed);

	switch(state)
	{
		default:
		case STOP:
		DIO_voidSetPinValue(DC_MOTOR_INPUT_PORT_ID,DC_MOTOR_INPUT1_PIN_ID,LOGIC_LOW);
		DIO_voidSetPinValue(DC_MOTOR_INPUT_PORT_ID,DC_MOTOR_INPUT2_PIN_ID,LOGIC_LOW);
		break;
		case A_CW:
		DIO_voidSetPinValue(DC_MOTOR_INPUT_PORT_ID,DC_MOTOR_INPUT1_PIN_ID,LOGIC_HIGH);
		DIO_voidSetPinValue(DC_MOTOR_INPUT_PORT_ID,DC_MOTOR_INPUT2_PIN_ID,LOGIC_LOW);
		break;
		case CW:
		DIO_voidSetPinValue(DC_MOTOR_INPUT_PORT_ID,DC_MOTOR_INPUT1_PIN_ID,LOGIC_LOW);
		DIO_voidSetPinValue(DC_MOTOR_INPUT_PORT_ID,DC_MOTOR_INPUT2_PIN_ID,LOGIC_HIGH);
		break;
	}
}