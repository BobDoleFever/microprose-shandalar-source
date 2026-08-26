/*
 * Decompiled function: __fpreset
 * Entry Point: 004ea4e0
 * Size: 89 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __fpreset
   
   Library: Visual Studio 1998 Debug */

void __cdecl __fpreset(void)

{
  int iVar1;
  
  iVar1 = DAT_0050a670;
  __setdefaultprecision();
  if ((iVar1 != 0) && ((**(uint **)(iVar1 + 4) & 0x10008) != 0)) {
    iVar1 = *(int *)(iVar1 + 4);
    *(undefined4 *)(iVar1 + 0x20) = 0;
    *(undefined4 *)(iVar1 + 0x24) = 0xffff;
  }
  return;
}


