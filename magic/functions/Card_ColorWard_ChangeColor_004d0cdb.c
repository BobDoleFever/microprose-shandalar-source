/*
 * Decompiled function: Card_ColorWard_ChangeColor
 * Entry Point: 004d0cdb
 * Size: 959 bytes
 */
#include "magic.h"


undefined4 Card_ColorWard_ChangeColor(int arg_1,int arg_2,int arg_3)

{
  bool bVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  byte local_8;
  
  if (((((g_PlayerManaPool == 0xc9) || (arg_3 == 199)) && (arg_2 == g_OverworldMapGrid)) &&
      ((arg_1 == g_OverworldPlayerCoordX && (arg_1 == g_DefendingPlayer)))) &&
     (DAT_006a4b5c == arg_1)) {
    if (arg_3 == 0x7d) {
      g_ActivePalette = g_ActivePalette | 2;
    }
    if ((arg_3 == 0x7e) || (arg_3 == 199)) {
      if (g_IsAiThinking != 1) {
        Magic_UpkeepPhase(0x29);
      }
      iVar2 = FUN_0040a1d2(5);
      local_8 = (byte)(iVar2 + 1);
      (&DAT_006a5f4d)[arg_2 * 0x120 + arg_1 * 0x5b20] = (char)(1 << (local_8 & 0x1f));
      strcpy(&g_OverworldWorldState,s_changes_color_to_0052e874);
      pcVar3 = (char *)Mem_AllocOrFree_00473d7e(iVar2 + 1);
      strcat(&g_OverworldWorldState,pcVar3);
      Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,-1,-1,&g_OverworldWorldState,0);
    }
  }
  if (arg_3 == 0x73) {
    if ((*(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) == 0) &&
       (iVar2 = FUN_0040d949(arg_1,7,2), iVar2 != 0)) {
      uVar4 = 1;
    }
    else {
      uVar4 = 0;
    }
  }
  else {
    if ((arg_3 == 0x6d) && (iVar2 = FUN_0040d949(arg_1,7,2), iVar2 != 0)) {
      Ai_CalcManaRequirement_004ba890(arg_1,0,2);
    }
    if (arg_3 == 0x72) {
      if (*(int *)(&g_CardSlot_CardId +
                  *(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
                  *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120) ==
          -1) {
        g_ActivePlayer = 1;
      }
      else {
        if (g_IsAiThinking != 1) {
          Magic_UpkeepPhase(0x29);
        }
        iVar2 = FUN_0040a1d2(5);
        local_8 = (byte)(iVar2 + 1);
        (&DAT_006a5f4d)
        [*(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
         *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120] =
             (char)(1 << (local_8 & 0x1f));
        strcpy(&g_OverworldWorldState,s_changes_color_to_0052e888);
        pcVar3 = (char *)Mem_AllocOrFree_00473d7e(iVar2 + 1);
        strcat(&g_OverworldWorldState,pcVar3);
        Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,-1,-1,&g_OverworldWorldState,0);
        *(uint *)(&g_CardSlot_ConvertedManaCost +
                 *(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
                 *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120) =
             *(uint *)(&g_CardSlot_ConvertedManaCost +
                      *(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
                      *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120)
             | 1 << ((byte)g_DefendingPlayer & 0x1f);
      }
    }
    if ((arg_2 == g_OverworldMapGrid) && (arg_1 == g_OverworldPlayerCoordX)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
    }
    uVar4 = 0;
  }
  return uVar4;
}


