/*
 * Decompiled function: __free_osfhnd
 * Entry Point: 004e5ca0
 * Size: 263 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __free_osfhnd
   
   Library: Visual Studio 1998 Debug */

int __cdecl __free_osfhnd(int arg_1)

{
  int iVar1;
  
  if ((((uint)arg_1 < DAT_006c1c90) &&
      ((*(byte *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 4 +
                 (arg_1 & 0x1fU) * 8) & 1) != 0)) &&
     (*(int *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3)) +
              (arg_1 & 0x1fU) * 8) != -1)) {
    if (DAT_005096ec == 1) {
      if (arg_1 == 0) {
        SetStdHandle(0xfffffff6,(HANDLE)0x0);
      }
      else if (arg_1 == 1) {
        SetStdHandle(0xfffffff5,(HANDLE)0x0);
      }
      else if (arg_1 == 2) {
        SetStdHandle(0xfffffff4,(HANDLE)0x0);
      }
    }
    *(undefined4 *)
     (*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + (arg_1 & 0x1fU) * 8) =
         0xffffffff;
    iVar1 = 0;
  }
  else {
    DAT_00509420 = 9;
    DAT_00509424 = 0;
    iVar1 = -1;
  }
  return iVar1;
}


