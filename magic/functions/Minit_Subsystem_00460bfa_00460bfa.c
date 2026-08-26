/*
 * Decompiled function: Minit_Subsystem_00460bfa
 * Entry Point: 00460bfa
 * Size: 1095 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_00460bfa(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  
  if (((arg_3 == 0x82) && (arg_2 == g_OverworldMapGrid)) && (arg_1 == g_OverworldPlayerCoordX)) {
    *(uint *)(&DAT_006a6038 + arg_1 * 0x5b20 + arg_2 * 0x120) =
         *(uint *)(&DAT_006a6038 + arg_1 * 0x5b20 + arg_2 * 0x120) & 0xfffffffc;
  }
  if ((((arg_3 == 0x84) && (arg_2 == g_OverworldMapGrid)) &&
      ((arg_1 == g_OverworldPlayerCoordX &&
       ((((&g_CardSlot_Flags)[arg_1 * 0x5b20 + arg_2 * 0x120] & 0x10) != 0 &&
        (arg_1 == g_DefendingPlayer)))))) && (arg_1 == DAT_0063edc0)) {
    *(uint *)(&g_CardSlot_SpecialState + arg_1 * 0x5b20 + arg_2 * 0x120) =
         *(uint *)(&g_CardSlot_SpecialState + arg_1 * 0x5b20 + arg_2 * 0x120) | 0x10;
    (&DAT_006a603c)[arg_1 * 0x5b20 + arg_2 * 0x120] =
         (&DAT_006a603c)[arg_1 * 0x5b20 + arg_2 * 0x120] + '\x04';
  }
  if (((arg_3 == 1) && (arg_2 == g_OverworldMapGrid)) && (arg_1 == g_OverworldPlayerCoordX)) {
    *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_1 * 0x5b20 + arg_2 * 0x120) = 1;
  }
  if (((arg_3 == 0x6c) && (arg_2 == g_OverworldMapGrid)) && (arg_1 == g_OverworldPlayerCoordX)) {
    g_SpellStackDepth = g_SpellStackDepth + 0xc;
  }
  if (arg_3 == 0x73) {
    if (((((&DAT_006a5f3e)[arg_1 * 0x5b20 + arg_2 * 0x120] & 3) == 0) ||
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x34] & 2) == 0)) &&
       (((&g_CardSlot_Flags)[arg_1 * 0x5b20 + arg_2 * 0x120] & 0x10) == 0)) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    if (arg_3 == 0x6d) {
      FUN_0040d901(arg_1,0,3);
      *(uint *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + arg_2 * 0x120) =
           *(uint *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + arg_2 * 0x120) | 0x10;
      DAT_006ff2d4 = 0;
    }
    if (((g_PlayerManaPool == 0xcb) || (arg_3 == 199)) &&
       ((arg_2 == g_OverworldMapGrid &&
        ((((arg_1 == g_OverworldPlayerCoordX && (arg_1 == g_DefendingPlayer)) &&
          (arg_1 == DAT_006a4b5c)) &&
         ((((&g_CardSlot_Flags)[arg_1 * 0x5b20 + arg_2 * 0x120] & 0x10) != 0 &&
          (*(int *)(&g_CardSlot_ConvertedManaCost + arg_1 * 0x5b20 + arg_2 * 0x120) == 0)))))))) {
      if (arg_3 == 0x7d) {
        g_ActivePalette = g_ActivePalette | 2;
      }
      if ((arg_3 == 0x7e) || (arg_3 == 199)) {
        Mem_AllocOrFree_0041df33(arg_1,1,arg_1,arg_2);
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_1 * 0x5b20 + arg_2 * 0x120) = 0;
      }
    }
    if (((arg_3 == 199) && (*(int *)(&DAT_0063ee4c + arg_1 * 0x20) < 4)) &&
       (((&g_CardSlot_Flags)[arg_1 * 0x5b20 + arg_2 * 0x120] & 0x10) != 0)) {
      (&g_PlayerCreatureCount)[arg_1] =
           (&g_PlayerCreatureCount)[arg_1] - (4 - *(int *)(&DAT_0063ee4c + arg_1 * 0x20));
    }
    if (((arg_3 == 0x7f) && (arg_2 == g_OverworldMapGrid)) &&
       ((arg_1 == g_OverworldPlayerCoordX &&
        (((&g_CardSlot_Flags)[arg_1 * 0x5b20 + arg_2 * 0x120] & 0x10) == 0)))) {
      FUN_0040d7e9(arg_1,0,3);
    }
    uVar1 = 0;
  }
  return uVar1;
}


