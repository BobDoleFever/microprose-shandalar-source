/*
 * Decompiled function: Palette_Subsystem_004a7a25
 * Entry Point: 004a7a25
 * Size: 424 bytes
 */
#include "magic.h"


int Palette_Subsystem_004a7a25(int arg_1,int arg_2,int arg_3)

{
  int local_514;
  int local_50c;
  int local_508;
  int local_504 [320];
  
  local_514 = Palette_Subsystem_004a7bcd(arg_1,arg_2,(int)local_504);
  local_508 = 0;
  for (; (local_508 < arg_3 && (local_514 != 0)); local_514 = local_514 + -1) {
    local_50c = FUN_0040a1d2(local_514);
    FUN_00415d48(local_504[local_50c * 2],local_504[local_50c * 2 + 1]);
    if ((*(int *)(&DAT_006b3088 +
                 *(int *)(&g_MasterCardTypeTable +
                         *(int *)(&g_CardSlot_CardId +
                                 local_504[local_50c * 2] * 0x5b20 +
                                 local_504[local_50c * 2 + 1] * 0x120) * 0x34) * 0x98) == 0x58) ||
       (*(int *)(&DAT_006b3088 +
                *(int *)(&g_MasterCardTypeTable +
                        *(int *)(&g_CardSlot_CardId +
                                local_504[local_50c * 2] * 0x5b20 +
                                local_504[local_50c * 2 + 1] * 0x120) * 0x34) * 0x98) == 0x57)) {
      FUN_00410cc0(arg_1,arg_2,DAT_00695df4,local_504[local_50c * 2],local_504[local_50c * 2 + 1]);
    }
    for (; local_50c < local_514; local_50c = local_50c + 1) {
      local_504[local_50c * 2] = local_504[local_50c * 2 + 2];
      local_504[local_50c * 2 + 1] = local_504[local_50c * 2 + 3];
    }
    local_508 = local_508 + 1;
  }
  return local_508;
}


