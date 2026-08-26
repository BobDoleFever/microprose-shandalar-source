/*
 * Decompiled function: Mana_Init_004532f1
 * Entry Point: 004532f1
 * Size: 514 bytes
 */
#include "magic.h"


undefined4 Mana_Init_004532f1(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (arg_3 == 1) {
    uVar1 = Minit_Subsystem_004528c0(arg_1,arg_2,1,0);
  }
  else if (arg_3 == 0x73) {
    if ((((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0) &&
       ((((&DAT_006a5f3e)[arg_2 * 0x120 + arg_1 * 0x5b20] & 3) == 0 ||
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34] & 2) == 0)))) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    if (arg_3 == 0x6d) {
      if (arg_1 == g_CurrentTurnPhase) {
        iVar2 = FUN_0040a1d2(5);
        local_10 = iVar2 + 1;
      }
      else {
        local_8 = -1;
        for (local_c = 1; local_c < 7; local_c = local_c + 1) {
          if (local_8 < *(int *)(&DAT_006ff690 + local_c * 4 + arg_1 * 0x20)) {
            local_8 = *(int *)(&DAT_006ff690 + local_c * 4 + arg_1 * 0x20);
            local_10 = local_c;
          }
        }
      }
      if (arg_1 == 1) {
        local_14 = local_10;
      }
      else {
        local_14 = -1;
      }
      iVar2 = Ai_Subsystem_004cc93d(arg_1,s_What_kind_of_mana__00523f40,1,local_14,0xffffffff);
      if (iVar2 == -1) {
        g_ActivePlayer = 1;
      }
      else {
        FUN_0040d875(arg_1,iVar2,1);
        Mem_AllocOrFree_0041df33(arg_1,1,arg_1,arg_2);
        *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
        DAT_006ff2d4 = iVar2;
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}


