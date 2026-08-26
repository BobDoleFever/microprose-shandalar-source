/*
 * Decompiled function: Pic_Subsystem_004397e3
 * Entry Point: 004397e3
 * Size: 938 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_004397e3(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_c;
  int local_8;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (arg_3 == 0x6a) {
      *(undefined4 *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
      for (local_c = 0; local_c < (int)(&g_PlayerActiveCardCount)[g_DefendingPlayer];
          local_c = local_c + 1) {
        iVar2 = FUN_00471c32(g_DefendingPlayer,local_c);
        if (((iVar2 != 0) &&
            (((&g_CardSlot_Flags)[local_c * 0x120 + g_DefendingPlayer * 0x5b20] & 0x10) == 0)) &&
           (((&g_MasterCardColorTable)
             [*(int *)(&g_CardSlot_CardId + local_c * 0x120 + g_DefendingPlayer * 0x5b20) * 0x34] &
            1) != 0)) {
          *(int *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20) =
               *(int *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20) + 1;
        }
      }
    }
    if (arg_3 == 0x73) {
      if (((g_ScWillyScore == 4) &&
          (((&g_CardSlot_ConvertedManaCost)[arg_2 * 0x120 + arg_1 * 0x5b20] & 1) == 0)) &&
         (g_DefendingPlayer == DAT_0063edc0)) {
        *(uint *)(&g_CardSlot_SpecialState + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(uint *)(&g_CardSlot_SpecialState + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x101;
        DAT_006a4920 = DAT_006a4920 | 3;
        uVar1 = 1;
      }
      else {
        uVar1 = 0;
      }
    }
    else {
      if (((arg_3 == 4) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
        *(uint *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(uint *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) | 1;
        DAT_00695df8 = 1;
        g_ActivePalette = g_ActivePalette | 1;
      }
      if (arg_3 == 0x86) {
        Mem_AllocOrFree_0041df33
                  (g_DefendingPlayer,
                   *(int *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20),arg_1,arg_2);
        *(undefined4 *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
      }
      if (arg_3 == 0x22) {
        *(uint *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(uint *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xfffffffe;
      }
      if (arg_3 == 199) {
        local_8 = 0;
        for (local_c = 0; local_c < (int)(&g_PlayerActiveCardCount)[1 - g_DefendingPlayer];
            local_c = local_c + 1) {
          iVar2 = FUN_00471c32(1 - g_DefendingPlayer,local_c);
          if (((iVar2 != 0) &&
              (((&g_CardSlot_Flags)[local_c * 0x120 + (1 - g_DefendingPlayer) * 0x5b20] & 0x10) == 0
              )) && (((&g_MasterCardColorTable)
                      [*(int *)(&g_CardSlot_CardId +
                               local_c * 0x120 + (1 - g_DefendingPlayer) * 0x5b20) * 0x34] & 1) != 0
                    )) {
            local_8 = local_8 + 1;
          }
        }
        Mem_AllocOrFree_0041df33(1 - g_DefendingPlayer,local_8,arg_1,arg_2);
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}


