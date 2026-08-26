/*
 * Decompiled function: __callnewh
 * Entry Point: 004e1960
 * Size: 62 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __callnewh
   
   Library: Visual Studio 1998 Debug */

int __cdecl __callnewh(size_t arg_1)

{
  int iVar1;
  
  if ((DAT_005edaf0 != (code *)0x0) && (iVar1 = (*DAT_005edaf0)(arg_1), iVar1 != 0)) {
    return 1;
  }
  return 0;
}


