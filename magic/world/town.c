/*
 * magic/world/town.c - Shandalar RPG World - Towns, Castles, Dungeons, Merchants & Quests
 * Reconstructed Module containing 24 functions
 */
#include "magic.h"

/*
 * Decompiled function: Story_Load_0040706f
 * Entry Point: 0040706f
 * Size: 155 bytes
 */


void Story_Load_0040706f(void)

{
  int local_74;
  char local_70 [100];
  FILE *local_c;
  int local_8;
  
  local_c = fopen(s_story_txt_00516504,&DAT_00516500);
  local_74 = 6;
  do {
    local_8 = fscanf(local_c,s_______00516510,local_70);
    if (local_70[0] == '.') {
      local_74 = local_74 + 3;
    }
    else {
      FUN_0040c336(local_70,0xa0,local_74,0xff);
      local_74 = local_74 + 7;
    }
    local_8 = fscanf(local_c,&DAT_00516518,local_70);
  } while (local_8 != -1);
  return;
}

/*
 * Decompiled function: Tale_Load_0040710a
 * Entry Point: 0040710a
 * Size: 196 bytes
 */


void Tale_Load_0040710a(int arg_1)

{
  int local_74;
  char local_70 [100];
  FILE *local_c;
  int local_8;
  
  local_c = fopen(s_tale_txt_00516524,&DAT_00516520);
  local_74 = 0;
  do {
    local_8 = fscanf(local_c,s_______00516530,local_70);
    if (local_70[0] == '.') {
      local_74 = local_74 + 1;
    }
    else if (local_74 == arg_1) {
      strcat(&g_OverworldWorldState,local_70);
      strcat(&g_OverworldWorldState,&DAT_00516538);
    }
    local_8 = fscanf(local_c,&DAT_0051653c,local_70);
  } while ((local_8 != -1) && (local_74 <= arg_1));
  fclose(local_c);
  return;
}

/*
 * Decompiled function: Merchant_ProcessBuy_00407b34
 * Entry Point: 00407b34
 * Size: 776 bytes
 */


void Merchant_ProcessBuy_00407b34(int arg_1)

{
  int iVar1;
  int arg_4;
  int arg_3;
  int arg_2;
  int local_458;
  void *local_454;
  undefined4 local_450;
  undefined4 local_44c;
  undefined4 auStack_448 [6];
  undefined4 auStack_430 [4];
  uint local_420;
  undefined4 auStack_41c [6];
  undefined4 local_404;
  undefined4 auStack_400 [3];
  char local_3f4 [1000];
  void *local_c;
  undefined4 local_8;
  
  if (*(int *)(&DAT_00701944 + arg_1 * 8) == -1) {
    strcpy(&g_OverworldWorldState,s_The_card_seller_notes___If_you_b_005165fc);
    iVar1 = Pic_Subsystem_0045268f(*(int *)(&DAT_00701940 + arg_1 * 8));
    strcat(&g_OverworldWorldState,s_Swamp_0051aea9 + iVar1 * 0x34);
    strcat(&g_OverworldWorldState,s___you_can_00516628);
  }
  else {
    iVar1 = FUN_00407747(*(int *)(&DAT_00701940 + arg_1 * 8));
    local_420 = (uint)(iVar1 != 0);
    strcpy(&g_OverworldWorldState,s_The_card_seller_suggests___If_yo_005165a0);
    iVar1 = Pic_Subsystem_0045268f(*(int *)(&DAT_00701940 + local_420 * 4 + arg_1 * 8));
    strcat(&g_OverworldWorldState,s_Swamp_0051aea9 + iVar1 * 0x34);
    strcat(&g_OverworldWorldState,s_with_the_005165d4);
    iVar1 = Pic_Subsystem_0045268f(*(int *)(&DAT_00701940 + (local_420 ^ 1) * 4 + arg_1 * 8));
    strcat(&g_OverworldWorldState,s_Swamp_0051aea9 + iVar1 * 0x34);
    strcat(&g_OverworldWorldState,s_you_already_have__you_can_005165e0);
  }
  Hints_GetNext_0040741b(arg_1);
  strcat(&g_OverworldWorldState,&DAT_00516634);
  Sprite_LoadAll(&local_454,s_BuyButtons_spr_00516638);
  local_c = local_454;
  local_8 = local_450;
  local_404 = local_44c;
  for (local_458 = 0; local_458 < 3; local_458 = local_458 + 1) {
    auStack_400[local_458] = auStack_448[local_458];
  }
  for (local_458 = 0; local_458 < 3; local_458 = local_458 + 1) {
    auStack_41c[local_458 + 3] = auStack_448[local_458 + 3];
  }
  for (local_458 = 0; local_458 < 3; local_458 = local_458 + 1) {
    auStack_41c[local_458] = auStack_448[local_458 + 6];
  }
  iVar1 = Ai_Util_004c3bc4(0x10f);
  arg_4 = Ai_Util_004c3bc4(0xc5);
  arg_3 = Ai_Util_004c3bc4(0x34);
  arg_2 = Ai_Util_004c3bc4(0xdc);
  Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,arg_2,arg_3,arg_4,iVar1,(int)local_454);
  iVar1 = Ai_Util_004c3bc4(0x85);
  FUN_00407843(&g_OverworldWorldState,local_3f4,iVar1);
  Font_DrawTextInRect((int)g_DisplaySurfaceScreen,0xfe,0x140,0xbc);
  Ai_Subsystem_004cd1d1();
  Mem_AllocOrFree_0050fc50(local_c);
  return;
}

/*
 * Decompiled function: Castle_Process_0040b7fa
 * Entry Point: 0040b7fa
 * Size: 1193 bytes
 */


int Castle_Process_0040b7fa(int arg_1)

{
  int iVar1;
  char *str_2;
  uint uVar2;
  uint local_18;
  uint local_14;
  
  if (arg_1 < 0) {
    arg_1 = 0;
  }
  if (DAT_005384d8 < arg_1) {
    arg_1 = DAT_005384d8;
  }
  if (arg_1 == DAT_005384d4) {
    iVar1 = 0;
  }
  else {
    g_OverworldWorldState = '\0';
    while (g_OverworldWorldState == '\0') {
      iVar1 = *(int *)(&DAT_0067a9a0 + arg_1 * 0x10);
      uVar2 = *(uint *)(&DAT_0067a9a4 + arg_1 * 0x10);
      local_14 = *(uint *)(&DAT_0067a9a8 + arg_1 * 0x10);
      local_18 = *(uint *)(&DAT_0067a9ac + arg_1 * 0x10);
      if (*(int *)(&DAT_0067a9a0 + arg_1 * 0x10) == 0) {
        return 0;
      }
      Surface_BlitToDevice((int *)g_DisplaySurfaceBackBuffer,0,0,g_DisplayScreenWidth,g_DisplayScreenHeight,
                   (int *)g_DisplaySurfaceScreen,0,0);
      g_OverworldWorldState = '\0';
      switch(iVar1) {
      case 1:
        if ((uVar2 & 0x80) == 0) {
          strcat(&g_OverworldWorldState,s_Visited_00517354);
        }
        else {
          strcat(&g_OverworldWorldState,s_Completed_quest_at_00517340);
        }
        Ai_TownEncounter_004c3b19(uVar2 & 0x7f);
        break;
      case 2:
        if ((uVar2 & 0x80) == 0) {
          strcat(&g_OverworldWorldState,s_Lost_to_0051737c);
        }
        else {
          strcat(&g_OverworldWorldState,s_Defeated_00517370);
        }
        Glue_Subsystem_004eaa19(uVar2 & 0x7f,1,0);
        break;
      case 3:
        strcat(&g_OverworldWorldState,s_Explored_00517388);
        FUN_0048e2b0(uVar2 & 0x7f);
        break;
      case 4:
        if ((uVar2 & 0x80) == 0) {
          strcat(&g_OverworldWorldState,s_Entered_005173a0);
        }
        else {
          strcat(&g_OverworldWorldState,s_Defeated_00517394);
        }
        FUN_0048e2b0(uVar2 & 0x7f);
        strcat(&g_OverworldWorldState,&DAT_005173ac);
        str_2 = (char *)Mem_AllocOrFree_00473d7e((uVar2 & 0x7f) + 1);
        strcat(&g_OverworldWorldState,str_2);
        strcat(&g_OverworldWorldState,s_Castle__005173b0);
        break;
      case 5:
        strcat(&g_OverworldWorldState,s_Discovered_a_005173bc);
        FUN_0040eb04(uVar2);
        if ((int)uVar2 < 5) {
          g_OverworldWorldState = '\0';
        }
        break;
      case 6:
        strcat(&g_OverworldWorldState,s_Bought_WM__005173cc);
        strcat(&g_OverworldWorldState,(&PTR_s_Sleight_of_hand_005225d0)[uVar2]);
        break;
      case 7:
        strcat(&g_OverworldWorldState,s_Freed_00517360);
        Ai_TownEncounter_004c3b19(uVar2);
        break;
      case 8:
      case 9:
      case 10:
      case 0xb:
      case 0xc:
        iVar1 = (iVar1 + -8) * 0x100 + uVar2;
        strcat(&g_OverworldWorldState,s_Acquired_005173d8);
        Glue_Subsystem_004eaa9c((int)s_Swamp_0051aea9[iVar1 * 0x34],0);
        strcat(&g_OverworldWorldState,s_Swamp_0051aea9 + iVar1 * 0x34);
        strcat(&g_OverworldWorldState,s_spell_005173e4);
        break;
      case 0xd:
        strcat(&g_OverworldWorldState,s_Saved_00517368);
        Glue_Subsystem_004f0a4a(local_14,local_18);
        break;
      case 0x12:
        switch(uVar2 & 0xffff) {
        case 1:
        case 2:
          strcat(&g_OverworldWorldState,s_JUMP__005173ec);
          break;
        case 3:
          strcat(&g_OverworldWorldState,s_SPEED__005173f4);
          break;
        case 4:
          strcat(&g_OverworldWorldState,s_THUNDERED_on_005173fc);
          Glue_Subsystem_004eaa19((int)uVar2 >> 0x10,1,0);
          strcat(&g_OverworldWorldState,&DAT_0051740c);
          break;
        case 5:
          strcat(&g_OverworldWorldState,s_Went_to_aid_of_00517410);
          uVar2 = Glue_Subsystem_004f0a4a(local_14,local_18);
          Ai_TownEncounter_004c3b19(uVar2);
        }
      }
      arg_1 = arg_1 + 1;
    }
    DAT_005384e0 = 0xffffffff;
    DAT_005384dc = 0xffffffff;
    if (arg_1 + -1 == DAT_005384d4) {
      iVar1 = 0;
    }
    else {
      FUN_0040bcff(local_14,local_18);
      iVar1 = arg_1 + -1;
      DAT_005384d4 = iVar1;
    }
  }
  return iVar1;
}

/*
 * Decompiled function: Dungeon_Process_0040fcfd
 * Entry Point: 0040fcfd
 * Size: 3913 bytes
 */


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
    iVar1 = Math_RandomRange(5);
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
        App_ProcessPendingMessages();
        Ai_Subsystem_004cd1d1();
        *(undefined1 *)(local_818[local_81c + 1] + -3) = 10;
        FUN_0040a883(s_wiseman3_pic_0051934c);
      }
      DAT_00538608 = 0;
      return 1;
    }
LAB_0040ff03:
    iVar1 = Math_RandomRange(5);
    if ((iVar1 == 0) || (local_7e8 != 0)) break;
    DAT_00538608 = 2;
LAB_004102e4:
    iVar1 = Math_RandomRange(5);
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
          App_ProcessPendingMessages();
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
          App_ProcessPendingMessages();
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
            Glue_Subsystem_004eaa19(-DAT_0067f2c0,1,0);
            strcat(&g_OverworldWorldState,&DAT_00519480);
          }
          *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 1;
          iVar1 = Ai_Util_004c3bc4(0x13c);
          iVar2 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
          iVar1 = iVar1 + iVar2 * -3;
          iVar2 = Ai_Util_004c3bc4(0x50);
          FUN_0040d1cd((int)g_DisplaySurfaceScreen,0xc1,iVar2,iVar1);
          App_ProcessPendingMessages();
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
      App_ProcessPendingMessages();
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
        App_ProcessPendingMessages();
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
      App_ProcessPendingMessages();
      uVar5 = Ai_Subsystem_004cd1d1();
      return uVar5;
    case 4:
      if (DAT_00522454 == -1) {
        iVar1 = Math_RandomRange(2);
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
        App_ProcessPendingMessages();
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
      App_ProcessPendingMessages();
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
      App_ProcessPendingMessages();
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
    App_ProcessPendingMessages();
    Ai_Subsystem_004cd1d1();
    *(undefined1 *)(local_850[local_854 + 1] + -3) = 10;
    FUN_0040a883(s_wiseman3_pic_00519388);
    local_854 = local_854 + 1;
  } while( true );
}

