#include "stm32f30x.h"                  // Device header
#include "serial_stdio.h"
#include "retarget_stm32f3.h"
#include "window_manager.h"
#include "myWindows.h"
#include <string.h>
/*Led PB13, Button PC13*/

void delay_ms(int delay_time);
void led_init(void);
void buttons_init(void);

Serial_t USART1_Serial={USART1_getChar,USART1_sendChar};
Serial_t USART2_Serial={USART2_getChar,USART2_sendChar};

char mybf[80];/*Input buffer*/
char wordBuffer[80];

int main(){
	int lastState = 0;
	int lastStateButtonA = 1;
	int lastStateButtonB = 1;
	int newStateButtonA = 1;
	int newStateButtonB = 1;
	
	led_init();
	buttons_init();
	USART2_init(9600);
	myWindowInit();
	
	serial_puts(USART2_Serial,"\nSystem ready\n");
	while(1){
		
		GPIO_WriteBit(GPIOB, GPIO_Pin_13, lastState);
		lastState = !lastState;
		
		newStateButtonA = GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_0);
		newStateButtonB = GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_1);
		
		if((lastStateButtonA == 1) && (newStateButtonA == 0))
			window_postEvent(WINDOW_EVENT_BUTTON_A);
		if((lastStateButtonB == 1) && (newStateButtonB == 0))
			window_postEvent(WINDOW_EVENT_BUTTON_B);
		
		lastStateButtonA =  newStateButtonA;
		lastStateButtonB =  newStateButtonB;
		
		delay_ms(0x0CFFF);
	}
	return 0;
}


void led_init(void){
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB,ENABLE);
	GPIO_InitTypeDef myGPIO;
	GPIO_StructInit(&myGPIO);
	myGPIO.GPIO_Pin=GPIO_Pin_13;
	myGPIO.GPIO_Mode=GPIO_Mode_OUT;
	myGPIO.GPIO_OType=GPIO_OType_PP;
	myGPIO.GPIO_PuPd=GPIO_PuPd_NOPULL;
	myGPIO.GPIO_Speed=GPIO_Speed_10MHz;
	GPIO_Init(GPIOB,&myGPIO);
	GPIO_WriteBit(GPIOB,GPIO_Pin_13,Bit_RESET);
}

/**
 * Configure PC0 and PC1 as inputs with pull-ups
 */
void buttons_init(void){
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC,ENABLE);
	GPIO_InitTypeDef myGPIO;
	GPIO_StructInit(&myGPIO);
	myGPIO.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 ;
	myGPIO.GPIO_Mode = GPIO_Mode_IN;
	myGPIO.GPIO_PuPd = GPIO_PuPd_UP;
	myGPIO.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOC,&myGPIO);
}

void delay_ms(int delay_time){
	for(int i=0; i<delay_time; i++);
}
