/*
 * Decompiled function: FUN_00458802
 * Entry Point: 00458802
 * Size: 1727 bytes
 */
#include "duel.h"


undefined4 FUN_00458802(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  if ((param_3 == 0x71) &&
     (local_8 = FUN_004a2b00(param_1,param_2,DAT_00690c40,param_1,param_2), local_8 != -1)) {
    *(undefined4 *)(&DAT_006826e4 + local_8 * 0x120 + param_1 * 0x5b20) = 3;
    *(undefined4 *)(&DAT_006826f0 + local_8 * 0x120 + param_1 * 0x5b20) = 0x10d;
    *(undefined4 *)(&DAT_006826f8 + local_8 * 0x120 + param_1 * 0x5b20) = 0x10000;
    (&DAT_006826d3)[param_2 * 0x120 + param_1 * 0x5b20] = (undefined1)param_1;
    *(int *)(&DAT_006826ec + param_2 * 0x120 + param_1 * 0x5b20) = local_8;
  }
  if ((((param_3 == 0x32) || (param_3 == 0x33)) && (param_2 == DAT_00690c48)) &&
     (param_1 == DAT_0068ecb0)) {
    if (((&DAT_006826cc)[param_2 * 0x120 + param_1 * 0x5b20] & 4) == 0) {
      *(uint *)(&DAT_006826f0 +
               *(int *)(&DAT_006826ec + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
               (char)(&DAT_006826d3)[param_2 * 0x120 + param_1 * 0x5b20] * 0x5b20) =
           *(uint *)(&DAT_006826f0 +
                    *(int *)(&DAT_006826ec + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
                    (char)(&DAT_006826d3)[param_2 * 0x120 + param_1 * 0x5b20] * 0x5b20) | 1;
      *(uint *)(&DAT_006826f0 +
               *(int *)(&DAT_006826ec + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
               (char)(&DAT_006826d3)[param_2 * 0x120 + param_1 * 0x5b20] * 0x5b20) =
           *(uint *)(&DAT_006826f0 +
                    *(int *)(&DAT_006826ec + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
                    (char)(&DAT_006826d3)[param_2 * 0x120 + param_1 * 0x5b20] * 0x5b20) & 0xfffffffd
      ;
    }
    else {
      *(uint *)(&DAT_006826f0 +
               *(int *)(&DAT_006826ec + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
               (char)(&DAT_006826d3)[param_2 * 0x120 + param_1 * 0x5b20] * 0x5b20) =
           *(uint *)(&DAT_006826f0 +
                    *(int *)(&DAT_006826ec + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
                    (char)(&DAT_006826d3)[param_2 * 0x120 + param_1 * 0x5b20] * 0x5b20) | 2;
      *(uint *)(&DAT_006826f0 +
               *(int *)(&DAT_006826ec + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
               (char)(&DAT_006826d3)[param_2 * 0x120 + param_1 * 0x5b20] * 0x5b20) =
           *(uint *)(&DAT_006826f0 +
                    *(int *)(&DAT_006826ec + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
                    (char)(&DAT_006826d3)[param_2 * 0x120 + param_1 * 0x5b20] * 0x5b20) & 0xfffffffe
      ;
    }
  }
  if (param_3 == 0x73) {
    if ((*(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) & 0x20010) == 0) {
      uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
      iVar2 = FUN_0041bcf0(0,0,param_1,2,2,0x200,1,0,0,uVar1);
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
      FUN_00434660(s_prompts_txt_004f892c,s_GAEAS_LIEGE_004f8920);
      uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0,
                           &DAT_006679f0,1,&local_10);
      iVar2 = FUN_0041e2a2(param_1,2,1 - param_1,0x200,1,0,0,uVar1);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(undefined4 *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) = local_10;
        *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20) = local_c;
        (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 1;
        *(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) =
             *(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) | 0x10;
      }
    }
    if (param_3 == 0x72) {
      local_10 = *(undefined4 *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20);
      local_c = *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20);
      uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
      iVar2 = FUN_0041c0ab(local_10,local_c,0,param_1,2,2,0x200,1,0,0,uVar1);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(undefined4 *)
         (&DAT_006826e4 +
         *(int *)(&DAT_006827b4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
         *(int *)(&DAT_006827b0 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20) = 3;
        local_8 = FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_00681ec8,local_10,local_c);
        if (local_8 != -1) {
          *(uint *)(&DAT_006826f8 + local_8 * 0x120 + param_1 * 0x5b20) =
               *(uint *)(&DAT_006826f8 + local_8 * 0x120 + param_1 * 0x5b20) | 0x11020;
        }
      }
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
       *(int *)(&DAT_006827b0 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20] = 0;
    }
    if (((param_3 == 0x22) || (param_3 == 199)) &&
       ((param_2 == DAT_00690c48 &&
        ((param_1 == DAT_0068ecb0 &&
         (((&DAT_006826e5)[param_2 * 0x120 + param_1 * 0x5b20] & 0x40) != 0)))))) {
      *(uint *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) =
           *(uint *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) & 0xffffbfff;
      FUN_0048b81a(param_1,param_2,0x32,0xffffffff);
      FUN_0048b81a(param_1,param_2,0x33,0xffffffff);
    }
  }
  return 0;
}


