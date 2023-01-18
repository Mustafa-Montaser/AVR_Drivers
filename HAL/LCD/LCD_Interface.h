/*
 * LCD_Interface.c
 *
 *  Created on: Nov 14, 2022
 *      Author: mmont
 */


#ifndef LCD_INTERFACE_C_
#define LCD_INTERFACE_C_


void LCD_voidInit();
void LCD_voidWriteCommand(u8 copy_u8Command);
void LCD_voidClear();
void LCD_voidGoToXY(u8 copy_u8X, u8 copy_u8y);
void LCD_voidWriteData(u8 copy_u8Char);
void LCD_voidWriteNumber(u32 copy_u32Number);
void LCD_voidWriteString(u8 *u8String);
void LCD_voidWrtiteSpecialChar(u8* u8CharArr, u8 copy_u8BlockNum, u8 copy_u8PosX, u8 copy_u8PosY);


#endif /* LCD_INTERFACE_C_ */
