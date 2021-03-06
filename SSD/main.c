/*
 * main.c
 *
 *  Created on: Feb 3, 2016
 *      Author: mahmoud
 */
#include"Delay_prog.c"
#include "SSD_Interface.h"
#include"DIO_Interface.h"
#include"DIO_private.h"
#include "Button_Interface.h"
//#include "SWITCH_Interface.h"
#include "util.h"
#define SH_CLK DIO_u8PIN2
#define SERIAL  DIO_u8PIN0
#define ST_CLK	DIO_u8PIN1
#define OE DIO_u8PIN3
#define u8_MOTORL DIO_u8PIN16
#define u8_MOTORR DIO_u8PIN17
//#define smallDelay 0


u8 DOTMATRIX47959_PRIVATE_u8_ThecahracterLMatrix[8][1]=
		   {{0b10000000},
			{0b10000000},
			{0b10000000},
			{0b10000000},
			{0b10000000},
			{0b10000000},
			{0b10000000},
			{0b11111111}};

u8 DOTMATRIX47959_PRIVATE_u8_ThecahracterRMatrix[8][1]=
			{{0b00000000},
			{0b11110000},
			{0b10001000},
			{0b10001000},
			{0b11111000},
			{0b10001000},
			{0b10000100},
			{0b10000010}};




/*
u64 try1[8][1]={{0b00000000	00000000	00000000	00000000	00011000	10000001	11110000	00000000},
				{0b11000110	00111100	10000001	11000110	00100100	10000001	10001000	00000000},
				{0b11000110	01000010	10000001	11000110	01000010	10000001	10000100	00000000},
				{0b10101010	10000001	10000001	10101010	10000001	10000001	10000010	00000000},
				{0b10010010	11111111	11111111	10010010	10000001	10000001	10000010	00000000},
				{0b10000010	10000001	10000001	10000010	01000010	01000010	10000100	00000000},
				{0b10000010	10000001	10000001	10000010	00100100	00100100	10001000	00000000},
				{0b10000010	10000001	10000001	10000010	00011000	00011000	11110000	00000000}};

*/


/*
 // move right array
u64 try12[8][1]={{0b0000000000000000000000000000000000000000000000000000000000000000},
				{0b1100011000111100100000011100011000111100100000011111100000000000},
				{0b1100011001000010100000011100011001000010100000011000010000000000},
				{0b1010101010000001100000011010101010000001100000011000001000000000},
				{0b1001001011111111111111111001001010000001100000011000001000000000},
				{0b1000001010000001100000011000001001000010010000101000001000000000},
				{0b1000001010000001100000011000001000111100001001001000010000000000},
				{0b1000001010000001100000011000001000000000000110001111100000000000}};
*/


 // move right array//mahmoud mohamed arabic
u64 try12[8][1]={{0b0000000000000000000000000000000000000000000000000000000000000000},
				 {0b1000000000000000000001000011111000000000111000000000000000000000},
				 {0b0100000011000000000000100010001000000000001110000000000000000000},
				 {0b0010000001100000000000010010001000000000000001100000000000000000},
				 {0b0001000000110000000000010010001000000000000000011000000000000000},
				 {0b1111111111111111100111110011111111111111111111111111111000000000},
				 {0b0000001010000010100000000000001000000100100000000000101000000000},
				 {0b0000001110000011100000000011111000000111100000000000111000000000}};
/*

// move right array//AKRAM arabic
u64 try12[8][1]={{0b0000000000000000000000000000000000000000111000000000000000000000},
				 {0b0000000000000000000000000000000000000000111000000000000000000000},
				 {0b0000000000000000000000000000000000000000111000000000011100000000},
				 {0b0000000110000000000000110000110000110000111000000000011100000000},
				 {0b0000000001000000000000110000110000110000111000000000011100000000},
				 {0b0000000000100000000000110000110000110000111111111111111100000000},
				 {0b0000000000111111111111111111111111110000111111111111111100000000},
				 {0b0000011111000000000000000000000000000000000000001100011000000000}};


u64 try12[8][1]={{0b0000000000000000000000000000000000000000000000000000011100000000},
				 {0b0000000000000000000000000000000000000000000000000000010100000000},
				 {0b0000000000000000000000000000000000000000000000000000011100000000},
				 {0b0000000000000000000000000000000000000000000001110000000000000000},
				 {0b0000000000000000000000000001010010000001110000111000011100000000},
				 {0b00000000000000000000000000010100100000011100000011000011100000000},
				 {0b0000000000000000000000000001000011111111110000000111111100000000},
				 {0b0000000000000000000000000111111111111111100011111111111100000000}};


*/


