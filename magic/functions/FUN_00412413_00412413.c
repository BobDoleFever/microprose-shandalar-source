/*
 * Decompiled function: FUN_00412413
 * Entry Point: 00412413
 * Size: 371 bytes
 */
#include "magic.h"


undefined4 FUN_00412413(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  
  if ((((arg_3 == 0x32) &&
       (*(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) == g_OverworldMapGrid)
       ) && ((char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] ==
             g_OverworldPlayerCoordX)) && (g_OverworldMapGrid != -1)) {
    iVar1 = FUN_00471c32((int)(char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20],
                         *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20));
    if ((iVar1 != 0) &&
       (((&g_MasterCardColorTable)
         [*(int *)(&g_CardSlot_CardId +
                  *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                  (char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) * 0x34] &
        2) != 0)) {
      g_ActivePalette = g_ActivePalette + -2;
    }
  }
  if ((arg_3 == 0x22) || (arg_3 == 199)) {
    Pic_Subsystem_0044867e(arg_1,arg_2,1);
  }
  return 0;
}


