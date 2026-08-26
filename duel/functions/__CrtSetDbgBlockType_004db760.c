/*
 * Decompiled function: __CrtSetDbgBlockType
 * Entry Point: 004db760
 * Size: 160 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __CrtSetDbgBlockType
   
   Library: Visual Studio 1998 Debug */

void __CrtSetDbgBlockType(int arg1,undefined4 arg2)

{
  code *pcVar1;
  int iVar2;
  
  iVar2 = __CrtIsValidHeapPointer(arg1);
  if (iVar2 != 0) {
    if (((((*(uint *)(arg1 + -0xc) & 0xffff) != 4) && (*(int *)(arg1 + -0xc) != 1)) &&
        ((*(uint *)(arg1 + -0xc) & 0xffff) != 2)) && (*(int *)(arg1 + -0xc) != 3)) {
      iVar2 = __CrtDbgReport(2,0x4f0430,0x4d3,0,"_BLOCK_TYPE_IS_VALID(pHead->nBlockUse)");
      if (iVar2 == 1) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
    }
    *(undefined4 *)(arg1 + -0xc) = arg2;
  }
  return;
}


