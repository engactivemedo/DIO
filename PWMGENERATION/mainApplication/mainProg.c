/*
 * mainProg.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: mahmoud
 */
#include"../headerfiles/types.h"
#include "../headerfiles/util.h"
#include "../SCHEDULARCORE/Schedular_interface.h"
#include "../headerfiles/DIOFiles/DIO_Interface.h"
#include "../headerfiles/DIOFiles/DIO_Private.h"
#include"../ADC_files/ADC_Interface.h"

#define FIRSTONEPERIODE 	40
#define SECONDZEROPERIODE 	140
#define ENDOFPERIODE 		1136

#define  MOTOR_U8UPFIVE    1
#define  MOTOR_U8DOWNFIVE  0
#define FIVESTEPS 1

#define relaeseSemaphore 		 GLopal_u8BinarySemaphore=0
#define captureSmaphore			 GLopal_u8BinarySemaphore=1
#define ISTHESEMAPHORERELEASED	 GLopal_u8BinarySemaphore==0

u8 GLopal_u8BinarySemaphore=1;
u8 Glopal_u8DutyCycleSaver[8];
void GetOnePosition(void);
void Change_DutyCycleBy5(u8 copy_u8MotorNo, u8 copy_u8Direction);

u8 Glopal_u8ADC_VAL;
u8 glopal_u88servoControllArray[100]=
		{
		0b11111111,
		0b11111111,
		0b11111111,
		0b11111111,
		0b11111111,
		0b11111111,
		0b11111111,
		0b11111111,
		0b11111111,
		0b11111111,
		0b11111111,
		0b11111111,
		0b11111111,
		0b11111111,
		0b11111111,
		0b11111111,
		0b11111111,
		0b11111111,
		0b11111111,
		0b11111111,
		0b11111111,
		0b11111111,
		0b11111111,
		0b11111111,
		0b11111111,
		0b11111111,
		0b11111111,
		0b11111111,
		0b01111111,
		0b01111111,
		0b00111111,
		0b00111111,
		0b00111111,
		0b00111111,
		0b00111111,
		0b00011111,
		0b00011111,
		0b00011111,
		0b00011111,
		0b00011111,
		0b00001111,
		0b00001111,
		0b00001111,
		0b00001111,
		0b00001111,
		0b00000111,
		0b00000111,
		0b00000111,
		0b00000111,
		0b00000111,
		0b00000011,
		0b00000011,
		0b00000011,
		0b00000011,
		0b00000011,
		0b00000011,
		0b00000011,
		0b00000001,
		0b00000001,
		0b00000001,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000};
//#define FIRSTONEPERIODE 	40
//#define SECONDZEROPERIODE 	140
//#define ENDOFPERIODE 		1136
void PWM_GENERATIONTASKPERIODIC() {
	static u16 count = 0;
	if (count < FIRSTONEPERIODE) {
		PORTB = 0xff;
	} else if (count < SECONDZEROPERIODE) {
		PORTB = glopal_u88servoControllArray[count - FIRSTONEPERIODE];
	} else if (count <= ENDOFPERIODE) {
		PORTB = 0x00;
		;
	} else {
		count = 0;
	}

	count++;
}

//read analog pin1->3
//set the global variable
//release the semaphore if there is any change in the system of three analog three semaphore
void changeMotor1Dutycyle() {
	if(Glopal_u8DutyCycleSaver[0]>Glopal_u8ADC_VAL){
		Change_DutyCycleBy5(0,MOTOR_U8DOWNFIVE);
	}
	else if(Glopal_u8DutyCycleSaver[0]<Glopal_u8ADC_VAL){
		Change_DutyCycleBy5(0,MOTOR_U8UPFIVE);

	}
	else{}


	//Change_DutyCycleBy5(1,MOTOR_U8DOWNFIVE);
//	Change_DutyCycleBy5(7,MOTOR_U8UPFIVE);
//	Change_DutyCycleBy5(1,MOTOR_U8DOWNFIVE);
//	Change_DutyCycleBy5(1,MOTOR_U8UPFIVE);

}

