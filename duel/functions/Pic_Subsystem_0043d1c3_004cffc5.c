/*
 * Decompiled function: Pic_Subsystem_0043d1c3
 * Entry Point: 004cffc5
 * Size: 2124 bytes
 */
#include "duel.h"


undefined4 Pic_Subsystem_0043d1c3(int spell_id,int target_id,int flags)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined4 arg_11;
  int iVar7;
  undefined4 arg_12;
  uint uVar8;
  undefined4 arg_13;
  uint uVar9;
  undefined4 arg_14;
  uint uVar10;
  undefined4 arg_15;
  uint uVar11;
  undefined4 arg_16;
  uint uVar12;
  undefined4 arg_17;
  undefined *arg_18;
  undefined4 arg_18_00;
  undefined4 arg_19;
  int *arg_20;
  int local_10;
  int local_c;
  int local_8;
  
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
    uVar2 = FUN_004521e2(spell_id,target_id);
    uVar2 = FUN_0041bcf0((int *)0x0,0,spell_id,2,2,0x200,0x40,0,0,uVar2,arg_11,arg_12,arg_13,arg_14,
                         arg_15,arg_16,arg_17,arg_18_00,arg_19);
  }
  else {
    if (((flags == 0x6c) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) {
      do {
        FUN_00434660(s_prompts_txt_00508ea0,s_COPY_ARTIFACT_00508e90);
        arg_20 = &local_10;
        uVar2 = 1;
        arg_18 = &DAT_006679f0;
        uVar12 = 0;
        uVar11 = 0;
        uVar10 = 0;
        uVar9 = 0xffffffff;
        uVar8 = 0xffffffff;
        iVar7 = -1;
        iVar6 = -1;
        uVar5 = 0;
        uVar4 = 0;
        uVar3 = FUN_004521e2(spell_id,target_id);
        iVar6 = Action_ValidateTarget_0041e2a2
                          (spell_id,2,2,0x200,0x40,0,0,uVar3,uVar4,uVar5,iVar6,iVar7,uVar8,uVar9,
                           uVar10,uVar11,uVar12,arg_18,uVar2,arg_20);
        if (iVar6 == 0) {
          DAT_00681ea4 = 1;
        }
        else if (((&DAT_004ff594)
                  [*(int *)(&DAT_006826c0 + local_10 * 0x5b20 + local_c * 0x120) * 0x34] & 0x40) ==
                 0) {
          if (DAT_0066aaf4 != 1) {
            Mem_AllocOrFree_00450eed(s_Illegal_target__didn_t_enter_pla_00508eac);
            Sleep(2000);
            Mem_AllocOrFree_00450eed(&DAT_00508ee0);
          }
        }
        else {
          *(int *)(&DAT_00682718 +
                  target_id * 0x120 +
                  spell_id * 0x5b20 +
                  (char)(&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] * 8) = local_10;
          *(int *)(&DAT_0068271c +
                  target_id * 0x120 +
                  spell_id * 0x5b20 +
                  (char)(&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] * 8) = local_c;
          (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        }
      } while ((DAT_00681ea4 != 1) &&
              (((&DAT_004ff594)
                [*(int *)(&DAT_006826c0 + local_10 * 0x5b20 + local_c * 0x120) * 0x34] & 0x40) == 0)
              );
    }
    if (flags == 0x71) {
      uVar12 = 0;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0xffffffff;
      uVar8 = 0xffffffff;
      iVar7 = -1;
      iVar6 = -1;
      uVar5 = 0;
      uVar4 = 0;
      uVar3 = FUN_004521e2(spell_id,target_id);
      iVar6 = Rules_ParseFilter_0041c0ab
                        (*(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20),
                         (undefined1 *)0x0,spell_id,2,2,0x200,0x40,0,0,uVar3,uVar4,uVar5,iVar6,iVar7
                         ,uVar8,uVar9,uVar10,uVar11,uVar12);
      if (iVar6 == 0) {
        FUN_0046e571(spell_id,target_id,1);
        DAT_00681ea4 = 1;
      }
      else {
        bVar1 = false;
        if ((*(int *)(&DAT_004ff590 +
                     *(int *)(&DAT_006826c0 +
                             *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) *
                             0x5b20 + *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20
                                              ) * 0x120) * 0x34) == 0x207) ||
           (*(int *)(&DAT_004ff590 +
                    *(int *)(&DAT_006826c0 +
                            *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20
                            + *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20) *
                              0x120) * 0x34) == 0x20d)) {
          bVar1 = true;
        }
        if (bVar1) {
          local_8 = FUN_004af68f(*(int *)(&DAT_006826c4 +
                                         *(int *)(&DAT_00682718 +
                                                 target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                                         *(int *)(&DAT_0068271c +
                                                 target_id * 0x120 + spell_id * 0x5b20) * 0x120));
        }
        else {
          local_8 = FUN_004af68f(*(int *)(&DAT_006826c0 +
                                         *(int *)(&DAT_00682718 +
                                                 target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                                         *(int *)(&DAT_0068271c +
                                                 target_id * 0x120 + spell_id * 0x5b20) * 0x120));
        }
        if (local_8 != -1) {
          *(int *)(&DAT_006826c8 + target_id * 0x120 + spell_id * 0x5b20) = local_8;
          *(undefined4 *)(&DAT_006826c4 + target_id * 0x120 + spell_id * 0x5b20) =
               *(undefined4 *)(&DAT_006826c8 + target_id * 0x120 + spell_id * 0x5b20);
          *(undefined4 *)(&DAT_006826fc + target_id * 0x120 + spell_id * 0x5b20) = 0x1000000;
          (&DAT_004ff594)[*(int *)(&DAT_006826c4 + target_id * 0x120 + spell_id * 0x5b20) * 0x34] =
               (&DAT_004ff594)
               [*(int *)(&DAT_006826c4 + target_id * 0x120 + spell_id * 0x5b20) * 0x34] | 4;
        }
        (&DAT_006826dd)[target_id * 0x120 + spell_id * 0x5b20] =
             (&DAT_006826dd)
             [*(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
              *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20) * 0x120];
        if (bVar1) {
          if (((&DAT_004ff594)
               [*(int *)(&DAT_006826c4 + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2) != 0) {
            *(int *)(&DAT_0068ee80 + spell_id * 4) = *(int *)(&DAT_0068ee80 + spell_id * 4) + 1;
          }
          if (((&DAT_004ff594)
               [*(int *)(&DAT_006826c4 + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 0x40) != 0
             ) {
            (&DAT_0068ee88)[spell_id] = (&DAT_0068ee88)[spell_id] + 1;
          }
          if (((&DAT_004ff594)
               [*(int *)(&DAT_006826c4 + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 4) != 0) {
            *(int *)(&DAT_0068ee90 + spell_id * 4) = *(int *)(&DAT_0068ee90 + spell_id * 4) + 1;
          }
          *(uint *)(&DAT_0066aad0 + spell_id * 4) =
               *(uint *)(&DAT_0066aad0 + spell_id * 4) |
               (uint)(byte)(&DAT_004ff594)
                           [*(int *)(&DAT_006826c4 + target_id * 0x120 + spell_id * 0x5b20) * 0x34];
          *(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) =
               *(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) |
               (spell_id == 0) - 1 & 0x400000 | 0x30082;
          DAT_00666754 = spell_id;
          DAT_0068edd0 = target_id;
          FUN_0048e8a8(DAT_00666458,0xdb,s_Card_into_play_00508ee4,0);
        }
        else {
          Pic_Subsystem_0042ac1f(spell_id,target_id);
        }
      }
      (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if ((((flags == 0x3c) && ((DAT_00681eb0._2_1_ & 2) == 0)) && (DAT_00690c48 == target_id)) &&
       ((DAT_0068ecb0 == spell_id && (iVar6 = FUN_0048a33f(spell_id,target_id), iVar6 != 0)))) {
      DAT_0066642c = *(undefined4 *)(&DAT_006826c8 + target_id * 0x120 + spell_id * 0x5b20);
    }
    uVar2 = 0;
  }
  return uVar2;
}


