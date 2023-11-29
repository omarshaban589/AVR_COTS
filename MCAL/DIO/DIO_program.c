// Library Inclusion
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

// Lower Layer Inclusion

// Self Layer Inclusion

// Self Files Inclusion
#include "DIO_private.h"
#include "DIO_interface.h"
#include "DIO_config.h"

void DIO_voidSetPinDirection(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinDirection)
{
    if (Copy_u8PortName <= PORTD &&
        Copy_u8PinNumber <= PIN7 &&
        Copy_u8PinDirection <= OUTPUT)
    {
        switch (Copy_u8PortName)
        {
        case PORTA:
            if (Copy_u8PinDirection == INPUT)
            {
                CLR_BIT(DIO_DDRA, Copy_u8PinNumber);
            }
            else if (Copy_u8PinDirection == OUTPUT)
            {
                SET_BIT(DIO_DDRA, Copy_u8PinNumber);
            }
            else
            {
                // Do Nothing
            }
            break;

        case PORTB:
            if (Copy_u8PinDirection == INPUT)
            {
                CLR_BIT(DIO_DDRB, Copy_u8PinNumber);
            }
            else if (Copy_u8PinDirection == OUTPUT)
            {
                SET_BIT(DIO_DDRB, Copy_u8PinNumber);
            }
            else
            {
                // Do Nothing
            }
            break;

        case PORTC:
            if (Copy_u8PinDirection == INPUT)
            {
                CLR_BIT(DIO_DDRC, Copy_u8PinNumber);
            }
            else if (Copy_u8PinDirection == OUTPUT)
            {
                SET_BIT(DIO_DDRC, Copy_u8PinNumber);
            }
            else
            {
                // Do Nothing
            }
            break;

        case PORTD:
            if (Copy_u8PinDirection == INPUT)
            {
                CLR_BIT(DIO_DDRD, Copy_u8PinNumber);
            }
            else if (Copy_u8PinDirection == OUTPUT)
            {
                SET_BIT(DIO_DDRD, Copy_u8PinNumber);
            }
            else
            {
                // Do Nothing
            }
            break;

        default:
            // Do Nothing
            break;
        }
    }
    else
    {
        // Raise An Error
    }
}

void DIO_voidSetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinValue)
{
    switch (Copy_u8PortName)
    {
    case PORTA:
        switch (Copy_u8PinValue)
        {
        case LOW:
            CLR_BIT(DIO_PORTA, Copy_u8PinNumber);
            break;

        case HIGH:
            SET_BIT(DIO_PORTA, Copy_u8PinNumber);
            break;

        default:
            break;
        }
        break;

    case PORTB:
        switch (Copy_u8PinValue)
        {
        case LOW:
            CLR_BIT(DIO_PORTB, Copy_u8PinNumber);
            break;

        case HIGH:
            SET_BIT(DIO_PORTB, Copy_u8PinNumber);
            break;

        default:
            break;
        }
        break;

    case PORTC:
        switch (Copy_u8PinValue)
        {
        case LOW:
            CLR_BIT(DIO_PORTC, Copy_u8PinNumber);
            break;

        case HIGH:
            SET_BIT(DIO_PORTC, Copy_u8PinNumber);
            break;

        default:
            break;
        }
        break;

    case PORTD:
        switch (Copy_u8PinValue)
        {
        case LOW:
            CLR_BIT(DIO_PORTD, Copy_u8PinNumber);
            break;

        case HIGH:
            SET_BIT(DIO_PORTD, Copy_u8PinNumber);
            break;

        default:
            break;
        }
        break;

    default:
        break;
    }
}

void DIO_voidSetPinPullUp(u8 Copy_u8PortName, u8 Copy_u8PinNumber)
{
    switch (Copy_u8PortName)
    {
    case PORTA:
        CLR_BIT(DIO_DDRA, Copy_u8PinNumber);
        SET_BIT(DIO_PORTA, Copy_u8PinNumber);
        break;

    case PORTB:
        CLR_BIT(DIO_DDRB, Copy_u8PinNumber);
        SET_BIT(DIO_PORTB, Copy_u8PinNumber);
        break;

    case PORTC:
        CLR_BIT(DIO_DDRC, Copy_u8PinNumber);
        SET_BIT(DIO_PORTC, Copy_u8PinNumber);
        break;

    case PORTD:
        CLR_BIT(DIO_DDRD, Copy_u8PinNumber);
        SET_BIT(DIO_PORTD, Copy_u8PinNumber);
        break;

    default:
        break;
    }
}

u8 DIO_u8GetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber)
{
    u8 value = LOW;
    switch (Copy_u8PortName)
    {
    case PORTA:
        if (GET_BIT(DIO_PINA, Copy_u8PinNumber) == 1)
        {
            value = HIGH;
        }
        break;

    case PORTB:
        if (GET_BIT(DIO_PINB, Copy_u8PinNumber) == 1)
        {
            value = HIGH;
        }
        break;

    case PORTC:
        if (GET_BIT(DIO_PINC, Copy_u8PinNumber) == 1)
        {
            value = HIGH;
        }
        break;

    case PORTD:
        if (GET_BIT(DIO_PIND, Copy_u8PinNumber) == 1)
        {
            value = HIGH;
        }
        break;

    default:
        break;
    }

    return value;
}

