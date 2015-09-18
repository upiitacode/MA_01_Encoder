#include "myEncoder.h"
#include "myEncoder_hw.h"
#include "encoder.h"
#include <stdlib.h>

static encoder_handle myEncoder = NULL;

encoder_handle getMyEncoderHandle(void){
	if(myEncoder == NULL){
		myEncoder = encoder_new();
		myEncoder_hw_init();
	}
	
	return myEncoder;
}

void myEncoder_hw_postEvent(int chA, int chB){
	encoder_postEvent(myEncoder,chA,chB);
}
