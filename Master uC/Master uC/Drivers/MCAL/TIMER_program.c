/*
 * TIMER_program.c
 *
 * Created: 10/26/2023 11:49:32 PM
 *  Author: DELL
 */ 
#include "../MCAL/TIMER_interface.h"
#include "../MCAL/TIMER_cfg.h"
#include "../MCAL/TIMER_private.h"
#include "../Common_Macros.h"

#include "../HAL/LED_interface.h"


void (*TIMER0_OVF_ptr)(void);
void (*TIMER0_CMP_ptr)(void);

void TIMER0_init()
{
#if(TIMER_MODE == NORMAL_MODE)
{
		/*Set Normal mode*/
		CLEAR_BIT(TCCR0,WGM00);
		CLEAR_BIT(TCCR0,WGM01);
		
		/*Enable timer overflow interrupt*/
		SET_BIT(TIMSK,TOIE0);
}
#elif(TIMER_MODE == CTC_MODE)
{
		/*Set CTC mode*/
		CLEAR_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
		
		/*Set OCR0*/
		OCR0 = 250;
		
		/*Enable timer compare interrupt*/
		SET_BIT(TIMSK,OCIE0);
}
#elif(TIMER_MODE == FAST_PWM_MODE)
{
	/*Set FAST PWM mode*/
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	
	/*Set INVERTING or Not*/
	CLEAR_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
	
}
#endif
	
	/*Set prescaler*/
	CLEAR_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	CLEAR_BIT(TCCR0,CS02);
	
	/*Set TCNT value*/
	TCNT0 = 0;
	
}

void TIMER0_PWM_init(void)
{
	/*Set FAST PWM mode*/
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
		
	/*Set non-INVERTING*/
	CLEAR_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);

	/*Set prescaler*/
	CLEAR_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	CLEAR_BIT(TCCR0,CS02);
	
	/*Set TCNT value*/
	TCNT0 = 0;
	
}
void set_TCNT(uint8 value)
{
	TCNT0 = value;
}

void set_OCR(uint8 value)
{
	OCR0 = value;
}
void TIMER0_callback(uint8 mode, void (*ptr)(void))
{
	switch(mode)
	{
		case 0:
		TIMER0_OVF_ptr = ptr;
		break;
		case 2:
		TIMER0_CMP_ptr = ptr;
		break;
	}
}

void TIMER0_deinit(void)
{
	/*Stop Timer*/
	CLEAR_BIT(TCCR0,CS00);
	CLEAR_BIT(TCCR0,CS01);
	CLEAR_BIT(TCCR0,CS02);
}
/*Timer 0 overflow ISR*/
void __vector_11()__attribute__((signal));
void __vector_11()
{
	TIMER0_OVF_ptr();
}

/*Timer 0 compare ISR*/
void __vector_10()__attribute__((signal));
void __vector_10()
{
	TIMER0_CMP_ptr();
}

void delay(uint8 delayUnit,uint32 delayValue)
{
	uint8 Tovf = 128; /*T overflow in us*/
	
	switch(delayUnit)
	{
		case 0:
		if(delayValue<0.5){}
		if(delayValue<Tovf)
		{
			TCNT0 = (254*delayValue)%256;
			while(BIT_IS_CLEAR(TIFR,TOV0));
			SET_BIT(TIFR,TOV0);
		}
		if(delayValue>=Tovf)
		{
			for(int i=0; i<(delayValue)%128; i++)
			{
				while(BIT_IS_CLEAR(TIFR,TOV0));
				SET_BIT(TIFR,TOV0);
			}
		}
		break;
		case 1:
		for(int i=0; i<=delayValue*8; i++)
		{
			while(BIT_IS_CLEAR(TIFR,TOV0));
			SET_BIT(TIFR,TOV0);
		}
		break;
		case 2:
		for(int i=0; i<= delayValue*7812; i++)
		{
			while(BIT_IS_CLEAR(TIFR,TOV0));
			SET_BIT(TIFR,TOV0);
		}
		break;
	}
}