void DIO_voidSetPortDirection(u8 Copy_u8PortName, u8 Copy_u8PortDirection)
{
    switch (Copy_u8PortName)
    {
    case PORTA:
        if (Copy_u8PortDirection == OUTPUT)
        {
            DIO_DDRA = 0xFF;
        }
        else if (Copy_u8PortDirection == INPUT)
        {
            DIO_DDRA = 0x00;
        }
        break;

    case PORTB:
        if (Copy_u8PortDirection == OUTPUT)
        {
            DIO_DDRB = 0xFF;
        }
        else if (Copy_u8PortDirection == INPUT)
        {
            DIO_DDRB = 0x00;
        }
        break;

    case PORTC:
        if (Copy_u8PortDirection == OUTPUT)
        {
            DIO_DDRC = 0xFF;
        }
        else if (Copy_u8PortDirection == INPUT)
        {
            DIO_DDRC = 0x00;
        }
        break;

    case PORTD:
        if (Copy_u8PortDirection == OUTPUT)
        {
            DIO_DDRD = 0xFF;
        }
        else if (Copy_u8PortDirection == INPUT)
        {
            DIO_DDRD = 0x00;
        }
        break;

    default:
        break;
    }
}

void DIO_voidSetPortSpecificDirection(u8 Copy_u8PortName, u8 Copy_u8PortDirection)
{
    switch (Copy_u8PortName)
    {
    case PORTA:
        DIO_DDRA = Copy_u8PortDirection;
        break;

    case PORTB:
        DIO_DDRB = Copy_u8PortDirection;
        break;

    case PORTC:
        DIO_DDRC = Copy_u8PortDirection;
        break;

    case PORTD:
        DIO_DDRD = Copy_u8PortDirection;
        break;

    default:
        break;
    }
}

void DIO_voidSetPortValue(u8 Copy_u8PortName, u8 Copy_u8PortValue)
{
    switch (Copy_u8PortName)
    {
    case PORTA:
        if (Copy_u8PortValue == HIGH)
        {
            DIO_PORTA = 0xFF;
        }
        else if (Copy_u8PortValue == LOW)
        {
            DIO_PORTA = 0x00;
        }
        else
        {
        }
        break;

    case PORTB:
        if (Copy_u8PortValue == HIGH)
        {
            DIO_PORTB = 0xFF;
        }
        else if (Copy_u8PortValue == LOW)
        {
            DIO_PORTB = 0x00;
        }
        else
        {
        }
        break;

    case PORTC:
        if (Copy_u8PortValue == HIGH)
        {
            DIO_PORTC = 0xFF;
        }
        else if (Copy_u8PortValue == LOW)
        {
            DIO_PORTC = 0x00;
        }
        else
        {
        }
        break;

    case PORTD:
        if (Copy_u8PortValue == HIGH)
        {
            DIO_PORTD = 0xFF;
        }
        else if (Copy_u8PortValue == LOW)
        {
            DIO_PORTD = 0x00;
        }
        else
        {
        }
        break;

    default:
        break;
    }
}

void DIO_voidSetPortSpecificValue(u8 Copy_u8PortName, u8 Copy_u8PortValue)
{
    switch (Copy_u8PortName)
    {
    case PORTA:
        DIO_PORTA = Copy_u8PortValue;
        break;

    case PORTB:
        DIO_PORTB = Copy_u8PortValue;
        break;

    case PORTC:
        DIO_PORTC = Copy_u8PortValue;
        break;

    case PORTD:
        DIO_PORTD = Copy_u8PortValue;
        break;

    default:
        break;
    }
}

void DIO_voidSetPortPullUp(u8 Copy_u8PortName)
{
    switch (Copy_u8PortName)
    {
    case PORTA:
        DIO_DDRA = 0x00;
        DIO_PORTA = 0xFF;
        break;

    case PORTB:
        DIO_DDRB = 0x00;
        DIO_PORTB = 0xFF;
        break;

    case PORTC:
        DIO_DDRC = 0x00;
        DIO_PORTC = 0xFF;
        break;

    case PORTD:
        DIO_DDRD = 0x00;
        DIO_PORTD = 0xFF;
        break;

    default:
        break;
    }
}

u8 DIO_u8GetPortValue(u8 Copy_u8PortName)
{
    u8 value = LOW;
    switch (Copy_u8PortName)
    {
    case PORTA:
        if (DIO_PINA == 0xFF)
        {
            value = HIGH;
        }
        break;

    case PORTB:
        if (DIO_PINB == 0xFF)
        {
            value = HIGH;
        }
        break;

    case PORTC:
        if (DIO_PINC == 0xFF)
        {
            value = HIGH;
        }
        break;

    case PORTD:
        if (DIO_PIND == 0xFF)
        {
            value = HIGH;
        }
        break;

    default:
        break;
    }

    return value;
}
