/*
 * Decompiled function: FUN_00476b0e
 * Entry Point: 00476b0e
 * Size: 361 bytes
 */
#include "magic.h"


void FUN_00476b0e(void)

{
  int iVar1;
  int local_10;
  int local_c;
  int local_8;
  
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    for (local_10 = 0; local_10 < (int)(&g_PlayerActiveCardCount)[local_8]; local_10 = local_10 + 1)
    {
      if (((&g_CardSlot_SpecialState)[local_10 * 0x120 + local_8 * 0x5b20] & 4) == 0) {
        iVar1 = FUN_00471c32(local_8,local_10);
        if (iVar1 != 0) {
          for (local_c = 0; local_c < 7; local_c = local_c + 1) {
            (&DAT_006a603c)[local_c + local_8 * 0x5b20 + local_10 * 0x120] = 0;
            (&DAT_006a6048)[local_c + local_8 * 0x5b20 + local_10 * 0x120] =
                 (&DAT_006a603c)[local_c + local_8 * 0x5b20 + local_10 * 0x120];
          }
          *(undefined4 *)(&g_CardSlot_SpecialState + local_10 * 0x120 + local_8 * 0x5b20) = 0;
          FUN_00473e69(local_8,local_10,0x85);
          FUN_00473e69(local_8,local_10,0x84);
        }
      }
    }
  }
  return;
}


