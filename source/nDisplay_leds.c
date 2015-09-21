#include "nDisplay_leds.h"
#include "stdlib.h"
#include "serial_stdio.h"
#include "retarget_stm32f3.h"


static void leds_output(int val);
static void leds_hw_init(void);

Serial_t USART1_Serial={USART1_getChar,USART1_sendChar};
Serial_t USART2_Serial={USART2_getChar,USART2_sendChar};

static nDisplay_handle ledDisplay = NULL;

nDisplay_handle getLedDisplayHandle(void){
	if(ledDisplay == NULL){
		ledDisplay = nDisplay_new(leds_output, 0);
		leds_hw_init();
	}
	return ledDisplay;
}

static void leds_hw_init(void){
	USART2_init(9600);
	serial_puts(USART2_Serial,"\nSystem ready\n");
}

static void leds_output(int val){
	serial_printf(USART2_Serial,"\nDisplay: %d\n", val);
}