/*
 * Decompiled function: Pic_Subsystem_0043bcba
 * Entry Point: 0043bcba
 * Size: 1006 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_0043bcba(int arg_1,int arg_2,int arg_3,int arg_4,int arg_5)

{
  undefined4 uVar1;
  int iVar2;
  uint arg_11;
  undefined4 uVar3;
  uint arg_12;
  undefined4 uVar4;
  uint arg_13;
  undefined4 uVar5;
  undefined4 uVar6;
  int arg_15;
  undefined4 uVar7;
  uint arg_16;
  undefined4 uVar8;
  uint arg_17;
  undefined4 uVar9;
  uint arg_18;
  undefined4 uVar10;
  uint arg_19;
  undefined4 uVar11;
  uint arg_20;
  uint local_8;
  
  if (arg_3 == 0x74) {
    if (g_CurrentTurnPhase == arg_1) {
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      uVar6 = 0xffffffff;
      uVar5 = 0xffffffff;
      uVar4 = 0;
      uVar3 = 0;
      uVar1 = SpellChain_ProcessTriggerEvent(arg_1,arg_2);
      uVar1 = FUN_00403250((int *)0x0,0,arg_1,2,2,0x200,2,0,0,uVar1,uVar3,uVar4,uVar5,uVar6,uVar7,
                           uVar8,uVar9,uVar10,uVar11);
    }
    else if (arg_5 + arg_4 < 0) {
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      uVar6 = 0xffffffff;
      uVar5 = 0xffffffff;
      uVar4 = 0;
      uVar3 = 0;
      uVar1 = SpellChain_ProcessTriggerEvent(arg_1,arg_2);
      uVar1 = FUN_00403250((int *)0x0,0,arg_1,2,2,0x200,2,0,0,uVar1,uVar3,uVar4,uVar5,uVar6,uVar7,
                           uVar8,uVar9,uVar10,uVar11);
    }
    else {
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      uVar6 = 0xffffffff;
      uVar5 = 0xffffffff;
      uVar4 = 0;
      uVar3 = 0;
      uVar1 = SpellChain_ProcessTriggerEvent(arg_1,arg_2);
      uVar1 = FUN_00403250((int *)0x0,0,arg_1,2,2,0x200,2,0,0,uVar1,uVar3,uVar4,uVar5,uVar6,uVar7,
                           uVar8,uVar9,uVar10,uVar11);
    }
  }
  else {
    if (((arg_3 == 0x6c) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
      if (arg_5 + arg_4 < 0) {
        local_8 = 1 - arg_1;
      }
      else {
        local_8 = arg_1;
      }
      iVar2 = CardTarget_PromptTargetCreature(arg_1,local_8,arg_2);
      if (iVar2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        g_SpellStackDepth = g_SpellStackDepth + -0x18;
      }
    }
    if (arg_3 == 0x71) {
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      iVar2 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = SpellChain_ProcessTriggerEvent(arg_1,arg_2);
      iVar2 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + arg_2 * 0x120 + arg_1 * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20),
                         (char *)0x0,arg_1,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,iVar2,arg_15,arg_16,
                         arg_17,arg_18,arg_19,arg_20);
      if (iVar2 == 0) {
        Pic_Subsystem_0044867e(arg_1,arg_2,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] =
             (&g_CardSlot_CombatTarget)[arg_2 * 0x120 + arg_1 * 0x5b20];
        *(undefined4 *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(undefined4 *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20);
      }
      (&g_CardSlot_TurnPlayed)[arg_2 * 0x120 + arg_1 * 0x5b20] = 0;
    }
    if (((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x20) == 0) {
      if (((arg_3 == 0x32) &&
          (*(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) ==
           g_OverworldMapGrid)) &&
         (((char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] == g_OverworldPlayerCoordX
          && (g_OverworldMapGrid != -1)))) {
        g_ActivePalette = g_ActivePalette + arg_4;
      }
      if (((arg_3 == 0x33) &&
          (*(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) ==
           g_OverworldMapGrid)) &&
         (((char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] == g_OverworldPlayerCoordX
          && (g_OverworldMapGrid != -1)))) {
        g_ActivePalette = g_ActivePalette + arg_5;
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}


