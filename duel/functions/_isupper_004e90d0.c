/*
 * Decompiled function: _isupper
 * Entry Point: 004e90d0
 * Size: 68 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _isupper
   
   Library: Visual Studio 1998 Debug */

int __cdecl _isupper(int arg_1)

{
  uint uVar1;
  
  if (DAT_005096ac < 2) {
    uVar1 = *(ushort *)(PTR_DAT_005094a0 + arg_1 * 2) & 1;
  }
  else {
    uVar1 = __isctype(arg_1,1);
  }
  return uVar1;
}


