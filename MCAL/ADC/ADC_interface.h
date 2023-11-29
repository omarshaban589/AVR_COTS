#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

#define ADC_CHANNEL0 0b00000
#define ADC_CHANNEL1 0b00001
#define ADC_CHANNEL2 0b00010
#define ADC_CHANNEL3 0b00011
#define ADC_CHANNEL4 0b00100
#define ADC_CHANNEL5 0b00101
#define ADC_CHANNEL6 0b00110
#define ADC_CHANNEL7 0b00111

#define ADC_LEFT_ADJUST 0
#define ADC_RIGHT_ADJUST 1

#define AVCC 0
#define AREF_TURNED_OFF 1
#define RESERVED 2
#define INTERNAL_3V 3

void ADC_voidInit(void);
u8 ADC_voidStartConversionSynchronous(u8 Copy_u8ADCChannel);
void ADC_voidStartConversionAsynchronous(u8 Copy_u8ADCChannel, void (*NotificationFunction)(u8 *));

#endif