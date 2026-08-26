/*
 * Decompiled function: FUN_00453daf
 * Entry Point: 00453daf
 * Size: 970 bytes
 */
#include "duel.h"


undefined4 FUN_00453daf(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_14;
  int local_10;
  int local_c;
  
  if (param_3 == 0x73) {
    if ((*(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) & 0x20010) == 0) {
      uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
      iVar2 = FUN_0041bcf0(0,0,param_1,2,2,0x200,0x40,2,0,uVar1);
      if (iVar2 != 0) {
        return 1;
      }
    }
  }
  else if (param_3 == 0x90) {
    FUN_0043071d(0);
  }
  else {
    if (param_3 == 0x6d) {
      FUN_00434660(s_prompts_txt_004f8810,s_XENIC_POLTERGEIST_004f87fc);
      uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0,
                           &DAT_006679f0,1,&local_14);
      iVar2 = FUN_0041e2a2(param_1,2,param_1,0x200,0x40,2,0,uVar1);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) = local_14;
        *(int *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20) = local_10;
        (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 1;
        *(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) =
             *(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) | 0x10;
      }
    }
    if (param_3 == 0x72) {
      local_14 = *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20);
      local_10 = *(int *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20);
      uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
      iVar2 = FUN_0041c0ab(local_14,local_10,0,param_1,2,2,0x200,0x40,2,0,uVar1);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        local_c = FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_00666414,local_14,local_10);
        if ((local_c != -1) &&
           (iVar2 = FUN_004af68f(*(undefined4 *)
                                  (&DAT_006826c4 + local_14 * 0x5b20 + local_10 * 0x120)),
           iVar2 != -1)) {
          *(int *)(&DAT_006826c8 + local_c * 0x120 + param_1 * 0x5b20) = iVar2;
          (&DAT_004ff594)[iVar2 * 0x34] = 0x42;
          *(short *)(&DAT_004ff59c + iVar2 * 0x34) =
               (short)(char)(&DAT_004ff598)
                            [*(int *)(&DAT_006826c4 + local_14 * 0x5b20 + local_10 * 0x120) * 0x34];
          *(undefined2 *)(&DAT_004ff59a + iVar2 * 0x34) =
               *(undefined2 *)(&DAT_004ff59c + iVar2 * 0x34);
        }
      }
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
       *(int *)(&DAT_006827b0 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20] = 0;
    }
  }
  return 0;
}


