/*
 * Decompiled function: Prompts_Load_0040a03a
 * Entry Point: 0040a03a
 * Size: 1180 bytes
 */
#include "duel.h"


undefined4 Prompts_Load_0040a03a(int spell_id,int target_id,int flags)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int local_c;
  int local_8;
  
  if ((flags == 0x82) && (*(int *)(&DAT_006826e4 + spell_id * 0x5b20 + target_id * 0x120) != 0)) {
    *(uint *)(&DAT_006827c8 + spell_id * 0x5b20 + target_id * 0x120) =
         *(uint *)(&DAT_006827c8 + spell_id * 0x5b20 + target_id * 0x120) & 0xfffffffc;
  }
  if (((flags == 0x6c) && (target_id == DAT_00690c48)) && (spell_id == DAT_0068ecb0)) {
    DAT_0068f2d4 = DAT_0068f2d4 + 0x18;
    *(uint *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) =
         *(uint *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) | 0x10;
    *(undefined4 *)(&DAT_006826e4 + spell_id * 0x5b20 + target_id * 0x120) = 1;
  }
  if (((flags == 0x6a) && (spell_id == DAT_00666458)) &&
     ((((&DAT_006826cc)[spell_id * 0x5b20 + target_id * 0x120] & 0x10) != 0 &&
      (iVar2 = FUN_004680fc(spell_id,target_id), iVar2 == 0)))) {
    FUN_004348b2(s_prompts_txt_004f26e4,s_TIME_VAULT_004f26d8);
    iVar2 = FUN_00439892(5);
    iVar2 = FUN_0045102d(spell_id,spell_id,target_id,-1,-1,&DAT_006679f0,(uint)(iVar2 < 1));
    if (iVar2 != 0) {
      DAT_00681eb0 = DAT_00681eb0 | 0x8000;
      *(uint *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) =
           *(uint *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) & 0xffffffef;
      FUN_00467e37(spell_id,target_id);
      *(undefined4 *)(&DAT_006826e4 + spell_id * 0x5b20 + target_id * 0x120) = 0;
    }
  }
  if (flags == 0x73) {
    if ((((((&DAT_006826ce)[spell_id * 0x5b20 + target_id * 0x120] & 3) == 0) ||
         (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + spell_id * 0x5b20 + target_id * 0x120) * 0x34] &
          2) == 0)) && (((&DAT_006826cc)[spell_id * 0x5b20 + target_id * 0x120] & 0x10) == 0)) &&
       (iVar2 = FUN_004680fc(spell_id,target_id), iVar2 != 0)) {
      uVar3 = 1;
    }
    else {
      uVar3 = 0;
    }
  }
  else {
    if (((flags == 0x6d) && (((&DAT_006826cc)[spell_id * 0x5b20 + target_id * 0x120] & 0x10) == 0))
       && (iVar2 = FUN_004680fc(spell_id,target_id), iVar2 != 0)) {
      *(uint *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) =
           *(uint *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) | 0x10;
    }
    if (flags == 0x72) {
      iVar2 = _rand();
      if (iVar2 % 5 < 1) {
        DAT_0068f2d4 = DAT_0068f2d4 + 0x30;
      }
      if (DAT_0068f0f8 == -1) {
        bVar1 = false;
        local_c = 0;
        while ((local_c < 2 && (!bVar1))) {
          for (local_8 = 0; local_8 < (int)(&DAT_00666408)[local_c]; local_8 = local_8 + 1) {
            if ((*(int *)(&DAT_006826c4 + local_8 * 0x120 + local_c * 0x5b20) == DAT_00681ec8) &&
               (((&DAT_006826f9)[local_8 * 0x120 + local_c * 0x5b20] & 1) != 0)) {
              bVar1 = true;
            }
          }
          local_c = local_c + 1;
        }
        if (!bVar1) {
          DAT_0068f0f8 = spell_id;
        }
      }
      FUN_00467eef(DAT_00690af0,DAT_0068efa0);
      *(undefined4 *)
       (&DAT_006826e4 +
       *(int *)(&DAT_006827b0 + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20 +
       *(int *)(&DAT_006827b4 + spell_id * 0x5b20 + target_id * 0x120) * 0x120) = 1;
      iVar2 = FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_00681ec8,-1,-1);
      *(uint *)(&DAT_006826f8 + iVar2 * 0x120 + spell_id * 0x5b20) =
           *(uint *)(&DAT_006826f8 + iVar2 * 0x120 + spell_id * 0x5b20) | 0x120;
    }
    uVar3 = 0;
  }
  return uVar3;
}