/*
 * Decompiled function: Castle_Process_00421b32
 * Entry Point: 00421b32
 * Size: 3986 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Castle_Process_00421b32(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  DWORD arg_5;
  uint arg_4;
  uint arg_2;
  undefined4 arg_2_00;
  int arg_2_01;
  int *arg_6;
  char *str_6;
  char *str_7;
  int local_374;
  uint local_368;
  undefined4 local_364 [200];
  int local_44;
  int local_40 [9];
  int *local_1c;
  int local_18;
  int local_14;
  int local_c;
  uint local_8;
  
  local_40[0] = 4;
  local_40[1] = 0;
  local_40[2] = 0;
  local_40[3] = 800;
  local_40[4] = 600;
  local_40[5] = 1;
  local_40[6] = 0xf;
  local_40[7] = 4;
  local_40[8] = 0;
  local_1c = local_40;
  local_14 = 0xb7;
  local_c = 0x1c;
  Surface_TransformPoint(0,(short)DAT_00530d9c);
  *(undefined4 *)(g_DisplaySurfaceBackBuffer + 0x20) = 4;
  *(undefined4 *)(g_DisplaySurfaceWork + 0x20) = 4;
  Surface_FillRect((int *)g_DisplaySurfaceScreen,0,0,g_DisplayScreenWidth,g_DisplayScreenHeight,0);
  LoadPalNoPic(s_advfac64_pic_0051ac9c);
  Sprite_LoadAll(local_364,s_statbutt_spr_0051acac);
  local_44 = 0;
  for (local_368 = 0; local_368 < 5; local_368 = local_368 + 1) {
    (&DAT_00538a10)[local_368] = (void *)local_364[local_44];
    local_44 = local_44 + 1;
  }
  for (local_368 = 0; local_368 < 3; local_368 = local_368 + 1) {
    *(undefined4 *)(&DAT_00538a88 + local_368 * 4) = local_364[local_44];
    local_44 = local_44 + 1;
  }
  for (local_368 = 0; local_368 < 3; local_368 = local_368 + 1) {
    *(undefined4 *)(&DAT_00538a98 + local_368 * 4) = local_364[local_44];
    local_44 = local_44 + 1;
  }
  for (local_368 = 0; iVar1 = local_44, local_368 < 3; local_368 = local_368 + 1) {
    *(undefined4 *)(&DAT_00538aa8 + local_368 * 4) = local_364[local_44];
    local_44 = local_44 + 1;
  }
  _DAT_00538ac0 = local_364[local_44];
  local_44 = local_44 + 1;
  DAT_00538ac4 = local_364[local_44];
  local_44 = iVar1 + 2;
  FUN_0040b441((int *)&DAT_0051a4e8,10);
  _DAT_0051a678 = 3;
  DAT_00538ac8 = 0;
LAB_00421d4c:
  DAT_0070a860 = DAT_0067bdd4;
  SelectObject(*(HDC *)(DAT_0067bdd4 + 4),DAT_0067bdd8);
  if (DAT_0070a880 == 8) {
    FUN_00510b70(1,0,g_DisplayScreenHeight - 0x1e0,s_statbak_pic_0051acbc,(short *)0x1);
  }
  else {
    FUN_00510b70(1,0,g_DisplayScreenHeight - 0x1e0,s_statbak_pic_0051acc8,(short *)0x1);
  }
  FUN_004219e1(g_DisplaySurfaceBackBuffer,0x26,g_DisplayScreenHeight - 0x1d1,0x8c,0xac,
               *(undefined4 *)(&DAT_0051ac18 + DAT_006410d8 * 8));
  FUN_004219e1(g_DisplaySurfaceBackBuffer,0x27,g_DisplayScreenHeight - 0x1d0,0x8a,0xaa,
               *(undefined4 *)(&DAT_0051ac1c + DAT_006410d8 * 8));
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,g_DisplayScreenHeight - 0x1e0,0x280,0x1e0,
                     (int *)g_DisplaySurfaceBackBuffer,0,0,g_DisplayScreenWidth,g_DisplayScreenHeight);
  iVar1 = Ai_Util_004c3bc4(0xa9);
  iVar2 = Ai_Util_004c3bc4(0x89);
  iVar3 = Ai_Util_004c3bc4(0x11);
  iVar4 = Ai_Util_004c3bc4(0x28);
  Surface_StretchBlt(local_1c,0,0,0x89,0xa9,(int *)g_DisplaySurfaceBackBuffer,iVar4,iVar3,iVar2,
                     iVar1);
  iVar3 = 0x154;
  iVar2 = 0;
  arg_6 = (int *)g_DisplaySurfaceWork;
  arg_5 = Ai_Util_004c3bc4(0x7f);
  arg_4 = Ai_Util_004c3bc4(0x173);
  iVar1 = Ai_Util_004c3bc4(0x43);
  arg_2 = Ai_Util_004c3bc4(0xf7);
  Surface_BlitToDevice((int *)g_DisplaySurfaceBackBuffer,arg_2,iVar1,arg_4,arg_5,arg_6,iVar2,iVar3);
  str_7 = s_advfac64_pic_0051acd4;
  str_6 = s_prdblk_pic_0051ace4;
  iVar1 = Ai_Util_004c3bc4(0xa9);
  iVar2 = Ai_Util_004c3bc4(0x89);
  iVar3 = Ai_Util_004c3bc4(0x11);
  arg_2_00 = Ai_Util_004c3bc4(0x28);
  FUN_00488fdb((undefined4 *)g_DisplaySurfaceBackBuffer,arg_2_00,iVar3,iVar2,iVar1,str_6,str_7);
  SelectObject(*(HDC *)(DAT_0070a860 + 4),*(HGDIOBJ *)(DAT_0070a860 + 0xc));
  DAT_0070a860 = 0;
  Font_DrawTextInRect((int)g_DisplaySurfaceBackBuffer,local_14,0x4f,0x102);
  Font_DrawTextInRect((int)g_DisplaySurfaceBackBuffer,local_14,0xb7,0x102);
  Minit_Subsystem_00452827();
  Font_DrawTextInRect((int)g_DisplaySurfaceBackBuffer,local_14,0x4f,0x138);
  Font_DrawTextInRect((int)g_DisplaySurfaceBackBuffer,local_14,0xb7,0x138);
  Font_DrawTextInRect((int)g_DisplaySurfaceBackBuffer,local_14,0x29,0x161);
  Font_DrawTextInRect((int)g_DisplaySurfaceBackBuffer,local_14,0x4e,0x161);
  Font_DrawTextInRect((int)g_DisplaySurfaceBackBuffer,local_14,0x73,0x161);
  Font_DrawTextInRect((int)g_DisplaySurfaceBackBuffer,local_14,0x98,0x161);
  Font_DrawTextInRect((int)g_DisplaySurfaceBackBuffer,local_14,0xbd,0x161);
  Font_DrawTextInRect((int)g_DisplaySurfaceBackBuffer,local_c,0x69,0xc6);
  Font_DrawTextInRect((int)g_DisplaySurfaceBackBuffer,local_c,0x69,0xd6);
  Font_DrawTextInRect((int)g_DisplaySurfaceBackBuffer,local_c,0x10e,0x16c);
  for (local_8 = 0; (int)local_8 < 5; local_8 = local_8 + 1) {
    if (*(int *)(&DAT_006410c0 + local_8 * 4) != 0) {
      iVar1 = (int)(&DAT_00538a10)[local_8];
      iVar2 = Ai_Util_004c3bc4(0x30);
      iVar3 = Ai_Util_004c3bc4(0x30);
      iVar4 = Ai_Util_004c3bc4(0x154);
      arg_2_01 = Ai_Util_004c3bc4(local_8 * 0x39 + 0x14d);
      Sprite_DrawScaled((int *)g_DisplaySurfaceBackBuffer,arg_2_01,iVar4,iVar3,iVar2,iVar1);
    }
  }
  Font_DrawTextInRect((int)g_DisplaySurfaceBackBuffer,local_c,0x118,0xeb);
  for (local_8 = 0; (int)local_8 < 0xc; local_8 = local_8 + 1) {
    *(undefined4 *)(&DAT_0051a528 + (local_8 + 10) * 0x54) = 3;
    *(undefined4 *)(&DAT_00538a30 + local_8 * 4) = 0;
    if (((int)local_8 < 2) || ((local_8 & 1) != 0)) {
      if ((int)local_8 < 2) {
        local_374 = local_8 * 0x35;
      }
      else {
        local_374 = ((int)(local_8 - 2) / 2) * 0x35 + 0x6a;
      }
      *(int *)(&DAT_0051a4f8 + (local_8 + 10) * 0x54) = local_374 + 0xee;
      *(undefined4 *)(&DAT_0051a4e8 + (local_8 + 10) * 0x54) =
           *(undefined4 *)(&DAT_0051a4f8 + (local_8 + 10) * 0x54);
      *(undefined4 *)(&DAT_0051a4fc + (local_8 + 10) * 0x54) = 0x10e;
      *(undefined4 *)(&DAT_0051a4ec + (local_8 + 10) * 0x54) =
           *(undefined4 *)(&DAT_0051a4fc + (local_8 + 10) * 0x54);
      if ((_DAT_0067f374 & 1 << ((byte)local_8 & 0x1f)) != 0) {
        *(undefined4 *)(&DAT_0051a528 + (local_8 + 10) * 0x54) = 0;
        *(undefined4 *)(&DAT_00538a30 + local_8 * 4) = 1;
      }
    }
    else {
      *(int *)(&DAT_0051a4f8 + (local_8 + 10) * 0x54) = ((int)(local_8 - 2) / 2) * 0x35 + 0x16b;
      *(undefined4 *)(&DAT_0051a4e8 + (local_8 + 10) * 0x54) =
           *(undefined4 *)(&DAT_0051a4f8 + (local_8 + 10) * 0x54);
      *(undefined4 *)(&DAT_0051a4fc + (local_8 + 10) * 0x54) = 0xd2;
      *(undefined4 *)(&DAT_0051a4ec + (local_8 + 10) * 0x54) =
           *(undefined4 *)(&DAT_0051a4fc + (local_8 + 10) * 0x54);
      if ((_DAT_0067f374 & 1 << ((byte)local_8 & 0x1f)) != 0) {
        *(undefined4 *)(&DAT_0051a528 + (local_8 + 10) * 0x54) = 0;
        *(undefined4 *)(&DAT_00538a30 + local_8 * 4) = 1;
      }
    }
    *(undefined4 *)(&DAT_0051a504 + (local_8 + 10) * 0x54) = 0x35;
    *(undefined4 *)(&DAT_0051a4f4 + (local_8 + 10) * 0x54) =
         *(undefined4 *)(&DAT_0051a504 + (local_8 + 10) * 0x54);
    *(undefined4 *)(&DAT_0051a500 + (local_8 + 10) * 0x54) =
         *(undefined4 *)(&DAT_0051a4f4 + (local_8 + 10) * 0x54);
    *(undefined4 *)(&DAT_0051a4f0 + (local_8 + 10) * 0x54) =
         *(undefined4 *)(&DAT_0051a500 + (local_8 + 10) * 0x54);
    *(undefined4 *)(&DAT_0051a52c + (local_8 + 10) * 0x54) =
         *(undefined4 *)(&DAT_006782a0 + local_8 * 4);
    *(undefined4 *)(&DAT_0051a534 + (local_8 + 10) * 0x54) =
         *(undefined4 *)(&DAT_006782d0 + local_8 * 4);
    *(undefined4 *)(&DAT_0051a530 + (local_8 + 10) * 0x54) =
         *(undefined4 *)(&DAT_0051a534 + (local_8 + 10) * 0x54);
  }
  FUN_0040b441((int *)&DAT_0051a830,0xc);
  FUN_00422f06();
  FUN_0040d49d((int)g_DisplaySurfaceBackBuffer,local_c,0x14,0x184);
  Font_DrawTextInRect((int)g_DisplaySurfaceBackBuffer,local_14,0xb2,0x184);
  FUN_0040d49d((int)g_DisplaySurfaceBackBuffer,local_c,0x14,0x196);
  Font_DrawTextInRect((int)g_DisplaySurfaceBackBuffer,local_14,0xb2,0x196);
  FUN_0040d49d((int)g_DisplaySurfaceBackBuffer,local_c,0x14,0x1a8);
  Font_DrawTextInRect((int)g_DisplaySurfaceBackBuffer,local_14,0xb2,0x1a8);
  FUN_0040d49d((int)g_DisplaySurfaceBackBuffer,local_c,0x14,0x1ba);
  Font_DrawTextInRect((int)g_DisplaySurfaceBackBuffer,local_14,0xb2,0x1ba);
  FUN_0040d49d((int)g_DisplaySurfaceBackBuffer,local_c,0xe9,0x19a);
  for (local_8 = 0; (int)local_8 < 5; local_8 = local_8 + 1) {
    FUN_0040d49d((int)g_DisplaySurfaceBackBuffer,local_14,local_8 * 0x39 + 0x165,0x19a);
  }
  FUN_0040d49d((int)g_DisplaySurfaceBackBuffer,local_c,0xe9,0x1c0);
  Font_DrawTextInRect((int)g_DisplaySurfaceBackBuffer,local_14,0x1a1,0x1c0);
  Font_DrawTextInRect((int)g_DisplaySurfaceBackBuffer,local_c,0x1b0,0x36);
  if (DAT_0070a880 == 8) {
    memset((void *)((int)&DAT_0070a134 + 2),0,0x300);
    FUN_0050e8b0((short *)&DAT_0070a130);
  }
  if (DAT_0070a880 == 8) {
    FUN_00510b70(-1,0,0,s_advfac64_pic_0051ae08,(short *)&DAT_0070a130);
  }
  else {
    LoadPalNoPic(s_advfac64_pic_0051ae18);
  }
  Surface_BlitToDevice((int *)g_DisplaySurfaceBackBuffer,0,0,g_DisplayScreenWidth,g_DisplayScreenHeight,
               (int *)g_DisplaySurfaceScreen,0,0);
  FUN_005115a0(0,(short)DAT_00530d9c);
  if (g_DisplayScreenWidth == 0x280) {
    Mem_AllocOrFree_00510de0(1,s_creatures640_pic_0051ae28);
    DAT_0051a4c8 = 0;
  }
  else if (g_DisplayScreenWidth == 800) {
    Mem_AllocOrFree_00510de0(1,s_creatures800_pic_0051ae3c);
    DAT_0051a4c8 = 1;
  }
  else if (g_DisplayScreenWidth == 0x400) {
    Mem_AllocOrFree_00510de0(1,s_creatures1024_pic_0051ae50);
    DAT_0051a4c8 = 2;
  }
  DAT_00538ac8 = 0;
  FUN_00422b04(0);
  FUN_0042192b(0x51a638);
LAB_004228ce:
  local_18 = FUN_0041f354();
  Mem_AllocOrFree_0041f12b(local_18);
  FUN_0041f17e(0x51a4e8,0x16,local_18);
  DAT_00680770 = 1;
  for (local_8 = 0; (int)local_8 < 3; local_8 = local_8 + 1) {
    FUN_004212f0((int)(&DAT_0051a4e8 + local_8 * 0x54),0);
  }
  for (local_8 = 10; (int)local_8 < 0x16; local_8 = local_8 + 1) {
    FUN_0041e370((int)(&DAT_0051a4e8 + local_8 * 0x54),0);
  }
  DAT_00680770 = 0;
  DAT_00538a28 = -1;
  while (DAT_00538a28 == -1) {
    Pic_Subsystem_0044b84b();
    FUN_0041f3ea(DAT_0067bda4,DAT_0067bda8,DAT_007039c4);
  }
  FUN_0041f391();
  switch(DAT_00538a28) {
  case 1:
    App_ProcessPendingMessages();
    Glue_Subsystem_004ec98e(0,0xffffffff);
    goto switchD_00422abd_caseD_6;
  case 2:
    FUN_0040b4e8();
    goto switchD_00422abd_caseD_6;
  case 3:
    Mem_AllocOrFree_0050fc50(DAT_00538a10);
    Surface_TransformPoint(0,(short)DAT_00530d9c);
    LoadPalNoPic(s_advfac64_pic_0051ae64);
    return 0;
  case 4:
  case 5:
    goto LAB_004228ce;
  default:
    goto switchD_00422abd_caseD_6;
  case 10:
  case 0xb:
  case 0xc:
  case 0xd:
  case 0xe:
    break;
  case 0xf:
  case 0x10:
  case 0x11:
  case 0x12:
  case 0x13:
  case 0x14:
  case 0x15:
  case 0x16:
  case 0x17:
  case 0x18:
  case 0x19:
  case 0x1a:
    Pic_Load_worlbak1_004230bd(DAT_00538a28 + -0xf);
    goto switchD_00422abd_caseD_6;
  }
  if (*(int *)(DAT_00538a28 * 4 + 0x641098) != 0) {
    Surface_TransformPoint(0,(short)DAT_00530d9c);
    Glue_Subsystem_004ec98e(0x101,DAT_00538a28 - 9);
  }
  App_ProcessPendingMessages();
  if (*(int *)(DAT_00538a28 * 4 + 0x641098) != 0) goto switchD_00422abd_caseD_6;
  goto LAB_004228ce;
switchD_00422abd_caseD_6:
  goto LAB_00421d4c;
}

/*
 * Decompiled function: Castle_Process_0046c8b0
 * Entry Point: 0046c8b0
 * Size: 2686 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Castle_Process_0046c8b0(void)

{
  char *pcVar1;
  int iVar2;
  uint uVar3;
  int local_fdc;
  undefined4 local_fd8 [200];
  int local_cb8;
  undefined4 local_cb4 [200];
  int local_994;
  int local_990;
  int local_98c;
  undefined4 local_988 [13];
  undefined1 auStack_954 [748];
  int local_668;
  int local_664;
  int local_660;
  undefined4 local_65c [200];
  int local_33c;
  undefined4 local_338 [201];
  int local_14;
  int local_c;
  int local_8;
  
  Mem_AllocOrFree_0050fc00();
  Mem_AllocOrFree_00510e20(1,s_endtop_pic_005250b0);
  DAT_00678514 = Sprite_EncodeFromSurface(1,0,0,0x95,0x13);
  FUN_0050fc20();
  Sprite_LoadAll((undefined4 *)&DAT_00677f44,s_gsprite_spr_005250bc);
  Sprite_LoadAll(&DAT_00677e10,s_questnew_spr_005250c8);
  Sprite_LoadAll((undefined4 *)&DAT_00678500,s_compnew_spr_005250d8);
  local_33c = 0;
  Sprite_LoadAll(local_338,s_worlds_spr_005250e4);
  for (local_c = 0; local_c < 4; local_c = local_c + 1) {
    for (local_8 = 0; local_8 < 0xc; local_8 = local_8 + 1) {
      *(undefined4 *)(&DAT_006782a0 + local_8 * 4 + local_c * 0x30) = local_338[local_33c];
      local_33c = local_33c + 1;
    }
  }
  for (local_8 = 0; iVar2 = local_33c, local_8 < 4; local_8 = local_8 + 1) {
    *(undefined4 *)(&DAT_0067f730 + local_8 * 4) = local_338[local_33c];
    local_33c = local_33c + 1;
    *(undefined4 *)(&DAT_0067f740 + local_8 * 4) = local_338[local_33c];
    local_33c = iVar2 + 2;
  }
  for (local_8 = 0; local_8 < 4; local_8 = local_8 + 1) {
    (&DAT_00677fa0)[local_8] = local_338[local_33c];
    local_33c = local_33c + 1;
  }
  Sprite_LoadAll((undefined4 *)&DAT_00677e20,s_asprite_spr_005250f0);
  local_668 = 0;
  Sprite_LoadAll(local_65c,s_ttsprite_spr_005250fc);
  for (local_664 = 0; local_664 < 3; local_664 = local_664 + 1) {
    for (local_660 = 0; local_660 < 0x10; local_660 = local_660 + 1) {
      *(undefined4 *)(&DAT_00678560 + local_660 * 4 + local_664 * 0x40) = local_65c[local_668];
      local_668 = local_668 + 1;
    }
  }
  for (local_660 = 0; local_660 < 6; local_660 = local_660 + 1) {
    *(undefined4 *)(&DAT_00677970 + local_660 * 4) = local_65c[local_668];
    local_668 = local_668 + 1;
  }
  for (local_660 = 0; local_660 < 8; local_660 = local_660 + 1) {
    *(undefined4 *)(&DAT_00677800 + local_660 * 4) = local_65c[local_668];
    local_668 = local_668 + 1;
  }
  for (local_660 = 0; iVar2 = local_668, local_660 < 10; local_660 = local_660 + 1) {
    *(undefined4 *)(&DAT_0067f390 + local_660 * 4) = local_65c[local_668];
    local_668 = local_668 + 1;
  }
  DAT_00677690 = local_65c[local_668];
  local_668 = local_668 + 1;
  DAT_006784f0 = local_65c[local_668];
  local_668 = iVar2 + 2;
  _DAT_006784f4 = local_65c[local_668];
  local_668 = iVar2 + 3;
  Sprite_LoadAll(&DAT_006776a0,s_amsprite_spr_0052510c);
  uVar3 = 0x54;
  pcVar1 = (char *)Sprite_ResolveAssetPath(s_cstline1_spr_0052511c);
  local_8 = Sprite_LoadCount((undefined4 *)&DAT_00677820,pcVar1,uVar3);
  uVar3 = 0x10;
  pcVar1 = (char *)Sprite_ResolveAssetPath(s_landtile_spr_0052512c);
  local_8 = Sprite_LoadCount(&DAT_00677650,pcVar1,uVar3);
  uVar3 = 0x37;
  pcVar1 = (char *)Sprite_ResolveAssetPath(s_land_spr_0052513c);
  local_8 = Sprite_LoadCount((undefined4 *)&DAT_00677450,pcVar1,uVar3);
  uVar3 = 0x37;
  pcVar1 = (char *)Sprite_ResolveAssetPath(s_sland_spr_00525148);
  local_8 = Sprite_LoadCount((undefined4 *)&DAT_00678010,pcVar1,uVar3);
  uVar3 = 0x37;
  pcVar1 = (char *)Sprite_ResolveAssetPath(s_land2_spr_00525154);
  local_8 = Sprite_LoadCount((undefined4 *)&DAT_0067752c,pcVar1,uVar3);
  uVar3 = 0x37;
  pcVar1 = (char *)Sprite_ResolveAssetPath(s_sland2_spr_00525160);
  local_8 = Sprite_LoadCount((undefined4 *)&DAT_006780ec,pcVar1,uVar3);
  uVar3 = 0xc;
  pcVar1 = (char *)Sprite_ResolveAssetPath(s_roads_spr_0052516c);
  local_8 = Sprite_LoadCount((undefined4 *)&DAT_00677350,pcVar1,uVar3);
  pcVar1 = (char *)Sprite_ResolveAssetPath(s_locatn01_spr_00525178);
  local_8 = Sprite_LoadAll((undefined4 *)&DAT_00677a10,pcVar1);
  pcVar1 = (char *)Sprite_ResolveAssetPath(s_locatn02_spr_00525188);
  iVar2 = Sprite_LoadAll((undefined4 *)(&DAT_00677a10 + local_8 * 4),pcVar1);
  local_8 = local_8 + iVar2;
  pcVar1 = (char *)Sprite_ResolveAssetPath(s_locatn03_spr_00525198);
  local_14 = Sprite_LoadAll((undefined4 *)(&DAT_00677a10 + local_8 * 4),pcVar1);
  local_14 = local_8 + local_14;
  local_8 = local_14;
  pcVar1 = (char *)Sprite_ResolveAssetPath(s_locatn04_spr_005251a8);
  iVar2 = Sprite_LoadAll((undefined4 *)(&DAT_00677a10 + local_8 * 4),pcVar1);
  local_8 = local_8 + iVar2;
  _DAT_00677ff4 = *(undefined4 *)(&DAT_00677a18 + local_14 * 4);
  _DAT_00678000 = *(undefined4 *)(&DAT_00677a1c + local_14 * 4);
  _DAT_00677ff8 = *(undefined4 *)(&DAT_00677a30 + local_14 * 4);
  _DAT_00677ff0 = *(undefined4 *)(&DAT_00677a38 + local_14 * 4);
  DAT_006784f8 = *(undefined4 *)(&DAT_00677a28 + local_14 * 4);
  pcVar1 = (char *)Sprite_ResolveAssetPath(s_locatn05_spr_005251b8);
  local_14 = Sprite_LoadAll((undefined4 *)(&DAT_00677a10 + local_8 * 4),pcVar1);
  local_14 = local_8 + local_14;
  local_8 = local_14;
  pcVar1 = (char *)Sprite_ResolveAssetPath(s_locatn06_spr_005251c8);
  iVar2 = Sprite_LoadAll((undefined4 *)(&DAT_00677a10 + local_8 * 4),pcVar1);
  local_8 = local_8 + iVar2;
  _DAT_00677ffc = *(undefined4 *)(&DAT_00677a10 + local_14 * 4);
  local_98c = 0;
  Sprite_LoadAll(local_988,s_tsprite2_spr_005251d8);
  for (local_8 = 0; local_8 < 6; local_8 = local_8 + 1) {
    for (local_c = 0; local_c < 2; local_c = local_c + 1) {
      *(undefined4 *)(&DAT_00677620 + local_8 * 8 + local_c * 4) = local_988[local_98c];
      local_98c = local_98c + 1;
    }
  }
  memcpy(&DAT_00677f10,local_988 + local_98c,0x34);
  memcpy(&DAT_00678540,auStack_954 + local_98c * 4,0x18);
  for (local_8 = 0; local_8 < 0x20; local_8 = local_8 + 1) {
    *(undefined4 *)(&g_OverworldFoodAmount + local_8 * 0xb4) = 0;
  }
  pcVar1 = (char *)Sprite_ResolveAssetPath(s_ego_f_spr_005251e8 +
                                ((*(int *)(&DAT_00525070 + DAT_006ff678 * 4) != 0) - 1 & 0xc));
  local_8 = Sprite_LoadAll(&DAT_00679370,pcVar1);
  local_990 = DAT_00679370;
  DAT_00678430 = (int)*(short *)(DAT_00679370 + 4);
  DAT_006784b0 = (int)*(short *)(DAT_00679370 + 6);
  DAT_006779d0 = (int)*(short *)(DAT_00679370 + 10);
  if (DAT_006784b0 < DAT_006779d0) {
    DAT_006779d0 = (DAT_006784b0 * 2) / 3;
  }
  pcVar1 = (char *)Sprite_ResolveAssetPath(s_sego_f_spr_00525200);
  local_8 = Sprite_LoadAll(&DAT_00679424,pcVar1);
  local_994 = DAT_00679424;
  DAT_00678434 = (int)*(short *)(DAT_00679424 + 4);
  DAT_006784b4 = (int)*(short *)(DAT_00679424 + 6);
  DAT_006779d4 = (int)*(short *)(DAT_00679424 + 10);
  if (DAT_006784b4 < DAT_006779d4) {
    DAT_006779d4 = (DAT_006784b4 * 2) / 3;
  }
  pcVar1 = (char *)Sprite_ResolveAssetPath(s_castles1_spr_0052520c);
  local_8 = Sprite_LoadAll((undefined4 *)&DAT_00678660,pcVar1);
  uVar3 = 8;
  pcVar1 = (char *)Sprite_ResolveAssetPath(s_castles2_spr_0052521c);
  local_8 = Sprite_LoadCount((undefined4 *)&DAT_00678690,pcVar1,uVar3);
  uVar3 = 0xc;
  pcVar1 = (char *)Sprite_ResolveAssetPath(s_locatn07_spr_0052522c);
  local_8 = Sprite_LoadCount((undefined4 *)&DAT_00677420,pcVar1,uVar3);
  local_cb8 = 0;
  Sprite_LoadAll(local_cb4,s_dbox_spr_0052523c);
  for (local_8 = 0; local_8 < 4; local_8 = local_8 + 1) {
    for (local_c = 0; local_c < 9; local_c = local_c + 1) {
      (&DAT_006781d0)[local_8 * 9 + local_c] = local_cb4[local_cb8];
      local_cb8 = local_cb8 + 1;
    }
  }
  Sprite_LoadAll((undefined4 *)&DAT_00678390,s_icons_spr_00525248);
  local_fdc = 0;
  Sprite_LoadAll(local_fd8,s_iconb_spr_00525254);
  for (local_8 = 0; local_8 < 4; local_8 = local_8 + 1) {
    *(undefined4 *)(&DAT_00678260 + local_8 * 0x10) = local_fd8[local_fdc];
    *(undefined4 *)(&DAT_00678264 + local_8 * 0x10) = local_fd8[local_fdc + 1];
    local_fdc = local_fdc + 2;
    for (local_c = 0; local_c < 2; local_c = local_c + 1) {
      *(undefined4 *)(&DAT_00678268 + local_c * 4 + local_8 * 0x10) = local_fd8[local_fdc];
      local_fdc = local_fdc + 1;
    }
  }
  if (DAT_0052f008 == 0) {
    Sprite_LoadAll(&DAT_00677fc0,s_clocknew_spr_00525260);
    Sprite_LoadAll((undefined4 *)&DAT_00678360,s_daysnew_spr_00525270);
    Sprite_LoadAll((undefined4 *)&DAT_00677f50,s_Sunmoon_spr_0052527c);
  }
  Mem_AllocOrFree_00510e20(1,s_tips_pic_00525288);
  Mem_AllocOrFree_0050fc00();
  if (g_DisplayScreenWidth == 0x280) {
    DAT_00677fb0 = Sprite_EncodeFromSurface(1,1,1,5,0x10);
    DAT_00677fe4 = Sprite_EncodeFromSurface(1,10,1,3,2);
  }
  else if (g_DisplayScreenWidth == 800) {
    DAT_00677fb0 = Sprite_EncodeFromSurface(1,1,0x1d,6,0x14);
    DAT_00677fe4 = Sprite_EncodeFromSurface(1,10,0x1d,5,3);
  }
  else if (g_DisplayScreenWidth == 0x400) {
    DAT_00677fb0 = Sprite_EncodeFromSurface(1,1,0x39,8,0x1b);
    DAT_00677fe4 = Sprite_EncodeFromSurface(1,10,0x39,6,9);
  }
  FUN_0050fc20();
  return;
}

/*
 * Decompiled function: Dungeon_Process_004856b0
 * Entry Point: 004856b0
 * Size: 14542 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int Dungeon_Process_004856b0(uint arg1,int arg2)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  char *pcVar10;
  undefined4 uVar11;
  void *pvVar12;
  uint uVar13;
  int local_964 [11];
  int local_938;
  int local_934;
  int local_930;
  int local_92c;
  int local_928;
  int local_924;
  int local_920;
  int local_91c;
  int local_918;
  int local_914;
  char *local_910;
  char *local_90c;
  char *local_908;
  char *local_904;
  char *local_900;
  int local_8fc;
  int local_8f8;
  void *local_8f4;
  void *local_8ec;
  int local_8cc;
  int local_8c8;
  uint local_8c4;
  int local_8c0;
  uint local_8bc;
  uint local_8b8;
  undefined *local_8b4;
  uint auStack_8b0 [10];
  int local_888;
  int local_884;
  uint local_880;
  uint local_87c;
  LPVOID local_878;
  uint local_874;
  uint local_870;
  int local_86c;
  int local_868;
  uint local_864;
  uint local_860;
  uint local_85c;
  int local_850;
  int local_84c;
  int local_848;
  int local_844;
  int local_840;
  int local_83c;
  int local_838;
  undefined4 local_834;
  int local_830;
  uint local_82c [518];
  LPVOID local_14;
  uint local_10;
  int local_c;
  int local_8;
  
  local_8b4 = PTR_FUN_00527b3c;
  Glue_Subsystem_004ebebf();
  if (*(int *)(&DAT_0067f2d0 + arg1 * 0x14) == 0) {
    Sound_LoadWav_x_DuelSounds_artifact_0040de30(*(int *)(&DAT_0067f2dc + arg1 * 0x14));
    DAT_0067f384 = DAT_0067f384 + 1;
    Glue_Subsystem_004eadb7(0);
  }
  else {
    FUN_0046f21e(s_dbox2_spr_00527110,0xd5,0xd2);
    local_14 = *(LPVOID *)(&DAT_0067f2d0 + arg1 * 0x14);
    DAT_006b2d64 = arg2;
    DAT_00695df0 = (int)(char)(&DAT_00522629)[(int)local_14 * 0x44];
    local_880 = DAT_00695df0 + (int)(char)(&DAT_00522628)[(int)local_14 * 0x44] / 2;
    if ('\n' < (char)(&DAT_0052262a)[(int)local_14 * 0x44]) {
      local_880 = 0;
    }
    Glue_Subsystem_004ebfef(0);
    if ((&DAT_0052262a)[(int)local_14 * 0x44] == '\v') {
      local_8bc = Glue_Subsystem_004f0de8(DAT_00531590);
    }
    else {
      local_8bc = Pic_Subsystem_0045268f(*(int *)(&DAT_0052262c + (int)local_14 * 0x44));
      if (local_8bc == 0xffffffff) {
        local_8bc = arg2 - 1;
      }
    }
    DAT_006b2d98 = 0xffffffff;
    DAT_006b2d94 = 0xffffffff;
    DAT_006b2d90 = 0xffffffff;
    DAT_006b2dd8 = 0xffffffff;
    DAT_006b2dd4 = 0xffffffff;
    DAT_006b2dd0 = -1;
    FUN_004909d3((int)local_14,0xffffffff,0,-1);
    if ((&DAT_0052262a)[(int)local_14 * 0x44] != '\v') {
      do {
        do {
          DAT_006b2dd0 = FUN_0040a02a(DAT_0052eff8);
        } while (DAT_006b2dd0 < 5);
      } while (((((&DAT_0051aed1)[DAT_006b2dd0 * 0x34] & 1) != 0) ||
               (iVar3 = FUN_00485005(DAT_006b2dd0), iVar3 == 0)) ||
              (*(int *)(&g_MasterCardTypeTable + DAT_006b2dd0 * 0x34) ==
               *(int *)(&DAT_0052262c + (int)local_14 * 0x44)));
    }
    if ((&DAT_0052262a)[(int)local_14 * 0x44] == '\f') {
      local_840 = 3;
    }
    else {
      local_840 = 1;
    }
    Glue_Subsystem_004eccd7();
    for (local_874 = 0; (int)local_874 < local_840; local_874 = local_874 + 1) {
      do {
        do {
          local_878 = (LPVOID)Math_RandomRange(500);
        } while (*(int *)(&deck + (int)local_878 * 4) == -1);
      } while ((((&DAT_00702151)[(int)local_878 * 4] & 0x40) != 0) ||
              ((*(uint *)(&deck + (int)local_878 * 4) & 0xfff) < 5));
      (&DAT_006b2d90)[local_874] = *(uint *)(&deck + (int)local_878 * 4) & 0xfff;
    }
    local_834 = 2;
    local_910 = s_prdblk_pic_00527128;
    local_90c = s_prdblu_pic_00527140;
    local_908 = s_prdgrn_pic_00527158;
    local_904 = s_prdrd_pic_00527170;
    local_900 = s_prdwt_pic_00527188;
    Surface_TransformPoint(0,(short)DAT_00530d9c);
    FUN_00510b70(1,0,0,(char *)(&local_914)[arg2],
                 (short *)((int)&DAT_0070a130 + ((DAT_0070a880 == 8) - 1 & 0xff8f5ed1)));
    Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,
                       (int *)g_DisplaySurfaceScreen,0,0,g_DisplayScreenWidth,g_DisplayScreenHeight);
    FUN_005115a0(0,(short)DAT_00530d9c);
    GDI_RealizeAndFlushPalette_Magic(_hdcScreen);
    Mem_AllocOrFree_00510e20(1,s_prdfrma_pic_00527194);
    Mem_AllocOrFree_0050fc00();
    local_8f4 = (void *)Sprite_EncodeFromSurface(1,1,1,0x68,0x2c);
    local_914 = Sprite_EncodeFromSurface(1,1,0x2e,0x67,0x31);
    local_8cc = Sprite_EncodeFromSurface(1,1,0x60,0x66,0x2c);
    local_8fc = Sprite_EncodeFromSurface(1,1,0x8d,0x79,0x2c);
    local_8c8 = Sprite_EncodeFromSurface(1,1,0xba,0x91,0x72);
    pvVar12 = local_8f4;
    iVar3 = Ai_Util_004c3bc4((int)*(short *)((int)local_8f4 + 6));
    iVar4 = Ai_Util_004c3bc4((int)*(short *)((int)local_8f4 + 4));
    iVar5 = Ai_Util_004c3bc4(0x173);
    iVar6 = Ai_Util_004c3bc4(0x14);
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,iVar6,iVar5,iVar4,iVar3,(int)pvVar12);
    iVar3 = local_914;
    iVar4 = Ai_Util_004c3bc4((int)*(short *)(local_914 + 6));
    iVar5 = Ai_Util_004c3bc4((int)*(short *)(local_914 + 4));
    iVar6 = Ai_Util_004c3bc4(0x16d);
    iVar7 = Ai_Util_004c3bc4((int)*(short *)((int)local_8f4 + 4));
    iVar8 = Ai_Util_004c3bc4(0x14);
    iVar9 = Ai_Util_004c3bc4(8);
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,(iVar7 + iVar8) - iVar9,iVar6,iVar5,iVar4,iVar3)
    ;
    iVar3 = Ai_Util_004c3bc4((int)*(short *)(local_914 + 4));
    iVar4 = Ai_Util_004c3bc4((int)*(short *)((int)local_8f4 + 4));
    iVar5 = Ai_Util_004c3bc4(8);
    local_8f8 = Ai_Util_004c3bc4(0x14);
    local_8f8 = ((iVar3 + iVar4) - iVar5) / 2 + local_8f8;
    iVar3 = Ai_Util_004c3bc4((int)*(short *)(local_8fc + 4));
    iVar4 = Ai_Util_004c3bc4((int)*(short *)(local_8cc + 4));
    iVar5 = Ai_Util_004c3bc4(8);
    local_8f8 = local_8f8 - ((iVar3 + iVar4) - iVar5) / 2;
    iVar3 = local_8fc;
    iVar4 = Ai_Util_004c3bc4((int)*(short *)(local_8fc + 6));
    iVar5 = Ai_Util_004c3bc4((int)*(short *)(local_8fc + 4));
    iVar6 = Ai_Util_004c3bc4((int)*(short *)((int)local_8f4 + 6));
    iVar7 = Ai_Util_004c3bc4(0x173);
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,local_8f8,iVar6 + iVar7,iVar5,iVar4,iVar3);
    iVar3 = local_8cc;
    iVar4 = Ai_Util_004c3bc4((int)*(short *)(local_8cc + 6));
    iVar5 = Ai_Util_004c3bc4((int)*(short *)(local_8cc + 4));
    iVar6 = Ai_Util_004c3bc4((int)*(short *)((int)local_8f4 + 6));
    iVar7 = Ai_Util_004c3bc4(0x173);
    iVar6 = iVar6 + iVar7;
    iVar7 = Ai_Util_004c3bc4((int)*(short *)(local_8fc + 4));
    iVar7 = local_8f8 + iVar7;
    iVar8 = Ai_Util_004c3bc4(8);
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,iVar7 - iVar8,iVar6,iVar5,iVar4,iVar3);
    *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 4;
    Font_DrawTextInRect((int)g_DisplaySurfaceScreen,0xd2,0x5b,0x188);
    Font_DrawTextInRect((int)g_DisplaySurfaceScreen,0xd2,0xbd,0x188);
    Font_DrawTextInRect((int)g_DisplaySurfaceScreen,0xd2,0x5b,0x1b5);
    Minit_Subsystem_00452827();
    Font_DrawTextInRect((int)g_DisplaySurfaceScreen,0xd2,0xc3,0x1b5);
    *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 2;
    iVar3 = local_8c8;
    iVar4 = Ai_Util_004c3bc4((int)*(short *)(local_8c8 + 6));
    iVar5 = Ai_Util_004c3bc4((int)*(short *)(local_8c8 + 4));
    iVar6 = Ai_Util_004c3bc4(0x15e);
    iVar7 = Ai_Util_004c3bc4(0x1d4);
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,iVar7,iVar6,iVar5,iVar4,iVar3);
    Ai_CalcManaRequirement_004c003d();
    Font_DrawTextInRect((int)g_DisplaySurfaceScreen,0xd2,0x21f,0x199);
    FUN_0050fc20();
    Mem_AllocOrFree_0050fc50(local_8f4);
    iVar6 = 0;
    iVar5 = 0;
    iVar3 = Ai_Util_004c3bc4(10);
    iVar4 = Ai_Util_004c3bc4(0x140);
    Pic_Load_advfac64_00489188(local_14,iVar4,iVar3,iVar5,iVar6);
    Mem_AllocOrFree_00510e20(1,s_prdfrmb_pic_005271b4);
    *(undefined4 *)(g_DisplaySurfaceBackBuffer + 0x20) = 4;
    *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 4;
    Mem_AllocOrFree_0050fc00();
    local_8ec = (void *)Sprite_EncodeFromSurface(1,1,0x17e,0x98,0x23);
    local_918 = Sprite_EncodeFromSurface(1,1,0x1a2,0x80,0x23);
    FUN_0050fc20();
    pvVar12 = local_8ec;
    iVar3 = Ai_Util_004c3bc4((int)*(short *)((int)local_8ec + 6));
    iVar4 = Ai_Util_004c3bc4((int)*(short *)((int)local_8ec + 4));
    iVar5 = Ai_Util_004c3bc4(5);
    iVar6 = Ai_Util_004c3bc4(0x220 - (int)*(short *)((int)local_8ec + 4) / 2);
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,iVar6,iVar5,iVar4,iVar3,(int)pvVar12);
    iVar3 = Ai_Util_004c3bc4((int)*(short *)((int)local_8ec + 6) / 2 + 5);
    iVar4 = Ai_Util_004c3bc4(0x220);
    FUN_0040d009((int)g_DisplaySurfaceScreen,0xe6,iVar4,iVar3);
    iVar3 = local_918;
    iVar4 = Ai_Util_004c3bc4((int)*(short *)(local_918 + 6));
    iVar5 = Ai_Util_004c3bc4((int)*(short *)(local_918 + 4));
    iVar6 = Ai_Util_004c3bc4(5);
    iVar7 = Ai_Util_004c3bc4(100 - (int)*(short *)(local_918 + 4) / 2);
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,iVar7,iVar6,iVar5,iVar4,iVar3);
    iVar3 = Ai_Util_004c3bc4((int)*(short *)(local_918 + 6) / 2 + 5);
    iVar4 = Ai_Util_004c3bc4(100);
    FUN_0040d009((int)g_DisplaySurfaceScreen,0xe6,iVar4,iVar3);
    *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 1;
    Mem_AllocOrFree_0050fc50(local_8ec);
    g_OverworldWorldState = 0;
    Glue_Subsystem_004eaa19((int)local_14,0,0);
    strcat(&g_OverworldWorldState,s__s_ANTE__005271dc);
    if ((g_IsAiThinking == 0) && ((&DAT_0052262a)[(int)local_14 * 0x44] != '\v')) {
      FUN_0050b206(DAT_006b2dd0,0xe8,0x18,1,&DAT_005271e8);
    }
    local_83c = Math_Clamp(local_880 * 10, 10, local_880 * 0x32);
    if ((&DAT_0052262a)[(int)local_14 * 0x44] != '\v') {
      local_86c = 0;
      local_838 = 0;
      local_924 = (int)(*(int *)(&DAT_0067f2d4 + arg1 * 0x14) +
                       (*(int *)(&DAT_0067f2d4 + arg1 * 0x14) >> 0x1f & 0x1fU)) >> 5;
      local_928 = (int)(*(int *)(&DAT_0067f2d8 + arg1 * 0x14) +
                       (*(int *)(&DAT_0067f2d8 + arg1 * 0x14) >> 0x1f & 0x1fU)) >> 5;
      local_91c = *(int *)(&DAT_0067f000 + (arg2 + -1) * 0x30);
      local_920 = *(int *)(&DAT_0067f004 + (arg2 + -1) * 0x30);
      iVar3 = abs(local_924 - local_91c);
      if ((iVar3 <= DAT_0067f380 / 2 + 2) &&
         (iVar3 = abs(local_928 - local_920), iVar3 <= DAT_0067f380 / 2 + 2)) {
        local_838 = 1;
      }
      if (arg1 == 7) {
        local_838 = 2;
      }
LAB_0048627e:
      for (local_874 = 0; (int)local_874 < local_840; local_874 = local_874 + 1) {
        if (g_IsAiThinking == 0) {
          FUN_0050b206((&DAT_006b2d90)[local_874],local_874 * 0x18 + 10,local_874 * 0xc + 0x18,1,
                       &DAT_005271ec);
        }
      }
      local_850 = 0;
      for (local_874 = 0; ((int)local_874 < 1000 && ((&DAT_0067b9b0)[local_874] != '\0'));
          local_874 = local_874 + 1) {
        if (((&DAT_0052262a)[(int)local_14 * 0x44] == ((&DAT_0067b9b0)[local_874] & 0xf)) &&
           ((int)(char)(&DAT_0067b9b0)[local_874] >> 4 == arg2)) {
          local_850 = local_850 + 1;
        }
      }
      if (local_838 == 1) {
        strcpy(&g_OverworldWorldState,s_Those_who_near_the_stronghold_of_005271f0);
        pcVar10 = (char *)Mem_AllocOrFree_00473d7e(arg2);
        strcat(&g_OverworldWorldState,pcVar10);
        strcat(&g_OverworldWorldState,s_Wizard_will_be_met_with_the_firm_00527220);
        strcat(&g_OverworldWorldState,s_you_must____Duel_00527254);
        Glue_Subsystem_004eaa19((int)local_14,1,0);
        strcat(&g_OverworldWorldState,&DAT_00527268);
      }
      else if (local_838 == 2) {
        strcpy(&g_OverworldWorldState,s_Those_who_would_challenge_the_Gr_0052726c);
        pcVar10 = (char *)Mem_AllocOrFree_00473d7e(arg2);
        strcat(&g_OverworldWorldState,pcVar10);
        strcat(&g_OverworldWorldState,s_Wizard_for_Supremacy_of_00527294);
        uVar13 = Glue_Subsystem_004f0a4a
                           ((int)(*(int *)(&DAT_0067f2d4 + arg1 * 0x14) +
                                 (*(int *)(&DAT_0067f2d4 + arg1 * 0x14) >> 0x1f & 0x1fU)) >> 5,
                            (int)(*(int *)(&DAT_0067f2d8 + arg1 * 0x14) +
                                 (*(int *)(&DAT_0067f2d8 + arg1 * 0x14) >> 0x1f & 0x1fU)) >> 5);
        Ai_TownEncounter_004c3b19(uVar13);
        strcat(&g_OverworldWorldState,s_must____Duel_005272b0);
        Glue_Subsystem_004eaa19((int)local_14,1,0);
        strcat(&g_OverworldWorldState,&DAT_005272c0);
      }
      else if (local_850 < 5) {
        strcpy(&g_OverworldWorldState,s_Those_who_enter_the_domain_of_th_005272c4);
        pcVar10 = (char *)Mem_AllocOrFree_00473d7e(arg2);
        strcat(&g_OverworldWorldState,pcVar10);
        strcat(&g_OverworldWorldState,s_Wizard_must_pay_for_the_privileg_005272f0);
        strcat(&g_OverworldWorldState,s_Will_you____Duel_00527318);
        Glue_Subsystem_004eaa19((int)local_14,1,0);
        strcat(&g_OverworldWorldState,&DAT_0052732c);
      }
      else {
        strcpy(&g_OverworldWorldState,&DAT_00527330);
        strcat(&g_OverworldWorldState,s_Lairs_00522614 + (int)local_14 * 0x44);
        strcat(&g_OverworldWorldState,s_who_inhabit_the_domain_of_the_Mi_00527338);
        pcVar10 = (char *)Mem_AllocOrFree_00473d7e(arg2);
        strcat(&g_OverworldWorldState,pcVar10);
        strcat(&g_OverworldWorldState,s_Wizard_tremble_in_fear_of_your_v_00527360);
        strcat(&g_OverworldWorldState,s_Will_you____Accept_tribute_for_y_0052738c);
      }
      local_8c4 = 1;
      if ((((local_878 == (LPVOID)0x0) || (Gold < local_83c)) || (local_838 != 0)) ||
         (4 < local_850)) {
        local_864 = 0xffffffff;
      }
      else {
        strcat(&g_OverworldWorldState,s_Pay_005273bc);
        pcVar10 = _itoa(local_83c,&DAT_00539d50,10);
        strcat(&g_OverworldWorldState,pcVar10);
        strcat(&g_OverworldWorldState,s_gold__005273c4);
        local_864 = local_8c4;
        local_8c4 = local_8c4 + 1;
      }
      if (((local_850 < DAT_0067f380 * 2 + 2) || (local_838 != 0)) || (4 < local_850)) {
        local_860 = 0xffffffff;
      }
      else {
        strcat(&g_OverworldWorldState,s_Answer_a_riddle__005273cc);
        local_860 = local_8c4;
        local_8c4 = local_8c4 + 1;
      }
      if ((((_DAT_0067f374 & 1) == 0) || (local_86c != 0)) || (local_840 != 1)) {
        if (local_86c == 0) {
          local_85c = 0xffffffff;
        }
        else {
          strcat(&g_OverworldWorldState,&DAT_005273f4);
          local_85c = 0xffffffff;
        }
      }
      else {
        strcat(&g_OverworldWorldState,s_Change_ante_card__005273e0);
        local_85c = local_8c4;
        local_8c4 = local_8c4 + 1;
      }
      if (g_IsAiThinking < 0) {
        local_870 = 0;
      }
      else {
        do {
          uVar11 = Ai_Util_004c3bc4(0x100);
          iVar3 = g_DisplayScreenWidth / 2;
          iVar4 = FUN_0050f440((int *)g_DisplaySurfaceScreen,&g_OverworldWorldState);
          local_870 = FUN_00489710(&g_OverworldWorldState,(iVar3 - iVar4 / 2) + -2,uVar11);
        } while (local_870 == 0xffffffff);
      }
      if (((((int)local_870 < 1) && (4 < local_850)) && (-(int)local_14 != DAT_0067f2c0)) &&
         (local_838 == 0)) {
        local_964[10] = Math_RandomRange(3);
        local_938 = Math_RandomRange(3);
        strcpy(&g_OverworldWorldState,s_I_thank_your_for_your_mercy_gran_005273f8);
        if (local_964[10] == 0) {
          strcat(&g_OverworldWorldState,s_A_spell_from_my_deck__00527430);
        }
        else if (local_964[10] == 1) {
          strcat(&g_OverworldWorldState,s_The_location_of_WORLDMAGIC_cards_00527448);
        }
        else if (local_964[10] == 2) {
          strcat(&g_OverworldWorldState,s_Secrets_from_the_0052746c);
          pcVar10 = (char *)Mem_AllocOrFree_00473d7e(arg2);
          strcat(&g_OverworldWorldState,pcVar10);
          strcat(&g_OverworldWorldState,s_Castle__00527480);
        }
        if (local_938 == 0) {
          strcat(&g_OverworldWorldState,&DAT_0052748c);
          cVar1 = (&DAT_00522628)[(int)local_14 * 0x44];
          iVar3 = Math_RandomRange(10 - DAT_0067f380);
          local_930 = (cVar1 + iVar3) * 10;
          pcVar10 = _itoa(local_930,&DAT_00539d50,10);
          strcat(&g_OverworldWorldState,pcVar10);
          strcat(&g_OverworldWorldState,s_Gold_00527490);
        }
        else if (local_938 == 1) {
          strcat(&g_OverworldWorldState,s_40_Food_00527498);
        }
        else if (local_938 == 2) {
          strcat(&g_OverworldWorldState,&DAT_005274a4);
          local_934 = Math_RandomRange(3);
          local_934 = local_934 + 1;
          local_92c = Math_RandomRange(5);
          local_92c = local_92c + 1;
          pcVar10 = _itoa(local_934,&DAT_00539d50,10);
          strcat(&g_OverworldWorldState,pcVar10);
          strcat(&g_OverworldWorldState,&DAT_005274a8);
          pcVar10 = (char *)Mem_AllocOrFree_00473d7e(local_92c);
          strcat(&g_OverworldWorldState,pcVar10);
          strcat(&g_OverworldWorldState,s_Jewel_005274ac);
          strcat(&g_OverworldWorldState,&DAT_005274b4 + ((local_934 == 1) - 1 & 4));
        }
        strcat(&g_OverworldWorldState,s_Duel_Anyway_005274bc);
        local_870 = FUN_00489710(&g_OverworldWorldState,0x80,0xc0);
        if ((local_870 == 0) && (local_964[10] == 0)) {
          FUN_004909d3((int)local_14,0xffffffff,0,-1);
          for (arg1 = 0; (int)arg1 < 500; arg1 = arg1 + 1) {
            uVar11 = FUN_0040a02a(DAT_0052eff8);
            *(undefined4 *)(&DAT_0069ef00 + arg1 * 4) = uVar11;
            if (((&DAT_0051aed1)[*(int *)(&DAT_0069ef00 + arg1 * 4) * 0x34] & 1) != 0) {
              *(undefined4 *)(&DAT_0069ef00 + arg1 * 4) = 0xffffffff;
            }
          }
          SelectPalette(_hdcScreen,DAT_00626834,0);
          Surface_TransformPoint(0,(short)DAT_00530d9c);
          FUN_0046f21e(s_dbox_spr_005274cc,0x71,0xe3);
          local_8bc = Pic_Load_004509e8(g_CurrentTurnPhase,0x69ef00,500,s_Pick_a_spell_005274dc,1);
          if ((*(int *)(&DAT_0069ef00 + local_8bc * 4) != -1) &&
             (local_878 = (LPVOID)Pic_Subsystem_00451e40(*(uint *)(&DAT_0069ef00 + local_8bc * 4)),
             local_878 != (LPVOID)0xffffffff)) {
            *(uint *)(&deck + (int)local_878 * 4) = *(uint *)(&deck + (int)local_878 * 4) | 0x4000;
          }
        }
        if ((local_870 == 0) && (local_964[10] == 1)) {
          strcpy(&g_OverworldWorldState,s_Which_WM_spell_do_you_seek____005274ec);
          local_84c = 0;
          for (arg1 = 0; (int)arg1 < 0xc; arg1 = arg1 + 1) {
            if ((_DAT_0067f374 & 1 << ((byte)arg1 & 0x1f)) == 0) {
              strcat(&g_OverworldWorldState,(&PTR_s_Sleight_of_hand_005225d0)[arg1]);
              strcat(&g_OverworldWorldState,&DAT_0052750c);
              local_82c[local_84c] = arg1;
              local_84c = local_84c + 1;
            }
          }
          if (local_84c == 0) {
            g_OverworldWorldState = 0;
            strcpy(&g_OverworldWorldState,s_You_have_already_gathered_all_of_00527510);
            local_870 = FUN_004896be(&g_OverworldWorldState,0x50,100);
          }
          else {
            local_870 = FUN_00489710(&g_OverworldWorldState,0xa0,200);
            if (local_870 != 0xffffffff) {
              local_874 = *(uint *)(&DAT_005224e8 + local_82c[local_870] * 0x10);
              *(uint *)(&DAT_0067be00 + local_874 * 100) =
                   *(uint *)(&DAT_0067be00 + local_874 * 100) | 2;
              FUN_0040c81c(0x80,*(int *)(&DAT_0067bdf4 + local_874 * 100),
                           *(int *)(&DAT_0067bdf8 + local_874 * 100));
              strcpy(&g_OverworldWorldState,(&PTR_s_Sleight_of_hand_005225d0)[local_82c[local_870]])
              ;
              strcat(&g_OverworldWorldState,s_may_be_found_in_0052754c);
              Ai_TownEncounter_004c3b19(local_874);
              strcat(&g_OverworldWorldState,&DAT_00527560);
              FUN_00489710(&g_OverworldWorldState,0x5a,0x6e);
              Glue_Subsystem_004ead96(0);
              Glue_Subsystem_004eadb7(0);
              SelectPalette(_hdcScreen,DAT_00626834,0);
              Surface_TransformPoint(0,(short)DAT_00530d9c);
              Ai_CastleEncounter_004c24b3(0);
            }
          }
        }
        if ((local_870 == 0) && (local_964[10] == 2)) {
          if (*(int *)(&DAT_006410bc + arg2 * 4) == 0) {
            if (((byte)*(undefined4 *)(&DAT_0067f010 + (arg2 + -1) * 0x30) & 7) == 7) {
              Castle_Process_00492ddf(arg2 + -1);
            }
            else {
              SelectPalette(_hdcScreen,DAT_00626834,0);
              Surface_TransformPoint(0,(short)DAT_00530d9c);
              FUN_0048ea81(arg2 + -1);
            }
          }
          else {
            g_OverworldWorldState = 0;
            strcpy(&g_OverworldWorldState,s_You_have_already_destroyed_the_00527564);
            pcVar10 = (char *)Mem_AllocOrFree_00473d7e(arg2);
            strcat(&g_OverworldWorldState,pcVar10);
            strcat(&g_OverworldWorldState,s_Castle__00527584);
            FUN_004896be(&g_OverworldWorldState,0x54,0x74);
          }
        }
        if (local_870 == 1) {
          if (local_938 == 0) {
            Gold = Gold + local_930;
          }
          else if (local_938 == 1) {
            DAT_00522448 = DAT_00522448 + 0x28;
          }
          else if (local_938 == 2) {
            *(int *)(&DAT_0067bdbc + local_92c * 4) =
                 *(int *)(&DAT_0067bdbc + local_92c * 4) + local_934;
          }
        }
        if (local_870 != 2) goto LAB_00488f4b;
      }
      else {
        if (local_85c == local_870) goto LAB_00486fd1;
        if (local_860 == local_870) {
          iVar3 = Palette_Subsystem_00498a18();
          if (iVar3 == 0) {
            Glue_Subsystem_004ebfef(2);
            strcpy(&g_OverworldWorldState,s_Lost_this_card_00527590);
            Mem_AllocOrFree_00510e20(1,s_losedul2_pic_005275a0);
            Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,
                               (int *)g_DisplaySurfaceScreen,0,0,g_DisplayScreenWidth,g_DisplayScreenHeight);
            FUN_0050b206(DAT_006b2d90,0x17,0x50,1,&g_OverworldWorldState);
            App_ProcessPendingMessages();
            Ai_Subsystem_004cd1d1();
            FUN_00489630(DAT_006b2d90);
          }
          else {
            FUN_00501736(0x1e);
          }
          LoadPalNoPic(s_Prdblk_pic_005275b0);
          SelectPalette(_hdcScreen,DAT_00626834,0);
          Surface_TransformPoint(0,(short)DAT_00530d9c);
          FUN_0050d560(0,0);
          LoadPalNoPic(s_advfac64_pic_005275bc);
          FUN_0046f21e(s_dbox_spr_005275cc,0x71,0xe3);
          return 0;
        }
        if (local_864 == local_870) {
          Gold = Gold - local_83c;
          SelectPalette(_hdcScreen,DAT_00626834,0);
          Surface_TransformPoint(0,(short)DAT_00530d9c);
          LoadPalNoPic(s_advfac64_pic_005275d8);
          FUN_0046f21e(s_dbox_spr_005275e8,0x71,0xe3);
          return 0;
        }
      }
      goto LAB_00487364;
    }
    for (local_874 = 0; (int)local_874 < local_840; local_874 = local_874 + 1) {
      if (g_IsAiThinking == 0) {
        FUN_0050b206((&DAT_006b2d90)[local_874],local_874 * 0x18 + 10,local_874 * 0xc + 0x18,1,
                     &DAT_005275f4);
      }
    }
    strcpy(&g_OverworldWorldState,s_The_Evil_005275f8);
    pcVar10 = (char *)Mem_AllocOrFree_00473d7e(arg2);
    strcat(&g_OverworldWorldState,pcVar10);
    strcat(&g_OverworldWorldState,s_Wizard_has_sent_00527604);
    FUN_00488f92(arg2);
    strcat(&g_OverworldWorldState,&DAT_00527618);
    strcat(&g_OverworldWorldState,s_most_trusted_servant_to_0052761c);
    strcat(&g_OverworldWorldState,s_test_your_strength_00527638);
    strcat(&g_OverworldWorldState,s_you_must____Duel_0052764c);
    Glue_Subsystem_004eaa19((int)local_14,1,0);
    strcat(&g_OverworldWorldState,&DAT_00527660);
    App_ProcessPendingMessages();
    uVar11 = Ai_Util_004c3bc4(0x100);
    iVar3 = g_DisplayScreenWidth / 2;
    iVar4 = FUN_0050f440((int *)g_DisplaySurfaceScreen,&g_OverworldWorldState);
    FUN_00489710(&g_OverworldWorldState,(iVar3 - iVar4 / 2) + -2,uVar11);
    Glue_Subsystem_004ebebf();
LAB_00487364:
    local_c = 0;
    for (local_874 = 0; (int)local_874 < 1000; local_874 = local_874 + 1) {
      if ((&DAT_0067b9b0)[local_874] != '\0') {
        local_c = local_c + 1;
      }
    }
    local_878 = *(LPVOID *)(&DAT_006a48f0 + arg2 * 4);
    if ('\n' < (char)(&DAT_0052262a)[(int)local_14 * 0x44]) {
      local_878 = DAT_0052f000;
    }
    local_848 = *(int *)(&DAT_006a4908 + arg2 * 4);
    if ('\n' < (char)(&DAT_0052262a)[(int)local_14 * 0x44]) {
      local_848 = DAT_00626804;
    }
    iVar3 = Math_Clamp(3 - local_c / 3,0,3);
    DAT_0063ee24 = -iVar3;
    if ((DAT_0067f380 == 3) || ('\n' < (char)(&DAT_0052262a)[(int)local_14 * 0x44])) {
      DAT_0063ee24 = 0;
    }
    if ((&DAT_0052262a)[(int)local_14 * 0x44] == '\v') {
      DAT_0063ee24 = *(int *)(&DAT_005224e4 + DAT_00531590 * 0x10) / 500 + -1;
    }
    if (-DAT_0067f380 < DAT_0063ee24) {
      local_878 = DAT_0052f000;
    }
    local_8b8 = (uint)((int)(CONCAT44(DAT_0067f37c >> 0x1f,DAT_0067f37c >> 2) % 3) == 0);
    if (local_8b8 != 0) {
      Glue_Subsystem_004ebcdc(s_x_sound_dsummon_wav_00527664,0xf,100,100,0);
      if ((((&DAT_00522638)[(int)local_14 * 0x44] & 4) != 0) &&
         (iVar3 = Math_RandomRange(3), iVar3 == 0)) {
        iVar3 = Math_RandomRange(0x23);
        local_878 = (LPVOID)(iVar3 + 1);
        strcpy(&g_OverworldWorldState,s_decks_0_00527678);
        if ((*(int *)(&DAT_0052262c + (int)local_878 * 0x44) < 100) &&
           (strcat(&g_OverworldWorldState,&DAT_00527680),
           *(int *)(&DAT_0052262c + (int)local_878 * 0x44) < 10)) {
          strcat(&g_OverworldWorldState,&DAT_00527684);
        }
        pcVar10 = _itoa(*(int *)(&DAT_0052262c + (int)local_878 * 0x44),&DAT_00539d50,10);
        strcat(&g_OverworldWorldState,pcVar10);
        strcat(&g_OverworldWorldState,&DAT_00527688);
        FUN_00409f99(&g_OverworldWorldState,0,0,-1);
        DAT_0052effc = 0;
        strcpy(&g_OverworldWorldState,s_Why_don_t_you_try_this_deck__00527690);
        FUN_00489710(&g_OverworldWorldState,0xa0,0xa0);
      }
      if ((((*(uint *)(&DAT_00522638 + (int)local_14 * 0x44) & 0x110) != 0) &&
          (iVar3 = Math_RandomRange(3), iVar3 == 0)) && (-(int)local_14 != DAT_0067f2c0)) {
        do {
          do {
            iVar3 = Math_RandomRange(3);
            local_878 = (LPVOID)((int)local_14 + iVar3 + 1);
          } while (local_878 == (LPVOID)0x37);
        } while (((int)local_878 < 0x24) && ((int)local_878 % 7 == 0));
        iVar6 = 1;
        iVar5 = 0;
        iVar3 = Ai_Util_004c3bc4(10);
        iVar4 = Ai_Util_004c3bc4(0x140);
        Pic_Load_advfac64_00489188(local_878,iVar4,iVar3,iVar5,iVar6);
        g_OverworldWorldState = 0;
        Glue_Subsystem_004eaa19((int)local_14,0,0);
        strcat(&g_OverworldWorldState,s_summons_005276b0);
        Glue_Subsystem_004eaa19((int)local_878,1,0);
        strcat(&g_OverworldWorldState,&DAT_005276bc);
        FUN_00489710(&g_OverworldWorldState,0xa0,0x78);
        local_14 = local_878;
        local_880 = DAT_00695df0 + (int)(char)(&DAT_00522628)[(int)local_878 * 0x44] / 2;
      }
      if (((&DAT_00522638)[(int)local_14 * 0x44] & 0xc1) != 0) {
        DAT_006b2fe0 = Pic_Subsystem_0045268f(*(int *)(&DAT_00522640 + (int)local_14 * 0x44));
      }
      if (((&DAT_00522638)[(int)local_14 * 0x44] & 0xcb) != 0) {
        g_OverworldWorldState = 0;
        Glue_Subsystem_004eaa19((int)local_14,0,0);
        strcat(&g_OverworldWorldState,s_has_005276c0);
        local_888 = 1;
        if (((&DAT_00522638)[(int)local_14 * 0x44] & 2) != 0) {
          if (DAT_0067f37c % 3 == 0) {
            strcat(&g_OverworldWorldState,s_Mind_Control_005276c8);
          }
          else {
            local_888 = 0;
          }
        }
        if (((&DAT_00522638)[(int)local_14 * 0x44] & 8) != 0) {
          DAT_0067a6b4 = 1;
          strcat(&g_OverworldWorldState,s_First_Strike_005276d8);
        }
        if (((&DAT_00522638)[(int)local_14 * 0x44] & 0xc1) != 0) {
          if (DAT_0063ee24 < 0) {
            DAT_006b2fe0 = -1;
            local_888 = 0;
          }
          else {
            Glue_Subsystem_004eaa9c((int)s_Swamp_0051aea9[DAT_006b2fe0 * 0x34],0);
            strcat(&g_OverworldWorldState,s_Swamp_0051aea9 + DAT_006b2fe0 * 0x34);
          }
        }
        strcat(&g_OverworldWorldState,&DAT_005276e8);
        if (local_888 != 0) {
          FUN_00489710(&g_OverworldWorldState,0xb4,0x8c);
        }
      }
    }
    for (local_874 = 0; (int)local_874 < 7; local_874 = local_874 + 1) {
      if (((local_874 != arg1) && (*(int *)(&DAT_0067f2d0 + local_874 * 0x14) != 0)) &&
         ((iVar3 = FUN_0040a36f(DAT_0052eff0 - *(int *)(&DAT_0067f2d4 + local_874 * 0x14),
                                DAT_0052eff4 - *(int *)(&DAT_0067f2d8 + local_874 * 0x14)),
          iVar3 < 0x40 && (*(int *)(&DAT_0067f2d0 + local_874 * 0x14) != -1)))) {
        FUN_0046e70d(local_874,local_874 + 8);
        *(undefined4 *)(&DAT_0067f2d0 + local_874 * 0x14) = 0xffffffff;
      }
    }
    FUN_004909d3((int)local_14,local_8bc,(uint)local_878,local_848);
    Palette_Subsystem_00496eaf();
    Surface_TransformPoint(0,(short)DAT_00530d9c);
    SelectPalette(_hdcScreen,DAT_00626834,0);
    FUN_0046f21e(s_dbox_spr_005276ec,0x71,0xe3);
    Pic_Subsystem_00423c82(0);
    local_964[9] = -1;
    while (local_964[9] != 0) {
      Pic_Subsystem_00424020(0,local_964 + 9);
    }
    local_8 = Pic_Load_0044ef70(local_8bc,local_14);
    LoadPalNoPic(s_advfac64_pic_005276f8);
    if (local_8 == 1) {
      local_964[7] = 0xca;
      local_964[6] = 0x8c;
      local_964[8] = 0x118;
      Glue_Subsystem_004f0d90((&DAT_0052262a)[(int)local_14 * 0x44],(byte)arg2);
      FUN_0040b3c2(2,(uint)local_14 | 0x80);
      Glue_Subsystem_004ec98e(2,DAT_006b2d64 << 0x10 | (uint)local_14);
      if (-(int)local_14 == DAT_0067f2c0) {
        DAT_0067f2c0 = DAT_0067f2c0 + -100;
      }
      if ((char)(&DAT_0052262a)[(int)local_14 * 0x44] < '\v') {
        local_830 = FUN_0050b00c();
        local_874 = local_880;
        local_8c4 = 0;
        do {
          do {
            do {
              uVar13 = 1;
              bVar2 = Math_RandomRange(6);
              local_8bc = Pic_Subsystem_00451d90(1 << (bVar2 & 0x1f),uVar13);
              iVar3 = Pic_Subsystem_004521a6
                                (1 << ((byte)arg2 & 0x1f),
                                 (int)(char)(&DAT_0051aebe)[local_8bc * 0x34],
                                 (-(uint)((local_8c4 & 1) == 0) & 2) + 1);
            } while (iVar3 == 0);
            iVar3 = Glue_Subsystem_004f0b50(local_8bc);
          } while (((iVar3 < 1) || (((&DAT_0051aed1)[local_8bc * 0x34] & 9) != 0)) ||
                  (iVar3 = FUN_00485005(local_8bc), iVar3 == 0));
          if (((int)local_8c4 < 3) && ((&DAT_006b2dd0)[local_8c4] != -1)) {
            local_8bc = (&DAT_006b2dd0)[local_8c4];
          }
          auStack_8b0[local_8c4] = local_8bc;
          local_8c4 = local_8c4 + 1;
          uVar13 = *(uint *)(&DAT_0051aed0 + local_8bc * 0x34);
          iVar3 = Pic_Subsystem_00452551(local_8bc);
          local_874 = local_874 - (((uVar13 & 0x400) >> 10) + iVar3);
        } while (0 < (int)local_874);
        Glue_Subsystem_004ebfef(1);
        Mem_AllocOrFree_00510de0(1,s_winbak01_pic_00527708);
        Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,
                           (int *)g_DisplaySurfaceScreen,0,0,g_DisplayScreenWidth,g_DisplayScreenHeight);
        local_8c0 = (int)(300 / (longlong)(int)(local_8c4 + 1));
        for (arg1 = 0; (int)arg1 < (int)local_8c4; arg1 = arg1 + 1) {
          iVar3 = Pic_Subsystem_00452551(auStack_8b0[arg1]);
          strcpy(&g_OverworldWorldState,(char *)(&DAT_0052b73c)[iVar3]);
          pcVar10 = &g_OverworldWorldState;
          iVar4 = 1;
          iVar3 = Math_RandomRange(10);
          FUN_0050b206(auStack_8b0[arg1],
                       (local_8c0 * arg1 + 0x6f) - (int)((local_8c4 - 1) * local_8c0) / 2,
                       iVar3 + 0x10,iVar4,pcVar10);
        }
        if (local_830 == -1) {
          *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 5;
          Font_DrawTextInRect((int)g_DisplaySurfaceScreen,0xff,0x140,0x15e);
          Ai_Subsystem_004cd1d1();
          for (arg1 = 0; (int)arg1 < (int)local_8c4; arg1 = arg1 + 1) {
            local_878 = (LPVOID)Pic_Subsystem_00451e40(auStack_8b0[arg1]);
            if (local_878 != (LPVOID)0xffffffff) {
              *(uint *)(&deck + (int)local_878 * 4) = *(uint *)(&deck + (int)local_878 * 4) | 0x4000
              ;
            }
          }
        }
        else {
          local_868 = 0xcb;
          Mem_AllocOrFree_00510e20(1,s_endplak_pic_00527718);
          iVar3 = Ai_Util_004c3bc4(0x36);
          iVar4 = Ai_Util_004c3bc4(0x128);
          iVar5 = Ai_Util_004c3bc4(0x195);
          iVar6 = Ai_Util_004c3bc4(0x34);
          Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x128,0x36,
                             (int *)g_DisplaySurfaceScreen,iVar6,iVar5,iVar4,iVar3);
          g_OverworldWorldState = 0;
          FUN_0048e2b0(local_830);
          FUN_0040c336(&g_OverworldWorldState,100,local_868 + 3,0xca);
          local_868 = local_868 + 9;
          g_OverworldWorldState = 0;
          for (local_874 = 0; (int)local_874 < 3; local_874 = local_874 + 1) {
            if (*(int *)(&DAT_0067eff0 + local_874 * 4 + local_830 * 0x30) != -1) {
              if (local_874 != 0) {
                strcat(&g_OverworldWorldState,&DAT_00527724);
              }
              strcat(&g_OverworldWorldState,
                     s_Swamp_0051aea9 +
                     *(int *)(&DAT_0067eff0 + local_874 * 4 + local_830 * 0x30) * 0x34);
            }
          }
          FUN_0040c2e9(&g_OverworldWorldState,100,local_868,0xca);
          local_868 = local_868 + 7;
          local_878 = (LPVOID)0x0;
          for (local_874 = 0; (int)local_874 < 4; local_874 = local_874 + 1) {
            if ((*(uint *)(&DAT_0067f010 + local_830 * 0x30) & 1 << ((byte)local_874 & 0x1f)) != 0)
            {
              local_878 = (LPVOID)((int)local_878 + 1);
            }
          }
          if (local_878 == (LPVOID)0x0) {
            strcpy(&g_OverworldWorldState,s__first_clue__00527728);
          }
          else if (local_878 == (LPVOID)0x1) {
            strcpy(&g_OverworldWorldState,s__second_clue__00527738);
          }
          else if (local_878 == (LPVOID)0x2) {
            strcpy(&g_OverworldWorldState,s__third_clue__00527748);
          }
          FUN_0040c2e9(&g_OverworldWorldState,100,local_868,200);
          strcpy(&g_OverworldWorldState,s_You_have_defeated_the_slimy_00527758);
          Glue_Subsystem_004eaa19((int)local_14,0,0);
          strcat(&g_OverworldWorldState,s___Will_you____Take_the_cards__Ta_00527778);
          FUN_0050afbd();
          iVar3 = FUN_004896be(&g_OverworldWorldState,0x40,0x7c);
          if (iVar3 == 0) {
            if (local_830 != -1) {
              *(uint *)(&DAT_0067f014 + local_830 * 0x30) =
                   *(uint *)(&DAT_0067f014 + local_830 * 0x30) | 0x200;
            }
            for (arg1 = 0; (int)arg1 < (int)local_8c4; arg1 = arg1 + 1) {
              local_878 = (LPVOID)Pic_Subsystem_00451e40(auStack_8b0[arg1]);
              if (local_878 != (LPVOID)0xffffffff) {
                *(uint *)(&deck + (int)local_878 * 4) =
                     *(uint *)(&deck + (int)local_878 * 4) | 0x4000;
              }
            }
          }
          else {
            FUN_0048ea81(local_830);
          }
        }
        App_ProcessPendingMessages();
        local_10 = *(uint *)(&DAT_0052263c + (int)local_14 * 0x44);
        if (local_8b8 == 0) {
          local_10 = 0;
        }
        iVar3 = Math_RandomRange(0x28);
        if (iVar3 < (int)local_880) {
          local_964[1] = 2;
          local_964[2] = 1;
          local_964[3] = 4;
          local_964[4] = 3;
          local_964[5] = 0;
          *(int *)(&DAT_0067bdbc + arg2 * 4) = *(int *)(&DAT_0067bdbc + arg2 * 4) + 1;
          Mem_AllocOrFree_00510e20(1,s_winbak02_pic_005277c4);
          Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,
                             (int *)g_DisplaySurfaceScreen,0,0,g_DisplayScreenWidth,g_DisplayScreenHeight);
          App_ProcessPendingMessages();
          strcpy(&g_OverworldWorldState,s_Won_this_Amulet__005277d4);
          local_964[0] = FUN_0050f440((int *)g_DisplaySurfaceScreen,&g_OverworldWorldState);
          iVar7 = 0;
          iVar3 = Ai_Util_004c3bc4(0x30);
          iVar3 = iVar3 + 0xe;
          iVar4 = local_964[0] + 0x10;
          iVar5 = Ai_Util_004c3bc4(0xa0);
          iVar6 = Ai_Util_004c3bc4(0xa0);
          FUN_0048a3cc((iVar6 - local_964[0] / 2) + -8,iVar5,iVar4,iVar3,iVar7);
          iVar3 = Ai_Util_004c3bc4(0xae);
          iVar4 = Ai_Util_004c3bc4(0xa0);
          FUN_0040d269((int)g_DisplaySurfaceScreen,0xff,iVar4,iVar3);
          iVar3 = (&DAT_006776a0)[local_964[arg2]];
          iVar4 = Ai_Util_004c3bc4(0x22);
          iVar5 = Ai_Util_004c3bc4(0x1a);
          iVar6 = Ai_Util_004c3bc4(0xbd);
          iVar7 = Ai_Util_004c3bc4(0xa0);
          iVar8 = Ai_Util_004c3bc4(0xd);
          Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,iVar7 - iVar8,iVar6,iVar5,iVar4,iVar3);
          if (local_10 == 0) {
            App_ProcessPendingMessages();
            Ai_Subsystem_004cd1d1();
          }
        }
        else if ((local_10 == 0) && (local_8b8 != 0)) {
          bVar2 = Math_RandomRange(0xc);
          local_10 = 1 << (bVar2 & 0x1f) & 0x1a19;
        }
        if (local_10 != 0) {
          Glue_Subsystem_004ebcdc(s_x_sound_treasure_wav_0052783c,0xf,100,100,0);
          Mem_AllocOrFree_00510e20(1,s_winbak02_pic_00527854);
          Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,
                             (int *)g_DisplaySurfaceScreen,0,0,g_DisplayScreenWidth,g_DisplayScreenHeight);
          iVar6 = 0;
          iVar5 = 1;
          iVar3 = Ai_Util_004c3bc4(0x23);
          iVar4 = Ai_Util_004c3bc4(local_964[6]);
          Pic_Load_advfac64_00489188(local_14,iVar4,iVar3,iVar5,iVar6);
          *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 4;
          g_OverworldWorldState = 0;
          strcpy(&g_OverworldWorldState,s_You_are_00527864);
          strcat(&g_OverworldWorldState,(&PTR_s_an_Adequate_Apprentice_00527100)[DAT_0067f380]);
          strcat(&g_OverworldWorldState,&DAT_00527870);
          strcat(&g_OverworldWorldState,s_says_the_00527874);
          Glue_Subsystem_004eaa19((int)local_14,0,0);
          strcat(&g_OverworldWorldState,&DAT_00527880);
          Font_DrawTextInRect((int)g_DisplaySurfaceScreen,local_964[7],local_964[6],local_964[8]);
          local_964[8] = local_964[8] + 0x28;
          strcpy(&g_OverworldWorldState,s_You_get_00527884);
        }
        if (((local_10 & 1) != 0) && (g_PlayerCreatureCount != DAT_00627868)) {
          DAT_00627a7c = g_PlayerCreatureCount - DAT_00627868;
          strcat(&g_OverworldWorldState,s_your_lives___00527890);
          pcVar10 = _itoa(g_PlayerCreatureCount,&DAT_00539d50,10);
          strcat(&g_OverworldWorldState,pcVar10);
          strcat(&g_OverworldWorldState,s___carried_over_to_the_next_duel__005278a0);
          Font_DrawTextInRect((int)g_DisplaySurfaceScreen,local_964[7],local_964[6],local_964[8]);
        }
        if ((local_10 & 0x800) != 0) {
          iVar3 = Math_RandomRange(4);
          DAT_00522454 = (LPVOID)(iVar3 + 1);
          strcat(&g_OverworldWorldState,&DAT_005278c4);
          pcVar10 = _itoa((int)DAT_00522454,&DAT_00539d50,10);
          strcat(&g_OverworldWorldState,pcVar10);
          strcat(&g_OverworldWorldState,s_lives_in_next_duel__005278c8);
          Font_DrawTextInRect((int)g_DisplaySurfaceScreen,local_964[7],local_964[6],local_964[8]);
        }
        if ((local_10 & 0x402) != 0) {
          do {
            local_844 = Math_RandomRange(0x40);
            local_868 = Math_RandomRange(0x40);
            iVar3 = Surface_GetPixelColor(local_844, local_868);
          } while (iVar3 == 0);
          DAT_0052eff0 = local_844 * 0x20 + 0x10;
          DAT_0052eff4 = local_868 * 0x20 + 0x10;
          DAT_00641884 = 0;
          Font_DrawTextInRect((int)g_DisplaySurfaceScreen,local_964[7],local_964[6],local_964[8]);
        }
        if ((local_10 & 4) != 0) {
          DAT_00522454 = (LPVOID)Pic_Subsystem_0045268f
                                           (*(int *)(&DAT_00522640 + (int)local_14 * 0x44));
          local_878 = (LPVOID)Pic_Subsystem_00451e40((uint)DAT_00522454);
          if (local_878 != (LPVOID)0xffffffff) {
            *(uint *)(&deck + (int)local_878 * 4) = *(uint *)(&deck + (int)local_878 * 4) | 0x4000;
          }
          strcpy(&g_OverworldWorldState,s_You_won_005278ec);
          Glue_Subsystem_004eaa9c((int)s_Swamp_0051aea9[(int)DAT_00522454 * 0x34],0);
          strcat(&g_OverworldWorldState,s_Swamp_0051aea9 + (int)DAT_00522454 * 0x34);
          FUN_0050b206((int)DAT_00522454,0xa0,0x70,1,&g_OverworldWorldState);
          DAT_00522454 = (LPVOID)0xffffffff;
        }
        if ((local_10 & 0x10) != 0) {
          DAT_00522454 = (LPVOID)0x0;
          Font_DrawTextInRect((int)g_DisplaySurfaceScreen,local_964[7],local_964[6],local_964[8]);
        }
        if ((local_10 & 0x20) != 0) {
          DAT_00522454 = (LPVOID)Pic_Subsystem_0045268f
                                           (*(int *)(&DAT_00522640 + (int)local_14 * 0x44));
          strcat(&g_OverworldWorldState,s_Swamp_0051aea9 + (int)DAT_00522454 * 0x34);
          strcat(&g_OverworldWorldState,s_in_the_next_duel__00527920);
          FUN_0050b206((int)DAT_00522454,0xa0,0x70,1,&g_OverworldWorldState);
        }
        if ((local_10 & 0x180) != 0) {
          do {
            do {
              local_878 = (LPVOID)Math_RandomRange(g_MasterCardCount + -0x29);
            } while (((&g_MasterCardColorTable)[(int)local_878 * 0x34] & 0x42) != 0x40);
          } while (((int)local_878 < 5) || (iVar3 = FUN_00485005((int)local_878), iVar3 == 0));
          DAT_00522454 = local_878;
          Glue_Subsystem_004eaa9c((int)s_Swamp_0051aea9[(int)local_878 * 0x34],0);
          strcat(&g_OverworldWorldState,s_Swamp_0051aea9 + (int)DAT_00522454 * 0x34);
          strcat(&g_OverworldWorldState,s_in_the_next_duel__00527934);
          FUN_0050b206((int)DAT_00522454,0xa0,0x70,1,&g_OverworldWorldState);
        }
        if ((local_10 & 0x200) != 0) {
          iVar3 = Math_RandomRange(0x1e);
          DAT_00522448 = DAT_00522448 + iVar3 + 0x14;
          strcat(&g_OverworldWorldState,s_Extra_FOOD__00527948);
          Font_DrawTextInRect((int)g_DisplaySurfaceScreen,local_964[7],local_964[6],local_964[8]);
        }
        if ((local_10 & 0x40) != 0) {
          strcat(&g_OverworldWorldState,s_any_card_of_your_choice__00527954);
          Font_DrawTextInRect((int)g_DisplaySurfaceScreen,local_964[7],local_964[6],local_964[8]);
          Ai_Subsystem_004cd1d1();
          Glue_Subsystem_004ead96(1);
          local_8bc = Palette_Color_0049716e(s_Pick_a_card_00527970,0,0xffffffff,1,0);
          while (local_8bc == 0xffffffff) {
            local_8bc = Palette_Color_0049716e(s_Pick_a_card_0052797c,0,0xffffffff,0,0);
          }
          if (local_8bc != 0xffffffff) {
            iVar3 = Pic_Subsystem_00451e40(local_8bc);
            *(uint *)(&deck + iVar3 * 4) = *(uint *)(&deck + iVar3 * 4) | 0x4000;
          }
          local_10 = 0;
        }
        if ((local_10 & 0x1000) != 0) {
          strcat(&g_OverworldWorldState,s_a_duplicate_card_of_your_choice__00527988);
          Font_DrawTextInRect((int)g_DisplaySurfaceScreen,local_964[7],local_964[6],local_964[8]);
          Ai_Subsystem_004cd1d1();
          Glue_Subsystem_004ead96(1);
          for (arg1 = 0; (int)arg1 < 500; arg1 = arg1 + 1) {
            local_82c[arg1] = *(uint *)(&deck + arg1 * 4);
            if (local_82c[arg1] != 0xffffffff) {
              local_82c[arg1] = local_82c[arg1] & 0xfff;
            }
          }
          local_8bc = Pic_Load_004509e8(g_CurrentTurnPhase,(int)local_82c,500,s_Pick_a_card_005279b0
                                        ,1);
          if (local_8bc != 0xffffffff) {
            iVar3 = Pic_Subsystem_00451e40(local_82c[local_8bc]);
            *(uint *)(&deck + iVar3 * 4) = *(uint *)(&deck + iVar3 * 4) | 0x4000;
          }
          local_10 = 0;
        }
        if ((local_10 & 8) != 0) {
          strcat(&g_OverworldWorldState,s_Extra_GOLD__005279bc);
          Font_DrawTextInRect((int)g_DisplaySurfaceScreen,local_964[7],local_964[6],local_964[8]);
          Gold = Gold + 100;
        }
        App_ProcessPendingMessages();
        if (local_10 != 0) {
          Ai_Subsystem_004cd1d1();
        }
        iVar3 = Math_RandomRange((int)(0x40 / (longlong)(DAT_0067f380 + 1)));
        if (iVar3 < (int)local_880) {
          *(LPVOID *)(&DAT_006a48f0 + arg2 * 4) = DAT_0052f000;
        }
        iVar3 = Math_RandomRange((int)(0x80 / (longlong)(DAT_0067f380 + 1)));
        if (iVar3 < (int)local_880) {
          *(int *)(&DAT_006a4908 + arg2 * 4) = DAT_00626804;
        }
      }
    }
    if (local_8 == 0) {
      Glue_Subsystem_004ebfef(2);
      Mem_AllocOrFree_00510e20(1,s_losedul2_pic_005279c8);
      Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,
                         (int *)g_DisplaySurfaceScreen,0,0,g_DisplayScreenWidth,g_DisplayScreenHeight);
      FUN_0040b3c2(2,local_14);
      for (local_884 = 0; local_884 < 3; local_884 = local_884 + 1) {
        Math_Clamp((Gold / 0x28) * 10,0,100);
        local_878 = (LPVOID)0x0;
        local_87c = (&DAT_006b2d90)[local_884];
        if (local_87c != 0xffffffff) {
          strcpy(&g_OverworldWorldState,s_Lost_this_card_005279d8);
          if (local_878 != (LPVOID)0x0) {
            strcat(&g_OverworldWorldState,s_and_005279e8);
            pcVar10 = _itoa((int)local_878,&DAT_00539d50,10);
            strcat(&g_OverworldWorldState,pcVar10);
            strcat(&g_OverworldWorldState,s_gold__005279f0);
          }
          FUN_0050b206(local_87c,0x17,0x50,1,&g_OverworldWorldState);
          App_ProcessPendingMessages();
          Ai_Subsystem_004cd1d1();
          FUN_00489630(local_87c);
        }
      }
    }
    if (local_8 == -1) {
      Mem_AllocOrFree_00510e20(1,s_losedul2_pic_005279f8);
      Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,
                         (int *)g_DisplaySurfaceScreen,0,0,g_DisplayScreenWidth,g_DisplayScreenHeight);
      iVar5 = 0;
      iVar4 = 1;
      iVar3 = Ai_Util_004c3bc4(0x3c);
      Pic_Load_advfac64_00489188
                (local_14,(int)(g_DisplayScreenWidth + (g_DisplayScreenWidth >> 0x1f & 3U)) >> 2,iVar3,iVar4,iVar5);
      *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 4;
      strcpy(&g_OverworldWorldState,s_The_people_are_disappointed_you_c_00527a08);
      Glue_Subsystem_004eaa19((int)local_14,0,0);
      iVar3 = Ai_Util_004c3bc4(300);
      FUN_0040d201((int)g_DisplaySurfaceScreen,0xca,
                   (int)(g_DisplayScreenWidth + (g_DisplayScreenWidth >> 0x1f & 3U)) >> 2,iVar3);
      iVar3 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
      iVar3 = Ai_Util_004c3bc4(iVar3 * 4 + 300);
      FUN_0040d201((int)g_DisplaySurfaceScreen,0xca,
                   (int)(g_DisplayScreenWidth + (g_DisplayScreenWidth >> 0x1f & 3U)) >> 2,iVar3);
      App_ProcessPendingMessages();
      Ai_Subsystem_004cd1d1();
    }
  }
LAB_00488f4b:
  FUN_0046f21e(s_dbox_spr_00527a78,0x71,0xe3);
  SelectPalette(_hdcScreen,DAT_00626834,0);
  LoadPalNoPic(s_advfac64_pic_00527a84);
  App_ProcessPendingMessages();
  return local_8;
LAB_00486fd1:
  do {
    do {
      local_878 = (LPVOID)Math_RandomRange(500);
    } while (*(int *)(&deck + (int)local_878 * 4) == -1);
  } while ((((&DAT_00702151)[(int)local_878 * 4] & 0x40) != 0) ||
          ((*(uint *)(&deck + (int)local_878 * 4) & 0xfff) < 5));
  DAT_006b2d90 = *(uint *)(&deck + (int)local_878 * 4) & 0xfff;
  local_86c = 1;
  local_850 = 0;
  goto LAB_0048627e;
}

/*
 * Decompiled function: Castle_Process_0048f523
 * Entry Point: 0048f523
 * Size: 5156 bytes
 */


