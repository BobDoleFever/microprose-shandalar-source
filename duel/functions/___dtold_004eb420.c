/*
 * Decompiled function: ___dtold
 * Entry Point: 004eb420
 * Size: 375 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    ___dtold
   
   Library: Visual Studio 1998 Debug */

void ___dtold(uint *arg1,uint *arg2)

{
  ushort uVar1;
  uint uVar2;
  ushort uVar3;
  uint uVar4;
  short local_18;
  uint local_10;
  
  local_10 = 0x80000000;
  uVar4 = (*(ushort *)((int)arg2 + 6) & 0x7ff0) >> 4;
  uVar1 = *(ushort *)((int)arg2 + 6);
  uVar2 = *arg2;
  local_18 = (short)uVar4;
  if (uVar4 == 0) {
    if (((arg2[1] & 0xfffff) == 0) && (uVar2 == 0)) {
      arg1[1] = 0;
      *arg1 = 0;
      *(undefined2 *)(arg1 + 2) = 0;
      return;
    }
    uVar3 = 0x3c01;
    local_10 = 0;
  }
  else if (uVar4 == 0x7ff) {
    uVar3 = 0x7fff;
  }
  else {
    uVar3 = local_18 + 0x3c00;
  }
  arg1[1] = uVar2 >> 0x15 | (arg2[1] & 0xfffff) << 0xb | local_10;
  *arg1 = uVar2 << 0xb;
  while ((*(byte *)((int)arg1 + 7) & 0x80) == 0) {
    arg1[1] = *arg1 >> 0x1f | arg1[1] * 2;
    *arg1 = *arg1 << 1;
    uVar3 = uVar3 - 1;
  }
  *(ushort *)(arg1 + 2) = uVar3 | uVar1 & 0x8000;
  return;
}


