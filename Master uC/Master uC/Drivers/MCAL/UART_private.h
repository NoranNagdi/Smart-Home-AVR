/*
 * UART_private.h
 *
 * Created: 10/30/2023 10:42:37 AM
 *  Author: DELL
 */ 


#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_


#include "../Std_Types.h"

#define UDR    *((volatile uint8*)(0x2C))
#define UCSRA  *((volatile uint8*)(0x2B))
#define UCSRB  *((volatile uint8*)(0x2A))
#define UCSRC  *((volatile uint8*)(0x40))
#define UBRRH  *((volatile uint8*)(0x40))
#define UBRRL  *((volatile uint8*)(0x29))


/*UCSRA_bits*/
typedef enum{
	MPCM,U2X,PE,DOR,FE,UDRE,TXC,RXC
}UCSRA_bits;

/*UCSRB_bits*/
typedef enum{
	TXB8,RXB8,UCSZ2,TXEN,RXEN,UDRIE,TXCIE,RXCIE
}UCSRB_bits;

/*UCSRC_bits*/
typedef enum{
	UCPOL,UCSZ0,UCSZ1,USBS,UPM0,UPM1,UMSEL,URSEL
}UCSRC_bits;


#endif /* UART_PRIVATE_H_ */