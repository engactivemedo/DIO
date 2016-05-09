/*
 * TIMER2.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: mahmoud
 */
#include"TIMER2_Config.h"
#include"TIMER2_Private.h"
#include"../headerfiles/InteruptVector.h"
#include"../headerfiles/util.h"
#include"../headerfiles/types.h"

#define preconfiguardcount2 1
#define PreconfiguardOCR2 10
#define counterSupport 0

static void (*TIMER2_InteruptPointer)(void);
static void (*TIMER2_InteruptPointerTCNT0)(void);

void TIMER2_voidSet_ISR(void (*Copy_PtrToISR)(void)) {
	TIMER2_InteruptPointer = Copy_PtrToISR;
}

void TIMER2_voidSet_ISRCompareMatch(void (*Copy_PtrToISR)(void)) {
	TIMER2_InteruptPointerTCNT0 = Copy_PtrToISR;
}

void TIMER2_voidInit(void) {

	//the prescaler =00
	///	TIMER2_u8TCCR0=0X09;

	//	//the prescaler =8
	TIMER2_u8TCCR0 = 0X0A;

	//the prescaler =64
	//		TIMER2_u8TCCR0=0X0B;
	//the prescaler =256
	//		TIMER2_u8TCCR0=0X0C;
	//the prescaler =1024
	//		TIMER2_u8TCCR0=0X0D;

	//TIMER2_u8TIMSK=Setbit(TIMER2_u8TIMSK,TIMER2_u8TIMSK_TOIE0);//over flow Iterupt Interupt
	TIMER2_u8TIMSK = Setbit(TIMER2_u8TIMSK, TIMER2_u8TIMSK_TOCIE0);	//COMPARE MATCH iNTERUPT
	//enable Global Interrupt
	TIMER2_u8OCR0 = PreconfiguardOCR2;
	__asm__("SEI");
}
void TIMER2_voidReadTIMER2TCNT0(u8 *ptrToVal) {
	*ptrToVal = TIMER2_u8TCNT0;
}

void TIMER2_voidsetTimerOCR0(u8 ptrToVal) {

	TIMER2_u8OCR0 = ptrToVal;
}

void TIMER2_voidCheckForInterupt(u8 *ptrToValOverflow, u8 *ptrToValCompareMatch) {
	*ptrToValOverflow = GetBit(TIMER2_u8TIFR, TIMER2_u8TIFR_TOV0);
	*ptrToValCompareMatch = GetBit(TIMER2_u8TIFR, TIMER2_u8TIFR_OCF0);
}

//timer 0 over flow ISR
ISR(__vector_5) {
	TIMER2_InteruptPointer();
}

//timer 0 output compare match ISR

ISR(__vector_4) {
	TIMER2_InteruptPointerTCNT0();
}

