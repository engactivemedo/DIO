/*
 * Button_prog.c
 *
 *  Created on: Feb 11, 2016
 *      Author: mahmoud
 */
#include "Button_Config.h"
#include "DIO_Interface.h"
#include"util.h"
#include"types.h"
#include"Delay_prog.c"
#define pressed 1
#define releassed 0
#define debouncing 2

/*comment!:to initialize the Button Acording to the config file */
void Button_voidInit(void) {

}

/*comment!:get the value Single  */
extern u8 Button_u8GetValSingle(u8 Copy_u8PINIdx, u8* Copy_u8PtrToVal) {

	static u8 local_u8WaitForOne = 0;
	static u8 local_u8WaitForZero = 0;
	u8 local_u8PinVal = 0, local_u8OperationStatus = ok;

	local_u8OperationStatus = DIO_u8ReadPinValue(Button_u8PinVal,&local_u8PinVal);
	if (local_u8PinVal == 1 && !local_u8WaitForZero) {
		if (local_u8WaitForOne != 4) {
			local_u8WaitForOne++;
			*Copy_u8PtrToVal = 0;
			Delay(5);
		} else {
			if (local_u8WaitForZero == 0) {
				local_u8WaitForZero++;
				local_u8WaitForOne = 0;
				*Copy_u8PtrToVal = 1;
			}

		}
	} else {
		*Copy_u8PtrToVal = 0;
		local_u8OperationStatus = DIO_u8ReadPinValue(Button_u8PinVal,&local_u8PinVal);
		if(local_u8PinVal==0)
		{
			local_u8WaitForZero=0;

		}

	}
	return local_u8OperationStatus;

}


extern u8 Button_u8GetValMulti(u8 Copy_u8PINIdx, u8* Copy_u8PtrToVal) {
	//static u8 local_u8WaitForOne = 0;
	static u8 localu8PrevState = 0;
	static u8 local_u8state = releassed;
	static u8 local_u8DebouncingCounter=0;
	u8 local_u8PinVal = 0, local_u8OperationStatus = ok;

	local_u8OperationStatus = DIO_u8ReadPinValue(Button_u8PinVal,
			&local_u8PinVal);
	switch (local_u8state) {
	case pressed:
		if (local_u8PinVal == DIO_u8HIGH) {
		} else {
			localu8PrevState=pressed;
			local_u8state = debouncing;
		}
		break;
	case releassed:
		Copy_u8PtrToVal = releassed;
		if (local_u8PinVal == DIO_u8LOW) {
		} else {
			localu8PrevState=releassed;
			local_u8state = debouncing;
		}
		break;
	case debouncing:
		Delay(5);
		local_u8OperationStatus = DIO_u8ReadPinValue(Button_u8PinVal,
					&local_u8PinVal);
		switch (localu8PrevState) {
		case pressed:
			if (local_u8PinVal==DIO_u8HIGH) {
				local_u8state=pressed;

			} else {
				local_u8state=releassed;
			}
			break;
		case releassed:
			if (local_u8PinVal==DIO_u8LOW) {
							local_u8state=releassed;

						} else {
							local_u8state=pressed;
						}
			break;
		default:
			break;
		}
		break;
	default:

		break;

	}

	return local_u8OperationStatus;


}
