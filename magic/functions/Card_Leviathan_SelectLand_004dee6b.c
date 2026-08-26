/*
 * Decompiled function: Card_Leviathan_SelectLand
 * Entry Point: 004dee6b
 * Size: 343 bytes
 */
#include "magic.h"


undefined4 Card_Leviathan_SelectLand(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  int local_8;
  
  if (((arg_3 == 2) && (arg_2 == g_OverworldMapGrid)) && (arg_1 == g_OverworldPlayerCoordX)) {
    g_ActivePalette = g_ActivePalette | 2;
  }
  if ((arg_2 == g_OverworldMapGrid) && (arg_1 == g_OverworldPlayerCoordX)) {
    iVar1 = CardQuery_PlayerControlsColor(arg_1,1);
    if (iVar1 == 0) {
      Pic_Subsystem_0044867e(arg_1,arg_2,2);
    }
  }
  if ((((arg_3 == 4) && (arg_2 == g_OverworldMapGrid)) && (arg_1 == g_OverworldPlayerCoordX)) ||
     (arg_3 == 199)) {
    strcpy(&g_OverworldWorldState,s_Pick_a_land__0052ed24);
    do {
    } while (local_8 == -1);
    if (local_8 != -1) {
      if (((&DAT_006a5f4c)[local_8 * 0x120 + arg_1 * 0x5b20] & 4) != 0) {
        Mem_AllocOrFree_0041df33(arg_1,3,arg_1,arg_2);
      }
      Pic_Subsystem_0044867e(arg_1,local_8,3);
    }
    iVar1 = CardQuery_PlayerControlsColor(arg_1,1);
    if (iVar1 == 0) {
      Pic_Subsystem_0044867e(arg_1,arg_2,2);
    }
  }
  return 0;
}


