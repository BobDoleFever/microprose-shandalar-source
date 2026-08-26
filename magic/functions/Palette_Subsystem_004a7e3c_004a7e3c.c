/*
 * Decompiled function: Palette_Subsystem_004a7e3c
 * Entry Point: 004a7e3c
 * Size: 238 bytes
 */
#include "magic.h"


undefined4 Palette_Subsystem_004a7e3c(int arg_1,int arg_2,int arg_3)

{
  if ((((arg_3 == 0x82) &&
       (*(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) == g_OverworldMapGrid)
       ) && ((char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] ==
             g_OverworldPlayerCoordX)) && (g_OverworldMapGrid != -1)) {
    *(uint *)(&DAT_006a6038 +
             *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
             (char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) =
         *(uint *)(&DAT_006a6038 +
                  *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                  (char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) &
         0xfffffffc;
    Pic_Subsystem_0044867e(arg_1,arg_2,1);
  }
  return 0;
}


