/*
 * Decompiled function: Dungeon_Process_0040fcfd
 * Entry Point: 0040fcfd
 * Size: 3913 bytes
 */
#include "magic.h"


undefined4 Dungeon_Process_0040fcfd(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  uint uVar6;
  int local_854;
  int local_850 [10];
  int local_828;
  int *local_824;
  int local_820;
  int local_81c;
  int local_818 [10];
  int local_7f0;
  int *local_7ec;
  int local_7e8;
  int local_7e4;
  int local_7e0;
  int local_7dc;
  int local_7d8;
  uint local_7d4 [500];
  
  local_7e8 = 0;
  FUN_0040a95d(s_wiseman3_pic_0051933c);
  if ((arg_2 == 0) && (local_7e8 = 1, DAT_00538608 != 0)) {
    if (DAT_00538608 == 1) goto LAB_0040ff03;
    if (DAT_00538608 == 2) goto LAB_004102e4;
  }
  while( true ) {
    iVar1 = FUN_0040a1d2(5);
    if (((iVar1 == 0) || (local_7e8 != 0)) || (arg_2 == 0)) {
      if ((DAT_005175c0 == -1) || (arg_2 != 0)) {
        iVar1 = rand();
        DAT_005175c0 = iVar1 % 0xc;
      }
      local_7ec = (int *)(&PTR_s_Shandalar_was_not_always_as_it_i_00517560)[DAT_005175c0];
      iVar1 = FUN_0040f681(local_7ec,local_818);
      local_820 = iVar1 + -1;
      for (local_81c = 0; local_81c < local_820; local_81c = local_81c + 1) {
        local_7ec = (int *)local_818[local_81c];
        *(undefined1 *)(local_818[local_81c + 1] + -3) = 0;
        local_7f0 = FUN_0040f636((char *)local_7ec);
        *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 1;
        iVar1 = Ai_Util_004c3bc4(0x13c);
        iVar2 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
        iVar1 = iVar1 - iVar2 * local_7f0;
        iVar2 = Ai_Util_004c3bc4(0x50);
        FUN_0040d1cd((int)g_DisplaySurfaceScreen,0xc1,iVar2,iVar1);
        FUN_0040a3e1();
        Ai_Subsystem_004cd1d1();
        *(undefined1 *)(local_818[local_81c + 1] + -3) = 10;
        FUN_0040a883(s_wiseman3_pic_0051934c);
      }
      DAT_00538608 = 0;
      return 1;
    }
LAB_0040ff03:
    iVar1 = FUN_0040a1d2(5);
    if ((iVar1 == 0) || (local_7e8 != 0)) break;
    DAT_00538608 = 2;
LAB_004102e4:
    iVar1 = FUN_0040a1d2(5);
    if ((iVar1 < 2) || (local_7e8 != 0)) {
      if (DAT_00522450 != 0xffffffff) {
        if (((DAT_0067f2c0 == 0) || (DAT_0067f2c0 == 2)) ||
           ((DAT_0067f2c0 == 1 &&
            (iVar1 = FUN_0050b0fc((byte)DAT_0067b9a0,(byte)(1 << ((byte)DAT_00522450 & 3))),
            iVar1 != 0)))) {
          strcpy(&g_OverworldWorldState,s_If_you_seek_the_00519398);
          if (DAT_0067f2c0 == 0) {
            strcat(&g_OverworldWorldState,s_mana_link__travel_005193c0);
          }
          else {
            pcVar4 = (char *)Mem_AllocOrFree_00473d7e(DAT_0067b9a0);
            strcat(&g_OverworldWorldState,pcVar4);
            strcat(&g_OverworldWorldState,s_amulet__travel_005193ac);
          }
          DAT_0067f3bc = FUN_0050aef6(*(int *)(&DAT_0067bdf4 + DAT_00522450 * 100),
                                      *(int *)(&DAT_0067bdf8 + DAT_00522450 * 100));
          strcat(&g_OverworldWorldState,&DAT_005193d4);
          Ai_TownEncounter_004c3b19(DAT_00522450);
          strcat(&g_OverworldWorldState,&DAT_005193dc);
          *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 1;
          iVar1 = Ai_Util_004c3bc4(0x13c);
          iVar2 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
          iVar1 = iVar1 + iVar2 * -2;
          iVar2 = Ai_Util_004c3bc4(0x50);
          FUN_0040d1cd((int)g_DisplaySurfaceScreen,0xc1,iVar2,iVar1);
          FUN_0040a3e1();
          Ai_Subsystem_004cd1d1();
          return 0;
        }
        if (DAT_0067f2c0 == 1) {
          strcpy(&g_OverworldWorldState,s_I_see_that_the_people_of_005193e0);
          Ai_TownEncounter_004c3b19(DAT_00522450);
          strcat(&g_OverworldWorldState,s_have_asked_for_a_005193fc);
          FUN_0050b1a0();
          strcat(&g_OverworldWorldState,&DAT_00519410);
          *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 1;
          iVar1 = Ai_Util_004c3bc4(0x13c);
          iVar2 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
          iVar1 = iVar1 + iVar2 * -3;
          iVar2 = Ai_Util_004c3bc4(0x50);
          FUN_0040d1cd((int)g_DisplaySurfaceScreen,0xc1,iVar2,iVar1);
          FUN_0040a3e1();
          Ai_Subsystem_004cd1d1();
          return 0;
        }
        if (DAT_0067f2c0 < 0) {
          if (DAT_0067f2c0 < -99) {
            strcpy(&g_OverworldWorldState,s_You_should_travel_00519414);
            DAT_0067f3bc = FUN_0050aef6(*(int *)(&DAT_0067bdf4 + DAT_00522450 * 100),
                                        *(int *)(&DAT_0067bdf8 + DAT_00522450 * 100));
            strcat(&g_OverworldWorldState,&DAT_00519428);
            Ai_TownEncounter_004c3b19(DAT_00522450);
            strcat(&g_OverworldWorldState,s_to_claim_your_reward__00519430);
          }
          else {
            strcpy(&g_OverworldWorldState,s_I_see_that_the_people_of_00519448);
            Ai_TownEncounter_004c3b19(DAT_00522450);
            strcat(&g_OverworldWorldState,s_have_asked_you_to_defeat_00519464);
            Adventure_FormatNewsString(-DAT_0067f2c0,1,0);
            strcat(&g_OverworldWorldState,&DAT_00519480);
          }
          *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 1;
          iVar1 = Ai_Util_004c3bc4(0x13c);
          iVar2 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
          iVar1 = iVar1 + iVar2 * -3;
          iVar2 = Ai_Util_004c3bc4(0x50);
          FUN_0040d1cd((int)g_DisplaySurfaceScreen,0xc1,iVar2,iVar1);
          FUN_0040a3e1();
          Ai_Subsystem_004cd1d1();
          return 0;
        }
      }
      arg_2 = 0;
    }
    DAT_00538608 = 0;
    strcpy(&g_OverworldWorldState,s_The_wise_man_says___The_people_a_00519484);
    strcat(&g_OverworldWorldState,s_the_tyranny_of_the_Five_Wizards__005194d8);
    strcat(&g_OverworldWorldState,s_To_assist_you_I_shall_005194fc);
    uVar6 = (int)*(uint *)(&DAT_0067bdf4 + arg_3 * 100) >> 0x1f;
    switch((*(int *)(&DAT_0067bdf8 + arg_3 * 100) % 3 - uVar6) +
           ((*(uint *)(&DAT_0067bdf4 + arg_3 * 100) ^ uVar6) - uVar6 & 1 ^ uVar6)) {
    case 0:
      strcat(&g_OverworldWorldState,s_tell_you_a_tale_of_long_long_ago_00519514);
      *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 1;
      iVar1 = Ai_Util_004c3bc4(0x13c);
      iVar2 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
      iVar1 = iVar1 + iVar2 * -7;
      iVar2 = Ai_Util_004c3bc4(0x50);
      FUN_0040d1cd((int)g_DisplaySurfaceScreen,0xc1,iVar2,iVar1);
      FUN_0040a3e1();
      Ai_Subsystem_004cd1d1();
      local_7e8 = 1;
      FUN_0040a883(s_wiseman3_pic_00519538);
      break;
    case 1:
      local_7d8 = FUN_0050b00c();
      if (local_7d8 != -1) {
        strcat(&g_OverworldWorldState,s_tell_you_of_the_dungeons_which_h_00519548);
        *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 1;
        iVar1 = Ai_Util_004c3bc4(0x13c);
        iVar2 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
        iVar1 = iVar1 + iVar2 * -7;
        iVar2 = Ai_Util_004c3bc4(0x50);
        FUN_0040d1cd((int)g_DisplaySurfaceScreen,0xc1,iVar2,iVar1);
        FUN_0040a3e1();
        Ai_Subsystem_004cd1d1();
        FUN_0048ea81(local_7d8);
        uVar5 = Ai_Subsystem_004c05ba();
        return uVar5;
      }
    case 2:
      if (DAT_00522454 == -1) {
        strcat(&g_OverworldWorldState,s_strengthen_you_with_two_extra_li_00519580);
        DAT_00522454 = 2;
      }
      else {
        strcat(&g_OverworldWorldState,s_fortify_you_with_extra_food_for_y_005195bc);
        DAT_00522448 = DAT_00522448 + 0x19;
      }
      *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 1;
      iVar1 = Ai_Util_004c3bc4(0x13c);
      iVar2 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
      iVar1 = iVar1 + iVar2 * -7;
      iVar2 = Ai_Util_004c3bc4(0x50);
      FUN_0040d1cd((int)g_DisplaySurfaceScreen,0xc1,iVar2,iVar1);
      FUN_0040a3e1();
      uVar5 = Ai_Subsystem_004cd1d1();
      return uVar5;
    case 4:
      if (DAT_00522454 == -1) {
        iVar1 = FUN_0040a1d2(2);
        DAT_00522454 = Pic_Subsystem_0045268f
                                 (*(int *)(&DAT_00517598 + (iVar1 + -2 + arg_1 * 2) * 4));
        strcat(&g_OverworldWorldState,s_provide_you_a_00519624);
        strcat(&g_OverworldWorldState,s_Swamp_0051aea9 + DAT_00522454 * 0x34);
        strcat(&g_OverworldWorldState,s_companion_in_your_next_duel___00519634);
        *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 1;
        iVar1 = Ai_Util_004c3bc4(0x13c);
        iVar2 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
        iVar1 = iVar1 + iVar2 * -7;
        iVar2 = Ai_Util_004c3bc4(0x50);
        FUN_0040d1cd((int)g_DisplaySurfaceScreen,0xc1,iVar2,iVar1);
        FUN_0040a3e1();
        uVar5 = Ai_Subsystem_004cd1d1();
        return uVar5;
      }
    case 3:
      strcat(&g_OverworldWorldState,s_reveal_to_you_the_secret_deck_of_005195ec);
      pcVar4 = (char *)Mem_AllocOrFree_00473d7e(arg_1);
      strcat(&g_OverworldWorldState,pcVar4);
      strcat(&g_OverworldWorldState,s_creature____00519614);
      *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 1;
      iVar1 = Ai_Util_004c3bc4(0x13c);
      iVar2 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
      iVar1 = iVar1 + iVar2 * -7;
      iVar2 = Ai_Util_004c3bc4(0x50);
      FUN_0040d1cd((int)g_DisplaySurfaceScreen,0xc1,iVar2,iVar1);
      FUN_0040a3e1();
      Ai_Subsystem_004cd1d1();
      FUN_0040f514((byte)arg_1);
      uVar5 = Ai_Subsystem_004c05ba();
      return uVar5;
    default:
      strcat(&g_OverworldWorldState,s_fashion_3_00519654);
      Mem_AllocOrFree_00473d7e(arg_1);
      strcat(&g_OverworldWorldState,s_amulets_into_a_duplicate_of_any_s_00519660);
      *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 1;
      iVar1 = Ai_Util_004c3bc4(0x13c);
      iVar2 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
      iVar1 = iVar1 + iVar2 * -7;
      iVar2 = Ai_Util_004c3bc4(0x50);
      FUN_0040d1cd((int)g_DisplaySurfaceScreen,0xc1,iVar2,iVar1);
      FUN_0040a3e1();
      Ai_Subsystem_004cd1d1();
      *(int *)(&DAT_0067bdbc + arg_1 * 4) = *(int *)(&DAT_0067bdbc + arg_1 * 4) + -3;
      for (local_7dc = 0; local_7dc < 500; local_7dc = local_7dc + 1) {
        local_7d4[local_7dc] = *(uint *)(&deck + local_7dc * 4);
        if (local_7d4[local_7dc] != 0xffffffff) {
          local_7d4[local_7dc] = local_7d4[local_7dc] & 0xfff;
        }
      }
      local_7e4 = Pic_Load_004509e8(g_CurrentTurnPhase,(int)local_7d4,500,s_Pick_a_spell_0051969c,1)
      ;
      if ((local_7e4 != -1) &&
         (local_7e0 = Pic_Subsystem_00451e40(local_7d4[local_7e4]), local_7e0 != -1)) {
        *(uint *)(&deck + local_7e0 * 4) = *(uint *)(&deck + local_7e0 * 4) | 0x4000;
      }
      uVar5 = Ai_Subsystem_004c05ba();
      return uVar5;
    }
  }
  if ((DAT_005175c4 == -1) || (arg_2 != 0)) {
    iVar1 = rand();
    DAT_005175c4 = iVar1 % 3;
    DAT_00538500 = FUN_0040f6e9();
    DAT_00538720 = FUN_0040fbe2();
    FUN_0040fa39(&DAT_00538508,&DAT_00538620,1);
  }
  local_824 = (int *)(&PTR_s_I_see_you_have_not_yet_defeated_t_00517550)[DAT_005175c4];
  iVar1 = FUN_0040f681(local_824,local_850);
  *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 1;
  local_854 = 0;
  do {
    if (iVar1 + -1 <= local_854) {
      DAT_00538608 = 1;
      return 1;
    }
    local_824 = (int *)local_850[local_854];
    *(undefined1 *)(local_850[local_854 + 1] + -3) = 0;
    local_828 = FUN_0040f636((char *)local_824);
    if (iVar1 + -2 == local_854) {
      if (DAT_005175c4 == 0) {
        FUN_0040f9b7((byte)DAT_00538500);
        FUN_0040f78d(DAT_00538500);
        Mem_AllocOrFree_00473d7e(DAT_00538500);
        iVar2 = Ai_Util_004c3bc4(0x13c);
        iVar3 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
        iVar2 = iVar2 - iVar3 * local_828;
        iVar3 = Ai_Util_004c3bc4(0x50);
        FUN_0040d1cd((int)g_DisplaySurfaceScreen,0xc1,iVar3,iVar2);
      }
      else if (DAT_005175c4 == 1) {
LAB_00410182:
        iVar2 = Ai_Util_004c3bc4(0x13c);
        iVar3 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
        iVar2 = iVar2 - iVar3 * local_828;
        iVar3 = Ai_Util_004c3bc4(0x50);
        FUN_0040d1cd((int)g_DisplaySurfaceScreen,0xc1,iVar3,iVar2);
      }
      else if (DAT_005175c4 == 2) {
        if (DAT_00538720 == -1) goto LAB_00410182;
        FUN_0040fc9a(DAT_00538720,&DAT_00538508,&DAT_00538620);
        iVar2 = Ai_Util_004c3bc4(0x13c);
        iVar3 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
        iVar2 = iVar2 - iVar3 * local_828;
        iVar3 = Ai_Util_004c3bc4(0x50);
        FUN_0040d1cd((int)g_DisplaySurfaceScreen,0xc1,iVar3,iVar2);
      }
    }
    else {
      iVar2 = Ai_Util_004c3bc4(0x13c);
      iVar3 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
      iVar2 = iVar2 - iVar3 * local_828;
      iVar3 = Ai_Util_004c3bc4(0x50);
      FUN_0040d1cd((int)g_DisplaySurfaceScreen,0xc1,iVar3,iVar2);
    }
    FUN_0040a3e1();
    Ai_Subsystem_004cd1d1();
    *(undefined1 *)(local_850[local_854 + 1] + -3) = 10;
    FUN_0040a883(s_wiseman3_pic_00519388);
    local_854 = local_854 + 1;
  } while( true );
}


