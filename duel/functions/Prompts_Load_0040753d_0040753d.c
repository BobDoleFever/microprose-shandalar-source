/*
 * Decompiled function: Prompts_Load_0040753d
 * Entry Point: 0040753d
 * Size: 559 bytes
 */
#include "duel.h"


undefined4 Prompts_Load_0040753d(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  int local_c;
  undefined4 local_8;
  
  if (flags == 0x74) {
    uVar1 = 1;
  }
  else {
    if (((flags == 0x6c) && (target_id == DAT_00690c48)) && (spell_id == DAT_0068ecb0)) {
      FUN_00434660(s_prompts_txt_004f23b4,s_VISIONS_004f23ac);
      iVar2 = Action_ValidateTarget_0041e2a2
                        (spell_id,2,1 - spell_id,0x1000,0,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,
                         0,&DAT_006679f0,1,&local_c);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(int *)(&DAT_00682718 + spell_id * 0x5b20 + target_id * 0x120) = local_c;
        *(undefined4 *)(&DAT_0068271c + spell_id * 0x5b20 + target_id * 0x120) = local_8;
        (&DAT_006827b8)[spell_id * 0x5b20 + target_id * 0x120] = 1;
      }
    }
    if (flags == 0x71) {
      if (((spell_id == 0) && (DAT_0066aaf4 != 1)) && (DAT_0068f0b0 == 0)) {
        FUN_00434660(s_prompts_txt_004f23c8,s_VISIONS_004f23c0);
        Pic_Load_advfac64_004d6639
                  (0,(int *)(&DAT_006669f0 + *(int *)(&DAT_00682718 + target_id * 0x120) * 2000),5,
                   &DAT_00667aea,0,&DAT_004f23d4);
      }
      iVar2 = FUN_0045102d(spell_id,spell_id,target_id,-1,-1,
                           s_Shuffle_library__Don_t_shuffle__004f23dc,1);
      if (iVar2 == 0) {
        FUN_004d7946(*(int *)(&DAT_00682718 + spell_id * 0x5b20 + target_id * 0x120));
      }
      (&DAT_006827b8)[spell_id * 0x5b20 + target_id * 0x120] = 0;
      FUN_0046e571(spell_id,target_id,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


