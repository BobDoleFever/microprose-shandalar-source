/*
 * Decompiled function: Prompts_Load_004cc99a
 * Entry Point: 004cc99a
 * Size: 500 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint Prompts_Load_004cc99a(int spell_id,int target_id,int flags)

{
  uint uVar1;
  int iVar2;
  
  if (flags == 0x74) {
    if (spell_id == DAT_00676510) {
      uVar1 = (DAT_0066aad4 | _DAT_0066aad0) & 2;
    }
    else {
      uVar1 = *(uint *)(&DAT_0066aad0 + DAT_00676510 * 4) & 2;
    }
  }
  else {
    if (((flags == 0x6c) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) {
      FUN_00434660(s_prompts_txt_00508cec,s_COCOON_00508ce4);
      iVar2 = FUN_00468130(spell_id,1 - spell_id,target_id);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        DAT_00681ea4 = 0;
      }
    }
    if (((*(int *)(&DAT_006826e8 + target_id * 0x120 + spell_id * 0x5b20) == DAT_00690c48) &&
        ((char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20] == DAT_0068ecb0)) &&
       ((DAT_00690c48 != -1 &&
        (((&DAT_006826cc)[target_id * 0x120 + spell_id * 0x5b20] & 0x20) == 0)))) {
      if (flags == 4) {
        *(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) =
             *(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) + 1;
      }
      if (*(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) < 4) {
        *(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      }
      else {
        if (flags == 0x33) {
          DAT_0066642c = DAT_0066642c + 1;
        }
        if (flags == 0x32) {
          DAT_0066642c = DAT_0066642c + 1;
        }
        if (flags == 0x34) {
          DAT_0066642c = DAT_0066642c | 0x20;
        }
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}


