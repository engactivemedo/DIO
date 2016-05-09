/*
 * TIMER0_Interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: mahmoud
 */

#ifndef TIMER2_INTERFACE_H_
#define TIMER2_INTERFACE_H_

void Timer0_voidInit(void);
void Timer0_voidReadTimer0TCNT0(u8 *ptrToVal);
void Timer0_voidCheckForInterupt(u8 *ptrToValOverflow,u8 *ptrToValCompareMatch);
void Timer0_voidSet_ISRCompareMatch(void (*Copy_PtrToISR)(void));
void Timer0_voidSet_ISR(void (*Copy_PtrToISR)(void));
void Timer0_voidsetTimerOCR0(u8 ptrToVal);

#endif /* TIMER0_INTERFACE_H_ */
