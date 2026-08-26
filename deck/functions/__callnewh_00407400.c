/*
 * Decompiled function: __callnewh
 * Entry Point: 00407400
 * Size: 62 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    __callnewh
   
   Library: Visual Studio 1998 Debug */

int __cdecl __callnewh(size_t arg_1)

{
  int val_1;
  
  if ((DAT_00414340 != (code *)0x0) && (val_1 = (*DAT_00414340)(arg_1), val_1 != 0)) {
    return 1;
  }
  return 0;
}


