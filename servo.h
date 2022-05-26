/*
 * servo.h
 *
 *  Created on: May 25, 2022
 *      Author: General
 */

#ifndef SERVO_H_
#define SERVO_H_

#include <avr/io.h>
#include "StdTypes.h"
#include "BitMath.h"
#include "ADC.h"
//#define F_CPU  (u32)8000000


void H_voidInitServo(void);

void H_voidServoMove(u16 copy_u16_servo);

//u16 H_voidReadChannlServo(u16 copy_u16_servoChannel);

#endif /* SERVO_H_ */
