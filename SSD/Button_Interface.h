/*
 * Button_Interface.h
 *
 *  Created on: Feb 11, 2016
 *      Author: mahmoud
 */

#ifndef BUTTON_INTERFACE_H_
#define BUTTON_INTERFACE_H_

/***********************************************/
/********** Public Definitions *****************/
/***********************************************/


/***********************************************/
/********** Public function *******************/
/***********************************************/
/*comment!:to initialize the Button Acording to the config file */
void Button_voidInit(void);

/*comment!:get the value Single  */
extern u8 Button_u8GetValSingle(u8 Copy_u8PINIdx,u8* Copy_u8PtrToVal);

/*comment!:get the value Multi   */
extern u8 Button_u8GetValMulti(u8 Copy_u8PINIdx,u8* Copy_u8PtrToVal);

#endif /* BUTTON_INTERFACE_H_ */
