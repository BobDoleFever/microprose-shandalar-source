/*
 * Decompiled function: FUN_0045da63
 * Entry Point: 0045da63
 * Size: 1021 bytes
 */
#include "duel.h"


undefined4 FUN_0045da63(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_10;
  int local_c;
  
  if (param_3 == 0x73) {
    uVar1 = 0;
    if ((*(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) & 0x20010) == 0) {
      uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,
                           (int)*(short *)(&DAT_006826d4 + param_2 * 0x120 + param_1 * 0x5b20) - 1U
                           | 0x2000,0xffffffff,0,0,0);
      uVar1 = FUN_0041bcf0(0,0,param_1,param_1,param_1,0x200,2,0,0,uVar1);
    }
  }
  else if (param_3 == 0x90) {
    FUN_0043071d(0);
    uVar1 = 0;
  }
  else {
    if ((param_3 == 0x6d) &&
       ((*(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) & 0x20010) == 0)) {
      FUN_00434660(s_prompts_txt_004f8aa8,s_STONE_GIANT_004f8a9c);
      iVar2 = FUN_0048b81a(param_1,param_2,0x32,0xffffffff,0,0,0,&DAT_006679f0,1,&local_10);
      uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,iVar2 - 1U | 0x2000)
      ;
      iVar2 = FUN_0041e2a2(param_1,param_1,param_1,0x200,2,0,0,uVar1);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) = local_10;
        *(int *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20) = local_c;
        (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 1;
        *(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) =
             *(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) | 0x10;
      }
    }
    if (param_3 == 0x72) {
      local_10 = *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20);
      local_c = *(int *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20);
      uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,
                           (int)*(short *)(&DAT_006826d4 + param_2 * 0x120 + param_1 * 0x5b20) - 1U
                           | 0x2000,0,0,0);
      iVar2 = FUN_0041c0ab(local_10,local_c,0,param_1,param_1,param_1,0x200,2,0,0,uVar1);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        iVar2 = FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_00667994,local_10,local_c);
        if (iVar2 != -1) {
          (&DAT_006826e0)[iVar2 * 0x120 + param_1 * 0x5b20] = 5;
          *(undefined4 *)(&DAT_006826e4 + iVar2 * 0x120 + param_1 * 0x5b20) = 0x20;
          *(undefined4 *)(&DAT_006826fc + local_10 * 0x5b20 + local_c * 0x120) = 0x8000000;
        }
      }
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
       *(int *)(&DAT_006827b0 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20] = 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}


