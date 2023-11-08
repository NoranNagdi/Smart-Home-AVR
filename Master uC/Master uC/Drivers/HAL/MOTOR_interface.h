/*
 * MOTOR_interface.h
 *
 * Created: 11/8/2023 5:44:29 PM
 *  Author: DELL
 */ 


#ifndef MOTOR_INTERFACE_H_
#define MOTOR_INTERFACE_H_

#include "../Std_Types.h"


typedef enum{
	STOP,A_CW,CW
}DcMotor_State;

void DcMotor_init(void);

void DcMotor_Rotate(DcMotor_State state,uint8 speed);


#endif /* MOTOR_INTERFACE_H_ */