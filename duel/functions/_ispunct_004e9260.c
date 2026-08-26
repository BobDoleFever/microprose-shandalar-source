/*
 * Decompiled function: _ispunct
 * Entry Point: 004e9260
 * Size: 68 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _ispunct
   
   Library: Visual Studio 1998 Debug */

int __cdecl _ispunct(int arg_1)

{
  uint uVar1;
  
  if (DAT_005096ac < 2) {
    uVar1 = *(ushort *)(PTR_DAT_005094a0 + arg_1 * 2) & 0x10;
  }
  else {
    uVar1 = __isctype(arg_1,0x10);
  }
  return uVar1;
}


