/*
 * Decompiled function: Ai_Subsystem_004cad65
 * Entry Point: 004cad65
 * Size: 96 bytes
 */
#include "magic.h"


void Ai_Subsystem_004cad65(int arg_1,int arg_2,int arg_3)

{
  if (arg_3 == 0) {
    *(uint *)(&g_CardSlot_Abilities1 + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(uint *)(&g_CardSlot_Abilities1 + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xfffdffff;
  }
  else {
    *(uint *)(&g_CardSlot_Abilities1 + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(uint *)(&g_CardSlot_Abilities1 + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x20000;
  }
  return;
}


