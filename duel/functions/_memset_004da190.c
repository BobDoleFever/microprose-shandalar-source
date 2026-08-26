/*
 * Decompiled function: _memset
 * Entry Point: 004da190
 * Size: 88 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _memset
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

void * __cdecl _memset(void *ptr_1,int arg_2,size_t arg_3)

{
  uint uVar1;
  uint uVar2;
  size_t sVar3;
  uint *puVar4;
  
  if (arg_3 == 0) {
    return ptr_1;
  }
  uVar1 = arg_2 & 0xff;
  puVar4 = ptr_1;
  if (3 < arg_3) {
    uVar2 = -(int)ptr_1 & 3;
    sVar3 = arg_3;
    if (uVar2 != 0) {
      sVar3 = arg_3 - uVar2;
      do {
        *(undefined1 *)puVar4 = (undefined1)arg_2;
        puVar4 = (uint *)((int)puVar4 + 1);
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
    }
    uVar1 = uVar1 * 0x1010101;
    arg_3 = sVar3 & 3;
    uVar2 = sVar3 >> 2;
    if (uVar2 != 0) {
      for (; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar4 = uVar1;
        puVar4 = puVar4 + 1;
      }
      if (arg_3 == 0) {
        return ptr_1;
      }
    }
  }
  do {
    *(char *)puVar4 = (char)uVar1;
    puVar4 = (uint *)((int)puVar4 + 1);
    arg_3 = arg_3 - 1;
  } while (arg_3 != 0);
  return ptr_1;
}


