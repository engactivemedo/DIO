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
#include"../ADC_files/ADC_Interface.h"
#include"../headerfiles/keypadsFiles/KeyPad_Interface.h"

#define SteperMotorPort DIO_u8PORT3
#define SPEED 0
#define DIRECTION 1
#define STOP 2
void stepperStop();
void stepperControll(u8 copy_u8,u8 copy_u8Direction);
void lcd_voidStringView(u8 copy_String);
void ADC_SteperInterface(u8 copy_u8display);

u8 glopal_u8mimecharacter[8]={0x0,0x7,0x5,0x1f,0x10,0x10,0x10,0x10};

u8 glopal_u8haacharacter[8]={0x1f,0x1,0x2,0x4,0x8,0x8,0x4,0x3};

u8 glopal_u8wowcharacter[8]={0xe,0x11,0x11,0xf,0x1,0x3,0x4,0x18};

u8 glopal_u8dalcharacter[8]={0x4,0x2,0x1,0x1,0x1,0x1,0x1e,0x8};

int main(void) {
	u16 local_u16TheADCVAL=0x00;
	u8 local_u8convflag=0;
	u8 local_u8ButtonRead;
	u8 local_u8Speed;
	DIO_voidInit();
	LCD_VOIDInit();

	////////////////////////////////////////////////////
	ADC_voidinit();
	ADC_voidEnable();

	///////////////////////////////////////////////////////////



	LCD_voidUploadCustomChar(0,glopal_u8mimecharacter);
	LCD_voidUploadCustomChar(1,glopal_u8haacharacter);
	LCD_voidUploadCustomChar(2,glopal_u8wowcharacter);
	LCD_voidUploadCustomChar(3,glopal_u8dalcharacter);


/*	LCD_u8WriteData(LCD_u8M);
	LCD_u8GotoXY(1,11);
	LCD_u8WriteData(0X00);
	LCD_u8GotoXY(2,1);
	LCD_u8WriteData(0X00);*/







	//

	DIO_u8WritePortDir(3,0xff);
	//DIO_u8WritePortDir(2,0xff);
	DIO_u8WritePortDir(3,0XFF);
	 ADC_voidEnable();
	lCD_u8CLRScreen();

	while (1) {
		KeyPad_u8DebouncingSol(21,&local_u8ButtonRead);

		 if(local_u8ButtonRead==1){
			 lCD_u8CLRScreen();
				LCD_u8GotoXY(2,11);
				LCD_arabicmode();
				LCD_u8WriteData(0X00);
				LCD_u8WriteData(0X01);
				LCD_u8WriteData(0X00);
				LCD_u8WriteData(0X02);
				LCD_u8WriteData(0X03);
			 do{ KeyPad_u8DebouncingSol(21,&local_u8ButtonRead);
			 local_u16TheADCVAL=ADC_u16ReadChannelOneShot(ADC_U8Channel1,&local_u8convflag);


			 if(local_u16TheADCVAL>523){
				 local_u8Speed=(499-(local_u16TheADCVAL-524))/125;
				 stepperControll(local_u8Speed+2,1);
				 DIO_u8WritePinVal(DIO_u8PIN23,DIO_u8LOW);

			 }
			 else if(local_u16TheADCVAL<501){
				 local_u8Speed= ((local_u16TheADCVAL)/125);
				 stepperControll(local_u8Speed+2,0);
				 DIO_u8WritePinVal(DIO_u8PIN23,DIO_u8LOW);

			}
			 else{
				 DIO_u8WritePinVal(DIO_u8PIN23,DIO_u8HIGH);
			     stepperStop();

			}

		}while(local_u8ButtonRead==1);

			 lCD_u8CLRScreen();
		 }
		 else{}




 local_u16TheADCVAL=ADC_u16ReadChannelOneShot(ADC_U8Channel1,&local_u8convflag);


 if(local_u16TheADCVAL>523){
	 local_u8Speed=(499-(local_u16TheADCVAL-524))/125;
	 stepperControll(local_u8Speed,1);
	 DIO_u8WritePinVal(DIO_u8PIN23,DIO_u8LOW);

	 //lCD_u8CLRScreen();
	 LCD_englishmode();
	 LCD_u8GotoXY(1,1);
	 lcd_voidStringView(SPEED);
	 LCD_u8WriteData(local_u8Speed+49);
	 LCD_u8GotoXY(2,1);
	 lcd_voidStringView(DIRECTION);
	 LCD_u8WriteData('R');

 }
 else if(local_u16TheADCVAL<501){
	 local_u8Speed= ((local_u16TheADCVAL)/125);
	 stepperControll(local_u8Speed,0);
	 DIO_u8WritePinVal(DIO_u8PIN23,DIO_u8LOW);

	 LCD_englishmode();
	 LCD_u8GotoXY(1,1);
	 lcd_voidStringView(SPEED);
	 LCD_u8WriteData(local_u8Speed+49);
	 LCD_u8GotoXY(2,1);
	 lcd_voidStringView(DIRECTION);
	 LCD_u8WriteData('L');

}
 else{
	 DIO_u8WritePinVal(DIO_u8PIN23,DIO_u8HIGH);
     stepperStop();
	 LCD_englishmode();
	 LCD_u8GotoXY(1,1);
	 lcd_voidStringView(SPEED);
	 LCD_u8WriteData(' ');
	 LCD_u8GotoXY(2,1);
	 lcd_voidStringView(DIRECTION);
	 LCD_u8WriteData('S');
}


/* while(counter<=3)
 {
	 local_u8ASCIIToDisplay=local_u16TheADCVAL%10;
	 local_u16TheADCVAL/=10;
	 local_u8ASCIIToDisplay+=48;
	 LCD_u8WriteData(local_u8ASCIIToDisplay);
	 counter++;
 }
 counter=0;*/



	}
return 0;
}


