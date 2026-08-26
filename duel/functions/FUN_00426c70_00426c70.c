/*
 * Decompiled function: FUN_00426c70
 * Entry Point: 00426c70
 * Size: 15615 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00426c70(int arg_1)

{
  int iVar1;
  uint uVar2;
  int local_7d0;
  char local_7c8 [100];
  int local_764;
  int local_760;
  int local_75c;
  int local_758 [80];
  int local_618;
  int local_614;
  int local_610;
  int local_60c [100];
  int local_47c [100];
  int local_2ec;
  int local_2e8;
  int local_2e4;
  int local_2e0;
  int local_2dc;
  int local_2d8;
  int local_2d4;
  int local_2d0;
  int local_2cc;
  int local_2c8;
  int local_2c4;
  int local_2c0;
  short local_2bc;
  int local_2b8;
  int local_2b4;
  int local_2b0;
  int local_2ac;
  undefined4 local_2a8;
  int local_2a4;
  int local_2a0;
  int local_29c;
  short asStack_298 [160];
  int local_158;
  int local_154;
  int local_150;
  undefined4 auStack_14c [16];
  uint local_10c;
  uint local_108 [64];
  int local_8;
  
  local_2b8 = 1 - arg_1;
  DAT_00666458 = arg_1;
  DAT_00666400 = -1;
  if (arg_1 == DAT_00676510) {
    DAT_006663f0 = DAT_006663f0 + 1;
  }
  for (local_2ac = 0; local_2ac < 0x50; local_2ac = local_2ac + 1) {
    (&DAT_00690b01)[local_2ac * 2 + local_2b8 * 0xa0] = 0;
    (&DAT_00690b00)[local_2ac * 2 + local_2b8 * 0xa0] =
         (&DAT_00690b01)[local_2ac * 2 + local_2b8 * 0xa0];
    (&DAT_00690b01)[local_2ac * 2 + arg_1 * 0xa0] =
         (&DAT_00690b00)[local_2ac * 2 + local_2b8 * 0xa0];
    (&DAT_00690b00)[local_2ac * 2 + arg_1 * 0xa0] = (&DAT_00690b01)[local_2ac * 2 + arg_1 * 0xa0];
  }
  FUN_004d714c();
  FUN_0048ebb3();
  for (local_2ac = 0; local_2ac < 0x26; local_2ac = local_2ac + 1) {
    *(uint *)(&DAT_006667c0 + local_2ac * 4) = *(uint *)(&DAT_006667c0 + local_2ac * 4) & 1;
    *(uint *)(&DAT_00666858 + local_2ac * 4) = *(uint *)(&DAT_00666858 + local_2ac * 4) & 1;
  }
  FUN_004398be();
  FUN_0048b64f();
  Mem_AllocOrFree_0048d3bf();
  FUN_0048cc29();
  if ((-1 < DAT_0066aaf4) && (DAT_00601578 == 0)) goto LAB_00426f96;
  for (local_2a0 = 0; local_2a0 < 2; local_2a0 = local_2a0 + 1) {
    for (local_2ac = 0; local_2ac < 0x50; local_2ac = local_2ac + 1) {
      if (*(int *)(&DAT_006826c4 + local_2a0 * 0x5b20 + local_2ac * 0x120) != -1) {
        (&DAT_00666408)[local_2a0] = local_2ac;
      }
    }
  }
  FUN_00451482(0,0xff);
  iVar1 = DAT_0066aaf4;
  local_8 = DAT_0066aaf4;
  DAT_0066aaf4 = 0;
  if ((iVar1 == -1) || (iVar1 == -2)) goto LAB_00427c45;
  if (iVar1 == -10) {
    DAT_0066aac4 = DAT_00666458;
    DAT_0066ab04 = DAT_0068f2c4;
    if (DAT_0068f2c4 == 0x22) {
      DAT_0066ab04 = 0x20;
    }
    if (DAT_0068f2c4 == 0) goto LAB_00426f96;
    if (DAT_0068f2c4 == 1) goto LAB_004270a4;
    if (DAT_0068f2c4 == 4) goto LAB_00427905;
    if (DAT_0068f2c4 != 10) {
      if (DAT_0068f2c4 == 0x14) goto LAB_00427c45;
      if (DAT_0068f2c4 == 0x1f) goto LAB_004299cd;
      if (DAT_0068f2c4 == 0x22) goto LAB_00429d78;
      goto LAB_00426f96;
    }
  }
  else {
LAB_00426f96:
    if (DAT_0066aaf4 != 1) {
      Pic_Subsystem_0044edf5(0);
    }
    if ((DAT_00681eb0 & 0x8000) != 0) {
      DAT_00681eb0 = DAT_00681eb0 & 0xffff7fff;
      Magic_ScanCards(0x22);
      return;
    }
    Mem_AllocOrFree_004305ae();
    DAT_0068f2c4 = 0;
    FUN_0048cfda(arg_1,0);
    Magic_ScanCards(0x6a);
    if ((DAT_00681eb0 & 0x8000) != 0) {
      DAT_00681eb0 = DAT_00681eb0 & 0xffff7fff;
      Magic_ScanCards(0x22);
      return;
    }
    DAT_006679a0 = '\0';
    DAT_006826b0 = 0;
    DAT_00681eb0 = DAT_00681eb0 & 0xfffffe00;
    FUN_00451482(0,0xff);
    for (local_2ac = 0; local_2ac < (&DAT_00666408)[arg_1]; local_2ac = local_2ac + 1) {
      *(uint *)(&DAT_006826cc + local_2ac * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&DAT_006826cc + local_2ac * 0x120 + arg_1 * 0x5b20) & 0xfffc7bf3;
    }
LAB_004270a4:
    local_2c0 = CardTypeFromID(0xe9);
    if ((local_2c0 == -1) ||
       (iVar1 = FUN_0041bcf0((int *)0x0,0,arg_1,2,2,0x200,0,0,0,0,0,0,local_2c0,0xffffffff,
                             0xffffffff,0xffffffff,0,0,0), iVar1 == 0)) {
      DAT_0068f2c4 = 1;
      FUN_0048cfda(arg_1,1);
      DAT_00690314 = 0;
      DAT_0068eee4 = 0;
      DAT_00666424 = 1;
      Mem_AllocOrFree_00431fe0(arg_1);
      _DAT_0068f0cc = 0;
      for (local_2ec = 0; local_2ec < (&DAT_00666408)[arg_1]; local_2ec = local_2ec + 1) {
        iVar1 = FUN_0048a33f(arg_1,local_2ec);
        if ((iVar1 != 0) && (((&DAT_006826cc)[local_2ec * 0x120 + arg_1 * 0x5b20] & 0x10) != 0)) {
          *(undefined4 *)(&DAT_006827c8 + local_2ec * 0x120 + arg_1 * 0x5b20) = 3;
          FUN_0048c50b(arg_1,local_2ec,0x82);
        }
      }
      local_2e0 = 0;
      while (local_2e0 == 0) {
        local_614 = 0;
        local_2e8 = 0;
        for (local_2e4 = 0; local_2e4 < 2; local_2e4 = local_2e4 + 1) {
          for (local_2ec = 0; local_2ec < (&DAT_00666408)[local_2e4]; local_2ec = local_2ec + 1) {
            if (((&DAT_006826cc)[local_2ec * 0x120 + local_2e4 * 0x5b20] & 2) != 0) {
              DAT_0068ecb0 = local_2e4;
              DAT_00690c48 = local_2ec;
              DAT_0066642c = 0;
              Magic_ScanCards(0x7d);
              local_610 = DAT_0066642c;
              if (DAT_0066642c == 1) {
                local_47c[local_614 * 2] = local_2e4;
                local_47c[local_614 * 2 + 1] = local_2ec;
                local_614 = local_614 + 1;
              }
              else if (DAT_0066642c == 2) {
                local_60c[local_2e8 * 2] = local_2e4;
                local_60c[local_2e8 * 2 + 1] = local_2ec;
                local_2e8 = local_2e8 + 1;
              }
            }
          }
        }
        if (((arg_1 == 1) || (DAT_0066aaf4 == 1)) || (DAT_0068f0b0 != 0)) {
          local_2e0 = 1;
          if (((arg_1 == 1) && (DAT_0066aaf4 != 1)) && (iVar1 = FUN_0042aa48(1), iVar1 != 0)) {
            local_2e0 = 0;
          }
        }
        else if (((local_2e8 == 0) || (local_2e8 == 1)) &&
                ((local_614 == 0 && (iVar1 = FUN_0042aa48(1), iVar1 == 0)))) {
          local_2e0 = 1;
        }
        if (local_2e0 == 0) {
          Mem_AllocOrFree_0048e302();
          if ((((arg_1 == 0) && (DAT_0066aaf4 != 1)) && (DAT_0068f0b0 == 0)) &&
             ((0 < local_2e8 || (0 < local_614)))) {
            Mem_AllocOrFree_004d9630((uint *)&DAT_005f6810,(uint *)s_Untap_effects__004f36b0);
            local_2dc = Ai_Subsystem_004bc029(0,-1,0,0xff,0,0x5f6810,2);
          }
          else {
            Mem_AllocOrFree_004d9630((uint *)&DAT_005f6810,(uint *)s_Paused__Untap_phase_004f36c0);
            local_2dc = Ai_Subsystem_004bc029
                                  (DAT_00676510,DAT_00676510,DAT_00676510,0xff,0,0x5f6810,2);
            DAT_00690314 = 1;
          }
          if (DAT_0068f2cc != -3) {
            if (DAT_0068f2cc == -2) {
              local_2e0 = 1;
            }
            else if ((DAT_0068f2cc == 0) && (local_2dc != -1)) {
              iVar1 = FUN_0042b0b7((int)local_60c,local_2e8,DAT_0068eef0,local_2dc);
              if ((iVar1 == 0) &&
                 (iVar1 = FUN_0042b0b7((int)local_47c,local_614,DAT_0068eef0,local_2dc), iVar1 == 0)
                 ) {
                iVar1 = FUN_0042b120(DAT_0068eef0,local_2dc);
                if (iVar1 != 0) {
                  FUN_0042b213(DAT_0068eef0,local_2dc);
                }
              }
              else {
                DAT_0068ecb0 = DAT_0068eef0;
                DAT_00690c48 = local_2dc;
                Magic_ScanCards(0x7e);
              }
            }
          }
        }
      }
      if (local_2e8 != 0) {
        local_2e0 = 0;
        while (local_2e0 == 0) {
          local_2e8 = 0;
          local_2e4 = 0;
          while ((local_2e4 < 2 && (local_2e8 == 0))) {
            local_2ec = 0;
            while ((local_2ec < (&DAT_00666408)[local_2e4] && (local_2e8 == 0))) {
              if (((&DAT_006826cc)[local_2ec * 0x120 + local_2e4 * 0x5b20] & 2) != 0) {
                DAT_0068ecb0 = local_2e4;
                DAT_00690c48 = local_2ec;
                DAT_0066642c = 0;
                Magic_ScanCards(0x7d);
                local_610 = DAT_0066642c;
                if (DAT_0066642c == 2) {
                  local_60c[local_2e8 * 2] = local_2e4;
                  local_60c[local_2e8 * 2 + 1] = local_2ec;
                  local_2e8 = local_2e8 + 1;
                }
              }
              local_2ec = local_2ec + 1;
            }
            local_2e4 = local_2e4 + 1;
          }
          if (local_2e8 == 0) {
            local_2e0 = 1;
          }
          else {
            DAT_0068ecb0 = local_60c[0];
            DAT_00690c48 = local_60c[1];
            Magic_ScanCards(0x7e);
          }
        }
      }
      for (local_2ec = 0; local_2ec < (&DAT_00666408)[arg_1]; local_2ec = local_2ec + 1) {
        if ((((&DAT_006827c8)[local_2ec * 0x120 + arg_1 * 0x5b20] & 1) != 0) &&
           (((&DAT_006827c8)[local_2ec * 0x120 + arg_1 * 0x5b20] & 2) != 0)) {
          *(uint *)(&DAT_006826cc + local_2ec * 0x120 + arg_1 * 0x5b20) =
               *(uint *)(&DAT_006826cc + local_2ec * 0x120 + arg_1 * 0x5b20) & 0xffffffef;
          FUN_0048c907(arg_1,local_2ec,0x83,1 - arg_1,0xffffffff);
        }
      }
      for (local_2ec = 0; local_2ec < (&DAT_00666408)[arg_1]; local_2ec = local_2ec + 1) {
        iVar1 = FUN_0048a33f(arg_1,local_2ec);
        if (iVar1 != 0) {
          *(undefined4 *)(&DAT_006827c8 + local_2ec * 0x120 + arg_1 * 0x5b20) = 0;
        }
      }
      FUN_00451482(0,0xff);
      local_150 = DAT_00690314;
      if (DAT_00690314 == 0) {
        FUN_0042abcf(1);
      }
      FUN_0042ae2a();
      iVar1 = FUN_0042afdb();
      if (iVar1 != 0) {
        return;
      }
    }
LAB_00427905:
    DAT_0068f2c0 = 0;
    DAT_00690314 = 0;
    DAT_00666424 = 0;
    if ((DAT_0066ab04 == -1) || ((DAT_0066ab04 == 4 && (DAT_0066aac4 == arg_1)))) {
      DAT_0068eee4 = 0;
    }
    else {
      DAT_0068eee4 = 1;
    }
    DAT_0068f2c4 = 2;
    FUN_0048cfda(arg_1,2);
    FUN_0048e8f2(arg_1,0xc9,s_Begin_Upkeep_004f36d4,0);
    DAT_00666424 = 1;
    DAT_0068f2c4 = 4;
    FUN_0048f123();
    FUN_0048e32b(-1,DAT_0068f2c4,s_Upkeep_Phase_004f36e4,4);
    DAT_00666424 = 0;
    FUN_0048e8f2(arg_1,0xcb,s_End_Upkeep_004f36f4,0);
    DAT_0068eee4 = 0;
    DAT_00666440 = 1;
    Pic_Subsystem_004475a4(arg_1);
    DAT_00666440 = 0;
    DAT_0068f2c0 = 0;
    FUN_0042ae2a();
    iVar1 = FUN_0042afdb();
    if (iVar1 != 0) {
      return;
    }
  }
  if ((DAT_00681ec0 == 0) || (DAT_00681ec0 = 0, DAT_0066aaf0 == 0)) {
    DAT_0068f2c4 = 10;
    FUN_0048cfda(arg_1,10);
    DAT_00690314 = 0;
    DAT_00666424 = 0;
    if ((DAT_0066ab04 == -1) || ((DAT_0066ab04 == 10 && (DAT_0066aac4 == arg_1)))) {
      DAT_0068eee4 = 0;
    }
    else {
      DAT_0068eee4 = 1;
    }
    FUN_0048e8f2(arg_1,0xce,s_Draw_Phase_004f3700,1);
    DAT_0066642c = 1;
    Magic_ScanCards(10);
    local_8 = DAT_0066642c;
    if (0 < DAT_0066642c) {
      if (arg_1 == DAT_00676510) {
        for (local_2ac = 0; local_2ac < local_8; local_2ac = local_2ac + 1) {
          local_2b4 = Pic_Subsystem_00451291(arg_1,DAT_006764b4);
          if (local_2b4 != -1) {
            *(uint *)(&DAT_006826cc + local_2b4 * 0x120 + arg_1 * 0x5b20) =
                 *(uint *)(&DAT_006826cc + local_2b4 * 0x120 + arg_1 * 0x5b20) | 2;
          }
        }
        FUN_00451482(0,0x30);
      }
      else {
        for (local_2ac = 0; local_2ac < local_8; local_2ac = local_2ac + 1) {
          FUN_00487ce1(arg_1);
        }
      }
    }
    DAT_00666424 = 1;
    DAT_00690314 = 0;
    FUN_0048e32b(-1,DAT_0068f2c4,s_Draw_Phase_004f370c,DAT_0068f2c4);
    DAT_00666424 = 0;
    local_150 = DAT_00690314;
    DAT_0068eee4 = 0;
    Mem_AllocOrFree_00431fe0(arg_1);
    FUN_0042ae2a();
    iVar1 = FUN_0042afdb();
    if (iVar1 != 0) {
      return;
    }
  }
LAB_00427c45:
  DAT_006826b0 = 0;
  DAT_00681eb0 = DAT_00681eb0 & 0xfffffe00;
  DAT_0068f2c4 = 0x14;
  FUN_0048cfda(arg_1,0x14);
  DAT_00690314 = 0;
  DAT_00666424 = 0;
  if (DAT_0066aaf4 != 1) {
    DAT_0068eee4 = 0;
  }
LAB_00427ca0:
  do {
    if (arg_1 != DAT_00676510) {
      FUN_00451482(0,0xff);
      FUN_0048b5c9(1,((DAT_0068f2c4 < 0x1e) - 1 & 0xffffffd3) + 0x5a);
      DAT_0066aae0 = 0;
    }
LAB_00427ce5:
    DAT_00666424 = 1;
    DAT_0068ef48 = 0;
    if (arg_1 != DAT_00676510) {
      FUN_004305d3();
      DAT_0068ecbc = 0;
      DAT_0068ecb8 = 0;
      DAT_0066aae4 = 0;
      DAT_0068f2d4 = 0;
      if (((DAT_0066aaf4 != 1) && ((DAT_00681eb0 & 0x40) == 0)) && (DAT_006679a0 != '\0')) {
        FUN_004d7e29(&DAT_006679a0);
        DAT_00681eb0 = DAT_00681eb0 | 0x40;
        DAT_006679a0 = '\0';
      }
    }
LAB_00427d78:
    local_154 = 0;
    local_2a8 = 6;
    while (((DAT_00690c44 = 0, arg_1 == DAT_00676510 || (DAT_0066aaf4 == 1)) ||
           ((_DAT_0068f0c8 & 2) == 0))) {
      DAT_005ef980 = 0;
      if ((DAT_0066aaf4 != 1) && (DAT_006679a0 != '\0')) {
        FUN_004d7e29(&DAT_006679a0);
      }
      if (arg_1 == DAT_00676510) {
        if (DAT_00681ea4 == 1) {
          FUN_004d7e62(s_Cancel_error_004f3718);
          DAT_00681ea4 = 0;
        }
        do {
          while( true ) {
            DAT_00681eb0 = DAT_00681eb0 | 0x80;
            DAT_005f6810 = 0;
            if (DAT_0068f2c4 < 0x15) break;
            if (0x1d < DAT_0068f2c4) {
              Mem_AllocOrFree_004d9630
                        ((uint *)&DAT_005f6810,(uint *)s_Main_phase__after_combat___cast_s_004f3760)
              ;
              if ((DAT_00681eb0 & 1) == 0) {
                FUN_004d9640((uint *)&DAT_005f6810,(uint *)s___play_land_004f3788);
              }
              FUN_004d9640((uint *)&DAT_005f6810,(uint *)&DAT_004f3794);
              goto LAB_00427fc4;
            }
            if (arg_1 == DAT_00676510) {
              iVar1 = FUN_0048acd3(arg_1);
              if ((iVar1 != 0) || (iVar1 = FUN_0042ab67(0x15), iVar1 != 0)) goto LAB_00427f58;
              DAT_0068f2c4 = 0x1e;
            }
            else {
              iVar1 = FUN_0048b0c7(arg_1);
              if (iVar1 != 0) {
LAB_00427f58:
                if (DAT_00663e24 == 2) {
                  Mem_AllocOrFree_004d9630
                            ((uint *)&DAT_005f6810,
                             (uint *)(s_Choose_attackers__004f3798 +
                                     ((arg_1 == DAT_00666458) - 1 & 0x14)));
                }
                else {
                  Mem_AllocOrFree_004d9630
                            ((uint *)&DAT_005f6810,
                             (uint *)(s_Combat_phase__Choose_attackers__004f37c0 +
                                     ((arg_1 == DAT_00666458) - 1 & 0x20)));
                }
                goto LAB_00427fc4;
              }
              DAT_0068f2c4 = 0x1e;
            }
          }
          Mem_AllocOrFree_004d9630
                    ((uint *)&DAT_005f6810,(uint *)s_Main_phase__before_combat___cast_004f3728);
          if ((DAT_00681eb0 & 1) == 0) {
            FUN_004d9640((uint *)&DAT_005f6810,(uint *)s___play_land_004f3750);
          }
          FUN_004d9640((uint *)&DAT_005f6810,(uint *)&DAT_004f375c);
LAB_00427fc4:
          do {
            Mem_AllocOrFree_0048e302();
            iVar1 = FUN_0042a99c();
            if ((iVar1 == 0) || ((DAT_0068f2c4 == 0x15 && (DAT_006c1218 != 0)))) {
              local_2dc = Ai_Subsystem_004bc029(arg_1,arg_1,arg_1,0,0,0x5f6810,2);
            }
            else {
              DAT_0068f2cc = -2;
              local_2dc = -1;
            }
            if (local_2dc == -2) {
              local_2dc = -1;
            }
          } while (((DAT_0068f2c4 == 0x15) && (local_2dc < 0)) &&
                  (FUN_0048afc2(arg_1), DAT_006c1218 != 0));
          if ((DAT_0068f2cc == -2) && (DAT_0066aaf4 != 1)) {
            if (DAT_0068f2c4 < 0x18) {
              if (DAT_0066ab04 < 0x19) {
                DAT_0068eee4 = 0;
              }
              else {
                DAT_0068eee4 = 1;
              }
            }
            if (DAT_0068f2c4 < 0x16) {
              if (DAT_0066ab04 < 0x17) {
                DAT_0068eee4 = 0;
              }
              else {
                DAT_0068eee4 = 1;
              }
            }
          }
          DAT_00681eb0 = DAT_00681eb0 & 0xffffff7f;
          if ((DAT_0068f2cc != -2) || ((DAT_0066aac4 != -1 && (DAT_0066ab04 == -1))))
          goto LAB_00428424;
          iVar1 = Mem_AllocOrFree_00431fe0(arg_1);
          if (iVar1 == 0) {
            if (0x14 < DAT_0068f2c4) {
              if (0x1d < DAT_0068f2c4) goto LAB_004299ac;
              if ((arg_1 == DAT_00676510) && (DAT_0066aaf4 != 1)) {
                DAT_005f6810 = 0;
              }
              if ((DAT_006826b0 < 1) && (iVar1 = FUN_0048afc2(arg_1), iVar1 != 0))
              goto LAB_00428fa9;
              local_154 = 1;
              goto LAB_00428fa9;
            }
            Magic_ScanCards(0x89);
            FUN_0042ae2a();
            iVar1 = FUN_0042afdb();
            if (iVar1 != 0) {
              return;
            }
            FUN_0048cfda(arg_1,DAT_0068f2c4);
            if ((((DAT_006826b0 == 0) &&
                 ((iVar1 = FUN_0048acd3(arg_1), iVar1 == 0 || (iVar1 = FUN_0042a99c(), iVar1 != 0)))
                 ) && ((DAT_0066aac4 != DAT_00676510 || (DAT_0066ab04 != 0x15)))) &&
               (((&DAT_00666814)[arg_1 * 0x98] & 1) == 0)) goto LAB_00428fa9;
            DAT_0068f2c4 = 0x15;
            if (((DAT_00666458 == DAT_00676510) && (DAT_0066aac4 == DAT_00676510)) &&
               (DAT_0066ab04 == 0x15)) {
              *(uint *)(&DAT_00666814 + DAT_00676510 * 0x98) =
                   *(uint *)(&DAT_00666814 + DAT_00676510 * 0x98) | 2;
              *(uint *)(&DAT_00666818 + DAT_00676510 * 0x98) =
                   *(uint *)(&DAT_00666818 + DAT_00676510 * 0x98) | 2;
              *(uint *)(&DAT_00666820 + DAT_00676510 * 0x98) =
                   *(uint *)(&DAT_00666820 + DAT_00676510 * 0x98) | 2;
            }
            iVar1 = FUN_0042a99c();
            if (((iVar1 != 0) && (DAT_006826b0 == 0)) && (iVar1 = FUN_0048afc2(arg_1), iVar1 != 0))
            goto LAB_00428fa9;
            FUN_0048cfda(arg_1,DAT_0068f2c4);
            if (arg_1 != DAT_00676510) goto LAB_00428f9c;
            if (DAT_0066aaf4 == 1) goto LAB_00428f9c;
            if (DAT_00663e24 == 2) {
              Mem_AllocOrFree_004d9630((uint *)&DAT_005f6810,(uint *)s_Choose_attackers__004f3820);
              goto LAB_00428f9c;
            }
            Mem_AllocOrFree_004d9630
                      ((uint *)&DAT_005f6810,(uint *)s_Combat_phase__choose_attackers__004f3800);
            goto LAB_00428f9c;
          }
        } while( true );
      }
      Mem_AllocOrFree_0048e302();
      DAT_005ef980 = 2;
      local_2dc = FUN_0042ed60(arg_1);
      if (local_2dc == -1) {
        if (DAT_0066aaf4 != 1) {
          FUN_0048e32b(0,DAT_0068f2c4,s_Main_Phase_004f3834,DAT_0068f2c4);
        }
        if (DAT_0068f2c4 == 0x14) {
          DAT_0068f2c4 = 0x15;
        }
        else {
          DAT_0068f2c4 = 0x1e;
        }
        FUN_0048cfda(arg_1,DAT_0068f2c4);
        FUN_0042ae2a();
        iVar1 = FUN_0042afdb();
        if (iVar1 != 0) {
          return;
        }
        local_154 = 1;
      }
LAB_00428424:
      DAT_005ef980 = 3;
      local_2a8 = 0;
      if (local_2dc != -1) {
        local_158 = *(int *)(&DAT_006826c4 + local_2dc * 0x120 + arg_1 * 0x5b20);
        if (((&DAT_006826cc)[local_2dc * 0x120 + arg_1 * 0x5b20] & 0x12) == 0) {
          if ((((&DAT_004ff594)[local_158 * 0x34] & 1) == 0) || ((DAT_00681eb0 & 1) == 0)) {
            if (DAT_0068f2c4 != 0x15) {
              DAT_00681ea0 = 0;
              DAT_0068ecd0 = 0xffffffff;
              iVar1 = FUN_00488662(arg_1,local_2dc,0);
              if (iVar1 != 0) {
                if (arg_1 != DAT_00676510) goto LAB_00428569;
                if (DAT_0068f2c4 == 0x15) goto LAB_00428569;
                if (((&DAT_004ff594)[local_158 * 0x34] & 1) != 0) goto LAB_00428569;
                FUN_0048b5c9(4,0x1e);
                goto LAB_00428569;
              }
            }
          }
          else if (DAT_0066aaf4 == 1) {
            local_154 = 1;
          }
        }
        else {
          if (((DAT_0068f2c4 < 0x15) || (0x1d < DAT_0068f2c4)) || (arg_1 != DAT_00676510)) {
            DAT_0068ed04 = 0xffffffff;
            DAT_0068f0bc = 0xffffffff;
            if (((((&DAT_004ff5a8)[local_158 * 0x34] & 3) == 0) ||
                (((&DAT_006826cc)[local_2dc * 0x120 + arg_1 * 0x5b20] & 0x24) != 0)) &&
               (((&DAT_004ff5a9)[local_158 * 0x34] & 0x10) == 0)) goto LAB_00428c4f;
            iVar1 = FUN_0048c907(arg_1,local_2dc,0x73,local_2b8,0xffffffff);
            if (iVar1 == 0) goto LAB_00428c4f;
            if ((arg_1 != DAT_00676510) && (DAT_0066aaf4 != 1)) {
              DAT_0066aac4 = DAT_00666458;
              DAT_0066ab04 = DAT_0068f2c4;
            }
            if (DAT_0066aaf4 != 1) {
              DAT_00681ea4 = -1;
            }
            local_618 = FUN_0048974c(arg_1,local_2dc);
            DAT_0068ed04 = 0xffffffff;
            if (local_618 == 0) goto LAB_00428bb6;
            if (DAT_0066aaf4 == 1) goto LAB_00428b10;
            if (arg_1 != DAT_00676510) goto LAB_00428b10;
            if (DAT_0068f2c4 == 0x15) goto LAB_00428b10;
            if (((&DAT_004ff5a9)
                 [*(int *)(&DAT_006826c4 + local_2dc * 0x120 + arg_1 * 0x5b20) * 0x34] & 0x10) != 0)
            goto LAB_00428b10;
            FUN_0048b5c9(7,0xf);
            goto LAB_00428b10;
          }
          if ((((arg_1 == DAT_00676510) && (((&DAT_004ff594)[local_158 * 0x34] & 2) != 0)) &&
              ((*(uint *)(&DAT_006826cc + local_2dc * 0x120 + arg_1 * 0x5b20) & 0x10014) == 0)) &&
             ((-1 < DAT_006826b0 && (iVar1 = FUN_0048ad82(arg_1,local_2dc), iVar1 != 0)))) {
            FUN_0048cac9();
            Mem_AllocOrFree_004d9630(local_108,(uint *)&DAT_005f6810);
            DAT_00666754 = arg_1;
            DAT_0068edd0 = local_2dc;
            DAT_00666428 = 0;
            FUN_0048e8f2(arg_1,0xdc,s_Pay_for_attacker_004f3910,1);
            Mem_AllocOrFree_004d9630((uint *)&DAT_005f6810,local_108);
            FUN_0048cb7f();
            if (DAT_00666428 == 0) {
              (&DAT_006826de)[local_2dc * 0x120 + arg_1 * 0x5b20] = 0xff;
              iVar1 = DAT_006826b0;
              DAT_006826b0 = DAT_006826b0 + 1;
              if (iVar1 == 0) {
                FUN_0042ae2a();
                iVar1 = FUN_0042afdb();
                if (iVar1 != 0) {
                  return;
                }
                FUN_0048cfda(arg_1,DAT_0068f2c4);
              }
              uVar2 = FUN_0048b81a(arg_1,local_2dc,0x34,0xffffffff);
              if ((((uVar2 & 0x200040) != 0) && (1 < DAT_006826b0)) && (DAT_0066643c == 0)) {
                Mem_AllocOrFree_004d9630
                          ((uint *)&DAT_005f6810,(uint *)s_Band_with_other_attacker__004f3924);
                iVar1 = Action_ValidateTarget_0041e2a2
                                  (arg_1,arg_1,arg_1,0x200,0,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0
                                   ,2,0,&DAT_005f6810,2,&local_2d4);
                if (iVar1 != 0) {
                  local_2a4 = local_2d0;
                  if ((&DAT_006826de)[local_2d0 * 0x120 + arg_1 * 0x5b20] == -1) {
                    local_2a4._0_1_ = (undefined1)local_2d0;
                    (&DAT_006826de)[local_2d0 * 0x120 + arg_1 * 0x5b20] = (undefined1)local_2a4;
                    (&DAT_006826de)[local_2dc * 0x120 + arg_1 * 0x5b20] = (undefined1)local_2a4;
                  }
                  else {
                    (&DAT_006826de)[local_2dc * 0x120 + arg_1 * 0x5b20] =
                         (&DAT_006826de)[local_2d0 * 0x120 + arg_1 * 0x5b20];
                  }
                }
              }
              *(uint *)(&DAT_006826cc + local_2dc * 0x120 + arg_1 * 0x5b20) =
                   *(uint *)(&DAT_006826cc + local_2dc * 0x120 + arg_1 * 0x5b20) | 4;
              local_2a8 = 2;
            }
            else if (DAT_0066aaf4 != 1) {
              Mem_AllocOrFree_00450eed(s_Illegal_attacker__004f3940);
              Sleep(2000);
              Mem_AllocOrFree_00450eed(&DAT_004f3954);
            }
          }
        }
      }
LAB_00428f8a:
      while( true ) {
        if (DAT_0068ef40 != 0) {
          return;
        }
LAB_00428f9c:
        if (local_154 == 0) break;
LAB_00428fa9:
        DAT_005ef980 = 4;
        DAT_00666440 = 1;
        Pic_Subsystem_004475a4(arg_1);
        if ((arg_1 != DAT_00676510) &&
           (((DAT_0066aaf4 != 1 || (DAT_00666400 != 1)) && (DAT_0068f2c4 == 0x1e))))
        goto LAB_004299ac;
        if (arg_1 == DAT_00676510) goto LAB_0042943f;
        if (0x1d < DAT_0068f2c4) goto LAB_0042943f;
        Magic_ScanCards(0x89);
        iVar1 = FUN_00474d83(arg_1);
        if (iVar1 == 0) goto LAB_0042943f;
        if (DAT_00666458 == 1) {
          DAT_0066ab04 = -1;
          DAT_0066aac4 = -1;
        }
        DAT_00666754 = arg_1;
        for (DAT_0068edd0 = 0; DAT_0068edd0 < (&DAT_00666408)[arg_1];
            DAT_0068edd0 = DAT_0068edd0 + 1) {
          if ((*(int *)(&DAT_006826c4 + DAT_0068edd0 * 0x120 + DAT_00666754 * 0x5b20) != -1) &&
             (((byte)*(undefined4 *)(&DAT_006826cc + DAT_0068edd0 * 0x120 + DAT_00666754 * 0x5b20) &
              6) == 6)) {
            FUN_0048cac9();
            Mem_AllocOrFree_004d9630(local_108,(uint *)&DAT_005f6810);
            DAT_00666428 = 0;
            FUN_0048e8f2(arg_1,0xdc,s_Pay_for_attacker_004f3958,1);
            Mem_AllocOrFree_004d9630((uint *)&DAT_005f6810,local_108);
            FUN_0048cb7f();
            if ((DAT_00666428 != 0) &&
               (*(uint *)(&DAT_006826cc + DAT_0068edd0 * 0x120 + DAT_00666754 * 0x5b20) =
                     *(uint *)(&DAT_006826cc + DAT_0068edd0 * 0x120 + DAT_00666754 * 0x5b20) &
                     0xfffffffb, (&DAT_006826de)[DAT_0068edd0 * 0x120 + DAT_00666754 * 0x5b20] != -1
               )) {
              local_760 = 0;
              for (local_75c = 0; local_75c < (&DAT_00666408)[arg_1]; local_75c = local_75c + 1) {
                if ((local_75c != DAT_0068edd0) &&
                   ((&DAT_006826de)[local_75c * 0x120 + arg_1 * 0x5b20] ==
                    (&DAT_006826de)[DAT_0068edd0 * 0x120 + DAT_00666754 * 0x5b20])) {
                  local_758[local_760] = local_75c;
                  local_760 = local_760 + 1;
                }
              }
              if (local_760 == 1) {
                (&DAT_006826de)[arg_1 * 0x5b20 + local_758[0] * 0x120] = 0xff;
              }
              else {
                for (local_75c = 0; local_75c < local_760; local_75c = local_75c + 1) {
                  (&DAT_006826de)[arg_1 * 0x5b20 + local_758[local_75c] * 0x120] =
                       (undefined1)local_758[0];
                }
              }
            }
          }
        }
        FUN_0042ae2a();
        iVar1 = FUN_0042afdb();
        if (iVar1 != 0) {
          return;
        }
        FUN_0048cfda(arg_1,DAT_0068f2c4);
        Magic_ScanCards(0x15);
        FUN_0048cfda(arg_1,DAT_0068f2c4);
        DAT_0068f2c4 = 0x16;
        FUN_0048cfda(arg_1,0x16);
        do {
          if (DAT_0066aaf4 != 1) {
            FUN_00451482(0,0xff);
            FUN_0048b5c9(8,0x1e);
          }
LAB_00429373:
          if (DAT_00666400 == 8) {
            FUN_004305d3();
            DAT_0068ecbc = 0;
            DAT_0068ecb8 = 0;
            DAT_0066aae4 = 0;
            DAT_0068f2d4 = 0;
          }
          DAT_00666424 = 1;
          local_29c = FUN_0048e32b(-2,DAT_0068f2c4,s_Assign_Attackers_004f396c,0x16);
          DAT_00666424 = 0;
        } while (local_29c != 0);
        DAT_0068f2c4 = 0x17;
        FUN_0048cfda(arg_1,0x17);
        FUN_0048e8f2(1 - arg_1,0xda,s_Choose_Defenders_004f3980,0);
        Card_Setup_00467a68(arg_1);
        DAT_006826b0 = 1;
LAB_0042943f:
        if ((arg_1 == DAT_00676510) && (DAT_0068f2c4 < 0x1e)) {
          iVar1 = FUN_0042a99c();
          if ((iVar1 != 0) && ((DAT_006826b0 == 0 && (iVar1 = FUN_0042ab67(0x15), iVar1 == 0))))
          goto LAB_00429888;
          Magic_ScanCards(0x15);
          if ((DAT_0066aaf4 == 1) && (DAT_0068f2c4 < 0x15)) {
            FUN_00474d83(arg_1);
          }
          iVar1 = FUN_0048afc2(arg_1);
          if (iVar1 != 0) {
            if (arg_1 != DAT_00676510) goto LAB_00429888;
            iVar1 = FUN_0042ab67(0x15);
            if (iVar1 == 0) goto LAB_00429888;
          }
          if (DAT_006826b0 == 0) {
            DAT_006826b0 = 1;
            FUN_0042ae2a();
            iVar1 = FUN_0042afdb();
            if (iVar1 != 0) {
              return;
            }
            FUN_0048cfda(arg_1,DAT_0068f2c4);
          }
          FUN_0048e8f2(arg_1,0xd9,s_Choose_Attackers_004f3994,0);
          goto LAB_00429548;
        }
LAB_00429692:
        Magic_ScanCards(0x1a);
        FUN_0048ee91(arg_1);
        if (((0 < DAT_006826b0) ||
            ((arg_1 == DAT_00676510 && (iVar1 = FUN_0042ab67(0x18), iVar1 != 0)))) &&
           ((DAT_00681eb0 & 8) == 0)) goto LAB_004296fd;
        if ((arg_1 == DAT_00676510) && (DAT_0066aaf4 == 1)) goto LAB_004296fd;
LAB_00429888:
        if ((arg_1 == DAT_00676510) && (DAT_0066aaf4 != 1)) {
          if (DAT_0068f2c4 < 0x1e) {
            if (DAT_00681eac <= DAT_0068ee74 / 2) {
              FUN_004d7e29(s__Ouch__that_hurt___004f39f0);
            }
            DAT_006826b0 = 0;
            DAT_0068f2c4 = 0x1e;
            FUN_0048cfda(arg_1,0x1e);
            iVar1 = FUN_0042a99c();
            if (iVar1 == 0) goto LAB_00427ce5;
          }
          else if (DAT_00681ea8 <= DAT_00681eac / 2) {
            FUN_004d7e29(s__Give_up__you_re_doomed___004f3a04);
          }
        }
        if ((arg_1 != DAT_00676510) && (DAT_0068f2c4 != 0x1e)) {
          DAT_0068f2c4 = 0x1e;
          FUN_0048cfda(arg_1,0x1e);
          if (DAT_0066aaf4 != 1) {
            DAT_00681eb0 = DAT_00681eb0 | 0x100;
            goto LAB_00427ca0;
          }
          if ((DAT_00666400 == 1) || (DAT_00666400 == 2)) goto LAB_00427d78;
        }
LAB_004299ac:
        DAT_005ef980 = 5;
        FUN_0042ae2a();
        iVar1 = FUN_0042afdb();
        if (iVar1 != 0) {
          return;
        }
LAB_004299cd:
        local_2d8 = CardTypeFromID(0x8c);
        if ((local_2d8 != -1) &&
           (iVar1 = FUN_0041bcf0((int *)0x0,0,arg_1,arg_1,arg_1,0x200,0,0,0,0,0,0,local_2d8,
                                 0xffffffff,0xffffffff,0xffffffff,0,0,0), iVar1 != 0))
        goto LAB_00429d78;
        local_764 = 0;
        DAT_00690314 = 0;
        if (DAT_0066aaf4 != 1) {
          if ((DAT_0066ab04 == -1) || ((DAT_0066ab04 == 0x1f && (DAT_0066aac4 == arg_1)))) {
            DAT_0068eee4 = 0;
          }
          else {
            DAT_0068eee4 = 1;
          }
        }
LAB_00429a9e:
        DAT_00666424 = 0;
        if ((DAT_0066aaf4 != 1) && (arg_1 == DAT_00676510)) {
          FUN_00451482(0,0xff);
          FUN_0048b5c9(3,0x1e);
        }
LAB_00429ad4:
        if (DAT_00666400 == 3) {
          FUN_004305d3();
          DAT_0068ecbc = 0;
          DAT_0068ecb8 = 0;
          DAT_0066aae4 = 0;
          DAT_0068f2d4 = 0;
        }
        DAT_0068f2c4 = 0x1f;
        FUN_0048cfda(arg_1,0x1f);
        DAT_00666424 = 1;
        if (arg_1 == DAT_00676510) {
          local_7d0 = -1;
        }
        else {
          local_7d0 = arg_1;
        }
        local_29c = FUN_0048e32b(local_7d0,DAT_0068f2c4,s_Discard_Phase_004f3a20,0x1f);
        DAT_00666424 = 0;
        if (local_29c != 0) goto LAB_00429a9e;
        if (DAT_0066aaf4 == 1) {
          if (arg_1 != DAT_00676510) goto LAB_00429bca;
        }
        else {
          DAT_0068eee4 = 0;
LAB_00429bca:
          if ((DAT_00681eb0 & 0x800 << ((byte)arg_1 & 0x1f)) == 0) {
            if (arg_1 == DAT_00676510) {
              local_2c8 = 0;
            }
            else {
              local_2c8 = DAT_006668f8;
            }
            for (local_2ac = 0; local_2ac < (&DAT_00666408)[arg_1]; local_2ac = local_2ac + 1) {
              if ((*(int *)(&DAT_006826c4 + local_2ac * 0x120 + arg_1 * 0x5b20) != -1) &&
                 (((&DAT_006826cc)[local_2ac * 0x120 + arg_1 * 0x5b20] & 2) == 0)) {
                local_2c8 = local_2c8 + 1;
              }
            }
            DAT_0066642c = 0;
            Magic_ScanCards(0x1f);
            local_764 = 0;
            while ((DAT_0066642c == 0 && (7 < local_2c8))) {
              Palette_Color_0049ae00(arg_1,0,1);
              local_2c8 = local_2c8 + -1;
              if ((arg_1 == DAT_00676504) && (DAT_0066aaf4 == 1)) {
                DAT_0068f2d4 = DAT_0068f2d4 + -0x18;
              }
              if (((arg_1 == 0) && (DAT_0066aaf4 == 0)) && (DAT_0068f0b0 == 0)) {
                local_764 = 1;
              }
            }
          }
        }
        if (local_764 != 0) {
          FUN_0042ad51(s_Paused__Discard_phase_004f3a30);
          local_150 = 1;
          local_764 = 0;
        }
        FUN_0042ae2a();
        iVar1 = FUN_0042afdb();
        if (iVar1 != 0) {
          return;
        }
LAB_00429d78:
        if (DAT_0066aaf4 != 1) {
          DAT_0068f2c4 = 0x22;
          FUN_0048cfda(arg_1,0x22);
          DAT_00690314 = 0;
          DAT_00666424 = 0;
          if (DAT_0066aaf4 != 1) {
            if ((DAT_0066ab04 == -1) || ((DAT_0066ab04 == 0x20 && (DAT_0066aac4 == arg_1)))) {
              DAT_0068eee4 = 0;
            }
            else {
              DAT_0068eee4 = 1;
            }
          }
        }
        local_2ac = 0;
        while( true ) {
          iVar1 = DAT_0066640c;
          if (DAT_0066640c <= DAT_00666408) {
            iVar1 = DAT_00666408;
          }
          if (iVar1 <= local_2ac) break;
          if ((*(int *)(&DAT_006826c4 + local_2ac * 0x120 + arg_1 * 0x5b20) != -1) &&
             (((&DAT_006826cc)[local_2ac * 0x120 + arg_1 * 0x5b20] & 2) != 0)) {
            *(undefined2 *)(&DAT_006826d0 + local_2ac * 0x120 + arg_1 * 0x5b20) = 0;
            FUN_0048c907(arg_1,local_2ac,0x22,local_2b8,0xffffffff);
          }
          if ((*(int *)(&DAT_006826c4 + local_2b8 * 0x5b20 + local_2ac * 0x120) != -1) &&
             (((&DAT_006826cc)[local_2b8 * 0x5b20 + local_2ac * 0x120] & 2) != 0)) {
            *(undefined2 *)(&DAT_006826d0 + local_2b8 * 0x5b20 + local_2ac * 0x120) = 0;
            FUN_0048c907(local_2b8,local_2ac,0x22,arg_1,0xffffffff);
          }
          local_2ac = local_2ac + 1;
        }
        if (DAT_00666418 != -1) {
          (**(code **)(&DAT_004ff5a0 + DAT_00666418 * 0x34))(0,0x4e,0x22);
        }
        FUN_0048e8a8(arg_1,0xcd,s_End_of_Turn_004f3a48,0);
        Pic_Subsystem_004488a0();
        if (DAT_0066aaf4 != 1) {
          DAT_0068eee4 = 0;
        }
        Pic_Subsystem_004475a4(arg_1);
        FUN_00451482(0,0xff);
        local_2bc = 0;
        for (local_2ac = 0; local_2ac < 0x50; local_2ac = local_2ac + 1) {
          if (*(int *)(&DAT_006826c4 + local_2ac * 0x120 + arg_1 * 0x5b20) != -1) {
            *(uint *)(&DAT_006826cc + local_2ac * 0x120 + arg_1 * 0x5b20) =
                 *(uint *)(&DAT_006826cc + local_2ac * 0x120 + arg_1 * 0x5b20) & 0xffff7db2;
            (&DAT_006826de)[local_2ac * 0x120 + arg_1 * 0x5b20] = 0xff;
            *(undefined2 *)(&DAT_006826d0 + local_2ac * 0x120 + arg_1 * 0x5b20) = 0;
          }
          if (*(int *)(&DAT_006826c4 + local_2b8 * 0x5b20 + local_2ac * 0x120) != -1) {
            *(uint *)(&DAT_006826cc + local_2b8 * 0x5b20 + local_2ac * 0x120) =
                 *(uint *)(&DAT_006826cc + local_2b8 * 0x5b20 + local_2ac * 0x120) & 0xffff7db2;
            (&DAT_006826de)[local_2b8 * 0x5b20 + local_2ac * 0x120] = 0xff;
            *(undefined2 *)(&DAT_006826d0 + local_2b8 * 0x5b20 + local_2ac * 0x120) = 0;
          }
          if (DAT_00665ed0 <= *(int *)(&DAT_006826c4 + local_2ac * 0x120 + arg_1 * 0x5b20)) {
            asStack_298[local_2bc] =
                 (short)*(undefined4 *)(&DAT_006826c4 + local_2ac * 0x120 + arg_1 * 0x5b20);
            local_2bc = local_2bc + 1;
          }
          if (DAT_00665ed0 <= *(int *)(&DAT_006826c4 + local_2b8 * 0x5b20 + local_2ac * 0x120)) {
            asStack_298[local_2bc] =
                 (short)*(undefined4 *)(&DAT_006826c4 + local_2b8 * 0x5b20 + local_2ac * 0x120);
            local_2bc = local_2bc + 1;
          }
        }
        for (local_2ac = DAT_00665ed0; local_2ac < DAT_00665ed0 + 0x10; local_2ac = local_2ac + 1) {
          if (*(int *)(&DAT_004ff590 + local_2ac * 0x34) != -1) {
            local_2b0 = local_2bc + -1;
            local_2cc = 0;
            while ((-1 < local_2b0 && (local_2cc == 0))) {
              if (asStack_298[local_2b0] == local_2ac) {
                local_2cc = 1;
              }
              local_2b0 = local_2b0 + -1;
            }
            local_2b0 = 0;
            while( true ) {
              iVar1 = (&DAT_00666408)[DAT_00676504];
              if ((&DAT_00666408)[DAT_00676504] <= (&DAT_00666408)[DAT_00676510]) {
                iVar1 = (&DAT_00666408)[DAT_00676510];
              }
              if (iVar1 <= local_2b0) break;
              if (((*(int *)(&DAT_006826c4 + local_2b0 * 0x120 + DAT_00676510 * 0x5b20) != -1) &&
                  (((&DAT_006826cc)[local_2b0 * 0x120 + DAT_00676510 * 0x5b20] & 2) != 0)) &&
                 (*(int *)(&DAT_006826c8 + local_2b0 * 0x120 + DAT_00676510 * 0x5b20) == local_2ac))
              {
                local_2cc = 1;
              }
              if (((*(int *)(&DAT_006826c4 + local_2b0 * 0x120 + DAT_00676504 * 0x5b20) != -1) &&
                  (((&DAT_006826cc)[local_2b0 * 0x120 + DAT_00676504 * 0x5b20] & 2) != 0)) &&
                 (*(int *)(&DAT_006826c8 + local_2b0 * 0x120 + DAT_00676504 * 0x5b20) == local_2ac))
              {
                local_2cc = 1;
              }
              local_2b0 = local_2b0 + 1;
            }
            if (local_2cc == 0) {
              *(undefined4 *)(&DAT_004ff590 + local_2ac * 0x34) = 0xffffffff;
            }
          }
        }
        if (DAT_0066aaf4 != 1) goto LAB_0042a950;
        local_2a0 = 1 - arg_1;
        for (local_2ac = 0; local_2ac < 8; local_2ac = local_2ac + 1) {
          auStack_14c[local_2ac + local_2a0 * 8] =
               *(undefined4 *)(&DAT_0068ed10 + local_2ac * 4 + local_2a0 * 0x20);
          *(undefined4 *)(&DAT_0068ed10 + local_2ac * 4 + local_2a0 * 0x20) =
               *(undefined4 *)(&DAT_0068ef50 + local_2ac * 4 + local_2a0 * 0x20);
        }
        Magic_ScanCards(199);
        for (local_2ac = 0; local_2ac < (&DAT_00666408)[DAT_00676504]; local_2ac = local_2ac + 1) {
          if (*(int *)(&DAT_006826c4 + DAT_00676504 * 0x5b20 + local_2ac * 0x120) != -1) {
            (**(code **)(&DAT_004ff5a0 +
                        *(int *)(&DAT_006826c4 + DAT_00676504 * 0x5b20 + local_2ac * 0x120) * 0x34))
                      (DAT_00676504,local_2ac,0x38);
          }
        }
        Pic_Subsystem_004475a4(arg_1);
        Pic_Subsystem_004488a0();
        for (local_2a0 = 0; local_2a0 < 2; local_2a0 = local_2a0 + 1) {
          for (local_2ac = 0; local_2ac < 8; local_2ac = local_2ac + 1) {
            *(undefined4 *)(&DAT_0068ed10 + local_2ac * 4 + local_2a0 * 0x20) =
                 auStack_14c[local_2ac + local_2a0 * 8];
          }
        }
        FUN_0048b64f();
        local_8 = FUN_00430911(DAT_00676504);
        local_8 = DAT_0068f2d4 + local_8;
        if (0 < DAT_00681eac) {
          DAT_006663f8 = DAT_006663f8 | 4;
        }
        if (DAT_005ef574 != 0) {
          Ai_ChooseBlockers(0,local_8);
        }
        if ((DAT_00667990 < local_8) && (DAT_00690c44 == 0)) {
          DAT_00667990 = local_8;
          FUN_0043081e();
          local_10c = DAT_006663f8;
          local_2c4 = DAT_0068dd00;
        }
        if (DAT_0066aae0 == 999) {
          DAT_0066aae0 = -1;
        }
        DAT_0066aadc = 0;
        local_154 = 0;
        DAT_00690c44 = 0;
        iVar1 = FUN_0045219a();
        if (((DAT_0068ef94 / 2 < iVar1) &&
            (((DAT_005f2f50 * 5 + 5) * 5 <= DAT_0068dd00 ||
             (uVar2 = DAT_006663f8 & 4, iVar1 = FUN_0045219a(),
             (int)((-(uint)(uVar2 == 0) & 0x96) + 0x32) < iVar1)))) &&
           ((DAT_005ef574 == 0 || (0x32 < DAT_0068dd00)))) {
          _sprintf(local_7c8,s_phase___3d_num_tries___4d_mtime___004f3a54,DAT_006c1214,DAT_0068dd00,
                   DAT_0068ef94 / 2,DAT_006663e0);
          OutputDebugStringA(local_7c8);
          if (DAT_005ef574 != 0) {
            Ai_ChooseBlockers(1,DAT_00667990);
          }
          DAT_005ef980 = 0xffffffff;
          DAT_0066aaf4 = 0;
          DAT_0066aae0 = -1;
          DAT_006663f8 = local_10c;
        }
        DAT_0068dd00 = DAT_0068dd00 + 1;
        _DAT_00666728 = 0;
        if (DAT_00666400 == 1) {
          if ((DAT_00681eb0 & 0x100) == 0) {
            DAT_0068f2c4 = 0x14;
          }
          else {
            DAT_0068f2c4 = 0x1e;
          }
          goto LAB_00427ce5;
        }
        if (DAT_00666400 == 2) {
          DAT_0068f2c4 = 0x1a;
          while( true ) {
            if (DAT_00666400 == 2) {
              FUN_004305d3();
              DAT_0068ecbc = 0;
              DAT_0068ecb8 = 0;
              DAT_0066aae4 = 0;
              DAT_0068f2d4 = 0;
            }
            DAT_0068f2c4 = 0x18;
            FUN_0048cfda(arg_1,0x18);
            DAT_00666424 = 1;
            local_29c = FUN_0048e32b(-2,DAT_0068f2c4,s_Assign_Blockers_004f39d0,0x18);
            DAT_00666424 = 0;
            if (local_29c == 0) break;
LAB_004296fd:
            if (DAT_0066aaf4 != 1) {
              FUN_00451482(0,0xff);
              FUN_0048b5c9(2,0x1e);
            }
          }
          Ai_EvalAttackCandidate_004c864d(arg_1);
          DAT_00681eb0 = DAT_00681eb0 | 8;
LAB_004297eb:
          DAT_00666440 = 1;
          if (DAT_00666400 == 5) {
            FUN_004305d3();
            DAT_0068ecbc = 0;
            DAT_0068ecb8 = 0;
            DAT_0066aae4 = 0;
            DAT_0068f2d4 = 0;
            DAT_00666440 = 3;
          }
          FUN_0048e8a8(arg_1,0xcc,s_End_of_Combat_004f39e0,0);
          FUN_00478d48(arg_1);
          FUN_0048b64f();
          FUN_00451482(0,0xff);
          FUN_0042ae2a();
          iVar1 = FUN_0042afdb();
          if (iVar1 != 0) {
            return;
          }
          goto LAB_00429888;
        }
        if (DAT_00666400 == 3) goto LAB_00429ad4;
        if (DAT_00666400 != 4) {
          if (DAT_00666400 == 5) {
            DAT_0068f2c4 = 0x1a;
            goto LAB_004297eb;
          }
          if (DAT_00666400 != 6) goto LAB_0042a8f2;
          DAT_0068f2c4 = 0x1a;
          while( true ) {
            if (DAT_00666400 == 6) {
              FUN_004305d3();
              DAT_0068ecbc = 0;
              DAT_0068ecb8 = 0;
              DAT_0066aae4 = 0;
              DAT_0068f2d4 = 0;
            }
            DAT_0068f2c4 = 0x15;
            FUN_0048cfda(arg_1,0x15);
            DAT_0068f2c4 = 0x16;
            FUN_0048cfda(arg_1,0x16);
            FUN_00451482(0,0xff);
            DAT_00666424 = 1;
            local_29c = FUN_0048e32b(-2,DAT_0068f2c4,s_Assign_Attackers_004f39a8,0x16);
            DAT_00666424 = 0;
            if (local_29c == 0) break;
LAB_00429548:
            if (DAT_0066aaf4 != 1) {
              FUN_00451482(0,0xff);
              FUN_0048b5c9(6,0x1e);
            }
          }
          DAT_0068f2c4 = 0x17;
          FUN_0048cfda(arg_1,0x17);
          FUN_0048e8a8(arg_1,0xda,s_Choose_Defenders_004f39bc,0);
          FUN_00472fc0(arg_1);
          FUN_00476868(arg_1);
          FUN_0048cfda(arg_1,DAT_0068f2c4);
          goto LAB_00429692;
        }
        if ((DAT_00681eb0 & 8) == 0) {
          DAT_0068f2c4 = 0x14;
        }
        else {
          DAT_0068f2c4 = 0x1e;
        }
        local_154 = 0;
LAB_00428569:
        if (DAT_00666400 == 4) {
          FUN_004305d3();
          DAT_0068ecbc = 0;
          DAT_0068ecb8 = 0;
          DAT_0066aae4 = 0;
          DAT_0068f2d4 = 0;
        }
        iVar1 = FUN_00488662(arg_1,local_2dc,1);
        if (iVar1 != 0) {
          local_158 = *(int *)(&DAT_006826c4 + local_2dc * 0x120 + arg_1 * 0x5b20);
          iVar1 = Ai_ChooseBlockers(arg_1,local_2dc);
          if (iVar1 != 0) {
            local_2a8 = 6;
            if (((&DAT_004ff594)[local_158 * 0x34] & 1) != 0) {
              if (arg_1 == DAT_00676510) {
                DAT_0068ef94 = 0;
              }
              DAT_00681eb0 = DAT_00681eb0 | 1;
            }
            if (((&DAT_004ff594)[local_158 * 0x34] & 2) != 0) {
              *(uint *)(&DAT_006826cc + local_2dc * 0x120 + arg_1 * 0x5b20) =
                   *(uint *)(&DAT_006826cc + local_2dc * 0x120 + arg_1 * 0x5b20) | 0x400;
            }
            if (DAT_0066aaf4 != 1) {
              if (arg_1 == DAT_00676510) {
                if ((short)(*(ushort *)(&DAT_004ff59a + local_158 * 0x34) & 0xbfff) < 4) {
                  iVar1 = FUN_00439892(3);
                  if ((iVar1 == 0) && (iVar1 = Pic_Subsystem_00452551(local_158), 2 < iVar1)) {
                    Mem_AllocOrFree_004d9630
                              ((uint *)&DAT_006679a0,(uint *)s__Where_d_you_get_that_card___004f3854
                              );
                  }
                  iVar1 = FUN_00439892(3);
                  if (((iVar1 == 0) && (((&DAT_004ff594)[local_158 * 0x34] & 0x30) != 0)) &&
                     (0 < DAT_00681eac)) {
                    Mem_AllocOrFree_004d9630
                              ((uint *)&DAT_006679a0,(uint *)s__I_knew_that_was_coming___004f3874);
                  }
                }
                else {
                  Mem_AllocOrFree_004d9630
                            ((uint *)&DAT_006679a0,(uint *)s__Oooh__I_m_scared___004f3840);
                }
              }
              else if ((short)(*(ushort *)(&DAT_004ff59a + local_158 * 0x34) & 0xbfff) < 4) {
                iVar1 = FUN_00439892(3);
                if ((iVar1 == 0) &&
                   ((((&DAT_004ff594)[local_158 * 0x34] & 0x30) != 0 ||
                    (iVar1 = Pic_Subsystem_00452551(local_158), 2 < iVar1)))) {
                  Mem_AllocOrFree_004d9630
                            ((uint *)&DAT_006679a0,(uint *)s__Didn_t_expect_that__did_ya___004f38ac)
                  ;
                }
                iVar1 = Mem_AllocOrFree_004d9810((int)(char)(&DAT_004ff598)[local_158 * 0x34]);
                if (3 < iVar1 + (char)(&DAT_004ff597)[local_158 * 0x34]) {
                  Mem_AllocOrFree_004d9630
                            ((uint *)&DAT_006679a0,(uint *)s__Deal_with_this__rat_boy___004f38cc);
                }
                if (((char)(&DAT_006826d2)[local_2dc * 0x120 + arg_1 * 0x5b20] == DAT_00676510) &&
                   (*(int *)(&DAT_006826e8 + local_2dc * 0x120 + arg_1 * 0x5b20) != -1)) {
                  Mem_AllocOrFree_004d9630((uint *)&DAT_006679a0,(uint *)s__Gotcha___004f38e8);
                }
                if (((&DAT_004ff598)[local_158 * 0x34] == -1) && (2 < DAT_00681ea0)) {
                  Mem_AllocOrFree_004d9630
                            ((uint *)&DAT_006679a0,(uint *)s__I_just_love_doing_that___004f38f4);
                }
              }
              else {
                Mem_AllocOrFree_004d9630
                          ((uint *)&DAT_006679a0,(uint *)s__Take_that__troll_face___004f3890);
              }
            }
          }
        }
        if (((arg_1 != DAT_00676510) && (DAT_0066aaf4 != 1)) && (DAT_0067650c == 0))
        goto LAB_00427ca0;
        if ((DAT_0066aaf4 == 1) && (DAT_00666400 == 4)) {
          local_154 = 1;
        }
      }
    }
    _DAT_0068f0c8 = 0;
  } while( true );
LAB_0042a8f2:
  if (DAT_00666400 != 7) {
    if (DAT_00666400 != 8) {
LAB_0042a950:
      local_150 = 0;
      FUN_0042abcf(0x20);
      FUN_0042ae2a();
      iVar1 = FUN_0042afdb();
      if (iVar1 != 0) {
        return;
      }
      FUN_0042a99c();
      FUN_0048d00c(5);
      return;
    }
    DAT_0068f2c4 = 0x1a;
    goto LAB_00429373;
  }
  if ((DAT_00681eb0 & 8) == 0) {
    DAT_0068f2c4 = 0x14;
  }
  else {
    DAT_0068f2c4 = 0x1e;
  }
  local_154 = 0;
LAB_00428b10:
  local_158 = *(int *)(&DAT_006826c4 + local_2dc * 0x120 + arg_1 * 0x5b20);
  if (DAT_00666400 == 7) {
    FUN_004305d3();
    DAT_0068ecbc = 0;
    DAT_0068ecb8 = 0;
    DAT_0066aae4 = 0;
    DAT_0068f2d4 = 0;
  }
  if (DAT_00681ea4 != 1) {
    FUN_0048a07d(arg_1,local_2dc);
  }
  if ((DAT_0066aaf4 == 1) && (DAT_00666400 == 7)) {
    local_154 = 1;
  }
LAB_00428bb6:
  if (DAT_00681ea4 == 1) {
    if (arg_1 != DAT_00676510) {
      DAT_00690c44 = 1;
      local_154 = 1;
    }
    DAT_00681ea4 = 0;
  }
  else {
    DAT_00681ea4 = 0;
    if (((arg_1 != DAT_00676510) && (DAT_0066aaf4 != 1)) && (DAT_0067650c == 0)) goto LAB_00427ca0;
    if (DAT_0066aaf4 != 1) {
      FUN_00450eb8(arg_1,local_2dc,3,2);
    }
LAB_00428c4f:
    DAT_00681ea0 = 0;
  }
  goto LAB_00428f8a;
}


