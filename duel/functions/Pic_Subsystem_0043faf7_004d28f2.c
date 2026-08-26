/*
 * Decompiled function: Pic_Subsystem_0043faf7
 * Entry Point: 004d28f2
 * Size: 639 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint Pic_Subsystem_0043faf7(int spell_id,int target_id,int flags)

{
  uint uVar1;
  int iVar2;
  
  if (flags == 0x74) {
    if (DAT_00676510 == spell_id) {
      uVar1 = (DAT_0066aad4 | _DAT_0066aad0) & 2;
    }
    else {
      uVar1 = *(uint *)(&DAT_0066aad0 + DAT_00676510 * 4) & 2;
    }
  }
  else {
    if (((flags == 0x6c) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) {
      FUN_00434660(s_prompts_txt_00508fac,s_EARTH_BIND_00508fa0);
    }
    iVar2 = FUN_00468130(spell_id,1 - spell_id,target_id);
    DAT_00681ea4 = (uint)(iVar2 == 0);
    if ((flags == 0x71) && (*(int *)(&DAT_006826e8 + target_id * 0x120 + spell_id * 0x5b20) != -1))
    {
      *(undefined4 *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) = 1;
      uVar1 = FUN_0048b81a((int)(char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20],
                           *(int *)(&DAT_006826e8 + target_id * 0x120 + spell_id * 0x5b20),0x34,
                           0xffffffff);
      if ((uVar1 & 0x20) != 0) {
        FUN_004af950((int)(char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20],
                     *(int *)(&DAT_006826e8 + target_id * 0x120 + spell_id * 0x5b20),2,spell_id,
                     target_id);
      }
      *(undefined4 *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) = 0;
    }
    if (((*(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) == 0) &&
        (*(int *)(&DAT_006826e8 + target_id * 0x120 + spell_id * 0x5b20) == DAT_00690c48)) &&
       (((char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20] == DAT_0068ecb0 &&
        ((DAT_00690c48 != -1 && (flags == 0x34)))))) {
      DAT_0066642c = DAT_0066642c & 0xffffffdf;
    }
    uVar1 = 0;
  }
  return uVar1;
}


