/*
 * Decompiled function: Minit_Subsystem_00461041
 * Entry Point: 00461041
 * Size: 435 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_00461041(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (((arg_3 == 0x6c) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
    g_SpellStackDepth =
         g_SpellStackDepth + *(int *)(&DAT_0063ee4c + g_ActivePlayerPriority * 0x20) * 2;
  }
  if (arg_3 == 0x73) {
    if (((((&DAT_006a5f3e)[arg_2 * 0x120 + arg_1 * 0x5b20] & 3) == 0) ||
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34] & 2) == 0)) &&
       (((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0)) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    if (arg_3 == 0x6d) {
      *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
    }
    if (arg_3 == 0x72) {
      FUN_0040d875(arg_1,0,2);
    }
    if (((arg_3 == 2) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
      g_ActivePalette = g_ActivePalette | 2;
    }
    if (((arg_3 == 4) && (g_OverworldMapGrid == arg_2)) &&
       ((g_OverworldPlayerCoordX == arg_1 && (iVar2 = FUN_0040a1d2(2), iVar2 != 0)))) {
      Mem_AllocOrFree_0041df33(arg_1,3,arg_1,arg_2);
    }
    uVar1 = 0;
  }
  return uVar1;
}


