/*
 * Decompiled function: Pic_Subsystem_0042ec65
 * Entry Point: 0042ec65
 * Size: 314 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_0042ec65(int arg1,int arg2)

{
  *(int *)(&DAT_006a5f7c +
          *(int *)(&g_CardSlot_OriginalCardId + arg2 * 0x120 + arg1 * 0x5b20) * 0x120 +
          (char)(&g_CardSlot_Toughness)[arg2 * 0x120 + arg1 * 0x5b20] * 0x5b20) =
       *(int *)(&DAT_006a5f7c +
               *(int *)(&g_CardSlot_OriginalCardId + arg2 * 0x120 + arg1 * 0x5b20) * 0x120 +
               (char)(&g_CardSlot_Toughness)[arg2 * 0x120 + arg1 * 0x5b20] * 0x5b20) + 0x100;
  if (g_IsAiThinking != 1) {
    Magic_UpkeepPhase(0x1b);
  }
  *(short *)(&DAT_006a5f4a +
            *(int *)(&g_CardSlot_OriginalCardId + arg2 * 0x120 + arg1 * 0x5b20) * 0x120 +
            (char)(&g_CardSlot_Toughness)[arg2 * 0x120 + arg1 * 0x5b20] * 0x5b20) =
       *(short *)(&DAT_006a5f4a +
                 *(int *)(&g_CardSlot_OriginalCardId + arg2 * 0x120 + arg1 * 0x5b20) * 0x120 +
                 (char)(&g_CardSlot_Toughness)[arg2 * 0x120 + arg1 * 0x5b20] * 0x5b20) + -2;
  return 0;
}


