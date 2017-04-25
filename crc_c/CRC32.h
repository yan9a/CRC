//#############################################################################
//File Name   : CRC32.h
//Programmer  : Yan Naing Aye
//WebSite: http://cool-emerald.blogspot.sg/
//License: Creative Commons Attribution-ShareAlike 3.0
//         http://creativecommons.org/licenses/by-sa/3.0/
//Date: 31 July 2009
//#############################################################################
#ifndef   __CRC32_H
    #define __CRC32_H
	
	#define CRC32_InitialValue() 0xFFFFFFFF
	unsigned long CRC32_Calculate(char* s,unsigned char len,unsigned long crc);
	void CRC32_ToString(unsigned long crc,char* s);
#endif