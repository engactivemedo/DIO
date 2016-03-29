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

#define TIMER0_u8TCCR0  *((volatile u8*)(0x53))
#define TIMER0_u8TCNT0  *((volatile u8*)(0X52))
#define TIMER0_u8TIMSK  *((volatile u8*)(0X59))
#define TIMER0_u8TIFR   *((volatile u8*)(0X58))

#define TIMER0_u8TCCR0_CS00 	0
#define TIMER0_u8TCCR0_CS01		1
#define TIMER0_u8TCCR0_CS02		2
#define TIMER0_u8TCCR0_WGM01	3
#define TIMER0_u8TCCR0_COM00	4
#define TIMER0_u8TCCR0_COM01	5
#define TIMER0_u8TCCR0_WGM00	6
#define TIMER0_u8TCCR0_FOC0		7


#define TIMER0_u8TIMSK_TOIE0 0
#define TIMER0_u8TIMSK_TOCIE0 1

#define TIMER0_u8TIFR_TOV0 0
#define TIMER0_u8TIFR_OCF0 1


#define ISR(vector, ...) 	\
		void vector(void) __attribute__ ((signal,used,externally_visible)) __VA_ARGS__;\
		void vector(void)


#define DOTMATRIXREFRSHMENTRATE  1		//5ms
#define MOVINGPARTSTIME			 245   //1sec
#define MOVINGPARTSTIME2x		 122	//.5 sec

u8 glopal_u8mimecharacter[8] = { 0x0, 0x7, 0x5, 0x1f, 0x10, 0x10, 0x10, 0x10 };

u8 glopal_u8haacharacter[8] = { 0x1f, 0x1, 0x2, 0x4, 0x8, 0x8, 0x4, 0x3 };

u8 glopal_u8wowcharacter[8] = { 0xe, 0x11, 0x11, 0xf, 0x1, 0x3, 0x4, 0x18 };

u8 glopal_u8dalcharacter[8] = { 0x4, 0x2, 0x1, 0x1, 0x1, 0x1, 0x1e, 0x8 };

u8 arrayToTest[8][1]={{0b10000000},
					  {0b10000000},
					  {0b10000000},
					  {0b10000000},
					  {0b10000000},
					  {0b10000000},
					  {0b10000000},
					  {0b11111110}};


#define coulmn DIO_u8PORT2
#define Row  DIO_u8PORT3

void Timer0_voidInit(void)
{
			//the prescaler =64
			TIMER0_u8TCCR0=0X03;
			TIMER0_u8TIMSK=Setbit(TIMER0_u8TIMSK,TIMER0_u8TIMSK_TOIE0);
			//enable Glopal Interupt
			__asm__("SEI");
}

void Timer0_voidReadTimer0TCNT0(u8 *ptrToVal)
{
	*ptrToVal=TIMER0_u8TCNT0;
}


void Timer0_voidCheckForInterupt(u8 *ptrToValOverflow,u8 *ptrToValCompareMatch)
{
	*ptrToValOverflow=GetBit(TIMER0_u8TIFR,TIMER0_u8TIFR_TOV0);
	*ptrToValCompareMatch=GetBit(TIMER0_u8TIFR,TIMER0_u8TIFR_OCF0);
}


void Display_OnDotMatrix(){
//	static u8 local_u8Staticounter =0;
	u8 counter1;
	for(counter1=0;counter1<8;counter1++)
	{
		DIO_u8WritePortVal(Row,~(0x01<<counter1));
		DIO_u8WritePortVal(coulmn,arrayToTest[counter1][0]);
		Delay(1);

	}



}


//timer 0 over flow ISR
ISR(__vector_5)
{
	static u8 x1=0x00;
	static u8 x2=0x00;

	static u8 local_u8Timer0OVFCountermovingpart=0;
	static u8 local_u8Timer0OVFCounterledmatrix=0;
	local_u8Timer0OVFCountermovingpart++;
	local_u8Timer0OVFCounterledmatrix++;

	//its time to refresh the dot matrix
	if(local_u8Timer0OVFCounterledmatrix==DOTMATRIXREFRSHMENTRATE){
		local_u8Timer0OVFCounterledmatrix=0;
		x1=Togglebit(x1,0);
		DIO_u8WritePinVal(DIO_u8PIN0,x1);
	}
	else{}

	//its time to move the part on the dot matrix
	if(local_u8Timer0OVFCountermovingpart==MOVINGPARTSTIME)
	{
		local_u8Timer0OVFCountermovingpart=0;
				x2=Togglebit(x2,0);
				DIO_u8WritePinVal(DIO_u8PIN1,x2);
	}
	else{}


}


int main(void) {
	u8 counter = 0;
	u8 local_u8_keypadVal = 0x00;
	u8 local_u8ASCIIToDisplay = 0;
	// char Strings[5]="";
	DIO_voidInit();
	LCD_VOIDInit();
	KPD_voidInit();

/*
	LCD_voidUploadCustomChar(0, glopal_u8mimecharacter);
	LCD_voidUploadCustomChar(1, glopal_u8haacharacter);
	LCD_voidUploadCustomChar(2, glopal_u8wowcharacter);
	LCD_voidUploadCustomChar(3, glopal_u8dalcharacter);

	LCD_u8WriteData(LCD_u8M);
	LCD_u8GotoXY(1, 11);
	LCD_u8WriteData(0X00);
	LCD_u8GotoXY(2, 1);
	LCD_u8WriteData(0X00);

	LCD_u8GotoXY(2, 11);
	LCD_arabicmode();
	LCD_u8WriteData(0X00);
	LCD_u8WriteData(0X01);
	LCD_u8WriteData(0X00);
	LCD_u8WriteData(0X02);
	LCD_u8WriteData(0X03);
*/

	//

	lCD_u8CLRScreen();
	LCD_arabicmode();

	while (1) {

/*		LCD_u8GotoXY(2, 8);

		KPD_u8Read(&local_u8_keypadVal);
		if (local_u8_keypadVal != 0) {
			while (counter <= 3) {
				local_u8ASCIIToDisplay = local_u8_keypadVal % 10;
				local_u8_keypadVal /= 10;
				local_u8ASCIIToDisplay += 48;
				LCD_u8WriteData(local_u8ASCIIToDisplay);
				counter++;
			}

			counter = 0;
		} else {

		}*/
		KPD_u8Read(&local_u8_keypadVal);
		arrayToTest[2][0]=local_u8_keypadVal;
		Display_OnDotMatrix();
		Delay(5);
	}
	return 0;
}

