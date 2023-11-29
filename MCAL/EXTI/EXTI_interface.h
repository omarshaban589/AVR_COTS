#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

#define INT0 0
#define INT1 1
#define INT2 2

#define ENABLE 1
#define DISABLE 0

#define LOW_LEVEL 0
#define ON_CHANGE 1
#define FALLING_EDGE 2
#define RISING_EDGE 3

void EXTI_voidInt0Init(void);
void EXTI_voidInt1Init(void);
void EXTI_voidInt2Init(void);
void EXTI_voidInt0SetCallBack(void (*Ref_pvInt0Function)(void));
void EXTI_voidInt1SetCallBack(void (*Ref_pvInt1Function)(void));
void EXTI_voidSetInterruptSettings(u8 Copy_u8IntChannel, u8 Copy_u8IntState);
void EXTI_voidInterruptDisapled(u8 Copy_u8IntChannel);

#endif