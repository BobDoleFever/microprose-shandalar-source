/*
 * Decompiled function: Pic_Subsystem_004414dc
 * Entry Point: 004414dc
 * Size: 686 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_004414dc(int arg_1,int arg_2,int arg_3)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  if (arg_3 == 0x74) {
    uVar2 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
      g_SpellStackDepth = g_SpellStackDepth + (&DAT_0063ee34)[(1 - arg_1) * 8] * 5 + 0x18;
    }
    if (arg_3 == 0x73) {
      if (DAT_006b2d3c == -1) {
        uVar2 = 0;
      }
      else {
        if ((((byte)g_PlayerHandCardCount & 0x20) != 0) &&
           (iVar3 = FUN_0040dcca(arg_1,arg_2,3,2), iVar3 != 0)) {
          uVar10 = 0;
          uVar9 = 0;
          uVar8 = 2;
          uVar7 = 0xffffffff;
          uVar6 = 0xffffffff;
          iVar5 = -1;
          iVar3 = -1;
          uVar4 = 0;
          bVar1 = FUN_0041d9d2(arg_1,arg_2,1);
          iVar3 = Rules_ParseFilter_0040360b
                            (DAT_006b2d3c,DAT_006b2d2c,(char *)0x0,arg_1,2,2,0,0,0,0,0,
                             1 << (bVar1 & 0x1f),uVar4,iVar3,iVar5,uVar6,uVar7,uVar8,uVar9,uVar10);
          if (iVar3 != 0) {
            return 99;
          }
        }
        uVar2 = 0;
      }
    }
    else {
      if (((arg_3 == 0x6d) && (iVar3 = FUN_0040dcca(arg_1,arg_2,3,2), iVar3 != 0)) &&
         ((DAT_006b2d3c != -1 && (Ai_Subsystem_004be192(arg_1,arg_2,3,2), g_ActivePlayer != 1)))) {
        *(int *)(&g_CardSlot_CombatTarget + arg_2 * 0x120 + arg_1 * 0x5b20) = DAT_006b2d3c;
        *(int *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20) = DAT_006b2d2c;
      }
      if (arg_3 == 0x72) {
        uVar10 = 0;
        uVar9 = 0;
        uVar8 = 2;
        uVar7 = 0xffffffff;
        uVar6 = 0xffffffff;
        iVar5 = -1;
        iVar3 = -1;
        uVar4 = 0;
        bVar1 = FUN_0041d9d2(arg_1,arg_2,1);
        iVar3 = Rules_ParseFilter_0040360b
                          (*(int *)(&g_CardSlot_CombatTarget + arg_2 * 0x120 + arg_1 * 0x5b20),
                           *(int *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20),
                           (char *)0x0,arg_1,2,2,0,0,0,0,0,1 << (bVar1 & 0x1f),uVar4,iVar3,iVar5,
                           uVar6,uVar7,uVar8,uVar9,uVar10);
        if (iVar3 == 0) {
          g_ActivePlayer = 1;
        }
        else {
          Pic_Subsystem_0044867e
                    (*(int *)(&g_CardSlot_CombatTarget + arg_2 * 0x120 + arg_1 * 0x5b20),
                     *(int *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20),1);
        }
      }
      uVar2 = 0;
    }
  }
  return uVar2;
}


