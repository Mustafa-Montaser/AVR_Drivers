/*
 * SPI_Program.c
 *
 *  Created on: Nov 20, 2022
 *      Author: mmont
 */

#include "StdTypes.h"
#include "BitMath.h"

#include "SPI_Config.h"
#include "SPI_Interface.h"
#include "SPI_Private.h"

#include "DIO_Types.h"
#include "DIO_Interface.h"

//#define F_CPU	16000000UL
//#include <util/delay.h>

//////////////////////////
/*//// Master Mode	////*/
//////////////////////////

void SPI_voidInit() {
	/* PINs Configuration */
	#if SPI_MODE == SPI_MASTER_MODE
		DIO_voidSetPinMode(SPI_MISO_PIN, DIO_PIN_INPUT);
		DIO_voidSetPinMode(SPI_MOSI_PIN, DIO_PIN_OUTPUT);
		DIO_voidSetPinMode(SPI_SCK_PIN, DIO_PIN_OUTPUT);
		DIO_voidSetPinMode(SPI_SS_PIN, DIO_PIN_OUTPUT);
	#elif SPI_MODE == SPI_SLAVE_MODE
		DIO_voidSetPinMode(SPI_MISO_PIN, DIO_PIN_OUTPUT);
		DIO_voidSetPinMode(SPI_MOSI_PIN, DIO_PIN_INPUT);
		DIO_voidSetPinMode(SPI_SCK_PIN, DIO_PIN_INPUT);
		DIO_voidSetPinMode(SPI_SS_PIN, DIO_PIN_INPUT);
	#endif

	/* Single slave Selection */
	#if SPI_MODE == SPI_MASTER_MODE
		DIO_voidWritePinValue(SPI_SS_PIN, DIO_PIN_LOW);
	#endif

	/* Interrupt Setting */
	WRT_BIT(SPI_SPCR, SPI_SPCR_SPIE, SPI_OPERATION_MODE);

	/*	Data Order	*/
	WRT_BIT(SPI_SPCR, SPI_SPCR_DORD, SPI_DATA_ORDER);

	/*	Master/Slave mode */
	WRT_BIT(SPI_SPCR, SPI_SPCR_MSTR, SPI_MODE);

	/*	Clock Polarity	*/
	WRT_BIT(SPI_SPCR, SPI_SPCR_CPOL, SPI_CLK_POLARITY);

	/*	Clock Phase	*/
	WRT_BIT(SPI_SPCR, SPI_SPCR_CPHA, SPI_CLK_PHASE);

	/*	SPI Speed */
	WRT_2BITS(SPI_SPCR, SPI_SPCR_SPR0, SPI_SPEED);
	WRT_BIT(SPI_SPSR, SPI_SPSR_SPI2X, SPI_DOUBLE_SPEED);

//	SPI_SPDR = 'A';

	/*	SPI Enable	*/
	SET_BIT(SPI_SPCR, SPI_SPCR_SPE);
}


u8 SPI_u8Transeive(u8 copy_u8DataToTransmit) {
	u8 local_u8ReceivedData = 0;
	/*	writing data	*/
	SPI_SPDR = copy_u8DataToTransmit;
	#if SPI_OPERATION_MODE == SPI_POLLING_MODE
		/* Waiting till data is transmitted */
		while(GET_BIT(SPI_SPSR, SPI_SPSR_SPIF) == 0);
		/* Read SPDR Register if needed or to clear the flag */
		local_u8ReceivedData = SPI_SPDR;
	#endif
	return local_u8ReceivedData;
}

u8 SPI_u8Read() {
	#if SPI_OPERATION_MODE == SPI_POLLING_MODE
		while(GET_BIT(SPI_SPSR, SPI_SPSR_SPIF) == 0);
	#endif
	return SPI_SPDR;
}


#if SPI_OPERATION_MODE == SPI_INTERRUPT_MODE
	void (*SPICallBackTranseive) (void) = NULL;
	void SPI_voidCallbackTranseive(void (*ptr) (void)) { SPICallBackTranseive = ptr; }
	void  __vector_12 (void) __attribute__((signal));
	void __vector_12(void) { SPICallBackTranseive(); }
#endif

