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
	static u8 local_u8Timer0OVFCounter1 = 0;
	static u8 local_u8Timer0OVFCounter2 = 0;
	static u8 local_u8Timer0OVFCounter3 = 0;

	static u8 pin1 =0x01;
	static u8 pin2 =0x01;
	static u8 pin3 =0x01;


	local_u8Timer0OVFCounter1++;
	local_u8Timer0OVFCounter2++;
	local_u8Timer0OVFCounter3++;

	//its time to move the part on the dot matrix

		 if(local_u8Timer0OVFCounter1 == MOVINGPARTSTIME)
		 {	local_u8Timer0OVFCounter1=0;
			 pin1=Togglebit(pin1,0);
			 DIO_u8WritePinVal(led1Pin,(glopal_led1&pin1));
		 }else{
			}

		 if(local_u8Timer0OVFCounter2 == 122)
				 {
			 local_u8Timer0OVFCounter2=0;
			 pin2=Togglebit(pin2,0);
			 DIO_u8WritePinVal(led2Pin,(glopal_led2&pin2));


				 }else{
					}

		 if(local_u8Timer0OVFCounter3 == 62)
				 {
			 local_u8Timer0OVFCounter3=0;
			 pin3=Togglebit(pin3,0);
			 DIO_u8WritePinVal(led3Pin,(glopal_led3&pin3));


				 }else{
					}


}



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

int main(void) {
	u8 local_u8_keypadVal=0,oldVal=0;
	DIO_voidInit();
	KPD_voidInit();
	 DIO_u8WritePinVal(DIO_u8PIN30,DIO_u8LOW);
	// DIO_u8WritePinVal(DIO_u8PIN30,DIO_u8HIGH);
	 Delay(250);
	Timer0_voidSet_ISR(Interupt_voidTIMER0ISR);
	 //DIO_u8WritePinVal(DIO_u8PIN30,DIO_u8LOW);

	Timer0_voidInit();
	InteruptInit();

while(1){

	KPD_u8Read(&local_u8_keypadVal);
			if(local_u8_keypadVal!=oldVal)
			{
				switch(local_u8_keypadVal)
				{
				//left
				case 5:
					led1=Togglebit(led1,0);
					break;
				//right
				case 7:
					led2=Togglebit(led2,0);
					break;
					//rotate
				case 6:
					led3=Togglebit(led3,0);
					break;
				default:
					break;


				}

						 				}else{}

				oldVal=local_u8_keypadVal;
			}

	return 0;
}


void InteruptInit(void)
{
	ExtInter_u8MCUCR=Setbit(ExtInter_u8MCUCR,0);
	ExtInter_u8MCUCR=Clrbit(ExtInter_u8MCUCR,1);

	ExtInter_u8GICR=Setbit(ExtInter_u8GICR,6);


//	__asm__("SEI");
}

