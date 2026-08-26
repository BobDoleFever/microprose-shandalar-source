/*
 * Decompiled function: Magic_ResolveSpellStack
 * Entry Point: 00474389
 * Size: 159 bytes
 */
#include "magic.h"


bool Magic_ResolveSpellStack(int arg1,int arg2)

{
  bool bVar1;
  
  if (((&DAT_0051aed1)[*(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20) * 0x34] & 0x10)
      == 0) {
    bVar1 = false;
  }
  else {
    bVar1 = ((&DAT_0051aed0)[*(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20) * 0x34] & 1
            ) == 0;
  }
  return bVar1;
}


