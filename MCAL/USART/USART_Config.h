/*
 * USART_Config.h
 *
 *  Created on: Nov 18, 2022
 *      Author: mmont
 */

#ifndef USART_CONFIG_H_
#define USART_CONFIG_H_


/* USART_MODE
 *	values = {
 *		USART_ASYNCH_MODE
 *		USART_SYNCH_MODE
 *	}
*/
#define USART_MODE						USART_ASYNCH_MODE


/* USART_PARITY
 * values = {
 * 		USART_PARITY_DISABLED
 * 		USART_PARITY_EVEN
 *		USART_PARITY_ODD
 * }
*/
#define USART_PARITY					USART_PARITY_DISABLED


/* USART_STOP_BIT
 * values = {
 * 		USART_1_STOP_BIT
 * 		USART_2_STOP_BIT
 * }
*/
#define USART_STOP_BIT					USART_1_STOP_BIT


/* USART_CHAR_SIZE
 * values = {
 * 		USART_CHAR_SIZE_5_BITS
 *		USART_CHAR_SIZE_6_BITS
 *	 	USART_CHAR_SIZE_7_BITS
 *		USART_CHAR_SIZE_8_BITS
 *		USART_CHAR_SIZE_9_BITS
 * }
*/
#define USART_CHAR_SIZE					USART_CHAR_SIZE_8_BITS


/* USART_CHAR_SIZE_9_BITS_STATE
 * values = {
 * 		USART_CHAR_SIZE_9_TRUE
 *		USART_CHAR_SIZE_9_FALSE
 * }
*/
#define USART_CHAR_SIZE_9_BITS_STATE	USART_CHAR_SIZE_9_FALSE


/* USART_OPERATION_MODE
 * values = {
 * 		USART_INTERRUPT_MODE
 *		USART_POLLING_MODE
 * }
*/
#define USART_OPERATION_MODE			USART_INTERRUPT_MODE

#define USART_BAUD_RATE					115200

#define F_OSC							16000000


#endif /* USART_CONFIG_H_ */
