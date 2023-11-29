// Library Inclusion
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

// Lower Layer Inclusion
#include "../../MCAL/DIO/DIO_interface.h"
#include <util/delay.h>

// Self Layer Inclusion

// Self Files Inclusion
#include "KPD_interface.h"
#include "KPD_private.h"
#include "KPD_config.h"

static u8 u8RowsArray[4] = {KPD_R0_PIN, KPD_R1_PIN, KPD_R2_PIN, KPD_R3_PIN};
static u8 u8ColsArray[4] = {KPD_C0_PIN, KPD_C1_PIN, KPD_C2_PIN, KPD_C3_PIN};

void KPD_voidInit(void)
{
    u8 Local_u8LoopCounter = 0;

    for (Local_u8LoopCounter = 0; Local_u8LoopCounter < KPD_NUM_OF_COLS; Local_u8LoopCounter++)
    {
        /*Set Rows Pins To Be Input*/
        DIO_voidSetPinDirection(KPD_ROWS_PORT, u8RowsArray[Local_u8LoopCounter], INPUT);
        /*Set Rows Pins To Be Pulled Up*/
        DIO_voidSetPinPullUp(KPD_ROWS_PORT, u8RowsArray[Local_u8LoopCounter]);
        /*Set Cols Pins To Be Output*/
        DIO_voidSetPinDirection(KPD_COLS_PORT, u8ColsArray[Local_u8LoopCounter], OUTPUT);
        /*Set Cols Pins To Be High*/
        DIO_voidSetPinValue(KPD_COLS_PORT, u8ColsArray[Local_u8LoopCounter], HIGH);
    }
}

u8 KPD_u8GetPressedKey(void)
{
    static u8 Local_u8ButtonsArray[KPD_NUM_OF_ROWS][KPD_NUM_OF_COLS] = KPD_VAL;

    u8 Local_u8RowsIndex;
    u8 Local_u8ColsIndex;

    u8 Local_u8RowValue;

    u8 Local_u8PressedKey = KPD_DEFAULT_VAL;

    /*Deactivate All Columns*/
    voidDeactivateAllColumns();

    for (Local_u8ColsIndex = 0; Local_u8ColsIndex < KPD_NUM_OF_COLS; Local_u8ColsIndex++)
    {
        /*Activate The Current Column*/
        DIO_voidSetPinValue(KPD_COLS_PORT, u8ColsArray[Local_u8ColsIndex], LOW);
        /*Read Rows Pins*/
        for (Local_u8RowsIndex = 0; Local_u8RowsIndex < KPD_NUM_OF_ROWS; Local_u8RowsIndex++)
        {
            Local_u8RowValue = DIO_u8GetPinValue(KPD_ROWS_PORT, u8RowsArray[Local_u8RowsIndex]);
            if (Local_u8RowValue == LOW)
            {
                /*Get The Pressed Key*/
                Local_u8PressedKey = Local_u8ButtonsArray[Local_u8RowsIndex][Local_u8ColsIndex];
                /*Polling Until The Key is Released*/
                while (Local_u8RowValue == LOW)
                {
                    Local_u8RowValue = DIO_u8GetPinValue(KPD_ROWS_PORT, u8RowsArray[Local_u8RowsIndex]);
                }
                /*Return The Pressed Key*/
                return Local_u8PressedKey;
            }
        }
        /*Deactivate The Current Column*/
        DIO_voidSetPinValue(KPD_COLS_PORT, u8ColsArray[Local_u8ColsIndex], HIGH);
    }
    /*Return The Default Pressed Key*/
    return Local_u8PressedKey;
}

static void voidDeactivateAllColumns(void)
{
    u8 Local_u8ColsIndex = 0;

    for (Local_u8ColsIndex = 0; Local_u8ColsIndex < KPD_NUM_OF_COLS; Local_u8ColsIndex++)
    {
        DIO_voidSetPinValue(KPD_COLS_PORT, u8ColsArray[Local_u8ColsIndex], HIGH);
    }
}
