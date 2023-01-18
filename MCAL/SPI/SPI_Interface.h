/*
 * SPI_Interface.h
 *
 *  Created on: Nov 20, 2022
 *      Author: mmont
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_


#define SPI_DATA_ORDER_LSB				1
#define SPI_DATA_ORDER_MSB				0

#define SPI_SLAVE_MODE					0
#define SPI_MASTER_MODE					1


#define SPI_CPOL_LEADING_RISING			0
#define SPI_CPOL_LEADING_FALLING		1

#define SPI_CPHA_LEADING_SAMPLE		 	0
#define SPI_CPHA_LEADING_SETUP			1

#define SPI_POLLING_MODE				0
#define SPI_INTERRUPT_MODE				1

#define SPI_SPEED_FOSC_DEVIDE_BY_4		0b00
#define SPI_SPEED_FOSC_DEVIDE_BY_16		0b01
#define SPI_SPEED_FOSC_DEVIDE_BY_64		0b10
#define SPI_SPEED_FOSC_DEVIDE_BY_128	0b11

#define SPI_DOUPLE_SPEED_DISABLE		0
#define SPI_DOUPLE_SPEED_ENABLE			1


void SPI_voidInit();
u8 SPI_u8Transeive(u8 copy_u8DataToTransmit);
u8 SPI_u8Read();

/* Interrupt usage */
void SPI_voidCallbackTranseive(void (*ptr) (void));




#endif /* SPI_INTERFACE_H_ */
