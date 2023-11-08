/*
 * EXT_program.c
 *
 * Created: 10/22/2023 2:04:31 PM
 *  Author: DELL
 */ 

#include "../MCAL/EXT_interface.h"
#include "../MCAL/EXT_private.h"
#include "../MCAL/DIO_interface.h"

void (*EXT0_ptr)(void);
void (*EXT1_ptr)(void);
void (*EXT2_ptr)(void);


void EXT_init(uint8 EXT_num, uint8 EXT_sense)
{
	switch(EXT_num)
	{
		case EXT_0:
		DIO_voidSetPinDirection(EXT_0_PORT_ID,EXT_0_PIN_ID,INPUT_PIN);
		SET_BIT(GICR,INT0_EN);
		switch(EXT_sense)
		{
			case LOW_LEVEL:
			CLEAR_BIT(MCUCR,ISC00);
			CLEAR_BIT(MCUCR,ISC01);
			break;
			case LOGICAL_CHANGE:
			SET_BIT(MCUCR,ISC00);
			CLEAR_BIT(MCUCR,ISC01);
			break;
			case FALLING:
			CLEAR_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
			break;
			case RISING:
			SET_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
			break;	
		}
		break;
	case EXT_1:
	DIO_voidSetPinDirection(EXT_1_PORT_ID,EXT_1_PIN_ID,INPUT_PIN);
	SET_BIT(GICR,INT1_EN);
	switch(EXT_sense)
	{
		case LOW_LEVEL:
		CLEAR_BIT(MCUCR,ISC10);
		CLEAR_BIT(MCUCR,ISC11);
		break;
		case LOGICAL_CHANGE:
		SET_BIT(MCUCR,ISC10);
		CLEAR_BIT(MCUCR,ISC11);
		break;
		case FALLING:
		CLEAR_BIT(MCUCR,ISC10);
		SET_BIT(MCUCR,ISC11);
		break;
		case RISING:
		SET_BIT(MCUCR,ISC10);
		SET_BIT(MCUCR,ISC11);
		break;
	}
	break;
	case EXT_2:
	DIO_voidSetPinDirection(EXT_2_PORT_ID,EXT_2_PIN_ID,INPUT_PIN);
	SET_BIT(GICR,INT2_EN);
	switch(EXT_sense)
	{
		case FALLING:
		CLEAR_BIT(MCUCSR,ISC2);
		break;
		case RISING:
		SET_BIT(MCUCSR,ISC2);
		break;
	}
	break;
	}
}

void EXT_callback(uint8 EXT_num, void (*ptr)(void))
{
	switch(EXT_num)
	{
		case EXT_0:
		EXT0_ptr = ptr;
		break;
		case EXT_1:
		EXT1_ptr = ptr;
		break;
		case EXT_2:
		EXT2_ptr = ptr;
		break;
	}
}

void __vector_1()__attribute__((signal));
void __vector_1()
{
	EXT0_ptr();
}

void __vector_2()__attribute__((signal));
void __vector_2()
{
	EXT1_ptr();
}

void __vector_3()__attribute__((signal));
void __vector_3()
{
	EXT2_ptr();
}
