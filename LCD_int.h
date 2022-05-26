#ifndef _LCD_INT_H
#define _LCD_INT_H

/*************************************************************************************
 *                        Argument and Return Possibilities                          *
 *************************************************************************************/
/*
 * Rows Macros
 */
#define ROW0_ID     0
#define ROW1_ID     1

/*
 * Columns Macros
 */
#define COL0_ID    0
#define COL1_ID    1
#define COL2_ID    2
#define COL3_ID    3
#define COL4_ID    4
#define COL5_ID    5
#define COL6_ID    6
#define COL7_ID    7
#define COL8_ID    8
#define COL9_ID    9
#define COL10_ID   10
#define COL11_ID   11
#define COL12_ID   12
#define COL13_ID   13
#define COL14_ID   14
#define COL15_ID   15


/*************************************************************************************
 *                               Public Function Prototypes                          *
 *************************************************************************************/
/*
 *  H_LCD_void_Init
 *  	-> This function shall initialize the LCD i.e., sets all the data and control
 *  	   pins as output.
 */
void LCD_voidSendNumber		(u32  Copy_u32Number);

void H_LCD_void_Init(void);

/*
 *  H_LCD_void_DispChar
 *  	-> This function shall display one character on the screen.
 */
void H_LCD_void_DispChar(u8 copy_u8_Char);

/*
 *  H_LCD_void_DispStr
 *  	-> This function shall display a group of characters on the screen.
 */
void H_LCD_void_DispStr(u8* copy_Pu8_String);

/*
 *  H_LCD_void_DispNum
 *  	-> This function shall display a number on the screen (up to 10 digits)
 *  	   @note the max value is 2^32.
 */
void H_LCD_void_DispNum(u32 copy_u32_Number);

/*
 *  H_LCD_void_ClearScreen
 *  	-> This function shall clear the display and returns the cursor to
 *  	   the start.
 */
void H_LCD_void_ClearScreen();

/*
 *  H_LCD_void_ClearScreen
 *  	-> This function shall move the cursor to the required row and column.
 */
void H_LCD_void_GoToRowCol(u8 copy_u8_RowId, u8 copy_u8_ColId);

#endif /* _LCD_INT_H */
