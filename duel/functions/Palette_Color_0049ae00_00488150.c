/*
 * Decompiled function: Palette_Color_0049ae00
 * Entry Point: 00488150
 * Size: 1096 bytes
 */
#include "duel.h"


void Palette_Color_0049ae00(int spell_id,int target_id,int flags)

{
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if ((0 < (int)(&DAT_0068ee78)[spell_id]) &&
     ((DAT_00676504 != spell_id || (0 < (&DAT_0068ee78)[spell_id] + DAT_006668f8)))) {
    if ((DAT_00676510 == spell_id) && ((DAT_0066aaf4 != 1 && (target_id == 0)))) {
      FUN_00434660(s_prompts_txt_004faf40,s_DISCARD_004faf38);
      Action_ValidateTarget_0041e2a2
                (spell_id,spell_id,spell_id,0x100,0,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,0,
                 &DAT_006679f0,0,&local_18);
      local_1c = local_14;
    }
    else {
      local_8 = 0;
      local_20 = 0;
      do {
        local_1c = FUN_00439892((&DAT_00666408)[spell_id]);
        if (((*(int *)(&DAT_006826c4 + local_1c * 0x120 + spell_id * 0x5b20) != -1) &&
            (((&DAT_006826cc)[local_1c * 0x120 + spell_id * 0x5b20] & 2) == 0)) &&
           (((&DAT_006826cc)[local_1c * 0x120 + spell_id * 0x5b20] & 0x20) == 0)) {
          local_8 = 1;
        }
      } while ((local_8 == 0) && (local_20 = local_20 + 1, local_20 < 999));
      if (local_8 == 0) {
        local_c = 0;
        while ((local_c < (int)(&DAT_00666408)[spell_id] && (local_8 == 0))) {
          if ((*(int *)(&DAT_006826c4 + local_c * 0x120 + spell_id * 0x5b20) != -1) &&
             ((((&DAT_006826cc)[local_c * 0x120 + spell_id * 0x5b20] & 2) == 0 &&
              (((&DAT_006826cc)[local_c * 0x120 + spell_id * 0x5b20] & 0x20) == 0)))) {
            local_8 = 1;
            local_1c = local_c;
          }
          local_c = local_c + 1;
        }
      }
    }
    if (((DAT_00681eb0 & 0x800 << ((byte)spell_id & 0x1f)) == 0) || (flags != 0)) {
      if ((spell_id == 1) && (DAT_0066aaf4 != 1)) {
        if (target_id == 0) {
          Ai_Subsystem_004cc56d(1,1,local_1c,-1,-1,s_to_discard__004faf64,0);
        }
        else {
          Ai_Subsystem_004cc56d(1,1,local_1c,-1,-1,s_at_random_to_discard__004faf4c,0);
        }
      }
      FUN_0048c907(spell_id,local_1c,0x8d,1 - spell_id,0xffffffff);
      FUN_0046f02d(spell_id,local_1c);
      *(undefined4 *)(&DAT_006826c4 + local_1c * 0x120 + spell_id * 0x5b20) = 0xffffffff;
      FUN_00450eb8(spell_id,local_1c,0xb,1);
    }
    else {
      local_10 = Ai_Subsystem_004cc56d
                           (spell_id,spell_id,local_1c,-1,-1,
                            s_Discard_to_Library__Discard_to_G_004faf70,0);
      if (local_10 == 0) {
        FUN_004d7baa(spell_id,*(undefined4 *)(&DAT_006826c4 + local_1c * 0x120 + spell_id * 0x5b20))
        ;
        *(undefined4 *)(&DAT_006826c4 + local_1c * 0x120 + spell_id * 0x5b20) = 0xffffffff;
        FUN_00450eb8(spell_id,local_1c,10,1);
      }
      else {
        FUN_0048c907(spell_id,local_1c,0x8d,1 - spell_id,0xffffffff);
        FUN_0046f02d(spell_id,local_1c);
        *(undefined4 *)(&DAT_006826c4 + local_1c * 0x120 + spell_id * 0x5b20) = 0xffffffff;
        FUN_00450eb8(spell_id,local_1c,0xb,1);
      }
    }
    FUN_0048d00c(0x18);
    (&DAT_0068ee78)[spell_id] = (&DAT_0068ee78)[spell_id] + -1;
  }
  return;
}


