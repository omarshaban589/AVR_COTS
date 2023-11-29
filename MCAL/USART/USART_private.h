#ifndef USART_PRIVATE_H
#define USART_PRIVATE_H

#define USART_UDR *((volatile u8 *)0x2C)

#define USART_UCSRA *((volatile u8 *)0x2B)
#define UCSRA_MPCM 0
#define UCSRA_U2X 1
#define UCSRA_PE 2
#define UCSRA_DOR 3
#define UCSRA_FE 4
#define UCSRA_UDRE 5
#define UCSRA_TXC 6
#define UCSRA_RXC 7

#define USART_UCSRB *((volatile u8 *)0x2A)
#define UCSRB_TXB8 0
#define UCSRB_RXB8 1
#define UCSRB_UCSZ2 2
#define UCSRB_TXEN 3
#define UCSRB_RXEN 4
#define UCSRB_UDRIE 5
#define UCSRB_TXCIE 6
#define UCSRB_RXCIE 7

#define USART_UCSRC *((volatile u8 *)0x40)
#define UCSRC_UCPOL 0
#define UCSRC_UCSZ0 1
#define UCSRC_UCSZ1 2
#define UCSRC_USBS 3
#define UCSRC_UPM0 4
#define UCSRC_UPM1 5
#define UCSRC_UMSEL 6
#define UCSRC_URSEL 7

#define USART_UBRRL *((volatile u8 *)0x29)
#define USART_UBRRH *((volatile u8 *)0x40)

#define Synchronous 0
#define Asynchronous 1

#define DISABLED 0
#define EVEN_PARITY 1
#define ODD_PARITY 2

#define ONE_BIT 0
#define TWO_BIT 1

#define BITS_5 0
#define BITS_6 1
#define BITS_7 2
#define BITS_8 3
#define BITS_9 4

#define BPS_9600 0
#define BPS_115k 1
#define BPS_230k 2

#endif