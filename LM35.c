/*
 * LM35.c
 *
 *  Created on: May 25, 2022
 *      Author: General
 */



#include "LM35.h"
u16 ADC_Value ;

u16 H_voidReadChannlLM35(void)
{

	ADC_Value=ADC_Read(1)/10;

	return ADC_Value ;
}
