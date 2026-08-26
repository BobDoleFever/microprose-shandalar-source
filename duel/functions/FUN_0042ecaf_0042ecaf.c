/*
 * Decompiled function: FUN_0042ecaf
 * Entry Point: 0042ecaf
 * Size: 169 bytes
 */
#include "duel.h"


int FUN_0042ecaf(int x,int y,int width,int height)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_0048c367((&DAT_006826dd)[x * 0x5b20 + y * 0x120]);
  DAT_0068ece0 = DAT_0068ece0 + *(int *)(&DAT_00676150 + iVar1 * 4);
  iVar2 = Ai_CalcManaRequirement_004ba890(x,width,height);
  iVar1 = FUN_0048c367((&DAT_006826dd)[x * 0x5b20 + y * 0x120]);
  iVar2 = iVar2 - *(int *)(&DAT_00676150 + iVar1 * 4);
  if (DAT_00681ea4 == 1) {
    iVar2 = 0;
  }
  return iVar2;
}


