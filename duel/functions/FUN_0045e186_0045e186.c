/*
 * Decompiled function: FUN_0045e186
 * Entry Point: 0045e186
 * Size: 1124 bytes
 */
#include "duel.h"


undefined4 FUN_0045e186(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  bool bVar4;
  int local_10;
  int local_c;
  int local_8;
  
  if (param_3 == 0x73) {
    bVar4 = (*(uint *)(&DAT_006826cc + param_1 * 0x5b20 + param_2 * 0x120) & 0x20010) == 0;
    if ((bVar4) && (iVar2 = FUN_0049b309(param_1,4,2), iVar2 == 0)) {
      bVar4 = false;
    }
    if ((bVar4) && (iVar2 = FUN_0049b309(param_1,7,3), iVar2 == 0)) {
      bVar4 = false;
    }
    uVar3 = 0;
    if (bVar4) {
      uVar3 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
      uVar3 = FUN_0041bcf0(0,0,param_1,2,2,0x200,2,0,0,uVar3);
    }
  }
  else if (param_3 == 0x90) {
    FUN_0043071d(0);
    uVar3 = 0;
  }
  else {
    if (((param_2 == DAT_00690c48) && (param_1 == DAT_0068ecb0)) &&
       (((&DAT_006826cc)[param_1 * 0x5b20 + param_2 * 0x120] & 0x44) != 0)) {
      if (param_3 == 0x32) {
        DAT_0066642c = DAT_0066642c + 1;
      }
      if (param_3 == 0x33) {
        DAT_0066642c = DAT_0066642c + -2;
      }
    }
    if ((param_3 == 0x6d) &&
       ((*(uint *)(&DAT_006826cc + param_1 * 0x5b20 + param_2 * 0x120) & 0x20010) == 0)) {
      DAT_0068ece0 = 1;
      FUN_0042b6b0(param_1,4,2);
      if (DAT_00681ea4 != 1) {
        FUN_00434660(s_prompts_txt_004f8ae0,s_CAVE_PEOPLE_004f8ad4);
        uVar3 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0,
                             &DAT_006679f0,1,&local_10);
        iVar2 = FUN_0041e2a2(param_1,2,param_1,0x200,2,0,0,uVar3);
        if (iVar2 == 0) {
          DAT_00681ea4 = 1;
        }
        else {
          *(int *)(&DAT_00682718 + param_1 * 0x5b20 + param_2 * 0x120) = local_10;
          *(int *)(&DAT_0068271c + param_1 * 0x5b20 + param_2 * 0x120) = local_c;
          (&DAT_006827b8)[param_1 * 0x5b20 + param_2 * 0x120] = 1;
          *(uint *)(&DAT_006826cc + param_1 * 0x5b20 + param_2 * 0x120) =
               *(uint *)(&DAT_006826cc + param_1 * 0x5b20 + param_2 * 0x120) | 0x10;
        }
      }
    }
    if (param_3 == 0x72) {
      local_10 = *(int *)(&DAT_00682718 + param_1 * 0x5b20 + param_2 * 0x120);
      local_c = *(int *)(&DAT_0068271c + param_1 * 0x5b20 + param_2 * 0x120);
      uVar3 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
      iVar2 = FUN_0041c0ab(local_10,local_c,0,param_1,2,2,0x200,2,0,0,uVar3);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        local_8 = FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_00667994,local_10,local_c);
        if (local_8 != -1) {
          cVar1 = FUN_004af74c(param_1,param_2,4);
          *(int *)(&DAT_006826e4 + local_8 * 0x120 + param_1 * 0x5b20) = 1 << (cVar1 - 1U & 0x1f);
        }
        *(undefined4 *)(&DAT_006826fc + local_10 * 0x5b20 + local_c * 0x120) = 0x8000000;
      }
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b4 + param_1 * 0x5b20 + param_2 * 0x120) * 0x120 +
       *(int *)(&DAT_006827b0 + param_1 * 0x5b20 + param_2 * 0x120) * 0x5b20] = 0;
    }
    uVar3 = 0;
  }
  return uVar3;
}


