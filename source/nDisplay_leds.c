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
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef myGPIO;
	GPIO_StructInit(&myGPIO);
	myGPIO.GPIO_Pin = GPIO_Pin_15 | GPIO_Pin_14 |GPIO_Pin_13 | GPIO_Pin_12 |
			GPIO_Pin_11 | GPIO_Pin_10 | GPIO_Pin_9 | GPIO_Pin_8;
	myGPIO.GPIO_Mode = GPIO_Mode_OUT;
	myGPIO.GPIO_OType = GPIO_OType_PP;
	GPIO_Init(GPIOB, &myGPIO);
}

static void leds_output(int val){
	int outputByte = (val & 0xFF);
	GPIO_Write(GPIOB, (outputByte << 8));
}