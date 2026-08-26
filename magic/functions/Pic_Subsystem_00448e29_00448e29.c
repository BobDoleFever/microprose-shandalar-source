/*
 * Decompiled function: Pic_Subsystem_00448e29
 * Entry Point: 00448e29
 * Size: 785 bytes
 */
#include "magic.h"


void Pic_Subsystem_00448e29(int arg1,int arg2)

{
  int local_514;
  int local_510;
  int local_508;
  int aiStack_504 [320];
  
  local_510 = 0;
  for (local_508 = 0; local_508 < 2; local_508 = local_508 + 1) {
    for (local_514 = 0; local_514 < (int)(&g_PlayerActiveCardCount)[local_508];
        local_514 = local_514 + 1) {
      if ((((*(int *)(&g_CardSlot_CardId + local_514 * 0x120 + local_508 * 0x5b20) != -1) &&
           (((&g_CardSlot_Flags)[local_514 * 0x120 + local_508 * 0x5b20] & 2) != 0)) &&
          ((char)(&g_CardSlot_Toughness)[local_514 * 0x120 + local_508 * 0x5b20] == arg1)) &&
         ((*(int *)(&g_CardSlot_OriginalCardId + local_514 * 0x120 + local_508 * 0x5b20) == arg2 &&
          ((local_508 != arg1 || (local_514 != arg2)))))) {
        if (((&g_MasterCardColorTable)
             [*(int *)(&g_CardSlot_CardId + local_514 * 0x120 + local_508 * 0x5b20) * 0x34] & 0x43)
            == 0) {
          aiStack_504[local_510 * 2] = local_508;
          aiStack_504[local_510 * 2 + 1] = local_514;
          local_510 = local_510 + 1;
        }
        else {
          (&g_CardSlot_Toughness)[local_514 * 0x120 + local_508 * 0x5b20] = 0xff;
          *(undefined4 *)(&g_CardSlot_OriginalCardId + local_514 * 0x120 + local_508 * 0x5b20) =
               0xffffffff;
        }
      }
    }
  }
  while (local_510 != 0) {
    local_510 = local_510 + -1;
    Pic_Subsystem_0044867e(aiStack_504[local_510 * 2],aiStack_504[local_510 * 2 + 1],2);
  }
  *(undefined2 *)(&g_CardSlot_Power + arg2 * 0x120 + arg1 * 0x5b20) = 0;
  *(undefined2 *)(&DAT_006a5f4a + arg2 * 0x120 + arg1 * 0x5b20) =
       *(undefined2 *)(&g_CardSlot_Power + arg2 * 0x120 + arg1 * 0x5b20);
  *(undefined2 *)(&DAT_006a5f48 + arg2 * 0x120 + arg1 * 0x5b20) =
       *(undefined2 *)(&DAT_006a5f4a + arg2 * 0x120 + arg1 * 0x5b20);
  (&g_CardSlot_ColorMask)[arg2 * 0x120 + arg1 * 0x5b20] = 0xff;
  return;
}


