/*
 * ADC_interface.h
 *
 * Created: 10/23/2023 9:16:40 AM
 *  Author: DELL
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#include "../Std_Types.h"


typedef enum{
	CH_0,CH_1,CH_2,CH_3,CH_4,CH_5,CH_6
}Channel_num;

void ADC_init(void);

void ADC_readChannel(uint8 CH_num, uint16* ptr);

void ADC_autotrigger_init(void);

void ADC_autotrigger_readChannel(uint8 CH_num, uint16* ptr);



#endif /* ADC_INTERFACE_H_ */
