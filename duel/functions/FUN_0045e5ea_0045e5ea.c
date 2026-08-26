/*
 * Decompiled function: FUN_0045e5ea
 * Entry Point: 0045e5ea
 * Size: 1258 bytes
 */
#include "duel.h"


undefined4 FUN_0045e5ea(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  bool bVar3;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  if (param_3 == 0x73) {
    bVar3 = (*(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) & 0x20010) == 0;
    if ((bVar3) && (iVar1 = FUN_0049b309(param_1,3,1), iVar1 == 0)) {
      bVar3 = false;
    }
    if ((bVar3) && (iVar1 = FUN_0049b309(param_1,7,2), iVar1 == 0)) {
      bVar3 = false;
    }
    uVar2 = 0;
    if (bVar3) {
      uVar2 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
      uVar2 = FUN_0041bcf0(0,0,param_1,2,2,0x200,2,0,0,uVar2);
    }
  }
  else if (param_3 == 0x90) {
    FUN_0043071d(0);
    uVar2 = 0;
  }
  else {
    if ((param_3 == 0x6d) &&
       ((*(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) & 0x20010) == 0)) {
      DAT_0068ece0 = 1;
      FUN_0042b6b0(param_1,3,1);
      if (DAT_00681ea4 != 1) {
        FUN_00434660(s_prompts_txt_004f8afc,s_PRADESH_GYPSIES_004f8aec);
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
    }
    if (param_3 == 0x72) {
      local_10 = *(undefined4 *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20);
      local_c = *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20);
      uVar2 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
      iVar1 = FUN_0041c0ab(local_10,local_c,0,param_1,2,2,0x200,2,0,0,uVar2);
      if (iVar1 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        local_8 = FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_0066aaec,local_10,local_c);
        if (local_8 != -1) {
          *(undefined2 *)(&DAT_006826d8 + local_8 * 0x120 + param_1 * 0x5b20) = 0xfffe;
          *(undefined2 *)(&DAT_006826da + local_8 * 0x120 + param_1 * 0x5b20) = 0;
        }
      }
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b0 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20 +
       *(int *)(&DAT_006827b4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120] = 0;
    }
    if ((((param_3 == 0x3b) &&
         ((*(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) & 0x20010) == 0)) &&
        (iVar1 = FUN_0049b309(param_1,3,1), iVar1 != 0)) &&
       (iVar1 = FUN_0049b309(param_1,7,2), iVar1 != 0)) {
      *(int *)(&DAT_00666730 + (1 - param_1) * 4) = *(int *)(&DAT_00666730 + (1 - param_1) * 4) + -2
      ;
    }
    if (((param_3 == 0x8a) && (param_2 == DAT_00690c48)) &&
       ((param_1 == DAT_0068ecb0 && (iVar1 = FUN_0049b309(param_1,3,1), iVar1 != 0)))) {
      DAT_0069340c = DAT_0069340c + 0xc;
    }
    if (((param_3 == 0x8b) && (param_2 == DAT_00690c48)) &&
       ((param_1 == DAT_0068ecb0 && (iVar1 = FUN_0049b309(param_1,3,1), iVar1 != 0)))) {
      DAT_0069340c = DAT_0069340c + -0xc;
    }
    uVar2 = 0;
  }
  return uVar2;
}


