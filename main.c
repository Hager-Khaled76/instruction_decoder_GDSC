/*
 * main.c
 *
 *  Created on: Jul 28, 2024
 *      Author: !?
 */

//#include <stdtype.h>
#include<util/delay.h>
#include <avr/io.h>
//#include "PITS_CONTROL.h"
//#include"REG_CONTROLE.h"
typedef int u8;
/*
#define DDRA  *(( volatile u8*)0x3A)
#define DDRB  *(( volatile u8*)0x37)
#define DDRC  *(( volatile u8*)0x34)
#define DDRD  *(( volatile u8*)0x31)
#define PORTA  *(( volatile u8*)0x3B)
#define PORTB  *((volatile u8*)0x38)
#define PORTC  *((volatile u8*)0x35)
#define PORTD  *((volatile u8*)0x32)
#define PIND  *((volatile u8*)0x30)
#define PINA  *((volatile u8*)0x39)
#define PINB  *((volatile u8*)0x36)
*/
//true  bashmohandes

int main()
{
	// switch is input
	DDRA=0;
	PORTA=0xff;
	int x=0 , op1,op2;
	int seg_cth[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	// segment is output
	DDRC = 0xff;
	PORTC = seg_cth[0];// or any value
	DDRD = 0xff;  //00011101
	PORTD = seg_cth[0];
	int j,result;

	while(1)
	{
		x= ~PINA;
		PORTB =x;
		op1=x&7;
		op2=(x>>3)&7;
		if(((x>>6)&1)==0&&((x>>7)&1)==0) // sum
		{

			result=op1+op2;
			PORTC =seg_cth[result/10];
			PORTD =seg_cth[result%10];


		}


		else if(((x>>6)&1)==1&&((x>>7)&1)==0) // sub
		{
			result=op1-op2;
			PORTC =seg_cth[result/10];
			PORTD =seg_cth[result%10];

		}


		else if(((x>>6)&1)==0&&((x>>7)&1)==1) // mult
		{
			result=op1*op2;
			PORTC =seg_cth[result/10];
			PORTD =seg_cth[result%10];

		}

		else if(((x>>6)&1)==1&&((x>>7)&1)==1) // div
		{
			result=op1/op2;
			PORTC =seg_cth[result/10];
			PORTD =seg_cth[result%10];
		}


	}



}



/*
//true    Ana

int main()
{
	// switch is input
	DDRA=0;
	PORTA=0xff;
	u8 x=0;
	int seg_cth[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	// segment is output
	DDRC = 0xff;
	PORTC=0;
	DDRD = 0xff;
	PORTD =0;
	u8 j,sum,sub,mult,div,one,dec;
	while(1)
	{
		x= ~PINA;
		PORTB =x;
		if(((PINA>>6)&1)==0&&((PINA>>7)&1)==0) // sum
		{
			sum=(x&7)+((x>>3)&7);
			if(sum<=9)
			{
				j=0;
				PORTC =j;
				PORTD =seg_cth[sum];
			}
			else
			{
				one = sum%10;  // one
				PORTD =seg_cth[ one];
				dec=sum/10; // dec
				PORTC =seg_cth[ dec];

			}

		}


		else if(((PINA>>6)&1)==1&&((PINA>>7)&1)==0) // sub
		{
			sub=(x&7)-((x>>3)&7);
				j=0;
				PORTC =j;
				PORTD |= seg_cth[sub];
		}


		else if(((PINA>>6)&1)==0&&((PINA>>7)&1)==1) // mult
		{
			mult=(x&7)*((x>>3)&7);
			if(mult<=9)
			{
				j=0;
				PORTC =j;
				PORTD = seg_cth[mult];
			}
			else
			{
				one = mult%10;  // one
				PORTD =seg_cth[ one];
				dec = mult/10; // dec
				PORTC = seg_cth[dec];

			}

		}

		else if(((PINA>>6)&1)==1&&((PINA>>7)&1)==1) // div
		{
			div=(x&7)/((x>>3)&7);
				j=0;
				PORTC =j;
				PORTD = seg_cth[div];
		}

	}


}


*/





