/*
 * Button_Config.h
 *
 *  Created on: Feb 11, 2016
 *      Author: mahmoud
 */

#ifndef BUTTON_CONFIG_H_
#define BUTTON_CONFIG_H_

/***********************************************/
/**********switch types*************************/
/***********************************************/
#define Tactile_Switch 0
#define Button_u8ActiveHigh 1
#define Button_u8ActiveLow 0

/***********************************************/
/**********switch Info *************************/
/***********************************************/
#define Button_u8PinVal   DIO_u8PIN16
#define Button_u8Type  Tactile_Switch
#define Button_u8ActiveType Button_u8ActiveHigh

#endif /* BUTTON_CONFIG_H_ */
