// Library Inclusion
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

// Lower Layer Inclusion

// Self Layer Inclusion

// Self Files Inclusion
#include "../TIMER/TIMER_config.h"
#include "../TIMER/TIMER_interface.h"
#include "../TIMER/TIMER_private.h"

// ***************************************************** TIMER 0 **********************************************************
void TIMER0_voidInit(void)
{
#if (TIMER0_ENABLE == ENABLE)
// WaveForm Selection
#if (TIMER0_WAVEFORM == WAVEFORM_NORMAL)
    CLR_BIT(TIMER_TCCR0, TCCR0_WGM00);
    CLR_BIT(TIMER_TCCR0, TCCR0_WGM01);
#elif (TIMER0_WAVEFORM == WAVEFORM_CTC)
    CLR_BIT(TIMER_TCCR0, TCCR0_WGM00);
    SET_BIT(TIMER_TCCR0, TCCR0_WGM01);
#elif (TIMER0_WAVEFORM == WAVEFORM_FASTPWM)
    SET_BIT(TIMER_TCCR0, TCCR0_WGM00);
    SET_BIT(TIMER_TCCR0, TCCR0_WGM01);
#elif (TIMER0_WAVEFORM == WAVEFORM_PWMPHASECORRECT)
    SET_BIT(TIMER_TCCR0, TCCR0_WGM00);
    CLR_BIT(TIMER_TCCR0, TCCR0_WGM01);
#else
//
#endif

    // Preslacer Selection
    TIMER_TCCR0 &= TIMER_PRESACLING_MASK;
    TIMER_TCCR0 |= TIMER0_PRESCALER;

    // OC0 Control Behavior
    TIMER_TCCR0 &= TIMER_OCX_CONTROL_MASK;
    TIMER_TCCR0 |= TIMER0_OC0_BEHAVIOR;

#if (TIMER0_WAVEFORM == WAVEFORM_NORMAL)
    CLR_BIT(TIMER_TCCR0, TCCR0_COM00);
    CLR_BIT(TIMER_TCCR0, TCCR0_COM01);
#endif

#else
//
#endif
}

void TIMER0_voidSetPreloadValue(u8 Copy_u8PreloadValue)
{
    TIMER_TCNT0 = Copy_u8PreloadValue;
}

void TIMER0_voidSetOCRMatchValue(u8 Copy_u8OCRMatchValue)
{
    TIMER_OCR0 = Copy_u8OCRMatchValue;
}

void TIMER0_voidEnableInterrupt(u8 Copy_u8Mode)
{
    switch (Copy_u8Mode)
    {
    case OVF_MODE:
        SET_BIT(TIMER_TIMSK, TIMSK_TOIE0);
        break;
    case CTC_MODE:
        SET_BIT(TIMER_TIMSK, TIMSK_OCIE0);
        break;

    default:
        break;
    }
}

void TIMER0_voidDisableInterrupt(u8 Copy_u8Mode)
{
    switch (Copy_u8Mode)
    {
    case OVF_MODE:
        CLR_BIT(TIMER_TIMSK, TIMSK_TOIE0);
        break;
    case CTC_MODE:
        CLR_BIT(TIMER_TIMSK, TIMSK_OCIE0);
        break;

    default:
        break;
    }
}

static void (*T0NotificationOVFFunction)(void) = NULL;
static void (*T0NotificationOCFunction)(void) = NULL;

void TIMER0_voidSetOVFCallBack(void (*pvNotificationFunction)(void))
{
    T0NotificationOVFFunction = pvNotificationFunction;
}

void TIMER0_voidSetOCCallBack(void (*pvNotificationFunction)(void))
{
    T0NotificationOCFunction = pvNotificationFunction;
}

void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
    if (T0NotificationOVFFunction != NULL)
    {
        T0NotificationOVFFunction();
    }
    else
    {
    }
}

void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
    if (T0NotificationOCFunction != NULL)
    {
        T0NotificationOCFunction();
    }
    else
    {
    }
}

