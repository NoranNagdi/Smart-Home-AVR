/*
 * TIMER_interface.h
 *
 * Created: 10/26/2023 11:52:52 PM
 *  Author: DELL
 */ 


#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

#include "../Std_Types.h"
#include "../MCAL/TIMER_cfg.h"

void TIMER0_init(void);

void TIMER0_PWM_init(void);

void set_OCR(uint8 value);

void set_TCNT(uint8 value);

void TIMER0_deinit(void);

void TIMER0_callback(uint8 mode,void (*ptr)(void));

void delay (uint8 delayUnit,uint32 delayValue);


#endif /* TIMER_INTERFACE_H_ */