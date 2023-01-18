/*
 * EXT_INT_Program.c
 *
 *  Created on: Nov 17, 2022
 *      Author: mmont
 */

#include "StdTypes.h"
#include "BitMath.h"

#include "DIO_Types.h"
#include "DIO_Interface.h"

#include "GIE_Interface.h"
#include "GIE_Private.h"

#include "EXT_INT_Interface.h"
#include "EXT_INT_Private.h"
#include "EXT_INT_Config.h"

#include <avr/interrupt.h>


/* Pointer to callback function */
void (*callBack0) (void) = NULL;
void (*callBack1) (void) = NULL;
void (*callBack2) (void) = NULL;


/* EXT0 Interrupt callback function */
void ExtInt_SetCallBack0(void (*ptr) (void)) { callBack0 = ptr; }
ISR(INT0_vect) { callBack0(); }	
	
//void  __vector_1 (void) __attribute__((signal));
//void __vector_1(void) { callBack0(); }



/* EXT1 Interrupt callback function */
void ExtInt_SetCallBack1(void (*ptr) (void)) { callBack1 = ptr; }
ISR(INT1_vect) { callBack1(); }
	
//void  __vector_2 (void) __attribute__((signal));
//void __vector_2(void) { callBack1(); }

	
	
/* EXT2 Interrupt callback function */
void ExtInt_SetCallBack2(void (*ptr) (void)) { callBack2 = ptr; }
ISR(INT2_vect) { callBack2(); }
	
//void  __vector_3 (void) __attribute__((signal));
//void __vector_3(void) { callBack2(); }

	
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

