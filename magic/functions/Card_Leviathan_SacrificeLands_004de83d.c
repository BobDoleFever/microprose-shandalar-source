/*
 * Decompiled function: Card_Leviathan_SacrificeLands
 * Entry Point: 004de83d
 * Size: 972 bytes
 */
#include "magic.h"


undefined4 Card_Leviathan_SacrificeLands(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  
  if (((arg_3 == 0x6c) && (g_OverworldMapGrid == arg_2)) && (arg_1 == g_OverworldPlayerCoordX)) {
    *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
  }
  if (((arg_3 == 0x82) && (g_OverworldMapGrid == arg_2)) && (arg_1 == g_OverworldPlayerCoordX)) {
    *(uint *)(&DAT_006a6038 + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(uint *)(&DAT_006a6038 + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xfffffffc;
  }
  if (((arg_3 == 0x84) && (g_OverworldMapGrid == arg_2)) &&
     ((arg_1 == g_OverworldPlayerCoordX &&
      (((((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) != 0 &&
        (arg_1 == g_DefendingPlayer)) && (arg_1 == DAT_0063edc0)))))) {
    *(uint *)(&g_CardSlot_SpecialState + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(uint *)(&g_CardSlot_SpecialState + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
  }
  if ((arg_3 == 0x88) &&
     (iVar1 = FUN_0041d963(arg_1,arg_2,2), *(int *)(&DAT_0063ee30 + iVar1 * 4 + arg_1 * 0x20) < 2))
  {
    g_ActivePalette = g_ActivePalette | 1;
  }
  if (arg_3 == 1) {
    iVar1 = Card_Leviathan_PromptLandSacrifice(arg_1,arg_2,1);
    if (iVar1 == 0) {
      g_ActivePalette = g_ActivePalette | 1;
    }
    else {
      *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xffffffef;
    }
  }
  if ((arg_3 == 0x79) && (*(int *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20) == 0)) {
    iVar1 = FUN_0041d963(arg_1,arg_2,2);
    if (*(int *)(&DAT_0063ee30 + iVar1 * 4 + arg_1 * 0x20) < 2) {
      g_ActivePalette = 1;
    }
  }
  else {
    if ((((g_PlayerManaPool == 0xdc) &&
         ((((g_ScWillyScore == 0x15 && (g_OverworldMapGrid == arg_2)) &&
           (arg_1 == g_OverworldPlayerCoordX)) &&
          ((DAT_006a4b5c == g_DefendingPlayer &&
           (*(int *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20) == 0)))))) &&
        (arg_1 == DAT_00695f08)) && (DAT_006b2e14 == arg_2)) {
      iVar1 = FUN_0041d963(arg_1,arg_2,2);
      if (*(int *)(&DAT_0063ee30 + iVar1 * 4 + arg_1 * 0x20) < 2) {
        DAT_0068a65c = 1;
      }
      else {
        if (arg_3 == 0x7d) {
          g_ActivePalette = g_ActivePalette | 2;
        }
        if (arg_3 == 0x7e) {
          iVar1 = Card_Leviathan_PromptLandSacrifice(arg_1,arg_2,0);
          if (iVar1 == 0) {
            DAT_0068a65c = 1;
            g_ActivePlayer = 0;
          }
          else {
            *(undefined4 *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20) = 1;
          }
        }
      }
    }
    if ((arg_3 == 0x22) || (arg_3 == 199)) {
      *(undefined4 *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(undefined4 *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20);
    }
  }
  return 0;
}