void Castle_Process_0048f523(void)

{
  byte bVar1;
  undefined4 uVar2;
  void *pvVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  DWORD arg_5;
  uint arg_2;
  int iVar9;
  void **ppvVar10;
  bool bVar11;
  int local_1528;
  int local_14c8;
  int local_14c0;
  int local_14bc;
  int local_14b0;
  void *local_14ac [50];
  uint auStackY_13e4 [15];
  uint auStackY_13a8 [50];
  undefined4 local_12e0;
  uint local_12dc;
  uint local_12d4;
  int local_12d0;
  uint local_12cc;
  int local_12c8;
  char acStackY_12c4 [4744];
  undefined4 uStackY_3c;
  int *arg_6;
  
  Mem_AllocOrFree_00513bd0();
  local_12dc = 0;
  local_12c8 = 0;
  local_14c8 = 0;
  local_14ac[0] = (void *)0x0;
  ppvVar10 = local_14ac;
  for (iVar9 = 0x31; ppvVar10 = ppvVar10 + 1, iVar9 != 0; iVar9 = iVar9 + -1) {
    *ppvVar10 = (void *)0x0;
  }
  Mem_AllocOrFree_00510e20(1,s_dun_bar_pic_0052855c);
  Mem_AllocOrFree_0050fc00();
  DAT_00676bd0 = (void *)Sprite_EncodeFromSurface(1,2,1,0xd,0x70);
  for (local_14b0 = 0; local_14b0 < 3; local_14b0 = local_14b0 + 1) {
    uVar2 = Sprite_EncodeFromSurface(1,local_14b0 * 0x3c + 0x10,1,0x3b,0x1a);
    *(undefined4 *)(&DAT_00676bc0 + local_14b0 * 4) = uVar2;
  }
  for (local_14bc = 0; local_14bc < 2; local_14bc = local_14bc + 1) {
    for (local_14b0 = 0; local_14b0 < 4; local_14b0 = local_14b0 + 1) {
      uVar2 = Sprite_EncodeFromSurface
                        (1,local_14bc * 0x80 + local_14b0 * 0x20 + 0x10,0x1c,0x1f,0x24);
      *(undefined4 *)(&DAT_00676ba0 + local_14b0 * 4 + local_14bc * 0x10) = uVar2;
    }
  }
  FUN_0050fc20();
  if (DAT_00528000 == DAT_00527ff0) {
    for (local_14b0 = 0; local_14b0 < 3; local_14b0 = local_14b0 + 1) {
      uVar2 = Ai_Util_004c3bc4((&DAT_00528000)[local_14b0 * 0x15]);
      (&DAT_00528000)[local_14b0 * 0x15] = uVar2;
      uVar2 = Ai_Util_004c3bc4(*(int *)(&DAT_00528004 + local_14b0 * 0x54));
      *(undefined4 *)(&DAT_00528004 + local_14b0 * 0x54) = uVar2;
      uVar2 = Ai_Util_004c3bc4(*(int *)(&DAT_00528008 + local_14b0 * 0x54));
      *(undefined4 *)(&DAT_00528008 + local_14b0 * 0x54) = uVar2;
      uVar2 = Ai_Util_004c3bc4(*(int *)(&DAT_0052800c + local_14b0 * 0x54));
      *(undefined4 *)(&DAT_0052800c + local_14b0 * 0x54) = uVar2;
    }
  }
  FUN_00510b70(1,0,g_DisplayScreenHeight - 0x1e0,s_dung_bd_pic_00528568,(short *)0x0);
  uStackY_3c = 0x48f7d7;
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,g_DisplayScreenHeight - 0x1e0,0x280,0x1e0,
                     (int *)g_DisplaySurfaceBackBuffer,0,0,g_DisplayScreenWidth,g_DisplayScreenHeight);
  Surface_BlitToDevice((int *)g_DisplaySurfaceBackBuffer,0,0,g_DisplayScreenWidth,g_DisplayScreenHeight,
               (int *)g_DisplaySurfaceScreen,0,0);
  Mem_AllocOrFree_0050fc00();
  for (local_12cc = 0; (int)local_12cc < 0xf; local_12cc = local_12cc + 1) {
    local_12e0 = 0;
    if (((*(int *)(&DAT_0067f010 + local_12cc * 0x30) != 0) || (DAT_0067b9a4 != 0)) &&
       (((int)local_12cc < 5 ||
        ((*(int *)(&DAT_0067eff0 + local_12cc * 0x30) != -1 || (DAT_0067b9a4 != 0)))))) {
      auStackY_13a8[local_12c8] = local_12cc;
      if ((((&DAT_0067f010)[local_12cc * 0x30] & 1) != 0) || (DAT_0067b9a4 != 0)) {
        if ((int)local_12cc < 5) {
          Ai_Util_004c3bc4(0x3e);
          Ai_Util_004c3bc4(0x3e);
          pvVar3 = (void *)FUN_0048ee42();
          local_14ac[local_12c8] = pvVar3;
        }
        else {
          Ai_Util_004c3bc4(0x3e);
          Ai_Util_004c3bc4(0x3e);
          pvVar3 = (void *)FUN_0048ee42();
          local_14ac[local_12c8] = pvVar3;
        }
      }
      local_12c8 = local_12c8 + 1;
    }
  }
  FUN_0050fc20();
  local_12d0 = 1;
  iVar9 = FUN_0041f354();
  Mem_AllocOrFree_0041f12b(iVar9);
  FUN_0041f17e(0x527ff0,3,iVar9);
  Mem_AllocOrFree_0041f159(0);
