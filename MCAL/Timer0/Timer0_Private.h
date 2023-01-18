/*
 * Timer0_Private.h
 *
 * Created: 12/6/2022 4:14:15 PM
 *  Author: mmont
 */ 


#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_

//////////////////////////////////////////////////////////////////////////////////

#define TIMER0_TCCR0			*((volatile u8*)0x53)

#define TIMER0_TCCR0_CS00		0
#define TIMER0_TCCR0_CS01		1
#define TIMER0_TCCR0_CS02		2
#define TIMER0_TCCR0_WGM01		3
#define TIMER0_TCCR0_COM00		4
#define TIMER0_TCCR0_COM01		5
#define TIMER0_TCCR0_WGM00		6
#define TIMER0_TCCR0_FOC0		7

//////////////////////////////////////////////////////////////////////////////////

#define TIMER0_TCNT0			*((volatile u8*)0x52)

//////////////////////////////////////////////////////////////////////////////////

#define TIMER0_OCR0				*((volatile u8*)0x5C)

//////////////////////////////////////////////////////////////////////////////////

#define TIMER0_TIMSK			*((volatile u8*)0x59)

#define TIMER0_TIMSK_TOIE0		0
#define TIMER0_TIMSK_OCIE0		1

//////////////////////////////////////////////////////////////////////////////////

#define TIMER0_TIFR				*((volatile u8*)0x58)

#define TIMER0_TIFR_TOV0		0
#define TIMER0_TIFR_OCF0		1

//////////////////////////////////////////////////////////////////////////////////

#define TIMER0_FAST_PWM_PIN			DIO_PB3

#endif /* TIMER0_PRIVATE_H_ */