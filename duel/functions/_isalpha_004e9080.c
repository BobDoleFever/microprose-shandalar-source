/*
 * Decompiled function: _isalpha
 * Entry Point: 004e9080
 * Size: 74 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _isalpha
   
   Library: Visual Studio 1998 Debug */

int __cdecl _isalpha(int arg_1)

{
  uint uVar1;
  
  if (DAT_005096ac < 2) {
    uVar1 = *(ushort *)(PTR_DAT_005094a0 + arg_1 * 2) & 0x103;
  }
  else {
    uVar1 = __isctype(arg_1,0x103);
  }
  return uVar1;
}