LAB_0048fa24:
  if (local_12d0 == 0) {
    FUN_00510b70(1,0,g_DisplayScreenHeight - 0x1e0,s_dung_bd_pic_00528574,(short *)0x0);
    uStackY_3c = 0x48fa87;
    Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,g_DisplayScreenHeight - 0x1e0,0x280,0x1e0,
                       (int *)g_DisplaySurfaceBackBuffer,0,0,g_DisplayScreenWidth,g_DisplayScreenHeight);
    Surface_BlitToDevice((int *)g_DisplaySurfaceBackBuffer,0,0,g_DisplayScreenWidth,g_DisplayScreenHeight,
                 (int *)g_DisplaySurfaceScreen,0,0);
  }
  local_12d0 = 0;
  do {
    if (local_12c8 < 0xd) {
      FUN_0041ece4(0x527ff0);
      FUN_0041ece4(0x528044);
    }
    else {
      if (local_14c8 == 0) {
        FUN_0041ece4(0x527ff0);
      }
      else {
        FUN_0041ed3a(0x527ff0);
      }
      if (local_14c8 + 0xc < local_12c8) {
        FUN_0041ed3a(0x528044);
      }
      else {
        FUN_0041ece4(0x528044);
      }
    }
    FUN_0041f213();
    FUN_00510b70(1,0,g_DisplayScreenHeight - 0x1e0,s_dung_bd_pic_00528580,(short *)0x0);
    uStackY_3c = 0x48fbaf;
    Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,g_DisplayScreenHeight - 0x1e0,0x280,0x1e0,
                       (int *)g_DisplaySurfaceBackBuffer,0,0,g_DisplayScreenWidth,g_DisplayScreenHeight);
    *(undefined4 *)g_DisplaySurfaceScreen = 1;
    local_12dc = 0;
    *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 1;
    local_14bc = local_14c8;
    while( true ) {
      iVar9 = local_14c8 + 0xc;
      if (local_12c8 <= local_14c8 + 0xc) {
        iVar9 = local_12c8;
      }
      if (iVar9 <= local_14bc) break;
      local_12cc = auStackY_13a8[local_14bc];
      local_12e0 = 0;
      if (((*(int *)(&DAT_0067f010 + local_12cc * 0x30) != 0) || (DAT_0067b9a4 != 0)) &&
         (((int)local_12cc < 5 ||
          ((*(int *)(&DAT_0067eff0 + local_12cc * 0x30) != -1 || (DAT_0067b9a4 != 0)))))) {
        auStackY_13e4[local_12dc] = local_12cc;
        g_OverworldWorldState = 0;
        FUN_0048e2b0(local_12cc);
        if ((int)local_12cc < 5) {
          strcat(&g_OverworldWorldState,&DAT_0052858c);
          pcVar4 = (char *)Mem_AllocOrFree_00473d7e(local_12cc + 1);
          strcat(&g_OverworldWorldState,pcVar4);
          strcat(&g_OverworldWorldState,s_Castle__00528590);
        }
        iVar9 = Ai_Util_004c3bc4((-(uint)((local_12dc & 1) == 0) & 0xfffffef9) + 0x19b);
        iVar5 = Ai_Util_004c3bc4(((int)local_12dc / 2) * 0x3e + 0x69);
        iVar6 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
        FUN_0040cf6d((int)g_DisplaySurfaceScreen,0xff,iVar9,iVar5 - iVar6 / 2);
        strcpy(acStackY_12c4 + local_12dc * 0x30,&g_OverworldWorldState);
        g_OverworldWorldState = 0;
        if ((((&DAT_0067f010)[local_12cc * 0x30] & 1) != 0) || (DAT_0067b9a4 != 0)) {
          if (*(int *)(&DAT_0067f004 + local_12cc * 0x30) -
              *(int *)(&DAT_0067bdf8 + *(int *)(&DAT_0067f008 + local_12cc * 0x30) * 100) < 1) {
            strcpy(&g_OverworldWorldState,
                   &DAT_005285a4 +
                   ((0 < *(int *)(&DAT_0067f000 + local_12cc * 0x30) -
                         *(int *)(&DAT_0067bdf4 + *(int *)(&DAT_0067f008 + local_12cc * 0x30) * 100)
                    ) - 1 & 4));
          }
          else {
            strcpy(&g_OverworldWorldState,
                   &DAT_0052859c +
                   ((0 < *(int *)(&DAT_0067f000 + local_12cc * 0x30) -
                         *(int *)(&DAT_0067bdf4 + *(int *)(&DAT_0067f008 + local_12cc * 0x30) * 100)
                    ) - 1 & 4));
          }
          strcat(&g_OverworldWorldState,&DAT_005285ac);
          Ai_TownEncounter_004c3b19(*(uint *)(&DAT_0067f008 + local_12cc * 0x30));
          strcat(&g_OverworldWorldState,&DAT_005285b0);
          uVar7 = FUN_0040c7c0(*(int *)(&DAT_0067bdf4 +
                                       *(int *)(&DAT_0067f008 + local_12cc * 0x30) * 100),
                               *(int *)(&DAT_0067bdf8 +
                                       *(int *)(&DAT_0067f008 + local_12cc * 0x30) * 100));
          if ((uVar7 & 0x80) != 0) {
            local_12e0 = 1;
          }
          if ((int)local_12cc < 5) {
            iVar9 = Ai_Util_004c3bc4((-(uint)((local_12dc & 1) == 0) & 0xfffffef9) + 0x15b);
            iVar5 = Ai_Util_004c3bc4(((int)local_12dc / 2) * 0x3e + 0x49);
            pvVar3 = local_14ac[local_14bc];
            iVar6 = Ai_Util_004c3bc4(0x3e);
            iVar8 = Ai_Util_004c3bc4(0x3e);
            FUN_0048efc7(g_DisplaySurfaceScreen,iVar9,iVar5,iVar8,iVar6,(int)pvVar3);
          }
          else {
            iVar9 = Ai_Util_004c3bc4((-(uint)((local_12dc & 1) == 0) & 0xfffffef9) + 0x15b);
            iVar5 = Ai_Util_004c3bc4(((int)local_12dc / 2) * 0x3e + 0x49);
            pvVar3 = local_14ac[local_14bc];
            iVar6 = Ai_Util_004c3bc4(0x3e);
            iVar8 = Ai_Util_004c3bc4(0x3e);
            FUN_0048efc7(g_DisplaySurfaceScreen,iVar9,iVar5,iVar8,iVar6,(int)pvVar3);
          }
        }
        local_12dc = local_12dc + 1;
        if ((((&DAT_0067f010)[local_12cc * 0x30] & 2) != 0) || (DAT_0067b9a4 != 0)) {
          if ((int)local_12cc < 5) {
            bVar1 = FUN_0049094c();
            (&DAT_0067f00d)[local_12cc * 0x30] = bVar1 | 0x80;
          }
          strcat(&g_OverworldWorldState,
                 &DAT_005285b4 + ((((&DAT_0067f00d)[local_12cc * 0x30] & 0x80) != 0) - 1 & 4));
          pcVar4 = (char *)Mem_AllocOrFree_00473d7e((int)(char)(&DAT_0067f00c)[local_12cc * 0x30]);
          strcat(&g_OverworldWorldState,pcVar4);
          strcat(&g_OverworldWorldState,&DAT_005285bc);
        }
        if ((((&DAT_0067f010)[local_12cc * 0x30] & 4) != 0) || (DAT_0067b9a4 != 0)) {
          if (((&DAT_0067f014)[local_12cc * 0x30] & 0x10) != 0) {
            strcat(&g_OverworldWorldState,s_xColor_005285c0);
          }
          if (((&DAT_0067f014)[local_12cc * 0x30] & 0x20) != 0) {
            strcat(&g_OverworldWorldState,s_1deck_005285c8);
          }
          if (((&DAT_0067f014)[local_12cc * 0x30] & 0x40) != 0) {
            strcat(&g_OverworldWorldState,s_xArtifacts_005285d0);
          }
          if (((&DAT_0067f014)[local_12cc * 0x30] & 0x80) != 0) {
            strcat(&g_OverworldWorldState,s_xInstants_005285dc);
          }
          if (((&DAT_0067f014)[local_12cc * 0x30] & 1) != 0) {
            strcat(&g_OverworldWorldState,s__Life_005285e8);
          }
          if (((&DAT_0067f014)[local_12cc * 0x30] & 2) != 0) {
            strcat(&g_OverworldWorldState,s__Life_005285f0);
          }
          if (*(int *)(&DAT_0067effc + local_12cc * 0x30) == -1) {
            if (*(int *)(&DAT_0067f014 + local_12cc * 0x30) == 0) {
              strcat(&g_OverworldWorldState,s_xRules_005285f8);
            }
          }
          else {
            iVar9 = Pic_Subsystem_0045268f(*(int *)(&DAT_0067effc + local_12cc * 0x30));
            strcat(&g_OverworldWorldState,s_Swamp_0051aea9 + iVar9 * 0x34);
          }
        }
      }
      local_14bc = local_14bc + 1;
    }
    *(undefined4 *)g_DisplaySurfaceScreen = 0;
    iVar9 = Ai_Util_004c3bc4(0x46);
    iVar5 = Ai_Util_004c3bc4(0x50);
    arg_6 = (int *)g_DisplaySurfaceScreen;
    arg_5 = Ai_Util_004c3bc4(0x17a);
    uVar7 = Ai_Util_004c3bc4(0x208);
    iVar6 = Ai_Util_004c3bc4(0x46);
    arg_2 = Ai_Util_004c3bc4(0x50);
    Surface_BlitToDevice((int *)g_DisplaySurfaceBackBuffer,arg_2,iVar6,uVar7,arg_5,arg_6,iVar5,iVar9);
    DAT_0054aae0 = -5;
    local_12d4 = 0xffffffff;
    while( true ) {
      do {
        if (DAT_0054aae0 != -5) {
          App_ProcessPendingMessages();
          FUN_0041f391();
          Mem_AllocOrFree_0050fc50(DAT_00676bd0);
          if ((local_12c8 != 0) && (local_14ac[0] != (void *)0x0)) {
            Mem_AllocOrFree_0050fc50(local_14ac[0]);
          }
          return;
        }
        local_12cc = 0xffffffff;
        Pic_Subsystem_0044b84b();
        if (DAT_007039c4 == 0) {
          iVar9 = (DAT_0067bda8 * 0x1e0) / (int)g_DisplayScreenHeight;
          iVar5 = (DAT_0067bda4 * 0x280) / (int)g_DisplayScreenWidth;
          iVar6 = FUN_0048edeb(iVar5,iVar9,0x54,0x49,0xfb,0x174);
          if (iVar6 == 0) {
            iVar5 = FUN_0048edeb(iVar5,iVar9,0x15b,0x49,0xfd,0x174);
            if (iVar5 != 0) {
              local_12cc = ((iVar9 + -0x49) / 0x3e) * 2 + 1;
            }
          }
          else {
            local_12cc = ((iVar9 + -0x49) / 0x3e) * 2;
          }
          if (((-1 < (int)local_12cc) && ((int)local_12cc < (int)local_12dc)) &&
             (local_12cc != local_12d4)) {
            if (local_12d4 != 0xffffffff) {
              iVar9 = Ai_Util_004c3bc4((-(uint)((local_12d4 & 1) == 0) & 0xfffffef9) + 0x19b);
              iVar5 = Ai_Util_004c3bc4(((int)local_12d4 / 2) * 0x3e + 0x69);
              iVar6 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
              FUN_0040cf6d((int)g_DisplaySurfaceScreen,0xff,iVar9,iVar5 - iVar6 / 2);
            }
            iVar9 = Ai_Util_004c3bc4((-(uint)((local_12cc & 1) == 0) & 0xfffffef9) + 0x19b);
            iVar5 = Ai_Util_004c3bc4(((int)local_12cc / 2) * 0x3e + 0x69);
            iVar6 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
            FUN_0040cf6d((int)g_DisplaySurfaceScreen,0xe3,iVar9,iVar5 - iVar6 / 2);
            local_12d4 = local_12cc;
          }
        }
        else {
          iVar9 = (DAT_0067bda8 * 0x1e0) / (int)g_DisplayScreenHeight;
          iVar5 = (DAT_0067bda4 * 0x280) / (int)g_DisplayScreenWidth;
          iVar6 = FUN_0048edeb(iVar5,iVar9,0x54,0x49,0xfb,0x174);
          if (iVar6 == 0) {
            iVar5 = FUN_0048edeb(iVar5,iVar9,0x15b,0x49,0xfd,0x174);
            if (iVar5 != 0) {
              local_12cc = ((iVar9 + -0x49) / 0x3e) * 2 + 1;
            }
          }
          else {
            local_12cc = ((iVar9 + -0x49) / 0x3e) * 2;
          }
          if ((-1 < (int)local_12cc) && ((int)local_12cc < (int)local_12dc)) {
            iVar9 = Ai_Util_004c3bc4((-(uint)((local_12cc & 1) == 0) & 0xfffffef9) + 0x19b);
            iVar5 = Ai_Util_004c3bc4(((int)local_12cc / 2) * 0x3e + 0x69);
            iVar6 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
            FUN_0040cf6d((int)g_DisplaySurfaceScreen,0xbe,iVar9,iVar5 - iVar6 / 2);
            App_ProcessPendingMessages();
            Castle_Process_00492ddf(auStackY_13e4[local_12cc]);
            goto LAB_0048fa24;
          }
        }
        local_14c0 = -1;
        FUN_0041f3ea(DAT_0067bda4,DAT_0067bda8,DAT_007039c4);
        if (DAT_0054aae0 != -5) {
          if (DAT_0054aae0 == -1) {
            local_14c0 = 0x4800;
          }
          else if (DAT_0054aae0 == 1) {
            local_14c0 = 0x5000;
          }
          if (DAT_0054aae0 != 0) {
            DAT_0054aae0 = -5;
          }
        }
      } while ((local_12c8 < 0xd) || ((local_14c0 != 0x4800 && (local_14c0 != 0x5000))));
      if (local_14c0 == 0x4800) {
        local_1528 = -1;
      }
      else {
        local_1528 = 1;
      }
      iVar9 = local_14c8 + local_1528 * 2;
      if (iVar9 < 1) {
        iVar9 = 0;
      }
      iVar5 = (local_12c8 + 2U & 0xfffffffe) - 0xc;
      if (iVar9 <= iVar5) {
        iVar5 = iVar9;
      }
      bVar11 = local_14c8 != iVar5;
      local_14c8 = iVar5;
      if (bVar11) break;
      App_ProcessPendingMessages();
    }
  } while( true );
}

