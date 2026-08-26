/*
 * Decompiled function: __get_osfhandle
 * Entry Point: 004e5dc0
 * Size: 118 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __get_osfhandle
   
   Library: Visual Studio 1998 Debug */

intptr_t __cdecl __get_osfhandle(int arg_1)

{
  intptr_t iVar1;
  
  if (((uint)arg_1 < DAT_006c1c90) &&
     ((*(byte *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 4 +
                (arg_1 & 0x1fU) * 8) & 1) != 0)) {
    iVar1 = *(intptr_t *)
             (*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + (arg_1 & 0x1fU) * 8
             );
  }
  else {
    DAT_00509420 = 9;
    DAT_00509424 = 0;
    iVar1 = -1;
  }
  return iVar1;
}


