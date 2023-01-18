/*
 * Timer0_Config.h
 *
 * Created: 12/6/2022 4:13:44 PM
 *  Author: mmont
 */ 


#ifndef TIMER0_CONFIG_H_
#define TIMER0_CONFIG_H_

//////////////////////////////////////////////////////////////////////////////////
/*
	waveform generation setting
	values = {
		TIMER0_WAVEFORM_NORMAL_MODE,
		TIMER0_WAVEFORM_PHASE_CORRECT_MODE,
		TIMER0_WAVEFORM_CTC_MODE,
		TIMER0_WAVEFORM_FAST_PWM_MODE
	}
*/

#define TIMER0_WAVEFORM_MODE		TIMER0_WAVEFORM_PHASE_CORRECT_MODE

//////////////////////////////////////////////////////////////////////////////////
/*
	Timer0 Clock Select
	values = {
		TIMER0_STOP_PRESCALER	,
		TIMER0_NO_PRESCALER		,
		TIMER0_PRESCALER_8		,
		TIMER0_PRESCALER_64		,
		TIMER0_PRESCALER_256	,
		TIMER0_PRESCALER_1024	,
		TIMER0_EXT_CLK_FALLING	,
		TIMER0_EXT_CLK_RISING
	}
*/

#define TIMER0_PRESCALER			TIMER0_PRESCALER_1024

//////////////////////////////////////////////////////////////////////////////////

/* Timer0 Input Freq. (MHz) Before Prescaler */

#define TIMER0_F_OSC				16

//////////////////////////////////////////////////////////////////////////////////

/* 
	PWM Mode
	values = {
		TIMER0_FAST_PWM_NON_INVERTING_MODE ,
		TIMER0_FAST_PWM_INVERTING_MODE
	} 
*/

#define TIMER0_FAST_PWM_MODE		TIMER0_FAST_PWM_NON_INVERTING_MODE

//////////////////////////////////////////////////////////////////////////////////




#endif /* TIMER0_CONFIG_H_ */