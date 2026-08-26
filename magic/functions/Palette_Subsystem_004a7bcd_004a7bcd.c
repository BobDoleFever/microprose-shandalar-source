/*
 * Decompiled function: Palette_Subsystem_004a7bcd
 * Entry Point: 004a7bcd
 * Size: 312 bytes
 */
#include "magic.h"


int Palette_Subsystem_004a7bcd(int arg_1,int arg_2,int arg_3)

{
  uint uVar1;
  int local_10;
  int local_c;
  int local_8;
  
  local_c = 0;
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    for (local_10 = 0; local_10 < (int)(&g_PlayerActiveCardCount)[local_8]; local_10 = local_10 + 1)
    {
      if (((*(int *)(&g_CardSlot_CardId + local_8 * 0x5b20 + local_10 * 0x120) != -1) &&
          (((&g_CardSlot_Flags)[local_8 * 0x5b20 + local_10 * 0x120] & 2) != 0)) &&
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId + local_8 * 0x5b20 + local_10 * 0x120) * 0x34] & 2) != 0)) {
        uVar1 = SpellChain_ProcessTriggerEvent(arg_1,arg_2);
        if ((*(uint *)(&g_CardSlot_Abilities2 + local_8 * 0x5b20 + local_10 * 0x120) & uVar1) == 0)
        {
          *(int *)(arg_3 + local_c * 8) = local_8;
          *(int *)(arg_3 + 4 + local_c * 8) = local_10;
          local_c = local_c + 1;
        }
      }
    }
  }
  return local_c;
}


