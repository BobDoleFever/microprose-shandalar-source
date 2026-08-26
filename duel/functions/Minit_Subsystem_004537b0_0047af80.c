/*
 * Decompiled function: Minit_Subsystem_004537b0
 * Entry Point: 0047af80
 * Size: 1200 bytes
 */
#include "duel.h"


undefined4 Minit_Subsystem_004537b0(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  uint local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (flags == 0x73) {
    local_14 = (uint)(((byte)DAT_00681eb0 & 4) != 0);
    if (((&DAT_006826cc)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) != 0) {
      local_14 = 0;
    }
    if (((local_14 != 0) && (((&DAT_006826ce)[target_id * 0x120 + spell_id * 0x5b20] & 3) != 0)) &&
       (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2
        ) != 0)) {
      local_14 = 0;
    }
    if (local_14 != 0) {
      local_14 = FUN_0041bcf0((int *)0x0,1,spell_id,2,2,0x200,2,0,0,0,0,0,0xffffffff,0xffffffff,
                              0xffffffff,0xffffffff,0,0,0);
    }
    if (local_14 == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = 99;
    }
  }
  else if (flags == 0x90) {
    FUN_0043071d(0);
    uVar1 = 0;
  }
  else {
    if ((flags == 0x6d) && (((byte)DAT_00681eb0 & 4) != 0)) {
      if (DAT_0068f220 == 0) {
        local_8 = 0;
        while (local_8 == 0) {
          FUN_00434660(s_prompts_txt_004f9a98,s_OASIS_004f9a90);
          iVar2 = Action_ValidateTarget_0041e2a2
                            (spell_id,2,2,0x200,0,0,0,0,0,0,DAT_0068f104,-1,0xffffffff,0xffffffff,0,
                             0,0,&DAT_006679f0,1,&local_10);
          if (iVar2 == 0) {
            DAT_00681ea4 = 1;
            local_8 = 1;
          }
          else if (*(int *)(&DAT_006826e8 + local_10 * 0x5b20 + local_c * 0x120) == -1) {
            if (DAT_0066aaf4 != 1) {
              Mem_AllocOrFree_00450eed(s_Illegal_target__damage_type___004f9aa4);
              Sleep(2000);
              Mem_AllocOrFree_00450eed(&DAT_004f9ac4);
            }
          }
          else {
            local_8 = 1;
            *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) = local_10;
            *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20) = local_c;
            (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 1;
            *(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) =
                 *(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
          }
        }
      }
      else {
        (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 0;
        DAT_00681ea4 = 1;
      }
    }
    if ((flags == 0x72) && ((&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] != '\0')) {
      local_10 = *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20);
      local_c = *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20);
      iVar2 = Rules_ParseFilter_0041c0ab
                        (local_10,local_c,(undefined1 *)0x0,spell_id,2,2,0x200,0,0,0,0,0,0,
                         DAT_0068f104,-1,0xffffffff,0xffffffff,0,0,0);
      if (iVar2 != 0) {
        if (*(int *)(&DAT_006826e4 + local_10 * 0x5b20 + local_c * 0x120) < 1) {
          DAT_00681ea4 = 1;
        }
        else {
          *(int *)(&DAT_006826e4 + local_10 * 0x5b20 + local_c * 0x120) =
               *(int *)(&DAT_006826e4 + local_10 * 0x5b20 + local_c * 0x120) + -1;
        }
      }
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
    }
    if ((flags == 0x3b) && (((&DAT_006826cc)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0)) {
      *(int *)(&DAT_00666738 + spell_id * 4) = *(int *)(&DAT_00666738 + spell_id * 4) + 1;
    }
    uVar1 = 0;
  }
  return uVar1;
}


