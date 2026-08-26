/*
 * Decompiled function: Card_ClockworkBeast_GetPower
 * Entry Point: 004d6d82
 * Size: 247 bytes
 */
#include "magic.h"


undefined4 Card_ClockworkBeast_GetPower(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  
  if (arg_3 == 0x71) {
    iVar1 = FUN_00410cc0(arg_1,arg_2,DAT_00701000,arg_1,arg_2);
    if (iVar1 != -1) {
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + iVar1 * 0x120 + arg_1 * 0x5b20) = 1;
      *(undefined4 *)(&g_CardSlot_TargetSlot + iVar1 * 0x120 + arg_1 * 0x5b20) = 0x10d;
      *(undefined4 *)(&g_CardSlot_Abilities1 + iVar1 * 0x120 + arg_1 * 0x5b20) = 0x10000;
      (&g_CardSlot_DamageReceived)[arg_2 * 0x120 + arg_1 * 0x5b20] = (undefined1)arg_1;
      *(int *)(&g_CardSlot_TypeFlags + arg_2 * 0x120 + arg_1 * 0x5b20) = iVar1;
    }
  }
  return 0;
}


