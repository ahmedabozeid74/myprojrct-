
#include "servo.h"


u16 ADC_Value ;
void H_voidServoMove(u16 copy_u16_servo)
{

	OCR1A=copy_u16_servo;
	OCR1B=copy_u16_servo;

}

void H_voidInitServo(void)
{

	TCCR1A|=(1<<1)|(1<<7) ;
	TCCR1B|=(1<<1)|(1<<3)|(1<<4) ;
	ICR1=19999 ;
}

/*
u16 H_voidReadChannlServo(void)
{
	ADC_Value=ADC_Read(0);
	return ADC_Value ;
}
*/
