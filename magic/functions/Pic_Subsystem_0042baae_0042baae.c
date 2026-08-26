/*
 * Decompiled function: Pic_Subsystem_0042baae
 * Entry Point: 0042baae
 * Size: 64 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_0042baae(int arg_1,int arg_2,int arg_3)

{
  if (DAT_00695edc == arg_3) {
    *(int *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(int *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20) + 1;
  }
  return 0;
}