//move left array
u64 try1[8][1]={{0b0000000000000000000000000000000000000000000000000000000000000000},
				{0b0000000011000110001111001000000111000110001111001000000111111000},
				{0b0000000011000110010000101000000111000110010000101000000110000100},
				{0b0000000010101010100000011000000110101010100000011000000110000010},
				{0b0000000010010010111111111111111110010010100000011000000110000010},
				{0b0000000010000010100000011000000110000010010000100100001010000010},
				{0b0000000010000010100000011000000110000010001111000010010010000100},
				{0b0000000010000010100000011000000110000010000000000001100011111000}};
u8 l[8][1]={{0b10000000},
			{0b10000000},
			{0b10000000},
			{0b10000000},
			{0b10000000},
			{0b10000000},
			{0b10000000},
			{0b11111111}};

u8 R[8][1]={{0b00000000},
			{0b11110000},
			{0b10001000},
			{0b10001000},
			{0b11111000},
			{0b10001000},
			{0b10000100},
			{0b10000010}};




#define coulmn PORTA
#define Row  PORTD

// move righ function
 void DisR(u8 copy_u8Frame)
{ u8 i,counter=0x01;
u8 counter2;
static u8 local_u8MovingCounter=0,local_u8ShiftIndex=0;
counter2=~counter;
	for(i=0;i<8;i++)
	{

		local_u8MovingCounter++;
		coulmn= try12 [i][1]>>local_u8ShiftIndex;
		Row=counter2;
		Delay(2);
		counter<<=1;
		counter2=~counter;
		if(local_u8MovingCounter==100)
		{

			local_u8ShiftIndex++;
			local_u8ShiftIndex%=65;
			local_u8MovingCounter=0;
		}


	}
}


void Dis(u8 copy_u8Frame)
{ u8 i,counter=0x01;
u8 counter2;
u64 temp;
static u8 local_u8MovingCounter=0,local_u8ShiftIndex=0;
counter2=~counter;
	for(i=0;i<8;i++)
	{

		local_u8MovingCounter++;
		temp=try1 [i][1]<<local_u8ShiftIndex;
		temp=temp>>56;
		coulmn= temp;
		Row=counter2;
		Delay(2);
		counter<<=1;
		counter2=~counter;
		if(local_u8MovingCounter==100)
		{

			local_u8ShiftIndex++;
			local_u8ShiftIndex%=65;
			local_u8MovingCounter=0;
		}


	}
}

void shiftR(u8 y)
{ u8 x;
	for(x=0;x<8;x++)
	{
	DIO_u8WritePinVal(SERIAL,GetBit(y<<x,7));
	//DIO_u8WritePinVal(SERIAL,0x01);
	DIO_u8WritePinVal(SH_CLK,1);
	DIO_u8WritePinVal(SH_CLK,0);
	}

}
void shift(u8 copy_u8ROWS,u8 copy_u8COL)
{ u8 local_u8Counter=0;
	for(local_u8Counter=0;local_u8Counter<8;local_u8Counter++)
	{
	DIO_u8WritePinVal(SERIAL,GetBit(copy_u8ROWS<<local_u8Counter,7));
	DIO_u8WritePinVal(SH_CLK,1);
	DIO_u8WritePinVal(SH_CLK,0);
	}
	for(local_u8Counter=0;local_u8Counter<8;local_u8Counter++)
	{
	DIO_u8WritePinVal(SERIAL,GetBit(copy_u8COL<<local_u8Counter,7));
	DIO_u8WritePinVal(SH_CLK,1);
	DIO_u8WritePinVal(SH_CLK,0);
	}
	DIO_u8WritePinVal(ST_CLK,1);
	Delay(0);
	DIO_u8WritePinVal(ST_CLK,0);
}
////////////////////////////////////////////////////////////

