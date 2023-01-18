/*
 * SPI_Config.h
 *
 *  Created on: Nov 20, 2022
 *      Author: mmont
 */

#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_


#define SPI_MOSI_PIN	DIO_PB5
#define SPI_MISO_PIN	DIO_PB6
#define SPI_SCK_PIN		DIO_PB7
#define SPI_SS_PIN		DIO_PB4


/* SPI_MODE
 * values = {
 * 		SPI_SLAVE_MODE
 *		SPI_MASTER_MODE
 * }
*/
#define SPI_MODE			SPI_MASTER_MODE


/* SPI_OPERATION_MODE
 * values = {
 * 		SPI_POLLING_MODE
 *		SPI_INTERRUPT_MODE
 * }
*/
#define SPI_OPERATION_MODE	SPI_POLLING_MODE


/* SPI_SPEED
 * values = {
 *  SPI_SPEED_FOSC_DEVIDE_BY_4
 *  SPI_SPEED_FOSC_DEVIDE_BY_16
 *  SPI_SPEED_FOSC_DEVIDE_BY_64
 * }SPI_SPEED_FOSC_DEVIDE_BY_128
*/
#define SPI_SPEED		 	SPI_SPEED_FOSC_DEVIDE_BY_128


/*
 * values = {
 *		SPI_DOUPLE_SPEED_DISABLE
 *		SPI_DOUPLE_SPEED_ENABLE
 * }
*/
#define SPI_DOUBLE_SPEED	SPI_DOUPLE_SPEED_DISABLE


/* SPI_DATA_ORDER
 * values = {
 * 		SPI_DATA_ORDER_LSB
 * 		SPI_DATA_ORDER_MSB
 * }
*/
#define SPI_DATA_ORDER		SPI_DATA_ORDER_LSB


/* SPI_CLK_POLARITY
 * values = {
 * 		 SPI_CPOL_LEADING_RISING
 *		 SPI_CPOL_LEADING_FALLING
 * }
*/
#define SPI_CLK_POLARITY	SPI_CPOL_LEADING_RISING


/* SPI_CLK_PHASE
 * values = {
 *		SPI_CPHA_LEADING_SAMPLE
 *		SPI_CPHA_LEADING_SETUP
 * }
*/
#define SPI_CLK_PHASE		SPI_CPHA_LEADING_SAMPLE


#endif /* SPI_CONFIG_H_ */
