/*
 * Decompiled function: Ai_Subsystem_004cbe57
 * Entry Point: 004cbe57
 * Size: 283 bytes
 */
#include "magic.h"


byte Ai_Subsystem_004cbe57(int arg1,int arg2)

{
  byte bVar1;
  
  bVar1 = ((&DAT_006a5f3e)[arg1 * 0x5b20 + arg2 * 0x120] & 3) != 0;
  if (((&g_CardSlot_Flags)[arg1 * 0x5b20 + arg2 * 0x120] & 0x10) != 0) {
    bVar1 = bVar1 | 2;
  }
  if (((&g_CardSlot_Flags)[arg1 * 0x5b20 + arg2 * 0x120] & 4) != 0) {
    bVar1 = bVar1 | 4;
  }
  if ((&g_CardSlot_ColorMask)[arg1 * 0x5b20 + arg2 * 0x120] != -1) {
    bVar1 = bVar1 | 8;
  }
  if (((&g_CardSlot_Toughness)[arg1 * 0x5b20 + arg2 * 0x120] != -1) &&
     (*(int *)(&g_CardSlot_OriginalCardId + arg1 * 0x5b20 + arg2 * 0x120) != -1)) {
    bVar1 = bVar1 | 0x10;
  }
  return bVar1;
}


