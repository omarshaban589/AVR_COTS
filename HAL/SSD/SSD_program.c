// Library Inclusion
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

// Lower Layer Inclusion
#include "../../MCAL/DIO/DIO_interface.h"

// Self Layer Inclusion

// Self Files Inclusion
#include "SSD_private.h"
#include "SSD_config.h"
#include "SSD_interface.h"

u8 Global_u8ArrayOfNumbers[] = {0b11000000,
                                0b11111001,
                                0b10100100,
                                0b10110000,
                                0b10011001,
                                0b10010010,
                                0b10000010,
                                0b11111000,
                                0b10000000,
                                0b10010000};

void SSD_u8DisplayNumber(u8 Copy_u8PortName, u8 Copy_u8Number, u8 Copy_u8SSDType)
{
    switch (Copy_u8PortName)
    {
    case PORTA:
        DIO_voidSetPortDirection(PORTA, OUTPUT);
        if (Copy_u8SSDType == COMMONANODE)
        {
            DIO_voidSetPortSpecificValue(PORTA, Global_u8ArrayOfNumbers[Copy_u8Number]);
        }
        else if (Copy_u8SSDType == COMMONCATHODE)
        {
            DIO_voidSetPortSpecificValue(PORTA, ~Global_u8ArrayOfNumbers[Copy_u8Number]);
        }
        else
        {
        }
        break;

    case PORTB:
        DIO_voidSetPortDirection(PORTB, OUTPUT);
        if (Copy_u8SSDType == COMMONANODE)
        {
            DIO_voidSetPortSpecificValue(PORTB, Global_u8ArrayOfNumbers[Copy_u8Number]);
        }
        else if (Copy_u8SSDType == COMMONCATHODE)
        {
            DIO_voidSetPortSpecificValue(PORTB, ~Global_u8ArrayOfNumbers[Copy_u8Number]);
        }
        else
        {
        }
        break;

    case PORTC:
        DIO_voidSetPortDirection(PORTC, OUTPUT);
        if (Copy_u8SSDType == COMMONANODE)
        {
            DIO_voidSetPortSpecificValue(PORTC, Global_u8ArrayOfNumbers[Copy_u8Number]);
        }
        else if (Copy_u8SSDType == COMMONCATHODE)
        {
            DIO_voidSetPortSpecificValue(PORTC, ~Global_u8ArrayOfNumbers[Copy_u8Number]);
        }
        else
        {
        }
        break;

    case PORTD:
        DIO_voidSetPortDirection(PORTD, OUTPUT);
        if (Copy_u8SSDType == COMMONANODE)
        {
            DIO_voidSetPortSpecificValue(PORTD, Global_u8ArrayOfNumbers[Copy_u8Number]);
        }
        else if (Copy_u8SSDType == COMMONCATHODE)
        {
            DIO_voidSetPortSpecificValue(PORTD, ~Global_u8ArrayOfNumbers[Copy_u8Number]);
        }
        else
        {
        }
        break;

    default:
        break;
    }
}