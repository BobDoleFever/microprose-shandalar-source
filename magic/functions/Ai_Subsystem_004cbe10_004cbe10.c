/*
 * Decompiled function: Ai_Subsystem_004cbe10
 * Entry Point: 004cbe10
 * Size: 66 bytes
 */
#include "magic.h"


bool Ai_Subsystem_004cbe10(int arg1,int arg2)

{
  return ((&g_CardSlot_Flags)[arg2 * 0x120 + arg1 * 0x5b20] & 2) != 0;
}


