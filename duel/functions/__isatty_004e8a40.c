/*
 * Decompiled function: __isatty
 * Entry Point: 004e8a40
 * Size: 66 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __isatty
   
   Library: Visual Studio 1998 Debug */

int __cdecl __isatty(int arg_1)

{
  uint uVar1;
  
  if ((uint)arg_1 < DAT_006c1c90) {
    uVar1 = (int)*(char *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 4 +
                          (arg_1 & 0x1fU) * 8) & 0x40;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


