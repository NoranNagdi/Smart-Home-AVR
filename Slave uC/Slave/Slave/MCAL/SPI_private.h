/*
 * SPI_private.h
 *
 * Created: 10/31/2023 2:37:30 PM
 *  Author: DELL
 */ 


#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_


#define SPDR    *((volatile uint8*)(0x2F))
#define SPSR    *((volatile uint8*)(0x2E))
#define SPCR    *((volatile uint8*)(0x2D))

/*SPCR_bits*/
typedef enum{
	SPR0,SPR1,CPHA,CPOL,MSTR,DORD,SPE,SPIE
}SPCR_bits;


/*SPSR_bits*/
typedef enum{
	SPI2X,WCOL=6,SPIF
}SPSR_bits;




#endif /* SPI_PRIVATE_H_ */