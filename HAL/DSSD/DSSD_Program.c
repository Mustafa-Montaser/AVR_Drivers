/*
 * SVN_Program.c
 *
 *  Created on: Nov 12, 2022
 *      Author: mmont
 */

#include "StdTypes.h"
#include "BitMath.h"

#include "DIO_Types.h"
#include "DIO_Interface.h"
#include "DIO_Private.h"

#include "DSSD_Config.h"
#include "DSSD_Interface.h"
#include "DSSD_Private.h"

#include <util/delay.h>



static void display_0();
static void display_1();
static void display_2();
static void display_3();
static void display_4();
static void display_5();
static void display_6();
static void display_7();
static void display_8();
static void display_9();
static void displaySelected(u8 local_u8Num);


void DSSD_voidInit() {
	DIO_voidSetPinMode(DSSD_7SEG_EN1, DIO_PIN_OUTPUT);
	DIO_voidSetPinMode(DSSD_7SEG_EN2, DIO_PIN_OUTPUT);
	DIO_voidSetPinMode(DSSD_7SEG_DIP, DIO_PIN_OUTPUT);
	
	DIO_voidSetPinMode(DSSD_7SEG_A, DIO_PIN_OUTPUT);
	DIO_voidSetPinMode(DSSD_7SEG_B, DIO_PIN_OUTPUT);
	DIO_voidSetPinMode(DSSD_7SEG_C, DIO_PIN_OUTPUT);
	DIO_voidSetPinMode(DSSD_7SEG_D, DIO_PIN_OUTPUT);
	
	#if DSSD_MODE == DSSD_NORMAL_MODE
		DIO_voidSetPinMode(DSSD_7SEG_E, DIO_PIN_OUTPUT);
		DIO_voidSetPinMode(DSSD_7SEG_F, DIO_PIN_OUTPUT);
		DIO_voidSetPinMode(DSSD_7SEG_G, DIO_PIN_OUTPUT);
	#endif

//	DIO_voidClearPinValue(DSSD_7SEG_EN1);
//	DIO_voidClearPinValue(DSSD_7SEG_EN2);
//	DIO_voidClearPinValue(DSSD_7SEG_DIP);
			
//	DIO_voidClearPinValue(DSSD_7SEG_A);
//	DIO_voidClearPinValue(DSSD_7SEG_B);
//	DIO_voidClearPinValue(DSSD_7SEG_C);
//	DIO_voidClearPinValue(DSSD_7SEG_D);
}

void DSSD_voidEN1() {
	DIO_voidSetPinValue(DSSD_7SEG_EN1);
	DIO_voidClearPinValue(DSSD_7SEG_EN2);
}

void DSSD_voidEN2() {
	DIO_voidSetPinValue(DSSD_7SEG_EN2);
	DIO_voidClearPinValue(DSSD_7SEG_EN1);
}

void DSSD_voidEnableAll() {
	DIO_voidSetPinValue(DSSD_7SEG_EN1);
	DIO_voidSetPinValue(DSSD_7SEG_EN2);
}


void DSSD_voidDisplay(u8 local_u8Num) {
	if(local_u8Num >= 0 && local_u8Num <= 99) {
		if(local_u8Num <= 9) {
			DSSD_voidEN1();
			displaySelected(local_u8Num);
		} else {
			u8 local_u8Tens = local_u8Num / 10;
			u8 local_u8Ones = local_u8Num - local_u8Tens * 10;
			DSSD_voidEN1();
			displaySelected(local_u8Ones);
			_delay_ms(3);
			DSSD_voidEN2();
			displaySelected(local_u8Tens);
			_delay_ms(3);
		}
	}
}


//////////////////////////////////////////////////////////////////////

