#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

void LCD_voidSendData(u8 Copy_u8Data);

void LCD_voidDisplayClear(void);

void LCD_voidInit(void);

void LCD_voidDisplayString(u8 *Copy_u8String);

void LCD_voidGoToXY(u8 Copy_u8Row, u8 Copy_u8Column);

void LCD_voidDisplayNumber(u32 Copy_u32Number);

void LCD_voidDisplayCustomCharacter(u8 *Ref_pu8CharacterArray, u8 Copy_u8PatternNumber, u8 Copy_u8XPosition, u8 Copy_u8YPosition);

#endif