extern u8 DOTMATRIX47959_u8ShiftROWSANDCOL1(u8 copy_u8ROWS, u8 copy_u8COL) {
	u8 local_u8OperationStatus=ok;

   DIO_u8WritePortVal(DIO_u8PORT0,copy_u8ROWS);
   DIO_u8WritePortVal(DIO_u8PORT2,copy_u8COL);
	//local_u8OperationStatus=DIO_u8WritePinVal(ST_CLK, DIO_u8HIGH);
	Delay(0);
	//local_u8OperationStatus=DIO_u8WritePinVal(ST_CLK, DIO_u8LOW);
	return local_u8OperationStatus;
}

/*comment!:help the user to choose the character to display */
extern u8 DOTMATRIX47959_u8Shifthelper(u8 copy_u8Cahracter) {
	u8 local_u8OperationStatus = ok;
	u8 static local_u8Counter=0;
	u8 local_u8Rows,local_u8Col;
	switch (copy_u8Cahracter) {
	case 0:
/*		for(local_u8Counter=0;local_u8Counter<8;local_u8Counter++)
		{local_u8Rows=DOTMATRIX47959_PRIVATE_u8_ThecahracterLMatrix[local_u8Counter][0];
		local_u8Col=~(0x80)>>local_u8Counter;
		DOTMATRIX47959_u8ShiftROWSANDCOL(local_u8Rows,local_u8Col);
			}*/

				local_u8Col=DOTMATRIX47959_PRIVATE_u8_ThecahracterLMatrix[local_u8Counter][0];
				local_u8Rows=~(0x80)>>local_u8Counter;
				DOTMATRIX47959_u8ShiftROWSANDCOL1(local_u8Rows,local_u8Col);
				local_u8Counter++;
				if(local_u8Counter>=8)
					{local_u8Counter=0;}
				else{}


		break;
	case 1:
/*		for(local_u8Counter=0;local_u8Counter<8;local_u8Counter++)
		{local_u8Rows=DOTMATRIX47959_PRIVATE_u8_ThecahracterRMatrix[local_u8Counter][0];
		local_u8Col=~(0x80)>>local_u8Counter;
		DOTMATRIX47959_u8ShiftROWSANDCOL(local_u8Rows,local_u8Col);
			}*/

		local_u8Col=DOTMATRIX47959_PRIVATE_u8_ThecahracterRMatrix[local_u8Counter][0];
		local_u8Rows=~(0x80)>>local_u8Counter;
		DOTMATRIX47959_u8ShiftROWSANDCOL1(local_u8Rows,local_u8Col);
		local_u8Counter++;
		if(local_u8Counter>=8)
			{local_u8Counter=0;}
		else{}
		break;
	default:
		DOTMATRIX47959_u8ShiftROWSANDCOL1(0x00,0x00);
		break;
	}
	return local_u8OperationStatus;

}



/////////////////////////////////////////////////////////////




int main(void) {

	//u8 local_u8Counter=1;//, local_u8CopyLastVal;
	u8 x=0,y=0x01,X,y2=0xfe;
	DIO_voidInit();

	while (1) {

			//SSD_u8DisplayMultiScreen(3,6,0,x);
			//SSD_u8DisplayMultiScreen(2,2,0,y);

		//DisR(0);

/*for(X=0;X<8;X++)
{y=l[X][0];
 y2=~(0x80)>>X;
shift(0x00,0x00);
	}*/
/*y2=0x08;
y=0x01;
for(x=0;x<4;x++)
{

	//DIO_u8WritePortVal(0,y2>>x);
	DIO_u8WritePortVal(0,y<<x);

	Delay(3);
}*/
		DOTMATRIX47959_u8Shifthelper(1);
//		DOTMATRIX47959_u8ShiftROWSANDCOL1(0xfe,0x03);
//		PORTA=0x02;
//		PORTC=0xff;

	}
	return 0;
}





