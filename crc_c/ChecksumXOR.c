//#############################################################################
//File Name   : ChecksumXOR.c
//Programmer  : Yan Naing Aye
//WebSite: http://cool-emerald.blogspot.sg/
//License: Creative Commons Attribution-ShareAlike 3.0
//         http://creativecommons.org/licenses/by-sa/3.0/
//Date: 31 July 2009
//#############################################################################
#include "ChecksumXOR.h"
//-----------------------------------------------------------------------------
//Inputs
//s : pointer to input char string
//len: string len (maximum 255)

//Output
//Returns calculated Checksum
unsigned char ChecksumXOR_Calculate(char* s,unsigned char len)
{      	
    //Checksum: Xor of all input chars
	unsigned char i;
	unsigned char cs=0;
    for(i=0;i<len;i++,s++)cs^=(unsigned char)(*s);    	
    return cs;
}
//------------------------------------------------------------------------------