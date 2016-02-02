/*
 * main.c
 *
 *  Created on: Feb 2, 2016
 *      Author: mahmoud
 */
#include "types.h"
#include "DIO_Interface.h"

int main(void) {
	DIO_voidInit();
	DIO_u8WritePortDir(DIO_u8PORT2, 0xff);
	DIO_u8WritePortVal(DIO_u8PORT2, 0xff);
	while (1) {

		DIO_u8WritePortVal(DIO_u8PORT2,0x00);

		delay11();
		DIO_u8WritePortVal(DIO_u8PORT2,0xff);
		delay11();
	}

	return 0;
}

void delay11(void) {
	volatile u64 z;

	for (z = 1000000000; z > 0; z--) {
		//for (i = 1000000000; i > 0; i--) {
			__asm__("NOP");
			__asm__("NOP");
		//}
	}
}
