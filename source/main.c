#include "myEncoder.h"
#include "encoder.h"
#include "nDisplay.h"
#include "nDisplay_leds.h"

void encoderOnChangeCallback(encoder_handle eHandle);

int main(){
	//Initialization
	encoder_handle myEncoder = getMyEncoderHandle();
	nDisplay_handle myDisplay= getLedDisplayHandle();
	
	int encoderVal = encoder_getPosition(myEncoder);
	nDisplay_setVal(myDisplay, encoderVal);
	
	encoder_setOnChangeCallback(myEncoder, encoderOnChangeCallback);
	
	while(1);
}

void encoderOnChangeCallback(encoder_handle eHandle){
	encoder_handle myEncoder = getMyEncoderHandle();
	nDisplay_handle myDisplay= getLedDisplayHandle();
	
	int encoderVal = encoder_getPosition(myEncoder);
	nDisplay_setVal(myDisplay, encoderVal);
}
