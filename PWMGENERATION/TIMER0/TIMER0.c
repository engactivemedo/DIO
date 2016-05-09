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

#define preconfiguardcount 1
#define PreconfiguardOCR0 10
#define counterSupport 0

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


	//the prescaler =00
	///	TIMER0_u8TCCR0=0X09;

	//	//the prescaler =8
	TIMER0_u8TCCR0 = 0X0A;

	//the prescaler =64
	//		TIMER0_u8TCCR0=0X0B;
	//the prescaler =256
	//		TIMER0_u8TCCR0=0X0C;
	//the prescaler =1024
	//		TIMER0_u8TCCR0=0X0D;

			//TIMER0_u8TIMSK=Setbit(TIMER0_u8TIMSK,TIMER0_u8TIMSK_TOIE0);//over flow Iterupt Interupt
			TIMER0_u8TIMSK=Setbit(TIMER0_u8TIMSK,TIMER0_u8TIMSK_TOCIE0);//COMPARE MATCH iNTERUPT
			//enable Global Interrupt
			TIMER0_u8OCR0=PreconfiguardOCR0;
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


//timer 0 output compare match ISR

ISR(__vector_10) {
#if counterSupport==1
	 u8 Counter=preconfiguardcount;
	Counter--;
	if(Counter==0)
	{
		Counter=preconfiguardcount;
#endif
	Timer0_InteruptPointerTCNT0();
#if counterSupport==1
	}
#endif
}