/*
 * Decompiled function: Town_Process_00490d7b
 * Entry Point: 00490d7b
 * Size: 4071 bytes
 */


void Town_Process_00490d7b(void)

{
  undefined4 uVar1;
  int iVar2;
  uint arg_2;
  uint arg_4;
  DWORD arg_5;
  int iVar3;
  DWORD DVar4;
  uint uVar5;
  int *piVar6;
  uint uVar7;
  DWORD local_45c;
  int local_444;
  int local_43c;
  int local_434;
  DWORD local_430;
  int local_42c;
  int local_424;
  int aiStack_418 [10];
  int aiStack_3f0 [247];
  int local_14;
  int local_10;
  int local_8;
  
  local_14 = 0;
  local_444 = 0;
  Mem_AllocOrFree_00510e20(1,s_infobar_pic_00528650);
  Mem_AllocOrFree_0050fc00();
  for (local_43c = 0; local_43c < 4; local_43c = local_43c + 1) {
    if (*(int *)(&DAT_005281f0 + local_43c * 0x54) == *(int *)(&DAT_005281e0 + local_43c * 0x54)) {
      uVar1 = Ai_Util_004c3bc4(*(int *)(&DAT_005281f0 + local_43c * 0x54));
      *(undefined4 *)(&DAT_005281f0 + local_43c * 0x54) = uVar1;
      uVar1 = Ai_Util_004c3bc4(*(int *)(&DAT_005281f4 + local_43c * 0x54));
      *(undefined4 *)(&DAT_005281f4 + local_43c * 0x54) = uVar1;
      uVar1 = Ai_Util_004c3bc4(*(int *)(&DAT_005281f8 + local_43c * 0x54));
      *(undefined4 *)(&DAT_005281f8 + local_43c * 0x54) = uVar1;
      uVar1 = Ai_Util_004c3bc4(*(int *)(&DAT_005281fc + local_43c * 0x54));
      *(undefined4 *)(&DAT_005281fc + local_43c * 0x54) = uVar1;
    }
    for (local_42c = 0; local_42c < 4; local_42c = local_42c + 1) {
      uVar1 = Sprite_EncodeFromSurface(1,local_42c * 0x12 + 0x2b,local_43c * 0x31 + 0x1c,0x11,0x2f);
      (&DAT_00676c40)[local_43c * 4 + local_42c] = (void *)uVar1;
    }
  }
  if (DAT_00528340 == DAT_00528330) {
    DAT_00528340 = Ai_Util_004c3bc4(DAT_00528340);
    DAT_00528344 = Ai_Util_004c3bc4(DAT_00528344);
    DAT_00528348 = Ai_Util_004c3bc4(DAT_00528348);
    DAT_0052834c = Ai_Util_004c3bc4(DAT_0052834c);
  }
  for (local_42c = 0; local_42c < 3; local_42c = local_42c + 1) {
    uVar1 = Sprite_EncodeFromSurface(1,local_42c * 0x3c + 0x2b,1,0x3a,0x18);
    *(undefined4 *)(&DAT_00676be0 + local_42c * 4) = uVar1;
  }
  FUN_0050fc20();
  iVar2 = FUN_0041f354();
  Mem_AllocOrFree_0041f12b(iVar2);
  FUN_0041f17e(0x5281e0,5,iVar2);
  Mem_AllocOrFree_0041f159(0);
  DAT_00641884 = 1;
  Glue_Subsystem_004eadb7(1);
  *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 1;
  *(undefined4 *)(g_DisplaySurfaceBackBuffer + 0x20) = 1;
  FUN_00510b70(1,0,g_DisplayScreenHeight - 0x1e0,s_cityinfo_pic_0052865c,(short *)0x0);
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,g_DisplayScreenHeight - 0x1e0,0x280,0x1e0,
                     (int *)g_DisplaySurfaceBackBuffer,0,0,g_DisplayScreenWidth,g_DisplayScreenHeight);
  FUN_00510b70(2,0,*(int *)(g_DisplaySurfaceWork + 0x10) + -0x46,s_cinfopce_pic_0052866c,
               (short *)0x0);
  arg_2 = (int)((int)g_DisplayScreenWidth / 2 + g_DisplayScreenWidth * 0x30) / 0x280;
  local_8 = Ai_Util_004c3bc4(0x52);
  arg_4 = Ai_Util_004c3bc4(0x231);
  arg_5 = Ai_Util_004c3bc4(0x2a);
  iVar2 = Ai_Util_004c3bc4(0x19);
  uVar5 = arg_4;
  iVar3 = Ai_Util_004c3bc4(0x38);
  Surface_StretchBlt((int *)g_DisplaySurfaceWork,0,*(int *)(g_DisplaySurfaceWork + 0x10) + -0x46,
                     0x231,0x19,(int *)g_DisplaySurfaceBackBuffer,arg_2,iVar3,uVar5,iVar2);
  Surface_StretchBlt((int *)g_DisplaySurfaceWork,0,*(int *)(g_DisplaySurfaceWork + 0x10) + -0x2c,
                     0x231,0x2a,(int *)g_DisplaySurfaceWork,0,0x80,arg_4,arg_5);
  for (local_42c = 0; local_42c < 9; local_42c = local_42c + 1) {
    FUN_0050e040((int *)g_DisplaySurfaceWork,0,0x80,arg_4,arg_5,(int *)g_DisplaySurfaceBackBuffer,
                 arg_2,local_42c * arg_5 + local_8);
  }
  FUN_0050e040((int *)g_DisplaySurfaceBackBuffer,0,0,g_DisplayScreenWidth,g_DisplayScreenHeight,
               (int *)g_DisplaySurfaceScreen,0,0);
  for (local_10 = 0; local_10 < 0x80; local_10 = local_10 + 1) {
    if (((((&DAT_0067be00)[local_10 * 100] & 2) != 0) || (DAT_0067b9a4 != 0)) &&
       (*(int *)(&DAT_0067bdf0 + local_10 * 100) != 1)) {
      aiStack_418[local_14 + 1] = local_10;
      local_14 = local_14 + 1;
    }
  }
  for (local_42c = 0; local_42c < 5; local_42c = local_42c + 1) {
    Font_DrawTextInRect((int)g_DisplaySurfaceScreen,0xfe,local_42c * 0x2a + 0xcc,0x2a);
  }
