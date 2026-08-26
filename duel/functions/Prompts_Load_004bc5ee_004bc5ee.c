/*
 * Decompiled function: Prompts_Load_004bc5ee
 * Entry Point: 004bc5ee
 * Size: 1675 bytes
 */
#include "duel.h"


undefined4 Prompts_Load_004bc5ee(int spell_id,int target_id,int flags)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int local_1c;
  int local_18;
  int local_14 [4];
  
  if (flags == 0x74) {
    uVar2 = 1;
  }
  else {
    if ((((flags == 0x6c) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) &&
       (iVar3 = FUN_00404b06(spell_id,*(int *)(&DAT_006826c4 + target_id * 0x120 + spell_id * 0x5b20
                                              ),spell_id), iVar3 == 0)) {
      DAT_0068f2d4 = DAT_0068f2d4 +
                     ((*(int *)(&DAT_0068ef6c + (1 - spell_id) * 0x20) -
                      *(int *)(&DAT_0068ef6c + spell_id * 0x20)) * 3 + 6) * 4;
    }
    if (flags == 0x73) {
      if ((((DAT_0068f2c4 == 4) && (DAT_00666458 == spell_id)) && (spell_id == DAT_00681eb4)) &&
         ((*(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) == 0 &&
          (*(int *)(&DAT_0068ef6c + spell_id * 0x20) <
           *(int *)(&DAT_0068ef6c + (1 - spell_id) * 0x20))))) {
        iVar3 = FUN_0048c367((&DAT_006826dd)[target_id * 0x120 + spell_id * 0x5b20]);
        if ((*(int *)(&DAT_00676150 + iVar3 * 4) == 0) ||
           (iVar3 = FUN_0049b68d(spell_id,target_id,7,0), iVar3 != 0)) {
          if ((DAT_00676510 != spell_id) && (*(int *)(&DAT_00666a00 + spell_id * 2000) != -1)) {
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
      if (((flags == 0x6d) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) {
        iVar3 = FUN_0048c367((&DAT_006826dd)[target_id * 0x120 + spell_id * 0x5b20]);
        if (*(int *)(&DAT_00676150 + iVar3 * 4) != 0) {
          FUN_0042ecaf(spell_id,target_id,0,0);
        }
        if (DAT_00681ea4 != 1) {
          *(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) =
               *(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) + 1;
        }
      }
      if (flags == 0x72) {
        if ((DAT_00676510 == spell_id) && (DAT_0066aaf4 != 1)) {
          FUN_00434660(s_prompts_txt_00508834,s_LANDTAX_0050882c);
          iVar3 = FUN_00448b6f(&DAT_006669f0 + spell_id * 2000,500,(int)local_14,3);
          for (local_18 = 0; local_18 < iVar3; local_18 = local_18 + 1) {
            FUN_004d695b(spell_id,*(int *)(&DAT_006669f0 + local_14[local_18] * 4 + spell_id * 2000)
                        );
          }
          if (iVar3 == 1) {
            FUN_004d7acc(spell_id,local_14[0]);
          }
          if (iVar3 == 2) {
            iVar4 = local_14[1];
            if (local_14[1] <= local_14[0]) {
              iVar4 = local_14[0];
            }
            FUN_004d7acc(spell_id,iVar4);
            iVar4 = local_14[1];
            if (local_14[0] <= local_14[1]) {
              iVar4 = local_14[0];
            }
            FUN_004d7acc(spell_id,iVar4);
          }
          if (iVar3 == 3) {
            FUN_004d7acc(spell_id,local_14[0]);
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
            FUN_004d7acc(spell_id,iVar3);
            iVar3 = local_14[1];
            if (local_14[2] <= local_14[1]) {
              iVar3 = local_14[2];
            }
            FUN_004d7acc(spell_id,iVar3);
          }
          FUN_00451482(0,0xff);
        }
        else {
          local_1c = 0;
          local_18 = 0;
          bVar1 = false;
          while ((local_18 < (int)(&DAT_0068ee78)[spell_id] && (!bVar1))) {
            if (((&DAT_004ff594)
                 [*(int *)(&DAT_006826c4 + local_18 * 0x120 + spell_id * 0x5b20) * 0x34] & 1) != 0)
            {
              bVar1 = true;
            }
            local_18 = local_18 + 1;
          }
          if (!bVar1) {
            DAT_0068f2d4 = DAT_0068f2d4 + 0x30;
          }
          iVar3 = FUN_0049aa14(8 - (&DAT_0068ee78)[spell_id],1,3);
          for (local_18 = 0; local_18 < iVar3; local_18 = local_18 + 1) {
            local_14[3] = FUN_00408121(spell_id,spell_id,1);
            if (4 < *(int *)(&DAT_006669f0 + local_14[3] * 4 + spell_id * 2000)) {
              local_14[3] = -1;
              local_18 = 0;
              while (((local_18 < 500 && (local_14[3] == -1)) &&
                     (*(int *)(&DAT_006669f0 + local_18 * 4 + spell_id * 2000) != -1))) {
                if (*(int *)(&DAT_006669f0 + local_18 * 4 + spell_id * 2000) < 5) {
                  local_14[3] = local_18;
                }
                local_18 = local_18 + 1;
              }
            }
            if ((local_14[3] != -1) &&
               (*(int *)(&DAT_006669f0 + local_14[3] * 4 + spell_id * 2000) != -1)) {
              local_14[local_1c] = *(int *)(&DAT_006669f0 + local_14[3] * 4 + spell_id * 2000);
              local_1c = local_1c + 1;
              FUN_004d7acc(spell_id,local_14[3]);
            }
          }
          if (spell_id == 1) {
            Pic_Load_advfac64_004d6639
                      (0,local_14,local_1c,s_Opponent_chose_these_basic_lands_00508808,0,
                       &DAT_00508800);
          }
          for (local_18 = 0; local_18 < local_1c; local_18 = local_18 + 1) {
            FUN_004d695b(spell_id,local_14[local_18]);
          }
        }
        FUN_004d7946(spell_id);
      }
      if (((flags == 0x22) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) {
        *(undefined4 *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) = 0;
      }
      uVar2 = 0;
    }
  }
  return uVar2;
}


