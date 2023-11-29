// Library Inclusion
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

// Lower Layer Inclusion

// Self Layer Inclusion

// Self Files Inclusion
#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"

void ADC_voidInit(void)
{
    /*Prescaller*/
    ADCSRA &= ADC_PRESCALER_MASK;
    ADCSRA |= ADC_PRESCALER_SELECTION;

/*Adjustment*/
#if (ADC_ADJUSTMENT == ADC_LEFT_ADJUST)
    SET_BIT(ADMUX, ADMUX_ADLAR);
#elif (ADC_ADJUSTMENT == ADC_RIGHT_ADJUST)
    CLR_BIT(ADMUX, ADMUX_ADLAR);
#else
// error
#endif

/*Reference Volt*/
#if (ADC_VREF == AREF_TURNED_OFF)
    CLR_BIT(ADMUX, ADMUX_REFS0);
    CLR_BIT(ADMUX, ADMUX_REFS1);
#elif (ADC_VREF == AVCC)
    SET_BIT(ADMUX, ADMUX_REFS0);
    CLR_BIT(ADMUX, ADMUX_REFS1);
#elif (ADC_VREF == RESERVED)
    CLR_BIT(ADMUX, ADMUX_REFS0);
    SET_BIT(ADMUX, ADMUX_REFS1);
#elif (ADC_VREF == INTERNAL_3V)
    SET_BIT(ADMUX, ADMUX_REFS0);
    SET_BIT(ADMUX, ADMUX_REFS1);
#else
// error
#endif

    /*Enable*/
    SET_BIT(ADCSRA, ADCSRA_ADEN);
}

u8 ADC_voidStartConversionSynchronous(u8 Copy_u8ADCChannel)
{
    /*Choose ADC Channel*/
    ADMUX &= ADC_CHANNEL_MASK;
    ADMUX |= Copy_u8ADCChannel;

    /*Trigger the ADC*/
    SET_BIT(ADCSRA, ADCSRA_ADSC);

    /*Polling (busy wait) till ADC Ends Its Converstion*/
    while (GET_BIT(ADCSRA, ADCSRA_ADIF) == 0)
        ;

    /*Clear Flag*/
    SET_BIT(ADCSRA, ADCSRA_ADIF);

#if (ADC_ADJUSTMENT == ADC_LEFT_ADJUST)
    return ADCH;
#elif (ADC_ADJUSTMENT == ADC_RIGHT_ADJUST)
    return ADCL;
#else
//
#endif
}

u8 ADC_Result = 0;

static void (*ADC_NotificationFunction)(u8 *) = NULL;
void ADC_voidStartConversionAsynchronous(u8 Copy_u8ADCChannel, void (*NotificationFunction)(u8 *))
{
    ADC_NotificationFunction = NotificationFunction;
    /*Choose ADC Channel*/
    ADMUX &= ADC_CHANNEL_MASK;
    ADMUX |= Copy_u8ADCChannel;
    /*Enable PIE*/
    SET_BIT(ADCSRA, ADCSRA_ADIE);
    /*Trigger the ADC*/
    SET_BIT(ADCSRA, ADCSRA_ADSC);
}

void __vector_16(void) __attribute__((signal));
void __vector_16(void)
{
    if (ADC_NotificationFunction != NULL)
    {
        ADC_Result = ADCH;
        ADC_NotificationFunction(&ADC_Result);
    }
    else
    {
    }
}
