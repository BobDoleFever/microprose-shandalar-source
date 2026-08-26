/*
 * Decompiled function: FUN_004d7782
 * Entry Point: 004d7782
 * Size: 244 bytes
 */
#include "duel.h"


void FUN_004d7782(void)

{
  int iVar1;
  int local_7dc;
  uint auStack_7d8 [500];
  undefined4 local_8;
  
  for (local_7dc = 0; local_7dc < 500; local_7dc = local_7dc + 1) {
    auStack_7d8[local_7dc] = *(uint *)(&deck + local_7dc * 4);
    *(undefined4 *)(&deck + local_7dc * 4) = 0xffffffff;
  }
  local_8 = DAT_005ef9a8;
  for (local_7dc = 0; local_7dc < 500; local_7dc = local_7dc + 1) {
    if (auStack_7d8[local_7dc] != 0xffffffff) {
      iVar1 = Ai_Subsystem_004cc1e8(auStack_7d8[local_7dc] & 0xfff);
      *(uint *)(&deck + iVar1 * 4) =
           *(uint *)(&deck + iVar1 * 4) | auStack_7d8[local_7dc] & 0xfffff000;
    }
  }
  DAT_005ef9a8 = local_8;
  return;
}


