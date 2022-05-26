/*
 * File Description:
 * DDRx  -> This register is used for selecting the pin direction in Portx
 * 				0 -> Input
 * 				1 -> Output
 * PORTx -> This register has 2 Functionality that are dependent on the selected Direction
 * 				If pin is O/P -> the register is used to O/P Voltage
 * 									0 -> Output Low  "GND"
 * 									1 -> Output High "VCC"
 * 				If pin is I/P -> the register is used to provide Internal Pull-up Resistor
 * 									0 -> No Internal Pull up resistor is connected
 * 									1 -> Internal Pull up resistor is connected
 * 	PINx -> This register contains the voltage value applied on a pin
 * 				0 -> Input Low  "GND"
 * 				1 -> Input High "VCC"
 */

#ifndef _DIO_REG_H
#define _DIO_REG_H

/*
 * Port A Registers Definition
 */
#define PORTA *( (u8 *) 0x3B)
#define DDRA  *( (u8 *) 0x3A)
#define PINA  *( (volatile u8 *) 0x39)

/*
 * Port B Registers Definition
 */
#define PORTB *( (u8 *) 0x38)
#define DDRB  *( (u8 *) 0x37)
#define PINB  *( (volatile u8 *) 0x36)

/*
 * Port C Registers Definition
 */
#define PORTC *( (u8 *) 0x35)
#define DDRC  *( (u8 *) 0x34)
#define PINC  *( (volatile u8 *) 0x33)

/*
 * Port D Registers Definition
 */
#define PORTD *( (u8 *) 0x32)
#define DDRD  *( (u8 *) 0x31)
#define PIND  *( (volatile u8 *) 0x30)

#endif /* _DIO_REG_H */
