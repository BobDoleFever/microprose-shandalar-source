/*
 * Decompiled function: Prompts_Load_004a90e1
 * Entry Point: 004a90e1
 * Size: 951 bytes
 */
#include "duel.h"


undefined4 Prompts_Load_004a90e1(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  uint local_18;
  int local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  if (flags == 0x74) {
    uVar1 = 1;
  }
  else {
    if (((flags == 0x6c) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) {
      if (DAT_00676510 == spell_id) {
        FUN_00434660(s_prompts_txt_005062c8,s_HURKYLS_RECALL_005062b8);
        iVar2 = Action_ValidateTarget_0041e2a2
                          (spell_id,2,1 - spell_id,0x1000,0,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,
                           0,0,&DAT_006679f0,1,&local_14);
        if (iVar2 == 0) {
          DAT_00681ea4 = 1;
        }
        else {
          *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) = local_14;
          *(undefined4 *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20) = local_10;
          (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        }
      }
      else {
        if (DAT_0066aaf4 == 1) {
          iVar2 = FUN_00439892(3);
          DAT_0068f2c8 = (uint)(iVar2 == 0);
          if (DAT_0068f2c8 != 0) {
            iVar2 = FUN_00467cce(1 - spell_id,0x40);
            if (iVar2 == 0) {
              DAT_0068f2c8 = 0;
            }
            else {
              iVar2 = FUN_00467cce(spell_id,0x40);
              if (iVar2 == 0) {
                DAT_0068f2c8 = 1;
              }
            }
          }
          FUN_0043064a();
        }
        else {
          FUN_004307b2();
        }
        if (DAT_0068f2c8 == 0) {
          *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) = 1 - spell_id;
        }
        else {
          *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) = spell_id;
        }
        *(undefined4 *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20) = 0xffffffff;
        (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 1;
      }
    }
    if (flags == 0x71) {
      if (*(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) == 0) {
        local_18 = 0;
      }
      else {
        local_18 = 0x1000;
      }
      for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
        for (local_c = 0; local_c < (int)(&DAT_00666408)[local_8]; local_c = local_c + 1) {
          iVar2 = FUN_0048a33f(local_8,local_c);
          if (((iVar2 != 0) &&
              (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + local_c * 0x120 + local_8 * 0x5b20) * 0x34]
               & 0x40) != 0)) &&
             ((*(uint *)(&DAT_006826cc + local_c * 0x120 + local_8 * 0x5b20) & 0x1000) == local_18))
          {
            FUN_004af82a(local_8,local_c);
          }
        }
      }
      (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      FUN_0046e571(spell_id,target_id,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


