/*
 * SpeedSettings.h
 *
 *  Created on: 11 Oct 2020
 *      Author: johan
 */

#ifndef SPEEDSETTINGS_H_
#define SPEEDSETTINGS_H_

#include "FreeRTOS.h"
#include "DigitalIoPin.h"
#include <event_groups.h>
#include "ITM_write.h"

extern volatile uint32_t RIT_count;
extern volatile bool RIT_axis;
extern volatile bool RIT_dir;
extern EventGroupHandle_t xEventGroup;

#define BIT_1	( 1 << 1 )

/********************************************************************
 * Activate RIT interrupt and control the stepper motor movements.
 * count: to gain a step make count = 2.
 * us: us is time in microsecond.To get speed use this formula 1000000/(speed*2).
 * axis: if axis is true movement in the Y motor
 * if axis is false we get movement in X motor.
 *********************************************************************/
void RIT_start(int count, int us , bool axis, bool dir);

#endif /* SPEEDSETTINGS_H_ */
