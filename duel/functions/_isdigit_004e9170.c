/*
 * Decompiled function: _isdigit
 * Entry Point: 004e9170
 * Size: 68 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _isdigit
   
   Library: Visual Studio 1998 Debug */

int __cdecl _isdigit(int arg_1)

{
  uint uVar1;
  
  if (DAT_005096ac < 2) {
    uVar1 = *(ushort *)(PTR_DAT_005094a0 + arg_1 * 2) & 4;
  }
  else {
    uVar1 = __isctype(arg_1,4);
  }
  return uVar1;
}


