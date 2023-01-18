/*
 * USART_Interface.h
 *
 *  Created on: Nov 18, 2022
 *      Author: mmont
 */


#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

/*		MACROS		*/

#define USART_ASYNCH_MODE					0
#define USART_SYNCH_MODE						1

#define USART_PARITY_DISABLED				0b00
#define USART_PARITY_EVEN						0b10
#define USART_PARITY_ODD						0b11

#define USART_1_STOP_BIT						0
#define USART_2_STOP_BIT						1

#define USART_CHAR_SIZE_5_BITS			0b00
#define USART_CHAR_SIZE_6_BITS			0b01
#define USART_CHAR_SIZE_7_BITS			0b10
#define USART_CHAR_SIZE_8_BITS			0b11
#define USART_CHAR_SIZE_9_BITS			0b11

#define USART_CHAR_SIZE_9_TRUE			1
#define USART_CHAR_SIZE_9_FALSE		0

#define USART_INTERRUPT_MODE				0
#define USART_POLLING_MODE					1


/*			APIs			*/

void USART_voidInit();
void USART_voidTX(u8 copy_u8DataToTransmit);
void USART_voidStringTX(u8 *copy_u8PtrDataToTransmit);
u8 	 USART_u8RX();
void USART_voidStringRX(u8 *copy_u8PtrReceivedData);
void USART_voidDisable();

/* For Interrupt */
void USART_voidSetCallBackRX(void (*ptr) (void));
void USART_voidSetCallBackTX(void (*ptr) (void));

#endif /* USART_INTERFACE_H_ */
