#ifndef _DIO_INT_H
#define _DIO_INT_H

/*************************************************************************************
 *                        Argument and Return Possibilities                          *
 *************************************************************************************/

/*
 * Port ID Macros
 */
#define PORTA_ID        (0x00)
#define PORTB_ID        (0x01)
#define PORTC_ID        (0x02)
#define PORTD_ID        (0x03)

/*
 * Pin ID Macros
 */
#define PIN0_ID           (0x00)
#define PIN1_ID           (0x01)
#define PIN2_ID           (0x02)
#define PIN3_ID           (0x03)
#define PIN4_ID           (0x04)
#define PIN5_ID           (0x05)
#define PIN6_ID           (0x06)
#define PIN7_ID           (0x07)

/*
 * Direction Macros
 */
#define PIN_OUTPUT_ID     (0x01)
#define PIN_INPUT_ID      (0x00)

#define NIBBLE_OUTPUT_ID  (0x0F)
#define NIBBLE_INPUT_ID   (0x00)

#define PORT_OUTPUT_ID    (0xFF)
#define PORT_INPUT_ID     (0x00)

/*
 * O/P Pin Value Macros
 */
#define PIN_HIGH_ID       (0x01)
#define PIN_LOW_ID        (0x00)


/*************************************************************************************
 *                               Public Function Prototypes                          *
 *************************************************************************************/

/***
 * Pin Functions
 ***/
/*
 * M_DIO_void_SetPinDir
 * 		-> This function shall set the direction of specific pin
 *  	   in a specific port as I/P or as O/P
 */
void M_DIO_void_SetPinDir (u8 copy_u8_PortID, u8 copy_u8_PinID, u8 copy_u8_PinDir);

/*
 * M_DIO_void_SetPinDir
 * 		-> This function shall set the value of specific pin
 *  	   in a specific port as Low/GND or as High/VCC if the
 *  	   pin direction is O/P
 *
 *  	-> This function shall connect the internal Pull up
 *  	   resistor of specific pin in a specific port if the
 *  	   pin direction is I/P
 */
void M_DIO_void_SetPinVal (u8 copy_u8_PortID, u8 copy_u8_PinID, u8 copy_u8_PinVal);

/*
 * M_DIO_void_TogPinVal
 * 		-> This function shall flip the value of specific pin
 *  	   in a specific port
 */
void M_DIO_void_TogPinVal (u8 copy_u8_PortID, u8 copy_u8_PinID);

/*
 * M_DIO_void_GetPinVal
 * 		-> This function shall read the value of specific pin
 *  	   in a specific port
 */
void M_DIO_void_GetPinVal (u8 copy_u8_PortID, u8 copy_u8_PinID, u8 *copy_Pu8_PinVal);


/***
 * Port Functions
 ***/
/*
 * M_DIO_void_SetPortDir
 * 		-> This function shall set the direction of the whole port
 */
void M_DIO_void_SetPortDir (u8 copy_u8_PortID, u8 copy_u8_PortDir);

/*
 * M_DIO_void_SetPortDir
 * 		-> This function shall set the value of the whole port
 */
void M_DIO_void_SetPortVal (u8 copy_u8_PortID, u8 copy_u8_PortVal);

/***
 * Nibble Functions
 ***/
/*
 * M_DIO_void_SetNibbleDir
 * 		-> This function shall set the direction of 4-bits(Lower 0 : 3) inside port
 */
void M_DIO_void_SetLowerNibbleDir(u8 copy_u8_PortID, u8 copy_u8_NibbleDir);

/*
 * M_DIO_void_SetNibbleDir
 * 		-> This function shall set the direction of 4-bits(Higher 4 : 7) inside port
 */
void M_DIO_void_SetUpperNibbleDir(u8 copy_u8_PortID, u8 copy_u8_NibbleDir);

/*
 * M_DIO_void_SetNibbleDir
 * 		-> This function shall set the value of 4-bits(Lower 0 : 3) inside port
 */
void M_DIO_void_SetLowerNibbleVal(u8 copy_u8_PortID, u8 copy_u8_NibbleVal);

/*
 * M_DIO_void_SetNibbleDir
 * 		-> This function shall set the value of 4-bits(Higher 4 : 7) inside port
 */
void M_DIO_void_SetUpperNibbleVal(u8 copy_u8_PortID, u8 copy_u8_NibbleVal);

#endif /* _DIO_INT_H */
