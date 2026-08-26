/*
 * Decompiled function: FUN_00404bd4
 * Entry Point: 00404bd4
 * Size: 3165 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00404bd4(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
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
  
  if (param_3 == 0x74) {
    if (DAT_00676510 == param_1) {
      DAT_0068ef44 = 1;
    }
    else {
      iVar1 = FUN_0049b309(param_1,7,2);
      if (iVar1 == 0) {
        return 0;
      }
    }
    uVar2 = 1;
  }
  else {
    if (((param_3 == 0x6c) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
      iVar1 = FUN_00404a71(param_1,*(undefined4 *)
                                    (&DAT_006826c4 + param_2 * 0x120 + param_1 * 0x5b20));
      DAT_0068f2d4 = DAT_0068f2d4 - (int)(0x48 / (longlong)iVar1);
      if ((DAT_00676510 == param_1) && (DAT_0066aaf4 != 1)) {
        if ((DAT_00681eb0._1_1_ & 4) == 0) {
          local_14 = FUN_0049b309(param_1,7,1);
          local_14 = local_14 + -1;
          uVar2 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0
                              );
          FUN_0041bcf0(&local_18,0,param_1,2,2,0x200,2,0,0,uVar2);
          local_18 = local_18 + 2;
          local_10 = local_14;
          local_c = 1;
          iVar1 = FUN_004497f1(param_1,*(undefined4 *)
                                        (&DAT_006826c4 + param_2 * 0x120 + param_1 * 0x5b20),
                               local_14,local_18,&local_10,&local_c,&local_1c);
          if (iVar1 == 0) {
            DAT_00681ea4 = 1;
          }
          else {
            *(undefined4 *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) = local_1c;
            DAT_00681ea0 = 0;
            _DAT_0068ecf0 = 1;
            FUN_0042b6b0(param_1,0,local_10);
            if (DAT_00681ea4 != 1) {
              DAT_00681ea0 = local_10 - (local_c + -1);
              (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 0;
              local_20 = 0;
              while ((local_20 < local_c && (DAT_00681ea4 != 1))) {
                FUN_00434660(s_prompts_txt_004f221c,s_FIREBALL_004f2210);
                _sprintf(&DAT_006679f0,&DAT_006679f0,local_20 + 1,local_c);
                uVar2 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff
                                     ,0,0,0,&DAT_006679f0,1,&local_28);
                iVar1 = FUN_0041e2a2(param_1,2,1 - param_1,0x1200,2,0,0,uVar2);
                if (iVar1 == 0) {
                  DAT_00681ea4 = 1;
                }
                else {
                  *(uint *)(&DAT_006826cc + local_28 * 0x5b20 + local_24 * 0x120) =
                       *(uint *)(&DAT_006826cc + local_28 * 0x5b20 + local_24 * 0x120) | 0x300000;
                  FUN_00451482(0,0x20);
                  *(int *)(&DAT_00682718 +
                          param_2 * 0x120 +
                          param_1 * 0x5b20 +
                          (char)(&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] * 8) = local_28;
                  *(int *)(&DAT_0068271c +
                          param_2 * 0x120 +
                          param_1 * 0x5b20 +
                          (char)(&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] * 8) = local_24;
                  (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] =
                       (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] + '\x01';
                }
                local_20 = local_20 + 1;
              }
              for (local_20 = 0;
                  local_20 < (char)(&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20];
                  local_20 = local_20 + 1) {
                *(uint *)(&DAT_006826cc +
                         *(int *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20 + local_20 * 8)
                         * 0x120 + *(int *)(&DAT_00682718 +
                                           param_2 * 0x120 + param_1 * 0x5b20 + local_20 * 8) *
                                   0x5b20) =
                     *(uint *)(&DAT_006826cc +
                              *(int *)(&DAT_0068271c +
                                      param_2 * 0x120 + param_1 * 0x5b20 + local_20 * 8) * 0x120 +
                              *(int *)(&DAT_00682718 +
                                      param_2 * 0x120 + param_1 * 0x5b20 + local_20 * 8) * 0x5b20) &
                     0xffcfffff;
              }
              if (DAT_00681ea4 == 1) {
                (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 0;
              }
            }
          }
        }
        else {
          *(undefined4 *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) =
               *(undefined4 *)(&DAT_006826e4 + DAT_0068eccc * 0x120 + DAT_0068ecd0 * 0x5b20);
          local_c = (int)(char)(&DAT_006827b8)[DAT_0068eccc * 0x120 + DAT_0068ecd0 * 0x5b20];
          (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 0;
          local_20 = 0;
          while ((local_20 < local_c && (DAT_00681ea4 != 1))) {
            FUN_00434660(s_prompts_txt_004f2234,s_FIREBALL_004f2228);
            _sprintf(&DAT_006679f0,&DAT_006679f0,local_20 + 1,local_c);
            uVar2 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0
                                 ,0,&DAT_006679f0,1,&local_28);
            iVar1 = FUN_0041e2a2(param_1,2,1 - param_1,0x1200,2,0,0,uVar2);
            if (iVar1 == 0) {
              DAT_00681ea4 = 1;
            }
            else {
              *(uint *)(&DAT_006826cc + local_28 * 0x5b20 + local_24 * 0x120) =
                   *(uint *)(&DAT_006826cc + local_28 * 0x5b20 + local_24 * 0x120) | 0x300000;
              FUN_00451482(0,0x20);
              *(int *)(&DAT_00682718 +
                      param_2 * 0x120 +
                      param_1 * 0x5b20 +
                      (char)(&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] * 8) = local_28;
              *(int *)(&DAT_0068271c +
                      param_2 * 0x120 +
                      param_1 * 0x5b20 +
                      (char)(&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] * 8) = local_24;
              (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] =
                   (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] + '\x01';
            }
            local_20 = local_20 + 1;
          }
          for (local_20 = 0; local_20 < (char)(&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20];
              local_20 = local_20 + 1) {
            *(uint *)(&DAT_006826cc +
                     *(int *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20 + local_20 * 8) *
                     0x120 + *(int *)(&DAT_00682718 +
                                     param_2 * 0x120 + param_1 * 0x5b20 + local_20 * 8) * 0x5b20) =
                 *(uint *)(&DAT_006826cc +
                          *(int *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20 + local_20 * 8
                                  ) * 0x120 +
                          *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20 + local_20 * 8
                                  ) * 0x5b20) & 0xffcfffff;
          }
          if (DAT_00681ea4 == 1) {
            (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 0;
          }
        }
      }
      else {
        *(int *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) = DAT_00681ea0;
        if (DAT_0066aaf4 == 1) {
          if ((DAT_00681eb0._1_1_ & 4) == 0) {
            iVar1 = FUN_00439892((DAT_00681ea0 + 1) / 2,1,5);
            DAT_0068f2c8 = FUN_0049aa14(iVar1 + 1);
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
        iVar1 = ((DAT_00681ea0 - local_30) + 1) / local_30;
        for (local_20 = 0; local_20 < local_30; local_20 = local_20 + 1) {
          FUN_00461047(param_1,param_2,iVar1);
          *(undefined4 *)
           (&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20 + ((local_30 + -1) - local_20) * 8) =
               *(undefined4 *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20);
          *(undefined4 *)
           (&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20 + ((local_30 + -1) - local_20) * 8) =
               *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20);
          (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = (undefined1)local_30;
        }
        *(int *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) = iVar1;
      }
    }
    if (param_3 == 0x71) {
      if (DAT_00676510 == param_1) {
        local_8 = 0;
        for (local_20 = 0; local_20 < (char)(&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20];
            local_20 = local_20 + 1) {
          uVar2 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0
                              );
          iVar1 = FUN_0041c0ab(*(undefined4 *)
                                (&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20 + local_20 * 8),
                               *(undefined4 *)
                                (&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20 + local_20 * 8),
                               0,param_1,2,2,0x1200,2,0,0,uVar2);
          if (iVar1 == 0) {
            local_8 = local_8 + 1;
          }
          else {
            FUN_004af950(*(undefined4 *)
                          (&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20 + local_20 * 8),
                         *(undefined4 *)
                          (&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20 + local_20 * 8),
                         *(undefined4 *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20),param_1
                         ,param_2);
          }
        }
      }
      else {
        uVar2 = *(undefined4 *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20);
        for (local_20 = 0; local_20 < (char)(&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20];
            local_20 = local_20 + 1) {
          *(undefined4 *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) =
               *(undefined4 *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20 + local_20 * 8);
          *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20) =
               *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20 + local_20 * 8);
          FUN_004612b0(param_1,param_2,0x71,uVar2);
        }
      }
      if ((char)(&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] == local_8) {
        DAT_00681ea4 = 1;
      }
      (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 0;
      FUN_0046e571(param_1,param_2,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}


