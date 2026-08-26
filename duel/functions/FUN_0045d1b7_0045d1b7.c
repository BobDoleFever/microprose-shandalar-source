/*
 * Decompiled function: FUN_0045d1b7
 * Entry Point: 0045d1b7
 * Size: 1469 bytes
 */
#include "duel.h"


undefined4 FUN_0045d1b7(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (param_3 == 0x73) {
    uVar1 = 0;
    if ((*(uint *)(&DAT_006826cc + param_1 * 0x5b20 + param_2 * 0x120) & 0x20010) == 0) {
      uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
      uVar1 = FUN_0041bcf0(0,0,param_1,2,2,0x200,2,0,0,uVar1);
    }
  }
  else if (param_3 == 0x90) {
    FUN_0043071d(0);
    uVar1 = 0;
  }
  else {
    if ((param_3 == 0x6d) &&
       ((*(uint *)(&DAT_006826cc + param_1 * 0x5b20 + param_2 * 0x120) & 0x20010) == 0)) {
      FUN_00434660(s_prompts_txt_004f8a90,s_SORCERESS_QUEEN_004f8a80);
      *(uint *)(&DAT_006826cc + param_1 * 0x5b20 + param_2 * 0x120) =
           *(uint *)(&DAT_006826cc + param_1 * 0x5b20 + param_2 * 0x120) | 0x100000;
      FUN_00451482(0,0x20);
      uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0,
                           &DAT_006679f0,1,&local_14);
      iVar2 = FUN_0041e2a2(param_1,2,1 - param_1,0x200,2,0,0,uVar1);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(int *)(&DAT_00682718 + param_1 * 0x5b20 + param_2 * 0x120) = local_14;
        *(int *)(&DAT_0068271c + param_1 * 0x5b20 + param_2 * 0x120) = local_10;
        (&DAT_006827b8)[param_1 * 0x5b20 + param_2 * 0x120] = 1;
        *(uint *)(&DAT_006826cc + param_1 * 0x5b20 + param_2 * 0x120) =
             *(uint *)(&DAT_006826cc + param_1 * 0x5b20 + param_2 * 0x120) | 0x10;
      }
      *(uint *)(&DAT_006826cc + param_1 * 0x5b20 + param_2 * 0x120) =
           *(uint *)(&DAT_006826cc + param_1 * 0x5b20 + param_2 * 0x120) & 0xffefffff;
    }
    if (param_3 == 0x72) {
      local_14 = *(int *)(&DAT_00682718 + param_1 * 0x5b20 + param_2 * 0x120);
      local_10 = *(int *)(&DAT_0068271c + param_1 * 0x5b20 + param_2 * 0x120);
      uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
      iVar2 = FUN_0041c0ab(local_14,local_10,0,param_1,2,2,0x200,2,0,0,uVar1);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
          for (local_c = 0; local_c < (int)(&DAT_00666408)[local_8]; local_c = local_c + 1) {
            if ((((*(int *)(&DAT_006826c4 + local_c * 0x120 + local_8 * 0x5b20) == DAT_0068eed0) &&
                 (((&DAT_006826cc)[local_c * 0x120 + local_8 * 0x5b20] & 2) != 0)) &&
                ((char)(&DAT_006826d2)[local_c * 0x120 + local_8 * 0x5b20] == local_14)) &&
               (*(int *)(&DAT_006826e8 + local_c * 0x120 + local_8 * 0x5b20) == local_10)) {
              *(uint *)(&DAT_006826f8 + local_c * 0x120 + local_8 * 0x5b20) =
                   *(uint *)(&DAT_006826f8 + local_c * 0x120 + local_8 * 0x5b20) & 0xfeffffff;
            }
          }
        }
        iVar2 = FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_0068eed0,local_14,local_10);
        if (iVar2 != -1) {
          *(uint *)(&DAT_006826f8 + iVar2 * 0x120 + param_1 * 0x5b20) =
               *(uint *)(&DAT_006826f8 + iVar2 * 0x120 + param_1 * 0x5b20) | 0x1000000;
          *(ushort *)(&DAT_006826d8 + iVar2 * 0x120 + param_1 * 0x5b20) =
               -(*(ushort *)
                  (&DAT_004ff59a +
                  *(int *)(&DAT_006826c4 + local_14 * 0x5b20 + local_10 * 0x120) * 0x34) & 0xbfff);
          *(ushort *)(&DAT_006826da + iVar2 * 0x120 + param_1 * 0x5b20) =
               2 - (*(ushort *)
                     (&DAT_004ff59c +
                     *(int *)(&DAT_006826c4 + local_14 * 0x5b20 + local_10 * 0x120) * 0x34) & 0xbfff
                   );
        }
      }
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b0 + param_1 * 0x5b20 + param_2 * 0x120) * 0x5b20 +
       *(int *)(&DAT_006827b4 + param_1 * 0x5b20 + param_2 * 0x120) * 0x120] = 0;
    }
    if (((param_3 == 0x8a) && (param_2 == DAT_00690c48)) && (param_1 == DAT_0068ecb0)) {
      DAT_0069340c = DAT_0069340c + 0xc;
    }
    if (((param_3 == 0x8b) && (param_2 == DAT_00690c48)) && (param_1 == DAT_0068ecb0)) {
      DAT_0069340c = DAT_0069340c + -0xc;
    }
    uVar1 = 0;
  }
  return uVar1;
}


