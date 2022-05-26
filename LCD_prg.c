/*************************************************************************************
 *                                  Files Inclusion                                  *
 *************************************************************************************/

/* User Defined Library Files */
#include "BitMath.h"
#include "StdTypes.h"

/* Third Party Library Files */
#include "util/delay.h"

/* Standard Library Files */
#include "stdlib.h"

/* Interface File of used MCAL Drivers */
#include "DIO_int.h"

/* Module Header Files */
#include "LCD_int.h"
#include "LCD_cfg.h"
#include "LCD_pri.h"

/*************************************************************************************
 *                               Public Function Definition                          *
 *************************************************************************************/

void H_LCD_void_Init(void) {
	/* Set Data Port Direction as output */
#if (LCD_MODE == MODE_8BIT)
	M_DIO_void_SetPortDir(LCD_DATA_PORT, PORT_OUTPUT_ID);
#elif (LCD_MODE == MODE_4BIT)
#if (DATA_PORT_NIBBLE == LOWER)
	M_DIO_void_SetLowerNibbleDir(LCD_DATA_PORT, NIBBLE_OUTPUT_ID);
#elif (DATA_PORT_NIBBLE == UPPER)
	M_DIO_void_SetUpperNibbleDir(LCD_DATA_PORT, NIBBLE_OUTPUT_ID);
#endif
#endif
	/* Set Control pins as output */
	M_DIO_void_SetPinDir(RS_PORT, RS_PIN, PIN_OUTPUT_ID);
	M_DIO_void_SetPinDir(RW_PORT, RW_PIN, PIN_OUTPUT_ID);
	M_DIO_void_SetPinDir(EN_PORT, EN_PIN, PIN_OUTPUT_ID);
	_delay_ms(30); /* Delay 30ms to ensure the initialization of the LCD driver */
	H_LCD_void_SendCommand(CMD_RETURN_HOME); _delay_ms(15); /* Return Home */
	/* Function Set */
#if (LCD_MODE == MODE_8BIT)
	H_LCD_void_SendCommand(CMD_SET_8BITS_2LINES); _delay_ms(1); /* Configure as 8-bit data mode*/
#elif (LCD_MODE == MODE_4BIT)
	H_LCD_void_SendCommand(CMD_SET_4BITS_2LINES); _delay_ms(1); /* Configure as 4-bit data mode*/
#endif
	H_LCD_void_SendCommand(CMD_DISPLAY_ON);	_delay_ms(1);  /* Display ON OFF Control */
	H_LCD_void_SendCommand(CMD_CLEAR);      _delay_ms(15); /* Clear Display */
	H_LCD_void_SendCommand(CMD_ENTRY_MODE); _delay_ms(2);  /* Entry Mode Set */
}

void H_LCD_void_DispChar(u8 copy_u8_Data) {
	M_DIO_void_SetPinVal(RS_PORT, RS_PIN, PIN_HIGH_ID);/* Set RS to HIGH */
	M_DIO_void_SetPinVal(RW_PORT, RW_PIN, PIN_LOW_ID); /* Set R/W to LOW */
	M_DIO_void_SetPinVal(EN_PORT, EN_PIN, PIN_HIGH_ID);/* Set E to HIGH  */
	_delay_ms(1);  /* Wait for E to settle */
	/* Load Command on Data bus */
#if (LCD_MODE == MODE_8BIT)
	M_DIO_void_SetPortVal(LCD_DATA_PORT, copy_u8_Data);
#elif (LCD_MODE == MODE_4BIT)
#if (DATA_PORT_NIBBLE == LOWER)
	M_DIO_void_SetLowerNibbleVal(LCD_DATA_PORT, (copy_u8_Data & 0xF0) >> 0x04);
	M_DIO_void_SetPinVal(EN_PORT, EN_PIN, PIN_LOW_ID); /* Set E to LOW */
	_delay_ms(1);  /* Wait for E to settle */
	M_DIO_void_SetPinVal(EN_PORT, EN_PIN, PIN_HIGH_ID);/* Set E to HIGH  */
	M_DIO_void_SetLowerNibbleVal(LCD_DATA_PORT, (copy_u8_Data & 0x0F));
#elif (DATA_PORT_NIBBLE == UPPER)
	M_DIO_void_SetUpperNibbleVal(LCD_DATA_PORT, (copy_u8_Data & 0xF0) >> 0x04);
	M_DIO_void_SetPinVal(EN_PORT, EN_PIN, PIN_LOW_ID); /* Set E to LOW */
	_delay_ms(1); /* Wait for E to settle */
	M_DIO_void_SetPinVal(EN_PORT, EN_PIN, PIN_HIGH_ID);/* Set E to HIGH  */
	M_DIO_void_SetUpperNibbleVal(LCD_DATA_PORT, (copy_u8_Data & 0x0F));
#endif
#endif
	M_DIO_void_SetPinVal(EN_PORT, EN_PIN, PIN_LOW_ID); /* Set E to LOW */
	_delay_ms(1); /* Wait for E to settle */
	M_DIO_void_SetPinVal(EN_PORT, EN_PIN, PIN_HIGH_ID); /* Set E to LOW */
	_delay_ms(10); /* Delay for 10ms to let the LCD execute command */
}

