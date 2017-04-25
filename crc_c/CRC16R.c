//#############################################################################
//File Name   : CRC16R.c
//Programmer  : Yan Naing Aye
//WebSite: http://cool-emerald.blogspot.sg/
//License: Creative Commons Attribution-ShareAlike 3.0
//         http://creativecommons.org/licenses/by-sa/3.0/
//Date: 31 July 2009
//#############################################################################
#include "CRC16R.h"
//-----------------------------------------------------------------------------
//Inputs
//s : pointer to input char string
//len: string len (maximum 255)
//crc: initial CRC value

//Output
//Returns calculated CRC
unsigned int CRC16R_Calculate(char* s,unsigned char len,unsigned int crc)
{      	
    //CRC Order: 16
    //CCITT(recommendation) : F(x)= x16 + x12 + x5 + 1
    //CRC Poly: 0x8408 <=> 0x1021
    //Operational initial value:  0xFFFF 
    //Final xor value: 0xFFFF
	unsigned char i,j;		
    for(i=0;i<len;i++,s++)
    {
		crc^=((unsigned int)(*s)) & 0xFF;
		for(j=0;j<8;j++)
		{
    		if(crc & 0x0001) crc=(crc>>1)^0x8408;
			else crc>>=1;
		}
    }
	crc^=0xFFFF;
    return crc;
}
//------------------------------------------------------------------------------
//Input
//CRC : value to convert to string

//Output
//s : it will be updated with CRC value, there will be no NULL termination
void CRC16R_ToString(unsigned int crc,char* s)
{
	*s++=(unsigned char)(crc & 0xFF);
	*s=(unsigned char)(crc>>8);
}
//------------------------------------------------------------------------------