/*
 * Decompiled function: Minit_Subsystem_0045d028
 * Entry Point: 0045d028
 * Size: 456 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_0045d028(int arg_1,int arg_2,int arg_3)

{
  int arg_4;
  int local_14;
  int local_c;
  
  if (arg_3 == 0x3c) {
    (&DAT_006a604f)[arg_2 * 0x120 + arg_1 * 0x5b20] =
         (&DAT_006a604f)[arg_2 * 0x120 + arg_1 * 0x5b20] | 0x40;
  }
  if (((arg_3 == 0x1a) && (arg_4 = 1 - arg_1, arg_1 == g_DefendingPlayer)) &&
     (((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x44) != 0)) {
    if ((&g_CardSlot_ColorMask)[arg_2 * 0x120 + arg_1 * 0x5b20] == -1) {
      local_14 = arg_2;
    }
    else {
      local_14 = (int)(char)(&g_CardSlot_ColorMask)[arg_2 * 0x120 + arg_1 * 0x5b20];
    }
    for (local_c = 0; local_c < (int)(&g_PlayerActiveCardCount)[arg_4]; local_c = local_c + 1) {
      if ((((char)(&g_CardSlot_ColorMask)[local_c * 0x120 + arg_4 * 0x5b20] == local_14) &&
          ((&DAT_0051aebd)[*(int *)(&g_CardSlot_CardId + local_c * 0x120 + arg_4 * 0x5b20) * 0x34]
           == '\0')) &&
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId + local_c * 0x120 + arg_4 * 0x5b20) * 0x34] & 2) != 0)) {
        FUN_00410cc0(arg_1,arg_2,DAT_006a48e4,arg_4,local_c);
      }
    }
  }
  return 0;
}


