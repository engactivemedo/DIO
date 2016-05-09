/*
 * Schedular_interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: mahmoud
 */

#ifndef SCHEDULAR_INTERFACE_H_
#define SCHEDULAR_INTERFACE_H_


void RTO_INIT(void);
void RTO_SetTask(void (*ptrToTask)(void),u8 Copy_u8Periodicity,u8 Copy_u8StartTime,u8 copy_u8TaskPeriority);


#endif /* SCHEDULAR_INTERFACE_H_ */
