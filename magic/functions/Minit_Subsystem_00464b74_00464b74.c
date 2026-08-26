/*
 * Decompiled function: Minit_Subsystem_00464b74
 * Entry Point: 00464b74
 * Size: 1108 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_00464b74(int x,int y,int width,int height)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  if (((width == 0x6c) && (y == g_OverworldMapGrid)) && (x == g_OverworldPlayerCoordX)) {
    Card_SetCounters(x,y,height);
  }
  if ((((g_PlayerManaPool == 0xcc) && (iVar2 = Card_GetCounters(x,y), iVar2 != 0)) &&
      ((y == g_OverworldMapGrid && ((x == g_OverworldPlayerCoordX && (DAT_006a4b5c == x)))))) &&
     ((((&g_CardSlot_Flags)[y * 0x120 + x * 0x5b20] & 4) != 0 ||
      (((&g_CardSlot_ColorMask)[y * 0x120 + x * 0x5b20] != -1 && (x != g_DefendingPlayer)))))) {
    if (width == 0x7d) {
      g_ActivePalette = g_ActivePalette | 2;
    }
    if (width == 0x7e) {
      Card_DecrementCounter(x,y);
    }
  }
  if (((width == 0x32) && (y == g_OverworldMapGrid)) && (x == g_OverworldPlayerCoordX)) {
    iVar2 = Card_GetCounters(x,y);
    g_ActivePalette = g_ActivePalette + iVar2;
  }
  uVar1 = g_OverworldPlayerCoordY;
  if (((width == 0x73) && (g_ScWillyScore == 4)) &&
     ((x == g_DefendingPlayer &&
      ((((&g_CardSlot_Flags)[y * 0x120 + x * 0x5b20] & 0x10) == 0 && (DAT_0063edc0 == x)))))) {
    iVar2 = Card_GetCounters(x,y);
    if ((iVar2 < height) && (iVar2 = FUN_0040d949(x,7,1), iVar2 != 0)) {
      return 1;
    }
  }
  else if (width == 0x90) {
    iVar2 = FUN_0040d949(x,7,1);
    iVar5 = 0;
    iVar3 = Card_GetCounters(x,y);
    DAT_0062785c = FUN_0040a305(height - iVar3,iVar5,iVar2);
  }
  else {
    if (((width == 0x6d) && (y == g_OverworldMapGrid)) && (x == g_OverworldPlayerCoordX)) {
      iVar2 = Card_GetCounters(x,y);
      g_OverworldPlayerCoordY = height - iVar2;
      if (x == g_CurrentTurnPhase) {
        uVar4 = Ai_CalcManaRequirement_004ba890(x,0,-1);
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + y * 0x120 + x * 0x5b20) = uVar4;
      }
      else {
        iVar2 = FUN_0040d949(x,7,1);
        iVar5 = 0;
        iVar3 = Card_GetCounters(x,y);
        iVar2 = FUN_0040a305(height - iVar3,iVar5,iVar2);
        uVar4 = Ai_CalcManaRequirement_004ba890(x,0,iVar2);
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + y * 0x120 + x * 0x5b20) = uVar4;
      }
      g_OverworldPlayerCoordY = uVar1;
      if (g_ActivePlayer == 1) {
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + y * 0x120 + x * 0x5b20) = 0;
      }
      else {
        *(uint *)(&g_CardSlot_Flags + y * 0x120 + x * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags + y * 0x120 + x * 0x5b20) | 0x10;
      }
    }
    if ((width == 0x72) &&
       (*(int *)(&g_CardSlot_CardId +
                *(int *)(&g_CardSlot_SicknessState + y * 0x120 + x * 0x5b20) * 0x120 +
                *(int *)(&g_CardSlot_TapState + y * 0x120 + x * 0x5b20) * 0x5b20) != -1)) {
      iVar5 = 0;
      iVar2 = *(int *)(&g_CardSlot_ConvertedManaCost + y * 0x120 + x * 0x5b20);
      iVar3 = Card_GetCounters(g_DialogPromptHwnd,g_DuelArenaHwnd);
      iVar2 = FUN_0040a305(iVar2 + iVar3,iVar5,height);
      Card_SetCounters(g_DialogPromptHwnd,g_DuelArenaHwnd,iVar2);
    }
  }
  return 0;
}


