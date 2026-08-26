/*
 * Decompiled function: Card_Kudzu_LandDestruction
 * Entry Point: 004d1e10
 * Size: 796 bytes
 */
#include "magic.h"


undefined4 Card_Kudzu_LandDestruction(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int local_10;
  int local_c;
  
  if (((arg_3 == 0x6c) && (arg_2 == g_OverworldMapGrid)) && (arg_1 == g_OverworldPlayerCoordX)) {
    iVar1 = Pic_Subsystem_0045268f(0x38f);
    iVar1 = Pic_Subsystem_00451291(1 - arg_1,iVar1);
    if (iVar1 != -1) {
      *(uint *)(&g_CardSlot_Flags + iVar1 * 0x120 + (1 - arg_1) * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + iVar1 * 0x120 + (1 - arg_1) * 0x5b20) | 2;
      *(undefined4 *)(&DAT_006a5f74 + iVar1 * 0x120 + (1 - arg_1) * 0x5b20) =
           *(undefined4 *)
            (&g_MasterCardTypeTable +
            *(int *)(&g_CardSlot_CardId + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x34);
    }
    *(int *)(&g_CardSlot_ConvertedManaCost + arg_1 * 0x5b20 + arg_2 * 0x120) = iVar1;
  }
  if (arg_3 == 0x73) {
    uVar2 = FUN_0040d949(arg_1,3,1);
  }
  else {
    if (arg_3 == 0x6d) {
      iVar1 = FUN_0040d949(arg_1,3,1);
      if (iVar1 != 0) {
        Ai_CalcManaRequirement_004ba890(arg_1,3,1);
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_1 * 0x5b20 + arg_2 * 0x120) =
             g_TurnCounter;
      }
    }
    if ((arg_3 == 0x72) &&
       (*(int *)(&g_CardSlot_ConvertedManaCost + arg_1 * 0x5b20 + arg_2 * 0x120) != 0)) {
      Mem_AllocOrFree_0041df33
                (1 - arg_1,*(int *)(&g_CardSlot_ConvertedManaCost + arg_1 * 0x5b20 + arg_2 * 0x120),
                 arg_1,arg_2);
      Mem_AllocOrFree_0041df33
                (arg_1,*(int *)(&g_CardSlot_ConvertedManaCost + arg_1 * 0x5b20 + arg_2 * 0x120),
                 arg_1,arg_2);
      for (local_c = 0; local_c < 2; local_c = local_c + 1) {
        for (local_10 = 0; local_10 < (int)(&g_PlayerActiveCardCount)[local_c];
            local_10 = local_10 + 1) {
          iVar1 = FUN_00471c32(local_c,local_10);
          if (iVar1 != 0) {
            uVar3 = FUN_00473179(local_c,local_10,0x34,0xffffffff);
            if ((uVar3 & 0x20) != 0) {
              FUN_0041db67(local_c,local_10,
                           *(int *)(&g_CardSlot_ConvertedManaCost + arg_1 * 0x5b20 + arg_2 * 0x120),
                           arg_1,arg_2);
            }
          }
        }
      }
    }
    if (((arg_3 == 0x77) && (arg_2 == g_OverworldMapGrid)) && (arg_1 == g_OverworldPlayerCoordX)) {
      Pic_Subsystem_0044867e
                (1 - arg_1,*(int *)(&g_CardSlot_ConvertedManaCost + arg_1 * 0x5b20 + arg_2 * 0x120),
                 4);
    }
    uVar2 = 0;
  }
  return uVar2;
}


