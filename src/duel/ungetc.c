/*
 * ungetc.c - Reconstructed MicroProse Source Module
 * Program: DUEL.EXE
 * Contained Functions: 4
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "shandalar/shandalar.h"
/* Modular Shandalar Subsystem */

/*
 * Decompiled function: _ungetc
 * Entry Point: 004e9540
 * Size: 299 bytes
 */


/* Library Function - Single Match
    _ungetc
   
   Library: Visual Studio 1998 Debug */

int __cdecl _ungetc(int arg1,FILE *arg2)

{
  code *char_ptr_1;
  int val_2;
  uint32_t uval_3;
  
  if ((arg2 == (FILE *)0x0) && (val_2 = __CrtDbgReport(2,0x4f1264,0x60,0,"str != NULL"), val_2 == 1)
     ) {
    char_ptr_1 = (code *)swi(3);
    val_2 = (*char_ptr_1)();
    return val_2;
  }
  if ((arg1 == -1) ||
     (((arg2->_flag & 1) == 0 && (((arg2->_flag & 0x80) == 0 || ((arg2->_flag & 2) != 0)))))) {
    uval_3 = 0xffffffff;
  }
  else {
    if (arg2->_base == (char *)0x0) {
      __getbuf(arg2);
    }
    if (arg2->_base == arg2->_ptr) {
      if (arg2->_cnt != 0) {
        return -1;
      }
      arg2->_ptr = arg2->_ptr + 1;
    }
    if ((arg2->_flag & 0x40) == 0) {
      arg2->_ptr = arg2->_ptr + -1;
      *arg2->_ptr = (char)arg1;
    }
    else {
      arg2->_ptr = arg2->_ptr + -1;
      if (*arg2->_ptr != (char)arg1) {
        arg2->_ptr = arg2->_ptr + 1;
        return -1;
      }
    }
    arg2->_cnt = arg2->_cnt + 1;
    arg2->_flag = arg2->_flag & 0xffffffef;
    arg2->_flag = arg2->_flag | 1;
    uval_3 = arg1 & 0xff;
  }
  return uval_3;
}



/*
 * Decompiled function: __setmode
 * Entry Point: 004e9670
 * Size: 308 bytes
 */


/* Library Function - Single Match
    __setmode
   
   Library: Visual Studio 1998 Debug */

int __cdecl __setmode(int arg1,int arg2)

{
  char cVar1;
  int val_2;
  
  if (((uint32_t)arg1 < DAT_006c1c90) &&
     ((*(uint8_t *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg1 & 0xffffffe0U) >> 3)) + 4 +
                (arg1 & 0x1fU) * 8) & 1) != 0)) {
    cVar1 = *(char *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg1 & 0xffffffe0U) >> 3)) + 4 +
                     (arg1 & 0x1fU) * 8);
    if (arg2 == 0x8000) {
      *(uint8_t *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg1 & 0xffffffe0U) >> 3)) + 4 +
               (arg1 & 0x1fU) * 8) =
           *(uint8_t *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg1 & 0xffffffe0U) >> 3)) + 4 +
                    (arg1 & 0x1fU) * 8) & 0x7f;
    }
    else {
      if (arg2 != 0x4000) {
        DAT_00509420 = 0x16;
        return -1;
      }
      *(uint8_t *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg1 & 0xffffffe0U) >> 3)) + 4 +
               (arg1 & 0x1fU) * 8) =
           *(uint8_t *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg1 & 0xffffffe0U) >> 3)) + 4 +
                    (arg1 & 0x1fU) * 8) | 0x80;
    }
    if (((int)cVar1 & 0x80U) == 0) {
      val_2 = 0x8000;
    }
    else {
      val_2 = 0x4000;
    }
  }
  else {
    DAT_00509420 = 9;
    val_2 = -1;
  }
  return val_2;
}



/*
 * Decompiled function: FID_conflict:_memcpy
 * Entry Point: 004e97b0
 * Size: 285 bytes
 */


