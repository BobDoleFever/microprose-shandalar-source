/*
 * Decompiled function: __set_osfhnd
 * Entry Point: 004e5ba0
 * Size: 234 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __set_osfhnd
   
   Library: Visual Studio 1998 Debug */

int __cdecl __set_osfhnd(int arg1,intptr_t arg2)

{
  int iVar1;
  
  if (((uint)arg1 < DAT_006c1c90) &&
     (*(int *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg1 & 0xffffffe0U) >> 3)) + (arg1 & 0x1fU) * 8)
      == -1)) {
    if (DAT_005096ec == 1) {
      if (arg1 == 0) {
        SetStdHandle(0xfffffff6,(HANDLE)arg2);
      }
      else if (arg1 == 1) {
        SetStdHandle(0xfffffff5,(HANDLE)arg2);
      }
      else if (arg1 == 2) {
        SetStdHandle(0xfffffff4,(HANDLE)arg2);
      }
    }
    *(intptr_t *)
     (*(int *)((int)&DAT_006c1b90 + ((int)(arg1 & 0xffffffe0U) >> 3)) + (arg1 & 0x1fU) * 8) = arg2;
    iVar1 = 0;
  }
  else {
    DAT_00509420 = 9;
    DAT_00509424 = 0;
    iVar1 = -1;
  }
  return iVar1;
}


