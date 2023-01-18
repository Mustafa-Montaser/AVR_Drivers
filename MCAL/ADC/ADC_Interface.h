/*
 * ADC_Interface.h
 *
 * Created: 12/5/2022 8:29:25 PM
 *  Author: mmont
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

/************************************************************************/
/*                            MACROS                                    */
/************************************************************************/
	
#define ADC_RESOLUTION					1024

#define ADC_VOLT_REF_EXTERNAL			0b00
#define ADC_VOLT_REF_AVCC				0b01
#define ADC_VOLT_REF_INTERNAL_2V56		0b11


#define ADC_CH_ADC0						0b00000
#define ADC_CH_ADC1						0b00001
#define ADC_CH_ADC2						0b00010
#define ADC_CH_ADC3						0b00011
#define ADC_CH_ADC4						0b00100
#define ADC_CH_ADC5						0b00101
#define ADC_CH_ADC6						0b00110
#define ADC_CH_ADC7						0b00111


#define ADC_PRESCALER_2					0b001	
#define ADC_PRESCALER_4					0b010	
#define ADC_PRESCALER_8					0b011	
#define ADC_PRESCALER_16				0b100	
#define ADC_PRESCALER_32				0b101	
#define ADC_PRESCALER_64				0b110	
#define ADC_PRESCALER_128               0b111	


#define ADC_AUTO_TRIGGER_ENABLE			1
#define ADC_AUTO_TRIGGER_DISABLE		0


#define ADC_TRIG_SRC_FREE_RUNNING		0b000
#define ADC_TRIG_SRC_ANALOD_COMP		0b001
#define ADC_TRIG_SRC_EXT_INT0			0b010
#define ADC_TRIG_SRC_TIMER0_COM_MATCH	0b011
#define ADC_TRIG_SRC_TIMER0_OVERFLOW	0b100
#define ADC_TRIG_SRC_TIMER_COM_MATCH_B	0b101
#define ADC_TRIG_SRC_TIMER1_OVERFLOW	0b110
#define ADC_TRIG_SRC_TIMER1_CAP_EVENT	0b111


#define ADC_POLLING_MODE				0
#define ADC_INTERRUPT_MODE				1


/************************************************************************/
/*							      APIs			                        */
/************************************************************************/

void ADC_voidInit();

/* polling mode */
u16 ADC_u16Read(u8 Copy_u8ChNumber);

/* Interrupt mode */
void ADC_voidStartConversion(u8 Copy_u8ChNumber);
void ADC_voidSetCallBack(void (*ptr) (void));
u16 ADC_u16GetValue();

#endif /* ADC_INTERFACE_H_ */