void TIMER0_voidSetBusyWait_OCMode(u32 Copy_u32TimeValue)
{
    u8 Local_u8Counter = 0;

    CLR_BIT(TIMER_TCCR0, TCCR0_WGM00);
    SET_BIT(TIMER_TCCR0, TCCR0_WGM01);

    CLR_BIT(TIMER_TCCR0, TCCR0_CS00);
    CLR_BIT(TIMER_TCCR0, TCCR0_CS01);
    SET_BIT(TIMER_TCCR0, TCCR0_CS02);

    TIMER0_voidSetOCRMatchValue(125);
    for (Local_u8Counter = 0; Local_u8Counter < Copy_u32TimeValue; Local_u8Counter++)
    {
        while (GET_BIT(TIMER_TIFR, TIFR_OCF0) == 0)
            ;
        SET_BIT(TIMER_TIFR, TIFR_OCF2);
    }
}

// ***************************************************** TIMER 2 **********************************************************
void TIMER2_voidInit(void)
{
#if (TIMER2_ENABLE == ENABLE)
// WaveForm Selection
#if (TIMER2_WAVEFORM == WAVEFORM_NORMAL)
    CLR_BIT(TIMER_TCCR2, TCCR2_WGM20);
    CLR_BIT(TIMER_TCCR2, TCCR2_WGM21);
#elif (TIMER2_WAVEFORM == WAVEFORM_CTC)
    CLR_BIT(TIMER_TCCR2, TCCR2_WGM20);
    SET_BIT(TIMER_TCCR2, TCCR2_WGM21);
#elif (TIMER2_WAVEFORM == WAVEFORM_FASTPWM)
    SET_BIT(TIMER_TCCR2, TCCR2_WGM20);
    SET_BIT(TIMER_TCCR2, TCCR2_WGM21);
#elif (TIMER2_WAVEFORM == WAVEFORM_PWMPHASECORRECT)
    SET_BIT(TIMER_TCCR2, TCCR2_WGM20);
    CLR_BIT(TIMER_TCCR2, TCCR2_WGM21);
#else
//
#endif

    // Preslacer Selection
    TIMER_TCCR2 &= TIMER_PRESACLING_MASK;
    TIMER_TCCR2 |= TIMER2_PRESCALER;

    // OC0 Control Behavior
    TIMER_TCCR2 &= TIMER_OCX_CONTROL_MASK;
    TIMER_TCCR2 |= TIMER2_OC2_BEHAVIOR;

#if (TIMER2_WAVEFORM == WAVEFORM_NORMAL)
    CLR_BIT(TIMER_TCCR2, TCCR2_COM20);
    CLR_BIT(TIMER_TCCR2, TCCR2_COM21);
#endif

#else
//
#endif
}

void TIMER2_voidSetPreloadValue(u8 Copy_u8PreloadValue)
{
    TIMER_TCNT2 = Copy_u8PreloadValue;
}

void TIMER2_voidSetOCRMatchValue(u8 Copy_u8OCRMatchValue)
{
    TIMER_OCR2 = Copy_u8OCRMatchValue;
}

void TIMER2_voidEnableInterrupt(u8 Copy_u8Mode)
{
    switch (Copy_u8Mode)
    {
    case OVF_MODE:
        SET_BIT(TIMER_TIMSK, TIMSK_TOIE2);
        break;
    case CTC_MODE:
        SET_BIT(TIMER_TIMSK, TIMSK_OCIE2);
        break;

    default:
        break;
    }
}

void TIMER2_voidDisableInterrupt(u8 Copy_u8Mode)
{
    switch (Copy_u8Mode)
    {
    case OVF_MODE:
        CLR_BIT(TIMER_TIMSK, TIMSK_TOIE2);
        break;
    case CTC_MODE:
        CLR_BIT(TIMER_TIMSK, TIMSK_OCIE2);
        break;

    default:
        break;
    }
}

static void (*T2NotificationOVFFunction)(void) = NULL;
static void (*T2NotificationOCFunction)(void) = NULL;

void TIMER2_voidSetOVFCallBack(void (*pvNotificationFunction)(void))
{
    T2NotificationOVFFunction = pvNotificationFunction;
}

void TIMER2_voidSetOCCallBack(void (*pvNotificationFunction)(void))
{
    T2NotificationOCFunction = pvNotificationFunction;
}

void __vector_5(void) __attribute__((signal));
void __vector_5(void)
{
    if (T2NotificationOVFFunction != NULL)
    {
        T2NotificationOVFFunction();
    }
    else
    {
    }
}

void __vector_4(void) __attribute__((signal));
void __vector_4(void)
{
    if (T2NotificationOCFunction != NULL)
    {
        T2NotificationOCFunction();
    }
    else
    {
    }
}

