/*
 * Decompiled function: Palette_Subsystem_004a771b
 * Entry Point: 004a771b
 * Size: 249 bytes
 */
#include "magic.h"


int Palette_Subsystem_004a771b(int arg_1,int arg_2,undefined4 arg_3)

{
  int iVar1;
  
  iVar1 = FUN_00410cc0(arg_1,arg_2,DAT_006fefac,arg_1,arg_2);
  if (iVar1 != -1) {
    *(uint *)(&g_CardSlot_Abilities1 + iVar1 * 0x120 + arg_1 * 0x5b20) =
         *(uint *)(&g_CardSlot_Abilities1 + iVar1 * 0x120 + arg_1 * 0x5b20) | 0x20;
    *(undefined4 *)(&g_CardSlot_ConvertedManaCost + iVar1 * 0x120 + arg_1 * 0x5b20) = arg_3;
    if (arg_1 != 0) {
      *(uint *)(&g_CardSlot_Flags + iVar1 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + iVar1 * 0x120 + arg_1 * 0x5b20) | 0x1000;
    }
    (&g_CardSlot_DamageReceived)[arg_1 * 0x5b20 + arg_2 * 0x120] = (undefined1)arg_1;
    *(int *)(&g_CardSlot_TypeFlags + arg_1 * 0x5b20 + arg_2 * 0x120) = iVar1;
  }
  return iVar1;
}


