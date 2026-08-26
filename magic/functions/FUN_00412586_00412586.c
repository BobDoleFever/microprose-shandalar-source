/*
 * Decompiled function: FUN_00412586
 * Entry Point: 00412586
 * Size: 260 bytes
 */
#include "magic.h"


undefined4 FUN_00412586(int arg_1,int arg_2,int arg_3)

{
  if ((arg_3 == 0x21) &&
     (((g_ScWillyScore == 0x1a || (g_ScWillyScore == 0x19)) &&
      (((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId +
                 *(int *)(&g_CardSlot_TypeFlags +
                         g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) * 0x120 +
                 (char)(&g_CardSlot_DamageReceived)
                       [g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120] * 0x5b20) *
         0x34] & 2) != 0)))) {
    *(undefined4 *)
     (&g_CardSlot_ConvertedManaCost + g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120)
         = 0;
  }
  if ((arg_3 == 0x22) || (arg_3 == 199)) {
    Pic_Subsystem_0044867e(arg_1,arg_2,1);
  }
  return 0;
}


