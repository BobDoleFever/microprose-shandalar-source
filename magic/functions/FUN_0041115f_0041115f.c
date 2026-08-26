/*
 * Decompiled function: FUN_0041115f
 * Entry Point: 0041115f
 * Size: 162 bytes
 */
#include "magic.h"


undefined4 FUN_0041115f(int arg_1,int arg_2,int arg_3)

{
  if (((arg_3 == 0x78) &&
      (*(int *)(&g_CardSlot_OriginalCardId + arg_1 * 0x5b20 + arg_2 * 0x120) == DAT_006b2d5c)) &&
     ((char)(&g_CardSlot_Toughness)[arg_1 * 0x5b20 + arg_2 * 0x120] == DAT_007006c8)) {
    g_ActivePalette = g_ActivePalette + 1;
  }
  if ((arg_3 == 0x22) || (arg_3 == 199)) {
    Pic_Subsystem_0044867e(arg_1,arg_2,1);
  }
  return 0;
}


