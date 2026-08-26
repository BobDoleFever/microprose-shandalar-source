/*
 * Decompiled function: Pic_Subsystem_00429e7d
 * Entry Point: 004bcc7e
 * Size: 601 bytes
 */
#include "duel.h"


int Pic_Subsystem_00429e7d(int spell_id,int target_id,int flags)

{
  int iVar1;
  int local_c;
  undefined4 local_8;
  
  if (flags == 0x74) {
    iVar1 = 1;
  }
  else {
    if (((flags == 0x6c) && (target_id == DAT_00690c48)) && (spell_id == DAT_0068ecb0)) {
      iVar1 = FUN_00404b06(spell_id,*(int *)(&DAT_006826c4 + spell_id * 0x5b20 + target_id * 0x120),
                           -1);
      if (iVar1 == 0) {
        DAT_0068f2d4 = DAT_0068f2d4 + 0x30;
      }
    }
    if (((flags == 0x6c) && (target_id == DAT_00690c48)) && (spell_id == DAT_0068ecb0)) {
      FUN_00434660(s_prompts_txt_00508848,s_KISMET_00508840);
      iVar1 = Action_ValidateTarget_0041e2a2
                        (spell_id,2,1 - spell_id,0x1000,0,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,
                         0,&DAT_006679f0,1,&local_c);
      if (iVar1 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(int *)(&DAT_006826e4 + spell_id * 0x5b20 + target_id * 0x120) = local_c;
        *(int *)(&DAT_00682718 + spell_id * 0x5b20 + target_id * 0x120) = local_c;
        *(undefined4 *)(&DAT_0068271c + spell_id * 0x5b20 + target_id * 0x120) = local_8;
        (&DAT_006827b8)[spell_id * 0x5b20 + target_id * 0x120] = 1;
      }
    }
    iVar1 = target_id * 0x120;
    if (((((&DAT_006826cc)[spell_id * 0x5b20 + iVar1] & 0x20) == 0) && (flags == 0x6c)) &&
       ((iVar1 = target_id * 0x120,
        *(int *)(&DAT_006826e4 + spell_id * 0x5b20 + iVar1) == DAT_0068ecb0 &&
        (iVar1 = *(int *)(&DAT_006826c4 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) * 0xd,
        ((&DAT_004ff594)
         [*(int *)(&DAT_006826c4 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) * 0x34] & 0x43) !=
        0)))) {
      iVar1 = DAT_00690c48 * 0x120;
      *(uint *)(&DAT_006826cc + DAT_0068ecb0 * 0x5b20 + iVar1) =
           *(uint *)(&DAT_006826cc + DAT_0068ecb0 * 0x5b20 + iVar1) | 0x10;
    }
  }
  return iVar1;
}


