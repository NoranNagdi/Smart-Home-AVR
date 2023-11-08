/*
 * LCD_cfg.h
 *
 * Created: 10/21/2023 11:42:26 AM
 *  Author: DELL
 */ 


#ifndef LCD_CFG_H_
#define LCD_CFG_H_

/* LCD HW Ports and Pins Ids */
#define LCD_RS_PORT_ID                 PORTA_ID
#define LCD_RS_PIN_ID                  PIN3_ID

#define LCD_E_PORT_ID                  PORTA_ID
#define LCD_E_PIN_ID                   PIN2_ID

#define LCD_DATA_PORT_ID               PORTC_ID

#define LCD_D4_PIN_ID                 PIN0_ID
#define LCD_D5_PIN_ID                 PIN1_ID
#define LCD_D6_PIN_ID                 PIN2_ID
#define LCD_D7_PIN_ID                 PIN3_ID

/* LCD Commands */
#define LCD_CLEAR_COMMAND			   0x01
#define LCD_GO_TO_HOME				   0x02
#define LCD_TWO_LINES_EIGHT_BITS_MODE  0x38
#define LCD_TWO_LINES_FOUR_BITS_MODE   0x28
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT1   0x33
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT2   0x32
#define LCD_CURSOR_OFF                 0x0C
#define LCD_CURSOR_ON                  0x0E
#define LCD_SET_CURSOR_LOCATION        0x80


#endif /* LCD_CFG_H_ */