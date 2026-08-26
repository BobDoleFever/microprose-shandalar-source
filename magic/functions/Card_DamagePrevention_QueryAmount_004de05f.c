/*
 * Decompiled function: Card_DamagePrevention_QueryAmount
 * Entry Point: 004de05f
 * Size: 84 bytes
 */
#include "magic.h"


undefined4 Card_DamagePrevention_QueryAmount(int arg_1,int arg_2,int arg_3)

{
  if ((&DAT_0051aebd)[arg_3 * 0x34] == '\x02') {
    *(uint *)(&g_CardSlot_Abilities2 + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(uint *)(&g_CardSlot_Abilities2 + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x8000000;
  }
  return 1;
}


