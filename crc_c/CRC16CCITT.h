//#############################################################################
//File Name   : CRC16CCITT.h
//Programmer  : Yan Naing Aye
//WebSite: http://cool-emerald.blogspot.sg/
//License: Creative Commons Attribution-ShareAlike 3.0
//         http://creativecommons.org/licenses/by-sa/3.0/
//Date: 31 July 2009
//#############################################################################
#ifndef   __CRC16CCITT_H
    #define __CRC16CCITT_H
	
	#define CRC16CCITT_InitialValue() 0xFFFF
	unsigned int CRC16CCITT_Calculate(char* s,unsigned char len,unsigned int crc);
	void CRC16CCITT_ToString(unsigned int crc,char* s);
#endif