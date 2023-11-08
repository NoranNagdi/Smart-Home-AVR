/*
 * LCD_program.c
 *
 * Created: 10/21/2023 11:42:45 AM
 *  Author: DELL
 */ 
#define F_CPU 16000000
#include "../MCAL/DIO_interface.h"
#include "../HAL/LCD_interface.h"
#include "../HAL/LCD_cfg.h"
#include <util/delay.h>

void LCD_init(void)
{
	DIO_voidSetPinDirection(LCD_RS_PORT_ID,LCD_RS_PIN_ID,OUTPUT_PIN);
	DIO_voidSetPinDirection(LCD_E_PORT_ID,LCD_E_PIN_ID,OUTPUT_PIN);
	_delay_ms(20);
	DIO_voidSetPinDirection(LCD_DATA_PORT_ID,LCD_D4_PIN_ID,OUTPUT_PIN);
	DIO_voidSetPinDirection(LCD_DATA_PORT_ID,LCD_D5_PIN_ID,OUTPUT_PIN);
	DIO_voidSetPinDirection(LCD_DATA_PORT_ID,LCD_D6_PIN_ID,OUTPUT_PIN);
	DIO_voidSetPinDirection(LCD_DATA_PORT_ID,LCD_D7_PIN_ID,OUTPUT_PIN);

	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE_INIT1);
	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE_INIT2);

	/* use 2-lines LCD + 4-bits Data Mode + 5*7 dot display Mode */
	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE);
	LCD_sendCommand(0x06);


	LCD_sendCommand(LCD_CURSOR_OFF); /* cursor off */
	LCD_sendCommand(LCD_CLEAR_COMMAND); /* clear LCD at the beginning */
	
}


void LCD_sendCommand(uint8 command)
{
	DIO_voidSetPinValue(LCD_RS_PORT_ID,LCD_RS_PIN_ID,LOGIC_LOW);
	_delay_ms(1); 
	DIO_voidSetPinValue(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_HIGH); 
	_delay_ms(1); 
	
	DIO_voidSetPinValue(LCD_DATA_PORT_ID,LCD_D4_PIN_ID,GET_BIT(command,4));
	DIO_voidSetPinValue(LCD_DATA_PORT_ID,LCD_D5_PIN_ID,GET_BIT(command,5));
	DIO_voidSetPinValue(LCD_DATA_PORT_ID,LCD_D6_PIN_ID,GET_BIT(command,6));
	DIO_voidSetPinValue(LCD_DATA_PORT_ID,LCD_D7_PIN_ID,GET_BIT(command,7));
	
	_delay_ms(1); 
	DIO_voidSetPinValue(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_LOW); /* Disable LCD E=0 */
	_delay_ms(1); 
	DIO_voidSetPinValue(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_HIGH); /* Enable LCD E=1 */
	_delay_ms(1); 

	DIO_voidSetPinValue(LCD_DATA_PORT_ID,LCD_D4_PIN_ID,GET_BIT(command,0));
	DIO_voidSetPinValue(LCD_DATA_PORT_ID,LCD_D5_PIN_ID,GET_BIT(command,1));
	DIO_voidSetPinValue(LCD_DATA_PORT_ID,LCD_D6_PIN_ID,GET_BIT(command,2));
	DIO_voidSetPinValue(LCD_DATA_PORT_ID,LCD_D7_PIN_ID,GET_BIT(command,3));

	_delay_ms(1); 
	DIO_voidSetPinValue(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_LOW); /* Disable LCD E=0 */
	_delay_ms(1); 
}



void LCD_displayCharacter(uint8 data)
{
	DIO_voidSetPinValue(LCD_RS_PORT_ID,LCD_RS_PIN_ID,LOGIC_HIGH); /* Data Mode RS=1 */
	_delay_ms(1); 
	DIO_voidSetPinValue(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_HIGH); /* Enable LCD E=1 */
	_delay_ms(1); 	
	
	DIO_voidSetPinValue(LCD_DATA_PORT_ID,LCD_D4_PIN_ID,GET_BIT(data,4));
	DIO_voidSetPinValue(LCD_DATA_PORT_ID,LCD_D5_PIN_ID,GET_BIT(data,5));
	DIO_voidSetPinValue(LCD_DATA_PORT_ID,LCD_D6_PIN_ID,GET_BIT(data,6));
	DIO_voidSetPinValue(LCD_DATA_PORT_ID,LCD_D7_PIN_ID,GET_BIT(data,7));

	_delay_ms(1); 
	DIO_voidSetPinValue(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_LOW); /* Disable LCD E=0 */
	_delay_ms(1); 
	DIO_voidSetPinValue(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_HIGH); /* Enable LCD E=1 */
	_delay_ms(1); 

	DIO_voidSetPinValue(LCD_DATA_PORT_ID,LCD_D4_PIN_ID,GET_BIT(data,0));
	DIO_voidSetPinValue(LCD_DATA_PORT_ID,LCD_D5_PIN_ID,GET_BIT(data,1));
	DIO_voidSetPinValue(LCD_DATA_PORT_ID,LCD_D6_PIN_ID,GET_BIT(data,2));
	DIO_voidSetPinValue(LCD_DATA_PORT_ID,LCD_D7_PIN_ID,GET_BIT(data,3));

	_delay_ms(1); 
	DIO_voidSetPinValue(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_LOW); /* Disable LCD E=0 */
	_delay_ms(1); 
}


void LCD_displayString(const char *Str)
{
	while((*Str) != '\0')
	{
		LCD_displayCharacter(*Str);
		Str++;
	}	
}


void LCD_moveCursor(uint8 row,uint8 col)
{
	uint8 lcd_memory_address;
	
	/* Calculate the required address in the LCD DDRAM */
	switch(row)
	{
		case 0:
		lcd_memory_address=col;
		break;
		case 1:
		lcd_memory_address=col+0x40;
		break;
		case 2:
		lcd_memory_address=col+0x10;
		break;
		case 3:
		lcd_memory_address=col+0x50;
		break;
	}
	/* Move the LCD cursor to this specific address */
	LCD_sendCommand(lcd_memory_address | LCD_SET_CURSOR_LOCATION);
}


void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str)
{
	LCD_moveCursor(row,col); /* go to to the required LCD position */
	LCD_displayString(Str); /* display the string */
}


void LCD_intgerToString(int data)
{
	char buff[16]; /* String to hold the ascii result */
	itoa(data,buff,10); /* Use itoa C function to convert the data to its corresponding ASCII value, 10 for decimal */
	LCD_displayString(buff); /* Display the string */
}


void LCD_clearScreen(void)
{
	LCD_sendCommand(LCD_CLEAR_COMMAND);
}