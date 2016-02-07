/*
 * main.c
 *
 *  Created on: Feb 2, 2016
 *      Author: mahmoud
 */
#include "types.h"
#include "DIO_Interface.h"
#include "Delay_Interface.h"
#include "Delay_Config.h"

#define Glopal_u8DelayInMs 100
static volatile u8 shape[5][4] = { { 0b00011000, 0b00100100, 0b01000010,
		0b10000001 }, { 0b10000001, 0b01000010, 0b00100100, 0b00011000 }, {
		0b10001000, 0b01000100, 0b00100010, 0b00010001 }, { 0b00010001,
		0b00100010, 0b00100100, 0b00011000 }, { 0b00011000, 0b00111100,
		0b01111110, 0b11111111 } };

//int delay11(int v);

int main(void) {
	DIO_voidInit();
	DIO_u8WritePortDir(DIO_u8PORT2, 0xff);
	DIO_u8WritePortVal(DIO_u8PORT2, 0xff);
	while (1) {
		u8 i = 0, k = 0;
		i = 1;
		for (k = 0; k < 8; k++) {
			DIO_u8WritePortVal(DIO_u8PORT2, i);
			i <<= 1;
			//Delay_voidDelayms(Glopal_u8DelayInMs);
		do {
			u64 local_u64Counter;
			for(local_u64Counter=((Delay_u32CrystaValue*Copyu8_TimeDelayInms)*1000);local_u64Counter>=1;local_u64Counter--)
			{
				__asm__("NOP");
			}
		}while(0);
	}
	i = 0x80;
	;
	for (k = 0; k < 8; k++) {
		DIO_u8WritePortVal(DIO_u8PORT2, i);
		i >>= 1;
		Delay_voidDelayms(Glopal_u8DelayInMs);
	}

	for (k = 0; k < 4; k++) {
		for (i = 0; i < 5; i++) {
			DIO_u8WritePortVal(DIO_u8PORT2, shape[k][i]);
			Delay_voidDelayms(Glopal_u8DelayInMs);
		}

	}

	for (k = 0; k < 4; k++) {
		for (i = 0; i < 5; i++) {
			DIO_u8WritePortVal(DIO_u8PORT2, ~shape[k][i]);
			Delay_voidDelayms(Glopal_u8DelayInMs);
		}

	}
}

return 0;
}

/*
 void delay11(int v) {
 //u32 z;

 Delay_voidDelayms(500);

 for (z = 100000; z > 0; z--) {
 //for (i = 1000000000; i > 0; i--) {
 __asm__("NOP");
 //__asm__("NOP");
 //}
 }
 }
 */
