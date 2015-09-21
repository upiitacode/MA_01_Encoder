#include "nDisplay.h"
#include "stdlib.h"

typedef struct{
	int value;
	void (*displayValFcn)(int);
} nDisplay_t;

nDisplay_handle nDisplay_new(void (*dispValFcn)(int), int initialVal){
	nDisplay_t* nDisp = malloc(sizeof(nDisp));
	
	nDisp->value=initialVal;
	nDisp->displayValFcn=dispValFcn;
	
	return nDisp;
}

void nDisplay_setVal(nDisplay_handle dispHandle, int val){
	nDisplay_t* nDisp = dispHandle;
	nDisp->value = val;
	nDisp->displayValFcn(val);
}

int nDisplay_getVal(nDisplay_handle dispHandle){
	nDisplay_t* nDisp = dispHandle;
	return nDisp->value;
}
