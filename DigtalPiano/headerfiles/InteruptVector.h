/*
 * InteruptVector.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: mahmoud
 */

#ifndef INTERUPTVECTOR_H_
#define INTERUPTVECTOR_H_

#define ISR(vector, ...) 	\
		void vector(void) __attribute__ ((signal,used,externally_visible)) __VA_ARGS__;\
		void vector(void)

#endif /* INTERUPTVECTOR_H_ */
