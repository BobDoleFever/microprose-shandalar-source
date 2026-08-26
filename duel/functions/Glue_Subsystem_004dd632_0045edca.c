/*
 * Decompiled function: Glue_Subsystem_004dd632
 * Entry Point: 0045edca
 * Size: 861 bytes
 */
#include "duel.h"


undefined1 Glue_Subsystem_004dd632(int spell_id,int target_id,int flags)

{
  undefined1 uVar1;
  int iVar2;
  int local_c;
  int local_8;
  
  if (flags == 0x73) {
    uVar1 = 0;
    if ((*(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) & 0x20010) == 0 &&
        ((byte)DAT_00681eb0 & 4) != 0) {
      iVar2 = FUN_0041bcf0((int *)0x0,0,spell_id,2,2,0x200,0,0,0,0,0,0,DAT_0068f104,0xffffffff,
                           0xffffffff,0xffffffff,0,0,0);
      if (iVar2 == 0) {
        uVar1 = 0;
      }
      else {
        uVar1 = 99;
      }
    }
  }
  else if (flags == 0x90) {
    FUN_0043071d(0);
    uVar1 = 0;
  }
  else {
    if (flags == 0x6d) {
      FUN_00434660(s_prompts_txt_004f8b18,s_SAMITE_HEALER_004f8b08);
      iVar2 = Action_ValidateTarget_0041e2a2
                        (spell_id,2,2,0x200,0,0,0,0,0,0,DAT_0068f104,-1,0xffffffff,0xffffffff,0,0,0,
                         &DAT_006679f0,1,&local_c);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) = local_c;
        *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20) = local_8;
        (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        *(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      }
    }
    if (flags == 0x72) {
      local_c = *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20);
      local_8 = *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20);
      iVar2 = Rules_ParseFilter_0041c0ab
                        (local_c,local_8,(undefined1 *)0x0,spell_id,2,2,0x200,0,0,0,0,0,0,
                         DAT_0068f104,-1,0xffffffff,0xffffffff,0,0,0);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
      }
      else if (*(int *)(&DAT_006826e4 + local_c * 0x5b20 + local_8 * 0x120) != 0) {
        *(int *)(&DAT_006826e4 + local_c * 0x5b20 + local_8 * 0x120) =
             *(int *)(&DAT_006826e4 + local_c * 0x5b20 + local_8 * 0x120) + -1;
      }
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
    }
    if ((flags == 0x3b) &&
       ((*(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) & 0x20010) == 0)) {
      *(int *)(&DAT_00666738 + spell_id * 4) = *(int *)(&DAT_00666738 + spell_id * 4) + 1;
    }
    uVar1 = 0;
  }
  return uVar1;
}


