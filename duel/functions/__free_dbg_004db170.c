/*
 * Decompiled function: __free_dbg
 * Entry Point: 004db170
 * Size: 1057 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __free_dbg
   
   Library: Visual Studio 1998 Debug */

void __free_dbg(void *arg1,int arg2)

{
  code *pcVar1;
  int iVar2;
  int *ptr_1;
  
  if (((((byte)DAT_00509470 & 4) != 0) && (iVar2 = __CrtCheckMemory(), iVar2 == 0)) &&
     (iVar2 = __CrtDbgReport(2,0x4f0430,0x3e1,0,"_CrtCheckMemory()"), iVar2 == 1)) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  if (arg1 != (void *)0x0) {
    iVar2 = (*(code *)PTR_Mem_AllocOrFree_004e1ae0_005099d8)(3,arg1,0,arg2,0,0,0);
    if (iVar2 == 0) {
      iVar2 = __CrtDbgReport(0,0,0,0,"%s");
      if (iVar2 == 1) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
    }
    else {
      iVar2 = __CrtIsValidHeapPointer((int)arg1);
      if ((iVar2 == 0) &&
         (iVar2 = __CrtDbgReport(2,0x4f0430,0x3f3,0,"_CrtIsValidHeapPointer(pUserData)"), iVar2 == 1
         )) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      ptr_1 = (int *)((int)arg1 + -0x20);
      if ((((*(uint *)((int)arg1 + -0xc) & 0xffff) != 4) && (*(int *)((int)arg1 + -0xc) != 1)) &&
         (((*(uint *)((int)arg1 + -0xc) & 0xffff) != 2 &&
          ((*(int *)((int)arg1 + -0xc) != 3 &&
           (iVar2 = __CrtDbgReport(2,0x4f0430,0x3f9,0,"_BLOCK_TYPE_IS_VALID(pHead->nBlockUse)"),
           iVar2 == 1)))))) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      if (((byte)DAT_00509470 & 4) == 0) {
        iVar2 = _CheckBytes((char *)((int)arg1 + -4),DAT_0050947c,4);
        if ((iVar2 == 0) &&
           (iVar2 = __CrtDbgReport(1,0,0,0,"DAMAGE: before %hs block (#%d) at 0x%08X.\n"),
           iVar2 == 1)) {
          pcVar1 = (code *)swi(3);
          (*pcVar1)();
          return;
        }
        iVar2 = _CheckBytes((char *)(*(int *)((int)arg1 + -0x10) + (int)arg1),DAT_0050947c,4);
        if ((iVar2 == 0) &&
           (iVar2 = __CrtDbgReport(1,0,0,0,"DAMAGE: after %hs block (#%d) at 0x%08X.\n"), iVar2 == 1
           )) {
          pcVar1 = (code *)swi(3);
          (*pcVar1)();
          return;
        }
      }
      if (*(int *)((int)arg1 + -0xc) == 3) {
        if (((*(int *)((int)arg1 + -0x14) != -0x1234544) || (*(int *)((int)arg1 + -8) != 0)) &&
           (iVar2 = __CrtDbgReport(2,0x4f0430,0x40e,0,
                                   "pHead->nLine == IGNORE_LINE && pHead->lRequest == IGNORE_REQ"),
           iVar2 == 1)) {
          pcVar1 = (code *)swi(3);
          (*pcVar1)();
          return;
        }
        _memset(ptr_1,(uint)DAT_00509480,*(int *)((int)arg1 + -0x10) + 0x24);
        __free_base(ptr_1);
      }
      else {
        if ((*(int *)((int)arg1 + -0xc) == 2) && (arg2 == 1)) {
          arg2 = 2;
        }
        if ((*(int *)((int)arg1 + -0xc) != arg2) &&
           (iVar2 = __CrtDbgReport(2,0x4f0430,0x41b,0,"pHead->nBlockUse == nBlockUse"), iVar2 == 1))
        {
          pcVar1 = (code *)swi(3);
          (*pcVar1)();
          return;
        }
        DAT_005edacc = DAT_005edacc - *(int *)((int)arg1 + -0x10);
        if (((byte)DAT_00509470 & 2) == 0) {
          if (*ptr_1 == 0) {
            if ((ptr_1 != DAT_005edac0) &&
               (iVar2 = __CrtDbgReport(2,0x4f0430,0x42a,0,"_pLastBlock == pHead"), iVar2 == 1)) {
              pcVar1 = (code *)swi(3);
              (*pcVar1)();
              return;
            }
            DAT_005edac0 = *(int **)((int)arg1 + -0x1c);
          }
          else {
            *(undefined4 *)(*ptr_1 + 4) = *(undefined4 *)((int)arg1 + -0x1c);
          }
          if (*(int *)((int)arg1 + -0x1c) == 0) {
            if ((ptr_1 != DAT_005edac8) &&
               (iVar2 = __CrtDbgReport(2,0x4f0430,0x434,0,"_pFirstBlock == pHead"), iVar2 == 1)) {
              pcVar1 = (code *)swi(3);
              (*pcVar1)();
              return;
            }
            DAT_005edac8 = (int *)*ptr_1;
          }
          else {
            **(int **)((int)arg1 + -0x1c) = *ptr_1;
          }
          _memset(ptr_1,(uint)DAT_00509480,*(int *)((int)arg1 + -0x10) + 0x24);
          __free_base(ptr_1);
        }
        else {
          *(undefined4 *)((int)arg1 + -0xc) = 0;
          _memset(arg1,(uint)DAT_00509480,*(size_t *)((int)arg1 + -0x10));
        }
      }
    }
  }
  return;
}


