/*
 * Tetris_App.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Belal
 */
#include "../types.h"
//#include "Tertris_App.h"


 u8 DotMatrix[8][8] =	   { { 0, 0, 0, 0, 0, 0, 0, 0 },
		                     { 0, 0, 0, 0, 0, 0, 0, 0 },
							 { 0, 0, 0, 0, 0, 0, 0, 0 },
							 { 0, 0, 0, 0, 0, 0, 0, 0 },
							 { 0, 0, 0, 0, 0, 0, 0, 0 },
							 { 0, 0, 0, 0, 0, 0, 0, 0 },
							 { 0, 0, 0, 0, 0, 0, 0, 0 },
	                         { 0, 0, 0, 0, 0, 0, 0, 0 } };
void MatrixRotate(u8 Copy_u8PtrToMatrix[][2], u8 Copy_u8PtrTonewMatrix[][2]) {
	u8 i, j;
	for (i = 0; i < 2; ++i) {
		for (j = 0; j < 2; ++j) {
			Copy_u8PtrTonewMatrix[i][j] = Copy_u8PtrToMatrix[2 - j - 1][i];
		}
	}
}

void MatrixAddition(u8 Copy_u8PtrToMatrix[][2]) {

	DotMatrix[0][3] = Copy_u8PtrToMatrix[0][0];
	DotMatrix[0][4] = Copy_u8PtrToMatrix[0][1];
	DotMatrix[1][3] = Copy_u8PtrToMatrix[1][0];
	DotMatrix[1][4] = Copy_u8PtrToMatrix[1][1];

}

void MatrixFlow(void) {
	u8 btn=1;
	static u8 counter=0;
	static u8 reault1=0;
	static u8 reault2=0;
	switch (btn) {
			case 0:



			break;
			case 1:

				//for (counter = 0; counter < 8; counter++)

					counter++;
					reault1=DotMatrix[counter + 1][3] + DotMatrix[counter][3];
					reault2=DotMatrix[counter + 1][4] +  DotMatrix[counter][4];
					if (reault1>1 || reault2>1){
						break;
					}
					else{
						DotMatrix[counter + 1][3] =DotMatrix[counter][3];
						DotMatrix[counter + 1][4]= DotMatrix[counter][4];
						DotMatrix[counter][3] = 0;
						DotMatrix[counter][4] = 0;
					}

				if(counter==7)
				{
					counter=0;

				}

				break;
	}
}
