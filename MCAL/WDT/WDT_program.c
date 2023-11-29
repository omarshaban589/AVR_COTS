// Library Inclusion
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

// Lower Layer Inclusion

// Self Layer Inclusion

// Self Files Inclusion
#include "../WDT/WDT_config.h"
#include "../WDT/WDT_interface.h"
#include "../WDT/WDT_private.h"

void WDT_voidEnable(void)
{
    SET_BIT(WDTCR, WDTCR_WDE);
}

void WDT_voidSleep(u8 Copy_u8SleepTimer)
{
    WDTCR &= SLEEPTIME_MASK;
    WDTCR |= Copy_u8SleepTimer;
}

void WDT_voidDisabe(void)
{
    WDTCR |= (1 << WDTCR_WDTOE) | (1 << WDTCR_WDE);
    WDTCR = 0;
}