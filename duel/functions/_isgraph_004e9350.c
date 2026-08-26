/*
 * Decompiled function: _isgraph
 * Entry Point: 004e9350
 * Size: 74 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _isgraph
   
   Library: Visual Studio 1998 Debug */

int __cdecl _isgraph(int arg_1)

{
  uint uVar1;
  
  if (DAT_005096ac < 2) {
    uVar1 = *(ushort *)(PTR_DAT_005094a0 + arg_1 * 2) & 0x117;
  }
  else {
    uVar1 = __isctype(arg_1,0x117);
  }
  return uVar1;
}