/* Library Function - Multiple Matches With Different Base Names
    _memcpy
    _memmove
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

void * __cdecl FID_conflict__memcpy(void *ptr_1,void *ptr_2,size_t arg_3)

{
  uint32_t uval_1;
  int in_EDX;
  uint32_t uval_2;
  int32_t *u_ptr_3;
  uint8_t *puVar4;
  int32_t *puVar5;
  uint8_t *puVar6;
  
  if ((ptr_2 < ptr_1) && (ptr_1 < (void *)((int)ptr_2 + arg_3))) {
    u_ptr_3 = (int32_t *)((int)ptr_2 + arg_3);
    puVar5 = (int32_t *)((int)ptr_1 + arg_3);
    if (((uint32_t)puVar5 & 3) == 0) {
      uval_1 = arg_3 >> 2;
      while( true ) {
        puVar5 = puVar5 + -1;
        u_ptr_3 = u_ptr_3 + -1;
        if (uval_1 == 0) break;
        uval_1 = uval_1 - 1;
        *puVar5 = *u_ptr_3;
      }
      switch(arg_3 & 3) {
      case 1:
switchD_004e9879_caseD_1:
        *(uint8_t *)((int)puVar5 + 3) = *(uint8_t *)((int)u_ptr_3 + 3);
        return ptr_1;
      case 2:
switchD_004e9879_caseD_2:
        *(int16_t *)((int)puVar5 + 2) = *(int16_t *)((int)u_ptr_3 + 2);
        return ptr_1;
      case 3:
switchD_004e9879_caseD_3:
        *(int16_t *)((int)puVar5 + 2) = *(int16_t *)((int)u_ptr_3 + 2);
        *(uint8_t *)((int)puVar5 + 1) = *(uint8_t *)((int)u_ptr_3 + 1);
        return ptr_1;
      }
    }
    else {
      puVar4 = (uint8_t *)((int)u_ptr_3 + -1);
      puVar6 = (uint8_t *)((int)puVar5 + -1);
      if (arg_3 < 0xd) {
        for (; arg_3 != 0; arg_3 = arg_3 - 1) {
          *puVar6 = *puVar4;
          puVar4 = puVar4 + -1;
          puVar6 = puVar6 + -1;
        }
        return ptr_1;
      }
      uval_2 = -in_EDX & 3;
      uval_1 = arg_3 - uval_2;
      for (; uval_2 != 0; uval_2 = uval_2 - 1) {
        *puVar6 = *puVar4;
        puVar4 = puVar4 + -1;
        puVar6 = puVar6 + -1;
      }
      u_ptr_3 = (int32_t *)(puVar4 + -3);
      puVar5 = (int32_t *)(puVar6 + -3);
      for (uval_2 = uval_1 >> 2; uval_2 != 0; uval_2 = uval_2 - 1) {
        *puVar5 = *u_ptr_3;
        u_ptr_3 = u_ptr_3 + -1;
        puVar5 = puVar5 + -1;
      }
      switch(uval_1 & 3) {
      case 1:
        goto switchD_004e9879_caseD_1;
      case 2:
        goto switchD_004e9879_caseD_2;
      case 3:
        goto switchD_004e9879_caseD_3;
      }
    }
    return ptr_1;
  }
  u_ptr_3 = ptr_1;
  if (((uint32_t)ptr_1 & 3) == 0) {
    for (uval_1 = arg_3 >> 2; uval_1 != 0; uval_1 = uval_1 - 1) {
      *u_ptr_3 = *(int32_t *)ptr_2;
      ptr_2 = (int32_t *)((int)ptr_2 + 4);
      u_ptr_3 = u_ptr_3 + 1;
    }
    switch(arg_3 & 3) {
    case 1:
switchD_004e97e0_caseD_1:
      *(uint8_t *)u_ptr_3 = *(uint8_t *)ptr_2;
      return ptr_1;
    case 2:
switchD_004e97e0_caseD_2:
      *(int16_t *)u_ptr_3 = *(int16_t *)ptr_2;
      return ptr_1;
    case 3:
switchD_004e97e0_caseD_3:
      *(int16_t *)u_ptr_3 = *(int16_t *)ptr_2;
      *(uint8_t *)((int)u_ptr_3 + 2) = *(uint8_t *)((int)ptr_2 + 2);
      return ptr_1;
    }
  }
  else {
    puVar4 = ptr_1;
    if (arg_3 < 0xd) {
      for (; arg_3 != 0; arg_3 = arg_3 - 1) {
        *puVar4 = *(uint8_t *)ptr_2;
        ptr_2 = (uint8_t *)((int)ptr_2 + 1);
        puVar4 = puVar4 + 1;
      }
      return ptr_1;
    }
    uval_2 = -(int)ptr_1 & 3;
    uval_1 = arg_3 - uval_2;
    for (; uval_2 != 0; uval_2 = uval_2 - 1) {
      *(uint8_t *)u_ptr_3 = *(uint8_t *)ptr_2;
      ptr_2 = (int32_t *)((int)ptr_2 + 1);
      u_ptr_3 = (int32_t *)((int)u_ptr_3 + 1);
    }
    for (uval_2 = uval_1 >> 2; uval_2 != 0; uval_2 = uval_2 - 1) {
      *u_ptr_3 = *(int32_t *)ptr_2;
      ptr_2 = (int32_t *)((int)ptr_2 + 4);
      u_ptr_3 = u_ptr_3 + 1;
    }
    switch(uval_1 & 3) {
    case 1:
      goto switchD_004e97e0_caseD_1;
    case 2:
      goto switchD_004e97e0_caseD_2;
    case 3:
      goto switchD_004e97e0_caseD_3;
    }
  }
  return ptr_1;
}



/*
 * Decompiled function: ___tzset
 * Entry Point: 004e9900
 * Size: 35 bytes
 */


/* Library Function - Single Match
    ___tzset
   
   Library: Visual Studio 1998 Debug */

void ___tzset(void)

{
  if (DAT_0050a80c == 0) {
    __tzset();
    DAT_0050a80c = DAT_0050a80c + 1;
  }
  return;
}



