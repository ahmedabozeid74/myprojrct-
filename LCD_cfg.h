#ifndef _LCD_CFG_H
#define _LCD_CFG_H

/*************************************************************************************
 *                             Configuration of LCD Modes                            *
 *************************************************************************************/
/*
 * Select an option for the LCD Mode configuration
 * MODE_4BIT - MODE_8BIT
 */
#define LCD_MODE         MODE_4BIT

/*
 * Select an option for the LCD 4-bits Mode nibble configuration
 * LOWER - UPPER
 */
#if LCD_MODE == MODE_4BIT
#define DATA_PORT_NIBBLE UPPER
#endif

/*************************************************************************************
 *                          Abstraction of the physical connection                   *
 *************************************************************************************/
/*
 * Data Pins Connections
 */
#define LCD_DATA_PORT	 PORTA_ID

/*
 * Control Pins Connections
 */
/* Register Select */
#define RS_PORT	         PORTD_ID
#define RS_PIN	         PIN0_ID
/* Read / Write */
#define RW_PORT	         PORTD_ID
#define RW_PIN           PIN1_ID
/* Enable */
#define EN_PORT	         PORTD_ID
#define EN_PIN           PIN2_ID

#endif /* _LCD_CFG_H */
