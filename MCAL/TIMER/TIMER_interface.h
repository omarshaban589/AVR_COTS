#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H

#define ENABLE 1
#define DISABLE 0

// for TIMER1
#define NORMAL 0
#define PWM_PHASECORRECT_8BIT 1
#define PWM_PHASECORRECT_9BIT 2
#define PWM_PHASECORRECT_10BIT 3
#define CTC_OCR1A 4
#define FASTPWM_8BIT 5
#define FASTPWM_9BIT 6
#define FASTPWM_10BIT 7
#define PWM_PHASEFREQCORRECT_ICR 8
#define PWM_PHASEFREQCORRECT_OCR1A 9
#define PWM_PHASECORRECT_ICR 10
#define PWM_PHASECORRECT_OCR1A 11
#define CTC_ICR 12
#define RESERVED 13
#define FASTPWM_ICR 14
#define FASTPWM_OCR1A 15

#define RISING_EDGE 0
#define FALLING_EDGE 1

// for TIMER0 , TIMER2
#define WAVEFORM_NORMAL 0
#define WAVEFORM_CTC 1
#define WAVEFORM_FASTPWM 2
#define WAVEFORM_PWMPHASECORRECT 3

#define OVF_MODE 0
#define CTC_MODE 1
#define OCA_MODE 2
#define OCB_MODE 3

void TIMER0_voidInit(void);
void TIMER0_voidSetPreloadValue(u8 Copy_u8PreloadValue);
void TIMER0_voidSetOCRMatchValue(u8 Copy_u8OCRMatchValue);
void TIMER0_voidEnableInterrupt(u8 Copy_u8Mode);
void TIMER0_voidDisableInterrupt(u8 Copy_u8Mode);
void TIMER0_voidSetOVFCallBack(void (*pvNotificationFunction)(void));
void TIMER0_voidSetOCCallBack(void (*pvNotificationFunction)(void));
void TIMER0_voidSetBusyWait_OCMode(u32 Copy_u32TimeValue);
void TIMER2_voidInit(void);
void TIMER2_voidSetPreloadValue(u8 Copy_u8PreloadValue);
void TIMER2_voidSetOCRMatchValue(u8 Copy_u8OCRMatchValue);
void TIMER2_voidEnableInterrupt(u8 Copy_u8Mode);
void TIMER2_voidDisableInterrupt(u8 Copy_u8Mode);
void TIMER2_voidSetOVFCallBack(void (*pvNotificationFunction)(void));
void TIMER2_voidSetOCCallBack(void (*pvNotificationFunction)(void));
void TIMER2_voidSetBusyWait_OCMode(u32 Copy_u32TimeValue);
void TIMER1_voidInit(void);
void TIMER1_voidSetPreloadValue(u16 Copy_u16PreloadValue);
void TIMER1_voidSetOCRAMatchValue(u16 Copy_u16OCRMatchValue);
void TIMER1_voidSetOCRBMatchValue(u16 Copy_u16OCRMatchValue);
void TIMER1_voidSetTopValue(u16 Copy_u16TopValue);
void TIMER1_voidICUEnable(void);
void TIMER1_voidICUDisable(void);
void TIMER1_voidEnableInterrupt(u8 Copy_u8Mode);
void TIMER1_voidDisableInterrupt(u8 Copy_u8Mode);
void TIMER1_voidSetOVFCallBack(void (*pvNotificationFunction)(void));
void TIMER1_voidSetOCACallBack(void (*pvNotificationFunction)(void));
void TIMER1_voidSetOCBCallBack(void (*pvNotificationFunction)(void));
void TIMER1_voidSetICUCallBack(void (*pvNotificationFunction)(void));
void TIMER1_voidICUMode(u8 Copy_u8Mode);
u16 TIMER1_voidGetICRValue(void);
u16 TIMER1_voidGetTCNT1Value(void);
u8 TIMER0_voidGetTCNT0Value(void);

#endif
