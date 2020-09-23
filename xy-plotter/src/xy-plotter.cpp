/*
===============================================================================
 Name        : main.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
 */

#if defined (__USE_LPCOPEN)
#if defined(NO_BOARD_LIB)
#include "chip.h"
#else
#include "board.h"
#endif
#endif

#include <cr_section_macros.h>
#include "ITM_write.h"

// TODO: insert other include files here

// TODO: insert other definitions and declarations here

#include "FreeRTOS.h"
#include "task.h"
//#include "Parser.h"
#include <string>
#include <algorithm>
#include "LpcUart.h"
#include "Parser.h"

/*****************************************************************************
 * Setup
 ****************************************************************************/
/* Sets up system hardware */
static void prvSetupHardware(void)
{
	SystemCoreClockUpdate();
	Board_Init();
	ITM_init();
	/* Initial LED0 state is off */
	Board_LED_Set(0, false);
}

LpcUartConfig LpcUart_Setup(){
	LpcPinMap none = {-1, -1}; // unused pin has negative values in it
	LpcPinMap txpin = { 0, 18 }; // transmit pin that goes to debugger's UART->USB converter
	LpcPinMap rxpin = { 0, 13 }; // receive pin that goes to debugger's UART->USB converter
	LpcUartConfig cfg = { LPC_USART0, 115200, UART_CFG_DATALEN_8 | UART_CFG_PARITY_NONE | UART_CFG_STOPLEN_1, false, txpin, rxpin, none, none };
	LpcUart dbgu(cfg);
	return cfg;
}
/*****************************************************************************
 * Tasks
 ****************************************************************************/
static void vReadInput(void *pvParameters) {
	LpcUartConfig cfg = LpcUart_Setup();
	LpcUart u1(cfg);

	int c;
	Parser p;
	while(1){
		char str[80];
		c = u1.read(str, 80, portTICK_PERIOD_MS*100);
		if(c !=0)
		{

			str[80] = '\0';
			p.read(str);
			u1.write("OK\r\n");
			p.reply();
		}

	}
}

/*****************************************************************************
 * Public functions
 ****************************************************************************/

/* the following is required if runtime statistics are to be collected */
extern "C" {

void vConfigureTimerForRunTimeStats( void ) {
	Chip_SCT_Init(LPC_SCTSMALL1);
	LPC_SCTSMALL1->CONFIG = SCT_CONFIG_32BIT_COUNTER;
	LPC_SCTSMALL1->CTRL_U = SCT_CTRL_PRE_L(255) | SCT_CTRL_CLRCTR_L; // set prescaler to 256 (255 + 1), and start timer
}

}
/* end runtime statictics collection */

/**
 * @brief	main routine for FreeRTOS blinky example
 * @return	Nothing, function should not exit
 */
int main(void)
{
	prvSetupHardware();

	/* UART output thread, simply counts seconds */
	/*xTaskCreate(vUARTTask, "vTaskUart",
			configMINIMAL_STACK_SIZE + 128, NULL, (tskIDLE_PRIORITY + 1UL),
			(TaskHandle_t *) NULL);*/
	xTaskCreate(vReadInput, "vReadInput",
			configMINIMAL_STACK_SIZE * 10, NULL, (tskIDLE_PRIORITY + 1UL),
			(TaskHandle_t *) NULL);

	/* Start the scheduler */
	vTaskStartScheduler();

	/*	Parser h;
		h.readCommmand();*/


	/* Should never arrive here */
	return 1;
}

