/*
 * Decompiled function: realloc_help
 * Entry Point: 004dab50
 * Size: 1409 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _realloc_help
   
   Library: Visual Studio 1998 Debug */

int * __cdecl realloc_help(int arg_1,uint arg_2,uint arg_3,int arg_4,int arg_5,int arg_6)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  bool bVar6;
  int *local_10;
  
  if (arg_1 == 0) {
    piVar2 = (int *)__malloc_dbg(arg_2,arg_3,arg_4,arg_5);
  }
  else if ((arg_6 == 0) || (arg_2 != 0)) {
    if ((((byte)DAT_00509470 & 4) != 0) &&
       ((iVar3 = __CrtCheckMemory(), iVar3 == 0 &&
        (iVar3 = __CrtDbgReport(2,0x4f0430,0x239,0,"_CrtCheckMemory()"), iVar3 == 1)))) {
      pcVar1 = (code *)swi(3);
      piVar4 = (int *)(*pcVar1)();
      return piVar4;
    }
    iVar3 = DAT_00509474;
    if (DAT_00509474 == DAT_00509478) {
      pcVar1 = (code *)swi(3);
      piVar4 = (int *)(*pcVar1)();
      return piVar4;
    }
    iVar5 = (*(code *)PTR_Mem_AllocOrFree_004e1ae0_005099d8)
                      (2,arg_1,arg_2,arg_3,DAT_00509474,arg_4,arg_5);
    if (iVar5 == 0) {
      if (arg_4 == 0) {
        iVar3 = __CrtDbgReport(0,0,0,0,"%s");
        if (iVar3 == 1) {
          pcVar1 = (code *)swi(3);
          piVar4 = (int *)(*pcVar1)();
          return piVar4;
        }
      }
      else {
        iVar3 = __CrtDbgReport(0,0,0,0,"Client hook re-allocation failure at file %hs line %d.\n");
        if (iVar3 == 1) {
          pcVar1 = (code *)swi(3);
          piVar4 = (int *)(*pcVar1)();
          return piVar4;
        }
      }
      piVar2 = (int *)0x0;
    }
    else if (arg_2 < 0xffffffdc) {
      if ((((arg_3 != 1) && ((arg_3 & 0xffff) != 4)) && ((arg_3 & 0xffff) != 2)) &&
         (iVar5 = __CrtDbgReport(1,0,0,0,"%s"), iVar5 == 1)) {
        pcVar1 = (code *)swi(3);
        piVar4 = (int *)(*pcVar1)();
        return piVar4;
      }
      iVar5 = __CrtIsValidHeapPointer(arg_1);
      if ((iVar5 == 0) &&
         (iVar5 = __CrtDbgReport(2,0x4f0430,0x261,0,"_CrtIsValidHeapPointer(pUserData)"), iVar5 == 1
         )) {
        pcVar1 = (code *)swi(3);
        piVar4 = (int *)(*pcVar1)();
        return piVar4;
      }
      piVar4 = (int *)(arg_1 + -0x20);
      bVar6 = *(int *)(arg_1 + -0xc) == 3;
      if (bVar6) {
        if (((*(int *)(arg_1 + -0x14) != -0x1234544) || (*(int *)(arg_1 + -8) != 0)) &&
           (iVar5 = __CrtDbgReport(2,0x4f0430,0x26b,0,
                                   "pOldBlock->nLine == IGNORE_LINE && pOldBlock->lRequest == IGNORE_REQ"
                                  ), iVar5 == 1)) {
          pcVar1 = (code *)swi(3);
          piVar4 = (int *)(*pcVar1)();
          return piVar4;
        }
      }
      else {
        if (((*(uint *)(arg_1 + -0xc) & 0xffff) == 2) && ((arg_3 & 0xffff) == 1)) {
          arg_3 = 2;
        }
        if ((((*(uint *)(arg_1 + -0xc) ^ arg_3 & 0xffff) & 0xffff) != 0) &&
           (iVar5 = __CrtDbgReport(2,0x4f0430,0x272,0,
                                   "_BLOCK_TYPE(pOldBlock->nBlockUse)==_BLOCK_TYPE(nBlockUse)"),
           iVar5 == 1)) {
          pcVar1 = (code *)swi(3);
          piVar4 = (int *)(*pcVar1)();
          return piVar4;
        }
      }
      if (arg_6 == 0) {
        local_10 = (int *)__expand_base(piVar4,arg_2 + 0x24);
        if (local_10 == (int *)0x0) {
          return (int *)0x0;
        }
      }
      else {
        local_10 = (int *)__realloc_base(piVar4,arg_2 + 0x24);
        if (local_10 == (int *)0x0) {
          return (int *)0x0;
        }
      }
      DAT_00509474 = DAT_00509474 + 1;
      if (!bVar6) {
        DAT_005edac4 = DAT_005edac4 - local_10[4];
        DAT_005edac4 = DAT_005edac4 + arg_2;
        DAT_005edacc = DAT_005edacc - local_10[4];
        DAT_005edacc = DAT_005edacc + arg_2;
        if (DAT_005edad0 < DAT_005edacc) {
          DAT_005edad0 = DAT_005edacc;
        }
      }
      piVar2 = local_10 + 8;
      if ((uint)local_10[4] < arg_2) {
        _memset((void *)(local_10[4] + (int)piVar2),(uint)DAT_00509484,arg_2 - local_10[4]);
      }
      _memset((void *)(arg_2 + (int)piVar2),(uint)DAT_0050947c,4);
      if (!bVar6) {
        local_10[2] = arg_4;
        local_10[3] = arg_5;
        local_10[6] = iVar3;
      }
      local_10[4] = arg_2;
      if (((arg_6 == 0) && (local_10 != piVar4)) &&
         (iVar3 = __CrtDbgReport(2,0x4f0430,0x2a8,0,
                                 "fRealloc || (!fRealloc && pNewBlock == pOldBlock)"), iVar3 == 1))
      {
        pcVar1 = (code *)swi(3);
        piVar4 = (int *)(*pcVar1)();
        return piVar4;
      }
      if ((local_10 != piVar4) && (!bVar6)) {
        if (*local_10 == 0) {
          if ((DAT_005edac0 != piVar4) &&
             (iVar3 = __CrtDbgReport(2,0x4f0430,0x2b7,0,"_pLastBlock == pOldBlock"), iVar3 == 1)) {
            pcVar1 = (code *)swi(3);
            piVar4 = (int *)(*pcVar1)();
            return piVar4;
          }
          DAT_005edac0 = (int *)local_10[1];
        }
        else {
          *(int *)(*local_10 + 4) = local_10[1];
        }
        if (local_10[1] == 0) {
          if ((DAT_005edac8 != piVar4) &&
             (iVar3 = __CrtDbgReport(2,0x4f0430,0x2c2,0,"_pFirstBlock == pOldBlock"), iVar3 == 1)) {
            pcVar1 = (code *)swi(3);
            piVar4 = (int *)(*pcVar1)();
            return piVar4;
          }
          DAT_005edac8 = (int *)*local_10;
        }
        else {
          *(int *)local_10[1] = *local_10;
        }
        if (DAT_005edac8 == (int *)0x0) {
          DAT_005edac0 = local_10;
        }
        else {
          DAT_005edac8[1] = (int)local_10;
        }
        *local_10 = (int)DAT_005edac8;
        local_10[1] = 0;
        DAT_005edac8 = local_10;
      }
    }
    else {
      iVar3 = __CrtDbgReport(1,0,0,0,"Allocation too large or negative: %u bytes.\n");
      if (iVar3 == 1) {
        pcVar1 = (code *)swi(3);
        piVar4 = (int *)(*pcVar1)();
        return piVar4;
      }
      piVar2 = (int *)0x0;
    }
  }
  else {
    __free_dbg((void *)arg_1,arg_3);
    piVar2 = (int *)0x0;
  }
  return piVar2;
}


