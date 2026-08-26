/*
 * Decompiled function: __msize_dbg
 * Entry Point: 00404330
 * Size: 358 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    __msize_dbg
   
   Library: Visual Studio 1998 Debug */

int32_t __cdecl __msize_dbg(int arg1,int arg2)

{
  code *char_ptr_1;
  int val_2;
  int32_t uval_3;
  BOOL BVar4;
  
  if (((uint8_t)DAT_00412e28 & 4) != 0) {
    val_2 = __CrtCheckMemory();
    if (val_2 == 0) {
      val_2 = __CrtDbgReport(2,0x410460,0x47c,0,"_CrtCheckMemory()");
      if (val_2 == 1) {
        char_ptr_1 = (code *)swi(3);
        uval_3 = (*char_ptr_1)();
        return uval_3;
      }
    }
  }
  BVar4 = __CrtIsValidHeapPointer(arg1);
  if (BVar4 == 0) {
    val_2 = __CrtDbgReport(2,0x410460,0x485,0,"_CrtIsValidHeapPointer(pUserData)");
    if (val_2 == 1) {
      char_ptr_1 = (code *)swi(3);
      uval_3 = (*char_ptr_1)();
      return uval_3;
    }
  }
  if (((((*(uint32_t *)(arg1 + -0xc) & 0xffff) != 4) && (*(int *)(arg1 + -0xc) != 1)) &&
      ((*(uint32_t *)(arg1 + -0xc) & 0xffff) != 2)) && (*(int *)(arg1 + -0xc) != 3)) {
    val_2 = __CrtDbgReport(2,0x410460,0x48b,0,"_BLOCK_TYPE_IS_VALID(pHead->nBlockUse)");
    if (val_2 == 1) {
      char_ptr_1 = (code *)swi(3);
      uval_3 = (*char_ptr_1)();
      return uval_3;
    }
  }
  if ((*(int *)(arg1 + -0xc) == 2) && (arg2 == 1)) {
    arg2 = 2;
  }
  if ((*(int *)(arg1 + -0xc) != 3) && (*(int *)(arg1 + -0xc) != arg2)) {
    val_2 = __CrtDbgReport(2,0x410460,0x492,0,"pHead->nBlockUse == nBlockUse");
    if (val_2 == 1) {
      char_ptr_1 = (code *)swi(3);
      uval_3 = (*char_ptr_1)();
      return uval_3;
    }
  }
  return *(int32_t *)(arg1 + -0x10);
}


