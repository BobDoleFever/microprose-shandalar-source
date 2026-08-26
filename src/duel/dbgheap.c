/*
 * dbgheap.c - Reconstructed MicroProse Source Module
 * Program: DUEL.EXE
 * Contained Functions: 29
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "shandalar/shandalar.h"
/* Modular Shandalar Subsystem */

/*
 * Decompiled function: __heap_alloc_dbg
 * Entry Point: 004da700
 * Size: 818 bytes
 */


/* Library Function - Single Match
    __heap_alloc_dbg
   
   Library: Visual Studio 1998 Debug */

int32_t * __heap_alloc_dbg(uint32_t x,uint32_t y,int width,int32_t arg_4)

{
  code *char_ptr_1;
  bool flag_2;
  int32_t *u_ptr_3;
  int val_4;
  int32_t *puVar5;
  int val_6;
  
  flag_2 = false;
  if (((((uint8_t)DAT_00509470 & 4) != 0) && (val_4 = __CrtCheckMemory(), val_4 == 0)) &&
     (val_4 = __CrtDbgReport(2,0x4f0430,0x141,0,"_CrtCheckMemory()"), val_4 == 1)) {
    char_ptr_1 = (code *)swi(3);
    puVar5 = (int32_t *)(*char_ptr_1)();
    return puVar5;
  }
  val_4 = DAT_00509474;
  if (DAT_00509474 == DAT_00509478) {
    char_ptr_1 = (code *)swi(3);
    puVar5 = (int32_t *)(*char_ptr_1)();
    return puVar5;
  }
  val_6 = (*(code *)PTR_Mem_AllocOrFree_004e1ae0_005099d8)(1,0,x,y,DAT_00509474,width,arg_4);
  if (val_6 == 0) {
    if (width == 0) {
      val_4 = __CrtDbgReport(0,0,0,0,"%s");
      if (val_4 == 1) {
        char_ptr_1 = (code *)swi(3);
        puVar5 = (int32_t *)(*char_ptr_1)();
        return puVar5;
      }
    }
    else {
      val_4 = __CrtDbgReport(0,0,0,0,"Client hook allocation failure at file %hs line %d.\n");
      if (val_4 == 1) {
        char_ptr_1 = (code *)swi(3);
        puVar5 = (int32_t *)(*char_ptr_1)();
        return puVar5;
      }
    }
    puVar5 = (int32_t *)0x0;
  }
  else {
    if (((y & 0xffff) != 2) && (((uint8_t)DAT_00509470 & 1) == 0)) {
      flag_2 = true;
    }
    if ((x < 0xffffffe1) && (x + 0x24 < 0xffffffe1)) {
      if (((((y & 0xffff) != 4) && (y != 1)) && ((y & 0xffff) != 2)) &&
         ((y != 3 && (val_6 = __CrtDbgReport(1,0,0,0,"%s"), val_6 == 1)))) {
        char_ptr_1 = (code *)swi(3);
        puVar5 = (int32_t *)(*char_ptr_1)();
        return puVar5;
      }
      puVar5 = (int32_t *)__heap_alloc_base(x + 0x24);
      if (puVar5 == (int32_t *)0x0) {
        puVar5 = (int32_t *)0x0;
      }
      else {
        DAT_00509474 = DAT_00509474 + 1;
        if (flag_2) {
          *puVar5 = 0;
          puVar5[1] = 0;
          puVar5[2] = 0;
          puVar5[3] = 0xfedcbabc;
          puVar5[4] = x;
          puVar5[5] = 3;
          puVar5[6] = 0;
        }
        else {
          DAT_005edac4 = DAT_005edac4 + x;
          DAT_005edacc = DAT_005edacc + x;
          if (DAT_005edad0 < DAT_005edacc) {
            DAT_005edad0 = DAT_005edacc;
          }
          u_ptr_3 = puVar5;
          if (DAT_005edac8 != (int32_t *)0x0) {
            DAT_005edac8[1] = puVar5;
            u_ptr_3 = DAT_005edac0;
          }
          DAT_005edac0 = u_ptr_3;
          *puVar5 = DAT_005edac8;
          puVar5[1] = 0;
          puVar5[2] = width;
          puVar5[3] = arg_4;
          puVar5[4] = x;
          puVar5[5] = y;
          puVar5[6] = val_4;
          DAT_005edac8 = puVar5;
        }
        _memset(puVar5 + 7,(uint32_t)DAT_0050947c,4);
        _memset((void *)((int)puVar5 + x + 0x20),(uint32_t)DAT_0050947c,4);
        _memset(puVar5 + 8,(uint32_t)DAT_00509484,x);
        puVar5 = puVar5 + 8;
      }
    }
    else {
      val_4 = __CrtDbgReport(1,0,0,0,"Invalid allocation size: %u bytes.\n");
      if (val_4 == 1) {
        char_ptr_1 = (code *)swi(3);
        puVar5 = (int32_t *)(*char_ptr_1)();
        return puVar5;
      }
      puVar5 = (int32_t *)0x0;
    }
  }
  return puVar5;
}



/*
 * Decompiled function: _calloc
 * Entry Point: 004daa40
 * Size: 38 bytes
 */


/* Library Function - Single Match
    _calloc
   
   Library: Visual Studio 1998 Debug */

void * __cdecl _calloc(size_t arg_1,size_t arg_2)

{
  void *buf_ptr_1;
  
  buf_ptr_1 = (void *)__calloc_dbg(arg_1,arg_2,1,0,0);
  return buf_ptr_1;
}



/*
 * Decompiled function: __calloc_dbg
 * Entry Point: 004daa70
 * Size: 110 bytes
 */


/* Library Function - Single Match
    __calloc_dbg
   
   Library: Visual Studio 1998 Debug */

uint8_t * __calloc_dbg(int player_id,int card_slot,int32_t arg_3,int32_t arg_4,int32_t arg_5)

