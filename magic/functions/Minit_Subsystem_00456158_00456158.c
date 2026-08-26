/*
 * Decompiled function: Minit_Subsystem_00456158
 * Entry Point: 00456158
 * Size: 192 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_00456158(int arg_1,int arg_2,int arg_3)

{
  if (((((char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] == DAT_00679ec8) &&
       (*(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) == DAT_00679ec4)) &&
      (((&g_MasterCardColorTable)[arg_3 * 0x34] & 4) != 0)) &&
     (*(int *)(&DAT_006b3088 + *(int *)(&g_MasterCardTypeTable + arg_3 * 0x34) * 0x98) != 0x6d)) {
    Pic_Subsystem_0044867e(arg_1,arg_2,2);
  }
  return 0;
}


