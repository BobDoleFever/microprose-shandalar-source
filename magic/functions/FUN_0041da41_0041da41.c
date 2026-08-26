/*
 * Decompiled function: FUN_0041da41
 * Entry Point: 0041da41
 * Size: 294 bytes
 */
#include "magic.h"


void FUN_0041da41(int arg1,int arg2)

{
  int arg_2;
  uint local_c;
  
  DAT_00695f08 = arg1;
  DAT_006b2e14 = arg2;
  FUN_00476205(g_DefendingPlayer,0xd4,s_Card_leaving_play_00519c0c,0);
  *(undefined4 *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20) = 0xffffffff;
  Pic_Subsystem_00448e29(arg1,arg2);
  if (((&g_CardSlot_Abilities1)[arg2 * 0x120 + arg1 * 0x5b20] & 0x10) == 0) {
    local_c = (uint)(((&DAT_006a5f3d)[arg2 * 0x120 + arg1 * 0x5b20] & 0x10) != 0);
    arg_2 = Pic_Subsystem_00451291
                      (local_c,*(int *)(&g_ActiveCardsInPlay + arg2 * 0x120 + arg1 * 0x5b20));
    if (arg_2 != -1) {
      Ai_Subsystem_004cc3f8(local_c,arg_2,8,2);
    }
    (&DAT_006b3008)[local_c] = (&DAT_006b3008)[local_c] + 1;
  }
  return;
}


