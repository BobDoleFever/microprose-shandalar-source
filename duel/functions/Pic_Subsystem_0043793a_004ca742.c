/*
 * Decompiled function: Pic_Subsystem_0043793a
 * Entry Point: 004ca742
 * Size: 387 bytes
 */
#include "duel.h"


void Pic_Subsystem_0043793a(int spell_id,int target_id,int flags)

{
  int iVar1;
  
  if (flags != 0x74) {
    if (((flags == 0x6c) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) {
      FUN_00434660(s_prompts_txt_00508c40,s_INVISIBILITY_00508c30);
      iVar1 = FUN_00468130(spell_id,spell_id,target_id);
      if (iVar1 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        DAT_00681ea4 = 0;
      }
    }
    if (((flags == 0x78) &&
        (*(int *)(&DAT_006826e8 + target_id * 0x120 + spell_id * 0x5b20) == DAT_0068ecfc)) &&
       (((char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20] == DAT_00690310 &&
        ((((&DAT_006826cc)[target_id * 0x120 + spell_id * 0x5b20] & 0x20) == 0 &&
         ((&DAT_004ff595)
          [*(int *)(&DAT_006826c4 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) * 0x34] != '\0')))
        ))) {
      DAT_0066642c = DAT_0066642c + 1;
    }
  }
  return;
}


