/*
 * SSD_PROG.c
 *
 *  Created on: Feb 3, 2016
 *      Author: mahmoud
 */

#include "types.h"
#include "DIO_Interface.h"
#include "SSD_Config.h"
#include "SSD_private.h"
#include "SSD_interface.h"
#include "util.h"
//it alook up table to determine the Pin configuration to each SS
static volatile u8 Global_u8LookUpTableOfTheConfigPins[6][10]={{SSD_u8DISP1COM,SSD_u8DISP1SEGA,SSD_u8DISP1SEGB,SSD_u8DISP1SEGC,SSD_u8DISP1SEGD,SSD_u8DISP1SEGE,SSD_u8DISP1SEGF,SSD_u8DISP1SEGG,SSD_u8DISP1TYPE,SSD_u8DISP1INIT},
		 	 	 	 	 	 	 	 	 	 	               {SSD_u8DISP2COM,SSD_u8DISP2SEGA,SSD_u8DISP2SEGB,SSD_u8DISP2SEGC,SSD_u8DISP2SEGD,SSD_u8DISP2SEGE,SSD_u8DISP2SEGF,SSD_u8DISP2SEGG,SSD_u8DISP2TYPE,SSD_u8DISP2INIT},
												               {SSD_u8DISP3COM,SSD_u8DISP3SEGA,SSD_u8DISP3SEGB,SSD_u8DISP3SEGC,SSD_u8DISP3SEGD,SSD_u8DISP3SEGE,SSD_u8DISP3SEGF,SSD_u8DISP3SEGG,SSD_u8DISP3TYPE,SSD_u8DISP3INIT},
													           {SSD_u8DISP4COM,SSD_u8DISP4SEGA,SSD_u8DISP4SEGB,SSD_u8DISP4SEGC,SSD_u8DISP4SEGD,SSD_u8DISP4SEGE,SSD_u8DISP4SEGF,SSD_u8DISP4SEGG,SSD_u8DISP4TYPE,SSD_u8DISP4INIT},
													           {SSD_u8DISP5COM,SSD_u8DISP5SEGA,SSD_u8DISP5SEGB,SSD_u8DISP5SEGC,SSD_u8DISP5SEGD,SSD_u8DISP5SEGE,SSD_u8DISP5SEGF,SSD_u8DISP5SEGG,SSD_u8DISP5TYPE,SSD_u8DISP5INIT},
													           {SSD_u8DISP6COM,SSD_u8DISP6SEGA,SSD_u8DISP6SEGB,SSD_u8DISP6SEGC,SSD_u8DISP6SEGD,SSD_u8DISP6SEGE,SSD_u8DISP6SEGF,SSD_u8DISP6SEGG,SSD_u8DISP6TYPE,SSD_u8DISP6INIT}};

// Look up table for the convertion of the no to the display bit
static volatile u8 Global_u8LookUpTableOfTheNumbersToDisplay[10]={0b0000001,0b1001111,0b0010010,0b0000110,0b1001100,0b0100100,0b0100000,0b0001111,0b00000000,0b0000100};
//to store the currnt value on each SSD
u8 Global_u8CurrentValOfTheSS[6]={0};

/*comment!:to initialize the SSD Acording to the config file */

void SSD_voidInit(void) {
	u8 local_u8Counter;
	// TODO make the common
	for (local_u8Counter = 0; local_u8Counter <SSD_u8DISPLAYCOUNT;local_u8Counter++) {
		//initializ the ports as out put

		switch (Global_u8LookUpTableOfTheConfigPins[local_u8Counter][SSD_u8DISPTYPEColInMap]) {
		case SSD_u8COMMAND:
			DIO_u8WritePinVal(Global_u8LookUpTableOfTheConfigPins[local_u8Counter][SSD_u8DISPCOMColInMap],DIO_u8LOW);
			//TODO dont forget to uncomment what come next
			SSD_u8Display(local_u8Counter+1,Global_u8LookUpTableOfTheConfigPins[local_u8Counter][SSD_u8DISPINITColInMap]);
			break;
		case SSD_u8COMMCATH:
			DIO_u8WritePinVal(Global_u8LookUpTableOfTheConfigPins[local_u8Counter][SSD_u8DISPCOMColInMap],DIO_u8HIGH);
			//TODO dont forget to uncomment what come next
			SSD_u8Display(local_u8Counter+1,Global_u8LookUpTableOfTheConfigPins[local_u8Counter][SSD_u8DISPINITColInMap]);
			break;
		default:
			break;
		}

	}
}

