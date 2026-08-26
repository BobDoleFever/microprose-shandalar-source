/*
 * Decompiled function: __CrtIsMemoryBlock
 * Entry Point: 00404b80
 * Size: 255 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    __CrtIsMemoryBlock
   
   Library: Visual Studio 1998 Debug */

int32_t __cdecl
__CrtIsMemoryBlock(void *ptr_1,UINT_PTR arg_2,int32_t *ptr_3,int32_t *ptr_4,int32_t *ptr_5)

{
  BOOL BVar1;
  int val_2;
  
  BVar1 = __CrtIsValidHeapPointer((int)ptr_1);
  if (((BVar1 != 0) &&
      (((((*(uint32_t *)((int)ptr_1 + -0xc) & 0xffff) == 4 || (*(int *)((int)ptr_1 + -0xc) == 1)) ||
        ((*(uint32_t *)((int)ptr_1 + -0xc) & 0xffff) == 2)) || (*(int *)((int)ptr_1 + -0xc) == 3)))) &&
     (((val_2 = __CrtIsValidPointer(ptr_1,arg_2,1), val_2 != 0 &&
       (*(UINT_PTR *)((int)ptr_1 + -0x10) == arg_2)) && (*(int *)((int)ptr_1 + -8) <= DAT_00412e2c))
     )) {
    if (ptr_3 != (int32_t *)0x0) {
      *ptr_3 = *(int32_t *)((int)ptr_1 + -8);
    }
    if (ptr_4 != (int32_t *)0x0) {
      *ptr_4 = *(int32_t *)((int)ptr_1 + -0x18);
    }
    if (ptr_5 != (int32_t *)0x0) {
      *ptr_5 = *(int32_t *)((int)ptr_1 + -0x14);
    }
    return 1;
  }
  return 0;
}


