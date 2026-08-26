/*
 * Decompiled function: Prompts_Load_004c1ba3
 * Entry Point: 004c1ba3
 * Size: 1370 bytes
 */
#include "duel.h"


undefined4 Prompts_Load_004c1ba3(uint spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 arg_11;
  int iVar6;
  undefined4 arg_12;
  uint uVar7;
  undefined4 arg_13;
  uint uVar8;
  undefined4 arg_14;
  uint uVar9;
  undefined4 arg_15;
  uint uVar10;
  undefined4 arg_16;
  uint uVar11;
  undefined4 arg_17;
  undefined *arg_18;
  undefined4 arg_18_00;
  undefined4 arg_19;
  int *arg_20;
  uint local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (((((int)(char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20] == spell_id) &&
       (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) &&
     (*(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) == 0)) {
    *(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) =
         *(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) + 1;
    FUN_0046e571(spell_id,target_id,3);
  }
  if (flags == 0x74) {
    arg_19 = 0;
    arg_18_00 = 0;
    arg_17 = 0;
    arg_16 = 0xffffffff;
    arg_15 = 0xffffffff;
    arg_14 = 0xffffffff;
    arg_13 = 0xffffffff;
    arg_12 = 0;
    arg_11 = 0;
    uVar1 = FUN_004521e2(spell_id,target_id);
    uVar1 = FUN_0041bcf0((int *)0x0,0,spell_id,1 - spell_id,1 - spell_id,0x200,0x40,0,0,uVar1,arg_11
                         ,arg_12,arg_13,arg_14,arg_15,arg_16,arg_17,arg_18_00,arg_19);
  }
  else {
    if (((flags == 0x6c) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) {
      FUN_00434660(s_prompts_txt_005089ac,s_RELIC_BIND_005089a0);
      arg_20 = &local_10;
      uVar1 = 1;
      arg_18 = &DAT_006679f0;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      iVar5 = -1;
      uVar4 = 0;
      uVar3 = 0;
      uVar2 = FUN_004521e2(spell_id,target_id);
      iVar5 = Action_ValidateTarget_0041e2a2
                        (spell_id,1 - spell_id,1 - spell_id,0x200,0x40,0,0,uVar2,uVar3,uVar4,iVar5,
                         iVar6,uVar7,uVar8,uVar9,uVar10,uVar11,arg_18,uVar1,arg_20);
      if (iVar5 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) = local_10;
        *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20) = local_c;
        (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        if (((&DAT_004ff5a8)[*(int *)(&DAT_006826c4 + local_10 * 0x5b20 + local_c * 0x120) * 0x34] &
            1) != 0) {
          DAT_0068f2d4 = DAT_0068f2d4 +
                         (((char)(&DAT_004ff598)
                                 [*(int *)(&DAT_006826c4 + local_10 * 0x5b20 + local_c * 0x120) *
                                  0x34] * 3 + 6) * 8) / 2;
        }
      }
    }
    if (flags == 0x71) {
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      iVar5 = -1;
      uVar4 = 0;
      uVar3 = 0;
      uVar2 = FUN_004521e2(spell_id,target_id);
      iVar5 = Rules_ParseFilter_0041c0ab
                        (*(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20),
                         (undefined1 *)0x0,spell_id,1 - (char)spell_id,1 - (char)spell_id,0x200,0x40
                         ,0,0,uVar2,uVar3,uVar4,iVar5,iVar6,uVar7,uVar8,uVar9,uVar10,uVar11);
      if (iVar5 == 0) {
        FUN_0046e571(spell_id,target_id,1);
        DAT_00681ea4 = 1;
      }
      else {
        (&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20] =
             (&DAT_00682718)[target_id * 0x120 + spell_id * 0x5b20];
        *(undefined4 *)(&DAT_006826e8 + target_id * 0x120 + spell_id * 0x5b20) =
             *(undefined4 *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20);
      }
      (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if (((flags == 0x81) &&
        (*(int *)(&DAT_006826e8 + target_id * 0x120 + spell_id * 0x5b20) == DAT_00690c48)) &&
       (((int)(char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20] == DAT_0068ecb0 &&
        (DAT_00690c48 != -1)))) {
      local_8 = FUN_0045102d(spell_id,spell_id,target_id,-1,-1,s_Gain_life__Take_Damage__005089b8,
                             (uint)((int)(&DAT_00681ea8)[1 - spell_id] <=
                                   (int)(&DAT_00681ea8)[spell_id]));
      FUN_00434660(s_prompts_txt_005089e0,s_RELIC_BIND_005089d4);
      if ((int)(&DAT_00681ea8)[spell_id] < (int)(&DAT_00681ea8)[1 - spell_id]) {
        local_14 = spell_id;
      }
      else {
        local_14 = 1 - spell_id;
      }
      Action_ValidateTarget_0041e2a2
                (spell_id,2,local_14,0x1000,0,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0xffffffff,0,0,
                 &DAT_00667aea,0,&local_10);
      if (local_8 == 0) {
        (&DAT_00681ea8)[local_10] = (&DAT_00681ea8)[local_10] + 1;
      }
      else {
        Mem_AllocOrFree_004afd1c(local_10,1,spell_id,target_id);
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}


