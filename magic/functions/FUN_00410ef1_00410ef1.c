/*
 * Decompiled function: FUN_00410ef1
 * Entry Point: 00410ef1
 * Size: 622 bytes
 */
#include "magic.h"


undefined4 FUN_00410ef1(int arg_1,int arg_2,int arg_3)

{
  if (((*(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) == g_OverworldMapGrid)
      && ((char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] == g_OverworldPlayerCoordX))
     && (g_OverworldMapGrid != -1)) {
    if ((((&DAT_006a5f56)[arg_2 * 0x120 + arg_1 * 0x5b20] & 8) != 0) &&
       (*(int *)(&g_CardSlot_TypeFlags + arg_2 * 0x120 + arg_1 * 0x5b20) != -1)) {
      *(ushort *)(&DAT_006a5f48 + arg_2 * 0x120 + arg_1 * 0x5b20) =
           (ushort)*(undefined4 *)
                    (&g_CardSlot_ConvertedManaCost +
                    *(int *)(&g_CardSlot_TypeFlags + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                    (char)(&g_CardSlot_DamageReceived)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) &
           0xff;
      *(ushort *)(&DAT_006a5f4a + arg_2 * 0x120 + arg_1 * 0x5b20) =
           (ushort)((uint)*(undefined4 *)
                           (&g_CardSlot_ConvertedManaCost +
                           *(int *)(&g_CardSlot_TypeFlags + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120
                           + (char)(&g_CardSlot_DamageReceived)[arg_2 * 0x120 + arg_1 * 0x5b20] *
                             0x5b20) >> 8) & 0xff;
    }
    if (arg_3 == 0x32) {
      g_ActivePalette = g_ActivePalette + *(short *)(&DAT_006a5f48 + arg_2 * 0x120 + arg_1 * 0x5b20)
      ;
    }
    if (arg_3 == 0x33) {
      g_ActivePalette = g_ActivePalette + *(short *)(&DAT_006a5f4a + arg_2 * 0x120 + arg_1 * 0x5b20)
      ;
    }
  }
  if ((((&g_CardSlot_Abilities1)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x20) == 0) &&
     ((arg_3 == 0x22 || (arg_3 == 199)))) {
    Pic_Subsystem_0044867e(arg_1,arg_2,1);
  }
  return 0;
}


