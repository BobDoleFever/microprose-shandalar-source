/*
 * Decompiled function: Minit_Subsystem_004659d9
 * Entry Point: 004659d9
 * Size: 64 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Minit_Subsystem_004659d9(int arg_1,int arg_2,uint arg_3)

{
  *(uint *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20) =
       (-(uint)(_DAT_0063ee20 == 0) & 0xffffff00) + 0x200 | arg_3;
  return;
}


