/*
 * Decompiled function: Minit_Subsystem_00463c10
 * Entry Point: 00463c10
 * Size: 193 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_00463c10(int arg_1,int arg_2,int arg_3)

{
  if ((((&g_CardSlot_Flags)[arg_1 * 0x5b20 + arg_2 * 0x120] & 2) != 0) &&
     (((&g_MasterCardColorTable)[arg_3 * 0x34] & 2) != 0)) {
    Pic_Subsystem_0044867e(arg_1,arg_2,2);
  }
  Pic_Subsystem_004488a0();
  if ((((&g_CardSlot_Flags)[arg_1 * 0x5b20 + arg_2 * 0x120] & 2) != 0) &&
     (((&g_MasterCardColorTable)[arg_3 * 0x34] & 0x44) != 0)) {
    Pic_Subsystem_0044867e(arg_1,arg_2,2);
  }
  return 0;
}


