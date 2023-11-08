// /*
//  * UART_program.c
//  *
//  * Created: 10/30/2023 10:42:19 AM
//  *  Author: DELL
//  */ 
#define F_CPU 16000000UL
#include "../MCAL/UART_interface.h"
#include "../MCAL/UART_cfg.h"
#include "../MCAL/UART_private.h"
#include "../MCAL/DIO_interface.h"
#include "../Common_Macros.h"
#include "../Std_Types.h"


void UART_init(uint16 baudRate)
{
	/*configure baud rate*/
	uint16 ubrr_value = 0;
	ubrr_value = (uint16)(((16000000UL / (baudRate * 16))) - 1);
	UBRRL = 103;
	//UBRRH = (uint8)(ubrr_value>>8);
	
	DIO_voidSetPinDirection(PORTD_ID,PIN1_ID,OUTPUT_PIN);
	DIO_voidSetPinDirection(PORTD_ID,PIN0_ID,INPUT_PIN);
	
	CLEAR_BIT(UCSRA,U2X);
	
	/*enable receiver and transmitter*/
	SET_BIT(UCSRB,RXEN);
	SET_BIT(UCSRB,TXEN);
	
	/*configure 8-bit data*/
	CLEAR_BIT(UCSRB,UCSZ2);
	
	/*use UCSRC*/
	UCSRC = 0x86;
	
	UCSRA = 0x00;
	
	/*enable receive interrupt*/
	SET_BIT(UCSRB,RXCIE);
	
}

void UART_receive(uint8* value)
{
	while(!GET_BIT(UCSRA,RXC)){}
	*value = UDR;
	SET_BIT(UCSRA,RXC);
}

void UART_transmit(uint8 value)
{
	while(!GET_BIT(UCSRA,UDRE)){}
	UDR = value;
	SET_BIT(UCSRA,UDRE);
}

void UART_INT_receive(uint8* value)
{
	*value = UDR;
}

void (*UART_ptr)(void);


void UART_callback(void (*ptr)(void))
{
	UART_ptr = ptr;
}

void __vector_13()__attribute__((signal));
void __vector_13()
{
	UART_ptr();
}

