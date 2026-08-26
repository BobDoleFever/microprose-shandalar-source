/*
 * Decompiled function: Minit_Subsystem_00456218
 * Entry Point: 00456218
 * Size: 477 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_00456218(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  
  if ((arg_3 == 0x71) && (g_IsAiThinking != 1)) {
    Magic_UpkeepPhase(8);
  }
  if (arg_3 == 0x73) {
    if ((((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0) &&
       ((((&DAT_006a5f3e)[arg_2 * 0x120 + arg_1 * 0x5b20] & 3) == 0 ||
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34] & 2) == 0)))) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    if (arg_3 == 0x6d) {
      FUN_0040d901(arg_1,6,3);
      *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
      DAT_006ff2d4 = 6;
    }
    if (((arg_3 == 0x7f) && (arg_2 == g_OverworldMapGrid)) && (arg_1 == g_OverworldPlayerCoordX)) {
      if (((((&DAT_006a5f3e)[arg_2 * 0x120 + arg_1 * 0x5b20] & 3) == 0) ||
          (((&g_MasterCardColorTable)
            [*(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34] & 2) == 0)) &&
         (((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0)) {
        FUN_0040d7e9(arg_1,6,3);
      }
      *(uint *)(&DAT_0063eed0 + arg_1 * 4) = *(uint *)(&DAT_0063eed0 + arg_1 * 4) | 0x40;
    }
    uVar1 = 0;
  }
  return uVar1;
}


