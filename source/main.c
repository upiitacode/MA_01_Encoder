#include <string.h>
#include "serial_stdio.h"
#include "retarget_stm32f3.h"
#include "myEncoder.h"
#include "encoder.h"

void delay_ms(int delay_time);

Serial_t USART1_Serial={USART1_getChar,USART1_sendChar};
Serial_t USART2_Serial={USART2_getChar,USART2_sendChar};

void myEncoderCallBack(encoder_handle eHandle);

int main(){
	USART2_init(9600);
	serial_puts(USART2_Serial,"\nSystem ready\n");

	encoder_handle myEncoder = getMyEncoderHandle();
	encoder_setCallback(myEncoder, myEncoderCallBack);
	
	while(1);
}

void myEncoderCallBack(encoder_handle eHandle){
	serial_printf(USART2_Serial,"encoder: %d\n",encoder_getPosition(eHandle));
}
