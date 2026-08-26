/*
 * Decompiled function: Prompts_Load_0045c3ae
 * Entry Point: 0045c3ae
 * Size: 613 bytes
 */
#include "duel.h"


undefined4 Prompts_Load_0045c3ae(int spell_id,int target_id,int flags)

{
  undefined4 local_8;
  
  if ((flags == 0x73) || (flags == 0x6d)) {
    FUN_00434660(s_prompts_txt_004f8a58,s_KING_SULEIMAN_004f8a48);
    local_8 = FUN_0045c613(spell_id,target_id,flags,1 - spell_id);
  }
  if (flags == 0x90) {
    FUN_0043071d(0);
    local_8 = 0;
  }
  else if ((flags == 0x72) &&
          (*(int *)(&DAT_006826e8 + target_id * 0x120 + spell_id * 0x5b20) != -1)) {
    if (((&DAT_004ff595)
         [*(int *)(&DAT_006826c4 +
                  *(int *)(&DAT_006826e8 + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                  (char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) * 0x34] ==
         '\x05') ||
       ((&DAT_004ff595)
        [*(int *)(&DAT_006826c4 +
                 *(int *)(&DAT_006826e8 + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                 (char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) * 0x34] ==
        '\x06')) {
      FUN_0046e571((int)(char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20],
                   *(int *)(&DAT_006826e8 + target_id * 0x120 + spell_id * 0x5b20),2);
    }
    else {
      DAT_00681ea4 = 1;
    }
    (&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20] = 0xff;
    *(int *)(&DAT_006826e8 + target_id * 0x120 + spell_id * 0x5b20) =
         (int)(char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20];
    *(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) =
         *(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
  }
  return local_8;
}


