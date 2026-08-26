/*
 * Decompiled function: __allshl
 * Entry Point: 00513c50
 * Size: 31 bytes
 */
#include "magic.h"


/* Library Function - Single Match
    __allshl
   
   Library: Visual Studio */

longlong __fastcall __allshl(byte arg1,int arg2)

{
  uint in_EAX;
  
  if (0x3f < arg1) {
    return 0;
  }
  if (arg1 < 0x20) {
    return CONCAT44(arg2 << (arg1 & 0x1f) | in_EAX >> 0x20 - (arg1 & 0x1f),in_EAX << (arg1 & 0x1f));
  }
  return (ulonglong)(in_EAX << (arg1 & 0x1f)) << 0x20;
}


