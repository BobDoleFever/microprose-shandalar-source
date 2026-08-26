/*
 * Decompiled function: FUN_0040e560
 * Entry Point: 0040e560
 * Size: 1202 bytes
 */
#include "duel.h"


undefined4 FUN_0040e560(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_10;
  int local_c;
  
  if (((&DAT_006826cc)[param_2 * 0x120 + param_1 * 0x5b20] & 0x10) == 0) {
    FUN_0049b00c(param_1,(int)(char)(&DAT_006826dc)[param_2 * 0x120 + param_1 * 0x5b20],1);
    (&DAT_006826dc)[param_2 * 0x120 + param_1 * 0x5b20] = (&DAT_0068f360)[(1 - param_1) * 4];
    FUN_0049af5c(param_1,(int)(char)(&DAT_006826dc)[param_2 * 0x120 + param_1 * 0x5b20],1);
  }
  if (param_3 == 0x73) {
    if (((((&DAT_006826ce)[param_2 * 0x120 + param_1 * 0x5b20] & 3) == 0) ||
        (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x34] & 2)
         == 0)) && (((&DAT_006826cc)[param_2 * 0x120 + param_1 * 0x5b20] & 0x10) == 0)) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    if (param_3 == 0x6d) {
      if ((char)(&DAT_006826dc)[param_2 * 0x120 + param_1 * 0x5b20] < '\x01') {
        *(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) =
             *(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) | 0x10;
      }
      else {
        if (((param_1 == 1) || (DAT_0066aaf4 == 1)) || (DAT_0068f0b0 != 0)) {
          local_10 = -1;
          local_c = 1;
          while ((local_c < 6 && (local_10 == -1))) {
            if ((0 < (&DAT_0068ece0)[local_c]) &&
               (((int)(char)(&DAT_006826dc)[param_2 * 0x120 + param_1 * 0x5b20] &
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
          FUN_00434660(s_prompts_txt_004f28f8,s_FELLWAR_STONE_004f28e8);
          iVar2 = FUN_004513fa(param_1,&DAT_006679f0,1,local_10,
                               (int)(char)(&DAT_006826dc)[param_2 * 0x120 + param_1 * 0x5b20]);
          if (iVar2 == -1) {
            DAT_00681ea4 = 1;
          }
          else {
            local_10._0_1_ = (byte)iVar2;
            if ((*(uint *)(&DAT_0068f360 + (1 - param_1) * 4) & 1 << ((byte)local_10 & 0x1f)) == 0)
            {
              DAT_00681ea4 = 1;
            }
          }
          if (DAT_00681ea4 != 1) {
            FUN_0049b235(param_1,iVar2,1);
            FUN_0049b00c(param_1,(int)(char)(&DAT_006826dc)[param_2 * 0x120 + param_1 * 0x5b20],1);
            *(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) =
                 *(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) | 0x10;
            DAT_0068f0f4 = iVar2;
            if (param_1 != DAT_00676510) {
              FUN_004d9630(&DAT_005f6810,s_to_produce_004f2904);
              uVar1 = FUN_0048c420(iVar2);
              FUN_004d9640(&DAT_005f6810,uVar1);
              FUN_004d9640(&DAT_005f6810,s_mana__004f2910);
              FUN_0045102d(param_1,param_1,param_2,0xffffffff,0xffffffff,&DAT_005f6810,0);
            }
          }
        }
      }
    }
    if ((((param_3 == 0x77) && (param_2 == DAT_00690c48)) && (param_1 == DAT_0068ecb0)) &&
       (((&DAT_006826cc)[param_2 * 0x120 + param_1 * 0x5b20] & 0x10) == 0)) {
      FUN_0049b00c(param_1,(int)(char)(&DAT_006826dc)[param_2 * 0x120 + param_1 * 0x5b20],1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


