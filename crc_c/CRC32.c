//#############################################################################
//File Name   : CRC32.c
//Programmer  : Yan Naing Aye
//WebSite: http://cool-emerald.blogspot.sg/
//License: Creative Commons Attribution-ShareAlike 3.0
//         http://creativecommons.org/licenses/by-sa/3.0/
//Date: 31 July 2009
//#############################################################################
#include "CRC32.h"
//-----------------------------------------------------------------------------
//Inputs
//s : pointer to input char string
//len: string len (maximum 255)
//crc: initial CRC value

//Output
//Returns calculated CRC
unsigned long CRC32_Calculate(char* s,unsigned char len,unsigned long crc)
{      	
    //CRC Order: 32        
    //CRC Poly: 0x04C11DB7 <=> EDB88320
    //Operational initial value:  0xFFFFFFFF 
    //Final xor value: 0xFFFFFFFF
	unsigned char i,j;		
    for(i=0;i<len;i++,s++)
    {
		crc^=((unsigned long)(*s)) & 0xFF;
		for(j=0;j<8;j++)
		{
    		if(crc & 0x00000001) crc=(crc>>1)^0xEDB88320;
			else crc>>=1;
		}
    }	
	crc^=0xFFFFFFFF;
    return crc;
}
//------------------------------------------------------------------------------
//Input
//CRC : value to convert to string

//Output
//s : it will be updated with CRC value, there will be no NULL termination
void CRC32_ToString(unsigned long crc,char* s)
{
	*s++=(unsigned char)(crc>>24);
	*s++=(unsigned char)((crc>>16) & 0xFF);
	*s++=(unsigned char)((crc>>8) & 0xFF);
	*s=(unsigned char)(crc & 0xFF);
}
//------------------------------------------------------------------------------