/*
 * Decompiled function: __heap_init
 * Entry Point: 004e1ef0
 * Size: 93 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __heap_init
   
   Library: Visual Studio 1998 Debug */

int __cdecl __heap_init(void)

{
  int iVar1;
  
  DAT_006c1c94 = HeapCreate(1,0x1000,0);
  if (DAT_006c1c94 == (HANDLE)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = ___sbh_new_region();
    if (iVar1 == 0) {
      HeapDestroy(DAT_006c1c94);
      iVar1 = 0;
    }
    else {
      iVar1 = 1;
    }
  }
  return iVar1;
}


