#ifndef _KPD_INT_H
#define _KPD_INT_H

/*************************************************************************************
 *                        Argument and Return Possibilities                          *
 *************************************************************************************/
#define KPD_NOT_PRESSED   255

/*************************************************************************************
 *                               Public Function Prototypes                          *
 *************************************************************************************/
/*
 *  H_KPD_void_Init
 *  	-> This function shall initialize the Keypad i.e., sets all Columns as O/P
 *  	   and all Rows as Pulled-up I/P.
 */
void H_KPD_void_Init(void);

/*
 *  H_KPD_void_GetPressedKey
 *  	-> This function shall return the value of the pressed key
 *  	   or KPD_NOT_PRESSED otherwise.
 */
void H_KPD_void_GetPressedKey(u8* copy_Pu8_PressedKey);

#endif /* _KPD_INT_H */
