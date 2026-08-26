/*
 * Decompiled function: Pic_Subsystem_0043c287
 * Entry Point: 004cf08b
 * Size: 1644 bytes
 */
#include "duel.h"


undefined4 Pic_Subsystem_0043c287(int spell_id,int target_id,int flags,int height)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 arg_11;
  uint arg_12;
  undefined4 arg_12_00;
  uint arg_13;
  undefined4 arg_13_00;
  undefined4 arg_14;
  undefined4 arg_15;
  uint arg_16;
  undefined4 arg_16_00;
  uint arg_17;
  undefined4 arg_17_00;
  uint arg_18;
  undefined4 arg_18_00;
  uint arg_19;
  undefined4 arg_19_00;
  uint arg_20;
  int local_10;
  int local_8;
  
  if (flags == 0x74) {
    arg_19_00 = 0;
    arg_18_00 = 0;
    arg_17_00 = 0;
    arg_16_00 = 0xffffffff;
    arg_15 = 0xffffffff;
    arg_14 = 0xffffffff;
    arg_13_00 = 0xffffffff;
    arg_12_00 = 0;
    arg_11 = 0;
    uVar1 = FUN_004521e2(spell_id,target_id);
    uVar1 = FUN_0041bcf0((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uVar1,arg_11,arg_12_00,arg_13_00,
                         arg_14,arg_15,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) {
      FUN_00434660(s_prompts_txt_00508e64,s_ANY_WARD_00508e58);
      iVar2 = FUN_00468130(spell_id,spell_id,target_id);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        if ((char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20] == DAT_00676504) {
          iVar2 = *(int *)(&DAT_0068ede0 + height * 4 + DAT_00676510 * 0x20);
          iVar3 = FUN_0048b81a((int)(char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20],
                               *(int *)(&DAT_006826e8 + target_id * 0x120 + spell_id * 0x5b20),0x32,
                               0xffffffff);
          DAT_0068f2d4 = DAT_0068f2d4 + (iVar2 + 1) * iVar3 * 3;
        }
        if ((char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20] == DAT_00676510) {
          DAT_0068f2d4 = DAT_0068f2d4 + -0x60;
        }
      }
    }
    if (flags == 0x71) {
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      iVar3 = -1;
      iVar2 = -1;
      arg_13 = 0;
      arg_12 = 0;
      uVar4 = FUN_004521e2(spell_id,target_id);
      iVar2 = Rules_ParseFilter_0041c0ab
                        (*(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20),
                         (undefined1 *)0x0,spell_id,2,2,0x200,2,0,0,uVar4,arg_12,arg_13,iVar2,iVar3,
                         arg_16,arg_17,arg_18,arg_19,arg_20);
      if (iVar2 == 0) {
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
    uVar4 = DAT_0066642c;
    if (*(int *)(&DAT_006826e8 + target_id * 0x120 + spell_id * 0x5b20) != -1) {
      for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
        for (local_10 = 0; local_10 < (int)(&DAT_00666408)[local_8]; local_10 = local_10 + 1) {
          if (((((((&DAT_006826cc)[local_10 * 0x120 + local_8 * 0x5b20] & 2) != 0) &&
                (*(int *)(&DAT_006826e8 + local_10 * 0x120 + local_8 * 0x5b20) ==
                 *(int *)(&DAT_006826e8 + target_id * 0x120 + spell_id * 0x5b20))) &&
               (((&DAT_006826d2)[local_10 * 0x120 + local_8 * 0x5b20] ==
                 (&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20] &&
                ((int)(char)(&DAT_006826dd)[local_10 * 0x120 + local_8 * 0x5b20] ==
                 1 << ((byte)height & 0x1f))))) &&
              ((local_8 != spell_id || (target_id != local_10)))) &&
             (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + local_10 * 0x120 + local_8 * 0x5b20) * 0x34]
              & 4) != 0)) {
            DAT_0066642c = uVar4;
            FUN_0046e571(local_8,local_10,1);
          }
        }
      }
    }
    DAT_0066642c = uVar4;
    if ((((*(int *)(&DAT_006826e8 + target_id * 0x120 + spell_id * 0x5b20) == DAT_00690c48) &&
         ((char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20] == DAT_0068ecb0)) &&
        (DAT_00690c48 != -1)) &&
       ((((&DAT_006826cc)[target_id * 0x120 + spell_id * 0x5b20] & 0x20) == 0 &&
        (height = FUN_004af7bb(spell_id,target_id,height), flags == 0x34)))) {
      DAT_0066642c = DAT_0066642c | 0x800 << ((char)height - 1U & 0x1f);
    }
    if (((flags == 0x6c) &&
        ((&DAT_006826d2)[DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120] ==
         (&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20])) &&
       ((*(int *)(&DAT_006826e8 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) ==
         *(int *)(&DAT_006826e8 + target_id * 0x120 + spell_id * 0x5b20) &&
        (((1 << ((byte)height & 0x1f) &
          (int)(char)(&DAT_006826dd)[DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120]) != 0 &&
         (((&DAT_006826cc)[target_id * 0x120 + spell_id * 0x5b20] & 0x20) == 0)))))) {
      DAT_0066642c = 1;
    }
    uVar1 = 0;
  }
  return uVar1;
}


