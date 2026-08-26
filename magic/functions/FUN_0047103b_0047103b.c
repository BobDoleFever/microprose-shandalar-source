/*
 * Decompiled function: FUN_0047103b
 * Entry Point: 0047103b
 * Size: 2358 bytes
 */
#include "magic.h"


bool FUN_0047103b(int arg1,int arg2)

{
  uint uVar1;
  int iVar2;
  char *pcVar3;
  bool bVar4;
  uint local_28;
  int local_24;
  int local_20;
  uint local_18;
  uint local_14;
  int local_c;
  
  local_c = arg1;
  if (g_ScWillyScore == 4) {
    local_c = DAT_0063edc0;
  }
  if ((g_CurrentTurnPhase != local_c) && (g_IsAiThinking != 1)) {
    Magic_TriggerCardEvent(arg1,arg2,0x90,1 - arg1,0xffffffff);
    strcpy(&g_OverworldWorldState,&DAT_00695e10);
    strcat(&g_OverworldWorldState,s_activates____00525c20);
    iVar2 = FUN_004769c4(arg1,arg2);
    if (iVar2 == 0) {
      if (((((&DAT_0051aed0)[*(int *)(&g_CardSlot_CardId + arg1 * 0x5b20 + arg2 * 0x120) * 0x34] &
            0x18) != 0) && (g_DefendingPlayer == arg1)) && (DAT_0062785c != 0)) {
        strcat(&g_OverworldWorldState,s__with_00525c3c);
        pcVar3 = _itoa(DAT_0062785c,&DAT_00538df8,10);
        strcat(&g_OverworldWorldState,pcVar3);
        strcat(&g_OverworldWorldState,s_mana___00525c44);
      }
    }
    else {
      strcat(&g_OverworldWorldState,s_X_is_00525c30);
      pcVar3 = _itoa(DAT_0062785c,&DAT_00538df8,10);
      strcat(&g_OverworldWorldState,pcVar3);
      strcat(&g_OverworldWorldState,&DAT_00525c38);
    }
    if ((&g_CardSlot_TurnPlayed)[arg1 * 0x5b20 + arg2 * 0x120] == '\0') {
      if (DAT_006fefa8 == 0xffffffff) {
        Ai_Subsystem_004b574d(arg1,arg2,-1,-1,&g_OverworldWorldState,0);
      }
      else {
        Ai_Subsystem_004b574d
                  (arg1,arg2,(int)DAT_006fefa8 >> 8,DAT_006fefa8 & 0xff,&g_OverworldWorldState,0);
      }
    }
    else if ((&g_CardSlot_TurnPlayed)[arg1 * 0x5b20 + arg2 * 0x120] == '\x01') {
      Ai_Subsystem_004b574d
                (arg1,arg2,*(int *)(&g_CardSlot_CombatTarget + arg1 * 0x5b20 + arg2 * 0x120),
                 *(int *)(&g_CardSlot_AttachedAura + arg1 * 0x5b20 + arg2 * 0x120),
                 &g_OverworldWorldState,0);
    }
    else {
      Ai_Subsystem_004b574d(arg1,arg2,-1,-1,&g_OverworldWorldState,0);
    }
  }
  Magic_CombatPhase(arg1,arg2,0x72,arg1,0);
  DAT_00695df8 = 0;
  if (((&g_CardSlot_SpecialState)[arg1 * 0x5b20 + arg2 * 0x120] & 1) == 0) {
    if ((((&g_CardSlot_SpecialState)[arg1 * 0x5b20 + arg2 * 0x120] & 0x10) != 0) &&
       (iVar2 = FUN_00476675(arg1,arg2), iVar2 != 0)) {
      for (local_24 = 0; local_24 < 7; local_24 = local_24 + 1) {
        (&DAT_006b2d40)[local_24] =
             (int)(char)(&DAT_006a603c)[local_24 + arg2 * 0x120 + arg1 * 0x5b20];
      }
      Ai_CalcManaRequirement_004ba890(arg1,0,0);
      if ((g_ActivePlayer == 0) &&
         (Magic_TriggerCardEvent(arg1,arg2,1,1 - arg1,0xffffffff), DAT_006b2e38 == 0)) {
        *(uint *)(&g_CardSlot_SpecialState + arg1 * 0x5b20 + arg2 * 0x120) =
             *(uint *)(&g_CardSlot_SpecialState + arg1 * 0x5b20 + arg2 * 0x120) | 0x40;
      }
      if (g_ActivePlayer != 0) {
        g_ActivePlayer = 0;
        Magic_DiscardToHandSize();
        return false;
      }
      *(uint *)(&g_CardSlot_SpecialState + arg1 * 0x5b20 + arg2 * 0x120) =
           *(uint *)(&g_CardSlot_SpecialState + arg1 * 0x5b20 + arg2 * 0x120) & 0xffffffef;
      *(uint *)(&g_CardSlot_SpecialState + arg1 * 0x5b20 + arg2 * 0x120) =
           *(uint *)(&g_CardSlot_SpecialState + arg1 * 0x5b20 + arg2 * 0x120) | 0x80;
      Magic_MainTurnPhase(1);
      return true;
    }
    iVar2 = FUN_00473e69(arg1,arg2,0x80);
    if (iVar2 == 0) {
      if (((&DAT_0051aed1)[*(int *)(&g_CardSlot_CardId + arg1 * 0x5b20 + arg2 * 0x120) * 0x34] &
          0x10) != 0) {
        DAT_006ff2d4 = -1;
      }
      Ai_Subsystem_004bd4f0();
      uVar1 = *(uint *)(&g_CardSlot_Flags + arg1 * 0x5b20 + arg2 * 0x120);
      Magic_TriggerCardEvent(arg1,arg2,0x6d,1 - arg1,0xffffffff);
      bVar4 = g_ActivePlayer == 1;
      if (bVar4) {
        Ai_Subsystem_004bd5e3(arg1);
        Magic_DiscardToHandSize();
      }
      bVar4 = !bVar4;
      Ai_Util_004bd5af();
      if (bVar4) {
        if (((uVar1 & 0x10) == 0) &&
           (((&g_CardSlot_Flags)[arg1 * 0x5b20 + arg2 * 0x120] & 0x10) != 0)) {
          FUN_00473e69(arg1,arg2,0x81);
        }
        if (*(int *)(&g_CardSlot_CardId + arg1 * 0x5b20 + arg2 * 0x120) == -1) {
          local_28 = *(uint *)(&DAT_0051aed0 +
                              *(int *)(&g_ActiveCardsInPlay + arg1 * 0x5b20 + arg2 * 0x120) * 0x34);
        }
        else {
          local_28 = *(uint *)(&DAT_0051aed0 +
                              *(int *)(&g_CardSlot_CardId + arg1 * 0x5b20 + arg2 * 0x120) * 0x34);
        }
        local_28 = local_28 & 0x1000;
        if ((local_28 == 0) || (DAT_006ff2d4 == -1)) {
          Magic_MainTurnPhase(1);
        }
        else {
          Magic_MainTurnPhase(0);
        }
        if (g_IsAiThinking != 1) {
          if ((((&DAT_0051aed1)[*(int *)(&g_CardSlot_CardId + arg1 * 0x5b20 + arg2 * 0x120) * 0x34]
               & 0x10) == 0) || (DAT_006ff2d4 == -1)) {
            Magic_UpkeepPhase(0x1c);
          }
          else {
            Magic_UpkeepPhase(0x12);
          }
        }
        if (g_IsAiThinking != 1) {
          FUN_004755fd();
        }
      }
    }
    else {
      Magic_DiscardToHandSize();
      bVar4 = false;
    }
    if (bVar4 != false) {
      return bVar4;
    }
    DAT_00695df8 = 0;
    return false;
  }
  bVar4 = true;
  local_20 = 0;
  for (local_18 = 0; (int)local_18 < 7; local_18 = local_18 + 1) {
    (&DAT_006b2d40)[local_18] = (int)(char)(&DAT_006a6048)[local_18 + arg2 * 0x120 + arg1 * 0x5b20];
    if ((0 < (int)local_18) &&
       (iVar2 = FUN_0040d949(arg1,local_18,(&DAT_006b2d40)[local_18]), iVar2 == 0)) {
      bVar4 = false;
    }
    local_20 = local_20 + (&DAT_006b2d40)[local_18];
  }
  iVar2 = FUN_0040d949(local_c,7,local_20);
  if (iVar2 == 0) {
    bVar4 = false;
  }
  local_14 = (uint)!bVar4;
  if ((((&DAT_006a6045)[arg1 * 0x5b20 + arg2 * 0x120] & 1) != 0) ||
     (iVar2 = Ai_Subsystem_004cc56d
                        (local_c,arg1,arg2,-1,-1,s_Pay_Upkeep_costs__Don_t_pay_Upke_00525c4c,
                         local_14), iVar2 == 0)) {
    if (!bVar4) goto LAB_004714f6;
    Ai_CalcManaRequirement_004ba890(local_c,0,0);
    if ((g_ActivePlayer == 0) &&
       (Magic_TriggerCardEvent(arg1,arg2,4,1 - arg1,0xffffffff), DAT_006b2e38 == 0)) {
      *(uint *)(&g_CardSlot_SpecialState + arg1 * 0x5b20 + arg2 * 0x120) =
           *(uint *)(&g_CardSlot_SpecialState + arg1 * 0x5b20 + arg2 * 0x120) | 0x200;
    }
  }
  if (g_ActivePlayer != 0) {
    g_ActivePlayer = 0;
    Magic_DiscardToHandSize();
    return false;
  }
LAB_004714f6:
  for (local_18 = 0; (int)local_18 < 7; local_18 = local_18 + 1) {
    (&DAT_006b2d40)[local_18] = 0;
  }
  *(uint *)(&g_CardSlot_SpecialState + arg1 * 0x5b20 + arg2 * 0x120) =
       *(uint *)(&g_CardSlot_SpecialState + arg1 * 0x5b20 + arg2 * 0x120) & 0xfffffffe;
  *(uint *)(&g_CardSlot_SpecialState + arg1 * 0x5b20 + arg2 * 0x120) =
       *(uint *)(&g_CardSlot_SpecialState + arg1 * 0x5b20 + arg2 * 0x120) | 8;
  Magic_MainTurnPhase(1);
  return true;
}