static void display_0() {
	#if DSSD_MODE == DSSD_BCD_MODE
		DIO_voidWritePinValue(DSSD_7SEG_A, DIO_PIN_LOW);
		DIO_voidWritePinValue(DSSD_7SEG_B, DIO_PIN_LOW);
		DIO_voidWritePinValue(DSSD_7SEG_C, DIO_PIN_LOW);
		DIO_voidWritePinValue(DSSD_7SEG_D, DIO_PIN_LOW);
	#elif DSSD_MODE == DSSD_NORMAL_MODE
		DIO_voidWritePinValue(DSSD_7SEG_A, DIO_PIN_HIGH);
		DIO_voidWritePinValue(DSSD_7SEG_B, DIO_PIN_HIGH);
		DIO_voidWritePinValue(DSSD_7SEG_C, DIO_PIN_HIGH);
		DIO_voidWritePinValue(DSSD_7SEG_D, DIO_PIN_HIGH);
		DIO_voidWritePinValue(DSSD_7SEG_E, DIO_PIN_HIGH);
		DIO_voidWritePinValue(DSSD_7SEG_F, DIO_PIN_HIGH);
		DIO_voidWritePinValue(DSSD_7SEG_G, DIO_PIN_LOW);
	#endif
}

static void display_1() {
	#if DSSD_MODE == DSSD_BCD_MODE
		DIO_voidWritePinValue(DSSD_7SEG_A, DIO_PIN_HIGH);
		DIO_voidWritePinValue(DSSD_7SEG_B, DIO_PIN_LOW);
		DIO_voidWritePinValue(DSSD_7SEG_C, DIO_PIN_LOW);
		DIO_voidWritePinValue(DSSD_7SEG_D, DIO_PIN_LOW);
	#elif DSSD_MODE == DSSD_NORMAL_MODE
		DIO_voidWritePinValue(DSSD_7SEG_A, DIO_PIN_LOW);
		DIO_voidWritePinValue(DSSD_7SEG_B, DIO_PIN_HIGH);
		DIO_voidWritePinValue(DSSD_7SEG_C, DIO_PIN_HIGH);
		DIO_voidWritePinValue(DSSD_7SEG_D, DIO_PIN_LOW);
		DIO_voidWritePinValue(DSSD_7SEG_E, DIO_PIN_LOW);
		DIO_voidWritePinValue(DSSD_7SEG_F, DIO_PIN_LOW);
		DIO_voidWritePinValue(DSSD_7SEG_G, DIO_PIN_LOW);
	#endif
}

static void display_2() {
	#if DSSD_MODE == DSSD_BCD_MODE
		DIO_voidWritePinValue(DSSD_7SEG_A, DIO_PIN_LOW);
		DIO_voidWritePinValue(DSSD_7SEG_B, DIO_PIN_HIGH);
		DIO_voidWritePinValue(DSSD_7SEG_C, DIO_PIN_LOW);
		DIO_voidWritePinValue(DSSD_7SEG_D, DIO_PIN_LOW);
	#elif DSSD_MODE == DSSD_NORMAL_MODE
		DIO_voidWritePinValue(DSSD_7SEG_A, DIO_PIN_HIGH);
		DIO_voidWritePinValue(DSSD_7SEG_B, DIO_PIN_HIGH);
		DIO_voidWritePinValue(DSSD_7SEG_C, DIO_PIN_LOW);
		DIO_voidWritePinValue(DSSD_7SEG_D, DIO_PIN_HIGH);
		DIO_voidWritePinValue(DSSD_7SEG_E, DIO_PIN_HIGH);
		DIO_voidWritePinValue(DSSD_7SEG_F, DIO_PIN_LOW);
		DIO_voidWritePinValue(DSSD_7SEG_G, DIO_PIN_HIGH);
	#endif
}

static void display_3() {
	#if DSSD_MODE == DSSD_BCD_MODE
		DIO_voidWritePinValue(DSSD_7SEG_A, DIO_PIN_HIGH);
		DIO_voidWritePinValue(DSSD_7SEG_B, DIO_PIN_HIGH);
		DIO_voidWritePinValue(DSSD_7SEG_C, DIO_PIN_LOW);
		DIO_voidWritePinValue(DSSD_7SEG_D, DIO_PIN_LOW);
	#elif DSSD_MODE == DSSD_NORMAL_MODE
		DIO_voidWritePinValue(DSSD_7SEG_A, DIO_PIN_HIGH);
		DIO_voidWritePinValue(DSSD_7SEG_B, DIO_PIN_HIGH);
		DIO_voidWritePinValue(DSSD_7SEG_C, DIO_PIN_HIGH);
		DIO_voidWritePinValue(DSSD_7SEG_D, DIO_PIN_HIGH);
		DIO_voidWritePinValue(DSSD_7SEG_E, DIO_PIN_LOW);
		DIO_voidWritePinValue(DSSD_7SEG_F, DIO_PIN_LOW);
		DIO_voidWritePinValue(DSSD_7SEG_G, DIO_PIN_HIGH);
	#endif
}

