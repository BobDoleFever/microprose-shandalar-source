/*
 * Decompiled function: Pic_Subsystem_0042bfa5
 * Entry Point: 0042bfa5
 * Size: 2442 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_0042bfa5(int x,int y,int width,uint height)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 arg_11;
  int iVar6;
  undefined4 arg_12;
  uint uVar7;
  undefined4 arg_13;
  uint uVar8;
  undefined4 arg_14;
  uint uVar9;
  undefined4 arg_15;
  uint uVar10;
  undefined4 arg_16;
  uint uVar11;
  undefined4 arg_17;
  undefined1 *arg_18;
  undefined4 arg_18_00;
  undefined4 arg_19;
  int *arg_20;
  int local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  if (width == 0x74) {
    arg_19 = 0;
    arg_18_00 = 0;
    arg_17 = 0;
    arg_16 = 0xffffffff;
    arg_15 = 0xffffffff;
    arg_14 = 0xffffffff;
    arg_13 = 0xffffffff;
    arg_12 = 0;
    arg_11 = 0;
    uVar1 = SpellChain_ProcessTriggerEvent(x,y);
    uVar1 = FUN_00403250((int *)0x0,0,x,2,2,0x200,height,0,0,uVar1,arg_11,arg_12,arg_13,arg_14,
                         arg_15,arg_16,arg_17,arg_18_00,arg_19);
  }
  else {
    if (((width == 0x6c) && (g_OverworldMapGrid == y)) && (g_OverworldPlayerCoordX == x)) {
      arg_20 = &local_14;
      uVar1 = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      iVar5 = -1;
      uVar4 = 0;
      uVar3 = 0;
      uVar2 = SpellChain_ProcessTriggerEvent(x,y);
      iVar5 = Action_ValidateTarget_00405802
                        (x,2,1 - x,0x200,height,0,0,uVar2,uVar3,uVar4,iVar5,iVar6,uVar7,uVar8,uVar9,
                         uVar10,uVar11,arg_18,uVar1,arg_20);
      if (iVar5 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + y * 0x120 + x * 0x5b20) = local_14;
        *(undefined4 *)(&g_CardSlot_AttachedAura + y * 0x120 + x * 0x5b20) = local_10;
        (&g_CardSlot_TurnPlayed)[y * 0x120 + x * 0x5b20] = 1;
      }
    }
    if (width == 0x71) {
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      iVar5 = -1;
      uVar4 = 0;
      uVar3 = 0;
      uVar2 = SpellChain_ProcessTriggerEvent(x,y);
      iVar5 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + y * 0x120 + x * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + y * 0x120 + x * 0x5b20),(char *)0x0,x,2
                         ,2,0x200,height,0,0,uVar2,uVar3,uVar4,iVar5,iVar6,uVar7,uVar8,uVar9,uVar10,
                         uVar11);
      if (iVar5 == 0) {
        Pic_Subsystem_0044867e(x,y,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[y * 0x120 + x * 0x5b20] =
             (&g_CardSlot_CombatTarget)[y * 0x120 + x * 0x5b20];
        *(undefined4 *)(&g_CardSlot_OriginalCardId + y * 0x120 + x * 0x5b20) =
             *(undefined4 *)(&g_CardSlot_AttachedAura + y * 0x120 + x * 0x5b20);
        for (local_c = 0; local_c < 2; local_c = local_c + 1) {
          for (local_8 = 0; local_8 < (int)(&g_PlayerActiveCardCount)[local_c];
              local_8 = local_8 + 1) {
            if ((((*(int *)(&g_MasterCardTypeTable +
                           *(int *)(&g_CardSlot_CardId + local_8 * 0x120 + local_c * 0x5b20) * 0x34)
                   == 0x2c) ||
                 (*(int *)(&g_MasterCardTypeTable +
                          *(int *)(&g_CardSlot_CardId + local_8 * 0x120 + local_c * 0x5b20) * 0x34)
                  == 0xea)) &&
                ((((&g_CardSlot_Flags)[local_8 * 0x120 + local_c * 0x5b20] & 2) != 0 &&
                 (((&g_CardSlot_Toughness)[local_8 * 0x120 + local_c * 0x5b20] ==
                   (&g_CardSlot_Toughness)[y * 0x120 + x * 0x5b20] &&
                  (*(int *)(&g_CardSlot_OriginalCardId + local_8 * 0x120 + local_c * 0x5b20) ==
                   *(int *)(&g_CardSlot_OriginalCardId + y * 0x120 + x * 0x5b20))))))) &&
               (((&DAT_006a5f6b)[local_8 * 0x120 + local_c * 0x5b20] & 1) != 0)) {
              *(uint *)(&g_CardSlot_Abilities1 + local_8 * 0x120 + local_c * 0x5b20) =
                   *(uint *)(&g_CardSlot_Abilities1 + local_8 * 0x120 + local_c * 0x5b20) &
                   0xfeffffff;
              (&g_CardSlot_DamageReceived)[y * 0x120 + x * 0x5b20] = (undefined1)local_c;
              *(int *)(&g_CardSlot_TypeFlags + y * 0x120 + x * 0x5b20) = local_8;
            }
          }
        }
        *(uint *)(&g_CardSlot_Abilities1 + y * 0x120 + x * 0x5b20) =
             *(uint *)(&g_CardSlot_Abilities1 + y * 0x120 + x * 0x5b20) | 0x1000000;
        if (*(int *)(&g_CardSlot_CombatTarget + y * 0x120 + x * 0x5b20) != x) {
          local_8 = Pic_Subsystem_0042ca53
                              ((int)(char)(&g_CardSlot_Toughness)[y * 0x120 + x * 0x5b20],
                               *(int *)(&g_CardSlot_OriginalCardId + y * 0x120 + x * 0x5b20));
          (&g_CardSlot_Toughness)[y * 0x120 + x * 0x5b20] = (undefined1)x;
          *(int *)(&g_CardSlot_OriginalCardId + y * 0x120 + x * 0x5b20) = local_8;
        }
      }
      (&g_CardSlot_TurnPlayed)[y * 0x120 + x * 0x5b20] = 0;
    }
    if (((((g_PlayerManaPool == 0xd4) && (g_OverworldMapGrid == y)) &&
         (g_OverworldPlayerCoordX == x)) &&
        (((&g_CardSlot_Toughness)[y * 0x120 + x * 0x5b20] != -1 &&
         (*(int *)(&g_CardSlot_CardId +
                  *(int *)(&g_CardSlot_OriginalCardId + y * 0x120 + x * 0x5b20) * 0x120 +
                  (char)(&g_CardSlot_Toughness)[y * 0x120 + x * 0x5b20] * 0x5b20) != -1)))) &&
       ((DAT_00695f08 == x && ((DAT_006b2e14 == y && (x == DAT_006a4b5c)))))) {
      if (width == 0x7d) {
        g_ActivePalette = g_ActivePalette | 2;
      }
      if (width == 0x7e) {
        if (((&DAT_006a5f6b)[y * 0x120 + x * 0x5b20] & 1) == 0) {
          CardQuery_ForEachPermanent(Pic_Subsystem_0042c92f,-1);
        }
        else if ((&g_CardSlot_DamageReceived)[y * 0x120 + x * 0x5b20] == -1) {
          if ((*(int *)(&g_CardSlot_CardId +
                       *(int *)(&g_CardSlot_OriginalCardId + y * 0x120 + x * 0x5b20) * 0x120 +
                       (char)(&g_CardSlot_Toughness)[y * 0x120 + x * 0x5b20] * 0x5b20) != -1) &&
             (((((&DAT_006a5f3e)
                 [*(int *)(&g_CardSlot_OriginalCardId + y * 0x120 + x * 0x5b20) * 0x120 +
                  (char)(&g_CardSlot_Toughness)[y * 0x120 + x * 0x5b20] * 0x5b20] & 0x40) != 0 &&
               ((char)(&g_CardSlot_Toughness)[y * 0x120 + x * 0x5b20] == g_CurrentTurnPhase)) ||
              ((((&DAT_006a5f3e)
                 [*(int *)(&g_CardSlot_OriginalCardId + y * 0x120 + x * 0x5b20) * 0x120 +
                  (char)(&g_CardSlot_Toughness)[y * 0x120 + x * 0x5b20] * 0x5b20] & 0x40) == 0 &&
               ((char)(&g_CardSlot_Toughness)[y * 0x120 + x * 0x5b20] == g_ActivePlayerPriority)))))
             ) {
            Pic_Subsystem_0042ca53
                      ((int)(char)(&g_CardSlot_Toughness)[y * 0x120 + x * 0x5b20],
                       *(int *)(&g_CardSlot_OriginalCardId + y * 0x120 + x * 0x5b20));
          }
        }
        else {
          *(uint *)(&g_CardSlot_Abilities1 +
                   *(int *)(&g_CardSlot_TypeFlags + y * 0x120 + x * 0x5b20) * 0x120 +
                   (char)(&g_CardSlot_DamageReceived)[y * 0x120 + x * 0x5b20] * 0x5b20) =
               *(uint *)(&g_CardSlot_Abilities1 +
                        *(int *)(&g_CardSlot_TypeFlags + y * 0x120 + x * 0x5b20) * 0x120 +
                        (char)(&g_CardSlot_DamageReceived)[y * 0x120 + x * 0x5b20] * 0x5b20) |
               0x1000000;
          if ((&g_CardSlot_DamageReceived)[y * 0x120 + x * 0x5b20] !=
              (&g_CardSlot_Toughness)[y * 0x120 + x * 0x5b20]) {
            Pic_Subsystem_0042ca53
                      ((int)(char)(&g_CardSlot_Toughness)[y * 0x120 + x * 0x5b20],
                       *(int *)(&g_CardSlot_OriginalCardId + y * 0x120 + x * 0x5b20));
          }
        }
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}


