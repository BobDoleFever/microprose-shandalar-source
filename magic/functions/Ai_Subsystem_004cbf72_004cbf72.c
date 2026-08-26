/*
 * Decompiled function: Ai_Subsystem_004cbf72
 * Entry Point: 004cbf72
 * Size: 94 bytes
 */
#include "magic.h"


undefined8 Ai_Subsystem_004cbf72(int arg1,int arg2)

{
  return CONCAT44(*(undefined4 *)(&g_CardSlot_OriginalCardId + arg2 * 0x120 + arg1 * 0x5b20),
                  (int)(char)(&g_CardSlot_Toughness)[arg2 * 0x120 + arg1 * 0x5b20]);
}


