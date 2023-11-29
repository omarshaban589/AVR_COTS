#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

#define EXTI_SREG *((volatile u8 *)0x5F)
#define SREG_BIT 7

#define EXTI_GICR *((volatile u8 *)0x5B)
#define GICR_INT0_ENABLE 6
#define GICR_INT1_ENABLE 7
#define GICR_INT2_ENABLE 5

#define EXTI_GIFR *((volatile u8 *)0x5A)

#define EXTI_MCUCR *((volatile u8 *)0x55)
#define MUCUCR_INT0_ISC00 0
#define MUCUCR_INT0_ISC01 1
#define MUCUCR_INT1_ISC10 2
#define MUCUCR_INT1_ISC11 3

#define EXTI_MUCUCSR *((volatile u8 *)0x54)
#define MUCUCR_ISC2 6

#define NULL_POINTER 0x00

#endif