// Library Inclusion
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

// Lower Layer Inclusion

// Self Layer Inclusion

// Self Files Inclusion
#include "../USART/USART_config.h"
#include "../USART/USART_interface.h"
#include "../USART/USART_private.h"

void USART_voidInit(void)
{
    u8 Local_u8UCSRCTemp = 0;

    // Enable Transmitter And Reciever
    SET_BIT(USART_UCSRB, UCSRB_TXEN);
    SET_BIT(USART_UCSRB, UCSRB_RXEN);

    // Control UCSRC
    SET_BIT(Local_u8UCSRCTemp, UCSRC_URSEL);

// Select USART Mode
#if USART_MODE == Synchronous
    SET_BIT(Local_u8UCSRCTemp, UCSRC_UMSEL);
#elif USART_MODE == Asynchronous
    CLR_BIT(Local_u8UCSRCTemp, UCSRC_UMSEL);
#endif

// Select Parity Mode
#if PARITY_MODE == DISABLED
    CLR_BIT(Local_u8UCSRCTemp, UCSRC_UPM0);
    CLR_BIT(Local_u8UCSRCTemp, UCSRC_UPM1);
#elif PARITY_MODE == EVEN_PARITY
    CLR_BIT(Local_u8UCSRCTemp, UCSRC_UPM0);
    SET_BIT(Local_u8UCSRCTemp, UCSRC_UPM1);
#elif PARITY_MODE == ODD_PARITY
    SET_BIT(Local_u8UCSRCTemp, UCSRC_UPM0);
    SET_BIT(Local_u8UCSRCTemp, UCSRC_UPM1);
#endif

// Select Stop-Bit
#if STOP_BIT == ONE_BIT
    CLR_BIT(Local_u8UCSRCTemp, UCSRC_USBS);
#elif STOP_BIT == TWO_BIT
    SET_BIT(Local_u8UCSRCTemp, UCSRC_USBS);
#endif

// Select Character Size
#if CHAR_SIZE == BITS_5
    CLR_BIT(Local_u8UCSRCTemp, UCSRC_UCSZ0);
    CLR_BIT(Local_u8UCSRCTemp, UCSRC_UCSZ1);
    CLR_BIT(USART_UCSRB, UCSRB_UCSZ2);
#elif CHAR_SIZE == BITS_6
    SET_BIT(Local_u8UCSRCTemp, UCSRC_UCSZ0);
    CLR_BIT(Local_u8UCSRCTemp, UCSRC_UCSZ1);
    CLR_BIT(USART_UCSRB, UCSRB_UCSZ2);
#elif CHAR_SIZE == BITS_7
    CLR_BIT(Local_u8UCSRCTemp, UCSRC_UCSZ0);
    SET_BIT(Local_u8UCSRCTemp, UCSRC_UCSZ1);
    CLR_BIT(USART_UCSRB, UCSRB_UCSZ2);
#elif CHAR_SIZE == BITS_8
    SET_BIT(Local_u8UCSRCTemp, UCSRC_UCSZ0);
    SET_BIT(Local_u8UCSRCTemp, UCSRC_UCSZ1);
    CLR_BIT(USART_UCSRB, UCSRB_UCSZ2);
#elif CHAR_SIZE == BITS_9
    SET_BIT(Local_u8UCSRCTemp, UCSRC_UCSZ0);
    SET_BIT(Local_u8UCSRCTemp, UCSRC_UCSZ1);
    SET_BIT(USART_UCSRB, UCSRB_UCSZ2);
#endif

    // Save Byte In The Register Becaue It is not bit Accessable
    USART_UCSRC = Local_u8UCSRCTemp;

    // Double Speed Mode Disable
    CLR_BIT(USART_UCSRA, UCSRA_U2X);

    // Control UBRRH
    CLR_BIT(Local_u8UCSRCTemp, UCSRC_URSEL);

    // Make UBRRH Zero
    USART_UBRRH = 0;

// Select Baud Rate
#if BAUD_RATE == BPS_9600
    USART_UBRRL = (u8)((8000000UL / 153600UL) - 1UL);
#elif BAUD_RATE == BPS_115k
    USART_UBRRL = (u8)((8000000UL / 1843200UL) - 1UL);
#elif BAUD_RATE == BPS_230k
    USART_UBRRL = (u8)((8000000UL / 3686400UL) - 1UL);
#endif
}

void USART_voidTransmitDataSynchronous(u8 Copy_u8Data)
{
    while (GET_BIT(USART_UCSRA, UCSRA_UDRE) == 0)
        ;
    USART_UDR = Copy_u8Data;
    while (GET_BIT(USART_UCSRA, UCSRA_TXC) == 0)
        ;
    SET_BIT(USART_UCSRA, UCSRA_TXC);
}

void USART_voidRecieveDataSynchronous(u8 *Copy_u8Data)
{
    while (GET_BIT(USART_UCSRA, UCSRA_RXC) == 0)
        ;
    *Copy_u8Data = USART_UDR;
}

static void (*USART_pvTransFunction)(void) = NULL;

void USART_voidTransmitDataAsynchronous(void (*Ref_pvFunction)(void), u8 Copy_u8Data)
{
    USART_pvTransFunction = Ref_pvFunction;
    SET_BIT(USART_UCSRB, UCSRB_TXCIE);
    while (GET_BIT(USART_UCSRA, UCSRA_UDRE) == 0)
        ;
    USART_UDR = Copy_u8Data;
}

void __vector_15(void) __attribute__((signal));
void __vector_15(void)
{
    if (USART_pvTransFunction != NULL)
    {
        USART_pvTransFunction();
    }
    else
    {
    }
}

static void (*USART_pvResFunction)(u8 *) = NULL;
u8 RecievedData = 0;

void USART_voidRecieveDataAsynchronous(void (*Ref_pvFunction)(u8 *))
{
    USART_pvResFunction = Ref_pvFunction;
    SET_BIT(USART_UCSRB, UCSRB_RXCIE);
}

void __vector_13(void) __attribute__((signal));
void __vector_13(void)
{
    if (USART_pvResFunction != NULL)
    {
        RecievedData = USART_UDR;
        USART_pvResFunction(&RecievedData);
    }
    else
    {
    }
}