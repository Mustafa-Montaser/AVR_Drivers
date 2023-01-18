/*
 * SPI_Private.h
 *
 *  Created on: Nov 20, 2022
 *      Author: mmont
 */

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_


//////////////////////////////////////////////////////
/*		I2C Registers		*/
#define SPI_SPCR	*((volatile u8*)0x2D)
#define SPI_SPSR	*((volatile u8*)0x2E)
#define SPI_SPDR	*((volatile u8*)0x2F)

//////////////////////////////////////////////////////
/*		SPCR Register Bits		*/
#define SPI_SPCR_SPIE 		7
#define SPI_SPCR_SPE        6
#define SPI_SPCR_DORD       5
#define SPI_SPCR_MSTR       4
#define SPI_SPCR_CPOL       3
#define SPI_SPCR_CPHA       2
#define SPI_SPCR_SPR1       1
#define SPI_SPCR_SPR0       0

//////////////////////////////////////////////////////
/*		SPSR Register Bits		*/
#define SPI_SPSR_SPIF 		7
#define SPI_SPSR_WCOL 		6
#define SPI_SPSR_SPI2X		0

//////////////////////////////////////////////////////
/*		SPDR Register Bits		*/
//#define SPI_SPDR_MSB 		7
//#define SPI_SPDR_LSB		0



#endif /* SPI_PRIVATE_H_ */
