/* 
 * File:   myWindows.h
 * Author: eLimones <limonesu.me@gmail.com>
 *
 * Created on September 13, 2015, 1:21 AM
 */

#ifndef MYWINDOWS_H
#define	MYWINDOWS_H

#ifdef	__cplusplus
extern "C" {
#endif

#define WINDOW_EVENT_BUTTON_A 2
#define WINDOW_EVENT_BUTTON_B 3
#define WINDOW_EVENT_BUTTON_C 4

	void myWindowInit(void);
	
	void redraw1(void);
	void redraw2(void);
	void redraw3(void);

	void eventHandler1(int event);
	void eventHandler2(int event);
	void eventHandler3(int event);

#ifdef	__cplusplus
}
#endif

#endif	/* MYWINDOWS_H */

