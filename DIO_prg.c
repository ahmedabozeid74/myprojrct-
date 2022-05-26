/*************************************************************************************
 *                                  Files Inclusion                                  *
 *************************************************************************************/

/* User Defined Library Files */
#include "StdTypes.h"
#include "BitMath.h"

/* Module Header Files */
#include "DIO_int.h"
#include "DIO_reg.h"
#include "DIO_pri.h"

/*************************************************************************************
 *                               Public Function Definition                          *
 *************************************************************************************/
/***
 * Pin Functions
 ***/

void M_DIO_void_SetPinDir (u8 copy_u8_PortID, u8 copy_u8_PinID, u8 copy_u8_DirID) {
	switch (copy_u8_PortID)
	{
		case PORTA_ID: WRT_BIT(DDRA, copy_u8_PinID, copy_u8_DirID); break;
		case PORTB_ID: WRT_BIT(DDRB, copy_u8_PinID, copy_u8_DirID); break;
		case PORTC_ID: WRT_BIT(DDRC, copy_u8_PinID, copy_u8_DirID); break;
		case PORTD_ID: WRT_BIT(DDRD, copy_u8_PinID, copy_u8_DirID); break;
		default:       /* Wrong Port ID */                          break;
	}
}

void M_DIO_void_SetPinVal (u8 copy_u8_PortID, u8 copy_u8_PinID, u8 copy_u8_PinVal) {
	switch (copy_u8_PortID)
	{
		case PORTA_ID: WRT_BIT(PORTA, copy_u8_PinID, copy_u8_PinVal); break;
		case PORTB_ID: WRT_BIT(PORTB, copy_u8_PinID, copy_u8_PinVal); break;
		case PORTC_ID: WRT_BIT(PORTC, copy_u8_PinID, copy_u8_PinVal); break;
		case PORTD_ID: WRT_BIT(PORTD, copy_u8_PinID, copy_u8_PinVal); break;
		default:       /* Wrong Port ID */                            break;
	}
}

void M_DIO_void_TogPinVal (u8 copy_u8_PortID, u8 copy_u8_PinID) {
	switch (copy_u8_PortID){
		case PORTA_ID: TOG_BIT(PORTA, copy_u8_PinID); break;
		case PORTB_ID: TOG_BIT(PORTB, copy_u8_PinID); break;
		case PORTC_ID: TOG_BIT(PORTC, copy_u8_PinID); break;
		case PORTD_ID: TOG_BIT(PORTD, copy_u8_PinID); break;
		default:       /* Wrong Port ID */            break;
	}
}

void M_DIO_void_GetPinVal (u8 copy_u8_PortID, u8 copy_u8_PinID, u8 *copy_Pu8_PinVal){
	u8 local_u8_PinVal = 0;
	switch (copy_u8_PortID){
		case PORTA_ID: local_u8_PinVal = GET_BIT(PINA, copy_u8_PinID); break;
		case PORTB_ID: local_u8_PinVal = GET_BIT(PINB, copy_u8_PinID); break;
		case PORTC_ID: local_u8_PinVal = GET_BIT(PINC, copy_u8_PinID); break;
		case PORTD_ID: local_u8_PinVal = GET_BIT(PIND, copy_u8_PinID); break;
		default:       /* Wrong Port ID */                             break;
	}
	*copy_Pu8_PinVal = local_u8_PinVal;
}

/***
 * Port Functions
 ***/
void M_DIO_void_SetPortDir (u8 copy_u8_PortID, u8 copy_u8_PortDir) {
	switch (copy_u8_PortID){
		case PORTA_ID: DDRA = copy_u8_PortDir; break;
		case PORTB_ID: DDRB = copy_u8_PortDir; break;
		case PORTC_ID: DDRC = copy_u8_PortDir; break;
		case PORTD_ID: DDRD = copy_u8_PortDir; break;
		default:       /* Wrong Port ID */     break;
	}
}

