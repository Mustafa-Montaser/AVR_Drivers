/*
 * EEPROM_Program.c
 *
 *  Created on: Jan 7, 2023
 *      Author: mmont
 */


#include "StdTypes.h"
#include "BitMath.h"

#include "EEPROM_Config.h"
#include "EEPROM_Interface.h"
#include "EEPROM_Private.h"

#include "IIC_Config.h"
#include "IIC_Interface.h"


void EEPROM_voidInit() {
	IIC_voidInit();
}


EEPROM_State_t EEPROM_voidWriteByte(u8 local_u8DataByte, u8 local_u8PageAddress, u8 local_u8ByteAddress) {
	u8 local_u8State = IIC_NOK;
	local_u8State = IIC_enumStartCondition();
	if(local_u8State == IIC_OK)
		local_u8State = IIC_enumSendSlaveAddressWithWrite(EEPROM_MSB_ADDRESS | local_u8PageAddress);
	if(local_u8State == IIC_OK)
		local_u8State = IIC_enumSendByte(local_u8ByteAddress);
	if(local_u8State == IIC_OK)
		local_u8State = IIC_enumSendByte(local_u8DataByte);
	if(local_u8State == IIC_OK)
		local_u8State = IIC_enumStopCondition();

	if(local_u8State == IIC_OK) local_u8State = EEPROM_OK;
	else local_u8State = EEPROM_NOK;
	return local_u8State;
}

EEPROM_State_t EEPROM_u8ReadByte(u8 local_u8PageAddress, u8 local_u8ByteAddress, u8 *local_u8PtrReceivedData) {
	u8 local_u8State = IIC_NOK;
	local_u8State = IIC_enumStartCondition();
	if(local_u8State == IIC_OK)
		local_u8State = IIC_enumSendSlaveAddressWithWrite(EEPROM_MSB_ADDRESS | local_u8PageAddress);
	if(local_u8State == IIC_OK)
		local_u8State = IIC_enumSendByte(local_u8ByteAddress);
	if(local_u8State == IIC_OK)
		local_u8State = IIC_enumRepeatStart();
	if(local_u8State == IIC_OK)
		local_u8State = IIC_enumSendSlaveAddressWithRead(EEPROM_MSB_ADDRESS | local_u8PageAddress);
	if(local_u8State == IIC_OK)
		local_u8State = IIC_enumReceiveByte(local_u8PtrReceivedData);
	if(local_u8State == IIC_OK)
		local_u8State = IIC_enumStopCondition();

	if(local_u8State == IIC_OK) local_u8State = EEPROM_OK;
	else local_u8State = EEPROM_NOK;
	return local_u8State;
}



