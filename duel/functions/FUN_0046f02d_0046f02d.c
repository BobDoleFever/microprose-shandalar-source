/*
 * Decompiled function: FUN_0046f02d
 * Entry Point: 0046f02d
 * Size: 233 bytes
 */
#include "duel.h"


void FUN_0046f02d(int arg1,int arg2)

{
  int iVar1;
  int local_10;
  uint local_c;
  
  iVar1 = *(int *)(&DAT_006826c0 + arg2 * 0x120 + arg1 * 0x5b20);
  local_c = (uint)(((&DAT_006826cd)[arg2 * 0x120 + arg1 * 0x5b20] & 0x10) != 0);
  *(uint *)(&DAT_006664f0 + local_c * 4) =
       *(uint *)(&DAT_006664f0 + local_c * 4) | (uint)(byte)(&DAT_004ff594)[iVar1 * 0x34];
  local_10 = 0;
  while( true ) {
    if (499 < local_10) {
      return;
    }
    if (*(int *)(&DAT_0068f370 + local_10 * 4 + local_c * 2000) == -1) break;
    local_10 = local_10 + 1;
  }
  *(int *)(&DAT_0068f370 + local_10 * 4 + local_c * 2000) = iVar1;
  return;
}


