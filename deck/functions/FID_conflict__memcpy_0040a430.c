/*
 * Decompiled function: FID_conflict:_memcpy
 * Entry Point: 0040a430
 * Size: 285 bytes
 */
#include "deck.h"


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
switchD_0040a4f9_caseD_1:
        *(uint8_t *)((int)puVar5 + 3) = *(uint8_t *)((int)u_ptr_3 + 3);
        return ptr_1;
      case 2:
switchD_0040a4f9_caseD_2:
        *(int16_t *)((int)puVar5 + 2) = *(int16_t *)((int)u_ptr_3 + 2);
        return ptr_1;
      case 3:
switchD_0040a4f9_caseD_3:
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
        goto switchD_0040a4f9_caseD_1;
      case 2:
        goto switchD_0040a4f9_caseD_2;
      case 3:
        goto switchD_0040a4f9_caseD_3;
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
switchD_0040a460_caseD_1:
      *(uint8_t *)u_ptr_3 = *(uint8_t *)ptr_2;
      return ptr_1;
    case 2:
switchD_0040a460_caseD_2:
      *(int16_t *)u_ptr_3 = *(int16_t *)ptr_2;
      return ptr_1;
    case 3:
switchD_0040a460_caseD_3:
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
      goto switchD_0040a460_caseD_1;
    case 2:
      goto switchD_0040a460_caseD_2;
    case 3:
      goto switchD_0040a460_caseD_3;
    }
  }
  return ptr_1;
}


