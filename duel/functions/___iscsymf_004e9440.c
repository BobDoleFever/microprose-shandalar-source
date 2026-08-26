/*
 * Decompiled function: ___iscsymf
 * Entry Point: 004e9440
 * Size: 113 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    ___iscsymf
   
   Library: Visual Studio 1998 Debug */

int __cdecl ___iscsymf(int arg_1)

{
  int iVar1;
  uint local_8;
  
  if (DAT_005096ac < 2) {
    local_8 = *(ushort *)(PTR_DAT_005094a0 + arg_1 * 2) & 0x103;
  }
  else {
    local_8 = __isctype(arg_1,0x103);
  }
  if ((local_8 == 0) && (arg_1 != 0x5f)) {
    iVar1 = 0;
  }
  else {
    iVar1 = 1;
  }
  return iVar1;
}


