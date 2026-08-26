/*
 * Decompiled function: Pic_Subsystem_0043070c
 * Entry Point: 004c3513
 * Size: 2036 bytes
 */
#include "duel.h"


undefined4 Pic_Subsystem_0043070c(int spell_id,int target_id,int flags)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined4 arg_11;
  uint arg_12;
  undefined4 arg_12_00;
  uint arg_13;
  undefined4 arg_13_00;
  undefined4 arg_14;
  int iVar5;
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
  
  bVar1 = false;
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
    uVar2 = FUN_004521e2(spell_id,target_id);
    uVar2 = FUN_0041bcf0((int *)0x0,0,spell_id,2,2,0x200,1,0,0,uVar2,arg_11,arg_12_00,arg_13_00,
                         arg_14,arg_15,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) {
      FUN_00434660(s_prompts_txt_00508a78,s_EROSION_00508a70);
      iVar3 = FUN_00468550(spell_id,1 - spell_id,target_id);
      DAT_00681ea4 = (uint)(iVar3 == 0);
      if (DAT_00681ea4 != 1) {
        if (*(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) == DAT_00676510) {
          iVar3 = FUN_0048c367((&DAT_004ff596)
                               [*(int *)(&DAT_006826c4 +
                                        *(int *)(&DAT_0068271c +
                                                target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                                        *(int *)(&DAT_00682718 +
                                                target_id * 0x120 + spell_id * 0x5b20) * 0x5b20) *
                                0x34]);
          DAT_0068f2d4 = DAT_0068f2d4 +
                         *(int *)(&DAT_0068ef50 + iVar3 * 4 + DAT_00676510 * 0x20) * -4 + 0x20;
        }
        if (*(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) == DAT_00676504) {
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
      iVar5 = -1;
      iVar3 = -1;
      arg_13 = 0;
      arg_12 = 0;
      uVar4 = FUN_004521e2(spell_id,target_id);
      iVar3 = Rules_ParseFilter_0041c0ab
                        (*(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20),
                         (undefined1 *)0x0,spell_id,2,2,0x200,1,0,0,uVar4,arg_12,arg_13,iVar3,iVar5,
                         arg_16,arg_17,arg_18,arg_19,arg_20);
      if (iVar3 == 0) {
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
    if (flags == 0x73) {
      if ((((DAT_0068f2c4 == 4) && (DAT_00666458 == DAT_00681eb4)) &&
          ((char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20] == DAT_00666458)) &&
         (((&DAT_006826e4)[target_id * 0x120 + spell_id * 0x5b20] & 1) == 0)) {
        *(uint *)(&DAT_006827d4 + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&DAT_006827d4 + target_id * 0x120 + spell_id * 0x5b20) | 0x101;
        DAT_00676500 = DAT_00676500 | 3;
        uVar2 = 1;
      }
      else {
        uVar2 = 0;
      }
    }
    else {
      if (((flags == 4) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) {
        *(uint *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) | 1;
        DAT_006664ec = 1;
        DAT_0066642c = DAT_0066642c | 1;
      }
      if (flags == 0x86) {
        iVar3 = 1;
        uVar4 = FUN_0048c367((&DAT_006826dc)
                             [*(int *)(&DAT_006826e8 + target_id * 0x120 + spell_id * 0x5b20) *
                              0x120 + (char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20] *
                                      0x5b20]);
        iVar3 = FUN_0049b309((int)(char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20],uVar4
                             ,iVar3);
        iVar5 = FUN_0049b309((int)(char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20],7,1);
        if (iVar3 == 1) {
          if ((iVar5 < 4) &&
             (10 < (int)(&DAT_00681ea8)
                        [(char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20]])) {
            local_10 = 2;
          }
          else {
            local_10 = 1;
          }
        }
        else if ((iVar5 < 3) &&
                (0xf < (int)(&DAT_00681ea8)
                            [(char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20]])) {
          local_10 = 2;
        }
        else {
          local_10 = 0;
        }
        while (!bVar1) {
          iVar3 = Ai_Subsystem_004cc56d
                            ((int)(char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20],
                             spell_id,target_id,
                             (int)(char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20],
                             *(int *)(&DAT_006826e8 + target_id * 0x120 + spell_id * 0x5b20),
                             s_Destroy_enchanted_land__Pay_1_ma_00508a84,local_10);
          if (iVar3 == 0) {
            FUN_0046e571((int)(char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20],
                         *(int *)(&DAT_006826e8 + target_id * 0x120 + spell_id * 0x5b20),2);
            bVar1 = true;
          }
          else if (iVar3 == 1) {
            iVar3 = FUN_0049b309((int)(char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20],7
                                 ,1);
            if (iVar3 != 0) {
              *(uint *)(&DAT_006826cc +
                       *(int *)(&DAT_006826e8 + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                       (char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) =
                   *(uint *)(&DAT_006826cc +
                            *(int *)(&DAT_006826e8 + target_id * 0x120 + spell_id * 0x5b20) * 0x120
                            + (char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20)
                   | 0x40000;
              Ai_CalcManaRequirement_004ba890
                        ((int)(char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20],0,1);
              if (DAT_00681ea4 == 1) {
                DAT_00681ea4 = 0;
              }
              else {
                bVar1 = true;
              }
            }
          }
          else if (iVar3 == 2) {
            (&DAT_00681ea8)[(char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20]] =
                 (&DAT_00681ea8)[(char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20]] + -1;
            bVar1 = true;
          }
        }
      }
      if (flags == 0x22) {
        *(uint *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) & 0xfffffffe;
      }
      uVar2 = 0;
    }
  }
  return uVar2;
}


