/*
 * Decompiled function: Ai_Subsystem_004cbad0
 * Entry Point: 004cbad0
 * Size: 52 bytes
 */
#include "magic.h"


uint Ai_Subsystem_004cbad0(int arg1,int arg2)

{
  return *(uint *)(&g_CardSlot_Abilities1 + arg2 * 0x120 + arg1 * 0x5b20) & 0xff00;
}


