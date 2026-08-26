/*
 * Decompiled function: FUN_00463a3e
 * Entry Point: 00463a3e
 * Size: 988 bytes
 */
#include "duel.h"


bool FUN_00463a3e(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  bool bVar3;
  int local_10;
  int local_c;
  
  if (param_3 == 0x73) {
    bVar3 = (*(uint *)(&DAT_006826cc + param_1 * 0x5b20 + param_2 * 0x120) & 0x20010) == 0;
  }
  else {
    if ((param_3 == 0x6d) && (((&DAT_006826cc)[param_1 * 0x5b20 + param_2 * 0x120] & 0x10) == 0)) {
      if ((param_1 == 1) || ((DAT_0066aaf4 == 1 || (DAT_0068f0b0 != 0)))) {
        local_10 = -1;
        local_c = 1;
        while ((local_c < 6 && (local_10 == -1))) {
          if ((0 < (&DAT_0068ece0)[local_c]) &&
             (((int)(char)(&DAT_006826dc)[param_1 * 0x5b20 + param_2 * 0x120] &
              1 << ((byte)local_c & 0x1f)) != 0)) {
            local_10 = local_c;
          }
          local_c = local_c + 1;
        }
        if ((local_10 == -1) && (0 < DAT_0068ece0)) {
          local_10 = 1;
        }
        if ((local_10 == -1) && (0 < DAT_0068ecf8)) {
          local_10 = 1;
        }
        if (local_10 == -1) {
          DAT_00681ea4 = 1;
        }
      }
      else {
        local_10 = -1;
      }
      if (DAT_00681ea4 != 1) {
        FUN_00434660(s_prompts_txt_004f8cf0,s_BIRDS_OF_PARADISE_004f8cdc);
        iVar1 = FUN_004513fa(param_1,&DAT_006679f0,1,local_10,
                             (int)(char)(&DAT_006826dc)[param_1 * 0x5b20 + param_2 * 0x120]);
        if (iVar1 == -1) {
          DAT_00681ea4 = 1;
        }
        else {
          FUN_0049b235(param_1,iVar1,1);
          FUN_0049b00c(param_1,(int)(char)(&DAT_006826dc)[param_1 * 0x5b20 + param_2 * 0x120],1);
          *(uint *)(&DAT_006826cc + param_1 * 0x5b20 + param_2 * 0x120) =
               *(uint *)(&DAT_006826cc + param_1 * 0x5b20 + param_2 * 0x120) | 0x10;
          DAT_0068f0f4 = iVar1;
          if (param_1 != DAT_00676510) {
            FUN_004d9630(&DAT_005f6810,s_to_produce_004f8cfc);
            uVar2 = FUN_0048c420(iVar1);
            FUN_004d9640(&DAT_005f6810,uVar2);
            FUN_004d9640(&DAT_005f6810,s_mana__004f8d08);
            FUN_0045102d(param_1,param_1,param_2,0xffffffff,0xffffffff,&DAT_005f6810,0);
          }
        }
      }
    }
    if ((((param_3 == 0x7f) && (param_2 == DAT_00690c48)) && (param_1 == DAT_0068ecb0)) &&
       ((*(uint *)(&DAT_006826cc + param_1 * 0x5b20 + param_2 * 0x120) & 0x20010) == 0)) {
      FUN_0049af5c(param_1,(int)(char)(&DAT_006826dc)[param_1 * 0x5b20 + param_2 * 0x120],1);
    }
    if (((param_3 == 0x8a) && (param_2 == DAT_00690c48)) && (param_1 == DAT_0068ecb0)) {
      DAT_0069340c = DAT_0069340c +
                     (int)(0x60 / (longlong)(*(int *)(&DAT_0068ef6c + param_1 * 0x20) + 2));
    }
    if (((param_3 == 0x8b) && (param_2 == DAT_00690c48)) && (param_1 == DAT_0068ecb0)) {
      DAT_0069340c = DAT_0069340c -
                     (int)(0x60 / (longlong)(*(int *)(&DAT_0068ef6c + param_1 * 0x20) + 2));
    }
    bVar3 = false;
  }
  return bVar3;
}


