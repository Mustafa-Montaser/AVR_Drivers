

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

void DIO_voidSetPortMode(DIO_PortId_t Copy_u8PortId, DIO_PortMode_t Copy_u8PortMode);
void DIO_voidWritePortValue(DIO_PortId_t Copy_u8PortId, u8 Copy_u8PortValue);
u8 DIO_voidReadPortValue(DIO_PortId_t Copy_u8PortId);

void DIO_voidSetPinMode(DIO_Pin_t Copy_u8Pin, DIO_PinMode_t Copy_u8PinMode);
void DIO_voidSetPinValue(DIO_Pin_t Copy_u8Pin);
void DIO_voidClearPinValue(DIO_Pin_t Copy_u8Pin);
void DIO_voidTogglePinValue(DIO_Pin_t Copy_u8Pin);
void DIO_voidWritePinValue(DIO_Pin_t Copy_u8Pin, DIO_PinValue_t Copy_u8Value);
DIO_PinValue_t DIO_u8GetPinValue(DIO_Pin_t Copy_u8Pin);




#endif /* DIO_INTERFACE_H_ */
