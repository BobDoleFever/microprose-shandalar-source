/*
 * Decompiled function: Prompts_Load_00406226
 * Entry Point: 00406226
 * Size: 1103 bytes
 */
#include "duel.h"


int Prompts_Load_00406226(int spell_id,int target_id,int flags)

{
  int iVar1;
  int local_10;
  int local_c;
  int local_8;
  
  if (flags == 0x74) {
    local_8 = 0;
    local_10 = 0;
    while (((local_10 < 500 && (local_8 == 0)) &&
           (*(int *)(&DAT_0068f370 + local_10 * 4 + spell_id * 2000) != -1))) {
      if (((&DAT_004ff594)[*(int *)(&DAT_0068f370 + local_10 * 4 + spell_id * 2000) * 0x34] & 2) !=
          0) {
        local_8 = 1;
      }
      local_10 = local_10 + 1;
    }
  }
  else {
    if (((flags == 0x6c) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) {
      if ((DAT_00676510 == spell_id) && (DAT_0066aaf4 != 1)) {
        FUN_00434660(s_prompts_txt_004f22c0,s_RAISEDEAD_004f22b4);
        do {
          local_c = Pic_Load_advfac64_004d6639
                              (spell_id,(int *)(&DAT_0068f370 + spell_id * 2000),500,&DAT_006679f0,0
                               ,s_Cancel_004f22cc);
          if (local_c == -1) break;
        } while (((&DAT_004ff594)[*(int *)(&DAT_0068f370 + local_c * 4 + spell_id * 2000) * 0x34] &
                 2) == 0);
      }
      else {
        local_c = FUN_0040800f(spell_id,2);
      }
      if (((local_c == -1) || (*(int *)(&DAT_0068f370 + local_c * 4 + spell_id * 2000) == -1)) ||
         (((&DAT_004ff594)[*(int *)(&DAT_0068f370 + local_c * 4 + spell_id * 2000) * 0x34] & 2) == 0
         )) {
        DAT_00681ea4 = 1;
      }
      else {
        iVar1 = FUN_004d695b(spell_id,*(int *)(&DAT_0068f370 + local_c * 4 + spell_id * 2000));
        *(uint *)(&DAT_006826cc + spell_id * 0x5b20 + iVar1 * 0x120) =
             *(uint *)(&DAT_006826cc + spell_id * 0x5b20 + iVar1 * 0x120) | 0x20;
        *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) = spell_id;
        *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20) = iVar1;
        (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        *(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) = local_c;
      }
    }
    if (flags == 0x71) {
      iVar1 = *(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20);
      if (((iVar1 == -1) || (*(int *)(&DAT_0068f370 + iVar1 * 4 + spell_id * 2000) == -1)) ||
         (((&DAT_004ff594)[*(int *)(&DAT_0068f370 + iVar1 * 4 + spell_id * 2000) * 0x34] & 2) == 0))
      {
        *(undefined4 *)
         (&DAT_006826c4 +
         *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
         *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20) = 0xffffffff;
      }
      else {
        FUN_0046f116(spell_id,iVar1);
        *(uint *)(&DAT_006826cc +
                 *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                 *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20) =
             *(uint *)(&DAT_006826cc +
                      *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                      *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20) &
             0xffffffdf;
      }
      (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      FUN_0046e571(spell_id,target_id,1);
    }
    local_8 = 0;
  }
  return local_8;
}


