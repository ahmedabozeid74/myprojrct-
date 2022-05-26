#ifndef _ADC_REG_H
#define _ADC_REG_H

/*
 * ADC Multiplexer Selection Register
 */
#define ADMUX      *( (u8 *) 0x27)
#define REFS1      7
#define REFS0      6
#define ADLAR      5
#define MUX4       4
#define MUX3       3
#define MUX2       2
#define MUX1       1
#define MUX0       0

/*
 * ADC Control and Status Register
 */
#define ADCSRA     *( (volatile u8 *) 0x26)
#define ADEN       7
#define ADSC       6
#define ADATE      5
#define ADIF       4
#define ADIE       3
#define ADPS2      2
#define ADPS1      1
#define ADPS0      0

/*
 * ADC Data Registers
 */
#define ADCH       *( (volatile u8  *) 0x25)
#define ADCL       *( (volatile u8  *) 0x24)
#define ADC_DATA   *( (volatile u16 *) 0x24)

#endif /* _ADC_REG_H */
