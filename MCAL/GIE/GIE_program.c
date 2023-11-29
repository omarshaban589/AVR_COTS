// Library Inclusion
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

// Lower Layer Inclusion

// Self Layer Inclusion

// Self Files Inclusion
#include "GIE_private.h"
#include "GIE_interface.h"
#include "GIE_config.h"

void GIE_voidEnable(void)
{
    SET_BIT(SREG, SREG_BIT);
}

void GIE_voidDisable(void)
{
    CLR_BIT(SREG, SREG_BIT);
}