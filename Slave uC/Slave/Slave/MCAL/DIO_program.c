/*
 * DIO_program.c
 *
 * Created: 10/20/2023 11:00:12 AM
 *  Author: DELL
 */ 
#include "../MCAL/DIO_interface.h"
#include "../MCAL/DIO_private.h"
#include "../Common_Macros.h"


void DIO_voidSetPortDirection(uint8 copy_u8PortID, uint8 copy_u8PortDir)
{
	switch(copy_u8PortID)
	{
		case PORTA_ID:
		DDRA = copy_u8PortDir;
		break;
		
		case PORTB_ID:
		DDRB = copy_u8PortDir;
		break;
		
		case PORTC_ID:
		DDRC = copy_u8PortDir;
		break;
		
		case PORTD_ID:
		DDRD = copy_u8PortDir;
		break;
		
	}
}
void DIO_voidSetPortValue(uint8 copy_u8PortID, uint8 copy_u8PortVal)
{
	switch(copy_u8PortID)
	{
		case PORTA_ID:
		PORTA = copy_u8PortVal;
		break;
		
		case PORTB_ID:
		PORTB = copy_u8PortVal;
		break;
		
		case PORTC_ID:
		PORTC = copy_u8PortVal;
		break;
		
		case PORTD_ID:
		PORTD = copy_u8PortVal;
		break;
		
	}
}

void DIO_voidSetPinDirection(uint8 copy_u8PortID,uint8 copy_u8PinID, uint8 copy_u8PinDir)
{
	switch(copy_u8PortID)
	{
		case PORTA_ID:
		if(copy_u8PinDir == OUTPUT_PIN)
		{
			SET_BIT(DDRA,copy_u8PinID);
		}
		else
		{
			CLEAR_BIT(DDRA,copy_u8PinID);
		}
		break;
		
		case PORTB_ID:
		if(copy_u8PinDir == OUTPUT_PIN)
		{
			SET_BIT(DDRB,copy_u8PinID);
		}
		else
		{
			CLEAR_BIT(DDRB,copy_u8PinID);
		}
		break;
		
		case PORTC_ID:
		if(copy_u8PinDir == OUTPUT_PIN)
		{
			SET_BIT(DDRC,copy_u8PinID);
		}
		else
		{
			CLEAR_BIT(DDRC,copy_u8PinID);
		}
		break;
		
		case PORTD_ID:
		if(copy_u8PinDir == OUTPUT_PIN)
		{
			SET_BIT(DDRD,copy_u8PinID);
		}
		else
		{
			CLEAR_BIT(DDRD,copy_u8PinID);
		}
		break;
		
	}
}
void DIO_voidSetPinValue(uint8 copy_u8PortID,uint8 copy_u8PinID, uint8 copy_u8PinValue)
{
	switch(copy_u8PortID)
	{
		case PORTA_ID:
		if(copy_u8PinValue == LOGIC_HIGH)
		{
			SET_BIT(PORTA,copy_u8PinID);
		}
		else
		{
			CLEAR_BIT(PORTA,copy_u8PinID);
		}
		break;
		
		case PORTB_ID:
		if(copy_u8PinValue == LOGIC_HIGH)
		{
			SET_BIT(PORTB,copy_u8PinID);
		}
		else
		{
			CLEAR_BIT(PORTB,copy_u8PinID);
		}
		break;
		
		case PORTC_ID:
		if(copy_u8PinValue == LOGIC_HIGH)
		{
			SET_BIT(PORTC,copy_u8PinID);
		}
		else
		{
			CLEAR_BIT(PORTC,copy_u8PinID);
		}
		break;
		
		case PORTD_ID:
		if(copy_u8PinValue == LOGIC_HIGH)
		{
			SET_BIT(PORTD,copy_u8PinID);
		}
		else
		{
			CLEAR_BIT(PORTD,copy_u8PinID);
		}
		break;
		
	}
}

uint8 DIO_voidGetPinValue(uint8 copy_u8PortID, uint8 copy_PinID)
{
	uint8 value = LOGIC_LOW;
	switch(copy_u8PortID)
	{
		case PORTA_ID:
		if(BIT_IS_SET(PINA,copy_PinID))
		{
			value = LOGIC_HIGH;
		}
		else
		{
			value = LOGIC_LOW;
		}
		break;
		
		case PORTB_ID:
		if(BIT_IS_SET(PINB,copy_PinID))
		{
			value = LOGIC_HIGH;
		}
		else
		{
			value = LOGIC_LOW;
		}
		break;
		
		case PORTC_ID:
		if(BIT_IS_SET(PINC,copy_PinID))
		{
			value = LOGIC_HIGH;
		}
		else
		{
			value = LOGIC_LOW;
		}
		break;
		
		case PORTD_ID:
		if(BIT_IS_SET(PIND,copy_PinID))
		{
			value = LOGIC_HIGH;
		}
		else
		{
			value = LOGIC_LOW;
		}
		break;
	}
	return value;
}

uint8 DIO_voidGetPortValue(uint8 copy_u8PortID)
{
	uint8 value = LOGIC_LOW;

	/* Read the port value as required */
	switch(copy_u8PortID)
	{
	case PORTA_ID:
		value = PINA;
		break;
	case PORTB_ID:
		value = PINB;
		break;
	case PORTC_ID:
		value = PINC;
		break;
	case PORTD_ID:
		value = PIND;
		break;
	}

	return value;
}

void DIO_TogglePin(uint8 copy_u8PortID, uint8 copy_PinID)
{
	switch(copy_u8PortID)
	{
		case PORTA_ID:
		TOGGLE_BIT(PORTA,copy_PinID);
		break;
		
		case PORTB_ID:
		TOGGLE_BIT(PORTB,copy_PinID);
		break;
		
		case PORTC_ID:
		TOGGLE_BIT(PORTC,copy_PinID);
		break;
		
		case PORTD_ID:
		TOGGLE_BIT(PORTD,copy_PinID);
		break;
	}
}