/*
 * SpeedSettings.cpp
 *
 *  Created on: 11 Oct 2020
 *      Author: johan
 */

#include "SpeedSettings.h"

volatile uint32_t RIT_count;
volatile bool RIT_axis;
volatile bool RIT_dir;
EventGroupHandle_t xEventGroup;

void RIT_start(int count, int us , bool axis, bool dir)
{
	EventBits_t uxBits;
	uint64_t cmp_value;
	// Determine approximate compare value based on clock rate and passed interval
	cmp_value = (uint64_t) Chip_Clock_GetSystemClockRate() * (uint64_t) us / 1000000;
	// disable timer during configuration
	Chip_RIT_Disable(LPC_RITIMER);
	RIT_count = count;
	RIT_axis = axis;
	RIT_dir = dir;
	// enable automatic clear on when compare value==timer value
	// this makes interrupts trigger periodically
	Chip_RIT_EnableCompClear(LPC_RITIMER);
	// reset the counter
	Chip_RIT_SetCounter(LPC_RITIMER, 0);
	Chip_RIT_SetCompareValue(LPC_RITIMER, cmp_value);
	// start counting
	Chip_RIT_Enable(LPC_RITIMER);
	// Enable the interrupt signal in NVIC (the interrupt controller)
	NVIC_EnableIRQ(RITIMER_IRQn);
	// wait for ISR to tell that we're done
	uxBits = xEventGroupWaitBits(xEventGroup, BIT_1 ,pdTRUE,pdTRUE, portMAX_DELAY);
	if((uxBits & (BIT_1)) != 0) {
		// Disable the interrupt signal in NVIC (the interrupt controller)
		NVIC_DisableIRQ(RITIMER_IRQn);
	}
	else {
		// unexpected error
		ITM_write("Unexpected error at RIT_start\r\n");
	}
}

