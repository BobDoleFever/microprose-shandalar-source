/*
 * Decompiled function: __msize_dbg
 * Entry Point: 004db5c0
 * Size: 358 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __msize_dbg
   
   Library: Visual Studio 1998 Debug */

undefined4 __msize_dbg(int arg1,int arg2)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (((byte)DAT_00509470 & 4) != 0) {
    iVar2 = __CrtCheckMemory();
    if (iVar2 == 0) {
      iVar2 = __CrtDbgReport(2,0x4f0430,0x47c,0,"_CrtCheckMemory()");
      if (iVar2 == 1) {
        pcVar1 = (code *)swi(3);
        uVar3 = (*pcVar1)();
        return uVar3;
      }
    }
  }
  iVar2 = __CrtIsValidHeapPointer(arg1);
  if (iVar2 == 0) {
    iVar2 = __CrtDbgReport(2,0x4f0430,0x485,0,"_CrtIsValidHeapPointer(pUserData)");
    if (iVar2 == 1) {
      pcVar1 = (code *)swi(3);
      uVar3 = (*pcVar1)();
      return uVar3;
    }
  }
  if (((((*(uint *)(arg1 + -0xc) & 0xffff) != 4) && (*(int *)(arg1 + -0xc) != 1)) &&
      ((*(uint *)(arg1 + -0xc) & 0xffff) != 2)) && (*(int *)(arg1 + -0xc) != 3)) {
    iVar2 = __CrtDbgReport(2,0x4f0430,0x48b,0,"_BLOCK_TYPE_IS_VALID(pHead->nBlockUse)");
    if (iVar2 == 1) {
      pcVar1 = (code *)swi(3);
      uVar3 = (*pcVar1)();
      return uVar3;
    }
  }
  if ((*(int *)(arg1 + -0xc) == 2) && (arg2 == 1)) {
    arg2 = 2;
  }
  if ((*(int *)(arg1 + -0xc) != 3) && (*(int *)(arg1 + -0xc) != arg2)) {
    iVar2 = __CrtDbgReport(2,0x4f0430,0x492,0,"pHead->nBlockUse == nBlockUse");
    if (iVar2 == 1) {
      pcVar1 = (code *)swi(3);
      uVar3 = (*pcVar1)();
      return uVar3;
    }
  }
  return *(undefined4 *)(arg1 + -0x10);
}


