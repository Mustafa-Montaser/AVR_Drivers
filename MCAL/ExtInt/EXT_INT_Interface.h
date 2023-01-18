/*
 * EXT_INT_Interface.h
 *
 *  Created on: Nov 17, 2022
 *      Author: mmont
 */



#ifndef EXT_INT_INTERFACE_H_
#define EXT_INT_INTERFACE_H_

#include "StdTypes.h"

void ExtInt_voidInit();
void ExtInt_voidDisableInt0();
void ExtInt_voidDisableInt1();
void ExtInt_voidDisableInt2();
void ExtInt_voidEnableInt0();
void ExtInt_voidEnableInt1();
void ExtInt_voidEnableInt2();
//void ExtInt_voidEnableExtInt(u8 Copy_u8IntNum, u8 Copy_u8SenseCtrl);
//void ExtInt_voidDisableInt(u8 Copy_u8IntNum);

void ExtInt_SetCallBack0(void (*ptr) (void));
void ExtInt_SetCallBack1(void (*ptr) (void));
void ExtInt_SetCallBack2(void (*ptr) (void));


/* EXT INT state */
#define EXT_INT_ENABLE		1
#define EXT_INT_DISABLE		0

/* Sense control */
#define EXT_INT_SENSE_CONTROL_LOW_LEVEL		0b00
#define EXT_INT_SENSE_CONTROL_ANY_CHANGE	0b01
#define EXT_INT_SENSE_CONTROL_FALLING_EDGE	0b10
#define EXT_INT_SENSE_CONTROL_RISING_EDGE	0b11



#endif /* EXT_INT_INTERFACE_H_ */
