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

#define ExtInter_u8MCUCR 		*((volatile u8*)(0x55))
#define ExtInter_u8MCUCSK		*((volatile u8*)(0x54))
#define ExtInter_u8GICR			*((volatile u8*)(0x5B))
#define ExtInter_u8GIFR			*((volatile u8*)(0x5A))

#define led1Pin DIO_u8PIN8
#define led2Pin DIO_u8PIN9
#define led3Pin DIO_u8PIN10

#define MOVINGPARTSTIME			 245   //1sec
void InteruptInit(void);

u8 led1=0,led2=0,led3=0;
u8 glopal_led1=0,glopal_led2=0,glopal_led3=0;
u8 glopal_int=0;

//timer 0 over flow ISR
 void  Interupt_voidTIMER0ISR(void) {
	static u8 local_u8Timer0OVFCounter1 = 0x01;
	DIO_u8WritePinVal(DIO_u8PIN8,local_u8Timer0OVFCounter1)
	local_u8Timer0OVFCounter1=Togglebit(local_u8Timer0OVFCounter1,0);
}



/*
 ISR(__vector_1)
 {
 	static u8 local_u8counter=0;
 //	static u8 local_u8prevVal=0x01;

 	local_u8counter++;
// 	if(local_u8counter==4)
// 	{

 //		local_u8counter=0;
 		 glopal_led1=led1;
 		 glopal_led2=led2;
 		 glopal_led3=led3;

// 	}
// 	else {
// 	}


 }
*/

int main(void) {
	u8 local_u8_keypadVal=0,oldVal=0;
	KPD_voidInit();
	DIO_voidInit();
	Timer0_voidSet_ISR(Interupt_voidTIMER0ISR);
	Timer0_voidInit();
while(1){

	KPD_u8Read(&local_u8_keypadVal);
			if(local_u8_keypadVal!=oldVal)
			{
				switch(local_u8_keypadVal)
				{
				//left
				case 5:
					break;
				//right
				case 7:
					break;

				default:
					break;


				}

						 				}else{}

				oldVal=local_u8_keypadVal;
			}

	return 0;
}