LAB_00491326:
  do {
    for (local_42c = 0; local_42c < 9; local_42c = local_42c + 1) {
      FUN_0050e040((int *)g_DisplaySurfaceWork,0,0x80,arg_4,arg_5,(int *)g_DisplaySurfaceBackBuffer,
                   arg_2,local_42c * arg_5 + local_8);
    }
    local_424 = local_444;
    local_43c = 0;
    while( true ) {
      iVar2 = local_14 - local_444;
      if (8 < iVar2) {
        iVar2 = 9;
      }
      if (iVar2 <= local_43c) break;
      local_10 = aiStack_418[local_424 + 1];
      iVar2 = Ai_Util_004c3bc4(0x68);
      Castle_Process_00491d8f(g_DisplaySurfaceBackBuffer,local_10,0x30,iVar2 + local_43c * arg_5);
      local_43c = local_43c + 1;
      local_424 = local_424 + 1;
    }
    FUN_0050e040((int *)g_DisplaySurfaceBackBuffer,arg_2,local_8,arg_4,arg_5 * 9,
                 (int *)g_DisplaySurfaceScreen,arg_2,local_8);
    if (9 < local_14) {
      local_45c = arg_5;
      if (local_444 == 0) {
        local_45c = 0;
      }
      FUN_0050e040((int *)g_DisplaySurfaceBackBuffer,arg_2,local_8,arg_4,arg_5 * 9,
                   (int *)g_DisplaySurfaceBackBuffer,arg_2,local_45c);
      if (local_444 == 0) {
        FUN_0050e040((int *)g_DisplaySurfaceWork,0,0x80,arg_4,arg_5,
                     (int *)g_DisplaySurfaceBackBuffer,arg_2,arg_5 * 9);
        iVar2 = Ai_Util_004c3bc4(0x15);
        Castle_Process_00491d8f(g_DisplaySurfaceBackBuffer,aiStack_3f0[0],0x30,iVar2 + arg_5 * 9);
        FUN_0050e040((int *)g_DisplaySurfaceWork,0,0x80,arg_4,arg_5,
                     (int *)g_DisplaySurfaceBackBuffer,arg_2,arg_5 * 10);
        if (10 < local_14) {
          iVar2 = Ai_Util_004c3bc4(0x15);
          Castle_Process_00491d8f(g_DisplaySurfaceBackBuffer,aiStack_3f0[1],0x30,iVar2 + arg_5 * 10)
          ;
        }
      }
      else {
        FUN_0050e040((int *)g_DisplaySurfaceWork,0,0x80,arg_4,arg_5,
                     (int *)g_DisplaySurfaceBackBuffer,arg_2,0);
        iVar2 = Ai_Util_004c3bc4(0x15);
        Castle_Process_00491d8f(g_DisplaySurfaceBackBuffer,aiStack_418[local_444],0x30,iVar2);
        if (local_444 + 10 < local_14) {
          FUN_0050e040((int *)g_DisplaySurfaceWork,0,0x80,arg_4,arg_5,
                       (int *)g_DisplaySurfaceBackBuffer,arg_2,arg_5 * 10);
        }
        if (local_444 + 10 < local_14) {
          iVar2 = Ai_Util_004c3bc4(0x15);
          Castle_Process_00491d8f
                    (g_DisplaySurfaceBackBuffer,aiStack_3f0[local_444],0x30,iVar2 + arg_5 * 10);
        }
      }
    }
    local_430 = arg_5;
    if (local_444 == 0) {
      local_430 = 0;
    }
switchD_004918ce_default:
    if (local_14 < 10) {
      FUN_0041ece4(0x5281e0);
      FUN_0041ece4(0x528234);
      FUN_0041ece4(0x528288);
      FUN_0041ece4(0x5282dc);
    }
    else {
      if (local_444 == 0) {
        FUN_0041ece4(0x5281e0);
        FUN_0041ece4(0x528234);
      }
      else {
        FUN_0041ed3a(0x5281e0);
        FUN_0041ed3a(0x528234);
      }
      if (local_14 + -9 == local_444) {
        FUN_0041ece4(0x528288);
        FUN_0041ece4(0x5282dc);
      }
      else {
        FUN_0041ed3a(0x528288);
        FUN_0041ed3a(0x5282dc);
      }
    }
    FUN_0041f213();
    DAT_0054aae0 = -5;
    do {
      Pic_Subsystem_0044b84b();
      FUN_0041f3ea(DAT_0067bda4,DAT_0067bda8,DAT_007039c4);
      if (DAT_0054aae0 != -5) break;
      iVar2 = Mem_AllocOrFree_00408089();
    } while (iVar2 == 0);
    if (DAT_0054aae0 == 0) {
      FUN_0041f391();
      Mem_AllocOrFree_0050fc50(DAT_00676c40);
      return;
    }
    switch(DAT_0054aae0) {
    case 0:
      goto switchD_004918ce_default;
    case 1:
      local_434 = 0x5000;
      break;
    case 2:
      local_434 = 0x5100;
      break;
    case -2:
      local_434 = 0x4900;
      break;
    case -1:
      local_434 = 0x4800;
      break;
    default:
      goto switchD_004918ce_default;
    }
    if (local_14 < 10) {
      FUN_0041f391();
      Mem_AllocOrFree_0050fc50(DAT_00676c40);
      return;
    }
    if (local_434 == 0x4800) {
      local_444 = local_444 + -1;
      if (local_444 < 0) {
        local_444 = 0;
      }
      else {
        for (local_42c = 0; iVar2 = Ai_Util_004c3bc4(0x2b), local_42c < iVar2;
            local_42c = local_42c + 3) {
          iVar2 = Ai_Util_004c3bc4(3);
          iVar2 = local_8 + iVar2;
          piVar6 = (int *)g_DisplaySurfaceScreen;
          uVar7 = arg_2;
          iVar3 = Ai_Util_004c3bc4(5);
          DVar4 = arg_5 * 9 - iVar3;
          uVar5 = arg_4;
          iVar3 = Ai_Util_004c3bc4(3);
          FUN_0050e040((int *)g_DisplaySurfaceBackBuffer,arg_2,iVar3 + (local_430 - local_42c),uVar5
                       ,DVar4,piVar6,uVar7,iVar2);
        }
        piVar6 = (int *)g_DisplaySurfaceScreen;
        uVar5 = arg_2;
        iVar2 = local_8;
        iVar3 = Ai_Util_004c3bc4(5);
        FUN_0050e040((int *)g_DisplaySurfaceBackBuffer,arg_2,0,arg_4,arg_5 * 9 - iVar3,piVar6,uVar5,
                     iVar2);
        if (local_444 < 1) {
          local_430 = 0;
        }
        else {
          FUN_0050e040((int *)g_DisplaySurfaceBackBuffer,arg_2,0,arg_4,arg_5 * 10,
                       (int *)g_DisplaySurfaceBackBuffer,arg_2,arg_5);
          FUN_0050e040((int *)g_DisplaySurfaceWork,0,0x80,arg_4,arg_5,
                       (int *)g_DisplaySurfaceBackBuffer,arg_2,0);
          iVar2 = Ai_Util_004c3bc4(0x15);
          Castle_Process_00491d8f(g_DisplaySurfaceBackBuffer,aiStack_418[local_444],0x30,iVar2);
          local_430 = arg_5;
        }
      }
      goto switchD_004918ce_default;
    }
    if (local_434 == 0x5000) {
      if (local_14 + -9 != local_444) {
        for (local_42c = 0; iVar2 = Ai_Util_004c3bc4(0x2b), local_42c < iVar2;
            local_42c = local_42c + 3) {
          iVar2 = Ai_Util_004c3bc4(3);
          iVar2 = local_8 + iVar2;
          piVar6 = (int *)g_DisplaySurfaceScreen;
          uVar7 = arg_2;
          iVar3 = Ai_Util_004c3bc4(5);
          DVar4 = arg_5 * 9 - iVar3;
          uVar5 = arg_4;
          iVar3 = Ai_Util_004c3bc4(3);
          FUN_0050e040((int *)g_DisplaySurfaceBackBuffer,arg_2,local_42c + iVar3 + local_430,uVar5,
                       DVar4,piVar6,uVar7,iVar2);
        }
        piVar6 = (int *)g_DisplaySurfaceScreen;
        uVar5 = arg_2;
        iVar2 = local_8;
        iVar3 = Ai_Util_004c3bc4(5);
        FUN_0050e040((int *)g_DisplaySurfaceBackBuffer,arg_2,local_430 + arg_5,arg_4,
                     arg_5 * 9 - iVar3,piVar6,uVar5,iVar2);
        local_430 = arg_5;
        if ((0 < local_444) && (local_444 < local_14 + -9)) {
          FUN_0050e040((int *)g_DisplaySurfaceBackBuffer,arg_2,arg_5,arg_4,arg_5 * 10,
                       (int *)g_DisplaySurfaceBackBuffer,arg_2,0);
          if (local_444 + 10 < local_14) {
            FUN_0050e040((int *)g_DisplaySurfaceWork,0,0x80,arg_4,arg_5,
                         (int *)g_DisplaySurfaceBackBuffer,arg_2,arg_5 * 10);
          }
          if (local_444 + 10 < local_14) {
            iVar2 = Ai_Util_004c3bc4(0x15);
            Castle_Process_00491d8f
                      (g_DisplaySurfaceBackBuffer,aiStack_3f0[local_444 + 1],0x30,iVar2 + arg_5 * 10
                      );
          }
        }
      }
      local_444 = local_444 + 1;
      if (local_14 + -9 < local_444) {
        local_444 = local_14 + -9;
      }
      goto switchD_004918ce_default;
    }
    if (local_434 == 0x4900) {
      local_444 = local_444 + -8;
      if (local_444 < 1) {
        local_444 = 0;
      }
      goto LAB_00491326;
    }
    if (local_434 != 0x5100) goto switchD_004918ce_default;
    iVar2 = local_444 + 8;
    local_444 = local_14 + -9;
    if (iVar2 <= local_14 + -9) {
      local_444 = iVar2;
    }
  } while( true );
}

/*
 * Decompiled function: Castle_Process_00491d8f
 * Entry Point: 00491d8f
 * Size: 1320 bytes
 */


undefined4 Castle_Process_00491d8f(undefined4 arg_1,int y,int width,int height)

{
  size_t sVar1;
  undefined4 uVar2;
  int iVar3;
  int arg_4;
  int iVar4;
  int iVar5;
  char *str_2;
  int local_3c [7];
  undefined4 local_20;
  int local_1c;
  uint local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (*(int *)(&DAT_0067bdf0 + y * 100) == 4) {
    strcpy(&g_OverworldWorldState,s_Castle_00528680);
  }
  else {
    g_OverworldWorldState = 0;
    Ai_TownEncounter_004c3b19(y);
  }
  local_18 = 0;
  while (sVar1 = strlen(&g_OverworldWorldState), local_18 < sVar1) {
    if ((&g_OverworldWorldState)[local_18] == ' ') {
      (&g_OverworldWorldState)[local_18] = 10;
    }
    local_18 = local_18 + 1;
  }
  strcat(&g_OverworldWorldState,&DAT_00528688);
  uVar2 = Surface_GetPixelColor(*(int *)(&DAT_0067bdf4 + y * 100),*(int *)(&DAT_0067bdf8 + y * 100));
  local_3c[6] = Glue_Subsystem_004ea7a6(uVar2);
  if (((&DAT_0067be00)[y * 100] & 1) == 0) {
    local_c = 0xe3;
  }
  else {
    local_c = 0xff;
  }
  if ((&DAT_0067be01)[y * 100] != '\0') {
    local_c = *(int *)(&DAT_00526e48 + ((int)(*(uint *)(&DAT_0067be00 + y * 100) & 0xffffff00) >> 6)
                      );
  }
  iVar5 = height;
  iVar3 = Ai_Util_004c3bc4(width + 0x2a);
  FUN_0040d269((int)g_DisplaySurfaceBackBuffer,local_c,iVar3,iVar5);
  if (((&DAT_0067be00)[y * 100] & 1) != 0) {
    iVar5 = height;
    iVar3 = Ai_Util_004c3bc4(width + 0x20c);
    FUN_0040d269((int)g_DisplaySurfaceBackBuffer,local_c,iVar3,iVar5);
  }
  uVar2 = Surface_GetPixelColor(*(int *)(&DAT_0067bdf4 + y * 100),*(int *)(&DAT_0067bdf8 + y * 100));
  local_3c[6] = Glue_Subsystem_004ea7a6(uVar2);
  local_8 = 0;
  for (local_18 = 1; (int)local_18 < 6; local_18 = local_18 + 1) {
    if ((local_3c[6] & 1 << ((byte)local_18 & 0x1f)) != 0) {
      local_8 = local_8 + 1;
    }
  }
  local_10 = (int)*(short *)(DAT_006776a0 + 4);
  local_14 = (int)*(short *)(DAT_006776a0 + 6);
  local_1c = Ai_Util_004c3bc4(((width + 0x80) - (local_10 * local_8) / 2) - (local_8 * 5 + -5));
  for (local_18 = 1; (int)local_18 < 6; local_18 = local_18 + 1) {
    local_3c[1] = 2;
    local_3c[2] = 1;
    local_3c[3] = 4;
    local_3c[4] = 3;
    local_3c[5] = 0;
    if ((local_3c[6] & 1 << ((byte)local_18 & 0x1f)) != 0) {
      iVar5 = (&DAT_006776a0)[local_3c[local_18]];
      iVar3 = Ai_Util_004c3bc4(local_14);
      arg_4 = Ai_Util_004c3bc4(local_10);
      iVar4 = Ai_Util_004c3bc4(local_14 / 2);
      Sprite_DrawScaled((int *)g_DisplaySurfaceBackBuffer,local_1c,height - iVar4,arg_4,iVar3,iVar5)
      ;
      iVar5 = Ai_Util_004c3bc4(local_10 + 5);
      local_1c = local_1c + iVar5;
    }
  }
  local_3c[6] = Card_ColorMaskToColorIndex((byte)*(undefined4 *)(&DAT_0067bdfc + y * 100));
  g_OverworldWorldState = 0;
  if ((&DAT_0067bdfc)[y * 100] == '\0') {
    strcat(&g_OverworldWorldState,&DAT_00528690);
  }
  else {
    str_2 = (char *)Mem_AllocOrFree_00473d7e(local_3c[6]);
    strcat(&g_OverworldWorldState,str_2);
  }
  local_3c[0] = *(int *)(&DAT_0067bdfc + y * 100) >> 8;
  switch(local_3c[0]) {
  case 0:
    strcat(&g_OverworldWorldState,s_Cards_00528694);
    break;
  case 1:
    strcat(&g_OverworldWorldState,s_Land_0052869c);
    break;
  case 2:
    strcat(&g_OverworldWorldState,s_Creatures_005286a4);
    break;
  case 3:
    strcat(&g_OverworldWorldState,s_Enchantments_005286b0);
    break;
  case 4:
    strcat(&g_OverworldWorldState,s_Sorceries_005286c0);
    break;
  case 5:
    strcat(&g_OverworldWorldState,s_Fast_Effects_005286cc);
    break;
  case 7:
    strcat(&g_OverworldWorldState,s_Artifacts_005286dc);
  }
  iVar5 = height;
  iVar3 = Ai_Util_004c3bc4(width + 0xff);
  FUN_0040d269((int)g_DisplaySurfaceBackBuffer,local_c,iVar3,iVar5);
  g_OverworldWorldState = 0;
  for (local_18 = 0; (int)local_18 < 0xc; local_18 = local_18 + 1) {
    if ((y != 0) && (*(int *)(&DAT_005224e8 + local_18 * 0x10) == y)) {
      local_20 = Glue_Subsystem_004f0de8(local_18);
      strcat(&g_OverworldWorldState,(&PTR_s_Sleight_of_hand_005225d0)[local_18]);
    }
  }
  iVar5 = Ai_Util_004c3bc4(width + 0x19c);
  FUN_0040d269((int)g_DisplaySurfaceBackBuffer,local_c,iVar5,height);
  return 0;
}

/*
 * Decompiled function: Castle_Process_00492ddf
 * Entry Point: 00492ddf
 * Size: 2808 bytes
 */


void Castle_Process_00492ddf(int arg_1)

{
  byte bVar1;
  undefined4 uVar2;
  DWORD arg_5;
  uint arg_4;
  int iVar3;
  uint arg_2;
  char *pcVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int local_88 [4];
  int local_78 [4];
  int local_68 [4];
  int local_58 [4];
  undefined4 local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  undefined4 local_8;
  
  local_8 = 0x98;
  local_18 = 0xab;
  local_14 = 0x3a;
  Surface_TransformPoint(0,(short)DAT_00530d9c);
  LoadPalNoPic(s_advfac64_pic_005289ec);
  Mem_AllocOrFree_00510e20(1,s_cluebutn_pic_005289fc);
  Mem_AllocOrFree_0050fc00();
  for (local_c = 0; local_c < 3; local_c = local_c + 1) {
    uVar2 = Sprite_EncodeFromSurface(1,local_c * 0x5a + 1,1,0x59,0x23);
    (&DAT_00676b90)[local_c] = (void *)uVar2;
    uVar2 = Sprite_EncodeFromSurface(1,local_c * 0x15 + 1,0x25,0x14,0x24);
    *(undefined4 *)(&DAT_00676c80 + local_c * 4) = uVar2;
  }
  if (DAT_00527fa8 == DAT_00527f98) {
    DAT_00527fa8 = Ai_Util_004c3bc4(DAT_00527fa8);
    DAT_00527fac = Ai_Util_004c3bc4(DAT_00527fac);
    DAT_00527fb0 = Ai_Util_004c3bc4(DAT_00527fb0);
    DAT_00527fb4 = Ai_Util_004c3bc4(DAT_00527fb4);
  }
  local_20 = FUN_0041f354();
  Mem_AllocOrFree_0041f12b(local_20);
  FUN_0041f17e(0x527f98,1,local_20);
  FUN_0050fc20();
  FUN_00510b70(1,0,g_DisplayScreenHeight - 0x1e0,s_clueback_pic_00528a0c,(short *)0x0);
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,g_DisplayScreenHeight - 0x1e0,0x280,0x1e0,
                     (int *)g_DisplaySurfaceBackBuffer,0,0,g_DisplayScreenWidth,g_DisplayScreenHeight);
  FUN_0050e040((int *)g_DisplaySurfaceBackBuffer,0,0,g_DisplayScreenWidth,g_DisplayScreenHeight,
               (int *)g_DisplaySurfaceScreen,0,0);
  iVar8 = 0;
  iVar7 = 0;
  piVar6 = (int *)g_DisplaySurfaceBackBuffer;
  arg_5 = Ai_Util_004c3bc4(0x24);
  arg_4 = Ai_Util_004c3bc4(0x5a);
  iVar3 = Ai_Util_004c3bc4(0x1a2);
  arg_2 = Ai_Util_004c3bc4(0x16);
  Surface_BlitToDevice((int *)g_DisplaySurfaceBackBuffer,arg_2,iVar3,arg_4,arg_5,piVar6,iVar7,iVar8);
  FUN_0041f213();
  *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 4;
  g_OverworldWorldState = 0;
  FUN_0048e2b0(arg_1);
  if (arg_1 < 5) {
    strcat(&g_OverworldWorldState,s___00528a1c);
    pcVar4 = (char *)Mem_AllocOrFree_00473d7e(arg_1 + 1);
    strcat(&g_OverworldWorldState,pcVar4);
    strcat(&g_OverworldWorldState,s_Castle__00528a28);
    FUN_0040d1cd((int)g_DisplaySurfaceScreen,local_14,0x12,0x1c);
    local_10 = Ai_Util_004c3ba3(0x24);
  }
  else {
    local_10 = FUN_00492cb1(0x10,local_14);
    local_10 = Ai_Util_004c3ba3(0x1c);
  }
  for (local_c = 0; local_c < 3; local_c = local_c + 1) {
    if (*(int *)(&DAT_0067eff0 + local_c * 4 + arg_1 * 0x30) != -1) {
      FUN_0050b206(*(int *)(&DAT_0067eff0 + local_c * 4 + arg_1 * 0x30),local_c * 0x29 + 0xa0,
                   (-(uint)(local_c == 0) & 8) + local_c * 4 + 0x76,1,&DAT_00528a34);
    }
  }
  if ((((&DAT_0067f010)[arg_1 * 0x30] & 2) != 0) || (DAT_0067b9a4 != 0)) {
    iVar3 = local_10;
    uVar2 = local_8;
    iVar7 = Ai_Util_004c3ba3(0xc);
    FUN_0040c1ad(s_Creatures__00528a38,iVar7,iVar3,uVar2);
    iVar3 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
    local_10 = local_10 + iVar3;
    if (arg_1 < 5) {
      bVar1 = FUN_0049094c();
      (&DAT_0067f00d)[arg_1 * 0x30] = bVar1 | 0x80;
    }
    strcpy(&g_OverworldWorldState,s__Contains_00528a44);
    strcat(&g_OverworldWorldState,
           s_large_00528a50 + ((((&DAT_0067f00d)[arg_1 * 0x30] & 0x80) != 0) - 1 & 8));
    pcVar4 = (char *)Mem_AllocOrFree_00473d7e((int)(char)(&DAT_0067f00c)[arg_1 * 0x30]);
    strcat(&g_OverworldWorldState,pcVar4);
    strcat(&g_OverworldWorldState,s_creatures__00528a60);
    local_10 = FUN_00492cb1(local_10,local_18);
  }
  iVar3 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
  iVar3 = local_10 + iVar3;
  local_10 = iVar3;
  if ((((&DAT_0067f010)[arg_1 * 0x30] & 4) != 0) || (DAT_0067b9a4 != 0)) {
    uVar2 = local_8;
    iVar7 = Ai_Util_004c3ba3(0xc);
    FUN_0040c1ad(s_Dungeon_Rules__00528a6c,iVar7,iVar3,uVar2);
    iVar3 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
    local_10 = local_10 + iVar3;
    if (((&DAT_0067f014)[arg_1 * 0x30] & 0x10) != 0) {
      strcpy(&g_OverworldWorldState,&DAT_00528a7c);
      pcVar4 = (char *)Mem_AllocOrFree_00473d7e((int)(char)(&DAT_0067f00c)[arg_1 * 0x30]);
      strcat(&g_OverworldWorldState,pcVar4);
      strcat(&g_OverworldWorldState,s_cards_allowed__00528a84);
      local_10 = FUN_00492cb1(local_10,local_18);
    }
    if (((&DAT_0067f014)[arg_1 * 0x30] & 0x20) != 0) {
      strcpy(&g_OverworldWorldState,s__One_deck_for_all_duels__00528a94);
      local_10 = FUN_00492cb1(local_10,local_18);
    }
    if (((&DAT_0067f014)[arg_1 * 0x30] & 0x40) != 0) {
      strcpy(&g_OverworldWorldState,s__No_artifacts_allowed__00528ab0);
      local_10 = FUN_00492cb1(local_10,local_18);
    }
    if (((&DAT_0067f014)[arg_1 * 0x30] & 0x80) != 0) {
      strcpy(&g_OverworldWorldState,s__No_instants_or_interrupts_allow_00528ac8);
      local_10 = FUN_00492cb1(local_10,local_18);
    }
    if (((&DAT_0067f014)[arg_1 * 0x30] & 1) != 0) {
      strcpy(&g_OverworldWorldState,s__Life_losses_carried_over__00528aec);
      local_10 = FUN_00492cb1(local_10,local_18);
    }
    if (((&DAT_0067f014)[arg_1 * 0x30] & 2) != 0) {
      strcpy(&g_OverworldWorldState,s__Remaining_life_added_to_next_du_00528b08);
      local_10 = FUN_00492cb1(local_10,local_18);
    }
    if (*(int *)(&DAT_0067effc + arg_1 * 0x30) == -1) {
      if (*(int *)(&DAT_0067f014 + arg_1 * 0x30) == 0) {
        strcpy(&g_OverworldWorldState,s__No_special_rules__00528b48);
        local_10 = FUN_00492cb1(local_10,local_18);
      }
    }
    else {
      strcpy(&g_OverworldWorldState,&DAT_00528b2c);
      iVar3 = Pic_Subsystem_0045268f(*(int *)(&DAT_0067effc + arg_1 * 0x30));
      strcat(&g_OverworldWorldState,s_Swamp_0051aea9 + iVar3 * 0x34);
      strcat(&g_OverworldWorldState,s_permanently_in_effect__00528b30);
      local_10 = FUN_00492cb1(local_10,local_18);
    }
    iVar3 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
    local_10 = local_10 + iVar3;
  }
  if ((((&DAT_0067f010)[arg_1 * 0x30] & 1) != 0) || (DAT_0067b9a4 != 0)) {
    iVar3 = local_10;
    uVar2 = local_8;
    iVar7 = Ai_Util_004c3ba3(0xc);
    FUN_0040c1ad(s_Location__00528b5c,iVar7,iVar3,uVar2);
    iVar3 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
    local_10 = local_10 + iVar3;
    local_1c = *(int *)(&DAT_0067f000 + arg_1 * 0x30) -
               *(int *)(&DAT_0067bdf4 + *(int *)(&DAT_0067f008 + arg_1 * 0x30) * 100);
    local_24 = *(int *)(&DAT_0067f004 + arg_1 * 0x30) -
               *(int *)(&DAT_0067bdf8 + *(int *)(&DAT_0067f008 + arg_1 * 0x30) * 100);
    if (local_24 < 1) {
      strcpy(&g_OverworldWorldState,s__North_00528b78 + ((0 < local_1c) - 1 & 8));
    }
    else {
      strcpy(&g_OverworldWorldState,s__East_00528b68 + ((0 < local_1c) - 1 & 8));
    }
    strcat(&g_OverworldWorldState,&DAT_00528b88);
    Ai_TownEncounter_004c3b19(*(uint *)(&DAT_0067f008 + arg_1 * 0x30));
    strcat(&g_OverworldWorldState,&DAT_00528b90);
    local_10 = FUN_00492cb1(local_10,local_18);
  }
  if ((((&DAT_0067f010)[arg_1 * 0x30] & 1) != 0) || (DAT_0067b9a4 != 0)) {
    FUN_0040c550(g_DisplaySurfaceWork,0,0,0x50,0x32,g_DisplaySurfaceWork,0x50,0);
    uVar2 = 0;
    iVar3 = Ai_Util_004c3bc4(0xe1);
    iVar3 = iVar3 + -0x18;
    iVar7 = Ai_Util_004c3bc4(0x17e);
    iVar7 = iVar7 + -0x18;
    iVar8 = Ai_Util_004c3bc4(0xc);
    iVar8 = iVar8 + 10;
    iVar5 = Ai_Util_004c3bc4(0xf4);
    (*(code *)PTR_FUN_00527b3c)(iVar5 + 10,iVar8,iVar7,iVar3,uVar2);
    *(undefined4 *)g_DisplaySurfaceScreen = *(undefined4 *)g_DisplaySurfaceBackBuffer;
    Ai_Util_004be240();
    local_48 = *(undefined4 *)g_DisplaySurfaceBackBuffer;
    DAT_00641884 = 0;
    piVar6 = (int *)FUN_0050e6f0(local_58,(int)g_DisplaySurfaceBackBuffer,0,0x80,
                                 *(int *)(g_DisplaySurfaceScreen + 0xc),
                                 *(int *)(g_DisplaySurfaceScreen + 0x10) + -0x80);
    local_44 = *piVar6;
    local_40 = piVar6[1];
    local_3c = piVar6[2];
    local_38 = piVar6[3];
    piVar6 = (int *)FUN_0050e6f0(local_68,(int)g_DisplaySurfaceScreen,0,0x80,
                                 *(int *)(g_DisplaySurfaceScreen + 0xc),
                                 *(int *)(g_DisplaySurfaceScreen + 0x10) + -0x80);
    local_34 = *piVar6;
    local_30 = piVar6[1];
    local_2c = piVar6[2];
    local_28 = piVar6[3];
    Ai_Subsystem_004c06df
              (*(int *)(&DAT_0067f000 + arg_1 * 0x30) * 0x20 + 0x10,
               *(int *)(&DAT_0067f004 + arg_1 * 0x30) * 0x20 + 0x10);
    Ai_Subsystem_004be357();
    DAT_00641884 = 0;
    FUN_0050e6f0(local_78,(int)g_DisplaySurfaceBackBuffer,local_44,local_40,local_3c,local_38);
    FUN_0050e6f0(local_88,(int)g_DisplaySurfaceScreen,local_34,local_30,local_2c,local_28);
    *(undefined4 *)g_DisplaySurfaceBackBuffer = local_48;
    *(undefined4 *)g_DisplaySurfaceScreen = 0;
    FUN_0040c550(g_DisplaySurfaceBackBuffer,0x40,DAT_0052d77c,0xb3,100,g_DisplaySurfaceScreen,0x7f,
                 0xb);
    FUN_0040c550(g_DisplaySurfaceWork,0x50,0,0x50,0x32,g_DisplaySurfaceWork,0,0);
  }
  DAT_0054aae0 = -1;
  while (DAT_0054aae0 == -1) {
    Pic_Subsystem_0044b84b();
    FUN_0041f3ea(DAT_0067bda4,DAT_0067bda8,DAT_007039c4);
  }
  Palette_Subsystem_00496eaf();
  FUN_0041f391();
  Mem_AllocOrFree_0050fc50(DAT_00676b90);
  return;
}

