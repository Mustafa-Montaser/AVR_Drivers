/*
 * IIC_Interface.h
 *
 *  Created on: Jan 3, 2023
 *      Author: mmont
 */

#ifndef DATA_MCAL_IIC_IIC_INTERFACE_H_
#define DATA_MCAL_IIC_IIC_INTERFACE_H_

/*///////////////////////// Macros ////////////////////////*/


#define IIC_BIT_RATE_PRESCALER_1				0b00
#define IIC_BIT_RATE_PRESCALER_4				0b01
#define IIC_BIT_RATE_PRESCALER_16				0b10
#define IIC_BIT_RATE_PRESCALER_64				0b11

#define IIC_MASTER_MODE							1
#define IIC_SLAVE_MODE							0

#define IIC_LISTEN_GENERAL_CALL_ENABLE			1
#define IIC_LISTEN_GENERAL_CALL_DISABLE			0

#define IIC_TIMEOUT								16000000UL


/* M: Master, S: Slave */
typedef enum {
	IIC_OK,
	IIC_NOK,
	IIC_START_COND_ERR,
	IIC_RE_START_ERR,
	IIC_STOP_COND_ERR,
	IIC_SLA_ADD_WRT_ERR,
	IIC_SLA_ADD_WRT_NACK,
	IIC_ARBITRATION_LOST,
	IIC_SLA_ADD_READ_ERR,
	IIC_SLA_ADD_READ_NACK,
	IIC_M_SEND_BYTE_ERR,
	IIC_M_SEND_BYTE_NACK,
	IIC_M_RECEIVE_BYTE_ERR,
	IIC_M_RECEIVE_BYTE_NACK,
	IIC_S_SEND_BYTE_ERR,
	IIC_S_RECEIVE_BYTE_ERR,
	IIC_TIMEOUT_ERR
}IIC_State_t;


/*///////////////////////// APIs ////////////////////////*/

void IIC_voidInit(void);
IIC_State_t IIC_enumStartCondition(void);
IIC_State_t IIC_enumStopCondition(void);
IIC_State_t IIC_enumSendSlaveAddressWithWrite(u8);
IIC_State_t IIC_enumSendSlaveAddressWithRead(u8);
IIC_State_t IIC_enumSendByte(u8);
IIC_State_t	IIC_enumReceiveByte(u8 *);
IIC_State_t IIC_enumRepeatStart(void);
//void IIC_voidSendAck(void);

//u8 IIC_u8SlaveListen(void);




#endif /* DATA_MCAL_IIC_IIC_INTERFACE_H_ */
