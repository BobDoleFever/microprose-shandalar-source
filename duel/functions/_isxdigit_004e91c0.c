/*
 * Decompiled function: _isxdigit
 * Entry Point: 004e91c0
 * Size: 74 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _isxdigit
   
   Library: Visual Studio 1998 Debug */

int __cdecl _isxdigit(int arg_1)

{
  uint uVar1;
  
  if (DAT_005096ac < 2) {
    uVar1 = *(ushort *)(PTR_DAT_005094a0 + arg_1 * 2) & 0x80;
  }
  else {
    uVar1 = __isctype(arg_1,0x80);
  }
  return uVar1;
}


