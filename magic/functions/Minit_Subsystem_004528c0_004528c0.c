/*
 * Decompiled function: Minit_Subsystem_004528c0
 * Entry Point: 004528c0
 * Size: 494 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_004528c0(int x,int y,int width,int height)

{
  undefined4 uVar1;
  
  if ((width == 0x71) && (g_IsAiThinking != 1)) {
    Magic_UpkeepPhase(height + 8);
  }
  if (width == 0x73) {
    if ((((&g_CardSlot_Flags)[y * 0x120 + x * 0x5b20] & 0x10) == 0) &&
       ((((&DAT_006a5f3e)[y * 0x120 + x * 0x5b20] & 3) == 0 ||
        (((&g_MasterCardColorTable)[*(int *)(&g_CardSlot_CardId + y * 0x120 + x * 0x5b20) * 0x34] &
         2) == 0)))) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    if (width == 0x6d) {
      FUN_0040d901(x,height,1);
      *(uint *)(&g_CardSlot_Flags + y * 0x120 + x * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + y * 0x120 + x * 0x5b20) | 0x10;
      DAT_006ff2d4 = height;
    }
    if (((width == 0x7f) && (g_OverworldMapGrid == y)) && (x == g_OverworldPlayerCoordX)) {
      if (((((&DAT_006a5f3e)[y * 0x120 + x * 0x5b20] & 3) == 0) ||
          (((&g_MasterCardColorTable)[*(int *)(&g_CardSlot_CardId + y * 0x120 + x * 0x5b20) * 0x34]
           & 2) == 0)) && (((&g_CardSlot_Flags)[y * 0x120 + x * 0x5b20] & 0x10) == 0)) {
        FUN_0040d7e9(x,height,1);
      }
      *(uint *)(&DAT_0063eed0 + x * 4) =
           *(uint *)(&DAT_0063eed0 + x * 4) | 1 << ((byte)height & 0x1f);
    }
    uVar1 = 0;
  }
  return uVar1;
}


