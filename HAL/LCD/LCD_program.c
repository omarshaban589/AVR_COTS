// Library Inclusion
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

// Lower Layer Inclusion
#include "../../MCAL/DIO/DIO_interface.h"
#include <util/delay.h>

// Self Layer Inclusion

// Self Files Inclusion
#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"

static void voidSendCommand(u8 Copy_u8Command)
{
    /*set RS Low for send command*/
    DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_RS_PIN, LOW);

    /*set RW Low for write*/
    DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_RW_PIN, LOW);

    /*send command*/
    DIO_voidSetPortSpecificValue(LCD_DATA_PORT, Copy_u8Command);

    /*send pulse to enable pin*/
    DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_EN_PIN, LOW);
    DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_EN_PIN, HIGH);
    _delay_ms(2);
    DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_EN_PIN, LOW);
}

void LCD_voidSendData(u8 Copy_u8Data)
{
    /*set RS high for send data*/
    DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_RS_PIN, HIGH);

    /*set RW Low for write*/
    DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_RW_PIN, LOW);

    /*send data*/
    DIO_voidSetPortSpecificValue(LCD_DATA_PORT, Copy_u8Data);

    /*send pulse to enable pin*/
    DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_EN_PIN, LOW);
    DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_EN_PIN, HIGH);
    _delay_ms(2);
    DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_EN_PIN, LOW);
}

void LCD_voidDisplayClear(void)
{
    voidSendCommand(DISPLAY_CLEAR_CMD);
}

void LCD_voidInit(void)
{
    /*set data port to be output pins*/
    DIO_voidSetPinDirection(LCD_DATA_PORT, LCD_DATA_PIN_D0, OUTPUT);
    DIO_voidSetPinDirection(LCD_DATA_PORT, LCD_DATA_PIN_D1, OUTPUT);
    DIO_voidSetPinDirection(LCD_DATA_PORT, LCD_DATA_PIN_D2, OUTPUT);
    DIO_voidSetPinDirection(LCD_DATA_PORT, LCD_DATA_PIN_D3, OUTPUT);
    DIO_voidSetPinDirection(LCD_DATA_PORT, LCD_DATA_PIN_D4, OUTPUT);
    DIO_voidSetPinDirection(LCD_DATA_PORT, LCD_DATA_PIN_D5, OUTPUT);
    DIO_voidSetPinDirection(LCD_DATA_PORT, LCD_DATA_PIN_D6, OUTPUT);
    DIO_voidSetPinDirection(LCD_DATA_PORT, LCD_DATA_PIN_D7, OUTPUT);

    /*set control pins to be output pins*/
    DIO_voidSetPinDirection(LCD_CONTROL_PORT, LCD_RW_PIN, OUTPUT);
    DIO_voidSetPinDirection(LCD_CONTROL_PORT, LCD_RS_PIN, OUTPUT);
    DIO_voidSetPinDirection(LCD_CONTROL_PORT, LCD_EN_PIN, OUTPUT);

    /*wait for more than 30 ms*/
    _delay_ms(40);

    /*function set command : 8-bit , 2 lines , font 5*7 */
    voidSendCommand(FUNCTION_SET_CMD);

    /*display on/off control command : display enable , dispaly cursior , display cursior blink */
    voidSendCommand(DISPLAY_ON_OFF_CMD);

    /*diaplay clear*/
    LCD_voidDisplayClear();

    /*enrty mode*/
    voidSendCommand(0b00000110);
}

void LCD_voidDisplayString(u8 *Ref_pu8String)
{
    while (*Ref_pu8String != '\0')
    {
        LCD_voidSendData(*Ref_pu8String++);
    }
}

void LCD_voidGoToXY(u8 Copy_u8Row, u8 Copy_u8Column)
{
    u8 Local_u8Address;
    if (Copy_u8Row == 1)
    {
        Local_u8Address = Copy_u8Column;
    }
    else if (Copy_u8Row == 2)
    {
        Local_u8Address = Copy_u8Column + 0x40;
    }
    else
    {
    }
    SET_BIT(Local_u8Address, 7);
    voidSendCommand(Local_u8Address);
}

void LCD_voidDisplayNumber(u32 Copy_u32Number)
{
    u8 Local_u8Number[10];
    s8 Local_u8LoopCounter = 0;
    while (Copy_u32Number != 0)
    {
        Local_u8Number[Local_u8LoopCounter] = Copy_u32Number % 10;
        Copy_u32Number = Copy_u32Number / 10;
        Local_u8LoopCounter++;
    }
    Local_u8LoopCounter--;
    while (Local_u8LoopCounter >= 0)
    {
        LCD_voidSendData(Local_u8Number[Local_u8LoopCounter] + '0');
        Local_u8LoopCounter--;
    }
}

void LCD_voidDisplayCustomCharacter(u8 *Ref_pu8CharacterArray, u8 Copy_u8PatternNumber, u8 Copy_u8XPosition, u8 Copy_u8YPosition)
{
    u8 Local_u8LoopCounter = 0;

    /*calculate the CGRAM address*/
    u8 Local_u8CGRAMAddress = 0;
    Local_u8CGRAMAddress = Copy_u8PatternNumber * 8;

    /*Set the 6th bit of the CGRAM address*/
    SET_BIT(Local_u8CGRAMAddress, 6);

    /*Send CGRAm address comand to LCD*/
    voidSendCommand(Local_u8CGRAMAddress);

    /*Loop on array to send the data stored*/
    for (Local_u8LoopCounter = 0; Local_u8LoopCounter < 8; Local_u8LoopCounter++)
    {
        LCD_voidSendData(Ref_pu8CharacterArray[Local_u8LoopCounter]);
    }

    /*send the command set DDRAM address*/
    LCD_voidGoToXY(Copy_u8XPosition, Copy_u8YPosition);

    /*send the battern number to display*/
    LCD_voidSendData(Copy_u8PatternNumber);
}