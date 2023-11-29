#ifndef WDT_INTERFACE_H
#define WDT_INTERFACE_H

#define WDT_16_ms 0b000
#define WDT_32_ms 0b001
#define WDT_65_ms 0b010
#define WDT_130_ms 0b011
#define WDT_260_ms 0b100
#define WDT_520_ms 0b101
#define WDT_1_s 0b110
#define WDT_2_s 0b111

void WDT_voidEnable(void);
void WDT_voidSleep(u8 Copy_u8SleepTimer);
void WDT_voidDisabe(void);

#endif