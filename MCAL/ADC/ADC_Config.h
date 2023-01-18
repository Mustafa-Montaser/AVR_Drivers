/*
 * ADC_Config.h
 *
 * Created: 12/6/2022 6:35:56 AM
 *  Author: mmont
 */ 


#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

////////////////////////////////////////////////////////////////////////////////////////

/* Input Frequency for ADC */
#define ADC_INPUT_FREQ		16000000UL

////////////////////////////////////////////////////////////////////////////////////////

/* ADC Reference voltage 
	values = {
		ADC_VOLT_REF_EXTERNAL,
		ADC_VOLT_REF_AVCC,
		ADC_VOLT_REF_INTERNAL_2V56
	}
*/
#define ADC_VOLT_REF			ADC_VOLT_REF_AVCC

#define ADC_VOLT_REF_VALUE		5

////////////////////////////////////////////////////////////////////////////////////////

#define ADC_CH0					 0
#define ADC_CH1					 1
#define ADC_CH2					 2
#define ADC_CH3					 3
#define ADC_CH4					 4
#define ADC_CH5					 5
#define ADC_CH6					 6
#define ADC_CH7					 7

////////////////////////////////////////////////////////////////////////////////////////

/* ADC Prescaler selection
	values {
		ADC_PRESCALER_2  ,
		ADC_PRESCALER_4	 ,
		ADC_PRESCALER_8	 ,
		ADC_PRESCALER_16 ,
		ADC_PRESCALER_32 ,
		ADC_PRESCALER_64 ,
		ADC_PRESCALER_128
	}
 */

#define ADC_PRESCALER			ADC_PRESCALER_128

////////////////////////////////////////////////////////////////////////////////////////

/* ADC auto trigger state
	values = {
		ADC_AUTO_TRIGGER_ENABLE,
		ADC_AUTO_TRIGGER_DISABLE
	}
 */

#define ADC_AUTO_TRIGGER_STATE		ADC_AUTO_TRIGGER_ENABLE

////////////////////////////////////////////////////////////////////////////////////////

/* ADC trigger source 
	values = {
		ADC_TRIG_SRC_FREE_RUNNING		,
		ADC_TRIG_SRC_ANALOD_COMP		,
		ADC_TRIG_SRC_EXT_INT0			,
		ADC_TRIG_SRC_TIMER0_COM_MATCH	,
		ADC_TRIG_SRC_TIMER0_OVERFLOW	,
		ADC_TRIG_SRC_TIMER_COM_MATCH_B	,
		ADC_TRIG_SRC_TIMER1_OVERFLOW	,
		ADC_TRIG_SRC_TIMER1_CAP_EVENT
	}
*/

#define ADC_TRIG_SRC			ADC_TRIG_SRC_FREE_RUNNING

////////////////////////////////////////////////////////////////////////////////////////

/* ADC operation mode
	values = {
		ADC_POLLING_MODE,
		ADC_INTERRUPT_MODE
	}
 */

#define ADC_MODE				ADC_INTERRUPT_MODE

////////////////////////////////////////////////////////////////////////////////////////


#endif /* ADC_CONFIG_H_ */