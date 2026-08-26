/*
 * Decompiled function: Palette_Subsystem_004a8d46
 * Entry Point: 004a8d46
 * Size: 658 bytes
 */
#include "magic.h"


undefined4 Palette_Subsystem_004a8d46(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  int arg_1_00;
  int local_50c;
  undefined4 local_508 [320];
  int local_8;
  
  if (arg_3 == 0x74) {
    if ((g_ActivePlayerPriority == arg_1) && (iVar1 = FUN_0040d949(arg_1,7,3), iVar1 == 0)) {
      return 0;
    }
    uVar2 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) =
           g_TurnCounter;
    }
    if (arg_3 == 0x71) {
      for (local_50c = 0;
          local_50c < *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20);
          local_50c = local_50c + 1) {
        iVar1 = FUN_0040a1d2(0x10);
        if (*(int *)(&DAT_0052cb00 + iVar1 * 4) != 0) {
          arg_1_00 = Palette_Subsystem_004a8fd8
                               (arg_1,arg_2,(int)local_508,*(uint *)(&DAT_0052cb00 + iVar1 * 4));
          if (arg_1_00 == 0) {
            g_ActivePlayer = 1;
          }
          else {
            local_8 = FUN_0040a1d2(arg_1_00);
            *(undefined4 *)(&g_CardSlot_CombatTarget + arg_2 * 0x120 + arg_1 * 0x5b20) =
                 local_508[local_8 * 2];
            *(undefined4 *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20) =
                 local_508[local_8 * 2 + 1];
            (&g_CardSlot_TurnPlayed)[arg_2 * 0x120 + arg_1 * 0x5b20] = 1;
          }
        }
        if (g_ActivePlayer == 1) {
          if (g_IsAiThinking != 1) {
            Ai_Util_004cc42d(s_fizzle_0052cbdc);
            Sleep(0x5dc);
            Ai_Util_004cc42d(&DAT_0052cbe4);
          }
          g_ActivePlayer = 0;
        }
        else {
          Palette_Subsystem_004a9137(arg_1,arg_2,iVar1);
        }
      }
      if (g_IsAiThinking != 1) {
        Magic_UpkeepPhase(0x2d);
      }
      (&g_CardSlot_TurnPlayed)[arg_2 * 0x120 + arg_1 * 0x5b20] = 0;
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}


