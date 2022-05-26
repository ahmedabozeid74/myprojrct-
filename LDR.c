/*
 * LDR.c
 *
 *  Created on: May 25, 2022
 *      Author: General
 */

#include "LDR.h"
u16 ADC_Value ;

u16 H_voidReadChannlLdr(void)
{
	ADC_Value=ADC_Read(0)/100;


	return ADC_Value ;
}
