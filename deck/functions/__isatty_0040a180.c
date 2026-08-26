/*
 * Decompiled function: __isatty
 * Entry Point: 0040a180
 * Size: 66 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    __isatty
   
   Library: Visual Studio 1998 Debug */

int __cdecl __isatty(int arg_1)

{
  uint32_t uval_1;
  
  if ((uint32_t)arg_1 < DAT_004157fc) {
    uval_1 = (int)*(char *)(*(int *)((int)&DAT_004156c0 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 4 +
                          (arg_1 & 0x1fU) * 8) & 0x40;
  }
  else {
    uval_1 = 0;
  }
  return uval_1;
}


