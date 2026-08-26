/*
 * Decompiled function: FUN_0042b6b0
 * Entry Point: 0042b6b0
 * Size: 4254 bytes
 */
#include "duel.h"


/* WARNING: Heritage AFTER dead removal. Example location: r0x0068ecf8 : 0x0042bee4 */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

int FUN_0042b6b0(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  int local_d8;
  int aiStack_d4 [8];
  int local_b4;
  int aiStack_b0 [8];
  int local_90;
  int local_8c;
  int local_88;
  uint local_84;
  uint local_80;
  uint local_7c;
  uint local_78;
  int local_74;
  int local_70;
  uint local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50 [7];
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  uint local_1c;
  uint local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if ((DAT_00681eb0._1_1_ & 4) == 0) {
    (&DAT_0068ece0)[arg_2] = (&DAT_0068ece0)[arg_2] + arg_3;
    local_10 = 0;
    for (local_1c = 0; (int)local_1c < 7; local_1c = local_1c + 1) {
      local_50[local_1c] = 0;
    }
    iVar1 = FUN_0049b309(arg_1,6,1);
    local_24 = FUN_0049b309(arg_1,7,1);
    local_24 = iVar1 - local_24;
    local_8 = 1;
    if ((((DAT_0066643c == 0) && (arg_1 != 1)) && (DAT_0066aaf4 != 1)) && (DAT_0068f0b0 == 0)) {
      local_c = 0;
      local_28 = 0;
      local_2c = 0;
      local_34 = 0;
      local_54 = 0;
    }
    else {
      local_54 = 1;
      local_34 = 1;
      local_2c = 1;
      if (((arg_1 == 1) || (DAT_0066aaf4 == 1)) || (DAT_0068f0b0 != 0)) {
        local_28 = 1;
        local_c = 1;
      }
      else {
        local_c = 0;
        local_28 = 0;
      }
    }
    if (DAT_00676504 == arg_1) {
      for (local_1c = 0; (int)local_1c < 7; local_1c = local_1c + 1) {
        if ((&DAT_0068ece0)[local_1c] == -1) {
          local_64 = FUN_0049b309(arg_1,local_1c,1);
          if (DAT_0066aaf4 == 1) {
            iVar1 = FUN_00439892(3);
            if ((iVar1 == 0) || (local_64 < 2)) {
              local_60 = local_64;
            }
            else {
              local_60 = FUN_00439892(local_64 + -1);
              local_60 = local_60 + 1;
            }
            DAT_0068f2c8 = local_60;
            FUN_0043064a();
          }
          else {
            FUN_004307b2();
            if (DAT_0068f2c8 == 99) {
              DAT_0068f2c8 = 0;
            }
            local_60 = DAT_0068f2c8;
          }
        }
      }
      if (DAT_0068ed04 == -1) {
        DAT_0068ed04 = local_60;
      }
      else if (local_60 <= DAT_0068ed04) {
        DAT_0068ed04 = local_60;
      }
    }
    DAT_00681ea0 = 0;
    if (DAT_0068ed04 == 0) {
      for (local_1c = 0; (int)local_1c < 7; local_1c = local_1c + 1) {
        if ((&DAT_0068ece0)[local_1c] == -1) {
          (&DAT_0068ece0)[local_1c] = 0;
        }
      }
    }
    local_58 = 0;
    for (local_1c = 0; (int)local_1c < 7; local_1c = local_1c + 1) {
      if ((&DAT_0068ece0)[local_1c] == -1) {
        local_58 = 1;
      }
    }
    if ((local_8 != 0) && (iVar1 = FUN_0042cdb6(0x68ece0,DAT_00681ea0,DAT_0068ed04), iVar1 == 0)) {
      FUN_0042c815(arg_1,local_50,&local_10,local_24);
      FUN_00446d17();
    }
    if (((local_54 != 0) && (iVar1 = FUN_0042cdb6(0x68ece0,DAT_00681ea0,DAT_0068ed04), iVar1 == 0))
       && (local_58 != 0)) {
      FUN_0042c9be(arg_1,local_50,&local_10,local_24,&DAT_00681ea0,DAT_0068ed04);
      FUN_00446d17();
    }
    if ((local_34 != 0) && (iVar1 = FUN_0042cdb6(0x68ece0,DAT_00681ea0,DAT_0068ed04), iVar1 == 0)) {
      FUN_0042cbbb(arg_1,local_50,&local_10,local_24,&DAT_00681ea0,DAT_0068ed04);
      FUN_00446d17();
    }
    if ((local_2c != 0) && (iVar1 = FUN_0042cdb6(0x68ece0,DAT_00681ea0,DAT_0068ed04), iVar1 == 0)) {
      iVar1 = FUN_0042cdb6(0x68ece0,DAT_00681ea0,DAT_0068ed04);
      if (iVar1 == 0) {
        FUN_0042d247(arg_1,local_50,&local_10,0x1e,local_c);
      }
      iVar1 = FUN_0042cdb6(0x68ece0,DAT_00681ea0,DAT_0068ed04);
      if (iVar1 == 0) {
        FUN_0042d247(arg_1,local_50,&local_10,0x1c,local_c);
      }
    }
    if ((local_28 != 0) && (iVar1 = FUN_0042cdb6(0x68ece0,DAT_00681ea0,DAT_0068ed04), iVar1 == 0)) {
      iVar1 = FUN_0042cdb6(0x68ece0,DAT_00681ea0,DAT_0068ed04);
      if (iVar1 == 0) {
        FUN_0042d247(arg_1,local_50,&local_10,0x14,local_c);
      }
      iVar1 = FUN_0042cdb6(0x68ece0,DAT_00681ea0,DAT_0068ed04);
      if (iVar1 == 0) {
        FUN_0042d247(arg_1,local_50,&local_10,4,local_c);
      }
      iVar1 = FUN_0042cdb6(0x68ece0,DAT_00681ea0,DAT_0068ed04);
      if (iVar1 == 0) {
        FUN_0042d247(arg_1,local_50,&local_10,0x1a,local_c);
      }
      iVar1 = FUN_0042cdb6(0x68ece0,DAT_00681ea0,DAT_0068ed04);
      if (iVar1 == 0) {
        FUN_0042d247(arg_1,local_50,&local_10,0x18,local_c);
      }
      iVar1 = FUN_0042cdb6(0x68ece0,DAT_00681ea0,DAT_0068ed04);
      if (iVar1 == 0) {
        FUN_0042d247(arg_1,local_50,&local_10,0x10,local_c);
      }
      iVar1 = FUN_0042cdb6(0x68ece0,DAT_00681ea0,DAT_0068ed04);
      if (iVar1 == 0) {
        FUN_0042d247(arg_1,local_50,&local_10,0,local_c);
      }
    }
    if (((arg_1 == 1) || (DAT_0066aaf4 == 1)) || (DAT_0068f0b0 != 0)) {
      iVar1 = FUN_0042cdb6(0x68ece0,DAT_00681ea0,DAT_0068ed04);
      if ((iVar1 == 0) && (local_58 == 0)) {
        DAT_00681ea4 = 1;
      }
    }
    else {
      iVar1 = FUN_0042cdb6(0x68ece0,DAT_00681ea0,DAT_0068ed04);
      if (iVar1 == 0) {
        local_5c = 0;
        while ((local_5c == 0 &&
               (iVar1 = FUN_0042cdb6(0x68ece0,DAT_00681ea0,DAT_0068ed04), iVar1 == 0))) {
          local_68 = 1;
          for (local_1c = 0; (int)local_1c < 7; local_1c = local_1c + 1) {
            if (0 < (&DAT_0068ece0)[local_1c]) {
              local_68 = 0;
            }
          }
          Action_PromptTarget_0042ce51(&DAT_005f6810,&DAT_0068ece0,DAT_00681ea0,DAT_0068ed04);
          local_30 = Action_PromptTarget_004b2bd0
                               (arg_1,arg_1,arg_1,0,0,0x5f6810,
                                (-(uint)(local_68 == 0) & 0xfffffffe) + 3);
          if ((DAT_0068eef0 == -1) && ((local_30 == -1 || (local_30 == -2)))) {
            if (DAT_0068f2cc == -2) {
              if ((DAT_0066aac4 == -1) && (DAT_0066ab04 == -1)) {
                if (local_30 == -1) {
                  DAT_00681ea4 = 1;
                }
                local_5c = 1;
              }
              else if (local_68 != 0) {
                local_5c = 1;
              }
            }
            else if (((DAT_0068f2cc == -3) && (DAT_006663fc == arg_1)) &&
                    (DAT_006764bc != 0xffffffff)) {
              if ((0 < *(int *)(&DAT_0068f2e0 + DAT_006764bc * 4 + arg_1 * 0x20)) &&
                 (((((&DAT_0068ece0)[DAT_006764bc] != 0 || (DAT_0068ece0 != 0)) ||
                   (DAT_0068ecf8 != 0)) && ((DAT_006764bc != 6 || (DAT_0068ecf8 != 0)))))) {
                if ((&DAT_0068ece0)[DAT_006764bc] == 0) {
                  if (DAT_0068ecf8 == 0) {
                    local_6c = 0;
                  }
                  else {
                    local_6c = 6;
                  }
                }
                else {
                  local_6c = DAT_006764bc;
                }
                local_70 = FUN_0042df78(0x68ece0,local_6c,(int)(&DAT_0068f2e0 + arg_1 * 0x20),
                                        DAT_006764bc,DAT_0066643c,DAT_0068ed04,DAT_00681ea0);
                FUN_0042df08(0x68ece0,local_6c,local_70,&DAT_00681ea0,DAT_0068ed04,arg_1,
                             DAT_006764bc,(int)local_50,&local_10);
                FUN_00446d17();
              }
              if (0 < (&DAT_0068ece0)[DAT_006764bc]) {
                local_78 = 0;
                local_20 = 0;
                while ((local_20 < 10 &&
                       (*(int *)(&DAT_00666900 + local_20 * 4 + arg_1 * 0x2c) != -1))) {
                  local_80 = (uint)*(ushort *)(&DAT_00666900 + local_20 * 4 + arg_1 * 0x2c);
                  iVar1 = local_20 * 4;
                  if (local_80 == DAT_006764bc) {
                    local_84._0_1_ = (byte)(*(uint *)(&DAT_00666900 + iVar1 + arg_1 * 0x2c) >> 0x10)
                    ;
                    local_78 = local_78 | 1 << ((byte)local_84 & 0x1f);
                  }
                  local_20 = local_20 + 1;
                  local_84 = *(uint *)(&DAT_00666900 + iVar1 + arg_1 * 0x2c) >> 0x10;
                }
                local_7c = 0;
                for (local_1c = 0; (int)local_1c < 7; local_1c = local_1c + 1) {
                  if ((&DAT_0068ece0)[local_1c] != 0) {
                    local_7c = local_7c | 1 << ((byte)local_1c & 0x1f);
                  }
                }
                local_78 = local_78 & local_7c;
                if (local_78 != 0) {
                  local_74 = 0;
                  for (local_1c = 0; (int)local_1c < 7; local_1c = local_1c + 1) {
                    if ((local_78 & 1 << ((byte)local_1c & 0x1f)) != 0) {
                      local_74 = local_74 + 1;
                    }
                  }
                  if (local_74 == 1) {
                    local_88 = FUN_0048c367((byte)local_78);
                  }
                  else {
                    local_88 = FUN_004513fa(arg_1,s_Which_color_to_use_that_choice_a_004f3b30,1,
                                            DAT_006764bc,local_78);
                  }
                  local_8c = FUN_0042df78(0x68ece0,local_88,(int)(&DAT_0068f2e0 + arg_1 * 0x20),
                                          DAT_006764bc,DAT_0066643c,DAT_0068ed04,DAT_00681ea0);
                  FUN_0042df08(0x68ece0,local_88,local_8c,&DAT_00681ea0,DAT_0068ed04,arg_1,
                               DAT_006764bc,(int)local_50,&local_10);
                  FUN_00446d17();
                }
              }
            }
          }
          else if ((((DAT_0068eef0 == -1) || (local_30 != -1)) &&
                   (local_14 = *(int *)(&DAT_006826c4 + arg_1 * 0x5b20 + local_30 * 0x120),
                   ((&DAT_004ff5a9)[local_14 * 0x34] & 0x10) != 0)) &&
                  ((((&DAT_004ff594)[local_14 * 0x34] & 0x20) != 0 ||
                   (((((&DAT_006826cc)[arg_1 * 0x5b20 + local_30 * 0x120] & 2) != 0 &&
                     (((&DAT_006826cc)[arg_1 * 0x5b20 + local_30 * 0x120] & 0x10) == 0)) &&
                    ((((&DAT_006826ce)[arg_1 * 0x5b20 + local_30 * 0x120] & 3) == 0 ||
                     (((&DAT_004ff594)
                       [*(int *)(&DAT_006826c4 + arg_1 * 0x5b20 + local_30 * 0x120) * 0x34] & 2) ==
                      0)))))))) {
            for (local_d8 = 0; local_d8 < 8; local_d8 = local_d8 + 1) {
              aiStack_d4[local_d8] = *(int *)(&DAT_0068f2e0 + local_d8 * 4 + arg_1 * 0x20);
            }
            local_b4 = DAT_00681ea0;
            DAT_00681ea0 = 0;
            local_90 = DAT_0068ed04;
            DAT_0068ed04 = -1;
            for (local_d8 = 0; local_d8 < 7; local_d8 = local_d8 + 1) {
              aiStack_b0[local_d8] = (&DAT_0068ece0)[local_d8];
              (&DAT_0068ece0)[local_d8] = 0;
            }
            if (((&DAT_006826cc)[arg_1 * 0x5b20 + local_30 * 0x120] & 2) == 0) {
              FUN_00488598(arg_1,local_30);
              FUN_00451482(0,0xff);
            }
            else if ((((&DAT_004ff594)[local_14 * 0x34] & 1) != 0) ||
                    (iVar1 = FUN_0048c907(arg_1,local_30,0x73,1 - arg_1,0xffffffff), iVar1 != 0)) {
              FUN_0048d878(arg_1,local_30,0x72,arg_1,0);
              DAT_0068f220 = 1;
              DAT_0068f0f4 = 0xffffffff;
              local_18 = *(uint *)(&DAT_006826cc + arg_1 * 0x5b20 + local_30 * 0x120) & 0x10;
              FUN_0048c907(arg_1,local_30,0x6d,1 - arg_1,0xffffffff);
              DAT_0068f220 = 0;
              if (DAT_00681ea4 == 1) {
                DAT_00681ea4 = 0;
                FUN_0048e251();
              }
              else {
                if ((local_18 == 0) &&
                   (((&DAT_006826cc)[arg_1 * 0x5b20 + local_30 * 0x120] & 0x10) != 0)) {
                  FUN_0048c50b(arg_1,local_30,0x81);
                }
                if (DAT_0066aaf4 != 1) {
                  FUN_0048d00c(0x12);
                }
                FUN_0048dd43();
                FUN_00451482(0,0xff);
              }
            }
            DAT_00681ea0 = local_b4;
            DAT_0068ed04 = local_90;
            for (local_d8 = 0; local_d8 < 7; local_d8 = local_d8 + 1) {
              (&DAT_0068ece0)[local_d8] = aiStack_b0[local_d8];
            }
            for (local_d8 = 0; local_d8 < 8; local_d8 = local_d8 + 1) {
              *(int *)(&DAT_0068f2e0 + local_d8 * 4 + arg_1 * 0x20) =
                   *(int *)(&DAT_0068f2e0 + local_d8 * 4 + arg_1 * 0x20) - aiStack_d4[local_d8];
            }
            iVar1 = FUN_0049b309(arg_1,6,1);
            local_24 = FUN_0049b309(arg_1,7,1);
            local_24 = iVar1 - local_24;
            FUN_0042c815(arg_1,local_50,&local_10,local_24);
            FUN_0042c9be(arg_1,local_50,&local_10,local_24,&DAT_00681ea0,DAT_0068ed04);
            FUN_0042cbbb(arg_1,local_50,&local_10,local_24,&DAT_00681ea0,DAT_0068ed04);
            for (local_d8 = 0; local_d8 < 8; local_d8 = local_d8 + 1) {
              *(int *)(&DAT_0068f2e0 + local_d8 * 4 + arg_1 * 0x20) =
                   *(int *)(&DAT_0068f2e0 + local_d8 * 4 + arg_1 * 0x20) + aiStack_d4[local_d8];
            }
            FUN_00446d17();
          }
        }
      }
    }
  }
  if (DAT_00681ea4 == 1) {
    FUN_0042e1a0((int)local_50);
    for (local_1c = 0; (int)local_1c < 7; local_1c = local_1c + 1) {
      FUN_0049b235(arg_1,local_1c,local_50[local_1c]);
      local_50[local_1c] = 0;
    }
    local_10 = 0;
    DAT_00681ea0 = 0;
  }
  for (local_1c = 0; (int)local_1c < 7; local_1c = local_1c + 1) {
    (&DAT_0068ece0)[local_1c] = 0;
  }
  DAT_0068ed04 = -1;
  return local_10;
}


