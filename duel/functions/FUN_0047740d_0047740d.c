/*
 * Decompiled function: FUN_0047740d
 * Entry Point: 0047740d
 * Size: 6381 bytes
 */
#include "duel.h"


void FUN_0047740d(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  int local_d4;
  int local_d0;
  int local_cc;
  int local_c8;
  int local_c4;
  int local_c0;
  int local_bc;
  int local_b8;
  int local_b4;
  int local_b0;
  int local_ac [16];
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_54;
  int local_50 [16];
  int local_10;
  int local_c;
  int local_8;
  
  local_6c = 1 - param_1;
  local_bc = 0;
  local_64 = 0;
  do {
    if (1 < local_64) {
      return;
    }
    if (local_64 == 0) {
      DAT_0068f2c4 = 0x19;
    }
    else {
      DAT_0068f2c4 = 0x1a;
    }
    FUN_0048cfda(param_1,DAT_0068f2c4);
    for (local_60 = 0; local_60 < (int)(&DAT_00666408)[param_1]; local_60 = local_60 + 1) {
      if (((&DAT_006826de)[local_60 * 0x120 + param_1 * 0x5b20] == -1) ||
         ((char)(&DAT_006826de)[local_60 * 0x120 + param_1 * 0x5b20] == local_60)) {
        if ((local_bc == 0) && (DAT_0066aaf4 != 1)) {
          FUN_0048d00c(0x14);
          local_bc = 1;
        }
        local_54 = 0;
        local_10 = 0;
        DAT_0052297c = 0;
        local_cc = 0;
        for (local_c8 = 0; local_c8 < (int)(&DAT_00666408)[param_1]; local_c8 = local_c8 + 1) {
          if ((((local_c8 == local_60) ||
               ((char)(&DAT_006826de)[param_1 * 0x5b20 + local_c8 * 0x120] == local_60)) &&
              (*(int *)(&DAT_006826c4 + param_1 * 0x5b20 + local_c8 * 0x120) != -1)) &&
             (((byte)*(undefined4 *)(&DAT_006826cc + param_1 * 0x5b20 + local_c8 * 0x120) & 6) == 6)
             ) {
            (&DAT_005225a0)[DAT_0052297c] = local_c8;
            uVar1 = FUN_0048b81a(param_1,local_c8,0x33,0xffffffff);
            (&DAT_005226f0)[DAT_0052297c] = uVar1;
            uVar1 = FUN_0048b81a(param_1,local_c8,0x34,0xffffffff);
            (&DAT_005224e0)[DAT_0052297c] = uVar1;
            local_b4 = 0;
            (&DAT_00522e70)[DAT_0052297c] = 0;
            iVar2 = FUN_00478cfa(local_64,(&DAT_005224e0)[DAT_0052297c]);
            if (iVar2 != 0) {
              local_b4 = FUN_0048b81a(param_1,local_c8,0x32,0xffffffff);
              if (local_b4 < 0) {
                local_b4 = 0;
              }
              (&DAT_00522e70)[DAT_0052297c] = local_b4;
              local_10 = local_10 + local_b4;
              if ((*(byte *)(&DAT_005224e0 + DAT_0052297c) & 0x80) != 0) {
                local_54 = local_54 + local_b4;
              }
            }
            DAT_0052297c = DAT_0052297c + 1;
            if (DAT_0052297c == 0x10) break;
          }
        }
        if (1 < DAT_0052297c) {
          local_cc = 1;
        }
        local_5c = 0;
        DAT_00522a04 = 0;
        local_b0 = 0;
        for (local_c8 = 0; local_c8 < (int)(&DAT_00666408)[local_6c]; local_c8 = local_c8 + 1) {
          if (((*(int *)(&DAT_006826c4 + local_c8 * 0x120 + local_6c * 0x5b20) != -1) &&
              ((char)(&DAT_006826de)[local_c8 * 0x120 + local_6c * 0x5b20] == local_60)) &&
             (((&DAT_006826cc)[local_c8 * 0x120 + local_6c * 0x5b20] & 2) != 0)) {
            (&DAT_00522f38)[DAT_00522a04] = local_c8;
            iVar2 = FUN_0048b81a(local_6c,local_c8,0x33,local_60);
            (&DAT_00522730)[DAT_00522a04] =
                 iVar2 - *(short *)(&DAT_006826d0 + local_c8 * 0x120 + local_6c * 0x5b20);
            uVar1 = FUN_0048b81a(local_6c,local_c8,0x34,0xffffffff);
            (&DAT_00522520)[DAT_00522a04] = uVar1;
            local_d4 = 0;
            (&DAT_00522ef8)[DAT_00522a04] = 0;
            if ((((&DAT_006826cc)[local_c8 * 0x120 + local_6c * 0x5b20] & 0x10) == 0) &&
               (iVar2 = FUN_00478cfa(local_64,(&DAT_00522520)[DAT_00522a04]), iVar2 != 0)) {
              local_d4 = FUN_0048b81a(local_6c,local_c8,0x32,local_60);
              if (local_d4 < 0) {
                local_d4 = 0;
              }
              (&DAT_00522ef8)[DAT_00522a04] = local_d4;
              local_5c = local_5c + local_d4;
            }
            if ((*(byte *)(&DAT_00522520 + DAT_00522a04) & 0x40) != 0) {
              local_b0 = 1;
            }
            DAT_00522a04 = DAT_00522a04 + 1;
            if (DAT_00522a04 == 0x10) break;
          }
        }
        if (DAT_00522a04 != 0) {
          for (local_b8 = 0; local_b8 < DAT_0052297c; local_b8 = local_b8 + 1) {
            *(uint *)(&DAT_006826cc + param_1 * 0x5b20 + (&DAT_005225a0)[local_b8] * 0x120) =
                 *(uint *)(&DAT_006826cc + param_1 * 0x5b20 + (&DAT_005225a0)[local_b8] * 0x120) |
                 0x200;
          }
        }
        if ((DAT_0052297c != 0) || (DAT_00522a04 != 0)) {
          if (DAT_00522a04 < 2) {
            if (DAT_00522a04 == 1) {
              for (local_b8 = 0; local_b8 < DAT_0052297c; local_b8 = local_b8 + 1) {
                iVar2 = FUN_00478cfa(local_64,(&DAT_005224e0)[local_b8]);
                if ((iVar2 != 0) &&
                   (local_50[0] = FUN_004af950(local_6c,DAT_00522f38,(&DAT_00522e70)[local_b8],
                                               param_1,(&DAT_005225a0)[local_b8]),
                   local_c = local_50[0], local_50[0] != -1)) {
                  *(uint *)(&DAT_006826f8 + local_50[0] * 0x120 + param_1 * 0x5b20) =
                       *(uint *)(&DAT_006826f8 + local_50[0] * 0x120 + param_1 * 0x5b20) | 0x40000;
                  if ((*(byte *)(&DAT_005224e0 + local_b8) & 0x80) != 0) {
                    *(uint *)(&DAT_006826f8 + local_50[0] * 0x120 + param_1 * 0x5b20) =
                         *(uint *)(&DAT_006826f8 + local_50[0] * 0x120 + param_1 * 0x5b20) | 0x80000
                    ;
                  }
                  if (local_64 == 0) {
                    *(uint *)(&DAT_006826f8 + local_50[0] * 0x120 + param_1 * 0x5b20) =
                         *(uint *)(&DAT_006826f8 + local_50[0] * 0x120 + param_1 * 0x5b20) |
                         0x100000;
                  }
                }
              }
            }
            else {
              for (local_b8 = 0; local_b8 < DAT_0052297c; local_b8 = local_b8 + 1) {
                iVar2 = FUN_00478cfa(local_64,(&DAT_005224e0)[local_b8]);
                if ((iVar2 != 0) &&
                   ((((&DAT_006826cd)[param_1 * 0x5b20 + (&DAT_005225a0)[local_b8] * 0x120] & 2) ==
                     0 || ((*(byte *)(&DAT_005224e0 + local_b8) & 0x80) != 0)))) {
                  FUN_004afd1c(local_6c,(&DAT_00522e70)[local_b8],param_1,(&DAT_005225a0)[local_b8])
                  ;
                }
              }
            }
          }
          else if (((DAT_0066aaf4 == 1) || ((local_b0 == 0 && (DAT_00676510 != param_1)))) ||
                  ((local_b0 != 0 && (DAT_00676510 != local_6c)))) {
            local_dc = 0x7fffffff;
            local_d8 = 0xffff8001;
            FUN_00478e3b();
            for (local_68 = 0; local_68 < 0x10; local_68 = local_68 + 1) {
              local_50[local_68] = -1;
            }
            FUN_00478e99(param_1,0,local_b0,local_50,local_64,0,&local_dc,&local_d8);
            FUN_00478e99(param_1,0,local_b0,local_50,local_64,1,&local_dc,&local_d8);
          }
          else {
            for (local_b8 = 0; local_b8 < DAT_0052297c; local_b8 = local_b8 + 1) {
              for (local_68 = 0; local_68 < 0x10; local_68 = local_68 + 1) {
                local_50[local_68] = -1;
              }
              local_b4 = (&DAT_00522e70)[local_b8];
              while (local_b4 != 0) {
                if (DAT_00663e24 == 2) {
                  _sprintf(&DAT_005f6810,s_Assign__d__sdamage_004f993c,local_b4,
                           s_trample_004f992c +
                           (((*(byte *)(&DAT_005224e0 + local_b8) & 0x80) != 0) - 1 & 0xc));
                }
                else {
                  uVar1 = FUN_0044a314(param_1,(&DAT_005225a0)[local_b8],
                                       s_trample_004f98ec +
                                       (((*(byte *)(&DAT_005224e0 + local_b8) & 0x80) != 0) - 1 &
                                       0xc),local_b4);
                  _sprintf(&DAT_005f6810,s__s__Assign__sdamage_to_blockers__004f98fc,uVar1);
                }
                FUN_00479b25(param_1,(&DAT_005225a0)[local_b8],1);
                local_8 = 0;
                while (local_8 == 0) {
                  FUN_0041e2a2(DAT_00676510,local_6c,local_6c,0x200,2,0,0,0,0,0,0xffffffff,
                               0xffffffff,0xffffffff,0xffffffff,0,0x10,0,&DAT_005f6810,0,&local_c4);
                  for (local_68 = 0; local_68 < DAT_00522a04; local_68 = local_68 + 1) {
                    if ((&DAT_00522f38)[local_68] == local_c0) {
                      local_8 = 1;
                    }
                  }
                  if ((local_8 == 0) && (DAT_0066aaf4 != 1)) {
                    FUN_00450eed(s_Illegal_target__wrong_attack_gro_004f9950);
                    Sleep(0x5dc);
                    FUN_00450eed(&DAT_004f9974);
                  }
                  if (((local_8 == 1) && (iVar2 = FUN_00479f9f(local_c4,local_c0), iVar2 != 0)) &&
                     (local_8 = 0, DAT_0066aaf4 != 1)) {
                    FUN_00450eed(s_Illegal_target__gasseous_form__004f9978);
                    Sleep(0x5dc);
                    FUN_00450eed(&DAT_004f9998);
                  }
                }
                DAT_005f6810 = 0;
                FUN_00479b25(param_1,(&DAT_005225a0)[local_b8],0);
                if (((local_c4 != -1) && (local_c0 != -1)) && (local_c0 != -2)) {
                  for (local_68 = 0; local_68 < DAT_00522a04; local_68 = local_68 + 1) {
                    if ((&DAT_00522f38)[local_68] == local_c0) {
                      if (DAT_0066643c == 0) {
                        local_d0 = 1;
                      }
                      else {
                        local_d0 = local_b4;
                      }
                      if (local_50[local_68] == -1) {
                        local_c = FUN_004af950(local_c4,local_c0,local_d0,param_1,
                                               (&DAT_005225a0)[local_b8]);
                        local_50[local_68] = local_c;
                        if (local_c != -1) {
                          *(uint *)(&DAT_006826f8 + local_c * 0x120 + param_1 * 0x5b20) =
                               *(uint *)(&DAT_006826f8 + local_c * 0x120 + param_1 * 0x5b20) |
                               0x40000;
                          if ((*(byte *)(&DAT_005224e0 + local_b8) & 0x80) != 0) {
                            *(uint *)(&DAT_006826f8 + local_c * 0x120 + param_1 * 0x5b20) =
                                 *(uint *)(&DAT_006826f8 + local_c * 0x120 + param_1 * 0x5b20) |
                                 0x80000;
                          }
                          if (local_64 == 0) {
                            *(uint *)(&DAT_006826f8 + local_c * 0x120 + param_1 * 0x5b20) =
                                 *(uint *)(&DAT_006826f8 + local_c * 0x120 + param_1 * 0x5b20) |
                                 0x100000;
                          }
                        }
                      }
                      else {
                        *(int *)(&DAT_006826e4 + param_1 * 0x5b20 + local_50[local_68] * 0x120) =
                             *(int *)(&DAT_006826e4 + param_1 * 0x5b20 + local_50[local_68] * 0x120)
                             + local_d0;
                      }
                      local_b4 = local_b4 - local_d0;
                    }
                  }
                }
              }
            }
          }
          if (DAT_0052297c < 2) {
            if (DAT_0052297c == 1) {
              for (local_b8 = 0; local_b8 < DAT_00522a04; local_b8 = local_b8 + 1) {
                iVar2 = FUN_00478cfa(local_64,(&DAT_00522520)[local_b8]);
                if (((iVar2 != 0) &&
                    (local_ac[0] = FUN_004af950(param_1,DAT_005225a0,(&DAT_00522ef8)[local_b8],
                                                local_6c,(&DAT_00522f38)[local_b8]),
                    local_c = local_ac[0], local_ac[0] != -1)) &&
                   (*(uint *)(&DAT_006826f8 + local_ac[0] * 0x120 + local_6c * 0x5b20) =
                         *(uint *)(&DAT_006826f8 + local_ac[0] * 0x120 + local_6c * 0x5b20) |
                         0x40000, local_64 == 0)) {
                  *(uint *)(&DAT_006826f8 + local_ac[0] * 0x120 + local_6c * 0x5b20) =
                       *(uint *)(&DAT_006826f8 + local_ac[0] * 0x120 + local_6c * 0x5b20) | 0x100000
                  ;
                }
              }
            }
          }
          else if (((DAT_0066aaf4 == 1) || ((local_cc == 0 && (DAT_00676510 != local_6c)))) ||
                  ((local_cc != 0 && (DAT_00676510 != param_1)))) {
            local_e4 = 0x7fffffff;
            local_e0 = 0xffffffff;
            FUN_00478e3b();
            for (local_68 = 0; local_68 < 0x10; local_68 = local_68 + 1) {
              local_ac[local_68] = -1;
            }
            FUN_004794d4(param_1,0,local_cc,local_ac,local_64,0,&local_e4,&local_e0);
            FUN_004794d4(param_1,0,local_cc,local_ac,local_64,1,&local_e4,&local_e0);
          }
          else {
            for (local_b8 = 0; local_b8 < DAT_00522a04; local_b8 = local_b8 + 1) {
              for (local_68 = 0; local_68 < 0x10; local_68 = local_68 + 1) {
                local_ac[local_68] = -1;
              }
              local_d4 = (&DAT_00522ef8)[local_b8];
              while (local_d4 != 0) {
                if (DAT_00663e24 == 2) {
                  _sprintf(&DAT_005f6810,s_Assign__d_damage_004f99cc,local_d4);
                }
                else {
                  uVar1 = FUN_0044a314(local_6c,(&DAT_00522f38)[local_b8],local_d4);
                  _sprintf(&DAT_005f6810,s__s__Assign_damage_to_attackers____004f999c,uVar1);
                }
                FUN_00479b85(local_6c,(&DAT_00522f38)[local_b8],1);
                local_8 = 0;
                while (local_8 == 0) {
                  FUN_0041e2a2(DAT_00676510,param_1,param_1,0x200,2,0,0,0,0,0,0xffffffff,0xffffffff,
                               0xffffffff,0xffffffff,0,2,0,&DAT_005f6810,0,&local_c4);
                  for (local_68 = 0; local_68 < DAT_0052297c; local_68 = local_68 + 1) {
                    if ((&DAT_005225a0)[local_68] == local_c0) {
                      local_8 = 1;
                    }
                  }
                  if ((local_8 == 0) && (DAT_0066aaf4 != 1)) {
                    FUN_00450eed(s_Illegal_target__wrong_attack_gro_004f99e0);
                    Sleep(0x5dc);
                    FUN_00450eed(&DAT_004f9a04);
                  }
                  if (((local_8 == 1) && (iVar2 = FUN_00479f9f(local_c4,local_c0), iVar2 != 0)) &&
                     (local_8 = 0, DAT_0066aaf4 != 1)) {
                    FUN_00450eed(s_Illegal_target__gasseous_form__004f9a08);
                    Sleep(0x5dc);
                    FUN_00450eed(&DAT_004f9a28);
                  }
                }
                DAT_005f6810 = 0;
                FUN_00479b85(local_6c,(&DAT_00522f38)[local_b8],0);
                if (((local_c4 != -1) && (local_c0 != -1)) && (local_c0 != -2)) {
                  for (local_68 = 0; local_68 < DAT_0052297c; local_68 = local_68 + 1) {
                    if ((&DAT_005225a0)[local_68] == local_c0) {
                      if (DAT_0066643c == 0) {
                        local_d0 = 1;
                      }
                      else {
                        local_d0 = local_d4;
                      }
                      if (local_ac[local_68] == -1) {
                        local_c = FUN_004af950(param_1,local_c0,local_d0,local_6c,
                                               (&DAT_00522f38)[local_b8]);
                        local_ac[local_68] = local_c;
                        if ((local_c != -1) &&
                           (*(uint *)(&DAT_006826f8 + local_c * 0x120 + local_6c * 0x5b20) =
                                 *(uint *)(&DAT_006826f8 + local_c * 0x120 + local_6c * 0x5b20) |
                                 0x40000, local_64 == 0)) {
                          *(uint *)(&DAT_006826f8 + local_c * 0x120 + local_6c * 0x5b20) =
                               *(uint *)(&DAT_006826f8 + local_c * 0x120 + local_6c * 0x5b20) |
                               0x100000;
                        }
                      }
                      else {
                        *(int *)(&DAT_006826e4 + local_6c * 0x5b20 + local_ac[local_68] * 0x120) =
                             *(int *)(&DAT_006826e4 + local_6c * 0x5b20 + local_ac[local_68] * 0x120
                                     ) + local_d0;
                      }
                      local_d4 = local_d4 - local_d0;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    DAT_00522a04 = 0;
    for (local_c8 = 0; local_c8 < (int)(&DAT_00666408)[local_6c]; local_c8 = local_c8 + 1) {
      if ((*(int *)(&DAT_006826c4 + local_c8 * 0x120 + local_6c * 0x5b20) != -1) &&
         ((&DAT_006826de)[local_c8 * 0x120 + local_6c * 0x5b20] != -1)) {
        (&DAT_00522f38)[DAT_00522a04] = local_c8;
        iVar2 = FUN_0048b81a(local_6c,local_c8,0x33,local_60);
        (&DAT_00522730)[DAT_00522a04] =
             iVar2 - *(short *)(&DAT_006826d0 + local_c8 * 0x120 + local_6c * 0x5b20);
        iVar2 = FUN_00479f9f(local_6c,local_c8);
        if (iVar2 != 0) {
          (&DAT_00522730)[DAT_00522a04] = 0;
        }
        DAT_00522a04 = DAT_00522a04 + 1;
        if (DAT_00522a04 == 0x10) break;
      }
    }
    DAT_00690314 = 0;
    DAT_00666424 = 0;
    if (DAT_0066aaf4 != 1) {
      DAT_0068eee4 = 0;
    }
    FUN_0046d497(param_1);
    if (DAT_00690314 == 0) {
      FUN_0042abcf(DAT_0068f2c4);
      DAT_00690314 = 1;
    }
    for (local_68 = 0; local_68 < DAT_00522a04; local_68 = local_68 + 1) {
      local_c8 = (&DAT_00522f38)[local_68];
      local_d4 = (&DAT_00522730)[local_68];
      for (local_60 = 0; local_60 < (int)(&DAT_00666408)[param_1]; local_60 = local_60 + 1) {
        if (((((*(int *)(&DAT_006826c0 + local_60 * 0x120 + param_1 * 0x5b20) == DAT_0068f104) &&
              ((char)(&DAT_006826d2)[local_60 * 0x120 + param_1 * 0x5b20] == local_6c)) &&
             (*(int *)(&DAT_006826e8 + local_60 * 0x120 + param_1 * 0x5b20) == local_c8)) &&
            (((local_64 == 0 && (((&DAT_006826fa)[local_60 * 0x120 + param_1 * 0x5b20] & 0x10) != 0)
              ) || ((local_64 == 1 &&
                    (((&DAT_006826fa)[local_60 * 0x120 + param_1 * 0x5b20] & 0x10) == 0)))))) &&
           ((((&DAT_006826fa)[local_60 * 0x120 + param_1 * 0x5b20] & 4) != 0 &&
            (((&DAT_006826fa)[local_60 * 0x120 + param_1 * 0x5b20] & 8) == 0)))) {
          local_d4 = local_d4 - *(int *)(&DAT_006826e4 + local_60 * 0x120 + param_1 * 0x5b20);
        }
      }
      for (local_60 = 0; local_60 < (int)(&DAT_00666408)[param_1]; local_60 = local_60 + 1) {
        if ((((*(int *)(&DAT_006826c0 + local_60 * 0x120 + param_1 * 0x5b20) == DAT_0068f104) &&
             ((char)(&DAT_006826d2)[local_60 * 0x120 + param_1 * 0x5b20] == local_6c)) &&
            (*(int *)(&DAT_006826e8 + local_60 * 0x120 + param_1 * 0x5b20) == local_c8)) &&
           ((((local_64 == 0 && (((&DAT_006826fa)[local_60 * 0x120 + param_1 * 0x5b20] & 0x10) != 0)
              ) || ((local_64 == 1 &&
                    (((&DAT_006826fa)[local_60 * 0x120 + param_1 * 0x5b20] & 0x10) == 0)))) &&
            ((((&DAT_006826fa)[local_60 * 0x120 + param_1 * 0x5b20] & 8) != 0 &&
             (local_d4 -
              ((int)(char)(&DAT_006826df)[local_60 * 0x120 + param_1 * 0x5b20] +
              *(int *)(&DAT_006826e4 + local_60 * 0x120 + param_1 * 0x5b20)) < 0)))))) {
          iVar2 = -(local_d4 -
                   ((int)(char)(&DAT_006826df)[local_60 * 0x120 + param_1 * 0x5b20] +
                   *(int *)(&DAT_006826e4 + local_60 * 0x120 + param_1 * 0x5b20)));
          if ((int)(char)(&DAT_006826df)[local_60 * 0x120 + param_1 * 0x5b20] +
              *(int *)(&DAT_006826e4 + local_60 * 0x120 + param_1 * 0x5b20) <= iVar2) {
            iVar2 = (int)(char)(&DAT_006826df)[local_60 * 0x120 + param_1 * 0x5b20] +
                    *(int *)(&DAT_006826e4 + local_60 * 0x120 + param_1 * 0x5b20);
          }
          FUN_004afd1c(local_6c,iVar2,
                       (int)(char)(&DAT_006826d3)[local_60 * 0x120 + param_1 * 0x5b20],
                       *(undefined4 *)(&DAT_006826ec + local_60 * 0x120 + param_1 * 0x5b20));
          local_d4 = local_d4 -
                     ((int)(char)(&DAT_006826df)[local_60 * 0x120 + param_1 * 0x5b20] +
                     *(int *)(&DAT_006826e4 + local_60 * 0x120 + param_1 * 0x5b20));
        }
      }
    }
    FUN_0046e793();
    FUN_0046d497(param_1);
    DAT_00666424 = 0;
    DAT_0068eee4 = 0;
    if (DAT_00690314 == 0) {
      FUN_0042abcf(DAT_0068f2c4);
    }
    local_64 = local_64 + 1;
  } while( true );
}