static void display_4() {
	#if DSSD_MODE == DSSD_BCD_MODE
		DIO_voidWritePinValue(DSSD_7SEG_A, DIO_PIN_LOW);
		DIO_voidWritePinValue(DSSD_7SEG_B, DIO_PIN_LOW);
		DIO_voidWritePinValue(DSSD_7SEG_C, DIO_PIN_HIGH);
		DIO_voidWritePinValue(DSSD_7SEG_D, DIO_PIN_LOW);
	#elif DSSD_MODE == DSSD_NORMAL_MODE
		DIO_voidWritePinValue(DSSD_7SEG_A, DIO_PIN_LOW);
		DIO_voidWritePinValue(DSSD_7SEG_B, DIO_PIN_HIGH);
		DIO_voidWritePinValue(DSSD_7SEG_C, DIO_PIN_HIGH);
		DIO_voidWritePinValue(DSSD_7SEG_D, DIO_PIN_LOW);
		DIO_voidWritePinValue(DSSD_7SEG_E, DIO_PIN_LOW);
		DIO_voidWritePinValue(DSSD_7SEG_F, DIO_PIN_HIGH);
		DIO_voidWritePinValue(DSSD_7SEG_G, DIO_PIN_HIGH);
	#endif
}

static void display_5() {
	#if DSSD_MODE == DSSD_BCD_MODE
		DIO_voidWritePinValue(DSSD_7SEG_A, DIO_PIN_HIGH);
		DIO_voidWritePinValue(DSSD_7SEG_B, DIO_PIN_LOW);
		DIO_voidWritePinValue(DSSD_7SEG_C, DIO_PIN_HIGH);
		DIO_voidWritePinValue(DSSD_7SEG_D, DIO_PIN_LOW);
	#elif DSSD_MODE == DSSD_NORMAL_MODE
		DIO_voidWritePinValue(DSSD_7SEG_A, DIO_PIN_HIGH);
		DIO_voidWritePinValue(DSSD_7SEG_B, DIO_PIN_LOW);
		DIO_voidWritePinValue(DSSD_7SEG_C, DIO_PIN_HIGH);
		DIO_voidWritePinValue(DSSD_7SEG_D, DIO_PIN_HIGH);
		DIO_voidWritePinValue(DSSD_7SEG_E, DIO_PIN_LOW);
		DIO_voidWritePinValue(DSSD_7SEG_F, DIO_PIN_HIGH);
		DIO_voidWritePinValue(DSSD_7SEG_G, DIO_PIN_HIGH);
	#endif
}

static void display_6() {
	#if DSSD_MODE == DSSD_BCD_MODE
		DIO_voidWritePinValue(DSSD_7SEG_A, DIO_PIN_LOW);
		DIO_voidWritePinValue(DSSD_7SEG_B, DIO_PIN_HIGH);
		DIO_voidWritePinValue(DSSD_7SEG_C, DIO_PIN_HIGH);
		DIO_voidWritePinValue(DSSD_7SEG_D, DIO_PIN_LOW);
	#elif DSSD_MODE == DSSD_NORMAL_MODE
		DIO_voidWritePinValue(DSSD_7SEG_A, DIO_PIN_HIGH);
		DIO_voidWritePinValue(DSSD_7SEG_B, DIO_PIN_LOW);
		DIO_voidWritePinValue(DSSD_7SEG_C, DIO_PIN_HIGH);
		DIO_voidWritePinValue(DSSD_7SEG_D, DIO_PIN_HIGH);
		DIO_voidWritePinValue(DSSD_7SEG_E, DIO_PIN_HIGH);
		DIO_voidWritePinValue(DSSD_7SEG_F, DIO_PIN_HIGH);
		DIO_voidWritePinValue(DSSD_7SEG_G, DIO_PIN_HIGH);
	#endif
}

