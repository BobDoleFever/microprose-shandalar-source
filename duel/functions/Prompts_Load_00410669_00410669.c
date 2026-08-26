/*
 * Decompiled function: Prompts_Load_00410669
 * Entry Point: 00410669
 * Size: 1225 bytes
 */
#include "duel.h"


undefined4 Prompts_Load_00410669(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  int local_c;
  int local_8;
  
  if (flags == 0x73) {
    if ((((&DAT_006826cc)[spell_id * 0x5b20 + target_id * 0x120] & 0x10) == 0) ||
       (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + spell_id * 0x5b20 + target_id * 0x120) * 0x34] & 2
        ) != 0)) {
      if (((byte)DAT_00681eb0 & 4) == 0) {
        uVar1 = 0;
      }
      else if ((DAT_0068f2c4 == 0x1a) || (DAT_0068f2c4 == 0x19)) {
        iVar2 = FUN_0049b309(spell_id,7,1);
        if (iVar2 == 0) {
          uVar1 = 0;
        }
        else {
          iVar2 = FUN_0041bcf0((int *)0x0,2,spell_id,1 - spell_id,1 - spell_id,0x200,2,0,0,0,0,0,
                               0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,2,8);
          if (iVar2 == 0) {
            uVar1 = 0;
          }
          else {
            uVar1 = 99;
          }
        }
      }
      else {
        uVar1 = 0;
      }
    }
    else {
      uVar1 = 0;
    }
  }
  else if (flags == 0x90) {
    FUN_0043071d(0);
    uVar1 = 0;
  }
  else {
    if ((((flags == 0x6d) && (iVar2 = FUN_0049b309(spell_id,7,1), iVar2 != 0)) &&
        (((byte)DAT_00681eb0 & 4) != 0)) && ((DAT_0068f2c4 == 0x1a || (DAT_0068f2c4 == 0x19)))) {
      FUN_0042b6b0(spell_id,0,1);
      FUN_00434660(s_prompts_txt_004f2984,s_FORCEFIELD_004f2978);
      iVar2 = Action_ValidateTarget_0041e2a2
                        (spell_id,spell_id,spell_id,0x200,0,0,0,0,0,0,DAT_0068f104,-1,0xffffffff,
                         0xffffffff,0x20,0,0,&DAT_006679f0,1,&local_c);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
      }
      else if ((((&DAT_004ff594)
                 [*(int *)(&DAT_006826c4 +
                          *(int *)(&DAT_006826ec + local_c * 0x5b20 + local_8 * 0x120) * 0x120 +
                          (char)(&DAT_006826d3)[local_c * 0x5b20 + local_8 * 0x120] * 0x5b20) * 0x34
                 ] & 2) != 0) &&
              (((&DAT_006826cd)
                [*(int *)(&DAT_006826ec + local_c * 0x5b20 + local_8 * 0x120) * 0x120 +
                 (char)(&DAT_006826d3)[local_c * 0x5b20 + local_8 * 0x120] * 0x5b20] & 2) == 0)) {
        *(int *)(&DAT_00682718 + spell_id * 0x5b20 + target_id * 0x120) = local_c;
        *(int *)(&DAT_0068271c + spell_id * 0x5b20 + target_id * 0x120) = local_8;
        (&DAT_006827b8)[spell_id * 0x5b20 + target_id * 0x120] = 1;
      }
    }
    if (flags == 0x72) {
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b0 + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20 +
       *(int *)(&DAT_006827b4 + spell_id * 0x5b20 + target_id * 0x120) * 0x120] = 0;
      iVar2 = Rules_ParseFilter_0041c0ab
                        (*(int *)(&DAT_00682718 + spell_id * 0x5b20 + target_id * 0x120),
                         *(int *)(&DAT_0068271c + spell_id * 0x5b20 + target_id * 0x120),
                         (undefined1 *)0x0,spell_id,(byte)spell_id,(byte)spell_id,0x200,0,0,0,0,0,0,
                         DAT_0068f104,-1,0xffffffff,0xffffffff,0,0,0);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
      }
      else if (*(int *)(&DAT_006826e4 +
                       *(int *)(&DAT_00682718 + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20 +
                       *(int *)(&DAT_0068271c + spell_id * 0x5b20 + target_id * 0x120) * 0x120) != 0
              ) {
        *(undefined4 *)
         (&DAT_006826e4 +
         *(int *)(&DAT_00682718 + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20 +
         *(int *)(&DAT_0068271c + spell_id * 0x5b20 + target_id * 0x120) * 0x120) = 1;
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}


