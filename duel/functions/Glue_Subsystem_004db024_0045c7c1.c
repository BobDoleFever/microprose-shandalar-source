/*
 * Decompiled function: Glue_Subsystem_004db024
 * Entry Point: 0045c7c1
 * Size: 989 bytes
 */
#include "duel.h"


undefined4 Glue_Subsystem_004db024(int spell_id,int target_id,int flags)

{
  undefined4 local_8;
  
  if (flags == 0x73) {
    if ((*(uint *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) & 0x20010) == 0) {
      if ((spell_id == DAT_00666458) || (0x1a < DAT_0068f2c4)) {
        local_8 = 0;
      }
      else {
        local_8 = 1;
      }
    }
    else {
      local_8 = 0;
    }
  }
  else if (flags == 0x90) {
    FUN_0043071d(0);
    local_8 = 0;
  }
  else {
    if (flags == 0x6d) {
      FUN_00434660(s_prompts_txt_004f8a74,s_NETTLING_IMP_004f8a64);
      local_8 = FUN_0045c613(spell_id,target_id,0x6d,1 - spell_id);
    }
    if (((flags == 0x72) && (*(int *)(&DAT_006826e8 + spell_id * 0x5b20 + target_id * 0x120) != -1))
       && ((&DAT_004ff595)
           [*(int *)(&DAT_006826c4 +
                    *(int *)(&DAT_006826e8 + spell_id * 0x5b20 + target_id * 0x120) * 0x120 +
                    (char)(&DAT_006826d2)[spell_id * 0x5b20 + target_id * 0x120] * 0x5b20) * 0x34]
           == '\0')) {
      (&DAT_006826d2)[spell_id * 0x5b20 + target_id * 0x120] = 0xff;
      *(int *)(&DAT_006826e8 + spell_id * 0x5b20 + target_id * 0x120) =
           (int)(char)(&DAT_006826d2)[spell_id * 0x5b20 + target_id * 0x120];
      *(uint *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) =
           *(uint *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) & 0xffffffef;
    }
    if (((flags == 0x15) && (*(int *)(&DAT_006826e8 + spell_id * 0x5b20 + target_id * 0x120) != -1))
       && (spell_id != DAT_00666458)) {
      *(uint *)(&DAT_006826cc +
               *(int *)(&DAT_006826e8 + spell_id * 0x5b20 + target_id * 0x120) * 0x120 +
               (char)(&DAT_006826d2)[spell_id * 0x5b20 + target_id * 0x120] * 0x5b20) =
           *(uint *)(&DAT_006826cc +
                    *(int *)(&DAT_006826e8 + spell_id * 0x5b20 + target_id * 0x120) * 0x120 +
                    (char)(&DAT_006826d2)[spell_id * 0x5b20 + target_id * 0x120] * 0x5b20) | 4;
      DAT_006826b0 = 1;
      (&DAT_006826d2)[spell_id * 0x5b20 + target_id * 0x120] = 0xff;
      *(int *)(&DAT_006826e8 + spell_id * 0x5b20 + target_id * 0x120) =
           (int)(char)(&DAT_006826d2)[spell_id * 0x5b20 + target_id * 0x120];
    }
    if (((flags == 0x1f) && (*(int *)(&DAT_006826e8 + spell_id * 0x5b20 + target_id * 0x120) != -1))
       && ((spell_id != DAT_00666458 &&
           (((&DAT_006826cc)
             [*(int *)(&DAT_006826e8 + spell_id * 0x5b20 + target_id * 0x120) * 0x120 +
              (char)(&DAT_006826d2)[spell_id * 0x5b20 + target_id * 0x120] * 0x5b20] & 0x40) == 0)))
       ) {
      FUN_0046e571((int)(char)(&DAT_006826d2)[spell_id * 0x5b20 + target_id * 0x120],
                   *(int *)(&DAT_006826e8 + spell_id * 0x5b20 + target_id * 0x120),2);
    }
  }
  return local_8;
}


