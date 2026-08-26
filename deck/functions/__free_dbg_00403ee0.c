/*
 * Decompiled function: __free_dbg
 * Entry Point: 00403ee0
 * Size: 1057 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    __free_dbg
   
   Library: Visual Studio 1998 Debug */

void __cdecl __free_dbg(void *ptr_1,int arg_2)

{
  code *char_ptr_1;
  int val_2;
  BOOL BVar3;
  int *ptr_1_00;
  
  if (((((uint8_t)DAT_00412e28 & 4) != 0) && (val_2 = __CrtCheckMemory(), val_2 == 0)) &&
     (val_2 = __CrtDbgReport(2,0x410460,0x3e1,0,"_CrtCheckMemory()"), val_2 == 1)) {
    char_ptr_1 = (code *)swi(3);
    (*char_ptr_1)();
    return;
  }
  if (ptr_1 != (void *)0x0) {
    val_2 = (*(code *)PTR_FUN_00413900)(3,ptr_1,0,arg_2,0,0,0);
    if (val_2 == 0) {
      val_2 = __CrtDbgReport(0,0,0,0,"%s");
      if (val_2 == 1) {
        char_ptr_1 = (code *)swi(3);
        (*char_ptr_1)();
        return;
      }
    }
    else {
      BVar3 = __CrtIsValidHeapPointer((int)ptr_1);
      if ((BVar3 == 0) &&
         (val_2 = __CrtDbgReport(2,0x410460,0x3f3,0,"_CrtIsValidHeapPointer(pUserData)"), val_2 == 1
         )) {
        char_ptr_1 = (code *)swi(3);
        (*char_ptr_1)();
        return;
      }
      ptr_1_00 = (int *)((int)ptr_1 + -0x20);
      if ((((*(uint32_t *)((int)ptr_1 + -0xc) & 0xffff) != 4) && (*(int *)((int)ptr_1 + -0xc) != 1)) &&
         (((*(uint32_t *)((int)ptr_1 + -0xc) & 0xffff) != 2 &&
          ((*(int *)((int)ptr_1 + -0xc) != 3 &&
           (val_2 = __CrtDbgReport(2,0x410460,0x3f9,0,"_BLOCK_TYPE_IS_VALID(pHead->nBlockUse)"),
           val_2 == 1)))))) {
        char_ptr_1 = (code *)swi(3);
        (*char_ptr_1)();
        return;
      }
      if (((uint8_t)DAT_00412e28 & 4) == 0) {
        val_2 = _CheckBytes((char *)((int)ptr_1 + -4),DAT_00412e34,4);
        if ((val_2 == 0) &&
           (val_2 = __CrtDbgReport(1,0,0,0,"DAMAGE: before %hs block (#%d) at 0x%08X.\n"),
           val_2 == 1)) {
          char_ptr_1 = (code *)swi(3);
          (*char_ptr_1)();
          return;
        }
        val_2 = _CheckBytes((char *)(*(int *)((int)ptr_1 + -0x10) + (int)ptr_1),DAT_00412e34,4);
        if ((val_2 == 0) &&
           (val_2 = __CrtDbgReport(1,0,0,0,"DAMAGE: after %hs block (#%d) at 0x%08X.\n"), val_2 == 1
           )) {
          char_ptr_1 = (code *)swi(3);
          (*char_ptr_1)();
          return;
        }
      }
      if (*(int *)((int)ptr_1 + -0xc) == 3) {
        if (((*(int *)((int)ptr_1 + -0x14) != -0x1234544) || (*(int *)((int)ptr_1 + -8) != 0)) &&
           (val_2 = __CrtDbgReport(2,0x410460,0x40e,0,
                                   "pHead->nLine == IGNORE_LINE && pHead->lRequest == IGNORE_REQ"),
           val_2 == 1)) {
          char_ptr_1 = (code *)swi(3);
          (*char_ptr_1)();
          return;
        }
        _memset(ptr_1_00,(uint32_t)DAT_00412e38,*(int *)((int)ptr_1 + -0x10) + 0x24);
        __free_base((uint8_t *)ptr_1_00);
      }
      else {
        if ((*(int *)((int)ptr_1 + -0xc) == 2) && (arg_2 == 1)) {
          arg_2 = 2;
        }
        if ((*(int *)((int)ptr_1 + -0xc) != arg_2) &&
           (val_2 = __CrtDbgReport(2,0x410460,0x41b,0,"pHead->nBlockUse == nBlockUse"), val_2 == 1))
        {
          char_ptr_1 = (code *)swi(3);
          (*char_ptr_1)();
          return;
        }
        DAT_00414338 = DAT_00414338 - *(int *)((int)ptr_1 + -0x10);
        if (((uint8_t)DAT_00412e28 & 2) == 0) {
          if (*ptr_1_00 == 0) {
            if ((ptr_1_00 != DAT_0041432c) &&
               (val_2 = __CrtDbgReport(2,0x410460,0x42a,0,"_pLastBlock == pHead"), val_2 == 1)) {
              char_ptr_1 = (code *)swi(3);
              (*char_ptr_1)();
              return;
            }
            DAT_0041432c = *(int **)((int)ptr_1 + -0x1c);
          }
          else {
            *(int32_t *)(*ptr_1_00 + 4) = *(int32_t *)((int)ptr_1 + -0x1c);
          }
          if (*(int *)((int)ptr_1 + -0x1c) == 0) {
            if ((ptr_1_00 != DAT_00414334) &&
               (val_2 = __CrtDbgReport(2,0x410460,0x434,0,"_pFirstBlock == pHead"), val_2 == 1)) {
              char_ptr_1 = (code *)swi(3);
              (*char_ptr_1)();
              return;
            }
            DAT_00414334 = (int *)*ptr_1_00;
          }
          else {
            **(int **)((int)ptr_1 + -0x1c) = *ptr_1_00;
          }
          _memset(ptr_1_00,(uint32_t)DAT_00412e38,*(int *)((int)ptr_1 + -0x10) + 0x24);
          __free_base((uint8_t *)ptr_1_00);
        }
        else {
          *(int32_t *)((int)ptr_1 + -0xc) = 0;
          _memset(ptr_1,(uint32_t)DAT_00412e38,*(size_t *)((int)ptr_1 + -0x10));
        }
      }
    }
  }
  return;
}


