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


#define BUZZERPIN DIO_u8PIN9
#define LINEMAPPINGSLOPE 15

//timer 0 over flow ISR
 void  Interupt_voidTIMER0ISR(void) {
static u8 local_u8BuzzerVal=0x01;
local_u8BuzzerVal=Togglebit(local_u8BuzzerVal,0);
DIO_u8WritePinVal(BUZZERPIN,local_u8BuzzerVal);
}




int main(void) {
	u8 local_u8_keypadVal=0,oldVal=0;
	DIO_voidInit();
	KPD_voidInit();
	Timer0_voidSet_ISR(Interupt_voidTIMER0ISR);
	Timer0_voidInit();
while(1){
		KPD_u8Read(&local_u8_keypadVal);
		if (local_u8_keypadVal != oldVal) {
//			switch (local_u8_keypadVal) {
//			//left
//			case 1:
//				break;
//				//right
//			case 2:
//				break;
//				//rotate
//			case 3:
//				break;
//				//left
//			case 4:
//				break;
//				//right
//			case 5:
//				break;
//				//rotate
//			case 6:
//				break;
//
//				//right
//			case 7:
//				break;
//				//rotate
//			case 8:
//				break;
//
//				//left
//			case 9:
//				break;
//				//right
//			case 10:
//				break;
//				//rotate
//			case 11:
//				break;
//				//left
//			case 12:
//				break;
//				//right
//			case 13:
//				break;
//				//rotate
//			case 14:
//				break;
//
//				//right
//			case 15:
//				break;
//				//rotate
//			case 16:
//				break;
//			default:
//				break;
//
//			}
			//Timer0_voidWriteTimer0TCNT0(255/local_u8_keypadVal);
			if (local_u8_keypadVal == 0) {
				Timer0_voidClrTimerOVFInterupt();
				DIO_u8WritePinVal(BUZZERPIN,DIO_u8LOW);

			} else {
				Timer0_voidSetTimerOVFInterupt();
				//y=15*x ;     line equation mapping its slope =15
				Timer0_voidWriteTimer0TCNT0Permenant(LINEMAPPINGSLOPE*(local_u8_keypadVal));
			}


						 				}else{}
				oldVal=local_u8_keypadVal;
			}

	return 0;
}

