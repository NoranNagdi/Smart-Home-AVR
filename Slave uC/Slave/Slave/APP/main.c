/*
 * GccApplication1.c
 *
 * Created: 10/20/2023 10:48:35 AM
 * Author : DELL
 */ 
#define F_CPU 16000000
#include "../MCAL/DIO_interface.h"
#include "../HAL/LED_interface.h"
#include "../HAL/LCD_interface.h"
#include "../MCAL/SPI_interface.h"
#include <util/delay.h>

uint8 received;
uint8 data_arr[3]={0};


int main(void)
{	
		/*ALL INITS*/
	LCD_init();
	SPI_init();
	
	/*LCD initial display*/
	LCD_moveCursor(0,0);
	LCD_displayString("FLAME:  ");
				
	LCD_moveCursor(1,0);
	LCD_displayString("GAS:  ");
	
	LCD_moveCursor(2,4);
	LCD_displayString("TEMP:   C");
	
	while(1)
	{
		/*Saving Data Mode*/
		for(uint8 i=0; i<3; i++)
		{
			SPI_receive(&data_arr[i]);
			_delay_ms(10);
		}
		LCD_moveCursor(0,8);
		LCD_intgerToString(data_arr[0]);
		
		LCD_moveCursor(1,6);
		LCD_intgerToString(data_arr[1]);
		
		LCD_moveCursor(2,10);
		LCD_intgerToString(data_arr[2]);
	}
}

