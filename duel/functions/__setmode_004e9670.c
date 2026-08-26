/*
 * Decompiled function: __setmode
 * Entry Point: 004e9670
 * Size: 308 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __setmode
   
   Library: Visual Studio 1998 Debug */

int __cdecl __setmode(int arg1,int arg2)

{
  char cVar1;
  int iVar2;
  
  if (((uint)arg1 < DAT_006c1c90) &&
     ((*(byte *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg1 & 0xffffffe0U) >> 3)) + 4 +
                (arg1 & 0x1fU) * 8) & 1) != 0)) {
    cVar1 = *(char *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg1 & 0xffffffe0U) >> 3)) + 4 +
                     (arg1 & 0x1fU) * 8);
    if (arg2 == 0x8000) {
      *(byte *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg1 & 0xffffffe0U) >> 3)) + 4 +
               (arg1 & 0x1fU) * 8) =
           *(byte *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg1 & 0xffffffe0U) >> 3)) + 4 +
                    (arg1 & 0x1fU) * 8) & 0x7f;
    }
    else {
      if (arg2 != 0x4000) {
        DAT_00509420 = 0x16;
        return -1;
      }
      *(byte *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg1 & 0xffffffe0U) >> 3)) + 4 +
               (arg1 & 0x1fU) * 8) =
           *(byte *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg1 & 0xffffffe0U) >> 3)) + 4 +
                    (arg1 & 0x1fU) * 8) | 0x80;
    }
    if (((int)cVar1 & 0x80U) == 0) {
      iVar2 = 0x8000;
    }
    else {
      iVar2 = 0x4000;
    }
  }
  else {
    DAT_00509420 = 9;
    iVar2 = -1;
  }
  return iVar2;
}


