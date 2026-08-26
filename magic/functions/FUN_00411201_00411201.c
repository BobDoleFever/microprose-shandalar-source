/*
 * Decompiled function: FUN_00411201
 * Entry Point: 00411201
 * Size: 269 bytes
 */
#include "magic.h"


undefined4 FUN_00411201(int arg_1,int arg_2,int arg_3)

{
  if (((arg_3 == 0x22) || (arg_3 == 199)) &&
     ((char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] == g_DefendingPlayer)) {
    if (*(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) == 0) {
      *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) + 1;
    }
    else {
      *(uint *)(&g_CardSlot_Abilities1 +
               *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
               (char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) =
           *(uint *)(&g_CardSlot_Abilities1 +
                    *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                    (char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) &
           0xffff7fff;
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
  }
  return 0;
}


