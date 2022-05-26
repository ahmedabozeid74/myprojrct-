/*************************************************************************************
 *                                  Files Inclusion                                  *
 *************************************************************************************/

/* User Defined Library Files */
#include<util/delay.h>

#include "StdTypes.h"
#include "BitMath.h"

#include "DIO_int.h"

/* Module Header Files */
#include "KPD_int.h"
#include "KPD_cfg.h"
#include "KPD_pri.h"

/*************************************************************************************
 *                             Static Objects Definition                             *
 *************************************************************************************/
static const u8 global_Au8_SwitchVal[ROW_SIZE][COL_SIZE] =
{
	{
		0x07, /* Row 0 Column 0 */
		0x04, /* Row 1 Column 0 */
		0x01, /* Row 2 Column 0 */
		0x0A  /* Row 3 Column 0 */
	},
	{
		0x08, /* Row 0 Column 1 */
		0x05, /* Row 1 Column 1 */
		0x02, /* Row 2 Column 1 */
		0x00  /* Row 4 Column 1 */
	},
	{
		0x09, /* Row 0 Column 2 */
		0x06, /* Row 1 Column 2 */
		0x03, /* Row 2 Column 2 */
		0x0B  /* Row 3 Column 2 */
	},
	{
		0x01, /* Row 0 Column 3 */
		0x05, /* Row 1 Column 3 */
		0x09, /* Row 2 Column 3 */
		0x0D  /* Row 3 Column 3 */
	}
};

/*************************************************************************************
 *                               Public Function Definition                          *
 *************************************************************************************/

void H_KPD_void_Init(void) {
	/* Set Columns as Output */
	for (u8 local_u8_PinID = COL_START; local_u8_PinID <= COL_END; local_u8_PinID++) {
		M_DIO_void_SetPinDir(KPD_PORT, local_u8_PinID, PIN_OUTPUT_ID);
	}
	/* Set Rows as Inputs & Pulled up */
	for (u8 local_u8_PinID = ROW_START; local_u8_PinID <= ROW_END; local_u8_PinID++) {
		M_DIO_void_SetPinDir(KPD_PORT, local_u8_PinID, PIN_INPUT_ID);
		M_DIO_void_SetPinVal(KPD_PORT, local_u8_PinID, PIN_HIGH_ID);
	}
}

void H_KPD_void_GetPressedKey(u8* copy_Pu8_PressedKey){
	u8 local_u8_Column, local_u8_Row, local_u8_PinVal;
	/* Initialize the switch status to NOT Pressed as a default value */
	u8 local_u8_PressedKey = KPD_NOT_PRESSED;
	/* Looping on columns of the Key Pad */
	for (local_u8_Column = COL_START; local_u8_Column <= COL_END; local_u8_Column++) {
		M_DIO_void_SetPinVal(KPD_PORT, local_u8_Column, PIN_LOW_ID); /* Activate the Column */
		/* Loop on the rows of the Key Pad */
		for (local_u8_Row = ROW_START; local_u8_Row <= ROW_END; local_u8_Row++) {
			/* Check the status of the switch */
			M_DIO_void_GetPinVal(KPD_PORT, local_u8_Row, &local_u8_PinVal);
			if (local_u8_PinVal == 0) {
				/* Get the value of the currently pressed switch */
				local_u8_PressedKey = global_Au8_SwitchVal[local_u8_Row - ROW_START][local_u8_Column - COL_START];
				/* Wait until the switch is released (Single Press) */
				while (local_u8_PinVal == 0) {
					M_DIO_void_GetPinVal(KPD_PORT, local_u8_Row, &local_u8_PinVal);
				}
				_delay_ms(20); /* Delay to avoid bouncing */
			}
		}
		M_DIO_void_SetPinVal(KPD_PORT, local_u8_Column, PIN_HIGH_ID); /* Deactivate the Column */
	}
	*copy_Pu8_PressedKey = local_u8_PressedKey; /* Returning the value */
}