void H_LCD_void_DispStr (u8* copy_Pu8_String) {
	/* Local loop index */
	u8 u8Index = 0;
	while (copy_Pu8_String[u8Index] != '\0') {
		/* Write Character on LCD */
		H_LCD_void_DispChar(copy_Pu8_String[u8Index]);
		/* Increment local loop index */
		u8Index++;
	}
}

void H_LCD_void_ClearScreen (){
	H_LCD_void_SendCommand(CMD_CLEAR);
}

void H_LCD_void_GoToRowCol (u8 copy_u8_RawId, u8 copy_u8_ColId) {
	u8 local_u8_Address;
	switch(copy_u8_RawId) {
		case 0:
			local_u8_Address = copy_u8_ColId;
			break;
		case 1:
			local_u8_Address = copy_u8_ColId + 0x40;
			break;
		default: /* Wrong Row ID */ break;
	}
	H_LCD_void_SendCommand(local_u8_Address | CMD_CURSOR_OFFSET);
}

void H_LCD_void_DispNum (u32 copy_u32_Number) {
	s8 * local_Pu8_str[16] = {0};
	/* ToDo: Replaced with user defined function in the LIB layer in StrManip Module */
	ltoa(copy_u32_Number, (s8 *)&local_Pu8_str, 10);
	H_LCD_void_DispStr((u8 *)local_Pu8_str);


}




void LCD_voidSendNumber		(u32  Copy_u32Number)
{

	u32 Local_u16NumRange = 1;

		if(Copy_u32Number == 0)
		{
			H_LCD_void_DispChar('0');
		}
		else
		{
			while((Copy_u32Number/Local_u16NumRange) != 0)
			{
				Local_u16NumRange *= 10;
			}

			while(Local_u16NumRange != 1)
			{
				Local_u16NumRange /= 10;
				H_LCD_void_DispChar((Copy_u32Number/Local_u16NumRange) + 48) ;
			//	LCD_voidSendChar((Copy_u32Number/Local_u16NumRange) + 48 );
				Copy_u32Number %= Local_u16NumRange;
			}
		}

}








/*************************************************************************************
 *                           Defining Static Functions                               *
 *************************************************************************************/
 void H_LCD_void_SendCommand(u8 copy_u8_CmdID) {
	M_DIO_void_SetPinVal(RS_PORT, RS_PIN, PIN_LOW_ID); /* Set RS to LOW */
	M_DIO_void_SetPinVal(RW_PORT, RW_PIN, PIN_LOW_ID); /* Set R/W to LOW */
	M_DIO_void_SetPinVal(EN_PORT, EN_PIN, PIN_HIGH_ID);/* Set E to HIGH  */
	_delay_ms(1);  /* Wait for E to settle */
	/* Load Command on Data bus */
#if (LCD_MODE == MODE_8BIT)
	M_DIO_void_SetPortVal(LCD_DATA_PORT, copy_u8_CmdID);
#elif (LCD_MODE == MODE_4BIT)
#if (DATA_PORT_NIBBLE == LOWER)
	M_DIO_void_SetLowerNibbleVal(LCD_DATA_PORT, ((copy_u8_CmdID & 0xF0) >> 0x04));
	M_DIO_void_SetPinVal(EN_PORT, EN_PIN, PIN_LOW_ID); /* Set E to LOW */
	_delay_ms(1);  /* Wait for E to settle */
	M_DIO_void_SetPinVal(EN_PORT, EN_PIN, PIN_HIGH_ID);/* Set E to HIGH  */
	M_DIO_void_SetLowerNibbleVal(LCD_DATA_PORT, (copy_u8_CmdID & 0x0F));
#elif (DATA_PORT_NIBBLE == UPPER)
	M_DIO_void_SetUpperNibbleVal(LCD_DATA_PORT, ((copy_u8_CmdID & 0xF0) >> 0x04));
	M_DIO_void_SetPinVal(EN_PORT, EN_PIN, PIN_LOW_ID); /* Set E to LOW */
	_delay_ms(1); /* Wait for E to settle */
	M_DIO_void_SetPinVal(EN_PORT, EN_PIN, PIN_HIGH_ID);/* Set E to HIGH  */
	M_DIO_void_SetUpperNibbleVal(LCD_DATA_PORT, (copy_u8_CmdID & 0x0F));
#endif
#endif
	M_DIO_void_SetPinVal(EN_PORT, EN_PIN, PIN_LOW_ID); /* Set E to LOW */
	_delay_ms(1); /* Wait for E to settle */
	M_DIO_void_SetPinVal(EN_PORT, EN_PIN, PIN_HIGH_ID); /* Set E to LOW */
	_delay_ms(10); /* Delay for 10ms to let the LCD execute command */
}
