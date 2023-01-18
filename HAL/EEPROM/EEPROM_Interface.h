/*
 * EEPROM_Interface.h
 *
 *  Created on: Jan 7, 2023
 *      Author: mmont
 */

#ifndef DATA_HAL_EEPROM_EEPROM_INTERFACE_H_
#define DATA_HAL_EEPROM_EEPROM_INTERFACE_H_



#define EEPROM_MSB_ADDRESS		0x50


typedef enum {
	EEPROM_OK,
	EEPROM_NOK
} EEPROM_State_t;


void EEPROM_voidInit();
EEPROM_State_t EEPROM_voidWriteByte(u8, u8, u8);
EEPROM_State_t EEPROM_u8ReadByte(u8, u8, u8 *);


#endif /* DATA_HAL_EEPROM_EEPROM_INTERFACE_H_ */
