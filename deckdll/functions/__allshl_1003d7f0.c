/*
 * Decompiled function: __allshl
 * Entry Point: 1003d7f0
 * Size: 31 bytes
 */
#include "deckdll.h"


/* Library Function - Single Match
    __allshl
   
   Library: Visual Studio */

longlong __fastcall __allshl(uint8_t arg1,int arg2)

{
  uint32_t reg_eax;
  
  if (0x3f < arg1) {
    return 0;
  }
  if (arg1 < 0x20) {
    return CONCAT44(arg2 << (arg1 & 0x1f) | reg_eax >> 0x20 - (arg1 & 0x1f),reg_eax << (arg1 & 0x1f));
  }
  return (ulonglong)(reg_eax << (arg1 & 0x1f)) << 0x20;
}


