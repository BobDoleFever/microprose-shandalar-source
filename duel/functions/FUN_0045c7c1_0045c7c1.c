/*
 * Decompiled function: FUN_0045c7c1
 * Entry Point: 0045c7c1
 * Size: 989 bytes
 */
#include "duel.h"


undefined4 FUN_0045c7c1(int param_1,int param_2,int param_3)

{
  undefined4 local_8;
  
  if (param_3 == 0x73) {
    if ((*(uint *)(&DAT_006826cc + param_1 * 0x5b20 + param_2 * 0x120) & 0x20010) == 0) {
      if ((param_1 == DAT_00666458) || (0x1a < DAT_0068f2c4)) {
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
  else if (param_3 == 0x90) {
    FUN_0043071d(0);
    local_8 = 0;
  }
  else {
    if (param_3 == 0x6d) {
      FUN_00434660(s_prompts_txt_004f8a74,s_NETTLING_IMP_004f8a64);
      local_8 = FUN_0045c613(param_1,param_2,0x6d,1 - param_1);
    }
    if (((param_3 == 0x72) && (*(int *)(&DAT_006826e8 + param_1 * 0x5b20 + param_2 * 0x120) != -1))
       && ((&DAT_004ff595)
           [*(int *)(&DAT_006826c4 +
                    *(int *)(&DAT_006826e8 + param_1 * 0x5b20 + param_2 * 0x120) * 0x120 +
                    (char)(&DAT_006826d2)[param_1 * 0x5b20 + param_2 * 0x120] * 0x5b20) * 0x34] ==
           '\0')) {
      (&DAT_006826d2)[param_1 * 0x5b20 + param_2 * 0x120] = 0xff;
      *(int *)(&DAT_006826e8 + param_1 * 0x5b20 + param_2 * 0x120) =
           (int)(char)(&DAT_006826d2)[param_1 * 0x5b20 + param_2 * 0x120];
      *(uint *)(&DAT_006826cc + param_1 * 0x5b20 + param_2 * 0x120) =
           *(uint *)(&DAT_006826cc + param_1 * 0x5b20 + param_2 * 0x120) & 0xffffffef;
    }
    if (((param_3 == 0x15) && (*(int *)(&DAT_006826e8 + param_1 * 0x5b20 + param_2 * 0x120) != -1))
       && (param_1 != DAT_00666458)) {
      *(uint *)(&DAT_006826cc +
               *(int *)(&DAT_006826e8 + param_1 * 0x5b20 + param_2 * 0x120) * 0x120 +
               (char)(&DAT_006826d2)[param_1 * 0x5b20 + param_2 * 0x120] * 0x5b20) =
           *(uint *)(&DAT_006826cc +
                    *(int *)(&DAT_006826e8 + param_1 * 0x5b20 + param_2 * 0x120) * 0x120 +
                    (char)(&DAT_006826d2)[param_1 * 0x5b20 + param_2 * 0x120] * 0x5b20) | 4;
      DAT_006826b0 = 1;
      (&DAT_006826d2)[param_1 * 0x5b20 + param_2 * 0x120] = 0xff;
      *(int *)(&DAT_006826e8 + param_1 * 0x5b20 + param_2 * 0x120) =
           (int)(char)(&DAT_006826d2)[param_1 * 0x5b20 + param_2 * 0x120];
    }
    if (((param_3 == 0x1f) && (*(int *)(&DAT_006826e8 + param_1 * 0x5b20 + param_2 * 0x120) != -1))
       && ((param_1 != DAT_00666458 &&
           (((&DAT_006826cc)
             [*(int *)(&DAT_006826e8 + param_1 * 0x5b20 + param_2 * 0x120) * 0x120 +
              (char)(&DAT_006826d2)[param_1 * 0x5b20 + param_2 * 0x120] * 0x5b20] & 0x40) == 0)))) {
      FUN_0046e571((int)(char)(&DAT_006826d2)[param_1 * 0x5b20 + param_2 * 0x120],
                   *(undefined4 *)(&DAT_006826e8 + param_1 * 0x5b20 + param_2 * 0x120),2);
    }
  }
  return local_8;
}


