/*
 * Decompiled function: Minit_Subsystem_00465a19
 * Entry Point: 00465a19
 * Size: 92 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint Minit_Subsystem_00465a19(int arg1,int arg2)

{
  _DAT_0063ee20 = (*(int *)(&g_CardSlot_TargetSlot + arg2 * 0x120 + arg1 * 0x5b20) >> 8) + -1;
  return *(uint *)(&g_CardSlot_TargetSlot + arg2 * 0x120 + arg1 * 0x5b20) & 0xff;
}


