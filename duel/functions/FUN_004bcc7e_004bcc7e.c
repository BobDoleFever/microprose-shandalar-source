/*
 * Decompiled function: FUN_004bcc7e
 * Entry Point: 004bcc7e
 * Size: 601 bytes
 */
#include "duel.h"


int FUN_004bcc7e(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 local_c;
  undefined4 local_8;
  
  if (param_3 == 0x74) {
    iVar1 = 1;
  }
  else {
    if (((param_3 == 0x6c) && (param_2 == DAT_00690c48)) && (param_1 == DAT_0068ecb0)) {
      iVar1 = FUN_00404b06(param_1,*(undefined4 *)
                                    (&DAT_006826c4 + param_1 * 0x5b20 + param_2 * 0x120),0xffffffff)
      ;
      if (iVar1 == 0) {
        DAT_0068f2d4 = DAT_0068f2d4 + 0x30;
      }
    }
    if (((param_3 == 0x6c) && (param_2 == DAT_00690c48)) && (param_1 == DAT_0068ecb0)) {
      FUN_00434660(s_prompts_txt_00508848,s_KISMET_00508840);
      iVar1 = FUN_0041e2a2(param_1,2,1 - param_1,0x1000,0,0,0,0,0,0,0xffffffff,0xffffffff,0xffffffff
                           ,0xffffffff,0,0,0,&DAT_006679f0,1,&local_c);
      if (iVar1 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(undefined4 *)(&DAT_006826e4 + param_1 * 0x5b20 + param_2 * 0x120) = local_c;
        *(undefined4 *)(&DAT_00682718 + param_1 * 0x5b20 + param_2 * 0x120) = local_c;
        *(undefined4 *)(&DAT_0068271c + param_1 * 0x5b20 + param_2 * 0x120) = local_8;
        (&DAT_006827b8)[param_1 * 0x5b20 + param_2 * 0x120] = 1;
      }
    }
    iVar1 = param_2 * 0x120;
    if (((((&DAT_006826cc)[param_1 * 0x5b20 + iVar1] & 0x20) == 0) && (param_3 == 0x6c)) &&
       ((iVar1 = param_2 * 0x120, *(int *)(&DAT_006826e4 + param_1 * 0x5b20 + iVar1) == DAT_0068ecb0
        && (iVar1 = *(int *)(&DAT_006826c4 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) * 0xd,
           ((&DAT_004ff594)
            [*(int *)(&DAT_006826c4 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) * 0x34] & 0x43)
           != 0)))) {
      iVar1 = DAT_00690c48 * 0x120;
      *(uint *)(&DAT_006826cc + DAT_0068ecb0 * 0x5b20 + iVar1) =
           *(uint *)(&DAT_006826cc + DAT_0068ecb0 * 0x5b20 + iVar1) | 0x10;
    }
  }
  return iVar1;
}


