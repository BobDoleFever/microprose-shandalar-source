/*
 * Decompiled function: Pic_Subsystem_00451a82
 * Entry Point: 00451a82
 * Size: 154 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_00451a82(void)

{
  int local_c;
  int local_8;
  
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    for (local_c = 0; local_c < 0x50; local_c = local_c + 1) {
      if (*(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) == -1) {
        *(undefined4 *)(&g_ActiveCardsInPlay + local_c * 0x120 + local_8 * 0x5b20) = 0xffffffff;
      }
    }
  }
  return 0;
}


