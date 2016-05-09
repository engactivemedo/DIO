/*
 * TIMER0_Private.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: mahmoud
 */

#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_

#define TIMER0_u8TCCR0  *((volatile u8*)(0x53))
#define TIMER0_u8TCNT0  *((volatile u8*)(0X52))
#define TIMER0_u8TIMSK  *((volatile u8*)(0X59))
#define TIMER0_u8TIFR   *((volatile u8*)(0X58))
#define TIMER0_u8OCR0  *((volatile u8*)(0X5C))

#define TIMER0_u8TCCR0_CS00 	0
#define TIMER0_u8TCCR0_CS01		1
#define TIMER0_u8TCCR0_CS02		2
#define TIMER0_u8TCCR0_WGM01	3
#define TIMER0_u8TCCR0_COM00	4
#define TIMER0_u8TCCR0_COM01	5
#define TIMER0_u8TCCR0_WGM00	6
#define TIMER0_u8TCCR0_FOC0		7


#define TIMER0_u8TIMSK_TOIE0 0
#define TIMER0_u8TIMSK_TOCIE0 1

#define TIMER0_u8TIFR_TOV0 0
#define TIMER0_u8TIFR_OCF0 1

#endif /* TIMER0_PRIVATE_H_ */
