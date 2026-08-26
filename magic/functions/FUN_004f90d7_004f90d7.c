/*
 * Decompiled function: FUN_004f90d7
 * Entry Point: 004f90d7
 * Size: 540 bytes
 */
#include "magic.h"


undefined4 FUN_004f90d7(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int local_c;
  int local_8;
  
  if (arg_3 == 0x74) {
    if ((arg_1 == g_ActivePlayerPriority) && (iVar1 = FUN_0040d949(arg_1,7,2), iVar1 == 0)) {
      return 0;
    }
    uVar2 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (arg_2 == g_OverworldMapGrid)) && (arg_1 == g_OverworldPlayerCoordX)) {
      iVar1 = FUN_004fa423(arg_1,*(int *)(&g_CardSlot_CardId + arg_1 * 0x5b20 + arg_2 * 0x120));
      g_SpellStackDepth = g_SpellStackDepth - (int)(0x24 / (longlong)iVar1);
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_1 * 0x5b20 + arg_2 * 0x120) =
           g_TurnCounter;
    }
    if (arg_3 == 0x71) {
      for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
        Mem_AllocOrFree_0041df33
                  (local_8,*(int *)(&g_CardSlot_ConvertedManaCost + arg_1 * 0x5b20 + arg_2 * 0x120),
                   arg_1,arg_2);
        for (local_c = 0; local_c < (int)(&g_PlayerActiveCardCount)[local_8]; local_c = local_c + 1)
        {
          iVar1 = FUN_00471c32(local_8,local_c);
          if (((iVar1 != 0) &&
              (((&g_MasterCardColorTable)
                [*(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) * 0x34] & 2) != 0
              )) && (uVar3 = FUN_00473179(local_8,local_c,0x34,0xffffffff), (uVar3 & 0x20) == 0)) {
            FUN_0041db67(local_8,local_c,
                         *(int *)(&g_CardSlot_ConvertedManaCost + arg_1 * 0x5b20 + arg_2 * 0x120),
                         arg_1,arg_2);
          }
        }
      }
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}


