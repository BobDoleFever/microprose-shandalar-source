/*
 * Decompiled function: FUN_00414f59
 * Entry Point: 00414f59
 * Size: 295 bytes
 */
#include "magic.h"


undefined4 FUN_00414f59(int arg_1,int arg_2,int arg_3)

{
  DAT_006ff4ac = 1;
  DAT_006ff2d4 = 0xffffffff;
  if ((((((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0) &&
       (((&g_MasterCardColorTable)[arg_3 * 0x34] & 1) != 0)) &&
      (((&DAT_0051aed1)[arg_3 * 0x34] & 0x10) != 0)) &&
     ((((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0 &&
      (((&g_MasterCardColorTable)[arg_3 * 0x34] & 1) != 0)))) {
    Magic_TriggerCardEvent(arg_1,arg_2,0x6d,1 - arg_1,0xffffffff);
    if (((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) != 0) {
      FUN_00473e69(arg_1,arg_2,0x81);
    }
  }
  DAT_006ff4ac = 0;
  return 0;
}