/*comment!:to Display a number */
extern u8 SSD_u8Display(u8 copy_u8DispIdx, u8 copy_u8DispVal) {
	u8 local_u8OperationStatus = OK,local_u8PinsCounter,local_u8ValToDisp,local_u8TempVal;

		if (copy_u8DispIdx<=SSD_u8DISPLAYCOUNT&&copy_u8DispVal<=SSD_u8MaxNoDisplay) {

			switch (Global_u8LookUpTableOfTheConfigPins[copy_u8DispIdx-1][SSD_u8DISPTYPEColInMap]) {
					case SSD_u8COMMAND:
						local_u8ValToDisp=~Global_u8LookUpTableOfTheNumbersToDisplay[copy_u8DispVal];
						break;
					case SSD_u8COMMCATH:
						local_u8ValToDisp=Global_u8LookUpTableOfTheNumbersToDisplay[copy_u8DispVal];
						break;
					default:
						break;
					}
			Global_u8CurrentValOfTheSS[copy_u8DispIdx-1]=copy_u8DispVal;

			for (local_u8PinsCounter =SSD_u8LastBitRead;
					local_u8PinsCounter >= SSD_u8FirstBitRead;
					local_u8PinsCounter--) {
					//TODO DONT forget the 0 magic number of the lest significant bit
						local_u8TempVal=GetBit(local_u8ValToDisp,0);
						local_u8ValToDisp >>=1;
						DIO_u8WritePinVal(Global_u8LookUpTableOfTheConfigPins[copy_u8DispIdx-1][local_u8PinsCounter],local_u8TempVal);
			}

		} else {
			local_u8OperationStatus=ERROR;
		}
     return local_u8OperationStatus;
}

/*comment!:to GET the current value Displayed on the 7Segment*/
extern u8 SSD_u8GetVal(u8 copy_u8DispIdx, u8* copy_u8DispVal) {
	u8 local_u8OperationStatus = OK;
	if (copy_u8DispIdx <= SSD_u8DISPLAYCOUNT) {
	*copy_u8DispVal=Global_u8CurrentValOfTheSS[copy_u8DispIdx-1];
	}
	else{
		local_u8OperationStatus=ERROR;
	}

	return local_u8OperationStatus;
}

/*comment!:Turn the SS ON*/
u8 SSD_u8TurnOn(u8 copy_u8DispIdx) {
	u8 local_u8OperationStatus = OK;
	if (copy_u8DispIdx < SSD_u8DISPLAYCOUNT) {

		switch (Global_u8LookUpTableOfTheConfigPins[copy_u8DispIdx - 1][SSD_u8DISPCOMColInMap]) {
		case SSD_u8COMMAND:
			DIO_u8WritePortVal(SSD_u8DISP1COM, DIO_u8HIGH);
			break;
		case SSD_u8COMMCATH:
			DIO_u8WritePortVal(SSD_u8DISP1COM, DIO_u8LOW);
			break;
		default:
			break;
		}

	} else {
		local_u8OperationStatus = ERROR;
	}
	return local_u8OperationStatus;
}
/*comment!:Turn the SS OFF*/
u8 SSD_u8TurnOff(u8 copy_u8DispIdx) {
	u8 local_u8OperationStatus = OK;
		if (copy_u8DispIdx < SSD_u8DISPLAYCOUNT) {

			switch (Global_u8LookUpTableOfTheConfigPins[copy_u8DispIdx - 1][SSD_u8DISPCOMColInMap]) {
			case SSD_u8COMMAND:
				DIO_u8WritePortVal(SSD_u8DISP1COM, DIO_u8LOW);
				break;
			case SSD_u8COMMCATH:
				DIO_u8WritePortVal(SSD_u8DISP1COM, DIO_u8HIGH);
				break;
			default:
				break;
			}

		} else {
			local_u8OperationStatus = ERROR;
		}
		return local_u8OperationStatus;
}

