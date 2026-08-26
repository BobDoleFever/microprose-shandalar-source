/*
 * Decompiled function: Ai_Subsystem_004c9f88
 * Entry Point: 004c9f88
 * Size: 243 bytes
 */
#include "magic.h"


undefined4 Ai_Subsystem_004c9f88(int arg_1)

{
  int local_8;
  
  for (local_8 = 0; local_8 < DAT_00559b1c; local_8 = local_8 + 1) {
    *(uint *)(&g_CardSlot_Flags + (1 - arg_1) * 0x5b20 + (&DAT_0055a050)[local_8] * 0x120) =
         *(uint *)(&g_CardSlot_Flags + (1 - arg_1) * 0x5b20 + (&DAT_0055a050)[local_8] * 0x120) &
         0xfffffff7;
  }
  for (local_8 = 0; local_8 < (int)(&g_PlayerActiveCardCount)[arg_1]; local_8 = local_8 + 1) {
    if (((&g_CardSlot_Flags)[arg_1 * 0x5b20 + local_8 * 0x120] & 4) != 0) {
      *(uint *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + local_8 * 0x120) =
           *(uint *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + local_8 * 0x120) & 0xfffffffb;
      *(uint *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + local_8 * 0x120) =
           *(uint *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + local_8 * 0x120) | 0x40;
    }
  }
  return 1;
}