void M_DIO_void_SetPortVal (u8 copy_u8_PortID, u8 copy_u8_PortVal) {
	switch (copy_u8_PortID){
		case PORTA_ID: PORTA = copy_u8_PortVal; break;
		case PORTB_ID: PORTB = copy_u8_PortVal; break;
		case PORTC_ID: PORTC = copy_u8_PortVal; break;
		case PORTD_ID: PORTD = copy_u8_PortVal; break;
		default:       /* Wrong Port ID */      break;
	}
}

/***
 * Nibble Functions
 ***/

void M_DIO_void_SetLowerNibbleDir(u8 copy_u8_PortID, u8 copy_u8_NibbleDir){
    switch (copy_u8_PortID){
		case PORTA_ID: DDRA = (DDRA & LOWER_NIBBLE_MASK) | copy_u8_NibbleDir; break;
		case PORTB_ID: DDRB = (DDRB & LOWER_NIBBLE_MASK) | copy_u8_NibbleDir; break;
		case PORTC_ID: DDRC = (DDRC & LOWER_NIBBLE_MASK) | copy_u8_NibbleDir; break;
		case PORTD_ID: DDRD = (DDRD & LOWER_NIBBLE_MASK) | copy_u8_NibbleDir; break;
		default:       /* Wrong Port ID */                       break;
    }
}
void M_DIO_void_SetUpperNibbleDir(u8 copy_u8_PortID, u8 copy_u8_NibbleDir){
	switch (copy_u8_PortID){
		case PORTA_ID:
			DDRA = (DDRA & UPPER_NIBBLE_MASK) |
				   (copy_u8_NibbleDir << UPPER_NIBBLE_ADJUST_POSITION);
			break;
		case PORTB_ID:
			DDRB = (DDRB & UPPER_NIBBLE_MASK) |
			       (copy_u8_NibbleDir << UPPER_NIBBLE_ADJUST_POSITION);
			break;
		case PORTC_ID:
			DDRC = (DDRC & UPPER_NIBBLE_MASK) |
			       (copy_u8_NibbleDir << UPPER_NIBBLE_ADJUST_POSITION);
			break;
		case PORTD_ID:
			DDRD = (DDRD & UPPER_NIBBLE_MASK) |
			       (copy_u8_NibbleDir << UPPER_NIBBLE_ADJUST_POSITION);
			break;
		default:       /* Wrong Port ID */                       break;
	}
}

void M_DIO_void_SetLowerNibbleVal(u8 copy_u8_PortID, u8 copy_u8_NibbleVal){
	switch (copy_u8_PortID){
		case PORTA_ID: PORTA = (PORTA & LOWER_NIBBLE_MASK) | copy_u8_NibbleVal; break;
		case PORTB_ID: PORTB = (PORTB & LOWER_NIBBLE_MASK) | copy_u8_NibbleVal; break;
		case PORTC_ID: PORTC = (PORTC & LOWER_NIBBLE_MASK) | copy_u8_NibbleVal; break;
		case PORTD_ID: PORTD = (PORTD & LOWER_NIBBLE_MASK) | copy_u8_NibbleVal; break;
		default:       /* Wrong Port ID */                       break;
	}
}

void M_DIO_void_SetUpperNibbleVal(u8 copy_u8_PortID, u8 copy_u8_NibbleVal){
	switch (copy_u8_PortID){
		case PORTA_ID:
			PORTA = (PORTA & UPPER_NIBBLE_MASK) |
			       (copy_u8_NibbleVal << UPPER_NIBBLE_ADJUST_POSITION);
			break;
		case PORTB_ID:
			PORTB = (PORTB & UPPER_NIBBLE_MASK) |
			       (copy_u8_NibbleVal << UPPER_NIBBLE_ADJUST_POSITION);
			break;
		case PORTC_ID:
			PORTC = (PORTC & UPPER_NIBBLE_MASK) |
			       (copy_u8_NibbleVal << UPPER_NIBBLE_ADJUST_POSITION);
			break;
		case PORTD_ID:
			PORTD = (PORTD & UPPER_NIBBLE_MASK) |
			       (copy_u8_NibbleVal << UPPER_NIBBLE_ADJUST_POSITION);
			break;
		default:       /* Wrong Port ID */                       break;
	}
}

