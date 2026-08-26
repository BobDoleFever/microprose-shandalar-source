/*
 * Decompiled function: Town_Process_00507c86
 * Entry Point: 00507c86
 * Size: 4024 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Town_Process_00507c86(uint arg_1)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  int local_a4;
  int aiStack_a0 [16];
  int local_60;
  uint local_58;
  uint local_50;
  int local_4c;
  uint local_48;
  uint local_44;
  uint local_3c;
  int local_34;
  int local_30;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  uint local_14;
  undefined4 local_c;
  int local_8;
  
  FUN_0040a3e1();
  DAT_0062680c = arg_1;
  uVar2 = FUN_0040c761(*(int *)(&DAT_0067bdf4 + arg_1 * 100),*(int *)(&DAT_0067bdf8 + arg_1 * 100));
  local_50 = Adventure_GetLocationEncounterIndex(uVar2);
  local_20 = *(int *)(&DAT_0067bdf0 + DAT_0062680c * 100) + 3;
  if (DAT_005224f8 == 0) {
    local_20 = *(int *)(&DAT_0067bdf0 + DAT_0062680c * 100) + 4;
  }
  if (7 < local_20) {
    local_20 = 8;
  }
  local_14 = 0xffffffff;
  for (local_3c = 0; (int)local_3c < 199; local_3c = local_3c + 1) {
    iVar3 = FUN_0040a1d2(5);
    local_44 = iVar3 + 1;
    if (((*(int *)(&DAT_0067bdbc + local_44 * 4) != 0) || (0x50 < (int)local_3c)) &&
       ((local_50 & 1 << ((byte)local_44 & 0x1f)) != 0)) {
      local_14 = local_44;
    }
  }
  DAT_00626604 = local_14;
  DAT_006265f8 = -1;
  DAT_0061e0fc = arg_1;
  if (arg_1 == DAT_00531594) goto LAB_005085a9;
  iVar3 = FUN_0040a1d2(3);
  if (((iVar3 == 0) && (((&DAT_0067be00)[arg_1 * 100] & 1) == 0)) ||
     (*(int *)(&DAT_0067bdf0 + arg_1 * 100) != 1)) {
LAB_00507faa:
    local_44 = FUN_0040a1d2(6);
    if (*(int *)(&DAT_0067f2d0 + local_44 * 0x14) < 1) {
      DAT_0061e100 = 0xffffffff;
    }
    else {
      DAT_0061e100 = arg_1;
      DAT_0061e05c = -*(int *)(&DAT_0067f2d0 + local_44 * 0x14);
    }
    iVar3 = FUN_0040a1d2(4);
    if ((iVar3 == 0) || (DAT_0061e100 == 0xffffffff)) {
      DAT_0061e100 = arg_1;
      iVar3 = FUN_0040a1d2(8);
      iVar3 = Adventure_CheckMonsterEncounter(local_14,iVar3 * 2 + 4);
      DAT_0061e05c = -iVar3;
      FUN_0046e70d(0,8);
      _DAT_0067f2d0 = 0xffffffff;
    }
  }
  else {
    local_1c = 0;
    do {
      DAT_0061e100 = FUN_0040a1d2(0x80);
      local_18 = FUN_0040a36f(*(int *)(&DAT_0067bdf4 + arg_1 * 100) -
                              *(int *)(&DAT_0067bdf4 + DAT_0061e100 * 100),
                              *(int *)(&DAT_0067bdf8 + arg_1 * 100) -
                              *(int *)(&DAT_0067bdf8 + DAT_0061e100 * 100));
      local_1c = local_1c + 1;
      if (999 < local_1c) break;
    } while (((*(int *)(&DAT_0067bdf0 + DAT_0061e100 * 100) < 2) ||
             (*(int *)(&DAT_0067bdf0 + DAT_0061e100 * 100) == 4)) ||
            ((*(int *)(&DAT_0067bdf0 + DAT_0061e100 * 100) == 5 ||
             (((local_18 < 8 ||
               (((int)(local_1c + (local_1c >> 0x1f & 0xfU)) >> 4) + 0x10 < local_18)) ||
              ((*(uint *)(&DAT_0067be00 + DAT_0061e100 * 100) & 0xff01) != 0))))));
    iVar3 = FUN_0040a1d2(2);
    if (iVar3 == 0) {
      DAT_0061e05c = 2;
    }
    else {
      DAT_0061e05c = 0;
    }
    if (999 < local_1c) {
      if (((&DAT_0067be00)[arg_1 * 100] & 1) == 0) goto LAB_00507faa;
      DAT_0061e100 = 0xffffffff;
    }
    iVar3 = FUN_0040a1d2(5);
    local_44 = iVar3 + 1;
    iVar3 = Pic_Subsystem_004521a6(1 << ((byte)local_44 & 0x1f),1 << ((byte)local_14 & 0x1f),3);
    if ((iVar3 == 0) && (iVar3 = FUN_0040a1d2(2), iVar3 != 0)) {
      DAT_0061e05c = 1;
      _DAT_0061e058 = local_44;
    }
  }
  if (DAT_0061e05c != 1) {
    uVar2 = FUN_0040c761(*(int *)(&DAT_0067bdf4 + DAT_0061e100 * 100),
                         *(int *)(&DAT_0067bdf8 + DAT_0061e100 * 100));
    local_44 = Adventure_GetLocationEncounterIndex(uVar2);
    do {
      iVar3 = FUN_0040a1d2(5);
      _DAT_0061e058 = iVar3 + 1;
    } while ((local_44 & 1 << (DAT_0061e058 & 0x1f)) == 0);
  }
  if ((DAT_0061e05c == 0) && (*(int *)(&DAT_0067bdbc + _DAT_0061e058 * 4) == 0)) {
    DAT_0061e05c = 2;
  }
  if (((&DAT_0067be00)[arg_1 * 100] & 8) == 0) {
    for (local_3c = 0; (int)local_3c < 8; local_3c = local_3c + 1) {
      *(undefined4 *)(&DAT_0061e060 + local_3c * 4) = 0xffffffff;
    }
  }
  else {
    for (local_3c = 0; (int)local_3c < local_20; local_3c = local_3c + 1) {
      if (DAT_00641020 - *(int *)(&DAT_0067be24 + local_3c * 4 + arg_1 * 100) <
          DAT_0067f380 * 5 + 0xf) {
        *(undefined4 *)(&DAT_0061e060 + local_3c * 4) = 0xffffffff;
      }
      else {
        *(undefined4 *)(&DAT_0061e060 + local_3c * 4) =
             *(undefined4 *)(&DAT_0067be04 + local_3c * 4 + arg_1 * 100);
      }
    }
  }
  local_44 = FUN_0040a1d2(local_20);
  for (local_3c = 0; (int)local_3c < local_20; local_3c = local_3c + 1) {
    if ((*(int *)(&DAT_0061e060 + local_3c * 4) == -1) &&
       (DAT_0067f380 * 5 + 0xf <=
        DAT_00641020 - *(int *)(&DAT_0067be24 + local_3c * 4 + arg_1 * 100))) {
      bVar1 = FUN_0040a1d2(7);
      local_34 = 1 << (bVar1 & 0x1f);
      do {
        if (local_3c == local_44) {
          local_58 = FUN_0040a1d2(5);
          *(uint *)(&DAT_0061e060 + local_3c * 4) = local_58;
        }
        else {
          local_58 = FUN_0040a1d2(g_MasterCardCount + -0x29);
          *(uint *)(&DAT_0061e060 + local_3c * 4) = local_58;
        }
        local_4c = 0;
        for (local_48 = 1; (int)local_48 < 6; local_48 = local_48 + 1) {
          if (((local_50 & 1 << ((byte)local_48 & 0x1f)) != 0) &&
             (iVar3 = Pic_Subsystem_004521a6
                                (1 << ((byte)local_48 & 0x1f),
                                 (int)(char)(&DAT_0051aebe)[local_58 * 0x34],
                                 (-(uint)((local_48 & 1) == 0) & 2) + 1), iVar3 != 0)) {
            local_4c = 1;
          }
        }
        if (((local_3c & 1) != 0) && (((&g_MasterCardColorTable)[local_58 * 0x34] & 0x40) != 0)) {
          local_4c = 0;
        }
        if (((&DAT_0051aed1)[local_58 * 0x34] & 9) != 0) {
          local_4c = 0;
        }
        if (((&DAT_0051aed6)[local_58 * 0x34] & 0xc1) == 0) {
          local_4c = 0;
        }
        iVar3 = Pic_Subsystem_00452551(local_58);
        if ((int)local_3c % 3 + 1 < iVar3) {
          local_4c = 0;
        }
        iVar3 = Duel_UpdateCardMotionStep(local_58);
      } while (((iVar3 < 1) || (local_4c == 0)) ||
              ((*(uint *)(&DAT_0051aed0 + local_58 * 0x34) & 0x180) != 0));
    }
  }
  local_a4 = 0;
  for (local_3c = 0; (int)local_3c < local_20; local_3c = local_3c + 1) {
    local_24 = FUN_00407499(*(int *)(&DAT_0061e060 + local_3c * 4));
    if (local_24 != -1) {
      aiStack_a0[local_a4 * 2] = local_24;
      aiStack_a0[local_a4 * 2 + 1] = local_3c;
      local_a4 = local_a4 + 1;
    }
  }
  if (local_a4 != 0) {
    iVar3 = FUN_0040a1d2(local_a4);
    DAT_006265f8 = aiStack_a0[iVar3 * 2];
    DAT_00626808 = aiStack_a0[iVar3 * 2];
  }
  for (local_3c = 0; (int)local_3c < 8; local_3c = local_3c + 1) {
    local_58 = *(uint *)(&DAT_0061e060 + local_3c * 4);
    if (local_58 != 0xffffffff) {
      local_30 = FUN_0050a9bf(local_58);
      local_30 = (*(int *)(&DAT_0067bdf0 + arg_1 * 100) + 2) * local_30;
      if (((local_50 & (int)(char)(&DAT_0051aebe)[local_58 * 0x34]) == 0) &&
         ((&DAT_0051aebe)[local_58 * 0x34] != '\0')) {
        iVar3 = Pic_Subsystem_004521a6(local_50,(int)(char)(&DAT_0051aebe)[local_58 * 0x34],3);
        if (iVar3 == 0) {
          local_30 = local_30 << 1;
        }
        else {
          local_30 = (local_30 * 3) / 2;
        }
      }
      uVar2 = FUN_0040a305((local_30 / 0x32) * 5,5,1000);
      *(undefined4 *)(&DAT_0061e0a0 + local_3c * 4) = uVar2;
    }
  }
  *(uint *)(&DAT_0067be00 + arg_1 * 100) = *(uint *)(&DAT_0067be00 + arg_1 * 100) | 8;
LAB_005085a9:
  DAT_006265f4 = *(int *)(&DAT_0067bdf0 + arg_1 * 100) * 5 + 10;
  local_8 = DAT_006265f4;
  Pic_Subsystem_00423b93(0x12);
  Adventure_Audio_InitSoundTrack(s_x_sound_button_wav_00531f44,0x12,0);
  do {
    if (local_20 == 0) {
      iVar3 = FUN_00473cc5((byte)local_50);
      *(int *)(&DAT_0061e060 + local_20 * 4) = iVar3 + -1;
      *(undefined4 *)(&DAT_0061e0a0 + local_20 * 4) = 0x28;
      local_20 = local_20 + 1;
    }
    *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 4;
    g_OverworldWorldState = 0;
    Ai_TownEncounter_004c3b19(arg_1);
    FUN_0040c336(&g_OverworldWorldState,0xa0,0x1c,
                 (-(uint)(*(int *)(&DAT_0067bdf0 + arg_1 * 100) == 1) & 0x1e) + 0xe0);
    *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 1;
    for (local_3c = 0; (int)local_3c < 4; local_3c = local_3c + 1) {
      *(undefined4 *)(&DAT_005315dc + local_3c * 0x54) =
           *(undefined4 *)(&DAT_0067f730 + local_3c * 4);
      *(undefined4 *)(&DAT_005315e0 + local_3c * 0x54) =
           *(undefined4 *)(&DAT_0067f740 + local_3c * 4);
      *(undefined4 *)(&DAT_005315e4 + local_3c * 0x54) =
           *(undefined4 *)(&DAT_0067f740 + local_3c * 4);
      *(undefined4 *)(&DAT_005315e8 + local_3c * 0x54) =
           *(undefined4 *)(&DAT_0067f730 + local_3c * 4);
    }
    if (DAT_005316f8 == DAT_005316e8) {
      for (local_3c = 0; (int)local_3c < 4; local_3c = local_3c + 1) {
        uVar2 = Ai_Util_004c3bc4(*(int *)(&DAT_00531598 + local_3c * 0x54));
        *(undefined4 *)(&DAT_005315a8 + local_3c * 0x54) = uVar2;
        uVar2 = Ai_Util_004c3bc4(*(int *)(&DAT_0053159c + local_3c * 0x54));
        *(undefined4 *)(&DAT_005315ac + local_3c * 0x54) = uVar2;
        uVar2 = Ai_Util_004c3bc4(*(int *)(&DAT_005315a0 + local_3c * 0x54));
        *(undefined4 *)(&DAT_005315b0 + local_3c * 0x54) = uVar2;
        uVar2 = Ai_Util_004c3bc4(*(int *)(&DAT_005315a4 + local_3c * 0x54));
        *(undefined4 *)(&DAT_005315b4 + local_3c * 0x54) = uVar2;
      }
      for (local_3c = 0; (int)local_3c < 5; local_3c = local_3c + 1) {
        iVar3 = Ai_Util_004c3bc4((&DAT_005316e8)[local_3c * 0x15]);
        (&DAT_005316f8)[local_3c * 0x15] = iVar3;
        uVar2 = Ai_Util_004c3bc4(*(int *)(&DAT_005316ec + local_3c * 0x54));
        *(undefined4 *)(&DAT_005316fc + local_3c * 0x54) = uVar2;
        uVar2 = Ai_Util_004c3bc4(*(int *)(&DAT_005316f0 + local_3c * 0x54));
        *(undefined4 *)(&DAT_00531700 + local_3c * 0x54) = uVar2;
        uVar2 = Ai_Util_004c3bc4(*(int *)(&DAT_005316f4 + local_3c * 0x54));
        *(undefined4 *)(&DAT_00531704 + local_3c * 0x54) = uVar2;
      }
    }
    local_60 = FUN_0041f354();
    Mem_AllocOrFree_0041f12b(local_60);
    FUN_0041f17e(0x531598,4,local_60);
    FUN_0041f17e(0x5316e8,5,local_60);
    strcpy(&DAT_00626610,s_Edit_deck_Sell_cards_00531f58);
    sprintf(&DAT_00626674,s_Buy_10_food_for__d_gold_00531f70,DAT_006265f4);
    strcpy(&DAT_006266d8,s_Leave_the_village_00531f88);
    sprintf(&DAT_0062673c,s_Buy_Cards_s_00531fac,
            s__Card_Hints_00531f9c + ((DAT_006265f8 != -1) - 1 & 0xc));
    DAT_006267a0 = '\0';
    local_c = 0;
    PTR_Town_Process_00508cd7_00531860 = Town_Process_00508cd7;
    if (*(int *)(&DAT_0067bdf0 + arg_1 * 100) == 1) {
      if (((DAT_00522450 == -1) && (DAT_0061e100 != 0xffffffff)) &&
         ((DAT_0067f380 + 3) * 0x10 < DAT_00641020 - *(int *)(&DAT_0067be44 + arg_1 * 100))) {
        sprintf(&DAT_006267a0,s_Begin_a_Quest_00531ff8);
      }
      else {
        sprintf(&DAT_006267a0,s_Speak_to_Wise_Man_00532008);
      }
    }
    else if ((((local_14 == 0xffffffff) || (*(int *)(&DAT_0067bdbc + local_14 * 4) == 0)) ||
             (*(int *)(&DAT_0067bdfc + arg_1 * 100) == 0)) ||
            (DAT_00641020 - *(int *)(&DAT_0067be48 + arg_1 * 100) <= (DAT_0067f380 * 2 + 6) * 9)) {
      if (((DAT_00522450 == -1) && (DAT_0061e100 != 0xffffffff)) &&
         ((DAT_0067f380 + 3) * 0x10 < DAT_00641020 - *(int *)(&DAT_0067be44 + arg_1 * 100))) {
        sprintf(&DAT_006267a0,s_Begin_a_Quest_00531fd4);
        local_c = 1;
      }
      else {
        sprintf(&DAT_006267a0,s_Speak_to_Wise_Man_00531fe4);
      }
    }
    else {
      g_OverworldWorldState = 0;
      uVar2 = FUN_0050a73e(arg_1);
      uVar4 = Mem_AllocOrFree_00473d7e(local_14);
      sprintf(&DAT_006267a0,s_Trade__s_Amulets_for__s__00531fb8,uVar4,uVar2);
      PTR_Town_Process_00508cd7_00531860 = Town_Process_00509fd4;
    }
    if (DAT_006267a0 == '\0') {
      _DAT_00531878 = 3;
    }
    else {
      _DAT_00531878 = 1;
    }
    DAT_006265f0 = 1;
    FUN_0041f213();
    DAT_006265f0 = 0;
    DAT_006265fc = 0;
    while (DAT_006265fc == 0) {
      Pic_Subsystem_0044b84b();
      FUN_0041f3ea(DAT_0067bda4,DAT_0067bda8,DAT_007039c4);
    }
    FUN_0041f391();
  } while (DAT_006265fc == -2);
  for (local_3c = 0; (int)local_3c < 8; local_3c = local_3c + 1) {
    *(undefined4 *)(&DAT_0067be04 + local_3c * 4 + arg_1 * 100) =
         *(undefined4 *)(&DAT_0061e060 + local_3c * 4);
  }
  DAT_00531594 = arg_1;
  Pic_Subsystem_00423c82(0xf);
  Pic_Subsystem_00423b93(0xf);
  return 0;
}


