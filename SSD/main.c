/*
 * main.c
 *
 *  Created on: Feb 3, 2016
 *      Author: mahmoud
 */

#include "SSD_Interface.h"
#include"DIO_Interface.h"
int main(void) {
	DIO_voidInit();
	SSD_voidInit();
	SSD_u8Display(2, 3);

	while (1)
		;
	return 0;
}