void stepperStop(){

	DIO_u8WritePortVal(SteperMotorPort,0x00);
}
void stepperControll(u8 copy_u8Speed,u8 copy_u8Direction)
{ u8 static variable1=0x01;
  u8 static variable2=0x08;



	switch(copy_u8Direction)
	{
	case 0:

		DIO_u8WritePortVal(SteperMotorPort,variable1);
		variable1<<=1;
		Delay(copy_u8Speed);
		if(variable1==0x10)
					{variable1=0x01;}
		break;
	case 1:

		DIO_u8WritePortVal(SteperMotorPort,variable2);
				Delay(copy_u8Speed);
				variable2>>=1;
				if(variable2==0x00)
							{variable2=0x08;}
		break;

	default:
		break;
	}


}

#define SPEED 0
#define DIRECTION 1
#define STOP 2

void lcd_voidStringView(u8 copy_String){

	switch(copy_String)
	{
	case SPEED:
		LCD_u8WriteData('S');
		LCD_u8WriteData('p');
		LCD_u8WriteData('e');
		LCD_u8WriteData('e');
		LCD_u8WriteData('d');
		LCD_u8WriteData(':');
	break;
	case DIRECTION:
		LCD_u8WriteData('D');
		LCD_u8WriteData('i');
		LCD_u8WriteData('r');
		LCD_u8WriteData('e');
		LCD_u8WriteData('c');
		LCD_u8WriteData('t');
		LCD_u8WriteData('i');
		LCD_u8WriteData('o');
		LCD_u8WriteData('n');
		LCD_u8WriteData(':');
		break;
	case STOP:
		LCD_u8WriteData('S');
		LCD_u8WriteData('t');
		LCD_u8WriteData('o');
		LCD_u8WriteData('p');
		break;
	default:
		break;

	}

}

void ADC_SteperInterface(u8 copy_u8display){
	 u8 local_u16TheADCVAL1;
	 u8 local_u8Speed1;
	 u8 local_u8convflag1;

	local_u16TheADCVAL1=ADC_u16ReadChannelOneShot(ADC_U8Channel1,&local_u8convflag1);


	 if(local_u16TheADCVAL1>523){
		 local_u8Speed1=((499-(local_u16TheADCVAL1-524)))/125;
		 stepperControll(local_u8Speed1+2,1);
		 DIO_u8WritePinVal(DIO_u8PIN23,DIO_u8LOW);

	 }
	 else if(local_u16TheADCVAL1<501){
		 local_u8Speed1= ((local_u16TheADCVAL1)/125);
		 stepperControll(local_u8Speed1+2,0);
		 DIO_u8WritePinVal(DIO_u8PIN23,DIO_u8LOW);


	}
	 else{
		 DIO_u8WritePinVal(DIO_u8PIN23,DIO_u8HIGH);
	     stepperStop();

	}


}

