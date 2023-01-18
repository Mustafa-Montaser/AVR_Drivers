/*
 * EXT_INT_Config.h
 *
 *  Created on: Nov 17, 2022
 *      Author: mmont
 */

#ifndef EXT_INT_CONFIG_H_
#define EXT_INT_CONFIG_H_


/* EXT INT state
	values = {
		EXT_INT_ENABLE,
		EXT_INT_DISABLE
	}
*/
#define EXT_INT0_STATE		EXT_INT_ENABLE
#define EXT_INT1_STATE		EXT_INT_DISABLE
#define EXT_INT2_STATE		EXT_INT_DISABLE


////////////////////////////////////////////////////////////////////////////////

/* sense control 
	values = {
		EXT_INT_SENSE_CONTROL_LOW_LEVEL,		=> Int0, 1
		EXT_INT_SENSE_CONTROL_ANY_CHANGE,		=> Int0, 1
		EXT_INT_SENSE_CONTROL_FALLING_EDGE,		=> Int0, 1, 2
		EXT_INT_SENSE_CONTROL_RISING_EDGE		=> Int0, 1, 2
	}
*/
#if EXT_INT0_STATE == EXT_INT_ENABLE
	#define EXT_INT0_SENSE_CTRL		EXT_INT_SENSE_CONTROL_RISING_EDGE
#endif

#if EXT_INT1_STATE == EXT_INT_ENABLE
	#define EXT_INT1_SENSE_CTRL		EXT_INT_SENSE_CONTROL_FALLING_EDGE
#endif

#if EXT_INT2_STATE == EXT_INT_ENABLE
	#define EXT_INT2_SENSE_CTRL		EXT_INT_SENSE_CONTROL_FALLING_EDGE
#endif


////////////////////////////////////////////////////////////////////////////////////////

/* Ext Int. selection */
//#define EXT_INT0		0
//#define EXT_INT1		1
//#define EXT_INT2		2






#endif /* EXT_INT_CONFIG_H_ */
