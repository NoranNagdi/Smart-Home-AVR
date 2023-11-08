/*
 * GIE_program.c
 *
 * Created: 10/22/2023 12:17:37 PM
 *  Author: DELL
 */ 

#include "../MCAL/GIE_private.h"
#include "../MCAL/GIE_interface.h"
#include "../Common_Macros.h"

void GIE_enable(void)
{
	SET_BIT(SREG,I_BIT);
}

void GIE_disable(void)
{
	CLEAR_BIT(SREG,I_BIT);
}