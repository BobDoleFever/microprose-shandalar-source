/*
 * Decompiled function: Prompts_Load_00404bd4
 * Entry Point: 00404bd4
 * Size: 3165 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Prompts_Load_00404bd4(int spell_id,int target_id,int flags)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 arg_11;
  uint uVar4;
  undefined4 arg_12;
  uint uVar5;
  undefined4 arg_13;
  undefined4 arg_14;
  undefined4 arg_15;
  uint uVar6;
  undefined4 arg_16;
  uint uVar7;
  undefined4 arg_17;
  undefined *puVar8;
  uint uVar9;
  int iVar10;
  undefined4 arg_18;
  uint uVar11;
  int arg_3;
  undefined4 arg_19;
  int *piVar12;
  uint uVar13;
  int local_30;
  int local_28;
  int local_24;
  int local_20;
  undefined4 local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (flags == 0x74) {
    if (DAT_00676510 == spell_id) {
      DAT_0068ef44 = 1;
    }
    else {
      iVar1 = FUN_0049b309(spell_id,7,2);
      if (iVar1 == 0) {
        return 0;
      }
    }
    uVar2 = 1;
  }
  else {
    if (((flags == 0x6c) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) {
      iVar1 = FUN_00404a71(spell_id,*(int *)(&DAT_006826c4 + target_id * 0x120 + spell_id * 0x5b20))
      ;
      DAT_0068f2d4 = DAT_0068f2d4 - (int)(0x48 / (longlong)iVar1);
      if ((DAT_00676510 == spell_id) && (DAT_0066aaf4 != 1)) {
        if ((DAT_00681eb0._1_1_ & 4) == 0) {
          local_14 = FUN_0049b309(spell_id,7,1);
          local_14 = local_14 + -1;
          arg_19 = 0;
          arg_18 = 0;
          arg_17 = 0;
          arg_16 = 0xffffffff;
          arg_15 = 0xffffffff;
          arg_14 = 0xffffffff;
          arg_13 = 0xffffffff;
          arg_12 = 0;
          arg_11 = 0;
          uVar2 = FUN_004521e2(spell_id,target_id);
          FUN_0041bcf0(&local_18,0,spell_id,2,2,0x200,2,0,0,uVar2,arg_11,arg_12,arg_13,arg_14,arg_15
                       ,arg_16,arg_17,arg_18,arg_19);
          local_18 = local_18 + 2;
          local_10 = local_14;
          local_c = 1;
          iVar1 = FUN_004497f1(spell_id,*(int *)(&DAT_006826c4 +
                                                target_id * 0x120 + spell_id * 0x5b20),local_14,
                               local_18,&local_10,&local_c,&local_1c);
          if (iVar1 == 0) {
            DAT_00681ea4 = 1;
          }
          else {
            *(undefined4 *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) = local_1c;
            DAT_00681ea0 = 0;
            _DAT_0068ecf0 = 1;
            FUN_0042b6b0(spell_id,0,local_10);
            if (DAT_00681ea4 != 1) {
              DAT_00681ea0 = local_10 - (local_c + -1);
              (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 0;
              local_20 = 0;
              while ((local_20 < local_c && (DAT_00681ea4 != 1))) {
                FUN_00434660(s_prompts_txt_004f221c,s_FIREBALL_004f2210);
                _sprintf(&DAT_006679f0,&DAT_006679f0,local_20 + 1,local_c);
                piVar12 = &local_28;
                uVar2 = 1;
                puVar8 = &DAT_006679f0;
                uVar13 = 0;
                uVar11 = 0;
                uVar9 = 0;
                uVar7 = 0xffffffff;
                uVar6 = 0xffffffff;
                iVar10 = -1;
                iVar1 = -1;
                uVar5 = 0;
                uVar4 = 0;
                uVar3 = FUN_004521e2(spell_id,target_id);
                iVar1 = Action_ValidateTarget_0041e2a2
                                  (spell_id,2,1 - spell_id,0x1200,2,0,0,uVar3,uVar4,uVar5,iVar1,
                                   iVar10,uVar6,uVar7,uVar9,uVar11,uVar13,puVar8,uVar2,piVar12);
                if (iVar1 == 0) {
                  DAT_00681ea4 = 1;
                }
                else {
                  *(uint *)(&DAT_006826cc + local_28 * 0x5b20 + local_24 * 0x120) =
                       *(uint *)(&DAT_006826cc + local_28 * 0x5b20 + local_24 * 0x120) | 0x300000;
                  FUN_00451482(0,0x20);
                  *(int *)(&DAT_00682718 +
                          target_id * 0x120 +
                          spell_id * 0x5b20 +
                          (char)(&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] * 8) =
                       local_28;
                  *(int *)(&DAT_0068271c +
                          target_id * 0x120 +
                          spell_id * 0x5b20 +
                          (char)(&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] * 8) =
                       local_24;
                  (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] =
                       (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] + '\x01';
                }
                local_20 = local_20 + 1;
              }
              for (local_20 = 0;
                  local_20 < (char)(&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20];
                  local_20 = local_20 + 1) {
                *(uint *)(&DAT_006826cc +
                         *(int *)(&DAT_0068271c +
                                 target_id * 0x120 + spell_id * 0x5b20 + local_20 * 8) * 0x120 +
                         *(int *)(&DAT_00682718 +
                                 target_id * 0x120 + spell_id * 0x5b20 + local_20 * 8) * 0x5b20) =
                     *(uint *)(&DAT_006826cc +
                              *(int *)(&DAT_0068271c +
                                      target_id * 0x120 + spell_id * 0x5b20 + local_20 * 8) * 0x120
                              + *(int *)(&DAT_00682718 +
                                        target_id * 0x120 + spell_id * 0x5b20 + local_20 * 8) *
                                0x5b20) & 0xffcfffff;
              }
              if (DAT_00681ea4 == 1) {
                (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 0;
              }
            }
          }
        }
        else {
          *(undefined4 *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) =
               *(undefined4 *)(&DAT_006826e4 + DAT_0068eccc * 0x120 + DAT_0068ecd0 * 0x5b20);
          local_c = (int)(char)(&DAT_006827b8)[DAT_0068eccc * 0x120 + DAT_0068ecd0 * 0x5b20];
          (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 0;
          local_20 = 0;
          while ((local_20 < local_c && (DAT_00681ea4 != 1))) {
            FUN_00434660(s_prompts_txt_004f2234,s_FIREBALL_004f2228);
            _sprintf(&DAT_006679f0,&DAT_006679f0,local_20 + 1,local_c);
            piVar12 = &local_28;
            uVar2 = 1;
            puVar8 = &DAT_006679f0;
            uVar13 = 0;
            uVar11 = 0;
            uVar9 = 0;
            uVar7 = 0xffffffff;
            uVar6 = 0xffffffff;
            iVar10 = -1;
            iVar1 = -1;
            uVar5 = 0;
            uVar4 = 0;
            uVar3 = FUN_004521e2(spell_id,target_id);
            iVar1 = Action_ValidateTarget_0041e2a2
                              (spell_id,2,1 - spell_id,0x1200,2,0,0,uVar3,uVar4,uVar5,iVar1,iVar10,
                               uVar6,uVar7,uVar9,uVar11,uVar13,puVar8,uVar2,piVar12);
            if (iVar1 == 0) {
              DAT_00681ea4 = 1;
            }
            else {
              *(uint *)(&DAT_006826cc + local_28 * 0x5b20 + local_24 * 0x120) =
                   *(uint *)(&DAT_006826cc + local_28 * 0x5b20 + local_24 * 0x120) | 0x300000;
              FUN_00451482(0,0x20);
              *(int *)(&DAT_00682718 +
                      target_id * 0x120 +
                      spell_id * 0x5b20 +
                      (char)(&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] * 8) = local_28;
              *(int *)(&DAT_0068271c +
                      target_id * 0x120 +
                      spell_id * 0x5b20 +
                      (char)(&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] * 8) = local_24;
              (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] =
                   (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] + '\x01';
            }
            local_20 = local_20 + 1;
          }
          for (local_20 = 0; local_20 < (char)(&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20]
              ; local_20 = local_20 + 1) {
            *(uint *)(&DAT_006826cc +
                     *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20 + local_20 * 8)
                     * 0x120 + *(int *)(&DAT_00682718 +
                                       target_id * 0x120 + spell_id * 0x5b20 + local_20 * 8) *
                               0x5b20) =
                 *(uint *)(&DAT_006826cc +
                          *(int *)(&DAT_0068271c +
                                  target_id * 0x120 + spell_id * 0x5b20 + local_20 * 8) * 0x120 +
                          *(int *)(&DAT_00682718 +
                                  target_id * 0x120 + spell_id * 0x5b20 + local_20 * 8) * 0x5b20) &
                 0xffcfffff;
          }
          if (DAT_00681ea4 == 1) {
            (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 0;
          }
        }
      }
      else {
        *(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) = DAT_00681ea0;
        if (DAT_0066aaf4 == 1) {
          if ((DAT_00681eb0._1_1_ & 4) == 0) {
            arg_3 = 5;
            iVar10 = 1;
            iVar1 = FUN_00439892((DAT_00681ea0 + 1) / 2);
            DAT_0068f2c8 = FUN_0049aa14(iVar1 + 1,iVar10,arg_3);
          }
          else {
            DAT_0068f2c8 = (int)(char)(&DAT_006827b8)[DAT_0068eccc * 0x120 + DAT_0068ecd0 * 0x5b20];
          }
          FUN_0043064a();
        }
        else {
          FUN_004307b2();
        }
        local_30 = DAT_0068f2c8;
        if (DAT_0068f2c8 == 99) {
          local_30 = 1;
        }
        iVar1 = DAT_00681ea0 - local_30;
        for (local_20 = 0; local_20 < local_30; local_20 = local_20 + 1) {
          FUN_00461047(spell_id,target_id);
          *(undefined4 *)
           (&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20 + ((local_30 + -1) - local_20) * 8
           ) = *(undefined4 *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20);
          *(undefined4 *)
           (&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20 + ((local_30 + -1) - local_20) * 8
           ) = *(undefined4 *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20);
          (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = (undefined1)local_30;
        }
        *(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) = (iVar1 + 1) / local_30;
      }
    }
    if (flags == 0x71) {
      if (DAT_00676510 == spell_id) {
        local_8 = 0;
        for (local_20 = 0; local_20 < (char)(&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20];
            local_20 = local_20 + 1) {
          uVar13 = 0;
          uVar11 = 0;
          uVar9 = 0;
          uVar7 = 0xffffffff;
          uVar6 = 0xffffffff;
          iVar10 = -1;
          iVar1 = -1;
          uVar5 = 0;
          uVar4 = 0;
          uVar3 = FUN_004521e2(spell_id,target_id);
          iVar1 = Rules_ParseFilter_0041c0ab
                            (*(int *)(&DAT_00682718 +
                                     target_id * 0x120 + spell_id * 0x5b20 + local_20 * 8),
                             *(int *)(&DAT_0068271c +
                                     target_id * 0x120 + spell_id * 0x5b20 + local_20 * 8),
                             (undefined1 *)0x0,spell_id,2,2,0x1200,2,0,0,uVar3,uVar4,uVar5,iVar1,
                             iVar10,uVar6,uVar7,uVar9,uVar11,uVar13);
          if (iVar1 == 0) {
            local_8 = local_8 + 1;
          }
          else {
            FUN_004af950(*(int *)(&DAT_00682718 +
                                 target_id * 0x120 + spell_id * 0x5b20 + local_20 * 8),
                         *(int *)(&DAT_0068271c +
                                 target_id * 0x120 + spell_id * 0x5b20 + local_20 * 8),
                         *(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20),spell_id,
                         target_id);
          }
        }
      }
      else {
        uVar2 = *(undefined4 *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20);
        for (local_20 = 0; local_20 < (char)(&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20];
            local_20 = local_20 + 1) {
          *(undefined4 *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) =
               *(undefined4 *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20 + local_20 * 8)
          ;
          *(undefined4 *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20) =
               *(undefined4 *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20 + local_20 * 8)
          ;
          FUN_004612b0(spell_id,target_id,0x71,uVar2);
        }
      }
      if ((char)(&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] == local_8) {
        DAT_00681ea4 = 1;
      }
      (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      FUN_0046e571(spell_id,target_id,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}


