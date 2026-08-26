/*
 * Decompiled function: FUN_0043504d
 * Entry Point: 0043504d
 * Size: 100 bytes
 */
#include "duel.h"


void FUN_0043504d(uint arg1,uint *arg2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  iVar1 = ((arg1 & 0xff0000) >> 0x10) * 8;
  uVar4 = *(uint *)(&DAT_00694f54 + iVar1);
  iVar2 = (arg1 & 0xff) * 8;
  uVar5 = *(uint *)(&DAT_006bf954 + iVar2);
  iVar3 = (arg1 >> 8 & 0xff) * 8;
  uVar6 = *(uint *)(&DAT_006be134 + iVar3);
  *arg2 = *(uint *)(&DAT_00694f50 + iVar1) | *(uint *)(&DAT_006bf950 + iVar2) |
          *(uint *)(&DAT_006be130 + iVar3);
  arg2[1] = uVar4 | uVar5 | uVar6;
  return;
}


