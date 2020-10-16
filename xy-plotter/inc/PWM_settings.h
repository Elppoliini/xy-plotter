/*
 * PWM_settings.h
 *
 *  Created on: 10 Oct 2020
 *      Author: johan
 */

#ifndef PWM_SETTINGS_H_
#define PWM_SETTINGS_H_

#include "chip.h"
#include "board.h"
#include "ITM_write.h"
#include <string>

#define LPC_SCT LPC_SCT0

/*******************************************************************************************
* Initialize PWM settings for pen and laser:
* Creating two independent PWM signals. (for more info see chapter 21 in SCT_PWM cookbook)
* Pen: PWM0 :SCT_L : SCT_OUT0 : Pins P0.10
* Laser: PWM1 :SCT_H : SCT_OUT1 : Pins P0.12
********************************************************************************************/
void SCT_Init();
/* Control the power of laser */
void laser_pwm_set(int percent);
/* Control the position of pen*/
void pen_pwm_set(int percent);

#endif /* PWM_SETTINGS_H_ */
