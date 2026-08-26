/*
 * Decompiled function: __CrtSetDbgBlockType
 * Entry Point: 004044d0
 * Size: 160 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    __CrtSetDbgBlockType
   
   Library: Visual Studio 1998 Debug */

void __cdecl __CrtSetDbgBlockType(int arg1,int32_t arg2)

{
  code *char_ptr_1;
  BOOL BVar2;
  int val_3;
  
  BVar2 = __CrtIsValidHeapPointer(arg1);
  if (BVar2 != 0) {
    if (((((*(uint32_t *)(arg1 + -0xc) & 0xffff) != 4) && (*(int *)(arg1 + -0xc) != 1)) &&
        ((*(uint32_t *)(arg1 + -0xc) & 0xffff) != 2)) && (*(int *)(arg1 + -0xc) != 3)) {
      val_3 = __CrtDbgReport(2,0x410460,0x4d3,0,"_BLOCK_TYPE_IS_VALID(pHead->nBlockUse)");
      if (val_3 == 1) {
        char_ptr_1 = (code *)swi(3);
        (*char_ptr_1)();
        return;
      }
    }
    *(int32_t *)(arg1 + -0xc) = arg2;
  }
  return;
}


