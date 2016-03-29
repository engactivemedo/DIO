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
#include"../headerfiles/tetris/Tertris_App.h"

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


#define DOTMATRIXREFRSHMENTRATE  3		//5ms
#define MOVINGPARTSTIME			 245   //1sec
#define MOVINGPARTSTIME2x		 122	//.5 sec

#define SMALLARRAY  arrayToTest
#define bigArray 	DotMatrix

#define coulmn DIO_u8PORT2
#define Row  DIO_u8PORT3


 extern u8 DotMatrix[8][8];

u8 glopal_u8mimecharacter[8] = { 0x0, 0x7, 0x5, 0x1f, 0x10, 0x10, 0x10, 0x10 };

u8 glopal_u8haacharacter[8] = { 0x1f, 0x1, 0x2, 0x4, 0x8, 0x8, 0x4, 0x3 };

u8 glopal_u8wowcharacter[8] = { 0xe, 0x11, 0x11, 0xf, 0x1, 0x3, 0x4, 0x18 };

u8 glopal_u8dalcharacter[8] = { 0x4, 0x2, 0x1, 0x1, 0x1, 0x1, 0x1e, 0x8 };

u8 arrayToTest[8][1]={{0b11000000},
					  {0b10100000},
					  {0b10010000},
					  {0b10001000},
					  {0b10000100},
					  {0b10000010},
					  {0b10000000},
					  {0b11111111}};


u8 array2ToTest[8][8]={{1,1,0,0,0,0,0,1},
					   {1,0,1,1,1,1,1,1},
					   {1,0,0,1,0,0,0,1},
					   {1,0,0,1,1,0,0,1},
					   {1,0,0,1,0,1,0,1},
					   {1,0,0,1,0,0,1,1},
					   {1,0,0,1,0,0,0,1},
					   {1,0,0,1,0,0,0,1}};


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
		DIO_u8WritePortVal(coulmn,SMALLARRAY[counter1][0]);
		Delay(1);

	}



}


//timer 0 over flow ISR
ISR(__vector_11)
{	static u8 local_u8Timer0OVFCountermovingpart=0;
	static u8 local_u8Timer0OVFCounterledmatrix=0;

	local_u8Timer0OVFCountermovingpart++;
	local_u8Timer0OVFCounterledmatrix++;

	//its time to refresh the dot matrix
	if(local_u8Timer0OVFCounterledmatrix==DOTMATRIXREFRSHMENTRATE){
		local_u8Timer0OVFCounterledmatrix=0;
		Display_OnDotMatrix();

	}
	else{}

	//its time to move the part on the dot matrix
	if(local_u8Timer0OVFCountermovingpart==MOVINGPARTSTIME)
	{
		local_u8Timer0OVFCountermovingpart=0;
				arrayToTest[0][0]=Togglebit(arrayToTest[0][0],0);
		MatrixFlow();
	}
	else{}


}


void convert8by8to8by0matrix()
{u8 local_u8Rowcounter=0,local_u8colcounter=0;



//start critical section
	__asm__("CLI");

	for (local_u8Rowcounter = 0; local_u8Rowcounter < 8; local_u8Rowcounter++) {
		for (local_u8colcounter = 0; local_u8colcounter < 8;
				local_u8colcounter++) {
		//	SMALLARRAY   bigArray=
			if (bigArray[local_u8Rowcounter][local_u8colcounter]) {
				SMALLARRAY[7-local_u8Rowcounter][0]=Setbit(SMALLARRAY[7-local_u8Rowcounter][0],local_u8colcounter);

			} else {
				SMALLARRAY[7-local_u8Rowcounter][0]=Clrbit(SMALLARRAY[7-local_u8Rowcounter][0],local_u8colcounter);
			}
}

	}

//the  end  of the critical section
	__asm__("SEI");
}


int main(void) {
	u8 oldVal=0x00;
	u8 counter = 0;
	u8 local_u8_keypadVal = 0x00;
	u8 local_u8ASCIIToDisplay = 0;
	// char Strings[5]="";
	DIO_voidInit();
	//LCD_VOIDInit();
	KPD_voidInit();
	Timer0_voidInit();
    MatrixRotate(Lshape,temparr);
	MatrixAddition(temparr);
	convert8by8to8by0matrix();

	while (1) {

		KPD_u8Read(&local_u8_keypadVal);
		if(local_u8_keypadVal!=oldVal)
		{
			oldVal=local_u8_keypadVal;
		arrayToTest[2][0]=local_u8_keypadVal;
		}
		else
		{}
	}
	return 0;
}

