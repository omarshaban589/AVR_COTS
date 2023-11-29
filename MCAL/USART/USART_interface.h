#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H

void USART_voidInit(void);
void USART_voidTransmitDataSynchronous(u8 Copy_u8Data);
void USART_voidRecieveDataSynchronous(u8 *Copy_u8Data);
void USART_voidRecieveDataAsynchronous(void (*Ref_pvFunction)(u8 *));
void USART_voidTransmitDataAsynchronous(void (*Ref_pvFunction)(void), u8 Copy_u8Data);

#endif