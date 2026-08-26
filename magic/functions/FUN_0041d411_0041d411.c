/*
 * Decompiled function: FUN_0041d411
 * Entry Point: 0041d411
 * Size: 1173 bytes
 */
#include "magic.h"


undefined4 FUN_0041d411(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint arg_11;
  undefined4 arg_11_00;
  uint arg_12;
  undefined4 arg_12_00;
  uint arg_13;
  undefined4 arg_13_00;
  undefined4 arg_14;
  undefined4 arg_15;
  uint arg_16;
  undefined4 arg_16_00;
  uint arg_17;
  undefined4 arg_17_00;
  uint arg_18;
  undefined4 arg_18_00;
  uint arg_19;
  undefined4 arg_19_00;
  uint arg_20;
  int local_508;
  undefined4 local_504 [320];
  
  if (arg_3 == 0x74) {
    if ((g_ActivePlayerPriority == arg_1) && (iVar1 = FUN_0040d949(arg_1,7,3), iVar1 == 0)) {
      uVar2 = 0;
    }
    else {
      arg_19_00 = 0;
      arg_18_00 = 0;
      arg_17_00 = 0;
      arg_16_00 = 0xffffffff;
      arg_15 = 0xffffffff;
      arg_14 = 0xffffffff;
      arg_13_00 = 0xffffffff;
      arg_12_00 = 0;
      arg_11_00 = 0;
      uVar2 = SpellChain_ProcessTriggerEvent(arg_1,arg_2);
      uVar2 = FUN_00403250((int *)0x0,0,arg_1,2,2,0x200,2,0,0,uVar2,arg_11_00,arg_12_00,arg_13_00,
                           arg_14,arg_15,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
    }
  }
  else {
    if ((((arg_3 == 0x6c) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1))
       && (iVar1 = Palette_Subsystem_004a7bcd(arg_1,arg_2,(int)local_504), iVar1 != 0)) {
      for (local_508 = 0; local_508 < g_TurnCounter; local_508 = local_508 + 1) {
        iVar3 = FUN_0040a1d2(iVar1);
        *(undefined4 *)
         (&g_CardSlot_CombatTarget +
         arg_2 * 0x120 +
         arg_1 * 0x5b20 + (char)(&g_CardSlot_TurnPlayed)[arg_2 * 0x120 + arg_1 * 0x5b20] * 8) =
             local_504[iVar3 * 2];
        *(undefined4 *)
         (&g_CardSlot_AttachedAura +
         arg_2 * 0x120 +
         arg_1 * 0x5b20 + (char)(&g_CardSlot_TurnPlayed)[arg_2 * 0x120 + arg_1 * 0x5b20] * 8) =
             local_504[iVar3 * 2 + 1];
        (&g_CardSlot_TurnPlayed)[arg_2 * 0x120 + arg_1 * 0x5b20] =
             (&g_CardSlot_TurnPlayed)[arg_2 * 0x120 + arg_1 * 0x5b20] + '\x01';
      }
    }
    if (arg_3 == 0x71) {
      if (g_IsAiThinking != 1) {
        Magic_UpkeepPhase(0x2c);
        Sleep(0xdac);
      }
      while ((&g_CardSlot_TurnPlayed)[arg_2 * 0x120 + arg_1 * 0x5b20] != '\0') {
        (&g_CardSlot_TurnPlayed)[arg_2 * 0x120 + arg_1 * 0x5b20] =
             (&g_CardSlot_TurnPlayed)[arg_2 * 0x120 + arg_1 * 0x5b20] + -1;
        arg_20 = 0;
        arg_19 = 0;
        arg_18 = 0;
        arg_17 = 0xffffffff;
        arg_16 = 0xffffffff;
        iVar3 = -1;
        iVar1 = -1;
        arg_13 = 0;
        arg_12 = 0;
        arg_11 = SpellChain_ProcessTriggerEvent(arg_1,arg_2);
        iVar1 = Rules_ParseFilter_0040360b
                          (*(int *)(&g_CardSlot_CombatTarget +
                                   arg_2 * 0x120 +
                                   arg_1 * 0x5b20 +
                                   (char)(&g_CardSlot_TurnPlayed)[arg_2 * 0x120 + arg_1 * 0x5b20] *
                                   8),
                           *(int *)(&g_CardSlot_AttachedAura +
                                   arg_2 * 0x120 +
                                   arg_1 * 0x5b20 +
                                   (char)(&g_CardSlot_TurnPlayed)[arg_2 * 0x120 + arg_1 * 0x5b20] *
                                   8),(char *)0x0,arg_1,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,iVar1,
                           iVar3,arg_16,arg_17,arg_18,arg_19,arg_20);
        if (iVar1 != 0) {
          *(short *)(&DAT_006a5f4a +
                    *(int *)(&g_CardSlot_AttachedAura +
                            arg_2 * 0x120 +
                            arg_1 * 0x5b20 +
                            (char)(&g_CardSlot_TurnPlayed)[arg_2 * 0x120 + arg_1 * 0x5b20] * 8) *
                    0x120 + *(int *)(&g_CardSlot_CombatTarget +
                                    arg_2 * 0x120 +
                                    arg_1 * 0x5b20 +
                                    (char)(&g_CardSlot_TurnPlayed)[arg_2 * 0x120 + arg_1 * 0x5b20] *
                                    8) * 0x5b20) =
               *(short *)(&DAT_006a5f4a +
                         *(int *)(&g_CardSlot_AttachedAura +
                                 arg_2 * 0x120 +
                                 arg_1 * 0x5b20 +
                                 (char)(&g_CardSlot_TurnPlayed)[arg_2 * 0x120 + arg_1 * 0x5b20] * 8)
                         * 0x120 + *(int *)(&g_CardSlot_CombatTarget +
                                           arg_2 * 0x120 +
                                           arg_1 * 0x5b20 +
                                           (char)(&g_CardSlot_TurnPlayed)
                                                 [arg_2 * 0x120 + arg_1 * 0x5b20] * 8) * 0x5b20) +
               -1;
          *(int *)(&DAT_006a5f7c +
                  *(int *)(&g_CardSlot_AttachedAura +
                          arg_2 * 0x120 +
                          arg_1 * 0x5b20 +
                          (char)(&g_CardSlot_TurnPlayed)[arg_2 * 0x120 + arg_1 * 0x5b20] * 8) *
                  0x120 + *(int *)(&g_CardSlot_CombatTarget +
                                  arg_2 * 0x120 +
                                  arg_1 * 0x5b20 +
                                  (char)(&g_CardSlot_TurnPlayed)[arg_2 * 0x120 + arg_1 * 0x5b20] * 8
                                  ) * 0x5b20) =
               *(int *)(&DAT_006a5f7c +
                       *(int *)(&g_CardSlot_AttachedAura +
                               arg_2 * 0x120 +
                               arg_1 * 0x5b20 +
                               (char)(&g_CardSlot_TurnPlayed)[arg_2 * 0x120 + arg_1 * 0x5b20] * 8) *
                       0x120 + *(int *)(&g_CardSlot_CombatTarget +
                                       arg_2 * 0x120 +
                                       arg_1 * 0x5b20 +
                                       (char)(&g_CardSlot_TurnPlayed)
                                             [arg_2 * 0x120 + arg_1 * 0x5b20] * 8) * 0x5b20) +
               0x1000000;
          if (g_IsAiThinking != 1) {
            Magic_UpkeepPhase(0x2b);
          }
        }
      }
      Pic_Subsystem_0044867e(arg_1,arg_2,2);
    }
    uVar2 = 0;
  }
  return uVar2;
}


