/* 
 * File:   myEncoder_hw.h
 * Author: eLimones <limonesu.me@gmail.com>
 *
 * Created on September 18, 2015, 3:56 AM
 */

#ifndef MYENCODER_HW_H
#define	MYENCODER_HW_H

#ifdef	__cplusplus
extern "C" {
#endif

void myEncoder_hw_postEvent(int chA, int chB);
void myEncoder_hw_init(void);

#ifdef	__cplusplus
}
#endif

#endif	/* MYENCODER_HW_H */

