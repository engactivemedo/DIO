/*
 * LCD_main.c
 *
 *  Created on: Mar 9, 2016
 *      Author: mahmoud
 */


#include"../headerfiles/types.h"
#include"../headerfiles/util.h"
#include"../headerfiles/DIOFiles/DIO_Interface.h"
#include"../headerfiles/DelayFiles/Delay_prog.c"
#include"../lcd_files/LCD_Interface.h"
#include"../headerfiles/kpd/KPD_interface.h"
//#include"../ADC_files/ADC_Interface.h"

u8 glopal_u8mimecharacter[8]={0x0,0x7,0x5,0x1f,0x10,0x10,0x10,0x10};

u8 glopal_u8haacharacter[8]={0x1f,0x1,0x2,0x4,0x8,0x8,0x4,0x3};

u8 glopal_u8wowcharacter[8]={0xe,0x11,0x11,0xf,0x1,0x3,0x4,0x18};

u8 glopal_u8dalcharacter[8]={0x4,0x2,0x1,0x1,0x1,0x1,0x1e,0x8};


int main(void) {
	u8 counter=0;
	u16 local_u16TheADCVAL=0x00;
	u8 local_u8ASCIIToDisplay=0;
	DIO_voidInit();
	LCD_VOIDInit();






	LCD_voidUploadCustomChar(0,glopal_u8mimecharacter);
	LCD_voidUploadCustomChar(1,glopal_u8haacharacter);
	LCD_voidUploadCustomChar(2,glopal_u8wowcharacter);
	LCD_voidUploadCustomChar(3,glopal_u8dalcharacter);


	LCD_u8WriteData(LCD_u8M);
	LCD_u8GotoXY(1,11);
	LCD_u8WriteData(0X00);
	LCD_u8GotoXY(2,1);
	LCD_u8WriteData(0X00);



	LCD_u8GotoXY(2,11);
	LCD_arabicmode();
	LCD_u8WriteData(0X00);
	LCD_u8WriteData(0X01);
	LCD_u8WriteData(0X00);
	LCD_u8WriteData(0X02);
	LCD_u8WriteData(0X03);



	//


	lCD_u8CLRScreen();

	while (1) {

 LCD_arabicmode();
 LCD_u8GotoXY(2,8);


 while(counter<=3)
 {
	 local_u8ASCIIToDisplay=local_u16TheADCVAL%10;
	 local_u16TheADCVAL/=10;
	 local_u8ASCIIToDisplay+=48;
	 LCD_u8WriteData(local_u8ASCIIToDisplay);
	 counter++;
 }

 counter=0;

	}
return 0;
}





