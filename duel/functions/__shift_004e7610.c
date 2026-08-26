/*
 * Decompiled function: __shift
 * Entry Point: 004e7610
 * Size: 54 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __shift
   
   Library: Visual Studio 1998 Debug */

void __shift(char *str_1,int arg2)

{
  size_t sVar1;
  
  if (arg2 != 0) {
    sVar1 = _strlen(str_1);
    FID_conflict__memcpy(str_1 + arg2,str_1,sVar1 + 1);
  }
  return;
}


