#include "myEncoder_hw.h"
#include "stm32f30x.h"                  // Device header

void myEncoder_hw_init(void){
	
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA,ENABLE);
	GPIO_InitTypeDef myGPIO;
	//Set A0 and A4  as inputs with pull-ups
	GPIO_StructInit(&myGPIO);
	myGPIO.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_4 ;
	myGPIO.GPIO_Mode = GPIO_Mode_IN;
	myGPIO.GPIO_PuPd = GPIO_PuPd_UP;
	myGPIO.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOA,&myGPIO);
	
	//set A1 as open-drain output
	GPIO_StructInit(&myGPIO);
	myGPIO.GPIO_Pin = GPIO_Pin_1 ;
	myGPIO.GPIO_Mode = GPIO_Mode_OUT;
	myGPIO.GPIO_OType = GPIO_OType_OD;
	myGPIO.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOA,&myGPIO);
	GPIO_ResetBits(GPIOA,GPIO_Pin_1);

	EXTI_InitTypeDef myEXTI;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG,ENABLE);

	//Enable both edge interrupt in A0
	EXTI_StructInit(&myEXTI);
	myEXTI.EXTI_LineCmd=ENABLE;
	myEXTI.EXTI_Line=EXTI_Line0;
	myEXTI.EXTI_Mode=EXTI_Mode_Interrupt;
	myEXTI.EXTI_Trigger=EXTI_Trigger_Rising_Falling;
	EXTI_Init(&myEXTI);
	
	//Enable both edge interrupt in A4
	EXTI_StructInit(&myEXTI);
	myEXTI.EXTI_LineCmd=ENABLE;
	myEXTI.EXTI_Line=EXTI_Line4;
	myEXTI.EXTI_Mode=EXTI_Mode_Interrupt;
	myEXTI.EXTI_Trigger=EXTI_Trigger_Rising_Falling;
	EXTI_Init(&myEXTI);
	
	
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA,EXTI_PinSource0);
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA,EXTI_PinSource4);
	
	EXTI_ClearITPendingBit(EXTI_Line0);
	EXTI_ClearITPendingBit(EXTI_Line4);
	
	NVIC_EnableIRQ(EXTI0_IRQn);
	NVIC_EnableIRQ(EXTI4_IRQn);
}

void EXTI0_IRQHandler(void){
	EXTI_ClearITPendingBit(EXTI_Line0);
	int chA = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0);
	int chB = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_4);
	myEncoder_hw_postEvent(chA,chB);
} 

void EXTI4_IRQHandler(void){
	EXTI_ClearITPendingBit(EXTI_Line4);
	int chA = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0);
	int chB = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_4);
	myEncoder_hw_postEvent(chA,chB);
}