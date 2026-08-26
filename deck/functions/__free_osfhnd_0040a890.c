/*
 * Decompiled function: __free_osfhnd
 * Entry Point: 0040a890
 * Size: 263 bytes
 */
#include "deck.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __free_osfhnd
   
   Library: Visual Studio 1998 Debug */

int __cdecl __free_osfhnd(int arg_1)

{
  int val_1;
  
  if ((((uint32_t)arg_1 < DAT_004157fc) &&
      ((*(uint8_t *)(*(int *)((int)&DAT_004156c0 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 4 +
                 (arg_1 & 0x1fU) * 8) & 1) != 0)) &&
     (*(int *)(*(int *)((int)&DAT_004156c0 + ((int)(arg_1 & 0xffffffe0U) >> 3)) +
              (arg_1 & 0x1fU) * 8) != -1)) {
    if (DAT_00412a68 == 1) {
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
    *(int32_t *)
     (*(int *)((int)&DAT_004156c0 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + (arg_1 & 0x1fU) * 8) =
         0xffffffff;
    val_1 = 0;
  }
  else {
    _DAT_00412a6c = 9;
    _DAT_00412a70 = 0;
    val_1 = -1;
  }
  return val_1;
}