void TIMER2_voidSetBusyWait_OCMode(u32 Copy_u32TimeValue)
{
    u8 Local_u8Counter = 0;

    // ctc mode
    CLR_BIT(TIMER_TCCR2, TCCR2_WGM20);
    SET_BIT(TIMER_TCCR2, TCCR2_WGM21);
    // 64 prescaler
    CLR_BIT(TIMER_TCCR2, TCCR2_CS20);
    CLR_BIT(TIMER_TCCR2, TCCR2_CS21);
    SET_BIT(TIMER_TCCR2, TCCR2_CS22);

    TIMER2_voidSetOCRMatchValue(125);
    for (Local_u8Counter = 0; Local_u8Counter < Copy_u32TimeValue; Local_u8Counter++)
    {
        while (GET_BIT(TIMER_TIFR, TIFR_OCF2) == 0)
            ;
        SET_BIT(TIMER_TIFR, TIFR_OCF2);
    }
}

// ***************************************************** TIMER 1 **********************************************************
void TIMER1_voidInit(void)
{
// TIMER1 MODE SELECTION
#if (TIMER1_WAVEFORM == NORMAL)
    CLR_BIT(TIMER_TCCR1A, TCCR1A_WGM10);
    CLR_BIT(TIMER_TCCR1A, TCCR1A_WGM11);
    CLR_BIT(TIMER_TCCR1B, TCCR1B_WGM12);
    CLR_BIT(TIMER_TCCR1B, TCCR1B_WGM13);
#elif (TIMER1_WAVEFORM == PWM_PHASECORRECT_8BIT)
    SET_BIT(TIMER_TCCR1A, TCCR1A_WGM10);
    CLR_BIT(TIMER_TCCR1A, TCCR1A_WGM11);
    CLR_BIT(TIMER_TCCR1B, TCCR1B_WGM12);
    CLR_BIT(TIMER_TCCR1B, TCCR1B_WGM13);
#elif (TIMER1_WAVEFORM == PWM_PHASECORRECT_9BIT)
    CLR_BIT(TIMER_TCCR1A, TCCR1A_WGM10);
    SET_BIT(TIMER_TCCR1A, TCCR1A_WGM11);
    CLR_BIT(TIMER_TCCR1B, TCCR1B_WGM12);
    CLR_BIT(TIMER_TCCR1B, TCCR1B_WGM13);
#elif (TIMER1_WAVEFORM == PWM_PHASECORRECT_10BIT)
    SET_BIT(TIMER_TCCR1A, TCCR1A_WGM10);
    SET_BIT(TIMER_TCCR1A, TCCR1A_WGM11);
    CLR_BIT(TIMER_TCCR1B, TCCR1B_WGM12);
    CLR_BIT(TIMER_TCCR1B, TCCR1B_WGM13);
#elif (TIMER1_WAVEFORM == CTC_OCR1A)
    CLR_BIT(TIMER_TCCR1A, TCCR1A_WGM10);
    CLR_BIT(TIMER_TCCR1A, TCCR1A_WGM11);
    SET_BIT(TIMER_TCCR1B, TCCR1B_WGM12);
    CLR_BIT(TIMER_TCCR1B, TCCR1B_WGM13);
#elif (TIMER1_WAVEFORM == FASTPWM_8BIT)
    SET_BIT(TIMER_TCCR1A, TCCR1A_WGM10);
    CLR_BIT(TIMER_TCCR1A, TCCR1A_WGM11);
    SET_BIT(TIMER_TCCR1B, TCCR1B_WGM12);
    CLR_BIT(TIMER_TCCR1B, TCCR1B_WGM13);
#elif (TIMER1_WAVEFORM == FASTPWM_9BIT)
    CLR_BIT(TIMER_TCCR1A, TCCR1A_WGM10);
    SET_BIT(TIMER_TCCR1A, TCCR1A_WGM11);
    SET_BIT(TIMER_TCCR1B, TCCR1B_WGM12);
    CLR_BIT(TIMER_TCCR1B, TCCR1B_WGM13);
#elif (TIMER1_WAVEFORM == FASTPWM_10BIT)
    SET_BIT(TIMER_TCCR1A, TCCR1A_WGM10);
    SET_BIT(TIMER_TCCR1A, TCCR1A_WGM11);
    SET_BIT(TIMER_TCCR1B, TCCR1B_WGM12);
    CLR_BIT(TIMER_TCCR1B, TCCR1B_WGM13);
#elif (TIMER1_WAVEFORM == PWM_PHASEFREQCORRECT_ICR)
    CLR_BIT(TIMER_TCCR1A, TCCR1A_WGM10);
    CLR_BIT(TIMER_TCCR1A, TCCR1A_WGM11);
    CLR_BIT(TIMER_TCCR1B, TCCR1B_WGM12);
    SET_BIT(TIMER_TCCR1B, TCCR1B_WGM13);
#elif (TIMER1_WAVEFORM == PWM_PHASEFREQCORRECT_OCR1A)
    SET_BIT(TIMER_TCCR1A, TCCR1A_WGM10);
    CLR_BIT(TIMER_TCCR1A, TCCR1A_WGM11);
    CLR_BIT(TIMER_TCCR1B, TCCR1B_WGM12);
    SET_BIT(TIMER_TCCR1B, TCCR1B_WGM13);
#elif (TIMER1_WAVEFORM == PWM_PHASECORRECT_ICR)
    CLR_BIT(TIMER_TCCR1A, TCCR1A_WGM10);
    SET_BIT(TIMER_TCCR1A, TCCR1A_WGM11);
    CLR_BIT(TIMER_TCCR1B, TCCR1B_WGM12);
    SET_BIT(TIMER_TCCR1B, TCCR1B_WGM13);
#elif (TIMER1_WAVEFORM == PWM_PHASECORRECT_OCR1A)
    SET_BIT(TIMER_TCCR1A, TCCR1A_WGM10);
    SET_BIT(TIMER_TCCR1A, TCCR1A_WGM11);
    CLR_BIT(TIMER_TCCR1B, TCCR1B_WGM12);
    SET_BIT(TIMER_TCCR1B, TCCR1B_WGM13);
#elif (TIMER1_WAVEFORM == CTC_ICR)
    CLR_BIT(TIMER_TCCR1A, TCCR1A_WGM10);
    CLR_BIT(TIMER_TCCR1A, TCCR1A_WGM11);
    SET_BIT(TIMER_TCCR1B, TCCR1B_WGM12);
    SET_BIT(TIMER_TCCR1B, TCCR1B_WGM13);
#elif (TIMER1_WAVEFORM == RESERVED)
    SET_BIT(TIMER_TCCR1A, TCCR1A_WGM10);
    CLR_BIT(TIMER_TCCR1A, TCCR1A_WGM11);
    SET_BIT(TIMER_TCCR1B, TCCR1B_WGM12);
    SET_BIT(TIMER_TCCR1B, TCCR1B_WGM13);
#elif (TIMER1_WAVEFORM == FASTPWM_ICR)
    CLR_BIT(TIMER_TCCR1A, TCCR1A_WGM10);
    SET_BIT(TIMER_TCCR1A, TCCR1A_WGM11);
    SET_BIT(TIMER_TCCR1B, TCCR1B_WGM12);
    SET_BIT(TIMER_TCCR1B, TCCR1B_WGM13);
#elif (TIMER1_WAVEFORM == FASTPWM_OCR1A)
    SET_BIT(TIMER_TCCR1A, TCCR1A_WGM10);
    SET_BIT(TIMER_TCCR1A, TCCR1A_WGM11);
    SET_BIT(TIMER_TCCR1B, TCCR1B_WGM12);
    SET_BIT(TIMER_TCCR1B, TCCR1B_WGM13);
#else
//
#endif

    // TIMER1 PRESCALER SELECTION
    TIMER_TCCR1B &= TIMER_PRESACLING_MASK;
    TIMER_TCCR1B |= TIMER1_PRESCALER;

    // OC1A Control
    TIMER_TCCR1A &= TIMER_OC1A_CONTROL_MASK;
    TIMER_TCCR1A |= TIMER1_OC1A_BEHAVIOR;

    // OC1B Control
    TIMER_TCCR1A &= TIMER_OC1B_CONTROL_MASK;
    TIMER_TCCR1A |= TIMER1_OC1B_BEHAVIOR;
}

