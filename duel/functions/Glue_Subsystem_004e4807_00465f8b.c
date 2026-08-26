/*
 * Decompiled function: Glue_Subsystem_004e4807
 * Entry Point: 00465f8b
 * Size: 1959 bytes
 */
#include "duel.h"


undefined4 Glue_Subsystem_004e4807(int spell_id,int target_id,int flags)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  uint arg_11;
  undefined4 arg_11_00;
  uint arg_12;
  undefined4 arg_12_00;
  uint arg_13;
  undefined4 arg_13_00;
  undefined4 arg_14;
  int iVar4;
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
  int local_18;
  int local_10;
  
  if (((flags == 0x3c) && (*(int *)(&DAT_006826e8 + spell_id * 0x5b20 + target_id * 0x120) != -1))
     && ((&DAT_006826d2)[spell_id * 0x5b20 + target_id * 0x120] != -1)) {
    (&DAT_006827df)
    [*(int *)(&DAT_006826e8 + spell_id * 0x5b20 + target_id * 0x120) * 0x120 +
     (char)(&DAT_006826d2)[spell_id * 0x5b20 + target_id * 0x120] * 0x5b20] =
         (&DAT_006827df)
         [*(int *)(&DAT_006826e8 + spell_id * 0x5b20 + target_id * 0x120) * 0x120 +
          (char)(&DAT_006826d2)[spell_id * 0x5b20 + target_id * 0x120] * 0x5b20] | 0x3f;
  }
  if (flags == 0x74) {
    arg_19_00 = 0;
    arg_18_00 = 0;
    arg_17_00 = 0;
    arg_16_00 = 0xffffffff;
    arg_15 = 0xffffffff;
    arg_14 = 0xffffffff;
    arg_13_00 = 0xffffffff;
    arg_12_00 = 0;
    arg_11_00 = 0;
    uVar2 = FUN_004521e2(spell_id,target_id);
    uVar2 = FUN_0041bcf0((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uVar2,arg_11_00,arg_12_00,arg_13_00,
                         arg_14,arg_15,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else if (flags == 0x90) {
    FUN_0043071d(0);
    uVar2 = 0;
  }
  else {
    if (((flags == 0x6c) && (target_id == DAT_00690c48)) && (spell_id == DAT_0068ecb0)) {
      FUN_00434660(s_prompts_txt_004f8e40,s_VENOM_004f8e38);
      iVar3 = FUN_00468130(spell_id,spell_id,target_id);
      if (iVar3 == 0) {
        DAT_00681ea4 = 1;
      }
    }
    if (flags == 0x71) {
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      iVar4 = -1;
      iVar3 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = FUN_004521e2(spell_id,target_id);
      iVar3 = Rules_ParseFilter_0041c0ab
                        (*(int *)(&DAT_00682718 + spell_id * 0x5b20 + target_id * 0x120),
                         *(int *)(&DAT_0068271c + spell_id * 0x5b20 + target_id * 0x120),
                         (undefined1 *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,iVar3,iVar4
                         ,arg_16,arg_17,arg_18,arg_19,arg_20);
      if (iVar3 == 0) {
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
    if (flags == 0x1a) {
      iVar3 = 1 - (char)(&DAT_006826d2)[spell_id * 0x5b20 + target_id * 0x120];
      if (((char)(&DAT_006826d2)[spell_id * 0x5b20 + target_id * 0x120] == DAT_00666458) &&
         (((&DAT_006826cc)
           [*(int *)(&DAT_006826e8 + spell_id * 0x5b20 + target_id * 0x120) * 0x120 +
            (char)(&DAT_006826d2)[spell_id * 0x5b20 + target_id * 0x120] * 0x5b20] & 0x44) != 0)) {
        if ((&DAT_006826de)
            [*(int *)(&DAT_006826e8 + spell_id * 0x5b20 + target_id * 0x120) * 0x120 +
             (char)(&DAT_006826d2)[spell_id * 0x5b20 + target_id * 0x120] * 0x5b20] == -1) {
          local_18 = *(int *)(&DAT_006826e8 + spell_id * 0x5b20 + target_id * 0x120);
        }
        else {
          local_18 = (int)(char)(&DAT_006826de)
                                [*(int *)(&DAT_006826e8 + spell_id * 0x5b20 + target_id * 0x120) *
                                 0x120 + (char)(&DAT_006826d2)
                                               [spell_id * 0x5b20 + target_id * 0x120] * 0x5b20];
        }
        for (local_10 = 0; local_10 < (int)(&DAT_00666408)[iVar3]; local_10 = local_10 + 1) {
          if ((((char)(&DAT_006826de)[iVar3 * 0x5b20 + local_10 * 0x120] == local_18) &&
              ((&DAT_004ff595)[*(int *)(&DAT_006826c4 + iVar3 * 0x5b20 + local_10 * 0x120) * 0x34]
               != '\0')) &&
             (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + iVar3 * 0x5b20 + local_10 * 0x120) * 0x34] &
              2) != 0)) {
            FUN_004a2b00(spell_id,target_id,DAT_006764c0,iVar3,local_10);
          }
        }
      }
      if (((char)(&DAT_006826d2)[spell_id * 0x5b20 + target_id * 0x120] != DAT_00666458) &&
         ((&DAT_006826de)
          [*(int *)(&DAT_006826e8 + spell_id * 0x5b20 + target_id * 0x120) * 0x120 +
           (char)(&DAT_006826d2)[spell_id * 0x5b20 + target_id * 0x120] * 0x5b20] != -1)) {
        cVar1 = (&DAT_006826de)
                [iVar3 * 0x5b20 +
                 (char)(&DAT_006826de)
                       [*(int *)(&DAT_006826e8 + spell_id * 0x5b20 + target_id * 0x120) * 0x120 +
                        (char)(&DAT_006826d2)[spell_id * 0x5b20 + target_id * 0x120] * 0x5b20] *
                 0x120];
        if (cVar1 == -1) {
          FUN_004a2b00(spell_id,target_id,DAT_006764c0,iVar3,
                       (int)(char)(&DAT_006826de)
                                  [*(int *)(&DAT_006826e8 + spell_id * 0x5b20 + target_id * 0x120) *
                                   0x120 + (char)(&DAT_006826d2)
                                                 [spell_id * 0x5b20 + target_id * 0x120] * 0x5b20]);
        }
        else {
          for (local_10 = 0; local_10 < (int)(&DAT_00666408)[iVar3]; local_10 = local_10 + 1) {
            iVar4 = FUN_0048a33f(iVar3,local_10);
            if ((iVar4 != 0) && ((&DAT_006826de)[iVar3 * 0x5b20 + local_10 * 0x120] == cVar1)) {
              FUN_004a2b00(spell_id,target_id,DAT_006764c0,iVar3,local_10);
            }
          }
        }
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}


