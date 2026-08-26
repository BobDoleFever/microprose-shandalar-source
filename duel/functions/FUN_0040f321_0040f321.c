/*
 * Decompiled function: FUN_0040f321
 * Entry Point: 0040f321
 * Size: 2708 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0040f321(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  if (((param_3 == 0x82) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
    *(uint *)(&DAT_006827c8 + param_2 * 0x120 + param_1 * 0x5b20) =
         *(uint *)(&DAT_006827c8 + param_2 * 0x120 + param_1 * 0x5b20) & 0xfffffffd;
  }
  if (((DAT_0068f2c4 == 1) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
    if (((param_3 == 0x7d) && (((&DAT_006827c8)[param_2 * 0x120 + param_1 * 0x5b20] & 1) != 0)) &&
       ((((&DAT_006827c8)[param_2 * 0x120 + param_1 * 0x5b20] & 2) == 0 &&
        ((_DAT_0068f0cc &
         (byte)(&DAT_004ff594)[*(int *)(&DAT_006826c4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x34])
         == 0)))) {
      if (((param_1 == 1) || (DAT_0066aaf4 == 1)) || (DAT_0068f0b0 != 0)) {
        iVar1 = *(int *)(&DAT_006826ec + param_2 * 0x120 + param_1 * 0x5b20);
        if ((iVar1 == -1) ||
           ((((&DAT_006827c8)
              [*(int *)(&DAT_006826e8 + iVar1 * 0x120 + param_1 * 0x5b20) * 0x120 +
               (char)(&DAT_006826d2)[iVar1 * 0x120 + param_1 * 0x5b20] * 0x5b20] & 1) == 0 &&
            (((&DAT_006826cc)
              [*(int *)(&DAT_006826e8 + iVar1 * 0x120 + param_1 * 0x5b20) * 0x120 +
               (char)(&DAT_006826d2)[iVar1 * 0x120 + param_1 * 0x5b20] * 0x5b20] & 0x10) != 0)))) {
          DAT_0066642c = DAT_0066642c | 2;
        }
      }
      else {
        DAT_0066642c = DAT_0066642c | 1;
      }
    }
    if (param_3 == 0x7e) {
      *(uint *)(&DAT_006827c8 + param_2 * 0x120 + param_1 * 0x5b20) =
           *(uint *)(&DAT_006827c8 + param_2 * 0x120 + param_1 * 0x5b20) | 2;
    }
  }
  if (param_3 == 0x73) {
    if (((((&DAT_006826ce)[param_2 * 0x120 + param_1 * 0x5b20] & 3) == 0) ||
        (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x34] & 2)
         == 0)) &&
       ((((&DAT_006826cc)[param_2 * 0x120 + param_1 * 0x5b20] & 0x10) == 0 &&
        (iVar1 = FUN_0049b309(param_1,7,2), iVar1 != 0)))) {
      uVar2 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
      iVar1 = FUN_0041bcf0(0,0,param_1,2,2,0x200,2,0,0,uVar2);
      if (iVar1 != 0) {
        return 1;
      }
    }
  }
  else if (param_3 == 0x90) {
    FUN_0043071d(0);
  }
  else {
    if (((param_3 == 0x6d) && (((&DAT_006826cc)[param_2 * 0x120 + param_1 * 0x5b20] & 0x10) == 0))
       && ((iVar1 = FUN_0049b309(param_1,7,2), iVar1 != 0 &&
           (FUN_0042b6b0(param_1,0,2), DAT_00681ea4 != 1)))) {
      FUN_00434660(s_prompts_txt_004f2948,s_TAWNOS_WEAPONRY_004f2938);
      uVar2 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0,
                           &DAT_006679f0,1,&local_10);
      iVar1 = FUN_0041e2a2(param_1,2,param_1,0x200,2,0,0,uVar2);
      if (iVar1 == 0) {
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
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b0 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20 +
       *(int *)(&DAT_006827b4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120] = 0;
      uVar2 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
      iVar1 = FUN_0041c0ab(local_10,local_c,0,param_1,2,2,0x200,2,0,0,uVar2);
      if (iVar1 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        local_8 = FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_0066aaec,local_10,local_c);
        if (local_8 != -1) {
          *(uint *)(&DAT_006826f8 + local_8 * 0x120 + param_1 * 0x5b20) =
               *(uint *)(&DAT_006826f8 + local_8 * 0x120 + param_1 * 0x5b20) | 0x20;
          *(undefined2 *)(&DAT_006826d8 + local_8 * 0x120 + param_1 * 0x5b20) = 1;
          *(undefined2 *)(&DAT_006826da + local_8 * 0x120 + param_1 * 0x5b20) = 1;
          (&DAT_006826d3)
          [*(int *)(&DAT_006827b0 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20 +
           *(int *)(&DAT_006827b4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120] =
               (undefined1)param_1;
          *(int *)(&DAT_006826ec +
                  *(int *)(&DAT_006827b0 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20 +
                  *(int *)(&DAT_006827b4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120) = local_8;
        }
      }
    }
    if (param_3 == 0x77) {
      if (((*(int *)(&DAT_006826ec + param_2 * 0x120 + param_1 * 0x5b20) != -1) &&
          ((char)(&DAT_006826d2)
                 [*(int *)(&DAT_006826ec + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
                  (char)(&DAT_006826d3)[param_2 * 0x120 + param_1 * 0x5b20] * 0x5b20] ==
           DAT_0068ecb0)) &&
         (*(int *)(&DAT_006826e8 +
                  *(int *)(&DAT_006826ec + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
                  (char)(&DAT_006826d3)[param_2 * 0x120 + param_1 * 0x5b20] * 0x5b20) ==
          DAT_00690c48)) {
        *(undefined4 *)(&DAT_006826ec + param_2 * 0x120 + param_1 * 0x5b20) = 0xffffffff;
        (&DAT_006826d3)[param_2 * 0x120 + param_1 * 0x5b20] =
             (&DAT_006826ec)[param_2 * 0x120 + param_1 * 0x5b20];
      }
      if (((DAT_00690c48 == param_2) && (DAT_0068ecb0 == param_1)) &&
         (*(int *)(&DAT_006826ec + param_2 * 0x120 + param_1 * 0x5b20) != -1)) {
        FUN_0046e571((int)(char)(&DAT_006826d3)[param_2 * 0x120 + param_1 * 0x5b20],
                     *(undefined4 *)(&DAT_006826ec + param_2 * 0x120 + param_1 * 0x5b20),1);
        *(undefined4 *)(&DAT_006826ec + param_2 * 0x120 + param_1 * 0x5b20) = 0xffffffff;
        (&DAT_006826d3)[param_2 * 0x120 + param_1 * 0x5b20] =
             (&DAT_006826ec)[param_2 * 0x120 + param_1 * 0x5b20];
      }
    }
    if ((*(int *)(&DAT_006826ec + param_2 * 0x120 + param_1 * 0x5b20) != -1) &&
       (((&DAT_006826cc)[param_2 * 0x120 + param_1 * 0x5b20] & 0x10) == 0)) {
      FUN_0046e571((int)(char)(&DAT_006826d3)[param_2 * 0x120 + param_1 * 0x5b20],
                   *(undefined4 *)(&DAT_006826ec + param_2 * 0x120 + param_1 * 0x5b20),1);
      *(undefined4 *)(&DAT_006826ec + param_2 * 0x120 + param_1 * 0x5b20) = 0xffffffff;
    }
    if (((param_3 == 0x3b) &&
        ((*(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) & 0x20010) == 0)) &&
       (iVar1 = FUN_0049b309(param_1,7,2), iVar1 != 0)) {
      *(int *)(&DAT_00666730 + param_1 * 4) = *(int *)(&DAT_00666730 + param_1 * 4) + 1;
      *(int *)(&DAT_00666738 + param_1 * 4) = *(int *)(&DAT_00666738 + param_1 * 4) + 1;
    }
  }
  return 0;
}


