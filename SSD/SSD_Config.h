/*
 * SSD_Config.h
 *
 *  Created on: Feb 3, 2016
 *      Author: mahmoud
 */

#ifndef SSD_CONFIG_H_
#define SSD_CONFIG_H_

/*Comments!:   */
/*Range CommonCathode OR CommonAnode*/

/*Comments!:  PIN Initial Direction   */
/*Range CommonCathode OR CommonAnode*/
#define SSD_u8DISP1TYPE 	   SSD_u8COMMCATH
#define SSD_u8DISP1INIT		   2
#define SSD_u8DISP1INITSTATE   SSD_u8OFFSTATE
#define SSD_u8DISP1COM		   DIO_u8PIN0//WITH THE DESCREPTION OF THE dio DRIVER AND TO THE END OF THE CONFIG
#define SSD_u8DISP1SEGA		   DIO_u8PIN1
#define SSD_u8DISP1SEGB		   DIO_u8PIN2
#define SSD_u8DISP1SEGC		   DIO_u8PIN3
#define SSD_u8DISP1SEGD		   DIO_u8PIN4
#define SSD_u8DISP1SEGE		   DIO_u8PIN5
#define SSD_u8DISP1SEGF		   DIO_u8PIN6
#define SSD_u8DISP1SEGG		   DIO_u8PIN7


#define SSD_u8DISP2TYPE			SSD_u8COMMAND
#define SSD_u8DISP2INIT         4
#define SSD_u8DISP2INITSTATE	SSD_u8OFFSTATE
#define SSD_u8DISP2COM 			DIO_u8PIN8
#define SSD_u8DISP2SEGA			DIO_u8PIN9
#define SSD_u8DISP2SEGB			DIO_u8PIN10
#define SSD_u8DISP2SEGC			DIO_u8PIN11
#define SSD_u8DISP2SEGD			DIO_u8PIN12
#define SSD_u8DISP2SEGE			DIO_u8PIN13
#define SSD_u8DISP2SEGF			DIO_u8PIN14
#define SSD_u8DISP2SEGG			DIO_u8PIN15


#define SSD_u8DISP3TYPE SSD_u8COMMAND
#define SSD_u8DISP3INIT	3
#define SSD_u8DISP3INITSTATE  SSD_u8OFFSTATE
#define SSD_u8DISP3COM	DIO_u8PIN23//DIO_u8PIN16
#define SSD_u8DISP3SEGA	DIO_u8PIN9
#define SSD_u8DISP3SEGB	DIO_u8PIN10
#define SSD_u8DISP3SEGC	DIO_u8PIN11
#define SSD_u8DISP3SEGD	DIO_u8PIN12
#define SSD_u8DISP3SEGE	DIO_u8PIN13
#define SSD_u8DISP3SEGF	DIO_u8PIN14
#define SSD_u8DISP3SEGG	DIO_u8PIN15


#define SSD_u8DISP4TYPE	SSD_u8COMMAND
#define SSD_u8DISP4INIT	0
#define SSD_u8DISP4INITSTATE	SSD_u8OFFSTATE
#define SSD_u8DISP4COM	DIO_u8PIN22//DIO_u8PIN17
#define SSD_u8DISP4SEGA	DIO_u8PIN9
#define SSD_u8DISP4SEGB	DIO_u8PIN10
#define SSD_u8DISP4SEGC	DIO_u8PIN11
#define SSD_u8DISP4SEGD	DIO_u8PIN12
#define SSD_u8DISP4SEGE	DIO_u8PIN13
#define SSD_u8DISP4SEGF	DIO_u8PIN14
#define SSD_u8DISP4SEGG	DIO_u8PIN15

#define SSD_u8DISP5TYPE SSD_u8COMMAND
#define SSD_u8DISP5INIT	0
#define SSD_u8DISP5INITSTATE	SSD_u8OFFSTATE
#define SSD_u8DISP5COM	DIO_u8PIN17//DIO_u8PIN24
#define SSD_u8DISP5SEGA	DIO_u8PIN9
#define SSD_u8DISP5SEGB	DIO_u8PIN10
#define SSD_u8DISP5SEGC	DIO_u8PIN11
#define SSD_u8DISP5SEGD	DIO_u8PIN12
#define SSD_u8DISP5SEGE	DIO_u8PIN13
#define SSD_u8DISP5SEGF	DIO_u8PIN14
#define SSD_u8DISP5SEGG	DIO_u8PIN15


#define SSD_u8DISP6TYPE	0
#define SSD_u8DISP6INIT	0
#define SSD_u8DISP6INITSTATE	0
#define SSD_u8DISP6COM	0
#define SSD_u8DISP6SEGA	0
#define SSD_u8DISP6SEGB	0
#define SSD_u8DISP6SEGC	0
#define SSD_u8DISP6SEGD	0
#define SSD_u8DISP6SEGE	0
#define SSD_u8DISP6SEGF	0
#define SSD_u8DISP6SEGG	0


//FROM 1 TO 6
#define SSD_u8DISPLAYCOUNT 5//NO OF THE 7 SEGMENT DISPLAY

#endif /* SSD_CONFIG_H_ */