void TIMER1_voidSetPreloadValue(u16 Copy_u16PreloadValue)
{
    TIMER_TCNT1 = Copy_u16PreloadValue;
}

void TIMER1_voidSetOCRAMatchValue(u16 Copy_u16OCRMatchValue)
{
    TIMER_OCR1A = Copy_u16OCRMatchValue;
}

void TIMER1_voidSetOCRBMatchValue(u16 Copy_u16OCRMatchValue)
{
    TIMER_OCR1B = Copy_u16OCRMatchValue;
}

void TIMER1_voidSetTopValue(u16 Copy_u16TopValue)
{
    TIMER_ICR1 = Copy_u16TopValue;
}

void TIMER1_voidICUEnable(void)
{
    SET_BIT(TIMER_TIMSK, TIMSK_TICIE1);
}

void TIMER1_voidICUDisable(void)
{
    CLR_BIT(TIMER_TIMSK, TIMSK_TICIE1);
}

void TIMER1_voidICUMode(u8 Copy_u8Mode)
{
    switch (Copy_u8Mode)
    {
    case RISING_EDGE:
        SET_BIT(TIMER_TCCR1B, TCCR1B_ICES1);
        break;
    case FALLING_EDGE:
        CLR_BIT(TIMER_TCCR1B, TCCR1B_ICES1);
        break;

    default:
        break;
    }
}

