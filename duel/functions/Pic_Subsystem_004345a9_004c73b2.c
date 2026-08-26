/*
 * Decompiled function: Pic_Subsystem_004345a9
 * Entry Point: 004c73b2
 * Size: 1398 bytes
 */
#include "duel.h"


undefined4 Pic_Subsystem_004345a9(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  uint arg_11;
  undefined4 arg_11_00;
  uint arg_12;
  undefined4 arg_12_00;
  uint arg_13;
  undefined4 arg_13_00;
  undefined4 arg_14;
  int arg_15;
  undefined4 arg_15_00;
  uint arg_16;
  undefined4 arg_16_00;
  uint arg_17;
  undefined4 arg_17_00;
  uint arg_18;
  undefined4 arg_18_00;
  uint arg_19;
  undefined4 arg_19_00;
  uint arg_20;
  int local_8;
  
  if (flags == 0x74) {
    arg_19_00 = 0;
    arg_18_00 = 0;
    arg_17_00 = 0;
    arg_16_00 = 0xffffffff;
    arg_15_00 = 0xffffffff;
    arg_14 = 0xffffffff;
    arg_13_00 = 0xffffffff;
    arg_12_00 = 0;
    arg_11_00 = 0;
    uVar1 = FUN_004521e2(spell_id,target_id);
    uVar1 = FUN_0041bcf0((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uVar1,arg_11_00,arg_12_00,arg_13_00,
                         arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) {
      FUN_00434660(s_prompts_txt_00508b8c,s_SPIRITLINK_00508b80);
      iVar2 = FUN_00468130(spell_id,2,target_id);
      DAT_00681ea4 = (uint)(iVar2 == 0);
      if (DAT_00681ea4 != 1) {
        iVar2 = FUN_0048b81a(*(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20),
                             *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20),0x32,
                             0xffffffff);
        DAT_0068f2d4 = DAT_0068f2d4 + iVar2 * 0x18;
      }
    }
    if (flags == 0x71) {
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      iVar2 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = FUN_004521e2(spell_id,target_id);
      iVar2 = Rules_ParseFilter_0041c0ab
                        (*(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20),
                         (undefined1 *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,iVar2,
                         arg_15,arg_16,arg_17,arg_18,arg_19,arg_20);
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
    if (((flags == 0x6e) &&
        (*(int *)(&DAT_006826c4 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) == DAT_0068f104)) &&
       (((&DAT_006826d3)[DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120] ==
         (&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20] &&
        ((*(int *)(&DAT_006826ec + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) ==
          *(int *)(&DAT_006826e8 + target_id * 0x120 + spell_id * 0x5b20) &&
         (*(int *)(&DAT_006826e4 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) != 0)))))) {
      *(int *)(&DAT_00682718 +
              target_id * 0x120 +
              spell_id * 0x5b20 +
              *(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) * 8) = DAT_0068ecb0;
      *(int *)(&DAT_0068271c +
              target_id * 0x120 +
              spell_id * 0x5b20 +
              *(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) * 8) = DAT_00690c48;
      *(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) =
           *(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) + 1;
    }
    if ((((DAT_0068f230 == 0xd7) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) &&
       ((*(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) != 0 &&
        (spell_id == DAT_00681ec4)))) {
      if (flags == 0x7d) {
        DAT_0066642c = DAT_0066642c | 2;
      }
      if (flags == 0x7e) {
        for (local_8 = 0; local_8 < *(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20);
            local_8 = local_8 + 1) {
          (&DAT_00681ea8)[spell_id] =
               (&DAT_00681ea8)[spell_id] +
               *(int *)(&DAT_006826e4 +
                       *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20 + local_8 * 8)
                       * 0x5b20 +
                       *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20 + local_8 * 8)
                       * 0x120);
        }
        *(undefined4 *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) = 0;
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}