//
void startADC1ConvertionTask() {
	static u8 static_u8Oldstatus=0x00;
	captureSmaphore;
	switch (GetBit(static_u8Oldstatus, 0)) {
		case 0:
			//start convertion
			ADC_u8StartConvertion(ADC_U8Channel1);
			static_u8Oldstatus=1;
			break;
		case 1:
			//wait for convertion to end release the semaphor
			if(ADC_u8WaitForConvertion(ADC_U8Channel1))
			{
				static_u8Oldstatus=0;
				relaeseSemaphore;
			}
			else{

			}
			break;
		default:
			break;
	}

}

void getTheAdc0Val() {

	//wait for semaphore to be released
	if(ISTHESEMAPHORERELEASED)
	{
		Glopal_u8ADC_VAL=(ADC_u16ReadChannelOneShotNoWait(ADC_U8Channel1)/10);
		//the semaphore will be captured in the next task wwait for convertion
	}
	else{}
	//and get the value //catch the semaphore to block the function
}

void test5() {
//change the value of the system and decrease the error each time
}


int main (void)
{

GetOnePosition();
DIO_voidInit();
ADC_voidinit();
ADC_voidEnable();
RTO_SetTask(PWM_GENERATIONTASKPERIODIC,1,0,2);
RTO_SetTask(startADC1ConvertionTask,3,0,2);
RTO_SetTask(getTheAdc0Val,3,1,2);
RTO_SetTask(changeMotor1Dutycyle,3,2,2);
#if 0
RTO_SetTask(changeMotor1Dutycyle,1,0,2);
RTO_SetTask(test5,200,10,2);
#endif

RTO_INIT();
	while(1)
	{


	}
	return 0;
}


/*comment!: function to determine the initial duty cycle of eache servo and save it in the  Glopal_u8DutyCycleSaver*/
void Change_DutyCycleBy5(u8 copy_u8MotorNo, u8 copy_u8Direction) {
	u8 local_u8Mask;
	u8 local_u8Counter;
	u8 local_u8currentMotorDutyPosition=Glopal_u8DutyCycleSaver[copy_u8MotorNo];
	switch (copy_u8Direction) {
	case MOTOR_U8UPFIVE:
		local_u8Mask=(0x01<<copy_u8MotorNo);

		if ( local_u8currentMotorDutyPosition< (100-FIVESTEPS)) {

			for (local_u8Counter = 0; local_u8Counter < FIVESTEPS;
				 local_u8Counter++) {
					glopal_u88servoControllArray[local_u8currentMotorDutyPosition+local_u8Counter]|=local_u8Mask;
			}
			Glopal_u8DutyCycleSaver[copy_u8MotorNo]=Glopal_u8DutyCycleSaver[copy_u8MotorNo]+FIVESTEPS;
		} else {
		}

		break;

	case MOTOR_U8DOWNFIVE:
		local_u8Mask=~(0x01<<copy_u8MotorNo);
		//TODO make the downword system

		if ( local_u8currentMotorDutyPosition> FIVESTEPS) {
			//1 as  the pointer ponit to the next embty or zero place`
			for (local_u8Counter = 1; local_u8Counter <= FIVESTEPS;
				 local_u8Counter++) {
					glopal_u88servoControllArray[local_u8currentMotorDutyPosition-(local_u8Counter)]&=local_u8Mask;
			}
			Glopal_u8DutyCycleSaver[copy_u8MotorNo]=Glopal_u8DutyCycleSaver[copy_u8MotorNo]-FIVESTEPS;
		} else {
		}

		break;
	default:
		break;
	}

}


/*comment!: function to determine the initial duty cycle of eache servo and save it in the  Glopal_u8DutyCycleSaver*/
void GetOnePosition(void)
{ u8 testMatrix[2][2]={
						{2,1},
						{0,0}
					  };

	u8 local_u8Counter,local_u8Counter2;
u8 local_u8NEW,local_u8OLD=0;
for(local_u8Counter=0;local_u8Counter<8;local_u8Counter++)
{
	for(local_u8Counter2=0;local_u8Counter2<100;local_u8Counter2++)
	{
		local_u8NEW=GetBit(glopal_u88servoControllArray[local_u8Counter2],local_u8Counter);
		switch(testMatrix[local_u8NEW][local_u8OLD])
		{
		case 0:
			local_u8OLD=local_u8NEW;
			break;
		case 1:
			local_u8OLD=local_u8NEW;
			Glopal_u8DutyCycleSaver[local_u8Counter]=local_u8Counter2;
			break;
		default:
			break;

		}


	}//to search the 100 element
}//to fill the global variable / the pointer on the next position




}
