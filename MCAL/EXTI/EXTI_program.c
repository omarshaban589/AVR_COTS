// Library Inclusion
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

// Lower Layer Inclusion

// Self Layer Inclusion

// Self Files Inclusion
#include "EXTI_private.h"
#include "EXTI_interface.h"
#include "EXTI_config.h"

// Pointers To Functions To Use Them In ISR
static void (*EXTI_pvINT0Function)(void) = NULL_POINTER;
static void (*EXTI_pvINT1Function)(void) = NULL_POINTER;

void EXTI_voidInt0Init(void)
{
// PIE
#if (INT0_ENABLE == ENABLE)
    SET_BIT(EXTI_GICR, GICR_INT0_ENABLE);
    // State
#if (INT0_STATE == LOW_LEVEL)
    CLR_BIT(EXTI_MCUCR, MUCUCR_INT0_ISC00);
    CLR_BIT(EXTI_MCUCR, MUCUCR_INT0_ISC01);
#elif (INT0_STATE == ON_CHANGE)
    SET_BIT(EXTI_MCUCR, MUCUCR_INT0_ISC00);
    CLR_BIT(EXTI_MCUCR, MUCUCR_INT0_ISC01);
#elif (INT0_STATE == FALLING_EDGE)
    CLR_BIT(EXTI_MCUCR, MUCUCR_INT0_ISC00);
    SET_BIT(EXTI_MCUCR, MUCUCR_INT0_ISC01);
#elif (INT0_STATE == RISING_EDGE)
    SET_BIT(EXTI_MCUCR, MUCUCR_INT0_ISC00);
    SET_BIT(EXTI_MCUCR, MUCUCR_INT0_ISC01);
#else
// error
#endif

#elif (INT0_ENABLE == DISABLE)
    CLR_BIT(EXTI_GICR, GICR_INT0_ENABLE);
#else
// error
#endif
}

void EXTI_voidInt1Init(void)
{

// PIE
#if (INT1_ENABLE == ENABLE)
    SET_BIT(EXTI_GICR, GICR_INT1_ENABLE);
    // State
#if (INT0_STATE == LOW_LEVEL)
    CLR_BIT(EXTI_MCUCR, MUCUCR_INT1_ISC10);
    CLR_BIT(EXTI_MCUCR, MUCUCR_INT1_ISC11);
#elif (INT0_STATE == ON_CHANGE)
    SET_BIT(EXTI_MCUCR, MUCUCR_INT1_ISC10);
    CLR_BIT(EXTI_MCUCR, MUCUCR_INT1_ISC11);
#elif (INT0_STATE == FALLING_EDGE)
    CLR_BIT(EXTI_MCUCR, MUCUCR_INT1_ISC10);
    SET_BIT(EXTI_MCUCR, MUCUCR_INT1_ISC11);
#elif (INT0_STATE == RISING_EDGE)
    SET_BIT(EXTI_MCUCR, MUCUCR_INT1_ISC10);
    SET_BIT(EXTI_MCUCR, MUCUCR_INT1_ISC11);
#else
// error
#endif

#elif (INT1_ENABLE == DISABLE)
    CLR_BIT(EXTI_GICR, GICR_INT1_ENABLE);
#else
// error
#endif
}

void EXTI_voidInt2Init(void)
{

// PIE
#if (INT2_ENABLE == ENABLE)
    SET_BIT(EXTI_GICR, GICR_INT2_ENABLE);
#if (INT2_STATE == FALLING_EDGE)
    CLR_BIT(EXTI_MUCUCSR, MUCUCR_ISC2);
#elif (INT2_STATE == RISING_EDGE)
    SET_BIT(EXTI_MUCUCSR, MUCUCR_ISC2);
#else
// error
#endif
#elif (INT2_ENABLE == DISABLE)
    CLR_BIT(EXTI_GICR, GICR_INT2_ENABLE);
#else
// error
#endif
}

void EXTI_voidInt0SetCallBack(void (*Ref_pvInt0Function)(void))
{
    EXTI_pvINT0Function = Ref_pvInt0Function;
}

void EXTI_voidInt1SetCallBack(void (*Ref_pvInt1Function)(void))
{
    EXTI_pvINT1Function = Ref_pvInt1Function;
}

// ISR For INT0
void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
    if (EXTI_pvINT0Function != NULL_POINTER)
    {
        EXTI_pvINT0Function();
    }
    else
    {
    }
}

void EXTI_voidSetInterruptSettings(u8 Copy_u8IntChannel, u8 Copy_u8IntState)
{

    switch (Copy_u8IntChannel)
    {
    case INT0:
        SET_BIT(EXTI_GICR, GICR_INT0_ENABLE);
        switch (Copy_u8IntState)
        {
        case LOW_LEVEL:
            CLR_BIT(EXTI_MCUCR, MUCUCR_INT0_ISC00);
            CLR_BIT(EXTI_MCUCR, MUCUCR_INT0_ISC01);
            break;
        case ON_CHANGE:
            SET_BIT(EXTI_MCUCR, MUCUCR_INT0_ISC00);
            CLR_BIT(EXTI_MCUCR, MUCUCR_INT0_ISC01);
            break;
        case FALLING_EDGE:
            CLR_BIT(EXTI_MCUCR, MUCUCR_INT0_ISC00);
            SET_BIT(EXTI_MCUCR, MUCUCR_INT0_ISC01);
            break;
        case RISING_EDGE:
            SET_BIT(EXTI_MCUCR, MUCUCR_INT0_ISC00);
            SET_BIT(EXTI_MCUCR, MUCUCR_INT0_ISC01);
            break;
        default:
            break;
        }
        break;

    case INT1:
        SET_BIT(EXTI_GICR, GICR_INT1_ENABLE);
        switch (Copy_u8IntState)
        {
        case LOW_LEVEL:
            CLR_BIT(EXTI_MCUCR, MUCUCR_INT1_ISC10);
            CLR_BIT(EXTI_MCUCR, MUCUCR_INT1_ISC11);
            break;
        case ON_CHANGE:
            SET_BIT(EXTI_MCUCR, MUCUCR_INT1_ISC10);
            CLR_BIT(EXTI_MCUCR, MUCUCR_INT1_ISC11);
            break;
        case FALLING_EDGE:
            CLR_BIT(EXTI_MCUCR, MUCUCR_INT1_ISC10);
            SET_BIT(EXTI_MCUCR, MUCUCR_INT1_ISC11);
            break;
        case RISING_EDGE:
            SET_BIT(EXTI_MCUCR, MUCUCR_INT1_ISC10);
            SET_BIT(EXTI_MCUCR, MUCUCR_INT1_ISC11);
            break;
        default:
            break;
        }
        break;

    case INT2:
        SET_BIT(EXTI_GICR, GICR_INT2_ENABLE);
        switch (Copy_u8IntState)
        {
        case FALLING_EDGE:
            CLR_BIT(EXTI_MUCUCSR, MUCUCR_ISC2);
            break;
        case RISING_EDGE:
            SET_BIT(EXTI_MUCUCSR, MUCUCR_ISC2);
            break;
        }
        break;

    default:
        break;
    }
}

void EXTI_voidInterruptDisapled(u8 Copy_u8IntChannel)
{
    switch (Copy_u8IntChannel)
    {
    case INT0:
        CLR_BIT(EXTI_GICR, GICR_INT0_ENABLE);
        break;
    case INT1:
        CLR_BIT(EXTI_GICR, GICR_INT1_ENABLE);
        break;
    case INT2:
        CLR_BIT(EXTI_GICR, GICR_INT2_ENABLE);
        break;

    default:
        break;
    }
}