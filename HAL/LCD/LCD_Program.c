/*
 * LCD_Program.c
 *
 *  Created on: Nov 14, 2022
 *      Author: mmont
 */

#include "StdTypes.h"
#include "BitMath.h"

#include "DIO_Types.h"
#include "DIO_Interface.h"

#include "LCD_Config.h"
#include "LCD_Interface.h"
#include "LCD_Private.h"

#define F_CPU 16000000UL
#include "util/delay.h"


/* NEED to declare and define [shifting window display] function*/


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

static void LCD_voidEnablePulse();
static void LCD_voidFuncSet4Bits(u8 copy_u8FuncSet);
static void LCD_voidSendingBits(u8 copy_u8Bits);

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

void LCD_voidInit() {
	DIO_voidSetPinMode(LCD_RS_PIN, DIO_PIN_OUTPUT);
	DIO_voidSetPinMode(LCD_RW_PIN, DIO_PIN_OUTPUT);
	DIO_voidSetPinMode(LCD_E_PIN, DIO_PIN_OUTPUT);

	#if LCD_DATA_PINS_MODE == LCD_8BITS_MODE
		DIO_voidSetPinMode(LCD_D0_PIN, DIO_PIN_OUTPUT);
		DIO_voidSetPinMode(LCD_D1_PIN, DIO_PIN_OUTPUT);
		DIO_voidSetPinMode(LCD_D2_PIN, DIO_PIN_OUTPUT);
		DIO_voidSetPinMode(LCD_D3_PIN, DIO_PIN_OUTPUT);
		DIO_voidSetPinMode(LCD_D4_PIN, DIO_PIN_OUTPUT);
		DIO_voidSetPinMode(LCD_D5_PIN, DIO_PIN_OUTPUT);
		DIO_voidSetPinMode(LCD_D6_PIN, DIO_PIN_OUTPUT);
		DIO_voidSetPinMode(LCD_D7_PIN, DIO_PIN_OUTPUT);

	#elif LCD_DATA_PINS_MODE == LCD_4BITS_MODE
		DIO_voidSetPinMode(LCD_D4_PIN, DIO_PIN_OUTPUT);
		DIO_voidSetPinMode(LCD_D5_PIN, DIO_PIN_OUTPUT);
		DIO_voidSetPinMode(LCD_D6_PIN, DIO_PIN_OUTPUT);
		DIO_voidSetPinMode(LCD_D7_PIN, DIO_PIN_OUTPUT);
	#endif

	_delay_ms(40);
	
	/* Function Set command */
	#if LCD_DATA_PINS_MODE == LCD_8BITS_MODE
		LCD_voidWriteCommand(LCD_FUNCTION_SET_2LINES_5X7_DOTS_8BITS);

	#elif LCD_DATA_PINS_MODE == LCD_4BITS_MODE
		LCD_voidFuncSet4Bits(LCD_FUNCTION_SET_2LINES_5X7_DOTS_4BITS);
	#endif

	_delay_ms(1);
	
	/* Display ON/OFF control */
	LCD_voidWriteCommand(LCD_DISPLAY_ON_OFF_CONTROL);
	_delay_ms(1);
	
	/* Display Clear */
	LCD_voidWriteCommand(LCD_DISPLAY_CLEAR);
	_delay_ms(2);
	
	/* Entry Mode Set*/
	LCD_voidWriteCommand(LCD_ENTRY_MODE_SET);
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

void LCD_voidWriteCommand(u8 copy_u8Command) {
	DIO_voidWritePinValue(LCD_RS_PIN, DIO_PIN_LOW);
	LCD_voidSendingBits(copy_u8Command);
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

void LCD_voidClear() {
	LCD_voidWriteCommand(LCD_DISPLAY_CLEAR);
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

void LCD_voidGoToXY(u8 copy_u8X, u8 copy_u8Y) {
	u8 local_DDRamAddress;
	switch(copy_u8Y) {
		case 0: local_DDRamAddress = copy_u8X; break;
		case 1: local_DDRamAddress = copy_u8X + 0x40; break;
		default: break;
	}
	SET_BIT(local_DDRamAddress, 7);
	LCD_voidWriteCommand(local_DDRamAddress);
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

void LCD_voidWriteData(u8 copy_u8Data) {
	DIO_voidWritePinValue(LCD_RS_PIN, DIO_PIN_HIGH);
	LCD_voidSendingBits(copy_u8Data);
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

void LCD_voidWriteString(u8 *u8String) {
	while(*u8String != '\0') {
		LCD_voidWriteData(*u8String);
		u8String++;
	}
}


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

void LCD_voidWriteNumber(u32 copy_u32Number) {
	u32 local_Number = copy_u32Number;
	u8 local_Arr[10] ,i = 0;
	do {
		local_Arr[i] = ((local_Number % 10) + 48);
		local_Number = local_Number/10 ;
		i++ ;
	} while(local_Number != 0);

	for(; i > 0; i--) {
		LCD_voidWriteData(local_Arr[i - 1]);
	}

}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

void LCD_voidWrtiteSpecialChar(u8* u8CharArr, u8 copy_u8BlockNum, u8 copy_u8PosX, u8 copy_u8PosY) {
	u8 local_CGRamAddress = copy_u8BlockNum * LCD_CGRAM_CHAR_BLOCK_SIZE;
	SET_BIT(local_CGRamAddress, 6);
	LCD_voidWriteCommand(local_CGRamAddress);
	for(u8 i = 0; i < 8; i++) {
		LCD_voidWriteData(u8CharArr[i]);
	}
	LCD_voidGoToXY(copy_u8PosX, copy_u8PosY);
	LCD_voidWriteData(copy_u8BlockNum);
	_delay_ms(1);
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

static void LCD_voidEnablePulse() {
	DIO_voidWritePinValue(LCD_E_PIN, DIO_PIN_HIGH);
	_delay_ms(2);
	DIO_voidWritePinValue(LCD_E_PIN, DIO_PIN_LOW);
	_delay_ms(2);
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

static void LCD_voidFuncSet4Bits(u8 copy_u8FuncSet) {
	DIO_voidWritePinValue(LCD_RS_PIN, DIO_PIN_LOW);
	DIO_voidWritePinValue(LCD_RW_PIN, DIO_PIN_LOW);

	DIO_voidWritePinValue(LCD_D7_PIN, GET_BIT(copy_u8FuncSet, 7));
	DIO_voidWritePinValue(LCD_D6_PIN, GET_BIT(copy_u8FuncSet, 6));
	DIO_voidWritePinValue(LCD_D5_PIN, GET_BIT(copy_u8FuncSet, 5));
	DIO_voidWritePinValue(LCD_D4_PIN, GET_BIT(copy_u8FuncSet, 4));
	LCD_voidEnablePulse();

	DIO_voidWritePinValue(LCD_D7_PIN, GET_BIT(copy_u8FuncSet, 7));
	DIO_voidWritePinValue(LCD_D6_PIN, GET_BIT(copy_u8FuncSet, 6));
	DIO_voidWritePinValue(LCD_D5_PIN, GET_BIT(copy_u8FuncSet, 5));
	DIO_voidWritePinValue(LCD_D4_PIN, GET_BIT(copy_u8FuncSet, 4));
	LCD_voidEnablePulse();

	DIO_voidWritePinValue(LCD_D7_PIN, GET_BIT(copy_u8FuncSet, 3));
	DIO_voidWritePinValue(LCD_D6_PIN, GET_BIT(copy_u8FuncSet, 2));
	DIO_voidWritePinValue(LCD_D5_PIN, GET_BIT(copy_u8FuncSet, 1));
	DIO_voidWritePinValue(LCD_D4_PIN, GET_BIT(copy_u8FuncSet, 0));
	LCD_voidEnablePulse();
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

static void LCD_voidSendingBits(u8 copy_u8Bits) {
	DIO_voidWritePinValue(LCD_RW_PIN, DIO_PIN_LOW);

	#if LCD_DATA_PINS_MODE == LCD_8BITS_MODE
		DIO_voidWritePortValue(LCD_DATA_PORT, copy_u8Bits);
		LCD_voidEnablePulse();

	#elif LCD_DATA_PINS_MODE == LCD_4BITS_MODE
		DIO_voidWritePinValue(LCD_D7_PIN, GET_BIT(copy_u8Bits, 7));
		DIO_voidWritePinValue(LCD_D6_PIN, GET_BIT(copy_u8Bits, 6));
		DIO_voidWritePinValue(LCD_D5_PIN, GET_BIT(copy_u8Bits, 5));
		DIO_voidWritePinValue(LCD_D4_PIN, GET_BIT(copy_u8Bits, 4));
		LCD_voidEnablePulse();
		DIO_voidWritePinValue(LCD_D7_PIN, GET_BIT(copy_u8Bits, 3));
		DIO_voidWritePinValue(LCD_D6_PIN, GET_BIT(copy_u8Bits, 2));
		DIO_voidWritePinValue(LCD_D5_PIN, GET_BIT(copy_u8Bits, 1));
		DIO_voidWritePinValue(LCD_D4_PIN, GET_BIT(copy_u8Bits, 0));
		LCD_voidEnablePulse();
	#endif
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

