/*
 * Decompiled function: __ShrMan
 * Entry Point: 004ead80
 * Size: 235 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __ShrMan
   
   Library: Visual Studio 1998 Debug */

void __ShrMan(int arg1,int arg2)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 local_10;
  undefined4 local_c;
  undefined1 local_8;
  
  iVar3 = (int)(arg2 + (arg2 >> 0x1f & 0x1fU)) >> 5;
  local_8 = (byte)(arg2 >> 0x1f);
  local_8 = (((byte)arg2 ^ local_8) - local_8 & 0x1f ^ local_8) - local_8;
  local_c = 0;
  for (local_10 = 0; local_10 < 3; local_10 = local_10 + 1) {
    uVar2 = *(uint *)(arg1 + local_10 * 4);
    puVar1 = (uint *)(arg1 + local_10 * 4);
    *puVar1 = *puVar1 >> (local_8 & 0x1f);
    puVar1 = (uint *)(arg1 + local_10 * 4);
    *puVar1 = *puVar1 | local_c;
    local_c = (uVar2 & ~(-1 << (local_8 & 0x1f))) << (0x20 - local_8 & 0x1f);
  }
  for (local_10 = 2; -1 < local_10; local_10 = local_10 + -1) {
    if (local_10 < iVar3) {
      *(undefined4 *)(arg1 + local_10 * 4) = 0;
    }
    else {
      *(undefined4 *)(arg1 + local_10 * 4) = *(undefined4 *)(arg1 + (local_10 - iVar3) * 4);
    }
  }
  return;
}


