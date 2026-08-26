/*
 * Decompiled function: Pic_Subsystem_0043fe8e
 * Entry Point: 004d2c89
 * Size: 1014 bytes
 */
#include "duel.h"


undefined4 Pic_Subsystem_0043fe8e(int spell_id,int target_id,int flags,int height)

{
  undefined4 uVar1;
  int iVar2;
  int local_c;
  undefined4 local_8;
  
  if (flags == 0x74) {
    uVar1 = 1;
  }
  else {
    if ((((flags == 0x6c) && (DAT_00690c48 == target_id)) && (spell_id == DAT_0068ecb0)) &&
       (iVar2 = FUN_00404b06(spell_id,*(int *)(&DAT_006826c4 + target_id * 0x120 + spell_id * 0x5b20
                                              ),spell_id), iVar2 == 0)) {
      DAT_0068f2d4 = DAT_0068f2d4 +
                     (*(int *)(&DAT_0068ef50 + height * 4 + DAT_00676510 * 0x20) +
                     *(int *)(&DAT_0068ede0 + height * 4 + DAT_00676510 * 0x20) / 2) * 0x18;
    }
    if (flags == 0x73) {
      if (((((byte)DAT_00681eb0 & 4) == 0) ||
          (iVar2 = FUN_0049b68d(spell_id,target_id,7,1), iVar2 == 0)) ||
         (iVar2 = FUN_0041bcf0((int *)0x0,0,spell_id,2,2,0x200,0,0,0,0,1 << ((byte)height & 0x1f),0,
                               DAT_0068f104,0xffffffff,0xffffffff,0xffffffff,0x20,0,0), iVar2 == 0))
      {
        uVar1 = 0;
      }
      else {
        uVar1 = 99;
      }
    }
    else {
      if (((flags == 0x6d) && (((&DAT_006826cc)[target_id * 0x120 + spell_id * 0x5b20] & 0x20) == 0)
          ) && (FUN_0042ecaf(spell_id,target_id,0,1), DAT_00681ea4 != 1)) {
        FUN_00434660(s_prompts_txt_00508fd0,s_CIRCLE_OF_PROTECTION_00508fb8);
        iVar2 = Action_ValidateTarget_0041e2a2
                          (spell_id,2,2,0x200,0,0,0,0,1 << ((byte)height & 0x1f),0,DAT_0068f104,-1,
                           0xffffffff,0xffffffff,0x20,0,0,&DAT_006679f0,1,&local_c);
        if (iVar2 == 0) {
          DAT_00681ea4 = 1;
        }
        else {
          *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) = local_c;
          *(undefined4 *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20) = local_8;
          (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        }
      }
      if (flags == 0x72) {
        iVar2 = Rules_ParseFilter_0041c0ab
                          (*(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20),
                           *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20),
                           (undefined1 *)0x0,spell_id,2,2,0x200,0,0,0,0,1 << ((byte)height & 0x1f),0
                           ,DAT_0068f104,-1,0xffffffff,0xffffffff,0x20,0,0);
        if (iVar2 == 0) {
          DAT_00681ea4 = 1;
        }
        else if (*(int *)(&DAT_006826e4 +
                         *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                         *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20) * 0x120) !=
                 0) {
          *(undefined4 *)
           (&DAT_006826e4 +
           *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
           *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20) * 0x120) = 0;
        }
        (&DAT_006827b8)
        [*(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
         *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}


