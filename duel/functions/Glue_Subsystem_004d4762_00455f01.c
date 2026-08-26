/*
 * Decompiled function: Glue_Subsystem_004d4762
 * Entry Point: 00455f01
 * Size: 1468 bytes
 */
#include "duel.h"


undefined4 Glue_Subsystem_004d4762(int spell_id,int target_id,int flags)

{
  int iVar1;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (((flags == 0x6c) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) {
    DAT_0068f2d4 = DAT_0068f2d4 + 0x30;
  }
  if ((flags == 0x25) && (0 < (int)(&DAT_00681ea8)[spell_id])) {
    local_8 = 0;
    local_14 = 0;
    while( true ) {
      iVar1 = (&DAT_00666408)[DAT_00676504];
      if ((int)(&DAT_00666408)[DAT_00676504] <= (int)(&DAT_00666408)[DAT_00676510]) {
        iVar1 = (&DAT_00666408)[DAT_00676510];
      }
      if (iVar1 <= local_8) break;
      if ((((*(int *)(&DAT_006826c4 + DAT_00676510 * 0x5b20 + local_8 * 0x120) == DAT_0068f104) &&
           (((&DAT_006826cc)[DAT_00676510 * 0x5b20 + local_8 * 0x120] & 2) != 0)) &&
          ((char)(&DAT_006826d2)[DAT_00676510 * 0x5b20 + local_8 * 0x120] == spell_id)) &&
         (*(int *)(&DAT_006826e8 + DAT_00676510 * 0x5b20 + local_8 * 0x120) == -1)) {
        local_14 = local_14 + *(int *)(&DAT_006826e4 + DAT_00676510 * 0x5b20 + local_8 * 0x120);
      }
      if (((*(int *)(&DAT_006826c4 + local_8 * 0x120 + DAT_00676504 * 0x5b20) == DAT_0068f104) &&
          (((&DAT_006826cc)[local_8 * 0x120 + DAT_00676504 * 0x5b20] & 2) != 0)) &&
         (((char)(&DAT_006826d2)[local_8 * 0x120 + DAT_00676504 * 0x5b20] == spell_id &&
          (*(int *)(&DAT_006826e8 + local_8 * 0x120 + DAT_00676504 * 0x5b20) == -1)))) {
        local_14 = local_14 + *(int *)(&DAT_006826e4 + local_8 * 0x120 + DAT_00676504 * 0x5b20);
      }
      local_8 = local_8 + 1;
    }
    if ((0 < local_14) && ((int)(&DAT_00681ea8)[spell_id] <= local_14)) {
      Ai_Subsystem_004cc56d(spell_id,spell_id,target_id,-1,-1,s_is_doin__his_thing__004f88b0,0);
      local_14 = local_14 + (1 - (&DAT_00681ea8)[spell_id]);
      *(undefined4 *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) = 0;
      while (*(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) < local_14) {
        FUN_00434660(s_prompts_txt_004f88d8,s_ALI_FROM_CAIRO_004f88c8);
        _sprintf(&DAT_005f6810,&DAT_006679f0,
                 *(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) + 1,local_14);
        Action_ValidateTarget_0041e2a2
                  (spell_id,2,spell_id,0x200,0,0,0,0,0,0,DAT_0068f104,-1,0xffffffff,0xffffffff,0,0,0
                   ,&DAT_005f6810,0,&local_10);
        if (((char)(&DAT_006826d2)[local_10 * 0x5b20 + local_c * 0x120] == spell_id) &&
           (*(int *)(&DAT_006826e8 + local_10 * 0x5b20 + local_c * 0x120) == -1)) {
          *(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) =
               *(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) + 1;
          if (*(int *)(&DAT_006826e4 + local_10 * 0x5b20 + local_c * 0x120) != 0) {
            *(int *)(&DAT_006826e4 + local_10 * 0x5b20 + local_c * 0x120) =
                 *(int *)(&DAT_006826e4 + local_10 * 0x5b20 + local_c * 0x120) + -1;
          }
          if (DAT_0066643c == 1) {
            while ((*(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) < local_14 &&
                   (*(int *)(&DAT_006826e4 + local_10 * 0x5b20 + local_c * 0x120) != 0))) {
              *(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) =
                   *(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) + 1;
              *(int *)(&DAT_006826e4 + local_10 * 0x5b20 + local_c * 0x120) =
                   *(int *)(&DAT_006826e4 + local_10 * 0x5b20 + local_c * 0x120) + -1;
            }
          }
          FUN_00451482(0,0x20);
        }
        else if (DAT_0066aaf4 != 1) {
          Mem_AllocOrFree_00450eed(s_Illegal_target__prevent_damage_t_004f88e4);
          Sleep(2000);
          Mem_AllocOrFree_00450eed(&DAT_004f891c);
        }
      }
    }
  }
  if (((flags == 0x8a) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) {
    DAT_0069340c = DAT_0069340c + 0x18;
  }
  if (((flags == 0x8b) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) {
    DAT_0069340c = DAT_0069340c + -0x18;
  }
  if ((flags == 199) && (((&DAT_006826cc)[target_id * 0x120 + spell_id * 0x5b20] & 2) != 0)) {
    if (spell_id == DAT_00676504) {
      DAT_0068f2d4 = DAT_0068f2d4 + 0x1e0;
    }
    else {
      DAT_0068f2d4 = DAT_0068f2d4 + -0x1e0;
    }
  }
  return 0;
}