{
  uint8_t *u_ptr_1;
  uint8_t *card_idx;
  
  u_ptr_1 = (uint8_t *)__malloc_dbg(arg_2 * arg_1,arg_3,arg_4,arg_5);
  if (u_ptr_1 != (uint8_t *)0x0) {
    for (card_idx = u_ptr_1; card_idx < u_ptr_1 + arg_2 * arg_1; card_idx = card_idx + 1) {
      *card_idx = 0;
    }
  }
  return u_ptr_1;
}



/*
 * Decompiled function: FID_conflict:__expand
 * Entry Point: 004daae0
 * Size: 38 bytes
 */


/* Library Function - Multiple Matches With Different Base Names
    __expand
    _realloc
   
   Library: Visual Studio 1998 Debug */

void * __cdecl FID_conflict___expand(void *ptr_1,size_t arg_2)

{
  void *buf_ptr_1;
  
  buf_ptr_1 = (void *)__realloc_dbg(ptr_1,arg_2,1,0,0);
  return buf_ptr_1;
}



/*
 * Decompiled function: __realloc_dbg
 * Entry Point: 004dab10
 * Size: 55 bytes
 */


/* Library Function - Single Match
    __realloc_dbg
   
   Library: Visual Studio 1998 Debug */

int32_t __realloc_dbg(int player_id,uint32_t arg_2,uint32_t arg_3,int arg_4,int arg_5)

{
  int32_t uval_1;
  
  uval_1 = realloc_help(arg_1,arg_2,arg_3,arg_4,arg_5,1);
  return uval_1;
}



/*
 * Decompiled function: realloc_help
 * Entry Point: 004dab50
 * Size: 1409 bytes
 */


/* Library Function - Single Match
    _realloc_help
   
   Library: Visual Studio 1998 Debug */

int * __cdecl realloc_help(int player_id,uint32_t arg_2,uint32_t arg_3,int arg_4,int arg_5,int arg_6)

