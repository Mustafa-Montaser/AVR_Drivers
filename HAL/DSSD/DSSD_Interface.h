/*
 * SVN_SEG_Interface.h
 *
 *  Created on: Nov 12, 2022
 *      Author: mmont
 */




#ifndef DSSD_INTERFACE_H_
#define DSSD_INTERFACE_H_

#define DSSD_BCD_MODE		0
#define DSSD_NORMAL_MODE	1


void DSSD_voidInit();
void DSSD_voidEN1();
void DSSD_voidEN2();
void DSSD_voidEnableAll();
void DSSD_voidDisplay(u8 local_u8Num);



#endif /* DSSD_INTERFACE_H_ */
