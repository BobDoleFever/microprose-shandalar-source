/*
 * Decompiled function: FUN_004bc5ee
 * Entry Point: 004bc5ee
 * Size: 1675 bytes
 */
#include "duel.h"


undefined4 FUN_004bc5ee(int param_1,int param_2,int param_3)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int local_1c;
  int local_18;
  int local_14 [4];
  
  if (param_3 == 0x74) {
    uVar2 = 1;
  }
  else {
    if ((((param_3 == 0x6c) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) &&
       (iVar3 = FUN_00404b06(param_1,*(undefined4 *)
                                      (&DAT_006826c4 + param_2 * 0x120 + param_1 * 0x5b20),param_1),
       iVar3 == 0)) {
      DAT_0068f2d4 = DAT_0068f2d4 +
                     ((*(int *)(&DAT_0068ef6c + (1 - param_1) * 0x20) -
                      *(int *)(&DAT_0068ef6c + param_1 * 0x20)) * 3 + 6) * 4;
    }
    if (param_3 == 0x73) {
      if ((((DAT_0068f2c4 == 4) && (DAT_00666458 == param_1)) && (param_1 == DAT_00681eb4)) &&
         ((*(int *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) == 0 &&
          (*(int *)(&DAT_0068ef6c + param_1 * 0x20) < *(int *)(&DAT_0068ef6c + (1 - param_1) * 0x20)
          )))) {
        iVar3 = FUN_0048c367((int)(char)(&DAT_006826dd)[param_2 * 0x120 + param_1 * 0x5b20]);
        if ((*(int *)(&DAT_00676150 + iVar3 * 4) == 0) ||
           (iVar3 = FUN_0049b68d(param_1,param_2,7,0), iVar3 != 0)) {
          if ((DAT_00676510 != param_1) && (*(int *)(&DAT_00666a00 + param_1 * 2000) != -1)) {
            DAT_00676500 = DAT_00676500 | 3;
          }
          uVar2 = 1;
        }
        else {
          uVar2 = 0;
        }
      }
      else {
        uVar2 = 0;
      }
    }
    else {
      if (((param_3 == 0x6d) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
        iVar3 = FUN_0048c367((int)(char)(&DAT_006826dd)[param_2 * 0x120 + param_1 * 0x5b20]);
        if (*(int *)(&DAT_00676150 + iVar3 * 4) != 0) {
          FUN_0042ecaf(param_1,param_2,0,0);
        }
        if (DAT_00681ea4 != 1) {
          *(int *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) =
               *(int *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) + 1;
        }
      }
      if (param_3 == 0x72) {
        if ((DAT_00676510 == param_1) && (DAT_0066aaf4 != 1)) {
          FUN_00434660(s_prompts_txt_00508834,s_LANDTAX_0050882c);
          iVar3 = FUN_00448b6f(&DAT_006669f0 + param_1 * 2000,500,local_14,3);
          for (local_18 = 0; local_18 < iVar3; local_18 = local_18 + 1) {
            FUN_004d695b(param_1,*(undefined4 *)
                                  (&DAT_006669f0 + local_14[local_18] * 4 + param_1 * 2000));
          }
          if (iVar3 == 1) {
            FUN_004d7acc(param_1,local_14[0]);
          }
          if (iVar3 == 2) {
            iVar4 = local_14[1];
            if (local_14[1] <= local_14[0]) {
              iVar4 = local_14[0];
            }
            FUN_004d7acc(param_1,iVar4);
            iVar4 = local_14[1];
            if (local_14[0] <= local_14[1]) {
              iVar4 = local_14[0];
            }
            FUN_004d7acc(param_1,iVar4);
          }
          if (iVar3 == 3) {
            FUN_004d7acc(param_1,local_14[0]);
            if (local_14[0] < local_14[1]) {
              local_14[1] = local_14[1] + -1;
            }
            if (local_14[0] < local_14[2]) {
              local_14[2] = local_14[2] + -1;
            }
            iVar3 = local_14[1];
            if (local_14[1] <= local_14[2]) {
              iVar3 = local_14[2];
            }
            FUN_004d7acc(param_1,iVar3);
            iVar3 = local_14[1];
            if (local_14[2] <= local_14[1]) {
              iVar3 = local_14[2];
            }
            FUN_004d7acc(param_1,iVar3);
          }
          FUN_00451482(0,0xff);
        }
        else {
          local_1c = 0;
          local_18 = 0;
          bVar1 = false;
          while ((local_18 < (int)(&DAT_0068ee78)[param_1] && (!bVar1))) {
            if (((&DAT_004ff594)
                 [*(int *)(&DAT_006826c4 + local_18 * 0x120 + param_1 * 0x5b20) * 0x34] & 1) != 0) {
              bVar1 = true;
            }
            local_18 = local_18 + 1;
          }
          if (!bVar1) {
            DAT_0068f2d4 = DAT_0068f2d4 + 0x30;
          }
          iVar3 = FUN_0049aa14(8 - (&DAT_0068ee78)[param_1],1,3);
          for (local_18 = 0; local_18 < iVar3; local_18 = local_18 + 1) {
            local_14[3] = FUN_00408121(param_1,param_1,1);
            if (4 < *(int *)(&DAT_006669f0 + local_14[3] * 4 + param_1 * 2000)) {
              local_14[3] = -1;
              local_18 = 0;
              while (((local_18 < 500 && (local_14[3] == -1)) &&
                     (*(int *)(&DAT_006669f0 + local_18 * 4 + param_1 * 2000) != -1))) {
                if (*(int *)(&DAT_006669f0 + local_18 * 4 + param_1 * 2000) < 5) {
                  local_14[3] = local_18;
                }
                local_18 = local_18 + 1;
              }
            }
            if ((local_14[3] != -1) &&
               (*(int *)(&DAT_006669f0 + local_14[3] * 4 + param_1 * 2000) != -1)) {
              local_14[local_1c] = *(int *)(&DAT_006669f0 + local_14[3] * 4 + param_1 * 2000);
              local_1c = local_1c + 1;
              FUN_004d7acc(param_1,local_14[3]);
            }
          }
          if (param_1 == 1) {
            FUN_004d6639(0,local_14,local_1c,s_Opponent_chose_these_basic_lands_00508808,0,
                         &DAT_00508800);
          }
          for (local_18 = 0; local_18 < local_1c; local_18 = local_18 + 1) {
            FUN_004d695b(param_1,local_14[local_18]);
          }
        }
        FUN_004d7946(param_1);
      }
      if (((param_3 == 0x22) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
        *(undefined4 *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) = 0;
      }
      uVar2 = 0;
    }
  }
  return uVar2;
}


