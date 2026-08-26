/*
 * Decompiled function: FUN_0040cfd7
 * Entry Point: 0040cfd7
 * Size: 472 bytes
 */
#include "duel.h"


undefined4 FUN_0040cfd7(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int local_10;
  int local_c;
  int local_8;
  
  FUN_004348b2(s_prompts_txt_004f27e4,s_TETRAVUS_004f27d8);
  if (param_3 < 3) {
    if (param_3 < 2) {
      local_10 = 0;
    }
    else {
      local_10 = 1;
    }
  }
  else {
    local_10 = 2;
  }
  uVar1 = FUN_0045102d(param_1,param_1,param_2,0xffffffff,0xffffffff,&DAT_006679f0 + local_10 * 0xfa
                       ,0);
  *(undefined4 *)(&DAT_006826f0 + param_2 * 0x120 + param_1 * 0x5b20) = uVar1;
  local_8 = (int)*(short *)(&DAT_006826d6 + param_2 * 0x120 + param_1 * 0x5b20);
  if (*(int *)(&DAT_006826f0 + param_2 * 0x120 + param_1 * 0x5b20) <= param_3) {
    local_c = 0;
    while ((local_c < *(int *)(&DAT_006826f0 + param_2 * 0x120 + param_1 * 0x5b20) && (0 < local_8))
          ) {
      FUN_0046801f(param_1,param_2,1);
      *(uint *)(&DAT_006826fc + param_2 * 0x120 + param_1 * 0x5b20) =
           *(uint *)(&DAT_006826fc + param_2 * 0x120 + param_1 * 0x5b20) | 0x2000000;
      local_8 = FUN_0048b81a(param_1,param_2,0x33,0xffffffff);
      if (0 < local_8) {
        *(uint *)(&DAT_006826fc + param_2 * 0x120 + param_1 * 0x5b20) =
             *(uint *)(&DAT_006826fc + param_2 * 0x120 + param_1 * 0x5b20) | 0x4000000;
        FUN_0048b81a(param_1,param_2,0x32,0xffffffff);
      }
      local_c = local_c + 1;
    }
  }
  if (0 < DAT_0068f2c0) {
    DAT_0068f2c0 = DAT_0068f2c0 + -1;
  }
  return 0;
}


