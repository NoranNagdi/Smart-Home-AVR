/*
 * TIMER_private.h
 *
 * Created: 10/26/2023 11:50:20 PM
 *  Author: DELL
 */ 


#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_

#include "../Std_Types.h"

#define TIMSK *((volatile uint8*)(0x59))
#define TIFR  *((volatile uint8*)(0x58))

/*Timer 0 Registers*/
#define TCCR0 *((volatile uint8*)(0x53))
#define TCNT0 *((volatile uint8*)(0x52))
#define OCR0  *((volatile uint8*)(0x5C))

/*Timer 1 Registers*/
#define TCCR1A *((volatile uint8*)(0x4F))
#define TCCR1B *((volatile uint8*)(0x4B))
#define TCNT1H *((volatile uint8*)(0x4D))
#define TCNT1L *((volatile uint8*)(0x4C))
#define OCR1AH *((volatile uint8*)(0x4B))
#define OCR1AL *((volatile uint8*)(0x4A))
#define OCR1BH *((volatile uint8*)(0x49))
#define OCR1BL *((volatile uint8*)(0x48))
#define ICR1H  *((volatile uint8*)(0x47))
#define ICR1L  *((volatile uint8*)(0x46))

/*Timer 2 Registers*/
#define TCCR2 *((volatile uint8*)(0x45))
#define TCNT2 *((volatile uint8*)(0x44))
#define OCR2  *((volatile uint8*)(0x43))

/*TCCR0_bits*/
typedef enum{
	CS00,CS01,CS02,WGM01,COM00,COM01,WGM00,FOC0
}TCCR0_bits;

/*TIMSK_bits*/
typedef enum{
	TOIE0,OCIE0,TOIE1,OCIE1B,OCIE1A,TICIE1,TOIE2,OCIE2
}TIMSK_bits;

/*TIFR_bits*/
typedef enum{
	TOV0,OCF0,TOV1,OCF1B,OCF1A,ICF1,TOV2,OCF2
}TIFR_bits;

/*TCCR1A_bits*/
typedef enum{
	WGM10,WGM11,FOC1B,FOC1A,COM1B0,COM1B1,COM1A0,COM1A1
}TCCR1A_bits;

/*TCCR1B_bits*/
typedef enum{
	CS10,CS11,CS12,WGM12,WGM13,ICES11=6,ICNC1
}TCCR1B_bits;


/*TCCR2_bits*/
typedef enum{
	CS20,CS21,CS22,WGM21,COM20,COM21,WGM20,FOC2
}TCCR2_bits;


#endif /* TIMER_PRIVATE_H_ */