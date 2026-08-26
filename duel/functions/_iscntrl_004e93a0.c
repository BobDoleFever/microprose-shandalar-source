/*
 * Decompiled function: _iscntrl
 * Entry Point: 004e93a0
 * Size: 68 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _iscntrl
   
   Library: Visual Studio 1998 Debug */

int __cdecl _iscntrl(int arg_1)

{
  uint uVar1;
  
  if (DAT_005096ac < 2) {
    uVar1 = *(ushort *)(PTR_DAT_005094a0 + arg_1 * 2) & 0x20;
  }
  else {
    uVar1 = __isctype(arg_1,0x20);
  }
  return uVar1;
}


