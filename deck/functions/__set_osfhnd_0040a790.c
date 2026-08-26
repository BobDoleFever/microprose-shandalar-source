/*
 * Decompiled function: __set_osfhnd
 * Entry Point: 0040a790
 * Size: 234 bytes
 */
#include "deck.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __set_osfhnd
   
   Library: Visual Studio 1998 Debug */

int __cdecl __set_osfhnd(int arg1,intptr_t arg2)

{
  int val_1;
  
  if (((uint32_t)arg1 < DAT_004157fc) &&
     (*(int *)(*(int *)((int)&DAT_004156c0 + ((int)(arg1 & 0xffffffe0U) >> 3)) + (arg1 & 0x1fU) * 8)
      == -1)) {
    if (DAT_00412a68 == 1) {
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
     (*(int *)((int)&DAT_004156c0 + ((int)(arg1 & 0xffffffe0U) >> 3)) + (arg1 & 0x1fU) * 8) = arg2;
    val_1 = 0;
  }
  else {
    _DAT_00412a6c = 9;
    _DAT_00412a70 = 0;
    val_1 = -1;
  }
  return val_1;
}


