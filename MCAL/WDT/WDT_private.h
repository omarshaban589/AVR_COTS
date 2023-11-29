#ifndef WDT_PRIVATE_H
#define WDT_PRIVATE_H

#define WDTCR *((volatile u8 *)0x41)
#define WDTCR_WDE 3
#define WDTCR_WDTOE 4

#define SLEEPTIME_MASK 0b11111000

#endif