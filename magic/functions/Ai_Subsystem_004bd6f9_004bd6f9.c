/*
 * Decompiled function: Ai_Subsystem_004bd6f9
 * Entry Point: 004bd6f9
 * Size: 2684 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Ai_Subsystem_004bd6f9(int arg_1,uint arg_2,int arg_3)

{
  int iVar1;
  uint uVar2;
  char *str_2;
  int local_34;
  uint local_30;
  int local_24;
  uint local_20;
  int local_10;
  byte local_8;
  
  DAT_00695ec8 = arg_2;
LAB_004bd70a:
  while( true ) {
    if (0 < *(int *)(&DAT_0063ee90 + arg_2 * 4 + arg_1 * 0x20)) {
      FUN_0040d8b7(arg_1,arg_2,1);
      DAT_00695ec8 = 0xffffffff;
      return 1;
    }
    local_24 = 0;
    while ((local_24 < 10 && (*(int *)(&DAT_00627a20 + local_24 * 4 + arg_1 * 0x2c) != -1))) {
      if ((0 < *(int *)(&DAT_0063ee90 +
                       (uint)*(ushort *)(&DAT_00627a20 + local_24 * 4 + arg_1 * 0x2c) * 4 +
                       arg_1 * 0x20)) &&
         (*(uint *)(&DAT_00627a20 + local_24 * 4 + arg_1 * 0x2c) >> 0x10 == arg_2)) {
        FUN_0040d8b7(arg_1,(uint)*(ushort *)(&DAT_00627a20 + local_24 * 4 + arg_1 * 0x2c),1);
        DAT_00695ec8 = 0xffffffff;
        return 1;
      }
      local_24 = local_24 + 1;
    }
    if (arg_2 == 6) {
      for (local_20 = 0; (int)local_20 < 7; local_20 = local_20 + 1) {
        if (*(int *)(&DAT_0063ee90 + local_20 * 4 + arg_1 * 0x20) != 0) {
          FUN_0040d8b7(arg_1,local_10,1);
          DAT_00695ec8 = 0xffffffff;
          return 1;
        }
      }
    }
    if (arg_2 == 0) {
      for (local_20 = 0; (int)local_20 < 7; local_20 = local_20 + 1) {
        if ((local_20 != 6) && (*(int *)(&DAT_0063ee90 + local_20 * 4 + arg_1 * 0x20) != 0)) {
          FUN_0040d8b7(arg_1,local_10,1);
          DAT_00695ec8 = 0xffffffff;
          return 1;
        }
      }
    }
    if ((((g_CurrentTurnPhase == arg_1) && (g_IsAiThinking != 1)) && (DAT_00627864 == 0)) &&
       (DAT_006fedc0 == 0)) break;
    if (arg_2 == 0) {
      local_10 = -1;
      for (local_20 = 1; (int)local_20 < 7; local_20 = local_20 + 1) {
        iVar1 = FUN_0040d949(arg_1,local_20,1);
        if (iVar1 != 0) {
          iVar1 = FUN_0040d949(arg_1,local_20,1);
          iVar1 = (iVar1 << 5) / (*(int *)(&DAT_006ff690 + local_20 * 4 + arg_1 * 0x20) * 2 + 1);
          if (local_10 < iVar1) {
            arg_2 = local_20;
            DAT_00695ec8 = local_20;
            local_10 = iVar1;
          }
        }
      }
    }
    local_30 = 0;
    local_24 = 0;
    while ((local_24 < 10 && (*(int *)(&DAT_00627a20 + local_24 * 4 + arg_1 * 0x2c) != -1))) {
      if (*(uint *)(&DAT_00627a20 + local_24 * 4 + arg_1 * 0x2c) >> 0x10 == arg_2) {
        local_8 = (byte)*(undefined2 *)(&DAT_00627a20 + local_24 * 4 + arg_1 * 0x2c);
        local_30 = local_30 | 1 << (local_8 & 0x1f);
      }
      local_24 = local_24 + 1;
    }
    local_20 = 0;
    while( true ) {
      if ((int)(&g_PlayerActiveCardCount)[arg_1] <= (int)local_20) {
        DAT_00695ec8 = 0xffffffff;
        return 0;
      }
      if (((((((&g_CardSlot_Flags)[arg_1 * 0x5b20 + local_20 * 0x120] & 2) != 0) &&
            (((&g_CardSlot_Flags)[arg_1 * 0x5b20 + local_20 * 0x120] & 0x10) == 0)) &&
           (iVar1 = *(int *)(&g_CardSlot_CardId + arg_1 * 0x5b20 + local_20 * 0x120), iVar1 != -1))
          && ((((&g_MasterCardColorTable)[iVar1 * 0x34] & 1) != 0 &&
              (uVar2 = (uint)(char)(&DAT_006a5f4c)[arg_1 * 0x5b20 + local_20 * 0x120], uVar2 != 0)))
          ) && ((((uVar2 & 1 << ((byte)arg_2 & 0x1f)) != 0 ||
                 (((uVar2 & local_30) != 0 || (arg_2 == 0)))) || (arg_2 == 6)))) break;
      local_20 = local_20 + 1;
    }
    Magic_CombatPhase(arg_1,local_20,0x72,arg_1,0);
    DAT_006ff4ac = 1;
    DAT_006ff2d4 = 0xffffffff;
    uVar2 = *(uint *)(&g_CardSlot_Flags + local_34 * 0x120 + arg_1 * 0x5b20);
    _DAT_006b2d28 = iVar1;
    Magic_TriggerCardEvent(arg_1,local_20,0x6d,1 - arg_1,0xffffffff);
    DAT_006ff4ac = 0;
    if (g_ActivePlayer == 1) {
      g_ActivePlayer = 0;
      Magic_DiscardToHandSize();
    }
    else {
      if (((uVar2 & 0x10) == 0) &&
         (((&g_CardSlot_Flags)[local_34 * 0x120 + arg_1 * 0x5b20] & 0x10) != 0)) {
        FUN_00473e69(arg_1,local_20,0x81);
      }
      if (g_IsAiThinking != 1) {
        Magic_UpkeepPhase(0x12);
      }
      Magic_EndTurnPhase();
    }
    _DAT_006b2d28 = 0xffffffff;
  }
  do {
    switch(arg_2) {
    case 0:
      strcpy(&g_OverworldWorldState,s_Tap_any_land__0052d74c);
      break;
    case 1:
      strcpy(&g_OverworldWorldState,s_Tap_a_swamp__0052d6fc);
      break;
    case 2:
      strcpy(&g_OverworldWorldState,s_Tap_an_island__0052d70c);
      break;
    case 3:
      strcpy(&g_OverworldWorldState,s_Tap_a_forest__0052d71c);
      break;
    case 4:
      strcpy(&g_OverworldWorldState,s_Tap_a_mountain__0052d72c);
      break;
    case 5:
      strcpy(&g_OverworldWorldState,s_Tap_a_plains__0052d73c);
    }
    if (arg_3 == 0) {
      strcat(&g_OverworldWorldState,s__or_none__X_is_0052d75c);
      str_2 = _itoa(g_TurnCounter,&DAT_00556c40,10);
      strcat(&g_OverworldWorldState,str_2);
    }
    local_34 = Duel_LogActionStatusBanner(arg_1,arg_1,arg_1,0,0,&g_OverworldWorldState,1);
    if (((local_34 != -1) && (((&g_CardSlot_Flags)[local_34 * 0x120 + arg_1 * 0x5b20] & 2) != 0)) &&
       (((&g_CardSlot_Flags)[local_34 * 0x120 + arg_1 * 0x5b20] & 0x14) == 0)) {
      if (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId + local_34 * 0x120 + arg_1 * 0x5b20) * 0x34] & 1) == 0) {
        if ((((&DAT_0051aed1)
              [*(int *)(&g_CardSlot_CardId + local_34 * 0x120 + arg_1 * 0x5b20) * 0x34] & 0x10) != 0
            ) && (iVar1 = Magic_TriggerCardEvent(arg_1,local_34,0x73,1 - arg_1,0xffffffff),
                 iVar1 != 0)) break;
      }
      else if (((int)(char)(&DAT_006a5f4c)[local_34 * 0x120 + arg_1 * 0x5b20] != 0) &&
              ((((int)(char)(&DAT_006a5f4c)[local_34 * 0x120 + arg_1 * 0x5b20] &
                1 << ((byte)arg_2 & 0x1f)) != 0 || (arg_2 == 0)))) {
        Magic_CombatPhase(arg_1,local_20,0x72,arg_1,0);
        _DAT_006b2d28 = *(int *)(&g_CardSlot_CardId + local_34 * 0x120 + arg_1 * 0x5b20);
        DAT_006ff4ac = 1;
        DAT_006ff2d4 = 0xffffffff;
        uVar2 = *(uint *)(&g_CardSlot_Flags + local_34 * 0x120 + arg_1 * 0x5b20);
        Magic_TriggerCardEvent(arg_1,local_34,0x6d,1 - arg_1,0xffffffff);
        DAT_006ff4ac = 0;
        if (g_ActivePlayer == 1) {
          g_ActivePlayer = 0;
          Magic_DiscardToHandSize();
        }
        else {
          if (((uVar2 & 0x10) == 0) &&
             (((&g_CardSlot_Flags)[local_34 * 0x120 + arg_1 * 0x5b20] & 0x10) != 0)) {
            FUN_00473e69(arg_1,local_34,0x81);
          }
          if (g_IsAiThinking != 1) {
            Magic_UpkeepPhase(0x12);
          }
          Magic_EndTurnPhase();
          Ai_Subsystem_004cc9c5(0,0xff);
        }
        _DAT_006b2d28 = 0xffffffff;
        goto LAB_004bd70a;
      }
    }
    FUN_0040a3e1();
    if (arg_3 == 0) {
      Ai_Subsystem_004cc9c5(0,0xff);
      DAT_00695ec8 = 0xffffffff;
      return 0;
    }
  } while( true );
  Magic_CombatPhase(arg_1,local_20,0x72,arg_1,0);
  _DAT_006b2d28 = *(int *)(&g_CardSlot_CardId + local_34 * 0x120 + arg_1 * 0x5b20);
  DAT_006ff4ac = 1;
  DAT_006ff2d4 = 0xffffffff;
  uVar2 = *(uint *)(&g_CardSlot_Flags + local_34 * 0x120 + arg_1 * 0x5b20);
  Magic_TriggerCardEvent(arg_1,local_34,0x6d,1 - arg_1,0xffffffff);
  DAT_006ff4ac = 0;
  if (g_ActivePlayer == 1) {
    g_ActivePlayer = 0;
    Magic_DiscardToHandSize();
  }
  else {
    if (((uVar2 & 0x10) == 0) &&
       (((&g_CardSlot_Flags)[local_34 * 0x120 + arg_1 * 0x5b20] & 0x10) != 0)) {
      FUN_00473e69(arg_1,local_34,0x81);
    }
    if (g_IsAiThinking != 1) {
      Magic_UpkeepPhase(0x12);
    }
    Magic_EndTurnPhase();
    Ai_Subsystem_004cc9c5(0,0xff);
  }
  _DAT_006b2d28 = 0xffffffff;
  goto LAB_004bd70a;
}


