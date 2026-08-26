/*
 * Decompiled function: Palette_Subsystem_004a7d05
 * Entry Point: 004a7d05
 * Size: 311 bytes
 */
#include "magic.h"


int Palette_Subsystem_004a7d05(int arg1,int arg2)

{
  uint uVar1;
  int local_10;
  int local_c;
  int local_8;
  
  local_c = 0;
  local_8 = 0;
  while ((local_8 < 2 && (local_c == 0))) {
    local_10 = 0;
    while ((local_10 < (int)(&g_PlayerActiveCardCount)[local_8] && (local_c == 0))) {
      if (((*(int *)(&g_CardSlot_CardId + local_10 * 0x120 + local_8 * 0x5b20) != -1) &&
          (((&g_CardSlot_Flags)[local_10 * 0x120 + local_8 * 0x5b20] & 2) != 0)) &&
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId + local_10 * 0x120 + local_8 * 0x5b20) * 0x34] & 2) != 0)) {
        uVar1 = SpellChain_ProcessTriggerEvent(arg1,arg2);
        if ((*(uint *)(&g_CardSlot_Abilities2 + local_10 * 0x120 + local_8 * 0x5b20) & uVar1) == 0)
        {
          local_c = 1;
        }
      }
      local_10 = local_10 + 1;
    }
    local_8 = local_8 + 1;
  }
  return local_c;
}


