/*
 * Decompiled function: __CrtIsMemoryBlock
 * Entry Point: 004dbe10
 * Size: 255 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __CrtIsMemoryBlock
   
   Library: Visual Studio 1998 Debug */

undefined4
__CrtIsMemoryBlock(void *arg_1,UINT_PTR arg_2,undefined4 *arg_3,undefined4 *arg_4,undefined4 *arg_5)

{
  int iVar1;
  
  iVar1 = __CrtIsValidHeapPointer((int)arg_1);
  if (((iVar1 != 0) &&
      (((((*(uint *)((int)arg_1 + -0xc) & 0xffff) == 4 || (*(int *)((int)arg_1 + -0xc) == 1)) ||
        ((*(uint *)((int)arg_1 + -0xc) & 0xffff) == 2)) || (*(int *)((int)arg_1 + -0xc) == 3)))) &&
     (((iVar1 = __CrtIsValidPointer(arg_1,arg_2,1), iVar1 != 0 &&
       (*(UINT_PTR *)((int)arg_1 + -0x10) == arg_2)) && (*(int *)((int)arg_1 + -8) <= DAT_00509474))
     )) {
    if (arg_3 != (undefined4 *)0x0) {
      *arg_3 = *(undefined4 *)((int)arg_1 + -8);
    }
    if (arg_4 != (undefined4 *)0x0) {
      *arg_4 = *(undefined4 *)((int)arg_1 + -0x18);
    }
    if (arg_5 != (undefined4 *)0x0) {
      *arg_5 = *(undefined4 *)((int)arg_1 + -0x14);
    }
    return 1;
  }
  return 0;
}


