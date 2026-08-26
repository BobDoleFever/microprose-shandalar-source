/*
 * Decompiled function: Minit_Subsystem_00459d0a
 * Entry Point: 00459d0a
 * Size: 1041 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_00459d0a(int arg_1,int arg_2,int arg_3)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (((arg_3 == 0x6c) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
    Card_SetCounters(arg_1,arg_2,3);
  }
  if (((arg_3 == 0x32) || (arg_3 == 0x33)) &&
     ((g_OverworldMapGrid == arg_2 && (g_OverworldPlayerCoordX == arg_1)))) {
    iVar2 = Card_GetCounters(arg_1,arg_2);
    g_ActivePalette = g_ActivePalette + iVar2;
  }
  if (arg_3 == 0x73) {
    bVar1 = false;
    if (((g_ScWillyScore == 4) && (g_DefendingPlayer == arg_1)) && (DAT_0063edc0 == arg_1)) {
      iVar2 = Card_GetCounters(arg_1,arg_2);
      if (*(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) < iVar2) {
        bVar1 = true;
      }
      else {
        iVar2 = Minit_Subsystem_0045a120(arg_1,arg_2);
        if (iVar2 != 0) {
          bVar1 = true;
        }
      }
    }
    if (bVar1) {
      if ((g_ActivePlayerPriority == arg_1) && (0 < DAT_006ff550)) {
        DAT_006a4920 = DAT_006a4920 | 3;
      }
      uVar3 = 1;
    }
    else {
      uVar3 = 0;
    }
  }
  else {
    if (((arg_3 == 0x6d) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
      iVar2 = Card_GetCounters(arg_1,arg_2);
      iVar2 = iVar2 - *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20);
      iVar4 = Minit_Subsystem_0045a120(arg_1,arg_2);
      if ((iVar2 == 3) || ((iVar2 != 0 && (iVar4 == 0)))) {
        Minit_Subsystem_0045a252(arg_1,arg_2,iVar2);
      }
      else if ((iVar2 == 0) && (iVar4 != 0)) {
        *(uint *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(uint *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x100;
      }
      else if ((iVar2 != 0) && (iVar4 != 0)) {
        iVar4 = Ai_Subsystem_004cc56d
                          (arg_1,arg_1,arg_2,-1,-1,s_Launch_tetravite__Dock_tetravite_005242e8,0);
        if (iVar4 == 0) {
          Minit_Subsystem_0045a252(arg_1,arg_2,iVar2);
        }
        else {
          *(uint *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20) =
               *(uint *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x100;
        }
      }
    }
    if ((arg_3 == 0x72) &&
       (*(int *)(&g_CardSlot_CardId +
                *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                *(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) != -1)) {
      if (((&DAT_006a5f61)[arg_2 * 0x120 + arg_1 * 0x5b20] & 1) == 0) {
        Minit_Subsystem_0045a42a(arg_1,arg_2);
      }
      else {
        Minit_Subsystem_0045a575(arg_1,arg_2);
      }
    }
    if ((((arg_3 == 0x22) || (arg_3 == 199)) && (g_OverworldMapGrid == arg_2)) &&
       (g_OverworldPlayerCoordX == arg_1)) {
      *(undefined4 *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(undefined4 *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20);
    }
    uVar3 = 0;
  }
  return uVar3;
}


