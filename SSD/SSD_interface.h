/*
 * SSD_interface.h
 *
 *  Created on: Feb 3, 2016
 *      Author: mahmoud
 */
#include "types.h"
#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_


/*******************************************************************/
/****************Public Definitions********************************/
/*******************************************************************/

/*comment!:NUMBERS TO BE DISPLAYED ON SEVEN SEGMENT */
#define SSD_u8NUM0	0
#define SSD_u8NUM1	1
#define SSD_u8NUM2	2
#define SSD_u8NUM3	3
#define SSD_u8NUM4	4
#define SSD_u8NUM5	5
#define SSD_u8NUM6	6
#define SSD_u8NUM7	7
#define SSD_u8NUM8	8
#define SSD_u8NUM9	9

/*comment!:THE DISPLAY TO CONTROLL*/
#define SSD_U8Disp1 0
#define SSD_U8Disp2 1
#define SSD_U8Disp3 2
#define SSD_U8Disp4 3
#define SSD_U8Disp5 4
#define SSD_U8Disp6 5
#define SSD_U8Disp7 6

/*comment!:COOMON CATHODE OR COMMON ANODE */
#define SSD_u8COMMAND  0
#define SSD_u8COMMCATH 1

/*comment!:INITIAL STATE */
#define SSD_u8ONSTATE  1
#define SSD_u8OFFSTATE 0

/***********************************************************/
/******************public functions*************************/
/***********************************************************/

/*comment!:to Display a number on multi screen */
extern u8 SSD_u8DisplayMultiScreen(u8 copy_u8StartSS,u8 copy_u8EndSS,u8 copy_u8Delay,u16 copy_u8DispVal);

/*comment!:to Display a number */
extern u8 SSD_u8Display(u8 copy_u8DispIdx,u8 copy_u8DispVal);
/*comment!:to GET the current value Displayed on the 7Segment*/
extern u8 SSD_u8GetVal(u8 copy_u8DispIdx,u8* copy_u8DispVal);
/*comment!:Turn the SS ON*/
u8 SSD_u8TurnOn(u8 copy_u8DispIdx);
/*comment!:Turn the SS OFF*/
u8 SSD_u8TurnOff(u8 copy_u8DispIdx);
/*comment!:to initialize the SSD Acording to the config file */
void SSD_voidInit(void);


#endif /* SSD_INTERFACE_H_ */
