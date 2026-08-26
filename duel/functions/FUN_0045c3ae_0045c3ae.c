/*
 * Decompiled function: FUN_0045c3ae
 * Entry Point: 0045c3ae
 * Size: 613 bytes
 */
#include "duel.h"


undefined4 FUN_0045c3ae(int param_1,int param_2,int param_3)

{
  undefined4 local_8;
  
  if ((param_3 == 0x73) || (param_3 == 0x6d)) {
    FUN_00434660(s_prompts_txt_004f8a58,s_KING_SULEIMAN_004f8a48);
    local_8 = FUN_0045c613(param_1,param_2,param_3,1 - param_1);
  }
  if (param_3 == 0x90) {
    FUN_0043071d(0);
    local_8 = 0;
  }
  else if ((param_3 == 0x72) && (*(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) != -1)
          ) {
    if (((&DAT_004ff595)
         [*(int *)(&DAT_006826c4 +
                  *(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
                  (char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] * 0x5b20) * 0x34] ==
         '\x05') ||
       ((&DAT_004ff595)
        [*(int *)(&DAT_006826c4 +
                 *(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
                 (char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] * 0x5b20) * 0x34] ==
        '\x06')) {
      FUN_0046e571((int)(char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20],
                   *(undefined4 *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20),2);
    }
    else {
      DAT_00681ea4 = 1;
    }
    (&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] = 0xff;
    *(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) =
         (int)(char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20];
    *(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) =
         *(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) | 0x10;
  }
  return local_8;
}


