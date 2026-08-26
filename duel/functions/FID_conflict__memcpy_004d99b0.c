/*
 * Decompiled function: FID_conflict:_memcpy
 * Entry Point: 004d99b0
 * Size: 285 bytes
 */
#include "duel.h"


/* Library Function - Multiple Matches With Different Base Names
    _memcpy
    _memmove
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

void * __cdecl FID_conflict__memcpy(void *ptr_1,void *ptr_2,size_t arg_3)

{
  uint uVar1;
  int in_EDX;
  uint uVar2;
  undefined4 *puVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  undefined1 *puVar6;
  
  if ((ptr_2 < ptr_1) && (ptr_1 < (void *)((int)ptr_2 + arg_3))) {
    puVar3 = (undefined4 *)((int)ptr_2 + arg_3);
    puVar5 = (undefined4 *)((int)ptr_1 + arg_3);
    if (((uint)puVar5 & 3) == 0) {
      uVar1 = arg_3 >> 2;
      while( true ) {
        puVar5 = puVar5 + -1;
        puVar3 = puVar3 + -1;
        if (uVar1 == 0) break;
        uVar1 = uVar1 - 1;
        *puVar5 = *puVar3;
      }
      switch(arg_3 & 3) {
      case 1:
switchD_004d9a79_caseD_1:
        *(undefined1 *)((int)puVar5 + 3) = *(undefined1 *)((int)puVar3 + 3);
        return ptr_1;
      case 2:
switchD_004d9a79_caseD_2:
        *(undefined2 *)((int)puVar5 + 2) = *(undefined2 *)((int)puVar3 + 2);
        return ptr_1;
      case 3:
switchD_004d9a79_caseD_3:
        *(undefined2 *)((int)puVar5 + 2) = *(undefined2 *)((int)puVar3 + 2);
        *(undefined1 *)((int)puVar5 + 1) = *(undefined1 *)((int)puVar3 + 1);
        return ptr_1;
      }
    }
    else {
      puVar4 = (undefined1 *)((int)puVar3 + -1);
      puVar6 = (undefined1 *)((int)puVar5 + -1);
      if (arg_3 < 0xd) {
        for (; arg_3 != 0; arg_3 = arg_3 - 1) {
          *puVar6 = *puVar4;
          puVar4 = puVar4 + -1;
          puVar6 = puVar6 + -1;
        }
        return ptr_1;
      }
      uVar2 = -in_EDX & 3;
      uVar1 = arg_3 - uVar2;
      for (; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar6 = *puVar4;
        puVar4 = puVar4 + -1;
        puVar6 = puVar6 + -1;
      }
      puVar3 = (undefined4 *)(puVar4 + -3);
      puVar5 = (undefined4 *)(puVar6 + -3);
      for (uVar2 = uVar1 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar5 = *puVar3;
        puVar3 = puVar3 + -1;
        puVar5 = puVar5 + -1;
      }
      switch(uVar1 & 3) {
      case 1:
        goto switchD_004d9a79_caseD_1;
      case 2:
        goto switchD_004d9a79_caseD_2;
      case 3:
        goto switchD_004d9a79_caseD_3;
      }
    }
    return ptr_1;
  }
  puVar3 = ptr_1;
  if (((uint)ptr_1 & 3) == 0) {
    for (uVar1 = arg_3 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
      *puVar3 = *(undefined4 *)ptr_2;
      ptr_2 = (undefined4 *)((int)ptr_2 + 4);
      puVar3 = puVar3 + 1;
    }
    switch(arg_3 & 3) {
    case 1:
switchD_004d99e0_caseD_1:
      *(undefined1 *)puVar3 = *(undefined1 *)ptr_2;
      return ptr_1;
    case 2:
switchD_004d99e0_caseD_2:
      *(undefined2 *)puVar3 = *(undefined2 *)ptr_2;
      return ptr_1;
    case 3:
switchD_004d99e0_caseD_3:
      *(undefined2 *)puVar3 = *(undefined2 *)ptr_2;
      *(undefined1 *)((int)puVar3 + 2) = *(undefined1 *)((int)ptr_2 + 2);
      return ptr_1;
    }
  }
  else {
    puVar4 = ptr_1;
    if (arg_3 < 0xd) {
      for (; arg_3 != 0; arg_3 = arg_3 - 1) {
        *puVar4 = *(undefined1 *)ptr_2;
        ptr_2 = (undefined1 *)((int)ptr_2 + 1);
        puVar4 = puVar4 + 1;
      }
      return ptr_1;
    }
    uVar2 = -(int)ptr_1 & 3;
    uVar1 = arg_3 - uVar2;
    for (; uVar2 != 0; uVar2 = uVar2 - 1) {
      *(undefined1 *)puVar3 = *(undefined1 *)ptr_2;
      ptr_2 = (undefined4 *)((int)ptr_2 + 1);
      puVar3 = (undefined4 *)((int)puVar3 + 1);
    }
    for (uVar2 = uVar1 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar3 = *(undefined4 *)ptr_2;
      ptr_2 = (undefined4 *)((int)ptr_2 + 4);
      puVar3 = puVar3 + 1;
    }
    switch(uVar1 & 3) {
    case 1:
      goto switchD_004d99e0_caseD_1;
    case 2:
      goto switchD_004d99e0_caseD_2;
    case 3:
      goto switchD_004d99e0_caseD_3;
    }
  }
  return ptr_1;
}


