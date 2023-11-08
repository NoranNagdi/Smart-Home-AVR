/*
 * DIO_private.h
 *
 * Created: 10/20/2023 10:59:21 AM
 *  Author: DELL
 */ 


#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_
 
/*PORTA Registers Definitions*/

#define PORTA *((volatile uint8*)(0x3B))
#define DDRA  *((volatile uint8*)(0x3A))
#define PINA  *((volatile uint8*)(0x39))

/*PORTB Registers Definitions*/

#define PORTB *((volatile uint8*)(0x38))
#define DDRB  *((volatile uint8*)(0x37))
#define PINB  *((volatile uint8*)(0x36))

/*PORTC Registers Definitions*/

#define PORTC *((volatile uint8*)(0x35))
#define DDRC  *((volatile uint8*)(0x34))
#define PINC  *((volatile uint8*)(0x33))

/*PORTD Registers Definitions*/

#define PORTD *((volatile uint8*)(0x32))
#define DDRD  *((volatile uint8*)(0x31))
#define PIND  *((volatile uint8*)(0x30))



#endif /* DIO_PRIVATE_H_ */