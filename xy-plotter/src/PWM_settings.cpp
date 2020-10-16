#include "PWM_settings.h"

void SCT_Init(void)
{
	// PEN SETTINGS
	Chip_SWM_MovablePortPinAssign(SWM_SCT0_OUT0_O,0,10);
	LPC_SCT->CONFIG |= (1 << 17); // two 16-bit timers, auto limit
	LPC_SCT->CTRL_L |= (72-1) << 5; // set prescaler, SCTimer/PWM clock = 1 MHz
	LPC_SCT->MATCHREL[0].L = 20000 -1; // match 0 @ 20000/1MHz = 20ms (50Hz PWM freq)
	LPC_SCT->MATCHREL[1].L = 1000; // match 1 used for duty cycle (in 10 steps)
	LPC_SCT->EVENT[0].STATE = 0xFFFFFFFF; // event 0 happens in all states
	LPC_SCT->EVENT[0].CTRL = (1 << 12); // match 0 (pwm_cycle) only condition
	LPC_SCT->EVENT[1].STATE = 0xFFFFFFFF; // event 1 happens in all states
	LPC_SCT->EVENT[1].CTRL = (1 << 0) | (1 << 12); // match 1 only condition
	LPC_SCT->OUT[0].SET = (1 << 0); // event 0 sets OUT0 (PWM0)
	LPC_SCT->OUT[0].CLR = (1 << 1); // event 1 clear OUT0 (PWM0)
	LPC_SCT->CTRL_L &= ~(1 << 2); // start timer

	// LASER SETTINGS
	Chip_SWM_MovablePortPinAssign(SWM_SCT0_OUT1_O,0,12);
	LPC_SCT->CONFIG |= (1 << 18); // two 16-bit timers, auto limit
	LPC_SCT->CTRL_H |= (72-1) << 5; // set prescaler, SCTimer/PWM clock = 1 MHz
	LPC_SCT->MATCHREL[0].H = 1000 -1; // match 0 @ 1000/1MHz = 1 ms (1 kHz PWM freq)
	LPC_SCT->MATCHREL[1].H = 0; // match 1 used for duty cycle (in 10 steps)
	LPC_SCT->EVENT[2].STATE = 0xFFFFFFFF; // event 0 happens in all states
	LPC_SCT->EVENT[2].CTRL = (1 << 4)|(1 << 12); //ev 1 belongs to the H timer, match 0 only condition
	LPC_SCT->EVENT[3].STATE = 0xFFFFFFFF; // event 1 happens in all states
	LPC_SCT->EVENT[3].CTRL = (1 << 0) | (1 << 4) | (1 << 12); // ev 1 belongs to the H timer, match 1 only condition
	LPC_SCT->OUT[1].SET = (1 << 2); // event 2 sets OUT1 (PWM1)
	LPC_SCT->OUT[1].CLR = (1 << 3); // event 3 clear OU1 (PWM1)
	LPC_SCT->CTRL_H &= ~(1 << 2); // start timer
}

void laser_pwm_set(int percent)
{
	if(percent > 0) {
		LPC_SCT->OUT[1].SET = (1 << 2); // event 2 will set SCTx_OUT1
		LPC_SCT->MATCHREL[1].H = percent * 10;
	}
	else {
		LPC_SCT->OUT[1].SET = 0; // event 2 has no effect on  SCTx_OUT1 --> laser is always off
		LPC_SCT->MATCHREL[1].H = 1;
	}
}

void pen_pwm_set(int percent)
{
	int position = 1000 + (percent*10);
	LPC_SCT->MATCHREL[1].L = position + 20;
}