{
  code *char_ptr_1;
  int *i_ptr_2;
  int val_3;
  int *piVar4;
  int val_5;
  bool bVar6;
  int *card_idx;
  
  if (arg_1 == 0) {
    i_ptr_2 = (int *)__malloc_dbg(arg_2,arg_3,arg_4,arg_5);
  }
  else if ((arg_6 == 0) || (arg_2 != 0)) {
    if ((((uint8_t)DAT_00509470 & 4) != 0) &&
       ((val_3 = __CrtCheckMemory(), val_3 == 0 &&
        (val_3 = __CrtDbgReport(2,0x4f0430,0x239,0,"_CrtCheckMemory()"), val_3 == 1)))) {
      char_ptr_1 = (code *)swi(3);
      piVar4 = (int *)(*char_ptr_1)();
      return piVar4;
    }
    val_3 = DAT_00509474;
    if (DAT_00509474 == DAT_00509478) {
      char_ptr_1 = (code *)swi(3);
      piVar4 = (int *)(*char_ptr_1)();
      return piVar4;
    }
    val_5 = (*(code *)PTR_Mem_AllocOrFree_004e1ae0_005099d8)
                      (2,arg_1,arg_2,arg_3,DAT_00509474,arg_4,arg_5);
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
      val_5 = __CrtIsValidHeapPointer(arg_1);
      if ((val_5 == 0) &&
         (val_5 = __CrtDbgReport(2,0x4f0430,0x261,0,"_CrtIsValidHeapPointer(pUserData)"), val_5 == 1
         )) {
        char_ptr_1 = (code *)swi(3);
        piVar4 = (int *)(*char_ptr_1)();
        return piVar4;
      }
      piVar4 = (int *)(arg_1 + -0x20);
      bVar6 = *(int *)(arg_1 + -0xc) == 3;
      if (bVar6) {
        if (((*(int *)(arg_1 + -0x14) != -0x1234544) || (*(int *)(arg_1 + -8) != 0)) &&
           (val_5 = __CrtDbgReport(2,0x4f0430,0x26b,0,
                                   "pOldBlock->nLine == IGNORE_LINE && pOldBlock->lRequest == IGNORE_REQ"
                                  ), val_5 == 1)) {
          char_ptr_1 = (code *)swi(3);
          piVar4 = (int *)(*char_ptr_1)();
          return piVar4;
        }
      }
      else {
        if (((*(uint32_t *)(arg_1 + -0xc) & 0xffff) == 2) && ((arg_3 & 0xffff) == 1)) {
          arg_3 = 2;
        }
        if ((((*(uint32_t *)(arg_1 + -0xc) ^ arg_3 & 0xffff) & 0xffff) != 0) &&
           (val_5 = __CrtDbgReport(2,0x4f0430,0x272,0,
                                   "_BLOCK_TYPE(pOldBlock->nBlockUse)==_BLOCK_TYPE(nBlockUse)"),
           val_5 == 1)) {
          char_ptr_1 = (code *)swi(3);
          piVar4 = (int *)(*char_ptr_1)();
          return piVar4;
        }
      }
      if (arg_6 == 0) {
        card_idx = (int *)__expand_base(piVar4,arg_2 + 0x24);
        if (card_idx == (int *)0x0) {
          return (int *)0x0;
        }
      }
      else {
        card_idx = (int *)__realloc_base(piVar4,arg_2 + 0x24);
        if (card_idx == (int *)0x0) {
          return (int *)0x0;
        }
      }
      DAT_00509474 = DAT_00509474 + 1;
      if (!bVar6) {
        DAT_005edac4 = DAT_005edac4 - card_idx[4];
        DAT_005edac4 = DAT_005edac4 + arg_2;
        DAT_005edacc = DAT_005edacc - card_idx[4];
        DAT_005edacc = DAT_005edacc + arg_2;
        if (DAT_005edad0 < DAT_005edacc) {
          DAT_005edad0 = DAT_005edacc;
        }
      }
      i_ptr_2 = card_idx + 8;
      if ((uint32_t)card_idx[4] < arg_2) {
        _memset((void *)(card_idx[4] + (int)i_ptr_2),(uint32_t)DAT_00509484,arg_2 - card_idx[4]);
      }
      _memset((void *)(arg_2 + (int)i_ptr_2),(uint32_t)DAT_0050947c,4);
      if (!bVar6) {
        card_idx[2] = arg_4;
        card_idx[3] = arg_5;
        card_idx[6] = val_3;
      }
      card_idx[4] = arg_2;
      if (((arg_6 == 0) && (card_idx != piVar4)) &&
         (val_3 = __CrtDbgReport(2,0x4f0430,0x2a8,0,
                                 "fRealloc || (!fRealloc && pNewBlock == pOldBlock)"), val_3 == 1))
      {
        char_ptr_1 = (code *)swi(3);
        piVar4 = (int *)(*char_ptr_1)();
        return piVar4;
      }
      if ((card_idx != piVar4) && (!bVar6)) {
        if (*card_idx == 0) {
          if ((DAT_005edac0 != piVar4) &&
             (val_3 = __CrtDbgReport(2,0x4f0430,0x2b7,0,"_pLastBlock == pOldBlock"), val_3 == 1)) {
            char_ptr_1 = (code *)swi(3);
            piVar4 = (int *)(*char_ptr_1)();
            return piVar4;
          }
          DAT_005edac0 = (int *)card_idx[1];
        }
        else {
          *(int *)(*card_idx + 4) = card_idx[1];
        }
        if (card_idx[1] == 0) {
          if ((DAT_005edac8 != piVar4) &&
             (val_3 = __CrtDbgReport(2,0x4f0430,0x2c2,0,"_pFirstBlock == pOldBlock"), val_3 == 1)) {
            char_ptr_1 = (code *)swi(3);
            piVar4 = (int *)(*char_ptr_1)();
            return piVar4;
          }
          DAT_005edac8 = (int *)*card_idx;
        }
        else {
          *(int *)card_idx[1] = *card_idx;
        }
        if (DAT_005edac8 == (int *)0x0) {
          DAT_005edac0 = card_idx;
        }
        else {
          DAT_005edac8[1] = (int)card_idx;
        }
        *card_idx = (int)DAT_005edac8;
        card_idx[1] = 0;
        DAT_005edac8 = card_idx;
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
    __free_dbg((void *)arg_1,arg_3);
    i_ptr_2 = (int *)0x0;
  }
  return i_ptr_2;
}



/*
 * Decompiled function: FID_conflict:__expand
 * Entry Point: 004db0e0
 * Size: 38 bytes
 */


/* Library Function - Multiple Matches With Different Base Names
    __expand
    _realloc
   
   Library: Visual Studio 1998 Debug */

void * __cdecl FID_conflict___expand(void *ptr_1,size_t arg_2)

{
  void *buf_ptr_1;
  
  buf_ptr_1 = (void *)__expand_dbg((int)ptr_1,arg_2,1,0,0);
  return buf_ptr_1;
}



/*
 * Decompiled function: __expand_dbg
 * Entry Point: 004db110
 * Size: 55 bytes
 */


/* Library Function - Single Match
    __expand_dbg
   
   Library: Visual Studio 1998 Debug */

int32_t __expand_dbg(int player_id,uint32_t arg_2,uint32_t arg_3,int arg_4,int arg_5)

{
  int32_t uval_1;
  
  uval_1 = realloc_help(arg_1,arg_2,arg_3,arg_4,arg_5,0);
  return uval_1;
}



/*
 * Decompiled function: FUN_004db150
 * Entry Point: 004db150
 * Size: 25 bytes
 */


void FUN_004db150(void *arg_1)

{
  __free_dbg(arg_1,1);
  return;
}



/*
 * Decompiled function: __free_dbg
 * Entry Point: 004db170
 * Size: 1057 bytes
 */


/* Library Function - Single Match
    __free_dbg
   
   Library: Visual Studio 1998 Debug */

void __free_dbg(void *arg1,int arg2)

{
  code *char_ptr_1;
  int val_2;
  int *ptr_1;
  
  if (((((uint8_t)DAT_00509470 & 4) != 0) && (val_2 = __CrtCheckMemory(), val_2 == 0)) &&
     (val_2 = __CrtDbgReport(2,0x4f0430,0x3e1,0,"_CrtCheckMemory()"), val_2 == 1)) {
    char_ptr_1 = (code *)swi(3);
    (*char_ptr_1)();
    return;
  }
  if (arg1 != (void *)0x0) {
    val_2 = (*(code *)PTR_Mem_AllocOrFree_004e1ae0_005099d8)(3,arg1,0,arg2,0,0,0);
    if (val_2 == 0) {
      val_2 = __CrtDbgReport(0,0,0,0,"%s");
      if (val_2 == 1) {
        char_ptr_1 = (code *)swi(3);
        (*char_ptr_1)();
        return;
      }
    }
    else {
      val_2 = __CrtIsValidHeapPointer((int)arg1);
      if ((val_2 == 0) &&
         (val_2 = __CrtDbgReport(2,0x4f0430,0x3f3,0,"_CrtIsValidHeapPointer(pUserData)"), val_2 == 1
         )) {
        char_ptr_1 = (code *)swi(3);
        (*char_ptr_1)();
        return;
      }
      ptr_1 = (int *)((int)arg1 + -0x20);
      if ((((*(uint32_t *)((int)arg1 + -0xc) & 0xffff) != 4) && (*(int *)((int)arg1 + -0xc) != 1)) &&
         (((*(uint32_t *)((int)arg1 + -0xc) & 0xffff) != 2 &&
          ((*(int *)((int)arg1 + -0xc) != 3 &&
           (val_2 = __CrtDbgReport(2,0x4f0430,0x3f9,0,"_BLOCK_TYPE_IS_VALID(pHead->nBlockUse)"),
           val_2 == 1)))))) {
        char_ptr_1 = (code *)swi(3);
        (*char_ptr_1)();
        return;
      }
      if (((uint8_t)DAT_00509470 & 4) == 0) {
        val_2 = _CheckBytes((char *)((int)arg1 + -4),DAT_0050947c,4);
        if ((val_2 == 0) &&
           (val_2 = __CrtDbgReport(1,0,0,0,"DAMAGE: before %hs block (#%d) at 0x%08X.\n"),
           val_2 == 1)) {
          char_ptr_1 = (code *)swi(3);
          (*char_ptr_1)();
          return;
        }
        val_2 = _CheckBytes((char *)(*(int *)((int)arg1 + -0x10) + (int)arg1),DAT_0050947c,4);
        if ((val_2 == 0) &&
           (val_2 = __CrtDbgReport(1,0,0,0,"DAMAGE: after %hs block (#%d) at 0x%08X.\n"), val_2 == 1
           )) {
          char_ptr_1 = (code *)swi(3);
          (*char_ptr_1)();
          return;
        }
      }
      if (*(int *)((int)arg1 + -0xc) == 3) {
        if (((*(int *)((int)arg1 + -0x14) != -0x1234544) || (*(int *)((int)arg1 + -8) != 0)) &&
           (val_2 = __CrtDbgReport(2,0x4f0430,0x40e,0,
                                   "pHead->nLine == IGNORE_LINE && pHead->lRequest == IGNORE_REQ"),
           val_2 == 1)) {
          char_ptr_1 = (code *)swi(3);
          (*char_ptr_1)();
          return;
        }
        _memset(ptr_1,(uint32_t)DAT_00509480,*(int *)((int)arg1 + -0x10) + 0x24);
        __free_base(ptr_1);
      }
      else {
        if ((*(int *)((int)arg1 + -0xc) == 2) && (arg2 == 1)) {
          arg2 = 2;
        }
        if ((*(int *)((int)arg1 + -0xc) != arg2) &&
           (val_2 = __CrtDbgReport(2,0x4f0430,0x41b,0,"pHead->nBlockUse == nBlockUse"), val_2 == 1))
        {
          char_ptr_1 = (code *)swi(3);
          (*char_ptr_1)();
          return;
        }
        DAT_005edacc = DAT_005edacc - *(int *)((int)arg1 + -0x10);
        if (((uint8_t)DAT_00509470 & 2) == 0) {
          if (*ptr_1 == 0) {
            if ((ptr_1 != DAT_005edac0) &&
               (val_2 = __CrtDbgReport(2,0x4f0430,0x42a,0,"_pLastBlock == pHead"), val_2 == 1)) {
              char_ptr_1 = (code *)swi(3);
              (*char_ptr_1)();
              return;
            }
            DAT_005edac0 = *(int **)((int)arg1 + -0x1c);
          }
          else {
            *(int32_t *)(*ptr_1 + 4) = *(int32_t *)((int)arg1 + -0x1c);
          }
          if (*(int *)((int)arg1 + -0x1c) == 0) {
            if ((ptr_1 != DAT_005edac8) &&
               (val_2 = __CrtDbgReport(2,0x4f0430,0x434,0,"_pFirstBlock == pHead"), val_2 == 1)) {
              char_ptr_1 = (code *)swi(3);
              (*char_ptr_1)();
              return;
            }
            DAT_005edac8 = (int *)*ptr_1;
          }
          else {
            **(int **)((int)arg1 + -0x1c) = *ptr_1;
          }
          _memset(ptr_1,(uint32_t)DAT_00509480,*(int *)((int)arg1 + -0x10) + 0x24);
          __free_base(ptr_1);
        }
        else {
          *(int32_t *)((int)arg1 + -0xc) = 0;
          _memset(arg1,(uint32_t)DAT_00509480,*(size_t *)((int)arg1 + -0x10));
        }
      }
    }
  }
  return;
}



/*
 * Decompiled function: __msize
 * Entry Point: 004db5a0
 * Size: 30 bytes
 */


/* Library Function - Single Match
    __msize
   
   Library: Visual Studio 1998 Debug */

size_t __cdecl __msize(void *ptr_1)

{
  size_t len_1;
  
  len_1 = __msize_dbg((int)ptr_1,1);
  return len_1;
}



/*
 * Decompiled function: __msize_dbg
 * Entry Point: 004db5c0
 * Size: 358 bytes
 */


/* Library Function - Single Match
    __msize_dbg
   
   Library: Visual Studio 1998 Debug */

int32_t __msize_dbg(int arg1,int arg2)

{
  code *char_ptr_1;
  int val_2;
  int32_t uval_3;
  
  if (((uint8_t)DAT_00509470 & 4) != 0) {
    val_2 = __CrtCheckMemory();
    if (val_2 == 0) {
      val_2 = __CrtDbgReport(2,0x4f0430,0x47c,0,"_CrtCheckMemory()");
      if (val_2 == 1) {
        char_ptr_1 = (code *)swi(3);
        uval_3 = (*char_ptr_1)();
        return uval_3;
      }
    }
  }
  val_2 = __CrtIsValidHeapPointer(arg1);
  if (val_2 == 0) {
    val_2 = __CrtDbgReport(2,0x4f0430,0x485,0,"_CrtIsValidHeapPointer(pUserData)");
    if (val_2 == 1) {
      char_ptr_1 = (code *)swi(3);
      uval_3 = (*char_ptr_1)();
      return uval_3;
    }
  }
  if (((((*(uint32_t *)(arg1 + -0xc) & 0xffff) != 4) && (*(int *)(arg1 + -0xc) != 1)) &&
      ((*(uint32_t *)(arg1 + -0xc) & 0xffff) != 2)) && (*(int *)(arg1 + -0xc) != 3)) {
    val_2 = __CrtDbgReport(2,0x4f0430,0x48b,0,"_BLOCK_TYPE_IS_VALID(pHead->nBlockUse)");
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
    val_2 = __CrtDbgReport(2,0x4f0430,0x492,0,"pHead->nBlockUse == nBlockUse");
    if (val_2 == 1) {
      char_ptr_1 = (code *)swi(3);
      uval_3 = (*char_ptr_1)();
      return uval_3;
    }
  }
  return *(int32_t *)(arg1 + -0x10);
}



/*
 * Decompiled function: Mem_AllocOrFree_004db730
 * Entry Point: 004db730
 * Size: 38 bytes
 */


int32_t Mem_AllocOrFree_004db730(int32_t arg_1)

{
  int32_t uval_1;
  
  uval_1 = DAT_00509478;
  DAT_00509478 = arg_1;
  return uval_1;
}



/*
 * Decompiled function: __CrtSetDbgBlockType
 * Entry Point: 004db760
 * Size: 160 bytes
 */


/* Library Function - Single Match
    __CrtSetDbgBlockType
   
   Library: Visual Studio 1998 Debug */

void __CrtSetDbgBlockType(int arg1,int32_t arg2)

{
  code *char_ptr_1;
  int val_2;
  
  val_2 = __CrtIsValidHeapPointer(arg1);
  if (val_2 != 0) {
    if (((((*(uint32_t *)(arg1 + -0xc) & 0xffff) != 4) && (*(int *)(arg1 + -0xc) != 1)) &&
        ((*(uint32_t *)(arg1 + -0xc) & 0xffff) != 2)) && (*(int *)(arg1 + -0xc) != 3)) {
      val_2 = __CrtDbgReport(2,0x4f0430,0x4d3,0,"_BLOCK_TYPE_IS_VALID(pHead->nBlockUse)");
      if (val_2 == 1) {
        char_ptr_1 = (code *)swi(3);
        (*char_ptr_1)();
        return;
      }
    }
    *(int32_t *)(arg1 + -0xc) = arg2;
  }
  return;
}



/*
 * Decompiled function: Mem_AllocOrFree_004db800
 * Entry Point: 004db800
 * Size: 38 bytes
 */


uint8_t * Mem_AllocOrFree_004db800(uint8_t *arg_1)

{
  uint8_t *u_ptr_1;
  
  u_ptr_1 = PTR_Mem_AllocOrFree_004e1ae0_005099d8;
  PTR_Mem_AllocOrFree_004e1ae0_005099d8 = arg_1;
  return u_ptr_1;
}



/*
 * Decompiled function: _CheckBytes
 * Entry Point: 004db830
 * Size: 140 bytes
 */


/* Library Function - Single Match
    _CheckBytes
   
   Library: Visual Studio 1998 Debug */

int32_t _CheckBytes(char *filepath,char arg_2,int event_type)

{
  char *char_ptr_1;
  char cVar2;
  code *char_ptr_3;
  int val_4;
  int32_t uval_5;
  int32_t slot_idx;
  
  slot_idx = 1;
  while( true ) {
    do {
      val_4 = arg_3 + -1;
      if (arg_3 == 0) {
        return slot_idx;
      }
      char_ptr_1 = str_1 + 1;
      cVar2 = *str_1;
      str_1 = char_ptr_1;
      arg_3 = val_4;
    } while (cVar2 == arg_2);
    val_4 = __CrtDbgReport(0,0,0,0,"memory check error at 0x%08X = 0x%02X, should be 0x%02X.\n");
    if (val_4 == 1) break;
    slot_idx = 0;
  }
  char_ptr_3 = (code *)swi(3);
  uval_5 = (*char_ptr_3)();
  return uval_5;
}



/*
 * Decompiled function: __CrtCheckMemory
 * Entry Point: 004db8c0
 * Size: 873 bytes
 */


/* Library Function - Single Match
    __CrtCheckMemory
   
   Library: Visual Studio 1998 Debug */

int32_t __CrtCheckMemory(void)

{
  code *char_ptr_1;
  bool flag_2;
  int val_3;
  int32_t uval_4;
  int32_t *match_count;
  int32_t slot_idx;
  
  slot_idx = 1;
  if (((uint8_t)DAT_00509470 & 1) == 0) {
    slot_idx = 1;
  }
  else {
    val_3 = __heapchk();
    if ((val_3 == -1) || (val_3 == -2)) {
      for (match_count = DAT_005edac8; match_count != (int32_t *)0x0; match_count = (int32_t *)*match_count) {
        flag_2 = true;
        val_3 = _CheckBytes((char *)(match_count + 7),DAT_0050947c,4);
        if (val_3 == 0) {
          val_3 = __CrtDbgReport(0,0,0,0,"DAMAGE: before %hs block (#%d) at 0x%08X.\n");
          if (val_3 == 1) {
            char_ptr_1 = (code *)swi(3);
            uval_4 = (*char_ptr_1)();
            return uval_4;
          }
          flag_2 = false;
        }
        val_3 = _CheckBytes((char *)((int)match_count + match_count[4] + 0x20),DAT_0050947c,4);
        if (val_3 == 0) {
          val_3 = __CrtDbgReport(0,0,0,0,"DAMAGE: after %hs block (#%d) at 0x%08X.\n");
          if (val_3 == 1) {
            char_ptr_1 = (code *)swi(3);
            uval_4 = (*char_ptr_1)();
            return uval_4;
          }
          flag_2 = false;
        }
        if ((match_count[5] == 0) &&
           (val_3 = _CheckBytes((char *)(match_count + 8),DAT_00509480,match_count[4]), val_3 == 0)) {
          val_3 = __CrtDbgReport(0,0,0,0,"DAMAGE: on top of Free block at 0x%08X.\n");
          if (val_3 == 1) {
            char_ptr_1 = (code *)swi(3);
            uval_4 = (*char_ptr_1)();
            return uval_4;
          }
          flag_2 = false;
        }
        if (!flag_2) {
          if ((match_count[2] != 0) &&
             (val_3 = __CrtDbgReport(0,0,0,0,"%hs allocated at file %hs(%d).\n"), val_3 == 1)) {
            char_ptr_1 = (code *)swi(3);
            uval_4 = (*char_ptr_1)();
            return uval_4;
          }
          val_3 = __CrtDbgReport(0,0,0,0,"%hs located at 0x%08X is %u bytes long.\n");
          if (val_3 == 1) {
            char_ptr_1 = (code *)swi(3);
            uval_4 = (*char_ptr_1)();
            return uval_4;
          }
          slot_idx = 0;
        }
      }
    }
    else {
      switch(val_3) {
      case -6:
        val_3 = __CrtDbgReport(0,0,0,0,"%s");
        if (val_3 == 1) {
          char_ptr_1 = (code *)swi(3);
          uval_4 = (*char_ptr_1)();
          return uval_4;
        }
        break;
      case -5:
        val_3 = __CrtDbgReport(0,0,0,0,"%s");
        if (val_3 == 1) {
          char_ptr_1 = (code *)swi(3);
          uval_4 = (*char_ptr_1)();
          return uval_4;
        }
        break;
      case -4:
        val_3 = __CrtDbgReport(0,0,0,0,"%s");
        if (val_3 == 1) {
          char_ptr_1 = (code *)swi(3);
          uval_4 = (*char_ptr_1)();
          return uval_4;
        }
        break;
      case -3:
        val_3 = __CrtDbgReport(0,0,0,0,"%s");
        if (val_3 == 1) {
          char_ptr_1 = (code *)swi(3);
          uval_4 = (*char_ptr_1)();
          return uval_4;
        }
        break;
      default:
        val_3 = __CrtDbgReport(0,0,0,0,"%s");
        if (val_3 == 1) {
          char_ptr_1 = (code *)swi(3);
          uval_4 = (*char_ptr_1)();
          return uval_4;
        }
      }
      slot_idx = 0;
    }
  }
  return slot_idx;
}



/*
 * Decompiled function: __CrtSetDbgFlag
 * Entry Point: 004dbc40
 * Size: 48 bytes
 */


/* Library Function - Single Match
    __CrtSetDbgFlag
   
   Library: Visual Studio 1998 Debug */

int __CrtSetDbgFlag(int player_id)

{
  int val_1;
  
  val_1 = DAT_00509470;
  if (arg_1 != -1) {
    DAT_00509470 = arg_1;
  }
  return val_1;
}



/*
 * Decompiled function: __CrtDoForAllClientObjects
 * Entry Point: 004dbc70
 * Size: 105 bytes
 */


/* Library Function - Single Match
    __CrtDoForAllClientObjects
   
   Library: Visual Studio 1998 Debug */

void __CrtDoForAllClientObjects(uint8_t *arg1,int32_t arg2)

{
  int32_t *slot_idx;
  
  if (((uint8_t)DAT_00509470 & 1) != 0) {
    for (slot_idx = DAT_005edac8; slot_idx != (int32_t *)0x0; slot_idx = (int32_t *)*slot_idx) {
      if ((slot_idx[5] & 0xffff) == 4) {
        (*(code *)arg1)(slot_idx + 8,arg2);
      }
    }
  }
  return;
}



/*
 * Decompiled function: __CrtIsValidPointer
 * Entry Point: 004dbce0
 * Size: 92 bytes
 */


/* Library Function - Single Match
    __CrtIsValidPointer
   
   Library: Visual Studio 1998 Debug */

int32_t __CrtIsValidPointer(void *arg_1,UINT_PTR arg_2,int event_type)

{
  BOOL BVar1;
  
  if (((arg_1 != (void *)0x0) && (BVar1 = IsBadReadPtr(arg_1,arg_2), BVar1 == 0)) &&
     ((arg_3 == 0 || (BVar1 = IsBadWritePtr(arg_1,arg_2), BVar1 == 0)))) {
    return 1;
  }
  return 0;
}



/*
 * Decompiled function: __CrtIsValidHeapPointer
 * Entry Point: 004dbd40
 * Size: 182 bytes
 */


/* Library Function - Single Match
    __CrtIsValidHeapPointer
   
   Library: Visual Studio 1998 Debug */

BOOL __CrtIsValidHeapPointer(int player_id)

{
  BOOL BVar1;
  int val_2;
  int32_t card_idx;
  char *match_count;
  uint32_t slot_idx;
  
  if (arg_1 == 0) {
    BVar1 = 0;
  }
  else {
    val_2 = __CrtIsValidPointer((void *)(arg_1 + -0x20),0x20,1);
    if (val_2 == 0) {
      BVar1 = 0;
    }
    else {
      match_count = (char *)___sbh_find_block((uint8_t *)(arg_1 + -0x20),&card_idx,&slot_idx);
      if (match_count == (char *)0x0) {
        if ((DAT_0050942c._1_1_ & 0x80) == 0) {
          BVar1 = HeapValidate(DAT_006c1c94,0,(LPCVOID)(arg_1 + -0x20));
        }
        else {
          BVar1 = 1;
        }
      }
      else if (*match_count == '\0') {
        BVar1 = 0;
      }
      else {
        BVar1 = 1;
      }
    }
  }
  return BVar1;
}



/*
 * Decompiled function: __CrtIsMemoryBlock
 * Entry Point: 004dbe10
 * Size: 255 bytes
 */


/* Library Function - Single Match
    __CrtIsMemoryBlock
   
   Library: Visual Studio 1998 Debug */

int32_t
__CrtIsMemoryBlock(void *arg_1,UINT_PTR arg_2,int32_t *arg_3,int32_t *arg_4,int32_t *arg_5)

{
  int val_1;
  
  val_1 = __CrtIsValidHeapPointer((int)arg_1);
  if (((val_1 != 0) &&
      (((((*(uint32_t *)((int)arg_1 + -0xc) & 0xffff) == 4 || (*(int *)((int)arg_1 + -0xc) == 1)) ||
        ((*(uint32_t *)((int)arg_1 + -0xc) & 0xffff) == 2)) || (*(int *)((int)arg_1 + -0xc) == 3)))) &&
     (((val_1 = __CrtIsValidPointer(arg_1,arg_2,1), val_1 != 0 &&
       (*(UINT_PTR *)((int)arg_1 + -0x10) == arg_2)) && (*(int *)((int)arg_1 + -8) <= DAT_00509474))
     )) {
    if (arg_3 != (int32_t *)0x0) {
      *arg_3 = *(int32_t *)((int)arg_1 + -8);
    }
    if (arg_4 != (int32_t *)0x0) {
      *arg_4 = *(int32_t *)((int)arg_1 + -0x18);
    }
    if (arg_5 != (int32_t *)0x0) {
      *arg_5 = *(int32_t *)((int)arg_1 + -0x14);
    }
    return 1;
  }
  return 0;
}



/*
 * Decompiled function: Mem_AllocOrFree_004dbf10
 * Entry Point: 004dbf10
 * Size: 38 bytes
 */


int32_t Mem_AllocOrFree_004dbf10(int32_t arg_1)

{
  int32_t uval_1;
  
  uval_1 = DAT_006c2cac;
  DAT_006c2cac = arg_1;
  return uval_1;
}



/*
 * Decompiled function: __CrtMemCheckpoint
 * Entry Point: 004dbf40
 * Size: 316 bytes
 */


/* Library Function - Single Match
    __CrtMemCheckpoint
   
   Library: Visual Studio 1998 Debug */

void __CrtMemCheckpoint(int32_t *arg_1)

{
  code *char_ptr_1;
  int val_2;
  int32_t *match_count;
  int slot_idx;
  
  if (arg_1 == (int32_t *)0x0) {
    val_2 = __CrtDbgReport(0,0,0,0,"%s");
    if (val_2 == 1) {
      char_ptr_1 = (code *)swi(3);
      (*char_ptr_1)();
      return;
    }
  }
  else {
    *arg_1 = DAT_005edac8;
    for (slot_idx = 0; slot_idx < 5; slot_idx = slot_idx + 1) {
      arg_1[slot_idx + 6] = 0;
      arg_1[slot_idx + 1] = arg_1[slot_idx + 6];
    }
    for (match_count = DAT_005edac8; match_count != (int32_t *)0x0; match_count = (int32_t *)*match_count) {
      if ((match_count[5] & 0xffff) < 5) {
        arg_1[(match_count[5] & 0xffff) + 1] = arg_1[(match_count[5] & 0xffff) + 1] + 1;
        arg_1[(match_count[5] & 0xffff) + 6] = arg_1[(match_count[5] & 0xffff) + 6] + match_count[4];
      }
      else {
        val_2 = __CrtDbgReport(0,0,0,0,"Bad memory block found at 0x%08X.\n");
        if (val_2 == 1) {
          char_ptr_1 = (code *)swi(3);
          (*char_ptr_1)();
          return;
        }
      }
    }
    arg_1[0xb] = DAT_005edad0;
    arg_1[0xc] = DAT_005edac4;
  }
  return;
}



/*
 * Decompiled function: __CrtMemDifference
 * Entry Point: 004dc080
 * Size: 312 bytes
 */


/* Library Function - Single Match
    __CrtMemDifference
   
   Library: Visual Studio 1998 Debug */

int32_t __CrtMemDifference(int32_t *arg_1,int card_slot,int event_type)

{
  code *char_ptr_1;
  int val_2;
  int32_t uval_3;
  int32_t match_count;
  int slot_idx;
  
  match_count = 0;
  if (((arg_1 == (int32_t *)0x0) || (arg_2 == 0)) || (arg_3 == 0)) {
    val_2 = __CrtDbgReport(0,0,0,0,"%s");
    if (val_2 == 1) {
      char_ptr_1 = (code *)swi(3);
      uval_3 = (*char_ptr_1)();
      return uval_3;
    }
    match_count = 0;
  }
  else {
    for (slot_idx = 0; slot_idx < 5; slot_idx = slot_idx + 1) {
      arg_1[slot_idx + 6] =
           *(int *)(arg_3 + 0x18 + slot_idx * 4) - *(int *)(arg_2 + 0x18 + slot_idx * 4);
      arg_1[slot_idx + 1] = *(int *)(arg_3 + 4 + slot_idx * 4) - *(int *)(arg_2 + 4 + slot_idx * 4);
      if (((arg_1[slot_idx + 6] != 0) || (arg_1[slot_idx + 1] != 0)) &&
         ((slot_idx != 0 && ((slot_idx != 2 || (((uint8_t)DAT_00509470 & 0x10) != 0)))))) {
        match_count = 1;
      }
    }
    arg_1[0xb] = *(int *)(arg_3 + 0x2c) - *(int *)(arg_2 + 0x2c);
    arg_1[0xc] = *(int *)(arg_3 + 0x30) - *(int *)(arg_2 + 0x30);
    *arg_1 = 0;
  }
  return match_count;
}



/*
 * Decompiled function: __CrtMemDumpAllObjectsSince
 * Entry Point: 004dc1c0
 * Size: 704 bytes
 */


/* Library Function - Single Match
    __CrtMemDumpAllObjectsSince
   
   Library: Visual Studio 1998 Debug */

void __CrtMemDumpAllObjectsSince(int32_t *arg_1)

{
  code *char_ptr_1;
  int val_2;
  int32_t *match_count;
  int32_t *slot_idx;
  
  match_count = (int32_t *)0x0;
  val_2 = __CrtDbgReport(0,0,0,0,"%s");
  if (val_2 == 1) {
    char_ptr_1 = (code *)swi(3);
    (*char_ptr_1)();
    return;
  }
  if (arg_1 != (int32_t *)0x0) {
    match_count = (int32_t *)*arg_1;
  }
  slot_idx = DAT_005edac8;
  do {
    if ((slot_idx == (int32_t *)0x0) || (slot_idx == match_count)) {
      val_2 = __CrtDbgReport(0,0,0,0,"%s");
      if (val_2 != 1) {
        return;
      }
      char_ptr_1 = (code *)swi(3);
      (*char_ptr_1)();
      return;
    }
    if ((((slot_idx[5] & 0xffff) != 3) && ((slot_idx[5] & 0xffff) != 0)) &&
       (((slot_idx[5] & 0xffff) != 2 || (((uint8_t)DAT_00509470 & 0x10) != 0)))) {
      if (slot_idx[2] != 0) {
        val_2 = __CrtIsValidPointer((void *)slot_idx[2],1,0);
        if (val_2 == 0) {
          val_2 = __CrtDbgReport(0,0,0,0,"#File Error#(%d) : ");
          if (val_2 == 1) {
            char_ptr_1 = (code *)swi(3);
            (*char_ptr_1)();
            return;
          }
        }
        else {
          val_2 = __CrtDbgReport(0,0,0,0,"%hs(%d) : ");
          if (val_2 == 1) {
            char_ptr_1 = (code *)swi(3);
            (*char_ptr_1)();
            return;
          }
        }
      }
      val_2 = __CrtDbgReport(0,0,0,0,"{%ld} ");
      if (val_2 == 1) {
        char_ptr_1 = (code *)swi(3);
        (*char_ptr_1)();
        return;
      }
      if ((slot_idx[5] & 0xffff) == 4) {
        val_2 = __CrtDbgReport(0,0,0,0,"client block at 0x%08X, subtype %x, %u bytes long.\n");
        if (val_2 == 1) {
          char_ptr_1 = (code *)swi(3);
          (*char_ptr_1)();
          return;
        }
        if (DAT_006c2cac == (code *)0x0) {
          __printMemBlockData((int)slot_idx);
        }
        else {
          (*DAT_006c2cac)(slot_idx + 8,slot_idx[4]);
        }
      }
      else if (slot_idx[5] == 1) {
        val_2 = __CrtDbgReport(0,0,0,0,"normal block at 0x%08X, %u bytes long.\n");
        if (val_2 == 1) {
          char_ptr_1 = (code *)swi(3);
          (*char_ptr_1)();
          return;
        }
        __printMemBlockData((int)slot_idx);
      }
      else if ((slot_idx[5] & 0xffff) == 2) {
        val_2 = __CrtDbgReport(0,0,0,0,"crt block at 0x%08X, subtype %x, %u bytes long.\n");
        if (val_2 == 1) {
          char_ptr_1 = (code *)swi(3);
          (*char_ptr_1)();
          return;
        }
        __printMemBlockData((int)slot_idx);
      }
    }
    slot_idx = (int32_t *)*slot_idx;
  } while( true );
}



/*
 * Decompiled function: __printMemBlockData
 * Entry Point: 004dc480
 * Size: 252 bytes
 */


/* Library Function - Single Match
    __printMemBlockData
   
   Library: Visual Studio 1998 Debug */

void __printMemBlockData(int player_id)

{
  uint8_t flag_1;
  code *char_ptr_2;
  int val_3;
  uint32_t local_58;
  int local_50;
  uint8_t local_4c [20];
  char local_38 [52];
  
  local_50 = 0;
  while( true ) {
    val_3 = *(int *)(arg_1 + 0x10);
    if (0xf < val_3) {
      val_3 = 0x10;
    }
    if (val_3 <= local_50) break;
    flag_1 = *(uint8_t *)(arg_1 + 0x20 + local_50);
    if (DAT_005096ac < 2) {
      local_58 = *(uint16_t *)(PTR_DAT_005094a0 + (uint32_t)flag_1 * 2) & 0x157;
    }
    else {
      local_58 = __isctype((uint32_t)flag_1,0x157);
    }
    if (local_58 == 0) {
      local_4c[local_50] = 0x20;
    }
    else {
      local_4c[local_50] = flag_1;
    }
    _sprintf(local_38 + local_50 * 3,"%.2X ",(uint32_t)flag_1);
    local_50 = local_50 + 1;
  }
  local_4c[local_50] = 0;
  val_3 = __CrtDbgReport(0,0,0,0," Data: <%s> %s\n");
  if (val_3 == 1) {
    char_ptr_2 = (code *)swi(3);
    (*char_ptr_2)();
    return;
  }
  return;
}



/*
 * Decompiled function: __CrtDumpMemoryLeaks
 * Entry Point: 004dc580
 * Size: 132 bytes
 */


/* Library Function - Single Match
    __CrtDumpMemoryLeaks
   
   Library: Visual Studio 1998 Debug */

int32_t __CrtDumpMemoryLeaks(void)

{
  code *char_ptr_1;
  int val_2;
  int32_t uval_3;
  int32_t local_38 [2];
  int local_30;
  int local_2c;
  int local_24;
  
  __CrtMemCheckpoint(local_38);
  if (((local_24 == 0) && (local_30 == 0)) &&
     ((((uint8_t)DAT_00509470 & 0x10) == 0 || (local_2c == 0)))) {
    uval_3 = 0;
  }
  else {
    val_2 = __CrtDbgReport(0,0,0,0,"%s");
    if (val_2 == 1) {
      char_ptr_1 = (code *)swi(3);
      uval_3 = (*char_ptr_1)();
      return uval_3;
    }
    __CrtMemDumpAllObjectsSince((int32_t *)0x0);
    uval_3 = 1;
  }
  return uval_3;
}



/*
 * Decompiled function: __CrtMemDumpStatistics
 * Entry Point: 004dc610
 * Size: 199 bytes
 */


/* Library Function - Single Match
    __CrtMemDumpStatistics
   
   Library: Visual Studio 1998 Debug */

void __CrtMemDumpStatistics(int player_id)

{
  code *char_ptr_1;
  int val_2;
  int slot_idx;
  
  if (arg_1 != 0) {
    for (slot_idx = 0; slot_idx < 5; slot_idx = slot_idx + 1) {
      val_2 = __CrtDbgReport(0,0,0,0,"%ld bytes in %ld %hs Blocks.\n");
      if (val_2 == 1) {
        char_ptr_1 = (code *)swi(3);
        (*char_ptr_1)();
        return;
      }
    }
    val_2 = __CrtDbgReport(0,0,0,0,"Largest number used: %ld bytes.\n");
    if (val_2 == 1) {
      char_ptr_1 = (code *)swi(3);
      (*char_ptr_1)();
      return;
    }
    val_2 = __CrtDbgReport(0,0,0,0,"Total allocations: %ld bytes.\n");
    if (val_2 == 1) {
      char_ptr_1 = (code *)swi(3);
      (*char_ptr_1)();
      return;
    }
  }
  return;
}



