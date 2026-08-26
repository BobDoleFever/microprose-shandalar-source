/*
 * Decompiled function: Minit_Subsystem_004620c3
 * Entry Point: 004620c3
 * Size: 460 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_004620c3(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  
  if (((arg_3 == 0x6c) && (arg_2 == g_OverworldMapGrid)) && (arg_1 == g_OverworldPlayerCoordX)) {
    iVar1 = FUN_0040a305((&g_PlayerCreatureCount)[g_ActivePlayerPriority],1,99);
    g_SpellStackDepth = g_SpellStackDepth + (int)(0x30 / (longlong)iVar1);
  }
  if (((arg_3 == 0x77) && (arg_2 == g_OverworldMapGrid)) &&
     ((arg_1 == g_OverworldPlayerCoordX &&
      ((((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x20) == 0 &&
       ((&DAT_006a5f50)[arg_2 * 0x120 + arg_1 * 0x5b20] != '\x04')))))) {
    iVar1 = Pic_Subsystem_00451291(arg_1,DAT_006ff564);
    if (iVar1 != -1) {
      *(undefined4 *)(&g_ActiveCardsInPlay + iVar1 * 0x120 + arg_1 * 0x5b20) =
           *(undefined4 *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20);
      *(uint *)(&g_CardSlot_Flags + iVar1 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + iVar1 * 0x120 + arg_1 * 0x5b20) | 2;
      *(undefined4 *)(&DAT_006a5f74 + iVar1 * 0x120 + arg_1 * 0x5b20) = 0x200;
      *(undefined4 *)(&DAT_006a5f80 + iVar1 * 0x120 + arg_1 * 0x5b20) = 0xd5;
      (&DAT_006a5f50)[iVar1 * 0x120 + arg_1 * 0x5b20] = 2;
      FUN_00476482(arg_1,iVar1);
    }
  }
  return 0;
}