/*
 * Decompiled function: Town_Process_00506580
 * Entry Point: 00506580
 * Size: 5505 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int Town_Process_00506580(uint arg_1)

{
  byte bVar1;
  char *pcVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int arg_5;
  int arg_4;
  int arg_3;
  int arg_2;
  uint local_94;
  int local_78;
  char *local_74;
  char *local_70;
  char *local_6c;
  char *local_68;
  char *local_64 [4];
  char *local_54;
  char *local_50;
  int local_4c;
  int local_48;
  int local_44;
  uint local_40;
  int local_3c;
  int local_38;
  uint local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  LPVOID local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  DAT_0061e0d4 = arg_1;
  App_ProcessPendingMessages();
  if ((&DAT_0067be01)[arg_1 * 100] == '\0') {
    if (*(int *)(&DAT_0067bdf0 + arg_1 * 100) == 4) {
      local_64[1] = s_0246_pic_00531a34;
      local_64[2] = s_0364_pic_00531a4c;
      local_64[3] = s_0335_pic_00531a64;
      local_54 = s_0737_pic_00531a7c;
      local_50 = s_0028_pic_00531a94;
      uVar4 = Surface_GetPixelColor(*(int *)(&DAT_0067bdf4 + arg_1 * 100),
                           *(int *)(&DAT_0067bdf8 + arg_1 * 100));
      bVar1 = Glue_Subsystem_004ea7a6(uVar4);
      DAT_006b2d64 = Card_ColorMaskToColorIndex(bVar1);
      FUN_0040aaf1(local_64[DAT_006b2d64]);
      *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 1;
      strcpy(&g_OverworldWorldState,s_Who_dares_to_challenge_the_Might_00531aa0);
      pcVar2 = (char *)Mem_AllocOrFree_00473d7e(DAT_006b2d64);
      strcat(&g_OverworldWorldState,pcVar2);
      strcat(&g_OverworldWorldState,s_Wizard__Are_you_brave_enough_to_e_00531ac4);
      strcat(&g_OverworldWorldState,s_Well____No__Yes__enter_the_castl_00531af8);
      iVar3 = FUN_004896be(&g_OverworldWorldState,0x2a,0x1a);
      if (iVar3 == 1) {
        Pic_Subsystem_00423c82(0x10);
        FUN_004909a0(DAT_006b2d64 + -1);
        if (((DAT_0067bdb4 & 1 << ((byte)DAT_006b2d64 & 0x1f)) == 0) && (DAT_0067f380 == 3)) {
          Glue_Sound_004eb2f9(DAT_006b2d64);
        }
      }
      Palette_Subsystem_00496eaf();
      iVar3 = 0;
    }
    else if (*(int *)(&DAT_0067bdf0 + arg_1 * 100) == 5) {
      local_74 = s_0246_pic_00531b2c;
      local_70 = s_0364_pic_00531b44;
      local_6c = s_0335_pic_00531b5c;
      local_68 = s_0737_pic_00531b74;
      local_64[0] = s_0028_pic_00531b8c;
      uVar4 = Surface_GetPixelColor(*(int *)(&DAT_0067bdf4 + arg_1 * 100),
                           *(int *)(&DAT_0067bdf8 + arg_1 * 100));
      bVar1 = Glue_Subsystem_004ea7a6(uVar4);
      DAT_006b2d64 = Card_ColorMaskToColorIndex(bVar1);
      FUN_0040aaf1((&local_78)[DAT_006b2d64]);
      strcpy(&g_OverworldWorldState,s_The_Mighty_00531b98);
      pcVar2 = (char *)Mem_AllocOrFree_00473d7e(DAT_006b2d64);
      strcat(&g_OverworldWorldState,pcVar2);
      strcat(&g_OverworldWorldState,s_Wizard_was_crushed_in_epic_comba_00531ba4);
      FUN_004896be(&g_OverworldWorldState,0x2a,0x1a);
      Pic_Subsystem_00423c82(0x10);
      Palette_Subsystem_00496eaf();
      iVar3 = 0;
    }
    else {
      if ((DAT_00522450 == arg_1) && ((-1 < DAT_0067f2c0 || (DAT_0067f2c0 < -100)))) {
        FUN_0040a95d(s_village_pic_00531c0c +
                     ((*(int *)(&DAT_0067bdf0 + arg_1 * 100) == 1) - 1 & 0xc));
        local_c = 0;
        FUN_0040b3c2(0x10,DAT_0067f2c0);
        if ((DAT_0067f2c0 == 0) || (DAT_0067f2c0 == 2)) {
          strcpy(&g_OverworldWorldState,s_The_keeper_is_pleased_to_receive_00531c24);
          if (DAT_0067f2c0 == 0) {
            strcat(&g_OverworldWorldState,s_You_create_a_mana_link_here__00531c5c);
            Pic_Subsystem_00423b93(0xf);
            Glue_Subsystem_004ec5be(s_x_sound_manalink_wav_00531c7c,0xf,0);
            Glue_Subsystem_004ebd62(0xf,100,100,0);
            *(uint *)(&DAT_0067be00 + DAT_00522450 * 100) =
                 *(uint *)(&DAT_0067be00 + DAT_00522450 * 100) | 1;
          }
          if (DAT_0067f2c0 == 2) {
            strcat(&g_OverworldWorldState,s_You_are_rewarded_with_a_fine_00531c94);
            pcVar2 = (char *)Mem_AllocOrFree_00473d7e(DAT_0067b9a0);
            strcat(&g_OverworldWorldState,pcVar2);
            strcat(&g_OverworldWorldState,s_amulet__00531cb4);
            Pic_Subsystem_00423b93(0xf);
            Glue_Subsystem_004ec5be(s_x_sound_reward_wav_00531cc0,0xf,0);
            Glue_Subsystem_004ebd62(0xf,100,100,0);
            *(int *)(&DAT_0067bdbc + DAT_0067b9a0 * 4) =
                 *(int *)(&DAT_0067bdbc + DAT_0067b9a0 * 4) + 1;
          }
          *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 1;
          FUN_004896be(&g_OverworldWorldState,0x50,0x50);
          local_c = 1;
          DAT_00522450 = 0xffffffff;
          Ai_Subsystem_004c05ba();
          Ai_Subsystem_004c3c5c(1);
        }
        if ((DAT_0067f2c0 == 1) &&
           (iVar3 = FUN_0050b0fc((byte)DAT_0067b9a0,(byte)(1 << ((byte)DAT_00522450 & 3))),
           iVar3 != 0)) {
          local_30 = FUN_0050b0fc((byte)DAT_0067b9a0,(byte)(1 << ((byte)DAT_00522450 & 3)));
          *(int *)(&DAT_0067bdbc + DAT_0067b9a0 * 4) =
               *(int *)(&DAT_0067bdbc + DAT_0067b9a0 * 4) + 1;
          strcpy(&g_OverworldWorldState,s_The_people_are_pleased_to_receiv_00531cd4);
          strcat(&g_OverworldWorldState,
                 s_Swamp_0051aea9 + ((&DAT_0070214c)[local_30] & 0xfff) * 0x34);
          strcat(&g_OverworldWorldState,s_spell__You_are_rewarded_with_a_f_00531cfc);
          pcVar2 = (char *)Mem_AllocOrFree_00473d7e(DAT_0067b9a0);
          strcat(&g_OverworldWorldState,pcVar2);
          strcat(&g_OverworldWorldState,s_amulet_and_a_mana_link__00531d24);
          *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 1;
          DAT_00676d3c = 1;
          FUN_004896be(&g_OverworldWorldState,0x50,0x50);
          *(uint *)(&DAT_0067be00 + DAT_00522450 * 100) =
               *(uint *)(&DAT_0067be00 + DAT_00522450 * 100) | 1;
          local_c = 1;
          Pic_Subsystem_00452065(local_30 + -1);
          Ai_Subsystem_004cd1d1();
          DAT_00522450 = 0xffffffff;
          Ai_Subsystem_004c05ba();
          Ai_Subsystem_004c3c5c(1);
        }
        if (DAT_0067f2c0 < -100) {
          if (*(int *)(&DAT_0067bdf0 + DAT_00522450 * 100) < 2) {
            DAT_0067f2c0 = DAT_0067f2c0 + 100;
            local_20 = (int)(char)(&DAT_00522628)[DAT_0067f2c0 * -0x44] / 7 + 1;
            strcpy(&g_OverworldWorldState,s_The_village_is_glad_to_be_rid_of_00531de0);
            Glue_Subsystem_004eaa19(-DAT_0067f2c0,0,0);
            strcat(&g_OverworldWorldState,s_You_are_rewarded_with_00531e0c);
            pcVar2 = _itoa(local_20,&DAT_0061e0f0,10);
            strcat(&g_OverworldWorldState,pcVar2);
            strcat(&g_OverworldWorldState,s_fine_00531e24);
            pcVar2 = (char *)Mem_AllocOrFree_00473d7e(DAT_0067b9a0);
            strcat(&g_OverworldWorldState,pcVar2);
            strcat(&g_OverworldWorldState,s_amulet_00531e2c);
            strcat(&g_OverworldWorldState,&DAT_00531e34 + ((local_20 == 1) - 1 & 4));
            FUN_004896be(&g_OverworldWorldState,0x50,0x50);
            *(int *)(&DAT_0067bdbc + DAT_0067b9a0 * 4) =
                 *(int *)(&DAT_0067bdbc + DAT_0067b9a0 * 4) + local_20;
            *(uint *)(&DAT_0067be00 + DAT_00522450 * 100) =
                 *(uint *)(&DAT_0067be00 + DAT_00522450 * 100) | 1;
          }
          else {
            local_78 = 1;
            DAT_0067f2c0 = DAT_0067f2c0 + 100;
            local_20 = (int)(char)(&DAT_00522628)[DAT_0067f2c0 * -0x44] / 7 + 1;
            strcpy(&g_OverworldWorldState,s_The_people_are_glad_to_be_rid_of_00531d40);
            Glue_Subsystem_004eaa19(-DAT_0067f2c0,0,0);
            strcat(&g_OverworldWorldState,s_You_are_rewarded_with_00531d6c);
            FUN_0050a73e(DAT_00522450);
            strcat(&g_OverworldWorldState,s_of_your_choice__00531d88);
            FUN_004896be(&g_OverworldWorldState,0x50,0x50);
            PTR_FUN_00527b3c = Mem_AllocOrFree_0040eea2;
            local_40 = 0xffffffff;
            while (local_40 == 0xffffffff) {
              local_40 = Palette_Color_0049716e
                                   (s_Which_card_do_you_seek__00531d9c,
                                    *(uint *)(&DAT_0067bdfc + arg_1 * 100) & 0xff,
                                    (*(int *)(&DAT_0067bdfc + arg_1 * 100) >> 8) - 1,local_78,0);
              local_78 = 0;
              if (local_40 != 0xffffffff) {
                strcpy(&g_OverworldWorldState,s_Will_you_take_this_card____Yes_N_00531db4);
                do {
                  iVar3 = Ai_Util_004c3bc4(0x15c);
                  iVar3 = iVar3 + 10;
                  iVar5 = Ai_Util_004c3bc4(0xf4);
                  iVar3 = FUN_00489710(&g_OverworldWorldState,iVar5 + 10,iVar3);
                } while (iVar3 < 0);
                if (iVar3 == 0) {
                  local_30 = Pic_Subsystem_00451e40(local_40);
                  if (local_30 != -1) {
                    *(uint *)(&deck + local_30 * 4) = *(uint *)(&deck + local_30 * 4) | 0x4000;
                  }
                }
                else {
                  local_40 = 0xffffffff;
                }
              }
              FUN_00501736(0xf);
            }
            PTR_FUN_00527b3c = FUN_0048a3cc;
          }
          local_c = 1;
          if (DAT_00522450 == DAT_00531594) {
            DAT_00531594 = 0xffffffff;
          }
          DAT_00522450 = 0xffffffff;
          Ai_Subsystem_004c05ba();
          Ai_Subsystem_004c3c5c(1);
        }
        if (local_c == 0) {
          local_94 = arg_1;
        }
        else {
          local_94 = arg_1 | 0x80;
        }
        FUN_0040b3c2(1,local_94);
      }
      else {
        FUN_0040b3c2(1,arg_1);
      }
      *(uint *)(&DAT_0067be00 + arg_1 * 100) = *(uint *)(&DAT_0067be00 + arg_1 * 100) | 2;
      *(int *)(&DAT_0067be4c + arg_1 * 100) = *(int *)(&DAT_0067be4c + arg_1 * 100) + 1;
      FUN_0040a95d(s_village_pic_00531e3c + ((*(int *)(&DAT_0067bdf0 + arg_1 * 100) == 1) - 1 & 0xc)
                  );
      Town_Process_00507c86(arg_1);
      *(int *)(&DAT_0067be50 + arg_1 * 100) = DAT_00641020;
      if ((*(int *)(&DAT_0067bdf0 + arg_1 * 100) == 3) ||
         (*(int *)(&DAT_0067bdf0 + arg_1 * 100) == 2)) {
        local_10 = -1;
        local_38 = 999;
        for (local_28 = 0; local_28 < 0xc; local_28 = local_28 + 1) {
          if ((*(int *)(&DAT_005224e8 + local_28 * 0x10) != 0) &&
             (local_14 = FUN_0040a36f(*(int *)(&DAT_0067bdf4 + arg_1 * 100) -
                                      *(int *)(&DAT_0067bdf4 +
                                              *(int *)(&DAT_005224e8 + local_28 * 0x10) * 100),
                                      *(int *)(&DAT_0067bdf8 + arg_1 * 100) -
                                      *(int *)(&DAT_0067bdf8 +
                                              *(int *)(&DAT_005224e8 + local_28 * 0x10) * 100)),
             local_14 < local_38)) {
            local_10 = local_28;
            local_38 = local_14;
          }
        }
        if ((local_10 != -1) && ((_DAT_0067f374 & 1 << ((byte)local_10 & 0x1f)) == 0)) {
          Mem_AllocOrFree_00510e20(1,s_worlbak1_pic_00531e54);
          Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,
                             (int *)g_DisplaySurfaceScreen,0,0,g_DisplayScreenWidth,g_DisplayScreenHeight);
          local_30 = Glue_Subsystem_004f0de8(local_10);
          iVar3 = *(int *)(&DAT_006782a0 + local_10 * 4);
          local_24 = (0x4e - *(short *)(iVar3 + 6)) / 2 + 0x4c;
          local_1c = (0x4f - *(short *)(iVar3 + 4)) / 2 + 0x14f;
          iVar5 = *(int *)(&DAT_006782a0 + local_10 * 4);
          arg_5 = Ai_Util_004c3bc4((int)*(short *)(iVar3 + 6));
          arg_4 = Ai_Util_004c3bc4((int)*(short *)(iVar3 + 4));
          arg_3 = Ai_Util_004c3bc4(local_24);
          arg_2 = Ai_Util_004c3bc4(local_1c);
          Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,arg_2,arg_3,arg_4,arg_5,iVar5);
          local_24 = (local_24 + *(short *)(iVar3 + 6) + 0x10) / 2;
          local_1c = (local_1c + (int)*(short *)(iVar3 + 4) / 2) / 2;
          *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 4;
          Font_DrawTextInRect((int)g_DisplaySurfaceScreen,0x7b,0x176,0x4b);
          g_OverworldWorldState = 0;
          local_24 = local_24 + -5;
          strcat(&g_OverworldWorldState,(&PTR_s_Sleight_of_hand_005225d0)[local_10]);
          FUN_0040c336(&g_OverworldWorldState,local_1c,local_24,0x40);
          local_24 = local_24 + 8;
          strcpy(&g_OverworldWorldState,s_costs_00531e70);
          pcVar2 = _itoa(*(int *)(&DAT_005224e4 + local_10 * 0x10) / 2,&DAT_0061e0f0,10);
          strcat(&g_OverworldWorldState,pcVar2);
          strcat(&g_OverworldWorldState,s_gold_pieces__00531e78);
          FUN_0040c336(&g_OverworldWorldState,local_1c,local_24,0x7b);
          local_24 = local_24 + 8;
          strcpy(&g_OverworldWorldState,&DAT_00531e88);
          strcat(&g_OverworldWorldState,(&PTR_s_A_clever_duelist_can_switch_ante_005225a0)[local_10]
                );
          strcat(&g_OverworldWorldState,&DAT_00531e8c);
          iVar3 = Ai_Util_004c3ba3(local_24);
          iVar5 = Ai_Util_004c3ba3(local_1c);
          FUN_0040d201((int)g_DisplaySurfaceScreen,0x7b,iVar5,iVar3);
          if (local_38 == 0) {
            if (Gold < *(int *)(&DAT_005224e4 + local_10 * 0x10) / 2) {
              local_24 = local_24 + 0x18;
              strcpy(&g_OverworldWorldState,s_Insufficient_Funds_00531f1c);
              FUN_0040c336(&g_OverworldWorldState,local_1c,local_24,0xbe);
              local_24 = local_24 + 8;
              App_ProcessPendingMessages();
              Ai_Subsystem_004cd1d1();
            }
            else {
              local_24 = local_24 + 0x10;
              strcpy(&g_OverworldWorldState,s_To_release_the_WORLDMAGIC_spell___00531ea4);
              strcat(&g_OverworldWorldState,(&PTR_s_Sleight_of_hand_005225d0)[local_10]);
              strcat(&g_OverworldWorldState,s___from_00531ec8);
              Ai_TownEncounter_004c3b19(*(uint *)(&DAT_005224e8 + local_10 * 0x10));
              strcat(&g_OverworldWorldState,s___you_must_pay_00531ed4);
              pcVar2 = _itoa(*(int *)(&DAT_005224e4 + local_10 * 0x10) / 2,&DAT_0061e0f0,10);
              strcat(&g_OverworldWorldState,pcVar2);
              strcat(&g_OverworldWorldState,s_gold_pieces__00531ee4);
              strcat(&g_OverworldWorldState,s_Will_you____Never_mind_Pay_the_g_00531ef4);
              App_ProcessPendingMessages();
              local_30 = FUN_004896be(&g_OverworldWorldState,
                                      (-(uint)(g_DisplayScreenWidth == 0x280) & 0xffffffce) + 0xbe,0x88);
              DAT_00531590 = local_10;
              iVar3 = DAT_00531590;
              if (local_30 == 1) {
                Gold = Gold - *(int *)(&DAT_005224e4 + local_10 * 0x10) / 2;
                DAT_00531590._0_1_ = (byte)local_10;
                _DAT_0067f374 = _DAT_0067f374 | 1 << ((byte)DAT_00531590 & 0x1f);
                DAT_00531590 = iVar3;
                *(undefined4 *)(&DAT_005224e8 + local_10 * 0x10) = 0;
                FUN_0040b3c2(6,local_10);
              }
              DAT_00531590 = -1;
            }
          }
          else {
            local_48 = *(int *)(&DAT_0067bdf4 + *(int *)(&DAT_005224e8 + local_10 * 0x10) * 100) -
                       *(int *)(&DAT_0067bdf4 + arg_1 * 100);
            local_4c = *(int *)(&DAT_0067bdf8 + *(int *)(&DAT_005224e8 + local_10 * 0x10) * 100) -
                       *(int *)(&DAT_0067bdf8 + arg_1 * 100);
            local_24 = local_24 + 0x10;
            strcpy(&g_OverworldWorldState,s_Travel_00531e90);
            FUN_0050aef6(*(int *)(&DAT_0067bdf4 + *(int *)(&DAT_005224e8 + local_10 * 0x10) * 100),
                         *(int *)(&DAT_0067bdf8 + *(int *)(&DAT_005224e8 + local_10 * 0x10) * 100));
            strcat(&g_OverworldWorldState,&DAT_00531e98);
            Ai_TownEncounter_004c3b19(*(uint *)(&DAT_005224e8 + local_10 * 0x10));
            strcat(&g_OverworldWorldState,&DAT_00531ea0);
            local_24 = local_24 + 8;
            FUN_0040c336(&g_OverworldWorldState,local_1c,local_24,0x8d);
            local_24 = local_24 + 8;
            DAT_00531590 = local_10;
            App_ProcessPendingMessages();
            Ai_Subsystem_004cd1d1();
          }
        }
      }
      Palette_Subsystem_00496eaf();
      iVar3 = DAT_0067bddc;
      if (DAT_0067bddc < DAT_00641020) {
        DAT_00522450 = 0xffffffff;
      }
    }
  }
  else {
    FUN_0040a95d(s_village_pic_0053193c + ((*(int *)(&DAT_0067bdf0 + arg_1 * 100) == 1) - 1 & 0xc));
    Glue_Subsystem_004eadb7(1);
    for (local_2c = 0; local_2c < 0x10; local_2c = local_2c + 1) {
      (&DAT_006b2dd0)[local_2c] = -1;
      (&DAT_006b2d90)[local_2c] = (&DAT_006b2dd0)[local_2c];
    }
    Glue_Subsystem_004eccd7();
    local_44 = *(int *)(&DAT_0067bdf8 + arg_1 * 100);
    for (local_2c = 0; local_2c < *(int *)(&DAT_0067bdf4 + arg_1 * 100) % 3 + 1;
        local_2c = local_2c + 1) {
      do {
        do {
          local_30 = local_44 % 500;
          local_44 = local_44 + 7;
        } while (*(int *)(&deck + local_30 * 4) == -1);
      } while ((((&DAT_00702151)[local_30 * 4] & 0x40) != 0) ||
              ((*(uint *)(&deck + local_30 * 4) & 0xfff) < 5));
      (&DAT_006b2d90)[local_2c] = *(uint *)(&deck + local_30 * 4) & 0xfff;
      FUN_0050b206(*(uint *)(&deck + local_30 * 4) & 0xfff,local_2c * 0x28 + 0x60,
                   local_2c * 3 + 0x80,1,s_Your_ANTE_00531954);
    }
    local_3c = *(int *)(&DAT_0067be00 + arg_1 * 100) >> 8;
    switch((int)(DAT_0052f004 + (DAT_0052f004 >> 0x1f & 0x7fU)) >> 7) {
    case 0:
      local_18 = (LPVOID)0x4;
      break;
    case 1:
      local_18 = (LPVOID)0x6;
      break;
    case 2:
      local_18 = (LPVOID)0x8;
      break;
    case 3:
      local_18 = (LPVOID)0xc;
      break;
    case 4:
      local_18 = (LPVOID)0x10;
      break;
    default:
      if (((&DAT_0067bdf8)[arg_1 * 100] & 1) == 0) {
        local_18 = (LPVOID)0xe;
      }
      else {
        local_18 = (LPVOID)0x12;
      }
    }
    local_18 = (LPVOID)Glue_Subsystem_004ea97c(local_3c,(int)local_18);
    FUN_004909d3((int)local_18,0xffffffff,0,-1);
    do {
      do {
        DAT_006b2dd0 = FUN_0040a02a(DAT_0052eff8);
      } while (DAT_006b2dd0 < 5);
    } while (((&DAT_0051aed1)[DAT_006b2dd0 * 0x34] & 1) != 0);
    FUN_0050b206(DAT_006b2dd0,0xe0,0x40,1,s_Wizard_s_ANTE_00531960);
    Pic_Load_advfac64_00489188(local_18,0xa0,0x20,1,2);
    strcpy(&g_OverworldWorldState,s_This_place_is_ruled_by_the_00531970);
    pcVar2 = (char *)Mem_AllocOrFree_00473d7e(local_3c);
    strcat(&g_OverworldWorldState,pcVar2);
    strcat(&g_OverworldWorldState,s_Wizard_You_must_duel_0053198c);
    Glue_Subsystem_004eaa19((int)local_18,1,0);
    strcat(&g_OverworldWorldState,s_to_free_the_city__Never_mind__Du_005319a4);
    iVar3 = FUN_004896be(&g_OverworldWorldState,0x78,0x38);
    if (iVar3 == 1) {
      iVar3 = Math_RandomRange(3);
      DAT_0068a64c = Pic_Subsystem_0045268f
                               (*(int *)(&DAT_00527f10 + iVar3 * 4 + (local_3c * 3 + -3) * 4));
      _DAT_0067f354 = local_3c;
      _DAT_0067f348 = local_18;
      local_40 = Pic_Subsystem_0045268f(*(int *)(&DAT_0052262c + (int)local_18 * 0x44));
      FUN_004909d3((int)local_18,local_40,0,-1);
      DAT_006b2d64 = local_3c;
      DAT_0063ee24 = 0;
      DAT_00695df0 = 3;
      local_8 = Pic_Load_0044ef70(local_40,local_18);
      if (local_8 == 1) {
        Glue_Subsystem_004ebfef(1);
        *(uint *)(&DAT_0067be00 + arg_1 * 100) = *(uint *)(&DAT_0067be00 + arg_1 * 100) & 0xffff00ff
        ;
        Mem_AllocOrFree_00510de0(1,s_celeb_pic_005319dc);
        Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,
                           (int *)g_DisplaySurfaceScreen,0,0,g_DisplayScreenWidth,g_DisplayScreenHeight);
        g_OverworldWorldState = 0;
        Ai_TownEncounter_004c3b19(arg_1);
        strcat(&g_OverworldWorldState,s_is_freed__The_people_rejoice__005319e8);
        FUN_004896be(&g_OverworldWorldState,0x14,0x14);
        FUN_0040b3c2(7,arg_1);
      }
      if (local_8 == 0) {
        Glue_Subsystem_004ebfef(2);
        for (local_2c = 0; local_2c < 3; local_2c = local_2c + 1) {
          local_34 = (&DAT_006b2d90)[local_2c];
          if (local_34 != 0xffffffff) {
            Mem_AllocOrFree_00510de0(1,s_losedul2_pic_00531a08);
            Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,
                               (int *)g_DisplaySurfaceScreen,0,0,g_DisplayScreenWidth,g_DisplayScreenHeight);
            strcpy(&g_OverworldWorldState,s_Lost_this_card_00531a18);
            FUN_0050b206(local_34,0x17,0x50,1,&g_OverworldWorldState);
            App_ProcessPendingMessages();
            Ai_Subsystem_004cd1d1();
            FUN_00489630(local_34);
          }
        }
      }
    }
    Glue_Subsystem_004eadb7(0);
    Pic_Subsystem_00423c82(0x10);
    Palette_Subsystem_00496eaf();
    iVar3 = 0;
  }
  return iVar3;
}

/*
 * Decompiled function: Town_Process_00507c86
 * Entry Point: 00507c86
 * Size: 4024 bytes
 */


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
  
  App_ProcessPendingMessages();
  DAT_0062680c = arg_1;
  uVar2 = Surface_GetPixelColor(*(int *)(&DAT_0067bdf4 + arg_1 * 100),*(int *)(&DAT_0067bdf8 + arg_1 * 100));
  local_50 = Glue_Subsystem_004ea7a6(uVar2);
  local_20 = *(int *)(&DAT_0067bdf0 + DAT_0062680c * 100) + 3;
  if (DAT_005224f8 == 0) {
    local_20 = *(int *)(&DAT_0067bdf0 + DAT_0062680c * 100) + 4;
  }
  if (7 < local_20) {
    local_20 = 8;
  }
  local_14 = 0xffffffff;
  for (local_3c = 0; (int)local_3c < 199; local_3c = local_3c + 1) {
    iVar3 = Math_RandomRange(5);
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
  iVar3 = Math_RandomRange(3);
  if (((iVar3 == 0) && (((&DAT_0067be00)[arg_1 * 100] & 1) == 0)) ||
     (*(int *)(&DAT_0067bdf0 + arg_1 * 100) != 1)) {
LAB_00507faa:
    local_44 = Math_RandomRange(6);
    if (*(int *)(&DAT_0067f2d0 + local_44 * 0x14) < 1) {
      DAT_0061e100 = 0xffffffff;
    }
    else {
      DAT_0061e100 = arg_1;
      DAT_0061e05c = -*(int *)(&DAT_0067f2d0 + local_44 * 0x14);
    }
    iVar3 = Math_RandomRange(4);
    if ((iVar3 == 0) || (DAT_0061e100 == 0xffffffff)) {
      DAT_0061e100 = arg_1;
      iVar3 = Math_RandomRange(8);
      iVar3 = Glue_Subsystem_004ea97c(local_14,iVar3 * 2 + 4);
      DAT_0061e05c = -iVar3;
      FUN_0046e70d(0,8);
      _DAT_0067f2d0 = 0xffffffff;
    }
  }
  else {
    local_1c = 0;
    do {
      DAT_0061e100 = Math_RandomRange(0x80);
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
    iVar3 = Math_RandomRange(2);
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
    iVar3 = Math_RandomRange(5);
    local_44 = iVar3 + 1;
    iVar3 = Pic_Subsystem_004521a6(1 << ((byte)local_44 & 0x1f),1 << ((byte)local_14 & 0x1f),3);
    if ((iVar3 == 0) && (iVar3 = Math_RandomRange(2), iVar3 != 0)) {
      DAT_0061e05c = 1;
      _DAT_0061e058 = local_44;
    }
  }
  if (DAT_0061e05c != 1) {
    uVar2 = Surface_GetPixelColor(*(int *)(&DAT_0067bdf4 + DAT_0061e100 * 100),
                         *(int *)(&DAT_0067bdf8 + DAT_0061e100 * 100));
    local_44 = Glue_Subsystem_004ea7a6(uVar2);
    do {
      iVar3 = Math_RandomRange(5);
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
  local_44 = Math_RandomRange(local_20);
  for (local_3c = 0; (int)local_3c < local_20; local_3c = local_3c + 1) {
    if ((*(int *)(&DAT_0061e060 + local_3c * 4) == -1) &&
       (DAT_0067f380 * 5 + 0xf <=
        DAT_00641020 - *(int *)(&DAT_0067be24 + local_3c * 4 + arg_1 * 100))) {
      bVar1 = Math_RandomRange(7);
      local_34 = 1 << (bVar1 & 0x1f);
      do {
        if (local_3c == local_44) {
          local_58 = Math_RandomRange(5);
          *(uint *)(&DAT_0061e060 + local_3c * 4) = local_58;
        }
        else {
          local_58 = Math_RandomRange(g_MasterCardCount + -0x29);
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
        iVar3 = Glue_Subsystem_004f0b50(local_58);
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
    iVar3 = Math_RandomRange(local_a4);
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
      uVar2 = Math_Clamp((local_30 / 0x32) * 5,5,1000);
      *(undefined4 *)(&DAT_0061e0a0 + local_3c * 4) = uVar2;
    }
  }
  *(uint *)(&DAT_0067be00 + arg_1 * 100) = *(uint *)(&DAT_0067be00 + arg_1 * 100) | 8;
LAB_005085a9:
  DAT_006265f4 = *(int *)(&DAT_0067bdf0 + arg_1 * 100) * 5 + 10;
  local_8 = DAT_006265f4;
  Pic_Subsystem_00423b93(0x12);
  Glue_Subsystem_004ec5be(s_x_sound_button_wav_00531f44,0x12,0);
  do {
    if (local_20 == 0) {
      iVar3 = Card_ColorMaskToColorIndex((byte)local_50);
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

/*
 * Decompiled function: Town_Process_00508c3e
 * Entry Point: 00508c3e
 * Size: 153 bytes
 */


void Town_Process_00508c3e(void)

{
  if (DAT_006265f4 <= Gold) {
    DAT_00522448 = DAT_00522448 + 10;
    Gold = Gold - DAT_006265f4;
  }
  Ai_Subsystem_004c3c5c(1);
  *(undefined4 *)g_DisplaySurfaceScreen = 1;
  FUN_0040a883(s_village_pic_0053201c +
               ((*(int *)(&DAT_0067bdf0 + DAT_0061e0d4 * 100) == 1) - 1 & 0xc));
  *(undefined4 *)g_DisplaySurfaceScreen = 0;
  FUN_00507b44(0x53173c,1);
  return;
}

/*
 * Decompiled function: Town_Process_00508cd7
 * Entry Point: 00508cd7
 * Size: 1671 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Town_Process_00508cd7(void)

{
  undefined *puVar1;
  int arg_1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  bool bVar5;
  uint local_18;
  int local_8;
  
  arg_1 = DAT_0062680c;
  puVar1 = PTR_FUN_00527b3c;
  if (((&DAT_0067be00)[DAT_0062680c * 100] & 4) == 0) {
    if (((DAT_00522450 == 0xffffffff) && (DAT_0061e100 != 0xffffffff)) &&
       ((DAT_0067f380 + 3) * 0x10 < DAT_00641020 - *(int *)(&DAT_0067be44 + DAT_0062680c * 100))) {
      FUN_0040a95d(s_wiseman3_pic_005320c0);
      DAT_00522450 = DAT_0061e100;
      DAT_0067b9a0 = _DAT_0061e058;
      DAT_0067f2c0 = DAT_0061e05c;
      if ((DAT_0061e05c == 0) || (DAT_0061e05c == 2)) {
        strcpy(&g_OverworldWorldState,s_Take_this_message_005320d0);
        DAT_0067f3bc = FUN_0050aef6(*(int *)(&DAT_0067bdf4 + DAT_00522450 * 100),
                                    *(int *)(&DAT_0067bdf8 + DAT_00522450 * 100));
        FUN_0040c81c(0x80,*(int *)(&DAT_0067bdf4 + DAT_00522450 * 100),
                     *(int *)(&DAT_0067bdf8 + DAT_00522450 * 100));
        strcat(&g_OverworldWorldState,s_to_my_brother__the_keeper_of_005320e4);
        Ai_TownEncounter_004c3b19(DAT_00522450);
        strcat(&g_OverworldWorldState,s___He_will_reward_you_with_00532104);
        bVar5 = DAT_0067f2c0 != 0;
        if (!bVar5) {
          strcat(&g_OverworldWorldState,s_a_mana_link__00532120);
        }
        local_18 = (uint)bVar5;
        local_8 = 0x20;
      }
      if (DAT_0067f2c0 == 1) {
        strcpy(&g_OverworldWorldState,s_Take_a_00532130);
        FUN_0050b1a0();
        strcat(&g_OverworldWorldState,&DAT_00532138);
        FUN_0050aef6(*(int *)(&DAT_0067bdf4 + DAT_00522450 * 100),
                     *(int *)(&DAT_0067bdf8 + DAT_00522450 * 100));
        FUN_0040c81c(0x80,*(int *)(&DAT_0067bdf4 + DAT_00522450 * 100),
                     *(int *)(&DAT_0067bdf8 + DAT_00522450 * 100));
        strcat(&g_OverworldWorldState,s_to_the_keeper_of_0053213c);
        Ai_TownEncounter_004c3b19(DAT_00522450);
        strcat(&g_OverworldWorldState,s___He_will_give_you_a_mana_link_a_00532150);
        local_18 = 1;
        pcVar4 = _itoa(1,&DAT_0061e0f0,10);
        strcat(&g_OverworldWorldState,pcVar4);
        strcat(&g_OverworldWorldState,&DAT_00532174);
        local_8 = 0x28;
      }
      if (DAT_0067f2c0 < 0) {
        local_18 = (int)(char)(&DAT_00522628)[DAT_0067f2c0 * -0x44] / 7 + 1;
        strcpy(&g_OverworldWorldState,s_Defeat_the_00532178);
        Glue_Subsystem_004eaa19(-DAT_0067f2c0,0,0);
        if ((&DAT_00522628)[DAT_0067f2c0 * -0x44] == '\x12') {
          strcat(&g_OverworldWorldState,s_Dragon_00532184);
        }
        strcat(&g_OverworldWorldState,s_which_has_been_menacing_our_vill_0053218c);
        if (*(int *)(&DAT_0067bdf0 + arg_1 * 100) == 1) {
          pcVar4 = _itoa(local_18,&DAT_0061e0f0,10);
          strcat(&g_OverworldWorldState,pcVar4);
          strcat(&g_OverworldWorldState,&DAT_005321dc);
        }
        else {
          FUN_0050a73e(arg_1);
          strcat(&g_OverworldWorldState,&DAT_005321e0);
          local_18 = 0;
        }
        local_8 = 0x18;
      }
      if (local_18 != 0) {
        pcVar4 = (char *)Mem_AllocOrFree_00473d7e(DAT_0067b9a0);
        strcat(&g_OverworldWorldState,pcVar4);
        strcat(&g_OverworldWorldState,s_amulet__005321e4 + ((local_18 == 1) - 1 & 0xc));
      }
      strcat(&g_OverworldWorldState,s_Accept_the_Quest_Never_mind__005321fc);
      PTR_FUN_00527b3c = Mem_AllocOrFree_0040eea2;
      iVar2 = FUN_004896be(&g_OverworldWorldState,0x2d,0x24);
      if (iVar2 == 0) {
        FUN_0040a883(s_wiseman3_pic_00532220);
        DAT_0067f370 = arg_1;
        DAT_0067bddc = local_8 * 2 + DAT_00641020 + -1;
        *(int *)(&DAT_0067be44 + arg_1 * 100) = DAT_00641020;
        strcpy(&g_OverworldWorldState,s_You_have_00532230);
        pcVar4 = _itoa((int)(local_8 + (local_8 >> 0x1f & 7U)) >> 3,&DAT_0061e0f0,10);
        strcat(&g_OverworldWorldState,pcVar4);
        strcat(&g_OverworldWorldState,s_days_to_complete_the_quest__0053223c);
        FUN_004896be(&g_OverworldWorldState,0x48,0x48);
        FUN_0040c81c(0x80,*(int *)(&DAT_0067bdf4 + arg_1 * 100),
                     *(int *)(&DAT_0067bdf8 + arg_1 * 100));
        FUN_0040b3c2(0xf,DAT_0067f2c0);
        PTR_FUN_00527b3c = puVar1;
      }
      else {
        DAT_00522450 = 0xffffffff;
        DAT_0067f2c0 = 0;
        PTR_FUN_00527b3c = puVar1;
      }
    }
    else {
      Dungeon_Process_0040fcfd(DAT_00626604,(uint)(DAT_0062680c != DAT_00531594),DAT_0062680c);
    }
    DAT_00531594 = arg_1;
    Ai_Subsystem_004c3c5c(1);
    FUN_0040a95d(s_village_pic_0053225c + ((*(int *)(&DAT_0067bdf0 + arg_1 * 100) == 1) - 1 & 0xc));
  }
  else {
    FUN_0040a95d(s_wiseman3_pic_00532034);
    strcpy(&g_OverworldWorldState,s_You_failed_to_complete_your_last_00532044);
    strcat(&g_OverworldWorldState,s_The_people_have_no_new_quest_for_00532080);
    *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 1;
    iVar2 = Ai_Util_004c3bc4(0x13c);
    iVar3 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
    iVar2 = iVar2 + iVar3 * -4;
    iVar3 = Ai_Util_004c3bc4(0x50);
    FUN_0040d1cd((int)g_DisplaySurfaceScreen,0xc1,iVar3,iVar2);
    App_ProcessPendingMessages();
    Ai_Subsystem_004cd1d1();
    FUN_0040a95d(s_village_pic_005320a8 + ((*(int *)(&DAT_0067bdf0 + arg_1 * 100) == 1) - 1 & 0xc));
  }
  DAT_006265fc = 0xfffffffe;
  return;
}

/*
 * Decompiled function: Merchant_ProcessBuy_00509517
 * Entry Point: 00509517
 * Size: 2749 bytes
 */


void Merchant_ProcessBuy_00509517(void)

{
  undefined4 arg_1;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  void *arg_6;
  int local_100;
  void *local_fc;
  int local_f8;
  undefined4 local_f4;
  undefined4 auStack_f0 [6];
  undefined4 auStack_d8 [4];
  int local_c8;
  int local_c4;
  int local_c0;
  undefined4 local_bc;
  int local_b8;
  int local_b4;
  int local_b0;
  int local_ac;
  int local_a8;
  int local_a4 [40];
  
  local_a8 = DAT_0062680c;
  local_ac = 0;
  App_ProcessPendingMessages();
  arg_1 = Surface_GetPixelColor(*(int *)(&DAT_0067bdf4 + local_a8 * 100),
                       *(int *)(&DAT_0067bdf8 + local_a8 * 100));
  local_bc = Glue_Subsystem_004ea7a6(arg_1);
  local_ac = *(int *)(&DAT_0067bdf0 + local_a8 * 100) + 3;
  if (DAT_005224f8 == 0) {
    local_ac = *(int *)(&DAT_0067bdf0 + local_a8 * 100) + 4;
  }
  if (local_ac == 0) {
    iVar1 = Card_ColorMaskToColorIndex((byte)local_bc);
    *(int *)(&DAT_0061e060 + local_ac * 4) = iVar1 + -1;
    *(undefined4 *)(&DAT_0061e0a0 + local_ac * 4) = 0x28;
    local_ac = local_ac + 1;
  }
  Sprite_LoadAll(&local_fc,s_BuyButtons_spr_00532274);
  DAT_0061e0d8 = local_fc;
  DAT_0061e114 = local_f8;
  DAT_0061e0c0 = local_f4;
  for (local_100 = 0; local_100 < 3; local_100 = local_100 + 1) {
    (&DAT_0061e108)[local_100] = auStack_f0[local_100];
  }
  for (local_100 = 0; local_100 < 3; local_100 = local_100 + 1) {
    *(undefined4 *)(&DAT_0061e0c8 + local_100 * 4) = auStack_f0[local_100 + 3];
  }
  for (local_100 = 0; local_100 < 3; local_100 = local_100 + 1) {
    *(undefined4 *)(&DAT_0061e0e0 + local_100 * 4) = auStack_f0[local_100 + 6];
  }
  FUN_00510b70(1,0,g_DisplayScreenHeight + -0x118,s_buycards_pic_00532284,(short *)0x0);
  iVar1 = Ai_Util_004c3ba3(0x8c);
  iVar2 = Ai_Util_004c3ba3(0x100);
  iVar3 = Ai_Util_004c3ba3(0x18);
  iVar4 = Ai_Util_004c3ba3(0x20);
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,g_DisplayScreenHeight + -0x118,0x200,0x118,
                     (int *)g_DisplaySurfaceScreen,iVar4,iVar3,iVar2,iVar1);
  iVar1 = Ai_Util_004c3ba3(0x8c);
  iVar2 = Ai_Util_004c3ba3(0x100);
  iVar3 = Ai_Util_004c3ba3(0x18);
  iVar4 = Ai_Util_004c3ba3(0x20);
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,g_DisplayScreenHeight + -0x118,0x200,0x118,
                     (int *)g_DisplaySurfaceBackBuffer,iVar4,iVar3,iVar2,iVar1);
  FUN_0050b9d5(g_DisplaySurfaceScreen);
  if (DAT_006265f8 != -1) {
    Merchant_ProcessBuy_00407b34(DAT_006265f8);
  }
  local_c8 = FUN_0041f354();
  Mem_AllocOrFree_0041f12b(local_c8);
  if (DAT_005318a0 == DAT_00531890) {
    DAT_005318a0 = Ai_Util_004c3bc4(DAT_005318a0);
    DAT_005318a4 = Ai_Util_004c3bc4(DAT_005318a4);
    DAT_005318a8 = Ai_Util_004c3bc4(DAT_005318a8);
    DAT_005318ac = Ai_Util_004c3bc4(DAT_005318ac);
  }
  FUN_0041f17e(0x531890,1,local_c8);
LAB_00509872:
  Mem_AllocOrFree_00510e20(1,s_buycards_pic_00532294);
  iVar1 = Ai_Util_004c3ba3(0x8c);
  iVar2 = Ai_Util_004c3ba3(0x100);
  iVar3 = Ai_Util_004c3ba3(0x18);
  iVar4 = Ai_Util_004c3ba3(0x20);
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x200,0x118,(int *)g_DisplaySurfaceScreen
                     ,iVar4,iVar3,iVar2,iVar1);
  FUN_0050b9d5(g_DisplaySurfaceScreen);
  FUN_0041f213();
  FUN_0041f3ea(DAT_0067bda4,DAT_0067bda8,DAT_007039c4);
  *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 4;
  iVar1 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
  iVar2 = FUN_0040c465(s_Cards_for_Sale_005322a4);
  Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,(g_DisplayScreenWidth / 2 - iVar2 / 2) + -0x14,
                    (g_DisplayScreenHeight * 0x1f) / 0xf0 - iVar1,iVar2 + 0x28,iVar1 * 3,DAT_0061e114);
  FUN_0040c336(s_Cards_for_Sale_005322b4,0xa0,0x1f,0x1b);
  local_b0 = 0x40;
  local_c4 = (int)(0xf4 / (longlong)local_ac);
  memset(local_a4,0xff,0xa0);
  local_b4 = local_ac;
  while (local_b4 = local_b4 + -1, -1 < local_b4) {
    if (*(int *)(&DAT_0061e060 + local_b4 * 4) != -1) {
      FUN_0040c6c7(g_DisplaySurfaceScreen,local_c4 * local_b4 + 0x2c,
                   (*(uint *)(&DAT_0061e060 + local_b4 * 4) & 7) + local_b0 + -0xc,local_c4 + -4,0xc
                   ,DAT_0061e0c0);
      g_OverworldWorldState = 0;
      pcVar5 = _itoa(*(int *)(&DAT_0061e0a0 + local_b4 * 4),&DAT_0061e0f0,10);
      strcat(&g_OverworldWorldState,pcVar5);
      strcat(&g_OverworldWorldState,s_gold_005322c4);
      *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 1;
      FUN_0040c336(&g_OverworldWorldState,local_c4 * local_b4 + local_c4 / 2 + 0x29,
                   (*(uint *)(&DAT_0061e060 + local_b4 * 4) & 7) + local_b0 + -8,0x1b);
      pcVar5 = &DAT_005322cc;
      iVar3 = 0;
      iVar1 = (*(uint *)(&DAT_0061e060 + local_b4 * 4) & 7) + local_b0 + 4;
      iVar2 = Math_Clamp(local_c4 * local_b4 + local_c4 / 2 + 0x12,0,g_DisplayScreenWidth + -0x62);
      FUN_0050b206(*(int *)(&DAT_0061e060 + local_b4 * 4),iVar2,iVar1,iVar3,pcVar5);
      iVar1 = Math_Clamp(local_c4 * local_b4 + local_c4 / 2 + 0x12,0,g_DisplayScreenWidth + -0x62);
      iVar1 = Ai_Util_004c3ba3(iVar1);
      local_a4[local_b4 * 4] = iVar1;
      iVar1 = Ai_Util_004c3ba3((*(uint *)(&DAT_0061e060 + local_b4 * 4) & 7) + local_b0 + 4);
      local_a4[local_b4 * 4 + 1] = iVar1;
      iVar1 = local_a4[local_b4 * 4];
      iVar2 = Ai_Util_004c3ba3(0x30);
      local_a4[local_b4 * 4 + 2] = iVar1 + iVar2;
      iVar1 = local_a4[local_b4 * 4 + 1];
      iVar2 = Ai_Util_004c3ba3(0x30);
      local_a4[local_b4 * 4 + 3] = iVar1 + iVar2;
    }
  }
  DAT_00626600 = 0;
  do {
    while( true ) {
      if (DAT_00626600 != 0) {
        FUN_0041f391();
        Ai_Subsystem_004c05ba();
        Ai_Subsystem_004c3c5c(1);
        FUN_0040a95d(s_village_pic_005322f0 +
                     ((*(int *)(&DAT_0067bdf0 + local_a8 * 100) == 1) - 1 & 0xc));
        DAT_006265fc = 0xfffffffe;
        Mem_AllocOrFree_0050fc50(DAT_0061e0d8);
        return;
      }
      local_c0 = -1;
      Pic_Subsystem_0044b84b();
      if (DAT_007039c4 != 0) break;
      FUN_0041f3ea(DAT_0067bda4,DAT_0067bda8,0);
    }
    for (local_b4 = 0; local_b4 < local_ac; local_b4 = local_b4 + 1) {
      if ((((local_a4[local_b4 * 4] <= DAT_0067bda4) && (DAT_0067bda4 <= local_a4[local_b4 * 4 + 2])
           ) && (local_a4[local_b4 * 4 + 1] <= DAT_0067bda8)) &&
         (DAT_0067bda8 <= local_a4[local_b4 * 4 + 3])) {
        local_c0 = local_b4;
        break;
      }
    }
    if (local_c0 != -1) break;
    FUN_0041f3ea(DAT_0067bda4,DAT_0067bda8,DAT_007039c4);
  } while( true );
  sprintf(&g_OverworldWorldState,s_Buy_for__d_gold___Y_N__005322d0,
          *(undefined4 *)(&DAT_0061e0a0 + local_b4 * 4));
  arg_6 = DAT_0061e0d8;
  iVar1 = Ai_Util_004c3ba3(0x10f);
  iVar1 = iVar1 / 2;
  iVar2 = Ai_Util_004c3ba3(0xc5);
  iVar2 = iVar2 / 2;
  iVar3 = Ai_Util_004c3ba3(0x34);
  iVar3 = iVar3 / 2;
  iVar4 = Ai_Util_004c3ba3(0xdc);
  Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,iVar4 / 2,iVar3,iVar2,iVar1,(int)arg_6);
  FUN_0050b3de(*(int *)(&DAT_0061e060 + local_b4 * 4),0x7a,0x29,0x4b,0x70,1,&DAT_005322ec);
  FUN_0040d339((int)g_DisplaySurfaceScreen,0x1b,0x140,0x47);
  App_ProcessPendingMessages();
  local_b8 = FUN_0048ac2f();
  if (((local_b8 == 0x79) || (local_b8 == 0x59)) && (*(int *)(&DAT_0061e0a0 + local_b4 * 4) <= Gold)
     ) {
    Gold = Gold - *(int *)(&DAT_0061e0a0 + local_b4 * 4);
    iVar1 = Pic_Subsystem_00451e40(*(uint *)(&DAT_0061e060 + local_b4 * 4));
    *(uint *)(&deck + iVar1 * 4) = *(uint *)(&deck + iVar1 * 4) | 0x4000;
    *(undefined4 *)(&DAT_0061e060 + local_b4 * 4) = 0xffffffff;
    *(undefined4 *)(&DAT_0061e0a0 + local_b4 * 4) = 0;
    if (DAT_00626808 == local_b4) {
      DAT_006265f8 = -1;
    }
    iVar1 = Math_RandomRange(5);
    *(int *)(&DAT_0067be24 + local_b4 * 4 + local_a8 * 100) =
         iVar1 * (DAT_0067f380 + 2) + DAT_00641020;
    FUN_0040a566();
    Ai_Subsystem_004c3c5c(1);
  }
  goto LAB_00509872;
}

/*
 * Decompiled function: Town_Process_00509fd4
 * Entry Point: 00509fd4
 * Size: 145 bytes
 */


void Town_Process_00509fd4(void)

{
  int iVar1;
  
  iVar1 = DAT_0062680c;
  FUN_0040eeb4(DAT_00626604,DAT_0062680c);
  *(undefined4 *)(&DAT_0067be48 + iVar1 * 100) = DAT_00641020;
  Ai_Subsystem_004c05ba();
  FUN_0040a566();
  Ai_Subsystem_004c3c5c(1);
  FUN_0040a95d(s_village_pic_00532308 + ((*(int *)(&DAT_0067bdf0 + iVar1 * 100) == 1) - 1 & 0xc));
  DAT_006265fc = 0xfffffffe;
  return;
}

/*
 * Decompiled function: Town_Process_0050a065
 * Entry Point: 0050a065
 * Size: 152 bytes
 */


void Town_Process_0050a065(void)

{
  int iVar1;
  
  iVar1 = DAT_0062680c;
  Glue_Subsystem_004ebcdc(s_x_sound_button2_wav_00532320,0xf,100,100,0);
  Surface_TransformPoint(0,(short)DAT_00530d9c);
  DeckBuilderMain(_hwndScreen,1,3);
  Pic_Load_advfac64_0040a4fc();
  Ai_Subsystem_004c05ba();
  Ai_Subsystem_004c3c5c(1);
  FUN_0040a95d(s_village_pic_00532334 + ((*(int *)(&DAT_0067bdf0 + iVar1 * 100) == 1) - 1 & 0xc));
  DAT_006265fc = 0xfffffffe;
  return;
}

/*
 * Decompiled function: Town_Process_0050a0fd
 * Entry Point: 0050a0fd
 * Size: 126 bytes
 */


void Town_Process_0050a0fd(void)

{
  int iVar1;
  
  iVar1 = DAT_0062680c;
  Glue_Subsystem_004ebcdc(s_x_sound_button2_wav_0053234c,0xf,100,100,0);
  Ai_CastleEncounter_004c24b3(0);
  Ai_Subsystem_004c05ba();
  Ai_Subsystem_004c3c5c(1);
  FUN_0040a95d(s_village_pic_00532360 + ((*(int *)(&DAT_0067bdf0 + iVar1 * 100) == 1) - 1 & 0xc));
  DAT_006265fc = 0xfffffffe;
  return;
}

/*
 * Decompiled function: Town_Process_0050a17b
 * Entry Point: 0050a17b
 * Size: 126 bytes
 */


void Town_Process_0050a17b(void)

{
  int iVar1;
  
  iVar1 = DAT_0062680c;
  Glue_Subsystem_004ebcdc(s_x_sound_button2_wav_00532378,0xf,100,100,0);
  Castle_Process_0048f523(1);
  Ai_Subsystem_004c05ba();
  Ai_Subsystem_004c3c5c(1);
  FUN_0040a95d(s_village_pic_0053238c + ((*(int *)(&DAT_0067bdf0 + iVar1 * 100) == 1) - 1 & 0xc));
  DAT_006265fc = 0xfffffffe;
  return;
}

/*
 * Decompiled function: Town_Process_0050a1f9
 * Entry Point: 0050a1f9
 * Size: 105 bytes
 */


void Town_Process_0050a1f9(void)

{
  int iVar1;
  
  iVar1 = DAT_0062680c;
  Town_Process_00490d7b(1);
  Ai_Subsystem_004c05ba();
  Ai_Subsystem_004c3c5c(1);
  FUN_0040a95d(s_village_pic_005323a4 + ((*(int *)(&DAT_0067bdf0 + iVar1 * 100) == 1) - 1 & 0xc));
  DAT_006265fc = 0xfffffffe;
  return;
}

/*
 * Decompiled function: Town_Process_0050a262
 * Entry Point: 0050a262
 * Size: 126 bytes
 */


void Town_Process_0050a262(void)

{
  int iVar1;
  
  iVar1 = DAT_0062680c;
  Glue_Subsystem_004ebcdc(s_x_sound_button2_wav_005323bc,0xf,100,100,0);
  App_ProcessPendingMessages();
  Castle_Process_00421b32();
  Ai_Subsystem_004c05ba();
  Ai_Subsystem_004c3c5c(1);
  FUN_0040a95d(s_village_pic_005323d0 + ((*(int *)(&DAT_0067bdf0 + iVar1 * 100) == 1) - 1 & 0xc));
  DAT_006265fc = 0xfffffffe;
  return;
}

/*
 * Decompiled function: SellPrice
 * Entry Point: 0050a8ae
 * Size: 273 bytes
 */


int SellPrice(int arg_1)

{
  undefined4 arg_1_00;
  int iVar1;
  int local_8;
  
                    /* 0x10a8ae  7  SellPrice */
  arg_1_00 = Surface_GetPixelColor(*(int *)(&DAT_0067bdf4 + DAT_0061e0fc * 100),
                          *(int *)(&DAT_0067bdf8 + DAT_0061e0fc * 100));
  iVar1 = Glue_Subsystem_004ea7a6(arg_1_00);
  local_8 = FUN_0050a9bf(arg_1);
  local_8 = (*(int *)(&DAT_0067bdf0 + DAT_0061e0fc * 100) + 2) * local_8;
  if (((char)(&DAT_0051aebe)[arg_1 * 0x34] != iVar1) && ((&DAT_0051aebe)[arg_1 * 0x34] != '\0')) {
    iVar1 = Pic_Subsystem_004521a6(iVar1,(int)(char)(&DAT_0051aebe)[arg_1 * 0x34],3);
    if (iVar1 == 0) {
      local_8 = (local_8 * 3) / 2;
    }
    else {
      local_8 = (local_8 * 4) / 3;
    }
  }
  return (local_8 / 0x32) * 5;
}

