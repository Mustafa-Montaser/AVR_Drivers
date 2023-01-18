/*
 * USART_Program.c
 *
 *  Created on: Nov 18, 2022
 *      Author: mmont
 */

#include "StdTypes.h"
#include "BitMath.h"

#include "USART_Config.h"
#include "USART_Interface.h"
#include "USART_Private.h"

#include "GIE_Interface.h"

//#define F_CPU	16000000UL
//#include "util/delay.h"

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

void USART_voidInit() {

	u8 local_u8UCSRC = 0;

	/* Selecting UCSRC register */
	SET_BIT(local_u8UCSRC, USART_UCSRC_URSEL);

	/* Mode Selection [Asynch. or Synch.] */
	WRT_BIT(local_u8UCSRC, USART_UCSRC_UMSEL, USART_MODE);

	/* Parity Selection */
	WRT_2BITS(local_u8UCSRC, USART_UCSRC_UPM0, USART_PARITY);

	/* Stop Bit */
	WRT_BIT(local_u8UCSRC, USART_UCSRC_USBS, USART_STOP_BIT);

	/* Character Size */
	WRT_2BITS(local_u8UCSRC, USART_UCSRC_UCSZ0, USART_CHAR_SIZE);
	#if USART_CHAR_SIZE_9_BITS_STATE == USART_CHAR_SIZE_9_TRUE
		WRT_BIT(USART_UCSRB, USART_UCSRB_UCSZ2, 1);
	#elif USART_CHAR_SIZE_9_BITS_STATE == USART_CHAR_SIZE_9_FALSE
		WRT_BIT(USART_UCSRB, USART_UCSRB_UCSZ2, 0);
	#endif

	/* Writing value to UCSRC Register*/
	USART_UCSRC = local_u8UCSRC;

	/* Baud Rate */
//	u16 local_UBRR = (u16)(((u32)F_OSC / ((u32)16 * (u32)USART_BAUD_RATE)) - (u32)1);
//	USART_UBRRL = (u8)(local_UBRR);
//	CLR_BIT(local_u8UCSRC, USART_UCSRC_URSEL);
//	WRT_4BITS(USART_UBRRH, 0, (u8)(local_UBRR >> 8));
	#if USART_BAUD_RATE == 115200
		USART_UBRRL = 8;
	#elif USART_BAUD_RATE == 9600
		USART_UBRRL = 103;
	#endif
	CLR_BIT(local_u8UCSRC, USART_UCSRC_URSEL);
	USART_UBRRH = 0;

	#if USART_OPERATION_MODE == USART_INTERRUPT_MODE
		SET_BIT(USART_UCSRB, USART_UCSRB_RXCIE);
		SET_BIT(USART_UCSRB, USART_UCSRB_TXCIE);
		GIE_voidEnableGlobalINT();
	#elif USART_OPERATION_MODE == USART_POLLING_MODE
		CLR_BIT(USART_UCSRB, USART_UCSRB_RXCIE);
		CLR_BIT(USART_UCSRB, USART_UCSRB_TXCIE);
	#endif

	/* Receiver Enable */
	SET_BIT(USART_UCSRB, USART_UCSRB_RXEN);

	/* Transmitter Enable */
	SET_BIT(USART_UCSRB, USART_UCSRB_TXEN);
}



//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

void USART_voidTX(u8 copy_u8DataToTransmit) {

	/* Waiting for UDR register to be empty */
	while(GET_BIT(USART_UCSRA, USART_UCSRA_UDRE) == 0);

	/* Sending the data */
	USART_UDR = copy_u8DataToTransmit;

	#if USART_OPERATION_MODE == USART_POLLING_MODE
		/* Wait to make sure data is sent */
		while(GET_BIT(USART_UCSRA, USART_UCSRA_TXC) == 0);
	#endif
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

void USART_voidStringTX(u8 *copy_u8PtrDataToTransmit) {
	while(*copy_u8PtrDataToTransmit != '\0') {
		/* Waiting for UDR register to be empty */
		while(GET_BIT(USART_UCSRA, USART_UCSRA_UDRE) == 0);
		/* Sending the data */
		USART_UDR = *copy_u8PtrDataToTransmit;
		#if USART_OPERATION_MODE == USART_POLLING_MODE
			/* Wait to make sure data is sent */
			while(GET_BIT(USART_UCSRA, USART_UCSRA_TXC) == 0);
		#endif
		copy_u8PtrDataToTransmit++;
	}
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

u8 USART_u8RX() {
	#if USART_OPERATION_MODE == USART_POLLING_MODE
		/* waiting till data is received */
		while(GET_BIT(USART_UCSRA, USART_UCSRA_RXC) == 0);
	#endif

	/* Getting Received Data */
	return USART_UDR;
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

void USART_voidStringRX(u8 *copy_u8PtrReceivedData) {
	u8 local_u8ReceivedData;
	while(1) {
		#if USART_OPERATION_MODE == USART_POLLING_MODE
			/* waiting till data is received */
			while(GET_BIT(USART_UCSRA, USART_UCSRA_RXC) == 0);
		#endif

		/* Getting Received Data */
		local_u8ReceivedData = USART_UDR;
		if(local_u8ReceivedData == '\0') {
			break;
		} else {
			*copy_u8PtrReceivedData = local_u8ReceivedData;
			copy_u8PtrReceivedData++;
		}
	}
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

void USART_voidDisable()  {
	/* Receiver Enable */
	CLR_BIT(USART_UCSRB, USART_UCSRB_RXEN);

	/* Transmitter Enable */
	CLR_BIT(USART_UCSRB, USART_UCSRB_TXEN);
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

#if USART_OPERATION_MODE == USART_INTERRUPT_MODE

	/* Pointer to callback function */
	void (*USARTCallBackRX) (void) = NULL;
	void (*USARTCallBackTX) (void) = NULL;

	/* RX Interrupt */
	void USART_voidSetCallBackRX(void (*ptr) (void)) { USARTCallBackRX = ptr; }
	void  __vector_13 (void) __attribute__((signal));
	void __vector_13(void) { USARTCallBackRX(); }

	/* RX Interrupt */
	void USART_voidSetCallBackTX(void (*ptr) (void)) { USARTCallBackTX = ptr; }
	void  __vector_15 (void) __attribute__((signal));
	void __vector_15(void) { USARTCallBackTX(); }


#endif




















