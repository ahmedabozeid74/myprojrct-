#ifndef _LCD_PRI_H
#define _LCD_PRI_H

/*************************************************************************************
 *                          Instructions / Commands                                  *
 *************************************************************************************/
#define CMD_CLEAR             (0x01) /* replace all characters with ASCII 'space'     */
#define CMD_RETURN_HOME       (0x02) /* return cursor to first position on first line */
#define CMD_ENTRY_MODE        (0x06) /* shift cursor from left to right on read/write */
#define CMD_DISPLAY_OFF       (0x08) /* turn display off                              */
#define CMD_DISPLAY_ON        (0x0C) /* display on, cursor off, don't blink character */
#define CMD_RESET       	  (0x30) /* reset the LCD                                 */
#define CMD_SET_8BITS_2LINES  (0x38) /* 8-bit data, 2-line display, 5 x 7 font        */
#define CMD_SET_4BITS_2LINES  (0x28) /* 4-bit data, 2-line display, 5 x 7 font        */
#define CMD_CURSOR_OFFSET     (0x80) /* set cursor position                           */

/*************************************************************************************
 *                         Declaring Static Functions                                *
 *************************************************************************************/
 void H_LCD_void_SendCommand(u8 copy_u8_CmdID);

/*************************************************************************************
 *                                Declaring Options                                  *
 *************************************************************************************/
/*
 * Options for the Mode configuration of the LCD
 */
#define MODE_4BIT	(0x00)
#define MODE_8BIT	(0x01)

/*
 * Options for the 4-bit Mode nibble configuration of the LCD
 */
#define LOWER	(0x00)
#define UPPER	(0x01)

#endif /* _LCD_PRI_H */
