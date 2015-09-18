#include "window_manager.h"
#include "myWindows.h"
#include "serial_stdio.h"
#include "LCD.h"
#include "myEncoder.h"

Serial_t LCD_Serial = {NULL, lcd_sendChar};

window_t window1 = {redraw1, eventHandler1};
window_t window2 = {redraw2, eventHandler2};
window_t window3 = {redraw3, eventHandler3};

static encoder_handle knob;

void myWindowInit(void){
	lcd_init();
	knob = getMyEncoderHandle();
	window_init(&window1);
}

void eventHandler1(int event){
	if(event == WINDOW_EVENT_ON_CREATE){
	}
	else if(event == WINDOW_EVENT_ON_EXIT){
	}
	else if(event == WINDOW_EVENT_BUTTON_A){
	}
	else if(event == WINDOW_EVENT_BUTTON_B){
		window_changeWindow(&window2);
	}
	else if(event == WINDOW_EVENT_ENCODER_CHANGED){
		lcd_goto(9,0);
		serial_printf(LCD_Serial, "%d     ",encoder_getPosition(knob));
	}
}

void eventHandler2(int event){
	if(event == WINDOW_EVENT_ON_CREATE){
	}
	else if(event == WINDOW_EVENT_ON_EXIT){
	}
	else if(event == WINDOW_EVENT_BUTTON_A){
		window_changeWindow(&window1);
	}
	else if(event == WINDOW_EVENT_BUTTON_B){
		window_changeWindow(&window3);
	}
}

void eventHandler3(int event){
	if(event == WINDOW_EVENT_ON_CREATE){
	}
	else if(event == WINDOW_EVENT_ON_EXIT){
	}
	else if(event == WINDOW_EVENT_BUTTON_A){
		window_changeWindow(&window2);
	}
	else if(event == WINDOW_EVENT_BUTTON_B){
	}
}

void redraw1(void){
	serial_printf(LCD_Serial, "\fENCODER: %d\n",encoder_getPosition(knob));
}
void redraw2(void){
	serial_printf(LCD_Serial, "\fDrawing window 2\n");
}
void redraw3(void){
	serial_printf(LCD_Serial, "\fDrawing window 3\n");
}
