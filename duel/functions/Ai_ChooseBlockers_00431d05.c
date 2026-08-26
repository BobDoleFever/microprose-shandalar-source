/*
 * Decompiled function: Ai_ChooseBlockers
 * Entry Point: 00431d05
 * Size: 572 bytes
 */
#include "duel.h"


undefined4 Ai_ChooseBlockers(int arg1,int arg2)

{
  uint *puVar1;
  int local_14;
  int local_10;
  uint local_c;
  int local_8;
  
  Mem_AllocOrFree_004d9630((uint *)&DAT_005f6810,(uint *)&DAT_004f3ca8);
  puVar1 = (uint *)__itoa(arg2,&DAT_005126c8,10);
  FUN_004d9640((uint *)&DAT_005f6810,puVar1);
  FUN_004d9640((uint *)&DAT_005f6810,(uint *)&DAT_004f3cac);
  puVar1 = (uint *)__itoa(DAT_00681ea8,&DAT_005126c8,10);
  FUN_004d9640((uint *)&DAT_005f6810,puVar1);
  FUN_004d9640((uint *)&DAT_005f6810,(uint *)&DAT_004f3cb0);
  puVar1 = (uint *)__itoa(DAT_00681eac,&DAT_005126c8,10);
  FUN_004d9640((uint *)&DAT_005f6810,puVar1);
  FUN_004d9640((uint *)&DAT_005f6810,(uint *)s_____004f3cb4);
  local_8 = 0;
  while( true ) {
    if (arg1 == 0) {
      local_10 = DAT_0050b37c;
    }
    else {
      local_10 = DAT_00515e60;
    }
    if (local_10 <= local_8) break;
    if (arg1 == 0) {
      local_c = *(uint *)(&DAT_0050f170 + local_8 * 4);
    }
    else {
      local_c = *(uint *)(&DAT_0050ed70 + local_8 * 4);
    }
    if (local_c != 0xffffffff) {
      if ((local_c & 0x1000) != 0) {
        FUN_004d9640((uint *)&DAT_005f6810,(uint *)s_Cast_004f3cbc);
      }
      if ((local_c & 0x2000) != 0) {
        FUN_004d9640((uint *)&DAT_005f6810,(uint *)&DAT_004f3cc4);
      }
      if ((local_c & 0x4000) != 0) {
        FUN_004d9640((uint *)&DAT_005f6810,(uint *)s____target_004f3ccc);
      }
      if ((local_c & 0x100) == 0) {
        FUN_004d9640((uint *)&DAT_005f6810,(uint *)&DAT_004f3cd8);
      }
      if ((char)local_c == -1) {
        FUN_004d9640((uint *)&DAT_005f6810,(uint *)s_Player_004f3cdc);
      }
      else {
        if (arg1 == 0) {
          local_14 = *(int *)(&DAT_00512d78 + local_8 * 4);
        }
        else {
          local_14 = *(int *)(&DAT_00512978 + local_8 * 4);
        }
        FUN_004d9640((uint *)&DAT_005f6810,(uint *)(s_Swamp_004ff581 + local_14 * 0x34));
      }
      FUN_004d9640((uint *)&DAT_005f6810,(uint *)&DAT_004f3ce4);
    }
    local_8 = local_8 + 1;
  }
  Ai_Subsystem_004cc56d(0,0,0,-1,-1,&DAT_005f6810,0);
  return 0;
}


