#ifndef TIMER_PRIVATE_H
#define TIMER_PRIVATE_H

// ***************************************************** TIMER 0 **********************************************************
#define TIMER_TCCR0 *((volatile u8 *)0x53)
#define TCCR0_CS00 0
#define TCCR0_CS01 1
#define TCCR0_CS02 2
#define TCCR0_WGM01 3
#define TCCR0_COM00 4
#define TCCR0_COM01 5
#define TCCR0_WGM00 6
#define TCCR0_FOC0 7

#define TIMER_TCNT0 *((volatile u8 *)0x52)
#define TIMER_OCR0 *((volatile u8 *)0x5C)

#define TIMER_TIMSK *((volatile u8 *)0x59)
#define TIMSK_TOIE0 0
#define TIMSK_OCIE0 1
#define TIMSK_TOIE1 2
#define TIMSK_OCIE1B 3
#define TIMSK_OCIE1A 4
#define TIMSK_TICIE1 5
#define TIMSK_TOIE2 6
#define TIMSK_OCIE2 7

#define TIMER_TIFR *((volatile u8 *)0x58)
#define TIFR_TOV0 0
#define TIFR_OCF0 1
#define TIFR_TOV1 2
#define TIFR_OCF1B 3
#define TIFR_OCF1A 4
#define TIFR_ICF1 5
#define TIFR_TOV2 6
#define TIFR_OCF2 7

// ***************************************************** TIMER 1 **********************************************************
#define TIMER_TCCR1A *((volatile u8 *)0x4F)
#define TCCR1A_WGM10 0
#define TCCR1A_WGM11 1
#define TCCR1A_FOC1B 2
#define TCCR1A_FOC1A 3
#define TCCR1A_COM1B0 4
#define TCCR1A_COM1B1 5
#define TCCR1A_COM1A0 6
#define TCCR1A_COM1A1 7

#define TIMER_TCCR1B *((volatile u8 *)0x4E)
#define TCCR1B_CS10 0
#define TCCR1B_CS11 1
#define TCCR1B_CS12 2
#define TCCR1B_WGM12 3
#define TCCR1B_WGM13 4
#define TCCR1B_ICES1 6
#define TCCR1B_ICNC1 7

#define TIMER_TCNT1 *((volatile u16 *)0x4C)
#define TIMER_OCR1A *((volatile u16 *)0x4A)
#define TIMER_OCR1B *((volatile u16 *)0x48)
#define TIMER_ICR1 *((volatile u16 *)0x46)

// ***************************************************** TIMER 2 **********************************************************
#define TIMER_TCCR2 *((volatile u8 *)0x45)
#define TCCR2_CS20 0
#define TCCR2_CS21 1
#define TCCR2_CS22 2
#define TCCR2_WGM21 3
#define TCCR2_COM20 4
#define TCCR2_COM21 5
#define TCCR2_WGM20 6
#define TCCR2_FOC2 7

#define TIMER_TCNT2 *((volatile u8 *)0x44)
#define TIMER_OCR2 *((volatile u8 *)0x43)

#define TIMER_ASSR *((volatile u8 *)0x42)
#define ASSR_TCR2UB 0
#define ASSR_OCR2UB 1
#define ASSR_TCN2UB 2
#define ASSR_AS2 3

// **************************************************************************************************************************
#define TIMER_PRESACLING_MASK 0b11111000
#define TIMER_OCX_CONTROL_MASK 0b11001111
#define TIMER_OC1A_CONTROL_MASK 0b00111111
#define TIMER_OC1B_CONTROL_MASK 0b11001111

#define PRESCALER_1 0b001
#define PRESCALER_8 0b010
#define PRESCALER_64 0b011
#define PRESCALER_256 0b100
#define PRESCALER_1024 0b101
#define EXT_CLKSOURCE_FALLINGEDGE 0b110
#define EXT_CLKSOURCE_RISINGEDGE 0b111

#define TIMER0_OC0_TOOGLE_ON_CTC 0b010000
#define TIMER0_OC0_CLR_ON_CTC 0b100000
#define TIMER0_OC0_SET_ON_CTC 0b110000
#define TIMER0_OC0_RESERVED 0b010000
#define TIMER0_OC0_CANCELD 0b000000

#define TIMER2_OC2_TOOGLE_ON_CTC 0b010000
#define TIMER2_OC2_CLR_ON_CTC 0b100000
#define TIMER2_OC2_SET_ON_CTC 0b110000
#define TIMER2_OC2_RESERVED 0b010000
#define TIMER2_OC2_CANCELD 0b000000

#define TIMER1_OC1A_TOOGLE_ON_CTC 0b01000000
#define TIMER1_OC1A_CLR_ON_CTC 0b10000000
#define TIMER1_OC1A_SET_ON_CTC 0b11000000
// #define TIMER1_OC1A_RESERVED 0b000000
#define TIMER1_OC1A_CANCELD 0b00000000

#define TIMER1_OC1B_TOOGLE_ON_CTC 0b010000
#define TIMER1_OC1B_CLR_ON_CTC 0b100000
#define TIMER1_OC1B_SET_ON_CTC 0b110000
// #define TIMER1_OC1B_RESERVED 0b010000
#define TIMER1_OC1B_CANCELD 0b000000

#endif
