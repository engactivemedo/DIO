/*
 * Tertris_App.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Belal
 */

#ifndef TERTRIS_APP_H_
#define TERTRIS_APP_H_



 const u8 Ishape[2][2] =  { { 1, 0 },
		 	 	 	  { 1, 0 } };

 const u8 Tshape[2][2] = { { 1, 1 },
		 	 	 	 { 0, 0 } };

 const u8 Lshape[2][2] = { { 1, 0 },
		 	 	 	 { 1, 1 } };

 const u8 Sshape[2][2] = { { 1, 1 },
		 	 	 	 { 1, 1 } };

 const u8 LIshape[2][2] = { { 0, 1 },
		 	 	 	  { 1, 1 } };

 const u8 LTshape[2][2] = { { 1, 1 },
		 	 	 	  { 1, 0 } };

 const u8 LTIshape[2][2] = { { 1, 1 },
		 	 	 	        { 0, 1 } };


  u8 temparr[2][2] = 		{ { 0, 0 },
		 	 	 	        { 0, 0 } };
 void MatrixRotate(u8 Copy_u8PtrToMatrix[][2], u8  Copy_u8PtrTonewMatrix [][2]);
 void MatrixAddition(u8 Copy_u8PtrToMatrix[][2]);
 void MatrixFlow(void);

#endif /* TERTRIS_APP_H_ */
