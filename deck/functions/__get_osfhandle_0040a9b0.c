/*
 * Decompiled function: __get_osfhandle
 * Entry Point: 0040a9b0
 * Size: 118 bytes
 */
#include "deck.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __get_osfhandle
   
   Library: Visual Studio 1998 Debug */

intptr_t __cdecl __get_osfhandle(int arg_1)

{
  intptr_t val_1;
  
  if (((uint32_t)arg_1 < DAT_004157fc) &&
     ((*(uint8_t *)(*(int *)((int)&DAT_004156c0 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 4 +
                (arg_1 & 0x1fU) * 8) & 1) != 0)) {
    val_1 = *(intptr_t *)
             (*(int *)((int)&DAT_004156c0 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + (arg_1 & 0x1fU) * 8
             );
  }
  else {
    _DAT_00412a6c = 9;
    _DAT_00412a70 = 0;
    val_1 = -1;
  }
  return val_1;
}


