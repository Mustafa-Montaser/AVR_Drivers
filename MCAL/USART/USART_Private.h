/*
 * USART_Private.h
 *
 *  Created on: Nov 18, 2022
 *      Author: mmont
 */

#ifndef USART_PRIVATE_H_
#define USART_PRIVATE_H_

/* USART REGISTERS */
#define USART_UDR		*((volatile u8*)0x2C)
#define USART_UCSRA		*((volatile u8*)0x2B)
#define USART_UCSRB		*((volatile u8*)0x2A)
#define USART_UCSRC		*((volatile u8*)0x40)
#define USART_UBRRH		*((volatile u8*)0x40)
#define USART_UBRRL		*((volatile u8*)0x29)

/* USART [UCSRA] REGISTER BITS */
#define USART_UCSRA_RXC 		7
#define USART_UCSRA_TXC 		6
#define USART_UCSRA_UDRE 		5
#define USART_UCSRA_FE 			4
#define USART_UCSRA_DOR 		3
#define USART_UCSRA_PE 			2
#define USART_UCSRA_U2X 		1
#define USART_UCSRA_MPCM		0

/* USART [UCSRB] REGISTER BITS */
#define USART_UCSRB_RXCIE     7
#define USART_UCSRB_TXCIE     6
#define USART_UCSRB_UDRIE     5
#define USART_UCSRB_RXEN      4
#define USART_UCSRB_TXEN      3
#define USART_UCSRB_UCSZ2     2
#define USART_UCSRB_RXB8      1
#define USART_UCSRB_TXB8      0

/* USART [UCSRC] REGISTER BITS */
#define USART_UCSRC_URSEL     7
#define USART_UCSRC_UMSEL     6
#define USART_UCSRC_UPM1      5
#define USART_UCSRC_UPM0      4
#define USART_UCSRC_USBS      3
#define USART_UCSRC_UCSZ1     2
#define USART_UCSRC_UCSZ0     1
#define USART_UCSRC_UCPOL     0

/* USART [UBRRH] REGISTER BITS */
#define USART_UBRRH_URSEL	  15



#endif /* USART_PRIVATE_H_ */
