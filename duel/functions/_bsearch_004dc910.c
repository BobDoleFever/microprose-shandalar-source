/*
 * Decompiled function: _bsearch
 * Entry Point: 004dc910
 * Size: 277 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _bsearch
   
   Library: Visual Studio 1998 Debug */

void * __cdecl
_bsearch(void *ptr_1,void *out_buffer,size_t arg_3,size_t arg_4,_PtFuncCompare *ptr_5)

{
  uint uVar1;
  uint uVar2;
  void *pvVar3;
  int iVar4;
  uint local_1c;
  void *local_18;
  void *local_14;
  
  local_14 = out_buffer;
  local_18 = (void *)((arg_3 - 1) * arg_4 + (int)out_buffer);
  while( true ) {
    if (local_18 < local_14) {
      return (void *)0x0;
    }
    uVar2 = arg_3 >> 1;
    if (uVar2 == 0) break;
    local_1c = uVar2;
    if ((arg_3 & 1) == 0) {
      local_1c = uVar2 - 1;
    }
    pvVar3 = (void *)(arg_4 * local_1c + (int)local_14);
    iVar4 = (*ptr_5)(ptr_1,pvVar3);
    if (iVar4 == 0) {
      return pvVar3;
    }
    if (iVar4 < 0) {
      local_18 = (void *)((int)pvVar3 - arg_4);
      uVar1 = arg_3 & 1;
      arg_3 = uVar2;
      if (uVar1 == 0) {
        arg_3 = uVar2 - 1;
      }
    }
    else {
      local_14 = (void *)(arg_4 + (int)pvVar3);
      arg_3 = uVar2;
    }
  }
  if (arg_3 == 0) {
    return (void *)0x0;
  }
  iVar4 = (*ptr_5)(ptr_1,local_14);
  if (iVar4 != 0) {
    return (void *)0x0;
  }
  return local_14;
}


