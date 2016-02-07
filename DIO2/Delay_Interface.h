/*
 * Delay_Interface.h
 *
 *  Created on: Feb 5, 2016
 *      Author: mahmoud
 */

#ifndef DELAY_INTERFACE_H_
#define DELAY_INTERFACE_H_

#include "Delay_Config.h"

/***********************************************************/
/************public functions like Macro********************/
/***********************************************************/
#define Delay_voidDelayms(Copyu8_TimeDelayInms)  do{u64 local_u64Counter;\
													for(local_u64Counter=(Delay_u32CrystaValue*Copyu8_TimeDelayInms*1000);local_u64Counter>0;local_u64Counter--) {\
														__asm__("NOP");\
													}\
													}while(0)


#endif /* DELAY_INTERFACE_H_ */
