/*
 * Decompiled function: FUN_0045c1ed
 * Entry Point: 0045c1ed
 * Size: 449 bytes
 */
#include "duel.h"


undefined4 FUN_0045c1ed(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 local_8;
  
  if ((param_3 == 0x73) || (param_3 == 0x6d)) {
    FUN_00434660(s_prompts_txt_004f8a3c,s_DWARVEN_DTEAM_004f8a2c);
    local_8 = FUN_0045c613(param_1,param_2,param_3,1 - param_1);
  }
  if (param_3 == 0x90) {
    FUN_0043071d(0);
    local_8 = 0;
  }
  else if ((param_3 == 0x72) && (*(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) != -1)
          ) {
    iVar1 = *(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20);
    DAT_0068eef0 = (int)(char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20];
    *(undefined4 *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) = 0xffffffff;
    *(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) =
         *(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) & 0xffffffef;
    if ((iVar1 != -1) &&
       ((&DAT_004ff595)
        [*(int *)(&DAT_006826c4 +
                 *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20 +
                 *(int *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20) * 0x120) * 0x34] ==
        '\0')) {
      FUN_0046e571(DAT_0068eef0,iVar1,2);
    }
  }
  return local_8;
}


