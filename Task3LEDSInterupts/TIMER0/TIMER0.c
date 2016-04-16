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
static void (* Timer0_InteruptPointerTCNT0)(void);


void Timer0_voidSet_ISR(void (*Copy_PtrToISR)(void))
{
	Timer0_InteruptPointer=Copy_PtrToISR;
}

void Timer0_voidSet_ISRCompareMatch(void (*Copy_PtrToISR)(void))
{
	Timer0_InteruptPointerTCNT0=Copy_PtrToISR;
}


void Timer0_voidInit(void)
{
		//	//the prescaler =64
			TIMER0_u8TCCR0=0X03;
			TIMER0_u8TIMSK=Setbit(TIMER0_u8TIMSK,TIMER0_u8TIMSK_TOIE0);//over flow Iterupt Interupt
			TIMER0_u8TIMSK=Setbit(TIMER0_u8TIMSK,TIMER0_u8TIMSK_TOCIE0);//COMPARE MATCH iNTERUPT
			//enable Glopal Interupt
			TIMER0_u8OCR0=0xff;
			__asm__("SEI");
}
void Timer0_voidReadTimer0TCNT0(u8 *ptrToVal)
{
	*ptrToVal=TIMER0_u8TCNT0;
}

void Timer0_voidsetTimerOCR0(u8 ptrToVal){

	TIMER0_u8OCR0=ptrToVal;
}

void Timer0_voidCheckForInterupt(u8 *ptrToValOverflow,u8 *ptrToValCompareMatch)
{
	*ptrToValOverflow=GetBit(TIMER0_u8TIFR,TIMER0_u8TIFR_TOV0);
	*ptrToValCompareMatch=GetBit(TIMER0_u8TIFR,TIMER0_u8TIFR_OCF0);
}


//timer 0 over flow ISR
ISR(__vector_11) {
	Timer0_InteruptPointer();
}


//timer 0 over flow ISR
ISR(__vector_10) {
	Timer0_InteruptPointerTCNT0();
}
