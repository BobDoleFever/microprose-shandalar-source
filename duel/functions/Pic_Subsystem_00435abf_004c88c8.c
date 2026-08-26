/*
 * Decompiled function: Pic_Subsystem_00435abf
 * Entry Point: 004c88c8
 * Size: 2625 bytes
 */
#include "duel.h"


undefined4 Pic_Subsystem_00435abf(int spell_id,int target_id,int flags)

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
  
  if (flags == 1) {
    *(int *)(&DAT_0068f334 + spell_id * 0x20) = *(int *)(&DAT_0068f334 + spell_id * 0x20) + 1;
  }
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
    if (((flags == 0x6c) && (target_id == DAT_00690c48)) && (spell_id == DAT_0068ecb0)) {
      DAT_0068f2d4 = DAT_0068f2d4 + 0x18;
      *(undefined4 *)(&DAT_006826f0 + spell_id * 0x5b20 + target_id * 0x120) = 0;
      *(undefined4 *)(&DAT_006826e4 + spell_id * 0x5b20 + target_id * 0x120) =
           *(undefined4 *)(&DAT_006826f0 + spell_id * 0x5b20 + target_id * 0x120);
      FUN_00434660(s_prompts_txt_00508bf0,s_HOLY_ARMOR_00508be4);
      iVar2 = FUN_00468130(spell_id,spell_id,target_id);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        DAT_00681ea4 = 0;
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
                        (*(int *)(&DAT_00682718 + spell_id * 0x5b20 + target_id * 0x120),
                         *(int *)(&DAT_0068271c + spell_id * 0x5b20 + target_id * 0x120),
                         (undefined1 *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,iVar2,
                         arg_15,arg_16,arg_17,arg_18,arg_19,arg_20);
      if (iVar2 == 0) {
        FUN_0046e571(spell_id,target_id,1);
        DAT_00681ea4 = 1;
      }
      else {
        (&DAT_006826d2)[spell_id * 0x5b20 + target_id * 0x120] =
             (&DAT_00682718)[spell_id * 0x5b20 + target_id * 0x120];
        *(undefined4 *)(&DAT_006826e8 + spell_id * 0x5b20 + target_id * 0x120) =
             *(undefined4 *)(&DAT_0068271c + spell_id * 0x5b20 + target_id * 0x120);
      }
      (&DAT_006827b8)[spell_id * 0x5b20 + target_id * 0x120] = 0;
    }
    if (((flags == 0x33) && (((&DAT_006826cc)[spell_id * 0x5b20 + target_id * 0x120] & 0x20) == 0))
       && ((*(int *)(&DAT_006826e8 + spell_id * 0x5b20 + target_id * 0x120) == DAT_00690c48 &&
           (((char)(&DAT_006826d2)[spell_id * 0x5b20 + target_id * 0x120] == DAT_0068ecb0 &&
            (DAT_00690c48 != -1)))))) {
      DAT_0066642c = DAT_0066642c + 2;
    }
    if (flags == 0x73) {
      uVar1 = FUN_0049b68d(spell_id,target_id,5,1);
    }
    else if (flags == 0x90) {
      if (spell_id == DAT_00666458) {
        iVar2 = FUN_0048c367((&DAT_006826dd)[spell_id * 0x5b20 + target_id * 0x120]);
        if (*(int *)(&DAT_00676150 + iVar2 * 4) == 0) {
          FUN_00430768(0);
        }
        else {
          DAT_00666410 = 1;
        }
      }
      else {
        DAT_00666410 = 1;
      }
      DAT_0068f0bc = (int)(char)(&DAT_006826d2)[spell_id * 0x5b20 + target_id * 0x120] << 8 |
                     *(uint *)(&DAT_006826e8 + spell_id * 0x5b20 + target_id * 0x120);
      uVar1 = 0;
    }
    else {
      if ((flags == 0x6d) && (iVar2 = FUN_0049b68d(spell_id,target_id,5,1), iVar2 != 0)) {
        if (spell_id == DAT_00666458) {
          iVar2 = FUN_0048c367((&DAT_006826dd)[spell_id * 0x5b20 + target_id * 0x120]);
          if (*(int *)(&DAT_00676150 + iVar2 * 4) == 0) {
            Ai_CalcManaRequirement_004ba890(spell_id,5,-1);
          }
          else {
            DAT_00681ea0 = FUN_0042ecaf(spell_id,target_id,5,1);
          }
          if (DAT_00681ea0 < 1) {
            DAT_00681ea4 = 1;
          }
          else {
            *(int *)(&DAT_006826f0 + spell_id * 0x5b20 + target_id * 0x120) = DAT_00681ea0;
          }
        }
        else {
          iVar2 = FUN_0048c367((&DAT_006826dd)[spell_id * 0x5b20 + target_id * 0x120]);
          if (*(int *)(&DAT_00676150 + iVar2 * 4) == 0) {
            Ai_CalcManaRequirement_004ba890(spell_id,5,1);
          }
          else {
            FUN_0042ecaf(spell_id,target_id,5,1);
          }
          *(undefined4 *)(&DAT_006826f0 + spell_id * 0x5b20 + target_id * 0x120) = 1;
        }
        if (DAT_00681ea4 == 1) {
          *(undefined4 *)(&DAT_006826f0 + spell_id * 0x5b20 + target_id * 0x120) = 0;
        }
        else {
          *(int *)(&DAT_00682718 + spell_id * 0x5b20 + target_id * 0x120) =
               (int)(char)(&DAT_006826d2)[spell_id * 0x5b20 + target_id * 0x120];
          *(undefined4 *)(&DAT_0068271c + spell_id * 0x5b20 + target_id * 0x120) =
               *(undefined4 *)(&DAT_006826e8 + spell_id * 0x5b20 + target_id * 0x120);
          (&DAT_006827b8)[spell_id * 0x5b20 + target_id * 0x120] = 1;
          if (*(int *)(&DAT_006826e4 + spell_id * 0x5b20 + target_id * 0x120) == 0) {
            *(uint *)(&DAT_006826e4 + spell_id * 0x5b20 + target_id * 0x120) =
                 *(uint *)(&DAT_006826e4 + spell_id * 0x5b20 + target_id * 0x120) | 0x80000;
          }
        }
      }
      if (flags == 0x72) {
        if (*(int *)(&DAT_006826c4 +
                    *(int *)(&DAT_006826e8 + spell_id * 0x5b20 + target_id * 0x120) * 0x120 +
                    (char)(&DAT_006826d2)[spell_id * 0x5b20 + target_id * 0x120] * 0x5b20) == -1) {
          DAT_00681ea4 = 1;
        }
        else {
          (&DAT_006827b8)
          [*(int *)(&DAT_006827b4 + spell_id * 0x5b20 + target_id * 0x120) * 0x120 +
           *(int *)(&DAT_006827b0 + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20] = 0;
          *(uint *)(&DAT_006826e4 +
                   *(int *)(&DAT_006827b4 + spell_id * 0x5b20 + target_id * 0x120) * 0x120 +
                   *(int *)(&DAT_006827b0 + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20) =
               *(int *)(&DAT_006826e4 +
                       *(int *)(&DAT_006827b4 + spell_id * 0x5b20 + target_id * 0x120) * 0x120 +
                       *(int *)(&DAT_006827b0 + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20) +
               (*(uint *)(&DAT_006826f0 + spell_id * 0x5b20 + target_id * 0x120) & 0xff) * 0x100;
          if (((&DAT_006826e6)
               [*(int *)(&DAT_006827b4 + spell_id * 0x5b20 + target_id * 0x120) * 0x120 +
                *(int *)(&DAT_006827b0 + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20] & 8) != 0)
          {
            *(uint *)(&DAT_006826e4 +
                     *(int *)(&DAT_006827b4 + spell_id * 0x5b20 + target_id * 0x120) * 0x120 +
                     *(int *)(&DAT_006827b0 + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20) =
                 *(uint *)(&DAT_006826e4 +
                          *(int *)(&DAT_006827b4 + spell_id * 0x5b20 + target_id * 0x120) * 0x120 +
                          *(int *)(&DAT_006827b0 + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20)
                 & 0xfff7ffff;
            iVar2 = FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_0066aaec,
                                 (int)(char)(&DAT_006826d2)[spell_id * 0x5b20 + target_id * 0x120],
                                 *(int *)(&DAT_006826e8 + spell_id * 0x5b20 + target_id * 0x120));
            if (iVar2 != -1) {
              *(short *)(&DAT_006826da + iVar2 * 0x120 + spell_id * 0x5b20) =
                   (short)*(undefined4 *)(&DAT_006826f0 + spell_id * 0x5b20 + target_id * 0x120);
              *(uint *)(&DAT_006826e4 + iVar2 * 0x120 + spell_id * 0x5b20) =
                   *(uint *)(&DAT_006826e4 + iVar2 * 0x120 + spell_id * 0x5b20) | 0x80000;
            }
          }
        }
      }
      if (flags == 199) {
        if (spell_id == DAT_00676504) {
          DAT_0068f2d4 = DAT_0068f2d4 + *(int *)(&DAT_0068ef64 + spell_id * 0x20) * 0xc;
        }
        else {
          DAT_0068f2d4 = DAT_0068f2d4 + *(int *)(&DAT_0068ef64 + spell_id * 0x20) * -0xc;
        }
      }
      if ((flags == 0x22) || (flags == 199)) {
        *(undefined4 *)(&DAT_006826f0 + spell_id * 0x5b20 + target_id * 0x120) = 0;
        *(undefined4 *)(&DAT_006826e4 + spell_id * 0x5b20 + target_id * 0x120) =
             *(undefined4 *)(&DAT_006826f0 + spell_id * 0x5b20 + target_id * 0x120);
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}


