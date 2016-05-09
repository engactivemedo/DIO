/*
 * Schedular_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: mahmoud
 */
#include"../headerfiles/types.h"
#include"../headerfiles/util.h"
#include"../TIMER0/TIMER0_Interface.h"
#include"Schedular_config.h"
#include "Schedular_private.h"

/***********************************************************/
/******************GLOBAL VARIABLES*************************/
/***********************************************************/

/***********************************************************/
/*****************PRIVATE VARIABLES*************************/
/***********************************************************/

static RTO_structTCB RTO_StructTCB[MAXTASKNUMBER];
static u8 RTO_u8teRemaningTicksforEacTask[MAXTASKNUMBER];
/***********************************************************/
/*****************PRIVATE functions*************************/
/***********************************************************/


 static void RTO_Schedular(void){
	 	u8 local_u8counter=0;
		for(local_u8counter=0;local_u8counter<MAXTASKNUMBER;local_u8counter++)
		 	{
		 		//decrement the waiting number for each task as it will be served at 1 the zero will reset the current no
		 		//withe the no the user defined if the no is one then the system will serve the task
		 		if(RTO_u8teRemaningTicksforEacTask[local_u8counter]==1)
		 		{
		 			//this counnter is to know how many time the RTO Called the system
#ifdef HowManyTimeThatRTOCalledTasks
#if HowManyTimeThatRTOCalledTasks==1
		 			RTO_StructTCB[local_u8counter].HowManyTimeThatRTOCalledIt++;
#endif
#endif	 			//call the TASK
		 			RTO_StructTCB[local_u8counter].ptrToTask();
		 		}
		 		else{}

		 	}
 }


 static void RTO_ISR(void){
	 	u8 local_u8counter=0;
	 	for(local_u8counter=0;local_u8counter<MAXTASKNUMBER;local_u8counter++)
	 	{
	 		//decrement the waiting number for each task as it will be served at 1 the zero will reset the current no
	 		//withe the no the user defined

	 		RTO_u8teRemaningTicksforEacTask[local_u8counter]--;
	 		if(RTO_u8teRemaningTicksforEacTask[local_u8counter]==0)
	 		{
	 			RTO_u8teRemaningTicksforEacTask[local_u8counter]=RTO_StructTCB[local_u8counter].periodicity;
	 		}
	 		else{}

	 	}

		RTO_Schedular();

}

/***********************************************************/
/******************public functions*************************/
/***********************************************************/
/*Comments!:  PIN Initial Value   */
extern void RTO_INIT(void){
	u8 Local_u8Counter=0;
	//TODO set tick time for future use //Initialize the system TICK timer


	//adding the RTO_isr to the system
	Timer0_voidSet_ISRCompareMatch(RTO_ISR);
	//TODO do not forget to Initialize the counter for .5 sec over flow and to initialize the timer overflow

	//set the first call time of each Task
	for(Local_u8Counter=0;Local_u8Counter<MAXTASKNUMBER;Local_u8Counter++)
	{
	RTO_u8teRemaningTicksforEacTask[Local_u8Counter]=(RTO_StructTCB[Local_u8Counter].StartTime)+1;
	}
	//RTO SCHEDULAR CALL for first start

	//enable timer
	Timer0_voidInit();
	//start os Services
	RTO_Schedular();




}

//rto_setTask Properties task name ,periodicity with respect to System Task, start time we it will start, the pirority of the task for future use
 extern void RTO_SetTask(void (*ptrToTask)(void),u8 Copy_u8Periodicity,u8 Copy_u8StartTime,u8 copy_u8TaskPeriority){
	 static u8 local_u8TCBCounter=0;
	 //copy the data of the task into the TCB(Task control block)
	 RTO_StructTCB[local_u8TCBCounter].ptrToTask=ptrToTask;
	 RTO_StructTCB[local_u8TCBCounter].periodicity=Copy_u8Periodicity;
	 RTO_StructTCB[local_u8TCBCounter].periority=copy_u8TaskPeriority;
	 RTO_StructTCB[local_u8TCBCounter].StartTime=Copy_u8StartTime;
	 RTO_StructTCB[local_u8TCBCounter].HowManyTimeThatRTOCalledIt=0;
	 //adding one to the counter to be prepare  for the next task
	 local_u8TCBCounter++;

}
