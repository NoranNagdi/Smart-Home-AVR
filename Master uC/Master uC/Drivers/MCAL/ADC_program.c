/*
 * ADC_program.c
 *
 * Created: 10/23/2023 9:16:25 AM
 *  Author: DELL
 */ 

#include "../MCAL/ADC_interface.h"
#include "../MCAL/ADC_private.h"
#include "../Common_Macros.h"
#include "../HAL/LED_interface.h"

void ADC_init(void)
{
	/*disable ADC*/
	CLEAR_BIT(ADCSRA,ADEN);
	
	/*use AVCC*/
	SET_BIT(ADMUX,REFS0);
	CLEAR_BIT(ADMUX,REFS1);
	
	/*Right adjustment*/
	CLEAR_BIT(ADMUX,REFS1);
	
	/*Select Prescaler 128*/
	SET_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);
	
	/*Disable ADC Interrupts*/
	CLEAR_BIT(ADCSRA,ADIE);
	
	/*disable auto triggering*/
	CLEAR_BIT(ADCSRA,ADATE);
	
	/*clear the source of auto triggering*/
	CLEAR_BIT(SFIOR,ADTS0);
	CLEAR_BIT(SFIOR,ADTS1);
	CLEAR_BIT(SFIOR,ADTS2);
		//
	///*clear start conversion*/
	//CLEAR_BIT(ADCSRA,ADSC);
	
	/*Clear flag*/
	SET_BIT(ADCSRA,ADIF);
	
	/*enable ADC*/
	SET_BIT(ADCSRA,ADEN);
}

void ADC_readChannel(uint8 CH_num, uint16* ptr)
{
	/*initialize channel to 0*/
	ADMUX |= ((ADMUX & 0xE0) | (CH_num & 0x07)); 
	
	/*Start Conversion*/
	SET_BIT(ADCSRA,ADSC);
		
	/*wait for flag*/
	while(BIT_IS_CLEAR(ADCSRA,ADIF));
		
	/*clear flag*/
	SET_BIT(ADCSRA,ADIF);
	
	/*save the data*/
	*ptr = ADC;
}

void ADC_autotrigger_init(void)
{
	/*disable ADC*/
	CLEAR_BIT(ADCSRA,ADEN);
	
	/*use AVCC*/
	SET_BIT(ADMUX,REFS0);
	CLEAR_BIT(ADMUX,REFS1);
	
	/*Right adjustment*/
	CLEAR_BIT(ADMUX,REFS1);
	
	/*Select Prescaler 128*/
	SET_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);
	
	/*Disable ADC Interrupts*/
	CLEAR_BIT(ADCSRA,ADIE);
	
	/*enable auto triggering*/
	SET_BIT(ADCSRA,ADATE);
	
	/*specify the source of auto triggering*/
	CLEAR_BIT(SFIOR,ADTS0);
	SET_BIT(SFIOR,ADTS1);
	CLEAR_BIT(SFIOR,ADTS2);
	
	/*clear start conversion*/
	CLEAR_BIT(ADCSRA,ADSC);
	
	/*Clear flag*/
	SET_BIT(ADCSRA,ADIF);
	
	/*enable ADC*/
	SET_BIT(ADCSRA,ADEN);
}

void ADC_autotrigger_readChannel(uint8 CH_num, uint16* ptr)
{
	/*initialize channel to 0*/
	ADMUX |= ((ADMUX & 0xE0) | (CH_num & 0x07));
		
	/*wait for flag*/
	while(BIT_IS_CLEAR(ADCSRA,ADIF));
	
	/*save the data*/
	*ptr = ADC;
	
	/*clear flag*/
	SET_BIT(ADCSRA,ADIF);

}