void TIMER1_voidEnableInterrupt(u8 Copy_u8Mode)
{
    switch (Copy_u8Mode)
    {
    case OVF_MODE:
        SET_BIT(TIMER_TIMSK, TIMSK_TOIE1);
        break;
    case OCA_MODE:
        SET_BIT(TIMER_TIMSK, TIMSK_OCIE1A);
        break;
    case OCB_MODE:
        SET_BIT(TIMER_TIMSK, TIMSK_OCIE1B);
        break;

    default:
        break;
    }
}

void TIMER1_voidDisableInterrupt(u8 Copy_u8Mode)
{
    switch (Copy_u8Mode)
    {
    case OVF_MODE:
        CLR_BIT(TIMER_TIMSK, TIMSK_TOIE1);
        break;
    case OCA_MODE:
        CLR_BIT(TIMER_TIMSK, TIMSK_OCIE1A);
        break;
    case OCB_MODE:
        CLR_BIT(TIMER_TIMSK, TIMSK_OCIE1B);
        break;

    default:
        break;
    }
}

static void (*T1NotificationOVFFunction)(void) = NULL;
static void (*T1NotificationOCAFunction)(void) = NULL;
static void (*T1NotificationICUFunction)(void) = NULL;
static void (*T1NotificationOCBFunction)(void) = NULL;

void TIMER1_voidSetOVFCallBack(void (*pvNotificationFunction)(void))
{
    T1NotificationOVFFunction = pvNotificationFunction;
}

void TIMER1_voidSetOCACallBack(void (*pvNotificationFunction)(void))
{
    T1NotificationOCAFunction = pvNotificationFunction;
}

void TIMER1_voidSetOCBCallBack(void (*pvNotificationFunction)(void))
{
    T1NotificationOCBFunction = pvNotificationFunction;
}

void TIMER1_voidSetICUCallBack(void (*pvNotificationFunction)(void))
{
    T1NotificationICUFunction = pvNotificationFunction;
}

void __vector_6(void) __attribute__((signal));
void __vector_6(void)
{
    if (T1NotificationICUFunction != NULL)
    {
        T1NotificationICUFunction();
    }
    else
    {
    }
}

void __vector_7(void) __attribute__((signal));
void __vector_7(void)
{
    if (T1NotificationOCAFunction != NULL)
    {
        T1NotificationOCAFunction();
    }
    else
    {
    }
}

void __vector_8(void) __attribute__((signal));
void __vector_8(void)
{
    if (T1NotificationOCBFunction != NULL)
    {
        T1NotificationOCBFunction();
    }
    else
    {
    }
}

void __vector_9(void) __attribute__((signal));
void __vector_9(void)
{
    if (T1NotificationOVFFunction != NULL)
    {
        T1NotificationOVFFunction();
    }
    else
    {
    }
}

u16 TIMER1_voidGetICRValue(void)
{
    return TIMER_ICR1;
}

u16 TIMER1_voidGetTCNT1Value(void)
{
    return TIMER_TCNT1;
}

u8 TIMER0_voidGetTCNT0Value(void)
{
    return TIMER_TCNT0;
}
