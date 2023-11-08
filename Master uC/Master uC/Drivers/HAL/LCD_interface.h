/*
 * LCD_interface.h
 *
 * Created: 10/21/2023 11:42:11 AM
 *  Author: DELL
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_


#include "../Std_Types.h"



void LCD_init(void);


void LCD_sendCommand(uint8 command);


void LCD_displayCharacter(uint8 data);


void LCD_displayString(const char *Str);


void LCD_moveCursor(uint8 row,uint8 col);


void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str);


void LCD_intgerToString(int data);


void LCD_clearScreen(void);


#endif /* LCD_INTERFACE_H_ */