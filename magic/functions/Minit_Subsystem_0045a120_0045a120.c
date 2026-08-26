/*
 * Decompiled function: Minit_Subsystem_0045a120
 * Entry Point: 0045a120
 * Size: 306 bytes
 */
#include "magic.h"


int Minit_Subsystem_0045a120(int arg1,int arg2)

{
  int iVar1;
  int local_14;
  int local_c;
  int local_8;
  
  local_c = 0;
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    for (local_14 = 0; local_14 < (int)(&g_PlayerActiveCardCount)[local_8]; local_14 = local_14 + 1)
    {
      iVar1 = FUN_00471c32(local_8,local_14);
      if ((((iVar1 != 0) &&
           (*(int *)(&g_MasterCardTypeTable +
                    *(int *)(&g_CardSlot_CardId + local_14 * 0x120 + local_8 * 0x5b20) * 0x34) ==
            0x37b)) &&
          ((char)(&g_CardSlot_DamageReceived)[local_14 * 0x120 + local_8 * 0x5b20] == arg1)) &&
         ((*(int *)(&g_CardSlot_TypeFlags + local_14 * 0x120 + local_8 * 0x5b20) == arg2 &&
          (*(int *)(&g_CardSlot_ConvertedManaCost + local_14 * 0x120 + local_8 * 0x5b20) == 0)))) {
        local_c = local_c + 1;
      }
    }
  }
  return local_c;
}


