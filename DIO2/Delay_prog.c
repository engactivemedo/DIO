/*
 * Delay_prog.c
 *
 *  Created on: Feb 3, 2016
 *      Author: mahmoud
 */
#include "Delay_Config.h"

/***********************************************************/
/************public functions like Macro********************/
/***********************************************************/
#define Delay_voidDelayms(Copyu8_TimeDelayInms)  do{u64 local_u64Counter,local_u64CounterInternal;\
													for (local_u64Counter=(Delay_u32CrystaValue*Copyu8_TimeDelayInms*1000); local_u64Counter>0; local_u64Counter--) {\
														__asm__("NOP");\
													}\
													}while(0)
