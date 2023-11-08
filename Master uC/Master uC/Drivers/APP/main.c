/*
 * GccApplication1.c
 *
 * Created: 10/20/2023 10:48:35 AM
 * Author : DELL
 */ 
#define F_CPU 16000000
#include "../MCAL/DIO_interface.h"
#include "../MCAL/GIE_interface.h"
#include "../MCAL/EXT_interface.h"
#include "../MCAL/ADC_interface.h"
#include "../HAL/LED_interface.h"
#include "../HAL/LCD_interface.h"
#include "../HAL/PUSHBUTTON_interface.h"
#include "../MCAL/TIMER_interface.h"
#include "../MCAL/UART_interface.h"
#include "../MCAL/SPI_interface.h"
#include "../HAL/MOTOR_interface.h"
#include <util/delay.h>

uint16* ptr1 = NULL;
uint16 tempValue = 0;
uint8 data_arr[3]={0};

void receiveISR(void)
{
	uint8 receivedValue;
	
	/*Control Mode*/
	UART_INT_receive(&receivedValue);
	UART_transmit(receivedValue);
	switch(receivedValue)
	{
		case 'o':
		LED_ON(LED_PORT,BLUE_LED_PIN);
		LED_ON(LED_PORT,YELLOW_LED_PIN);
		break;
		
		default:
		LED_OFF(LED_PORT,BLUE_LED_PIN);
		LED_OFF(LED_PORT,YELLOW_LED_PIN);
		break;		
	}
}
void LM_ON(void)
{
	/*ADC READING*/
	ADC_autotrigger_readChannel(CH_1,ptr1);
	tempValue = ((*ptr1 * 5000UL)/1024)/10;
	data_arr[2] = tempValue;
	
	if(tempValue > 30)
	{
		/*BUZZER ON*/
		LED_ON(PORTC_ID,PIN6_ID);
	}
	else
	{
		/*BUZZER OFF*/
		LED_OFF(PORTC_ID,PIN6_ID);
	}
}

void DATA_SAVING(void)
{
	for(uint8 i=0; i<3; i++)
	{
		SPI_send(data_arr[i]);
		_delay_ms(10);
	}
}

int main(void)
{	
	uint8 flameSensorValue;
	uint8 gasSensorValue;
	uint8 duty=0;
	
	/*OCR0 PIN*/
	DIO_voidSetPinDirection(PORTB_ID,PIN3_ID,OUTPUT_PIN);
	
	/*GAS SENSOR PIN*/
	DIO_voidSetPinDirection(PORTC_ID,PIN7_ID,INPUT_PIN);
	DIO_voidSetPinValue(PORTC_ID,PIN7_ID,LOGIC_HIGH); /*activate pull up*/
	
	/*FLAME SENSOR PIN ON EXT INT0*/
	DIO_voidSetPinDirection(PORTD_ID,PIN2_ID,INPUT_PIN);
	DIO_voidSetPinValue(PORTD_ID,PIN2_ID,LOGIC_HIGH); /*activate pull up*/
	
	/*LM35 CHANNEL*/
	DIO_voidSetPinDirection(PORTA_ID,PIN1_ID,INPUT_PIN);
	DIO_voidSetPinValue(PORTA_ID,PIN1_ID,LOGIC_HIGH); /*activate pull up*/
	
	/*BUTTON PIN*/
	DIO_voidSetPinDirection(PORTB_ID,PIN2_ID,INPUT_PIN);
	DIO_voidSetPinValue(PORTB_ID,PIN2_ID,LOGIC_HIGH); /*activate pull up*/
	
	/*LED INITS*/
	LED_init(LED_PORT,RED_LED_PIN);
	LED_init(LED_PORT,GREEN_LED_PIN);
	LED_init(LED_PORT,BLUE_LED_PIN);
	LED_init(LED_PORT,YELLOW_LED_PIN);
	
	/*BUZZER INIT*/
	LED_init(PORTC_ID,PIN6_ID);
	
	
	/*ALL INITS*/
	ADC_autotrigger_init();
	LCD_init();
	TIMER0_PWM_init();
	UART_callback(receiveISR);
	UART_init(9600);
	SPI_init();
	
	/*motor:*/
	DcMotor_init();
	DcMotor_Rotate(STOP,0);
	
	
	/*LCD initial display*/
	LCD_moveCursor(0,0);
	LCD_displayString("FLAME:  ");
				
	LCD_moveCursor(1,0);
	LCD_displayString("GAS:  ");
	
	LCD_moveCursor(3,4);
	LCD_displayString("TEMP:   C");
	
	/*INTERRUPT INIT*/
	EXT_callback(EXT_0,LM_ON);
	EXT_init(EXT_0,LOW_LEVEL);
	
	EXT_callback(EXT_2,DATA_SAVING);
	EXT_init(EXT_2,FALLING);
	
	GIE_enable();
	
	while(1)
	{	
		/*FLAME SENSOR READING*/
		flameSensorValue = DIO_voidGetPinValue(PORTD_ID,PIN2_ID);
		data_arr[0] = flameSensorValue;
		if(flameSensorValue == 0)
		{	
			LED_ON(PORTC_ID,PIN6_ID);
			LED_OFF(LED_PORT,GREEN_LED_PIN);
			LED_ON(LED_PORT,RED_LED_PIN);
			
			LCD_moveCursor(0,8);
			LCD_displayString("DETECTED");
		}
		if(flameSensorValue == 1)
		{		
			LCD_moveCursor(0,8);
			LCD_displayString("NO FLAME");
		}
		
		/*GAS SENSOR READING*/
		gasSensorValue = DIO_voidGetPinValue(PORTC_ID,PIN7_ID);
		data_arr[1] = gasSensorValue;
		if(gasSensorValue == 0)
		{
			LCD_moveCursor(1,6);
			LCD_displayString("DETECTED");
			
			LED_ON(PORTC_ID,PIN6_ID);
			LED_OFF(LED_PORT,GREEN_LED_PIN);
			LED_ON(LED_PORT,RED_LED_PIN);
			
			for(duty = 0 ; duty<255; duty+=5)
			{
				DcMotor_Rotate(CW,duty); /*rotate motor*/
				_delay_ms(5);
			}
		}
		if(gasSensorValue == 1)
		{
			DcMotor_Rotate(STOP,0);
			LCD_moveCursor(1,6);
			LCD_displayString("NO GAS  ");
		}
		LCD_moveCursor(3,10);
		LCD_intgerToString(tempValue);
		
		if(flameSensorValue == 1 && gasSensorValue == 1)
		{
			LED_OFF(PORTC_ID,PIN6_ID);
			LED_ON(LED_PORT,GREEN_LED_PIN);
			LED_OFF(LED_PORT,RED_LED_PIN);
		}
	}
}