static void display_7() {
	#if DSSD_MODE == DSSD_BCD_MODE
		DIO_voidWritePinValue(DSSD_7SEG_A, DIO_PIN_HIGH);
		DIO_voidWritePinValue(DSSD_7SEG_B, DIO_PIN_HIGH);
		DIO_voidWritePinValue(DSSD_7SEG_C, DIO_PIN_HIGH);
		DIO_voidWritePinValue(DSSD_7SEG_D, DIO_PIN_LOW);
	#elif DSSD_MODE == DSSD_NORMAL_MODE
		DIO_voidWritePinValue(DSSD_7SEG_A, DIO_PIN_HIGH);
		DIO_voidWritePinValue(DSSD_7SEG_B, DIO_PIN_HIGH);
		DIO_voidWritePinValue(DSSD_7SEG_C, DIO_PIN_HIGH);
		DIO_voidWritePinValue(DSSD_7SEG_D, DIO_PIN_LOW);
		DIO_voidWritePinValue(DSSD_7SEG_E, DIO_PIN_LOW);
		DIO_voidWritePinValue(DSSD_7SEG_F, DIO_PIN_LOW);
		DIO_voidWritePinValue(DSSD_7SEG_G, DIO_PIN_LOW);
	#endif
}

static void display_8() {
	#if DSSD_MODE == DSSD_BCD_MODE
		DIO_voidWritePinValue(DSSD_7SEG_A, DIO_PIN_LOW);
		DIO_voidWritePinValue(DSSD_7SEG_B, DIO_PIN_LOW);
		DIO_voidWritePinValue(DSSD_7SEG_C, DIO_PIN_LOW);
		DIO_voidWritePinValue(DSSD_7SEG_D, DIO_PIN_HIGH);
	#elif DSSD_MODE == DSSD_NORMAL_MODE
		DIO_voidWritePinValue(DSSD_7SEG_A, DIO_PIN_HIGH);
		DIO_voidWritePinValue(DSSD_7SEG_B, DIO_PIN_HIGH);
		DIO_voidWritePinValue(DSSD_7SEG_C, DIO_PIN_HIGH);
		DIO_voidWritePinValue(DSSD_7SEG_D, DIO_PIN_HIGH);
		DIO_voidWritePinValue(DSSD_7SEG_E, DIO_PIN_HIGH);
		DIO_voidWritePinValue(DSSD_7SEG_F, DIO_PIN_HIGH);
		DIO_voidWritePinValue(DSSD_7SEG_G, DIO_PIN_HIGH);
	#endif
}

static void display_9() {
	#if DSSD_MODE == DSSD_BCD_MODE
		DIO_voidWritePinValue(DSSD_7SEG_A, DIO_PIN_HIGH);
		DIO_voidWritePinValue(DSSD_7SEG_B, DIO_PIN_LOW);
		DIO_voidWritePinValue(DSSD_7SEG_C, DIO_PIN_LOW);
		DIO_voidWritePinValue(DSSD_7SEG_D, DIO_PIN_HIGH);
	#elif DSSD_MODE == DSSD_NORMAL_MODE
		DIO_voidWritePinValue(DSSD_7SEG_A, DIO_PIN_HIGH);
		DIO_voidWritePinValue(DSSD_7SEG_B, DIO_PIN_HIGH);
		DIO_voidWritePinValue(DSSD_7SEG_C, DIO_PIN_HIGH);
		DIO_voidWritePinValue(DSSD_7SEG_D, DIO_PIN_HIGH);
		DIO_voidWritePinValue(DSSD_7SEG_E, DIO_PIN_LOW);
		DIO_voidWritePinValue(DSSD_7SEG_F, DIO_PIN_HIGH);
		DIO_voidWritePinValue(DSSD_7SEG_G, DIO_PIN_HIGH);
	#endif
}

static void displaySelected(u8 local_u8Num) {
	switch(local_u8Num) {
		case 0: 	display_0(); 	break;
		case 1: 	display_1(); 	break;
		case 2: 	display_2(); 	break;
		case 3: 	display_3(); 	break;
		case 4: 	display_4(); 	break;
		case 5: 	display_5(); 	break;
		case 6: 	display_6(); 	break;
		case 7: 	display_7();	break;
		case 8:	 	display_8(); 	break;
		case 9: 	display_9(); 	break;
		default: 	display_0();	break;
	}
}










