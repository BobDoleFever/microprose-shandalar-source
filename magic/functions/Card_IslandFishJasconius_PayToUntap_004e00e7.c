/*
 * Decompiled function: Card_IslandFishJasconius_PayToUntap
 * Entry Point: 004e00e7
 * Size: 718 bytes
 */
#include "magic.h"


undefined4 Card_IslandFishJasconius_PayToUntap(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  
  if (((((arg_3 == 0x84) && (arg_2 == g_OverworldMapGrid)) && (arg_1 == g_OverworldPlayerCoordX)) &&
      ((((&g_CardSlot_Flags)[arg_1 * 0x5b20 + arg_2 * 0x120] & 0x10) != 0 &&
       (arg_1 == g_DefendingPlayer)))) && (arg_1 == DAT_0063edc0)) {
    *(uint *)(&g_CardSlot_SpecialState + arg_1 * 0x5b20 + arg_2 * 0x120) =
         *(uint *)(&g_CardSlot_SpecialState + arg_1 * 0x5b20 + arg_2 * 0x120) | 0x10;
    (&DAT_006a603e)[arg_1 * 0x5b20 + arg_2 * 0x120] =
         (&DAT_006a603e)[arg_1 * 0x5b20 + arg_2 * 0x120] + '\x03';
  }
  if (arg_3 == 1) {
    *(int *)(&DAT_006ff698 + arg_1 * 0x20) = *(int *)(&DAT_006ff698 + arg_1 * 0x20) + 1;
  }
  Card_PirateShip_HasIsland(arg_1,arg_2,arg_3);
  if (((arg_3 == 0x82) && (arg_2 == g_OverworldMapGrid)) && (arg_1 == g_OverworldPlayerCoordX)) {
    *(uint *)(&DAT_006a6038 + arg_1 * 0x5b20 + arg_2 * 0x120) =
         *(uint *)(&DAT_006a6038 + arg_1 * 0x5b20 + arg_2 * 0x120) & 0xfffffffc;
  }
  if (((arg_3 == 0x6c) && (arg_2 == g_OverworldMapGrid)) && (arg_1 == g_OverworldPlayerCoordX)) {
    (&DAT_006a603e)[arg_1 * 0x5b20 + arg_2 * 0x120] =
         (&DAT_006a603e)[arg_1 * 0x5b20 + arg_2 * 0x120] + '\x03';
  }
  if ((((g_PlayerManaPool == 0xca) && (arg_1 == g_DefendingPlayer)) &&
      ((arg_2 == g_OverworldMapGrid &&
       ((arg_1 == g_OverworldPlayerCoordX && (arg_1 == DAT_006a4b5c)))))) &&
     (((&g_CardSlot_Flags)[arg_1 * 0x5b20 + arg_2 * 0x120] & 0x10) != 0)) {
    iVar1 = FUN_0040d949(arg_1,2,3);
    if (iVar1 != 0) {
      if (arg_3 == 0x7d) {
        g_ActivePalette = g_ActivePalette | 1;
      }
      if (arg_3 == 0x7e) {
        iVar1 = Ai_Subsystem_004cc56d
                          (arg_1,arg_1,arg_2,-1,-1,s_Untap_Island_Fish__Don_t_untap__0052edac,0);
        if (iVar1 == 0) {
          Ai_CalcManaRequirement_004ba890(arg_1,2,3);
          if (g_ActivePlayer == 1) {
            g_ActivePlayer = -1;
          }
          else {
            *(uint *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + arg_2 * 0x120) =
                 *(uint *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + arg_2 * 0x120) & 0xffffffef;
          }
        }
      }
    }
  }
  return 0;
}


