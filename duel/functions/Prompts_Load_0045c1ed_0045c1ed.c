/*
 * Decompiled function: Prompts_Load_0045c1ed
 * Entry Point: 0045c1ed
 * Size: 449 bytes
 */
#include "duel.h"


undefined4 Prompts_Load_0045c1ed(int spell_id,int target_id,int flags)

{
  int arg_2;
  undefined4 local_8;
  
  if ((flags == 0x73) || (flags == 0x6d)) {
    FUN_00434660(s_prompts_txt_004f8a3c,s_DWARVEN_DTEAM_004f8a2c);
    local_8 = FUN_0045c613(spell_id,target_id,flags,1 - spell_id);
  }
  if (flags == 0x90) {
    FUN_0043071d(0);
    local_8 = 0;
  }
  else if ((flags == 0x72) &&
          (*(int *)(&DAT_006826e8 + target_id * 0x120 + spell_id * 0x5b20) != -1)) {
    arg_2 = *(int *)(&DAT_006826e8 + target_id * 0x120 + spell_id * 0x5b20);
    DAT_0068eef0 = (int)(char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20];
    *(undefined4 *)(&DAT_006826e8 + target_id * 0x120 + spell_id * 0x5b20) = 0xffffffff;
    *(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) =
         *(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) & 0xffffffef;
    if ((arg_2 != -1) &&
       ((&DAT_004ff595)
        [*(int *)(&DAT_006826c4 +
                 *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                 *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20) * 0x120) * 0x34] ==
        '\0')) {
      FUN_0046e571(DAT_0068eef0,arg_2,2);
    }
  }
  return local_8;
}


