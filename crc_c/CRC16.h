//#############################################################################
//File Name   : CRC16.h
//Programmer  : Yan Naing Aye
//WebSite: http://cool-emerald.blogspot.sg/
//License: Creative Commons Attribution-ShareAlike 3.0
//         http://creativecommons.org/licenses/by-sa/3.0/
//Date: 31 July 2009
//#############################################################################
#ifndef   __CRC16_H
    #define __CRC16_H
	
	#define CRC16_InitialValue() 0x0000
	unsigned int CRC16_Calculate(char* s,unsigned char len,unsigned int crc);
	void CRC16_ToString(unsigned int crc,char* s);
#endif