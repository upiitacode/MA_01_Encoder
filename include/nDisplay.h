/* 
 * File:   nDisplay.h
 * Author: eLimones <limonesu.me@gmail.com>
 *
 * Created on September 20, 2015, 8:01 PM
 */

#ifndef NDISPLAY_H
#define	NDISPLAY_H

#ifdef	__cplusplus
extern "C" {
#endif

	typedef void * nDisplay_handle;
	nDisplay_handle nDisplay_new(void (*dispValFcn)(int), int initialVal);
	void nDisplay_setVal(nDisplay_handle dispHandle, int val);
	int nDisplay_getVal(nDisplay_handle dispHandle);

#ifdef	__cplusplus
}
#endif

#endif	/* NDISPLAY_H */