void ExtInt_voidInit() {
	#if EXT_INT0_STATE == EXT_INT_ENABLE
		DIO_voidSetPinMode(EXT_INT0_PIN, DIO_PIN_INPUT);
		DIO_voidWritePinValue(EXT_INT0_PIN, DIO_PIN_HIGH);
		WRT_2BITS(EXTINT_MCUCR, EXTINT_MCUCR_ISC00, EXT_INT0_SENSE_CTRL); /*sense ctrl setting*/
		SET_BIT(EXTINT_GICR, EXTINT_GICR_INT0); /*enable Int0*/
	#endif
	
	#if EXT_INT1_STATE == EXT_INT_ENABLE
		DIO_voidSetPinMode(EXT_INT1_PIN, DIO_PIN_INPUT);
		DIO_voidWritePinValue(EXT_INT1_PIN, DIO_PIN_HIGH);
		WRT_2BITS(EXTINT_MCUCR, EXTINT_MCUCR_ISC10, EXT_INT1_SENSE_CTRL); /*sense ctrl setting*/
		SET_BIT(EXTINT_GICR, EXTINT_GICR_INT1); /*enable Int1*/
	#endif
	
	#if EXT_INT2_STATE == EXT_INT_ENABLE
		DIO_voidSetPinMode(EXT_INT2_PIN, DIO_PIN_INPUT);
		DIO_voidWritePinValue(EXT_INT2_PIN, DIO_PIN_HIGH);
		switch(EXT_INT2_SENSE_CTRL) { /*sense ctrl setting*/
			case EXT_INT_SENSE_CONTROL_FALLING_EDGE: 
				CLR_BIT(EXTINT_MCUCSR, EXTINT_MCUCSR_ISC2); 
				break;
			case EXT_INT_SENSE_CONTROL_RISING_EDGE:
				SET_BIT(EXTINT_MCUCSR, EXTINT_MCUCSR_ISC2);
				break;
			default: break;			
		}
		SET_BIT(EXTINT_GICR, EXTINT_GICR_INT2); /*enable Int2*/
	#endif
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

void ExtInt_voidDisableInt0() {
	CLR_BIT(EXTINT_GICR, EXTINT_GICR_INT0);
}
void ExtInt_voidDisableInt1() {
	CLR_BIT(EXTINT_GICR, EXTINT_GICR_INT1);
}
void ExtInt_voidDisableInt2() {
	CLR_BIT(EXTINT_GICR, EXTINT_GICR_INT2);
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

void ExtInt_voidEnableInt0() {
	SET_BIT(EXTINT_GICR, EXTINT_GICR_INT0);
}
void ExtInt_voidEnableInt1() {
	SET_BIT(EXTINT_GICR, EXTINT_GICR_INT1);
}
void ExtInt_voidEnableInt2() {
	SET_BIT(EXTINT_GICR, EXTINT_GICR_INT2);
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////






//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//static void EXT_voidSenseCtrlEXT0(u8 Copy_u8SenseCtrl) {
//switch(Copy_u8SenseCtrl) {
//case EXT_INT_SENSE_CONTROL_LOW_LEVEL:
//WRT_2BITS(EXTINT_MCUCR, EXTINT_MCUCR_ISC00, EXT_INT_SENSE_CONTROL_LOW_LEVEL);
//break;
//case EXT_INT_SENSE_CONTROL_ANY_CHANGE:
//WRT_2BITS(EXTINT_MCUCR, EXTINT_MCUCR_ISC00, EXT_INT_SENSE_CONTROL_ANY_CHANGE);
//break;
//case EXT_INT_SENSE_CONTROL_FALLING_EDGE:
//WRT_2BITS(EXTINT_MCUCR, EXTINT_MCUCR_ISC00, EXT_INT_SENSE_CONTROL_FALLING_EDGE);
//break;
//case EXT_INT_SENSE_CONTROL_RISING_EDGE:
//WRT_2BITS(EXTINT_MCUCR, EXTINT_MCUCR_ISC00, EXT_INT_SENSE_CONTROL_RISING_EDGE);
//break;
//default: break;
//}
//}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//static void EXT_voidSenseCtrlEXT1(u8 Copy_u8SenseCtrl) {
//switch(Copy_u8SenseCtrl) {
//case EXT_INT_SENSE_CONTROL_LOW_LEVEL:
//WRT_2BITS(EXTINT_MCUCR, EXTINT_MCUCR_ISC10, EXT_INT_SENSE_CONTROL_LOW_LEVEL);
//break;
//case EXT_INT_SENSE_CONTROL_ANY_CHANGE:
//WRT_2BITS(EXTINT_MCUCR, EXTINT_MCUCR_ISC10, EXT_INT_SENSE_CONTROL_ANY_CHANGE);
//break;
//case EXT_INT_SENSE_CONTROL_FALLING_EDGE:
//WRT_2BITS(EXTINT_MCUCR, EXTINT_MCUCR_ISC10, EXT_INT_SENSE_CONTROL_FALLING_EDGE);
//break;
//case EXT_INT_SENSE_CONTROL_RISING_EDGE:
//WRT_2BITS(EXTINT_MCUCR, EXTINT_MCUCR_ISC10, EXT_INT_SENSE_CONTROL_RISING_EDGE);
//break;
//default: break;
//}
//}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//static void EXT_voidSenseCtrlEXT2(u8 Copy_u8SenseCtrl) {
//switch(Copy_u8SenseCtrl) {
//case EXT_INT_SENSE_CONTROL_FALLING_EDGE:
//CLR_BIT(EXTINT_MCUCSR, EXTINT_MCUCSR_ISC2);
//break;
//case EXT_INT_SENSE_CONTROL_RISING_EDGE:
//SET_BIT(EXTINT_MCUCSR, EXTINT_MCUCSR_ISC2);
//break;
//default: break;
//}
//}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//void ExtInt_voidEnableExtInt(u8 Copy_u8IntNum, u8 Copy_u8SenseCtrl) {
//switch(Copy_u8IntNum) {
//case EXT_INT0:
//DIO_voidSetPinMode(EXT_INT0_PIN, DIO_PIN_INPUT);
//DIO_voidWritePinValue(EXT_INT0_PIN, DIO_PIN_HIGH);
//EXT_voidSenseCtrlEXT0(Copy_u8SenseCtrl);
//SET_BIT(EXTINT_GICR, EXTINT_GICR_INT0);
//break;
//case EXT_INT1:
//DIO_voidSetPinMode(EXT_INT1_PIN, DIO_PIN_INPUT);
//DIO_voidWritePinValue(EXT_INT1_PIN, DIO_PIN_HIGH);
//EXT_voidSenseCtrlEXT1(Copy_u8SenseCtrl);
//SET_BIT(EXTINT_GICR, EXTINT_GICR_INT1);
//break;
//case EXT_INT2:
//DIO_voidSetPinMode(EXT_INT2_PIN, DIO_PIN_INPUT);
//DIO_voidWritePinValue(EXT_INT2_PIN, DIO_PIN_HIGH);
//EXT_voidSenseCtrlEXT2(Copy_u8SenseCtrl);
//SET_BIT(EXTINT_GICR, EXTINT_GICR_INT2);
//break;
//default: break;
//}
//}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//void EXT_voidDisableInt(u8 Copy_u8IntNum) {
//switch(Copy_u8IntNum) {
//case EXT_INT0: CLR_BIT(EXTINT_GICR, EXTINT_GICR_INT0); break;
//case EXT_INT1: CLR_BIT(EXTINT_GICR, EXTINT_GICR_INT1); break;
//case EXT_INT2: CLR_BIT(EXTINT_GICR, EXTINT_GICR_INT2); break;
//default: break;
//}
//}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
