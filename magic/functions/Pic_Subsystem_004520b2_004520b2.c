/*
 * Decompiled function: Pic_Subsystem_004520b2
 * Entry Point: 004520b2
 * Size: 244 bytes
 */
#include "magic.h"


void Pic_Subsystem_004520b2(void)

{
  int iVar1;
  int local_7dc;
  uint auStack_7d8 [500];
  undefined4 local_8;
  
  for (local_7dc = 0; local_7dc < 500; local_7dc = local_7dc + 1) {
    auStack_7d8[local_7dc] = *(uint *)(&deck + local_7dc * 4);
    *(undefined4 *)(&deck + local_7dc * 4) = 0xffffffff;
  }
  local_8 = DAT_0067bde0;
  for (local_7dc = 0; local_7dc < 500; local_7dc = local_7dc + 1) {
    if (auStack_7d8[local_7dc] != 0xffffffff) {
      iVar1 = Pic_Subsystem_00451e40(auStack_7d8[local_7dc] & 0xfff);
      *(uint *)(&deck + iVar1 * 4) =
           *(uint *)(&deck + iVar1 * 4) | auStack_7d8[local_7dc] & 0xfffff000;
    }
  }
  DAT_0067bde0 = local_8;
  return;
}


