/*
 * Decompiled function: realloc_help
 * Entry Point: 004038c0
 * Size: 1409 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    _realloc_help
   
   Library: Visual Studio 1998 Debug */

int * __cdecl realloc_help(void *ptr_1,uint32_t arg_2,uint32_t arg_3,int arg_4,int arg_5,int arg_6)

{
  code *char_ptr_1;
  int *i_ptr_2;
  int val_3;
  int *piVar4;
  int val_5;
  BOOL BVar6;
  bool bVar7;
  int *local_10;
  
  if (ptr_1 == (void *)0x0) {
    i_ptr_2 = (int *)__malloc_dbg(arg_2,arg_3,arg_4,arg_5);
  }
  else if ((arg_6 == 0) || (arg_2 != 0)) {
    if ((((uint8_t)DAT_00412e28 & 4) != 0) &&
       ((val_3 = __CrtCheckMemory(), val_3 == 0 &&
        (val_3 = __CrtDbgReport(2,0x410460,0x239,0,"_CrtCheckMemory()"), val_3 == 1)))) {
      char_ptr_1 = (code *)swi(3);
      piVar4 = (int *)(*char_ptr_1)();
      return piVar4;
    }
    val_3 = DAT_00412e2c;
    if (DAT_00412e2c == DAT_00412e30) {
      char_ptr_1 = (code *)swi(3);
      piVar4 = (int *)(*char_ptr_1)();
      return piVar4;
    }
    val_5 = (*(code *)PTR_FUN_00413900)(2,ptr_1,arg_2,arg_3,DAT_00412e2c,arg_4,arg_5);
    if (val_5 == 0) {
      if (arg_4 == 0) {
        val_3 = __CrtDbgReport(0,0,0,0,"%s");
        if (val_3 == 1) {
          char_ptr_1 = (code *)swi(3);
          piVar4 = (int *)(*char_ptr_1)();
          return piVar4;
        }
      }
      else {
        val_3 = __CrtDbgReport(0,0,0,0,"Client hook re-allocation failure at file %hs line %d.\n");
        if (val_3 == 1) {
          char_ptr_1 = (code *)swi(3);
          piVar4 = (int *)(*char_ptr_1)();
          return piVar4;
        }
      }
      i_ptr_2 = (int *)0x0;
    }
    else if (arg_2 < 0xffffffdc) {
      if ((((arg_3 != 1) && ((arg_3 & 0xffff) != 4)) && ((arg_3 & 0xffff) != 2)) &&
         (val_5 = __CrtDbgReport(1,0,0,0,"%s"), val_5 == 1)) {
        char_ptr_1 = (code *)swi(3);
        piVar4 = (int *)(*char_ptr_1)();
        return piVar4;
      }
      BVar6 = __CrtIsValidHeapPointer((int)ptr_1);
      if ((BVar6 == 0) &&
         (val_5 = __CrtDbgReport(2,0x410460,0x261,0,"_CrtIsValidHeapPointer(pUserData)"), val_5 == 1
         )) {
        char_ptr_1 = (code *)swi(3);
        piVar4 = (int *)(*char_ptr_1)();
        return piVar4;
      }
      piVar4 = (int *)((int)ptr_1 + -0x20);
      bVar7 = *(int *)((int)ptr_1 + -0xc) == 3;
      if (bVar7) {
        if (((*(int *)((int)ptr_1 + -0x14) != -0x1234544) || (*(int *)((int)ptr_1 + -8) != 0)) &&
           (val_5 = __CrtDbgReport(2,0x410460,0x26b,0,
                                   "pOldBlock->nLine == IGNORE_LINE && pOldBlock->lRequest == IGNORE_REQ"
                                  ), val_5 == 1)) {
          char_ptr_1 = (code *)swi(3);
          piVar4 = (int *)(*char_ptr_1)();
          return piVar4;
        }
      }
      else {
        if (((*(uint32_t *)((int)ptr_1 + -0xc) & 0xffff) == 2) && ((arg_3 & 0xffff) == 1)) {
          arg_3 = 2;
        }
        if ((((*(uint32_t *)((int)ptr_1 + -0xc) ^ arg_3 & 0xffff) & 0xffff) != 0) &&
           (val_5 = __CrtDbgReport(2,0x410460,0x272,0,
                                   "_BLOCK_TYPE(pOldBlock->nBlockUse)==_BLOCK_TYPE(nBlockUse)"),
           val_5 == 1)) {
          char_ptr_1 = (code *)swi(3);
          piVar4 = (int *)(*char_ptr_1)();
          return piVar4;
        }
      }
      if (arg_6 == 0) {
        local_10 = (int *)__expand_base((uint8_t *)piVar4,arg_2 + 0x24);
        if (local_10 == (int *)0x0) {
          return (int *)0x0;
        }
      }
      else {
        local_10 = (int *)__realloc_base((uint8_t *)piVar4,arg_2 + 0x24);
        if (local_10 == (int *)0x0) {
          return (int *)0x0;
        }
      }
      DAT_00412e2c = DAT_00412e2c + 1;
      if (!bVar7) {
        DAT_00414330 = DAT_00414330 - local_10[4];
        DAT_00414330 = DAT_00414330 + arg_2;
        DAT_00414338 = DAT_00414338 - local_10[4];
        DAT_00414338 = DAT_00414338 + arg_2;
        if (DAT_0041433c < DAT_00414338) {
          DAT_0041433c = DAT_00414338;
        }
      }
      i_ptr_2 = local_10 + 8;
      if ((uint32_t)local_10[4] < arg_2) {
        _memset((void *)(local_10[4] + (int)i_ptr_2),(uint32_t)DAT_00412e3c,arg_2 - local_10[4]);
      }
      _memset((void *)(arg_2 + (int)i_ptr_2),(uint32_t)DAT_00412e34,4);
      if (!bVar7) {
        local_10[2] = arg_4;
        local_10[3] = arg_5;
        local_10[6] = val_3;
      }
      local_10[4] = arg_2;
      if (((arg_6 == 0) && (local_10 != piVar4)) &&
         (val_3 = __CrtDbgReport(2,0x410460,0x2a8,0,
                                 "fRealloc || (!fRealloc && pNewBlock == pOldBlock)"), val_3 == 1))
      {
        char_ptr_1 = (code *)swi(3);
        piVar4 = (int *)(*char_ptr_1)();
        return piVar4;
      }
      if ((local_10 != piVar4) && (!bVar7)) {
        if (*local_10 == 0) {
          if ((DAT_0041432c != piVar4) &&
             (val_3 = __CrtDbgReport(2,0x410460,0x2b7,0,"_pLastBlock == pOldBlock"), val_3 == 1)) {
            char_ptr_1 = (code *)swi(3);
            piVar4 = (int *)(*char_ptr_1)();
            return piVar4;
          }
          DAT_0041432c = (int *)local_10[1];
        }
        else {
          *(int *)(*local_10 + 4) = local_10[1];
        }
        if (local_10[1] == 0) {
          if ((DAT_00414334 != piVar4) &&
             (val_3 = __CrtDbgReport(2,0x410460,0x2c2,0,"_pFirstBlock == pOldBlock"), val_3 == 1)) {
            char_ptr_1 = (code *)swi(3);
            piVar4 = (int *)(*char_ptr_1)();
            return piVar4;
          }
          DAT_00414334 = (int *)*local_10;
        }
        else {
          *(int *)local_10[1] = *local_10;
        }
        if (DAT_00414334 == (int *)0x0) {
          DAT_0041432c = local_10;
        }
        else {
          DAT_00414334[1] = (int)local_10;
        }
        *local_10 = (int)DAT_00414334;
        local_10[1] = 0;
        DAT_00414334 = local_10;
      }
    }
    else {
      val_3 = __CrtDbgReport(1,0,0,0,"Allocation too large or negative: %u bytes.\n");
      if (val_3 == 1) {
        char_ptr_1 = (code *)swi(3);
        piVar4 = (int *)(*char_ptr_1)();
        return piVar4;
      }
      i_ptr_2 = (int *)0x0;
    }
  }
  else {
    __free_dbg(ptr_1,arg_3);
    i_ptr_2 = (int *)0x0;
  }
  return i_ptr_2;
}


