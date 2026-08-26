/*
 * Decompiled function: Prompts_Load_0040abf8
 * Entry Point: 0040abf8
 * Size: 1839 bytes
 */
#include "duel.h"


undefined4 Prompts_Load_0040abf8(int spell_id,int target_id,int flags)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int local_164;
  int local_160;
  int local_15c;
  int local_150 [80];
  int local_10;
  int local_c;
  undefined4 local_8;
  
  if ((((DAT_0068f230 == 0xcf) &&
       (((&DAT_006826cc)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0)) &&
      (iVar3 = FUN_0049b309(spell_id,7,1), iVar3 != 0)) &&
     (((DAT_00690c48 == target_id && (DAT_0068ecb0 == spell_id)) && (DAT_00681ec4 == spell_id)))) {
    if (flags == 0x7d) {
      if (DAT_00676504 == spell_id) {
        if (((*(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) != 0) &&
            (local_10 = FUN_0049b309(spell_id,7,3), local_10 != 0)) &&
           (DAT_0066642c = DAT_0066642c | 2,
           *(int *)(&DAT_006826f0 + target_id * 0x120 + spell_id * 0x5b20) == 0)) {
          iVar3 = FUN_00439892(local_10 + -2);
          *(int *)(&DAT_006826f0 + target_id * 0x120 + spell_id * 0x5b20) = iVar3 + 2;
          DAT_00666410 = *(undefined4 *)(&DAT_006826f0 + target_id * 0x120 + spell_id * 0x5b20);
        }
      }
      else {
        DAT_0066642c = DAT_0066642c | 1;
      }
    }
    if (flags == 0x7e) {
      *(undefined4 *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) = 0;
      iVar3 = DAT_00681ea0;
      local_8 = DAT_0068ed04;
      DAT_0068ed04 = 0xffffffff;
      if (((DAT_00676510 == spell_id) && (DAT_0066aaf4 != 1)) && (DAT_0068f0b0 == 0)) {
        FUN_0048d878(spell_id,target_id,0x72,0,0);
        FUN_0042b6b0(spell_id,0,-1);
        FUN_0048e251();
        local_164 = DAT_00681ea0;
      }
      else {
        local_164 = FUN_0042b6b0(spell_id,0,
                                 *(int *)(&DAT_006826f0 + target_id * 0x120 + spell_id * 0x5b20));
        if (local_164 == 0) {
          DAT_00681ea4 = 1;
        }
        *(undefined4 *)(&DAT_006826f0 + target_id * 0x120 + spell_id * 0x5b20) = 0;
      }
      DAT_0068ed04 = local_8;
      DAT_00681ea0 = iVar3;
      if ((DAT_00681ea4 == 1) || (local_164 < 1)) {
        DAT_00681ea4 = -1;
      }
      else {
        *(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
        local_10 = 0;
        for (local_160 = 0; local_160 < local_164; local_160 = local_160 + 1) {
          if (*(int *)(&DAT_006669f0 + local_160 * 4 + spell_id * 2000) != -1) {
            local_150[local_10] = *(int *)(&DAT_006669f0 + local_160 * 4 + spell_id * 2000);
            local_10 = local_10 + 1;
          }
        }
        local_150[local_10] = -1;
        if (((DAT_00676510 == spell_id) && (DAT_0066aaf4 != 1)) && (DAT_0068f0b0 == 0)) {
          FUN_00434660(s_prompts_txt_004f2700,s_ALADDINS_LAMP_004f26f0);
          local_15c = Pic_Load_advfac64_004d6639
                                (spell_id,local_150,local_10,&DAT_006679f0,1,&DAT_004f270c);
        }
        else {
          local_15c = FUN_0040826f(spell_id,spell_id,2,(int)local_150);
          if (local_15c == -1) {
            local_15c = 0;
          }
        }
        if (local_10 != 0) {
          FUN_004d695b(spell_id,local_150[local_15c]);
          for (local_160 = 0; local_160 < local_10; local_160 = local_160 + 1) {
            FUN_004d7acc(spell_id,0);
          }
          local_150[local_15c] = -1;
          bVar2 = false;
          while (!bVar2) {
            local_160 = 0;
            do {
              local_15c = FUN_00439892(local_164);
              if (local_150[local_15c] != -1) break;
              bVar1 = local_160 < 999;
              local_160 = local_160 + 1;
            } while (bVar1);
            if (local_150[local_15c] == -1) {
              for (local_160 = 0; local_160 < local_164; local_160 = local_160 + 1) {
                if (local_150[local_160] != -1) {
                  local_15c = local_160;
                }
              }
            }
            if (local_150[local_15c] == -1) {
              bVar2 = true;
            }
            else {
              FUN_004d7b2d(spell_id,local_150[local_15c]);
              local_150[local_15c] = -1;
            }
          }
        }
        DAT_0068ef90 = 1;
      }
    }
  }
  if ((flags == 0x6a) && (DAT_00676504 == spell_id)) {
    *(undefined4 *)(&DAT_006826f0 + target_id * 0x120 + spell_id * 0x5b20) = 0;
    local_c = 0;
    local_10 = 0;
    for (local_160 = 0; local_160 < (int)(&DAT_00666408)[DAT_00676504]; local_160 = local_160 + 1) {
      if ((((*(int *)(&DAT_006826c4 + local_160 * 0x120 + DAT_00676504 * 0x5b20) != -1) &&
           (((&DAT_006826cc)[local_160 * 0x120 + DAT_00676504 * 0x5b20] & 2) != 0)) &&
          (((&DAT_004ff5a9)
            [*(int *)(&DAT_006826c4 + local_160 * 0x120 + DAT_00676504 * 0x5b20) * 0x34] & 0x10) !=
           0)) && (local_10 = local_10 + 1,
                  ((&DAT_006826cc)[local_160 * 0x120 + DAT_00676504 * 0x5b20] & 0x10) == 0)) {
        local_c = local_c + 1;
      }
    }
    if (0x50 < (local_c * 100) / local_10) {
      *(undefined4 *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) = 2;
    }
  }
  return 0;
}


