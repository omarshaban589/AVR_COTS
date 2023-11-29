// Library Inclusion
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

// Lower Layer Inclusion
#include "../../MCAL/ADC/ADC_interface.h"

// Self Layer Inclusion

// Self Files Inclusion
#include "LM35_interface.h"
#include "LM35_private.h"
#include "LM35_config.h"

u8 LM35_Temperature = 0;
u8 LM35_u8GetTemperature(u8 Copy_u8Channel)
{
    u8 Local_u8ADCValue = 0;
    u16 Local_u8AnalogVolt = 0;
    u8 Local_u8Temperature = 0;
    Local_u8ADCValue = ADC_voidStartConversionSynchronous(Copy_u8Channel);
    Local_u8AnalogVolt = (u16)(((u32)Local_u8ADCValue * 5000UL) / 256UL);
    Local_u8Temperature = (u8)((u32)Local_u8AnalogVolt / 10UL);

    return Local_u8Temperature;
}

void LM35_Calcs(u8 *Ref_pvReturnTemp)
{
    u16 Local_u8AnalogVolt = 0;
    Local_u8AnalogVolt = (u16)(((u32)(*Ref_pvReturnTemp) * 5000UL) / 256UL);
    LM35_Temperature = (u8)((u32)Local_u8AnalogVolt / 10UL);
}

u8 LM35_u8GetTempWithInterrupt(u8 Copy_u8Channel)
{
    ADC_voidStartConversionAsynchronous(Copy_u8Channel, &LM35_Calcs);
    return LM35_Temperature;
}