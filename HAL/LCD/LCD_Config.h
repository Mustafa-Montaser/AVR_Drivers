/*
 * LCD_Config.h
 *
 *  Created on: Nov 14, 2022
 *      Author: mmont
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_


/*
 * values = {
 * 		LCD_4BITS_MODE
 * 		LCD_8BITS_MODE
 * }
*/
#define LCD_DATA_PINS_MODE	LCD_4BITS_MODE


#define LCD_CTRL_PORT		DIO_PORT_A
#define LCD_DATA_PORT		DIO_PORT_B

#define LCD_RS_PIN			DIO_PA3
#define LCD_RW_PIN			DIO_PA1
#define LCD_E_PIN			DIO_PA2

#define LCD_D4_PIN			DIO_PB0
#define LCD_D5_PIN			DIO_PB1
#define LCD_D6_PIN			DIO_PB2
#define LCD_D7_PIN			DIO_PB4

#define LCD_D0_PIN			DIO_PB5
#define LCD_D1_PIN			DIO_PB6
#define LCD_D2_PIN			DIO_PB7
#define LCD_D3_PIN			DIO_PC1



#endif /* LCD_CONFIG_H_ */
