/*
 * Decompiled function: Minit_Subsystem_0045a825
 * Entry Point: 0040d5a8
 * Size: 478 bytes
 */
#include "duel.h"


bool Minit_Subsystem_0045a825(int spell_id,int target_id,int flags)

{
  bool bVar1;
  int iVar2;
  
  if (((flags == 0x6c) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) {
    FUN_00468097(spell_id,target_id,3);
  }
  if (((flags == 0x32) || (flags == 0x33)) &&
     ((DAT_00690c48 == target_id && (DAT_0068ecb0 == spell_id)))) {
    iVar2 = FUN_004680fc(spell_id,target_id);
    DAT_0066642c = DAT_0066642c + iVar2;
  }
  if (flags == 0x73) {
    iVar2 = FUN_004680fc(spell_id,target_id);
    bVar1 = 0 < iVar2;
  }
  else if (flags == 0x90) {
    FUN_0043071d(1);
    bVar1 = false;
  }
  else {
    if ((flags == 0x6d) && (iVar2 = FUN_004680fc(spell_id,target_id), 0 < iVar2)) {
      FUN_00434660(s_prompts_txt_004f2878,s_TRISKELION_004f286c);
      iVar2 = FUN_00461047(spell_id,target_id);
      if (iVar2 != 0) {
        *(uint *)(&DAT_006826fc + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&DAT_006826fc + target_id * 0x120 + spell_id * 0x5b20) | 0x6000000;
        FUN_00467eef(spell_id,target_id);
      }
    }
    if (flags == 0x72) {
      FUN_004612b0(spell_id,target_id,0x72,1);
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
    }
    bVar1 = false;
  }
  return bVar1;
}


