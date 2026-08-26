/*
 * Decompiled function: FUN_00413a32
 * Entry Point: 00413a32
 * Size: 376 bytes
 */
#include "magic.h"


undefined4 FUN_00413a32(int arg_1,int arg_2,int arg_3)

{
  if (((&g_CardSlot_Abilities1)
       [*(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
        (char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20] & 0x80) != 0) {
    (&DAT_006a5f50)
    [*(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
     (char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20] = 4;
  }
  if ((arg_3 == 0x22) || (arg_3 == 199)) {
    if ((&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] != -1) {
      *(undefined4 *)
       (&g_CardSlot_Abilities2 +
       *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
       (char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) = 0x8000000;
    }
    Pic_Subsystem_0044867e(arg_1,arg_2,1);
  }
  return 0;
}


