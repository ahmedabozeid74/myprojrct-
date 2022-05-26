//#include<avr/io.h>
#include <avr/io.h>

#include<util/delay.h>
#include "StdTypes.h"
#include "BitMath.h"
#include "DIO_reg.h"
#include "DIO_int.h"
#include "LCD_cfg.h"
#include "LCD_int.h"
#include "LCD_pri.h"
#include "servo.h"
#include "LDR.h"
#include "LM35.h"
#include "adc.h"

//#define F_CPU  (u32)8000000

u16 value,i=0;
u16 ADC_Value ;
u16  x=0,y=0 ;

u8 key ,val=0 ;
u8 ARR[5]={7,4,7,4} , arr_copy[5];
int main(void)
{
	H_LCD_void_Init();
	ADC_Init ();
	H_KPD_void_Init();
	M_DIO_void_SetPinDir (PORTA_ID , PIN0_ID, PIN_INPUT_ID); //PIN LDR
	M_DIO_void_SetPinDir (PORTA_ID , PIN1_ID, PIN_INPUT_ID); // PIN LM35
	M_DIO_void_SetPinDir (PORTD_ID, PIN5_ID, PIN_OUTPUT_ID); // PIN SERVO
	M_DIO_void_SetPinDir (PORTD_ID , PIN6_ID, PIN_OUTPUT_ID); // PIN MOTOR
	M_DIO_void_SetPinDir (PORTD_ID , PIN7_ID, PIN_OUTPUT_ID); // PIN buz

	H_voidInitServo();




	while (1)

	{



		/*main scr
		 *                Enter 0
	         light=....    Tem= .....

	    if usr entr 0 will go to enter pass to opn door
	    if not enter will dispaly same scr
		 */
		H_LCD_void_GoToRowCol (1, 0);
		H_LCD_void_DispStr((u8*)"Light=");
		H_LCD_void_DispNum (H_voidReadChannlLdr());
		H_LCD_void_GoToRowCol (1, 10);
		H_LCD_void_DispStr((u8*)"Tem=");
		H_LCD_void_DispNum (H_voidReadChannlLM35());
if(H_voidReadChannlLM35()>=40)
{
	M_DIO_void_SetPinVal (PORTD_ID, PIN6_ID,PIN_HIGH_ID);
	}
else {
	M_DIO_void_SetPinVal (PORTD_ID, PIN6_ID,PIN_LOW_ID);
}


		H_KPD_void_GetPressedKey(&key);
		H_LCD_void_GoToRowCol (0,1);
		H_LCD_void_DispStr((u8*)"Enter 0");
		if((key)!=255)
		{
			//clear all csr
			// scnd step enter pass
			H_LCD_void_ClearScreen ();
			if((key)==0)
			{
				//dispaly enter pass in first row
				H_LCD_void_GoToRowCol (0,1);
				H_LCD_void_DispStr((u8*)"Enter Pass");

				//dispaly the next to scnd row
				H_LCD_void_GoToRowCol (1,0);

				while(i<=4)   //will loop until user enter 4 num
				{

					H_KPD_void_GetPressedKey(&key);
					if((key)!=255)
					{
						//get pass
						H_LCD_void_DispChar (key+48);
						//save pass
						arr_copy[i]=key;
						i++;
					}

					//pass 4 digt
					// if usr enter 4 numer will check
					if(i==4)
					{
						for(u8 m=0;m<4;m++)
						{
							if(ARR[m]==arr_copy[m])
							{
								//if one digt right will incres
								val++ ;
							}

						}
						// if val =4 that mean all pass right
						if(val==4)
						{
							H_LCD_void_GoToRowCol (1,5);
							H_LCD_void_DispChar('C'); // C mean correct
							H_voidServoMove(2300); //open door .... servo motor
						}
						// if val !=  4 that mean  pass wrong

						else {
							M_DIO_void_SetPinVal (PORTD_ID, PIN7_ID,PIN_HIGH_ID); // open buz
							H_LCD_void_GoToRowCol (1,5);
							H_LCD_void_DispChar('E'); // E mean Error
							_delay_ms(2000); // wait 2 sec
							M_DIO_void_SetPinVal (PORTD_ID, PIN7_ID,PIN_LOW_ID);  // close buz
						}
						val=0;
					}


				}
			}
		}
	}

	return 0 ;

}













//#define	ZERO 0X3F
//#define	ONE 0
//#define	TWO 0X5B
//#define	THREE 0X4F
//#define	FOUR 0X66
//#define	FIVE 0X6D
//#define	SIX 0X7D
//#define	SEVEN 0X07
//#define	EIGHT 0X7F
//#define	NINE 0X6F






//ADC_Value= ((u16)( ((u32)((u32)5000*(*DATA))) /((u32)1024) ));
//#define clearBits(R,M)		R &= ~(M)
//int main(void)
//
//{
//
// u32 ADC_Value ;
//	H_LCD_void_Init();
//	//M_ADC_void_Init();
//	 ADC_Init (); // ADC Initialization And Enable
//	 M_DIO_void_SetPortDir(PORTA,PIN_INPUT_ID);
//
//
//	while(1)
//	{
//		H_LCD_void_GoToRowCol (0, 0);
//		ADC_Value= ADC_Read (2);
//		//H_LCD_void_DispNum (ADC_Value);
//		 LCD_voidSendNumber		(ADC_Value);
//		//_delay_ms(10);
//
//		H_LCD_void_GoToRowCol (0, 0);
//	//M_ADC_void_ReadDigitalSync (CHANNEL2_ID, &DATA);
//
//
//	 //H_LCD_void_DispChar(ADC_Value);
//	}
//
//	return 0 ;
//}
