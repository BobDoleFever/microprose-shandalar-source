/*
 * Decompiled function: Pic_Subsystem_0042ac1f
 * Entry Point: 0042ac1f
 * Size: 510 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_0042ac1f(int arg1,int arg2)

{
  if ((arg1 != -1) && (arg2 != -1)) {
    if (((&g_MasterCardColorTable)
         [*(int *)(&g_CardSlot_CardId + arg1 * 0x5b20 + arg2 * 0x120) * 0x34] & 2) != 0) {
      *(int *)(&DAT_006b3010 + arg1 * 4) = *(int *)(&DAT_006b3010 + arg1 * 4) + 1;
    }
    if (((&g_MasterCardColorTable)
         [*(int *)(&g_CardSlot_CardId + arg1 * 0x5b20 + arg2 * 0x120) * 0x34] & 0x40) != 0) {
      (&DAT_006b3018)[arg1] = (&DAT_006b3018)[arg1] + 1;
    }
    if (((&g_MasterCardColorTable)
         [*(int *)(&g_CardSlot_CardId + arg1 * 0x5b20 + arg2 * 0x120) * 0x34] & 4) != 0) {
      *(int *)(&DAT_006b3020 + arg1 * 4) = *(int *)(&DAT_006b3020 + arg1 * 4) + 1;
    }
    (&DAT_006a2828)[arg1] =
         (&DAT_006a2828)[arg1] |
         (uint)(byte)(&g_MasterCardColorTable)
                     [*(int *)(&g_CardSlot_CardId + arg1 * 0x5b20 + arg2 * 0x120) * 0x34];
    *(uint *)(&g_CardSlot_Flags + arg1 * 0x5b20 + arg2 * 0x120) =
         *(uint *)(&g_CardSlot_Flags + arg1 * 0x5b20 + arg2 * 0x120) | 0x30022;
    FUN_00473e69(arg1,arg2,0x6c);
    *(uint *)(&g_CardSlot_Flags + arg1 * 0x5b20 + arg2 * 0x120) =
         *(uint *)(&g_CardSlot_Flags + arg1 * 0x5b20 + arg2 * 0x120) |
         CONCAT31((uint3)((arg1 == 0) - 1 >> 8) & 0x4000,0x80);
    Magic_TriggerCardEvent(arg1,arg2,0x71,1 - arg1,0xffffffff);
    *(uint *)(&g_CardSlot_Flags + arg1 * 0x5b20 + arg2 * 0x120) =
         *(uint *)(&g_CardSlot_Flags + arg1 * 0x5b20 + arg2 * 0x120) & 0xffffffdf;
    DAT_00695f08 = arg1;
    DAT_006b2e14 = arg2;
    FUN_00476205(g_DefendingPlayer,0xdb,s_Card_into_play_00521248,0);
  }
  return 0;
}


