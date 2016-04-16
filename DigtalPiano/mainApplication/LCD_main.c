/*
 * LCD_main.c
 *
 *  Created on: Mar 9, 2016
 *      Author: mahmoud
 */

#include"../headerfiles/types.h"
#include"../headerfiles/util.h"
#include"../headerfiles/DIOFiles/DIO_Interface.h"
#include"../headerfiles/kpd/KPD_interface.h"
#include"../TIMER0/TIMER0_Interface.h"
#include"../headerfiles/DelayFiles/Delay_prog.c"
#include"../headerfiles/InteruptVector.h"
#include"../headerfiles/ADC_files/ADC_Interface.h"


#define BUZZERPIN DIO_u8PIN9

//timer 0 over flow ISR
 void  Interupt_voidTIMER0ISR(void) {




}




int main(void) {

	DIO_voidInit();
	Timer0_voidSet_ISR(Interupt_voidTIMER0ISR);
	Timer0_voidInit();

while(1){
					}


	return 0;
}

