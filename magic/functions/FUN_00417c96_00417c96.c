/*
 * Decompiled function: FUN_00417c96
 * Entry Point: 00417c96
 * Size: 674 bytes
 */
#include "magic.h"


undefined4 FUN_00417c96(int arg_1,int arg_2,int arg_3)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 arg_11;
  int iVar7;
  uint uVar8;
  undefined4 arg_13;
  uint uVar9;
  undefined4 arg_14;
  uint uVar10;
  undefined4 arg_15;
  uint uVar11;
  undefined4 arg_16;
  uint uVar12;
  undefined4 arg_17;
  char *arg_18;
  undefined4 arg_18_00;
  undefined4 arg_19;
  int *arg_20;
  int local_c;
  int local_8;
  
  if (arg_3 == 0x74) {
    Ai_GetOpponentPlayerScore(0);
    arg_19 = 0;
    arg_18_00 = 0;
    arg_17 = 0;
    arg_16 = 0xffffffff;
    arg_15 = 0xffffffff;
    arg_14 = 0xffffffff;
    arg_13 = 0xffffffff;
    bVar1 = FUN_0041d9d2(arg_1,arg_2,1);
    iVar4 = 1 << (bVar1 & 0x1f);
    arg_11 = 0;
    uVar2 = SpellChain_ProcessTriggerEvent(arg_1,arg_2);
    uVar2 = FUN_00403250((int *)0x0,0,arg_1,2,2,0x200,2,0x40,0,uVar2,arg_11,iVar4,arg_13,arg_14,
                         arg_15,arg_16,arg_17,arg_18_00,arg_19);
  }
  else {
    if (((arg_3 == 0x6c) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
      arg_20 = &local_c;
      uVar2 = 1;
      arg_18 = s_Target_Creature_00519974;
      uVar12 = 0;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0xffffffff;
      uVar8 = 0xffffffff;
      iVar7 = -1;
      iVar4 = -1;
      bVar1 = FUN_0041d9d2(arg_1,arg_2,1);
      uVar5 = 1 << (bVar1 & 0x1f);
      uVar6 = 0;
      uVar3 = SpellChain_ProcessTriggerEvent(arg_1,arg_2);
      iVar4 = Action_ValidateTarget_00405802
                        (arg_1,2,1 - arg_1,0x200,2,0x40,0,uVar3,uVar6,uVar5,iVar4,iVar7,uVar8,uVar9,
                         uVar10,uVar11,uVar12,arg_18,uVar2,arg_20);
      if (iVar4 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + arg_2 * 0x120 + arg_1 * 0x5b20) = local_c;
        *(int *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20) = local_8;
        (&g_CardSlot_TurnPlayed)[arg_2 * 0x120 + arg_1 * 0x5b20] = 1;
      }
    }
    if (arg_3 == 0x71) {
      local_c = *(int *)(&g_CardSlot_CombatTarget + arg_2 * 0x120 + arg_1 * 0x5b20);
      local_8 = *(int *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20);
      uVar12 = 0;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0xffffffff;
      uVar8 = 0xffffffff;
      iVar7 = -1;
      iVar4 = -1;
      bVar1 = FUN_0041d9d2(arg_1,arg_2,1);
      uVar5 = 1 << (bVar1 & 0x1f);
      uVar6 = 0;
      uVar3 = SpellChain_ProcessTriggerEvent(arg_1,arg_2);
      iVar4 = Rules_ParseFilter_0040360b
                        (local_c,local_8,(char *)0x0,arg_1,2,2,0x200,2,0x40,0,uVar3,uVar6,uVar5,
                         iVar4,iVar7,uVar8,uVar9,uVar10,uVar11,uVar12);
      if (iVar4 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        Pic_Subsystem_0044867e(local_c,local_8,1);
      }
      (&g_CardSlot_TurnPlayed)[arg_2 * 0x120 + arg_1 * 0x5b20] = 0;
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}


