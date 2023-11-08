/*
 * SPI_interface.h
 *
 * Created: 10/31/2023 2:50:32 PM
 *  Author: DELL
 */ 


#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

#include "../Std_Types.h"

void SPI_init(void);

void SPI_send(uint8 value);

void SPI_receive(uint8* value);




#endif /* SPI_INTERFACE_H_ */