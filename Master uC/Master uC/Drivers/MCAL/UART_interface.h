/*
 * UART_interface.h
 *
 * Created: 10/30/2023 10:43:56 AM
 *  Author: DELL
 */ 


#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_


#include "../Std_Types.h"


void UART_init(uint16 baudRate);

void UART_receive(uint8* value);

void UART_transmit(uint8 value);

void UART_INT_receive(uint8* value);

void UART_callback(void (*ptr)(void));



#endif /* UART_INTERFACE_H_ */