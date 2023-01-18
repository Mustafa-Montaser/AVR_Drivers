/*
 * IIC_Config.h
 *
 *  Created on: Jan 3, 2023
 *      Author: mmont
 */

#ifndef DATA_MCAL_IIC_IIC_CONFIG_H_
#define DATA_MCAL_IIC_IIC_CONFIG_H_



#define F_OSC_HZ					16000000

#define IIC_F_SCL_HZ				400000

#define IIC_SLAVE_ADDRESS			0x05


/*
 * IIC_MASTER_MODE
 * IIC_SLAVE_MODE
*/
#define IIC_OPERATION_MODE			IIC_MASTER_MODE


/*
 * IIC_LISTEN_GENERAL_CALL_ENABLE
 * IIC_LISTEN_GENERAL_CALL_DISABLE
*/
#define IIC_LISTEN_GENERAL_CALL		IIC_LISTEN_GENERAL_CALL_ENABLE




#endif /* DATA_MCAL_IIC_IIC_CONFIG_H_ */
