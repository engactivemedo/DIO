/*
 * TIMER0.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: mahmoud
 */
#include"TIMER0_Config.h"
#include"TIMER0_Private.h"
#include"../headerfiles/InteruptVector.h"
#include"../headerfiles/util.h"
#include"../headerfiles/types.h"

static void (* Timer0_InteruptPointer)(void);
static u8 glopal_u8tcnt0StartVal=0;


void Timer0_voidSet_ISR(void (*Copy_PtrToISR)(void))
{
	Timer0_InteruptPointer=Copy_PtrToISR;
}

void Timer0_voidInit(void)
{
		//	//the prescaler =64
			TIMER0_u8TCCR0=0X03;
	//		TIMER0_u8TIMSK=Setbit(TIMER0_u8TIMSK,TIMER0_u8TIMSK_TOIE0);
			//enable Glopal Interupt
			__asm__("SEI");
}

void Timer0_voidReadTimer0TCNT0(u8 *ptrToVal)
{
	*ptrToVal=TIMER0_u8TCNT0;
}


void Timer0_voidCheckForInterupt(u8 *ptrToValOverflow,u8 *ptrToValCompareMatch)
{
	*ptrToValOverflow=GetBit(TIMER0_u8TIFR,TIMER0_u8TIFR_TOV0);
	*ptrToValCompareMatch=GetBit(TIMER0_u8TIFR,TIMER0_u8TIFR_OCF0);
}


void Timer0_voidWriteTimer0TCNT0(u8 copy_u8ValToWrite){

	TIMER0_u8TCNT0=copy_u8ValToWrite;

}
void Timer0_voidWriteTimer0TCNT0Permenant(u8 copy_u8ValToWrite) {
	glopal_u8tcnt0StartVal = copy_u8ValToWrite;
}

void Timer0_voidSetTimerOVFInterupt(void)
{
	TIMER0_u8TIMSK=Setbit(TIMER0_u8TIMSK,TIMER0_u8TIMSK_TOIE0);

}


void Timer0_voidClrTimerOVFInterupt(void)
{
	TIMER0_u8TIMSK=Clrbit(TIMER0_u8TIMSK,TIMER0_u8TIMSK_TOIE0);

}
//timer 0 over flow ISR
ISR(__vector_11) {
	TIMER0_u8TCNT0=glopal_u8tcnt0StartVal;
	Timer0_InteruptPointer();
}
