/*
 * Decompiled function: Card_NetherShadow_CountCreaturesAbove
 * Entry Point: 004e3185
 * Size: 366 bytes
 */
#include "magic.h"


undefined4 Card_NetherShadow_CountCreaturesAbove(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  
  if (((arg_3 == 0x6c) && (g_OverworldMapGrid == arg_2)) && (arg_1 == g_OverworldPlayerCoordX)) {
    *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xfffcffff;
  }
  if ((arg_3 == 0x8d) ||
     (((arg_3 == 0x77 && (g_OverworldMapGrid == arg_2)) &&
      ((arg_1 == g_OverworldPlayerCoordX &&
       ((((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x20) == 0 &&
        ((&DAT_006a5f50)[arg_2 * 0x120 + arg_1 * 0x5b20] != '\x04')))))))) {
    iVar1 = Pic_Subsystem_00451291(arg_1,DAT_006a28b4);
    if (iVar1 != -1) {
      *(uint *)(&g_CardSlot_Flags + iVar1 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + iVar1 * 0x120 + arg_1 * 0x5b20) | 2;
      *(undefined4 *)(&DAT_006a5f74 + iVar1 * 0x120 + arg_1 * 0x5b20) =
           *(undefined4 *)
            (&g_MasterCardTypeTable +
            *(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34);
    }
  }
  return 0;
}


