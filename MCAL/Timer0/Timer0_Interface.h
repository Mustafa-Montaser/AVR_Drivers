/*
 * Timer0_Interface.h
 *
 * Created: 12/6/2022 4:14:01 PM
 *  Author: mmont
 */ 


#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_

/************************************************************************/
/*                             MACROS                                   */
/************************************************************************/

#define TIMER0_WAVEFORM_NORMAL_MODE			0
#define TIMER0_WAVEFORM_CTC_MODE			1
#define TIMER0_WAVEFORM_FAST_PWM_MODE		2
#define TIMER0_WAVEFORM_PHASE_CORRECT_MODE	3

#define TIMER0_STOP_PRESCALER				0b000
#define TIMER0_NO_PRESCALER					0b001
#define TIMER0_PRESCALER_8					0b010
#define	TIMER0_PRESCALER_64					0b011
#define TIMER0_PRESCALER_256				0b100
#define TIMER0_PRESCALER_1024				0b101
#define TIMER0_EXT_CLK_FALLING				0b110
#define TIMER0_EXT_CLK_RISING				0b111

#define TIMER0_FAST_PWM_NON_INVERTING_MODE	0
#define TIMER0_FAST_PWM_INVERTING_MODE		1



/************************************************************************/
/*                               APIs                                   */
/************************************************************************/


void Timer0_voidInit();
void Timer0_voidSetTime(u32 copy_u8Time);
void Timer0_voidStart();
void Timer0_voidStop();
void Timer0_voidSetCallBack(void (*ptr) (void));

//PWM
void Timer0_voidPwmInit();
void Timer0_voidSetPwmDutyCycle(u8 local_u8DuctyCycle);
void Timer0_voidStartPwm();
void Timer0_voidStopPwm();



#endif /* TIMER0_INTERFACE_H_ */