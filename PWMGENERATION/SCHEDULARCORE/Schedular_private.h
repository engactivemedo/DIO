/*
 * Schedular_private.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: mahmoud
 */

#ifndef SCHEDULAR_PRIVATE_H_
#define SCHEDULAR_PRIVATE_H_

// its a structure that will carry the data about each task
typedef struct {
	void (*ptrToTask)(void);
	u8 periodicity;
	u8 periority;
	u8 StartTime;
	u8 HowManyTimeThatRTOCalledIt;
} RTO_structTCB;






#endif /* SCHEDULAR_PRIVATE_H_ */
