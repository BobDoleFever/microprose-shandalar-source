/*
 * Decompiled function: Prompts_Load_00406ef0
 * Entry Point: 00406ef0
 * Size: 712 bytes
 */
#include "duel.h"


undefined4 Prompts_Load_00406ef0(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  uint local_10;
  int local_8;
  
  if (flags == 0x74) {
    uVar1 = 1;
  }
  else {
    if ((((flags == 0x6c) && (DAT_00690c48 == target_id)) && (spell_id == DAT_0068ecb0)) &&
       ((spell_id == DAT_00676504 && (*(int *)(&DAT_006669f0 + spell_id * 2000) == -1)))) {
      DAT_00681ea4 = 1;
    }
    if (flags == 0x71) {
      if (((spell_id == DAT_00676510) && (DAT_0066aaf4 != 1)) && (DAT_0068f0b0 == 0)) {
        FUN_00434660(s_prompts_txt_004f2374,s_DEMONIC_TUTOR_004f2364);
        local_8 = Pic_Load_advfac64_004d6639
                            (spell_id,(int *)(&DAT_006669f0 + spell_id * 2000),500,&DAT_006679f0,1,
                             &DAT_004f2380);
        if ((local_8 != -1) && (*(int *)(&DAT_006669f0 + local_8 * 4 + spell_id * 2000) != -1)) {
          FUN_004d695b(spell_id,*(int *)(&DAT_006669f0 + local_8 * 4 + spell_id * 2000));
          FUN_004d7acc(spell_id,local_8);
        }
      }
      else {
        if (spell_id == DAT_00676510) {
          local_10 = 0x42;
        }
        else {
          if (DAT_0066aaf4 == 1) {
            DAT_0068f2c8 = FUN_00439892(4);
            FUN_0043064a();
          }
          else {
            FUN_004307b2();
          }
          switch(DAT_0068f2c8) {
          case 0:
            local_10 = 2;
            break;
          case 1:
            local_10 = 0x40;
            break;
          case 2:
            local_10 = 8;
            break;
          case 3:
            local_10 = 0x10;
          }
        }
        local_8 = FUN_00408121(spell_id,spell_id,local_10);
        if (local_8 == -1) {
          local_8 = FUN_00408121(spell_id,spell_id,0xffffffff);
        }
        if ((local_8 != -1) && (*(int *)(&DAT_006669f0 + local_8 * 4 + spell_id * 2000) != -1)) {
          FUN_004d695b(spell_id,*(int *)(&DAT_006669f0 + local_8 * 4 + spell_id * 2000));
          FUN_004d7acc(spell_id,local_8);
        }
      }
      if (local_8 != -1) {
        FUN_00451482(0,0x30);
        FUN_004d7946(spell_id);
      }
      FUN_0046e571(spell_id,target_id,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


