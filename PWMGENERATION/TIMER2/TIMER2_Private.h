/*
 * TIMER2_Private.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: mahmoud
 */

#ifndef TIMER2_PRIVATE_H_
#define TIMER2_PRIVATE_H_

#define TIMER2_u8TCCR0  *((volatile u8*)(0x45))
#define TIMER2_u8TCNT0  *((volatile u8*)(0X53))
#define TIMER2_u8TIMSK  *((volatile u8*)(0X59))
#define TIMER2_u8TIFR   *((volatile u8*)(0X58))
#define TIMER2_u8OCR0  *((volatile u8*)(0x53))

#define TIMER2_u8TCCR0_CS00 	0
#define TIMER2_u8TCCR0_CS01		1
#define TIMER2_u8TCCR0_CS02		2
#define TIMER2_u8TCCR0_WGM01	3
#define TIMER2_u8TCCR0_COM00	4
#define TIMER2_u8TCCR0_COM01	5
#define TIMER2_u8TCCR0_WGM00	6
#define TIMER2_u8TCCR0_FOC0		7

#define TIMER2_u8TIMSK_TOIE0 0
#define TIMER2_u8TIMSK_TOCIE0 1

#define TIMER2_u8TIFR_TOV0 0
#define TIMER2_u8TIFR_OCF0 1

#endif /* TIMER2_PRIVATE_H_ */
