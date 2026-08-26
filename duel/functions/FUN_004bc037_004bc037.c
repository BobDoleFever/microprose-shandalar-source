/*
 * Decompiled function: FUN_004bc037
 * Entry Point: 004bc037
 * Size: 1463 bytes
 */
#include "duel.h"


undefined4 FUN_004bc037(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_10c;
  uint local_104;
  int local_100;
  int local_fc;
  int local_f8;
  undefined4 local_f4 [30];
  int aiStack_7c [30];
  
  if (param_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (param_3 == 0x6c) {
      DAT_0068f2d4 = DAT_0068f2d4 + 0x30;
    }
    if ((((param_3 == 0x73) && (DAT_00666458 == param_1)) &&
        (*(int *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) == 0)) && (DAT_0068f2c4 == 10)
       ) {
      iVar2 = FUN_0048c367((int)(char)(&DAT_006826dd)[param_2 * 0x120 + param_1 * 0x5b20]);
      if ((*(int *)(&DAT_00676150 + iVar2 * 4) == 0) ||
         (iVar2 = FUN_0049b68d(param_1,param_2,7,0), iVar2 != 0)) {
        if (param_1 == DAT_00676504) {
          DAT_00676500 = DAT_00676500 | 3;
        }
        uVar1 = 1;
      }
      else {
        uVar1 = 0;
      }
    }
    else {
      if ((param_3 == 0x6d) && (*(int *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) == 0))
      {
        iVar2 = FUN_0048c367((int)(char)(&DAT_006826dd)[param_2 * 0x120 + param_1 * 0x5b20]);
        if (*(int *)(&DAT_00676150 + iVar2 * 4) != 0) {
          FUN_0042ecaf(param_1,param_2,0,0);
        }
        if (DAT_00681ea4 != 1) {
          *(undefined4 *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) = 1;
        }
      }
      if ((param_3 == 0x72) && (*(int *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) != 0))
      {
        for (local_f8 = 0; local_f8 < 2; local_f8 = local_f8 + 1) {
          FUN_00487ce1(DAT_00666458);
        }
        for (local_f8 = 0; local_f8 < 2; local_f8 = local_f8 + 1) {
          local_10c = 0;
          for (local_100 = 0; local_100 < (int)(&DAT_00666408)[param_1]; local_100 = local_100 + 1)
          {
            if (((*(int *)(&DAT_006826c4 + local_100 * 0x120 + param_1 * 0x5b20) != -1) &&
                (((&DAT_006826cc)[local_100 * 0x120 + param_1 * 0x5b20] & 1) != 0)) &&
               (((&DAT_006826cc)[local_100 * 0x120 + param_1 * 0x5b20] & 2) == 0)) {
              local_f4[local_10c] =
                   *(undefined4 *)(&DAT_006826c4 + local_100 * 0x120 + param_1 * 0x5b20);
              aiStack_7c[local_10c] = local_100;
              local_10c = local_10c + 1;
            }
          }
          local_fc = 0;
          if (0x12 < (int)(&DAT_00681ea8)[param_1]) {
            local_fc = (&DAT_00681ea8)[param_1] + 0x1e;
          }
          if ((int)(&DAT_0068ee78)[param_1] < 7) {
            local_fc = local_fc + (7 - (&DAT_0068ee78)[param_1]) * 5 + 10;
          }
          if ((0 < local_f8) && (local_104 == 0)) {
            local_fc = local_fc / 2;
          }
          if ((int)(&DAT_00681ea8)[param_1] < 4) {
            local_fc = 0;
          }
          iVar2 = FUN_00439892(100);
          local_104 = (uint)(local_fc <= iVar2);
          iVar2 = FUN_0045102d(param_1,DAT_00690af0,DAT_0068efa0,0xffffffff,0xffffffff,
                               s_Lose_4_life__Put_back_on_library_005087bc,local_104);
          if (iVar2 == 0) {
            (&DAT_00681ea8)[param_1] = (&DAT_00681ea8)[param_1] + -4;
          }
          else if (((param_1 == DAT_00676510) && (DAT_0066aaf4 != 1)) && (DAT_0068f0b0 == 0)) {
            FUN_00434660(s_prompts_txt_005087f0,s_SYLVAN_LIBRARY_005087e0);
            iVar2 = FUN_004d6639(param_1,local_f4,local_10c,&DAT_006679f0,1,&DAT_005087fc);
            FUN_004d7baa(param_1,local_f4[iVar2]);
            *(undefined4 *)(&DAT_006826c4 + param_1 * 0x5b20 + aiStack_7c[iVar2] * 0x120) =
                 0xffffffff;
            (&DAT_0068ee78)[param_1] = (&DAT_0068ee78)[param_1] + -1;
          }
          else if (0 < local_10c) {
            iVar2 = FUN_00439892(local_10c);
            FUN_004d7baa(param_1,local_f4[iVar2]);
            *(undefined4 *)(&DAT_006826c4 + param_1 * 0x5b20 + aiStack_7c[iVar2] * 0x120) =
                 0xffffffff;
            (&DAT_0068ee78)[param_1] = (&DAT_0068ee78)[param_1] + -1;
          }
        }
      }
      if (((param_3 == 0x22) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
        *(undefined4 *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) = 0;
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}


