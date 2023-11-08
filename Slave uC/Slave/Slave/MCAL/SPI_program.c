/*
 * SPI_program.c
 *
 * Created: 10/31/2023 2:37:12 PM
 *  Author: DELL
 */ 

#include "../MCAL/SPI_interface.h"
#include "../MCAL/SPI_cfg.h"
#include "../MCAL/SPI_private.h"
#include "../MCAL/DIO_interface.h"
#include "../Common_Macros.h"
#include "../Std_Types.h"

void SPI_init(void)
{
	/******** Configure SPI Master Pins *********
	 * SS(PB4)   --> Output
	 * MOSI(PB5) --> Output 
	 * MISO(PB6) --> Input
	 * SCK(PB7) --> Output	
	 ********************************************/
	DIO_voidSetPinDirection(PORTB_ID,PIN4_ID,INPUT_PIN);
	DIO_voidSetPinDirection(PORTB_ID,PIN5_ID,INPUT_PIN);
	DIO_voidSetPinDirection(PORTB_ID,PIN6_ID,OUTPUT_PIN);
	DIO_voidSetPinDirection(PORTB_ID,PIN7_ID,INPUT_PIN);
	
	/*set data order to LSB first*/
	SET_BIT(SPCR,DORD);
	
	/*Set as master*/
	CLEAR_BIT(SPCR,MSTR);
	
	/*Clear clk POL and PHASE*/
	CLEAR_BIT(SPCR,CPOL);
	CLEAR_BIT(SPCR,CPHA);
	
	/*set prescaler*/
	SET_BIT(SPCR,SPR0);
	
#if(SPI_SPEED == NORMAL_SPEED)
	CLEAR_BIT(SPSR,SPI2X);
#elif(SPI_SPEED == DOUBLE_SPEED)
	SET_BIT(SPSR,SPI2X);
#endif

	/*enable SPI*/
	SET_BIT(SPCR,SPE);	
}

void SPI_send(uint8 value)
{
	SPDR = value;
	//while(BIT_IS_CLEAR(SPSR,SPIF));
}

void SPI_receive(uint8* value)
{
	while(BIT_IS_CLEAR(SPSR,SPIF));
	*value = SPDR;
}
