/*
 * Decompiled function: Ai_Subsystem_004ccca3
 * Entry Point: 004ccca3
 * Size: 565 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Ai_Subsystem_004ccca3(void)

{
  int local_c;
  int local_8;
  
  for (local_c = 0; local_c < 8; local_c = local_c + 1) {
    *(undefined4 *)(&DAT_006330d0 + local_c * 4) = 0;
    *(undefined4 *)(&DAT_0063edf0 + local_c * 4) = *(undefined4 *)(&DAT_006330d0 + local_c * 4);
    *(undefined4 *)(&DAT_0063edd0 + local_c * 4) = *(undefined4 *)(&DAT_0063edf0 + local_c * 4);
  }
  DAT_0062793c = 0xffffffff;
  _DAT_00627870 = 0xffffffff;
  DAT_00627a4c = 0xffffffff;
  _DAT_00627a20 = 0xffffffff;
  DAT_0063eed4 = 0;
  _DAT_0063eed0 = 0;
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    for (local_c = 0; local_c < (int)(&g_PlayerActiveCardCount)[local_8]; local_c = local_c + 1) {
      if ((((&DAT_0051aed1)
            [*(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) * 0x34] & 0x10) != 0)
         && (((&g_CardSlot_Flags)[local_c * 0x120 + local_8 * 0x5b20] & 2) != 0)) {
        FUN_00473e69(local_8,local_c,0x7f);
      }
      if ((*(int *)(&g_MasterCardTypeTable +
                   *(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) * 0x34) == 0xee
          ) && (((&g_CardSlot_Flags)[local_c * 0x120 + local_8 * 0x5b20] & 2) != 0)) {
        Magic_TriggerCardEvent(local_8,local_c,0x7f,0xffffffff,0xffffffff);
      }
      if ((*(int *)(&g_MasterCardTypeTable +
                   *(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) * 0x34) == 100)
         && (((&g_CardSlot_Flags)[local_c * 0x120 + local_8 * 0x5b20] & 2) != 0)) {
        Magic_TriggerCardEvent(local_8,local_c,0x7f,0xffffffff,0xffffffff);
      }
    }
  }
  return;
}


