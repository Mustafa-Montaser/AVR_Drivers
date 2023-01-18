#ifndef DIO_TYPES_H_
#define DIO_TYPES_H_

typedef enum {
	DIO_PORT_A,
	DIO_PORT_B,
	DIO_PORT_C,
	DIO_PORT_D
} DIO_PortId_t;

typedef enum {
	DIO_PIN0,
	DIO_PIN1,
	DIO_PIN2,
	DIO_PIN3,
	DIO_PIN4,
	DIO_PIN5,
	DIO_PIN6,
	DIO_PIN7
} DIO_PinId_t;

typedef enum {
	DIO_PA0 = 10,
	DIO_PA1,
	DIO_PA2,
	DIO_PA3,
	DIO_PA4,
	DIO_PA5,
	DIO_PA6,
	DIO_PA7,

	DIO_PB0 = 20,
	DIO_PB1,
	DIO_PB2,
	DIO_PB3,
	DIO_PB4,
	DIO_PB5,
	DIO_PB6,
	DIO_PB7,

	DIO_PC0 = 30,
	DIO_PC1,
	DIO_PC2,
	DIO_PC3,
	DIO_PC4,
	DIO_PC5,
	DIO_PC6,
	DIO_PC7,

	DIO_PD0 = 40,
	DIO_PD1,
	DIO_PD2,
	DIO_PD3,
	DIO_PD4,
	DIO_PD5,
	DIO_PD6,
	DIO_PD7
} DIO_Pin_t;

typedef enum {
	DIO_PIN_INPUT,
	DIO_PIN_OUTPUT
} DIO_PinMode_t;

typedef enum {
	DIO_PORT_INPUT,
	DIO_PORT_OUTPUT	= 0xFF
} DIO_PortMode_t;

typedef enum {
	DIO_PIN_LOW,
	DIO_PIN_HIGH
} DIO_PinValue_t;

typedef enum {
	DIO_PORT_LOW,
	DIO_PORT_HIGH = 0XFF
} DIO_PortValue_t;





#endif	/* DIO_TYPES_H_ */


















