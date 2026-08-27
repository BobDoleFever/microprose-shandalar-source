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
  FILE *match_count;
  int slot_idx;
  
  match_count = fopen(s_story_txt_00516504,&DAT_00516500);
  local_74 = 6;
  do {
    slot_idx = fscanf(match_count,s_______00516510,local_70);
    if (local_70[0] == '.') {
      local_74 = local_74 + 3;
    }
    else {
      FUN_0040c336(local_70,0xa0,local_74,0xff);
      local_74 = local_74 + 7;
    }
    slot_idx = fscanf(match_count,&DAT_00516518,local_70);
  } while (slot_idx != -1);
  return;
}

/*
 * Decompiled function: Tale_Load_0040710a
 * Entry Point: 0040710a
 * Size: 196 bytes
 */


void Tale_Load_0040710a(int player_id)

{
  int local_74;
  char local_70 [100];
  FILE *match_count;
  int slot_idx;
  
  match_count = fopen(s_tale_txt_00516524,&DAT_00516520);
  local_74 = 0;
  do {
    slot_idx = fscanf(match_count,s_______00516530,local_70);
    if (local_70[0] == '.') {
      local_74 = local_74 + 1;
    }
    else if (local_74 == arg_1) {
      strcat(&g_OverworldWorldState,local_70);
      strcat(&g_OverworldWorldState,&DAT_00516538);
    }
    slot_idx = fscanf(match_count,&DAT_0051653c,local_70);
  } while ((slot_idx != -1) && (local_74 <= arg_1));
  fclose(match_count);
  return;
}

/*
 * Decompiled function: Merchant_ProcessBuy_00407b34
 * Entry Point: 00407b34
 * Size: 776 bytes
 */


void Merchant_ProcessBuy_00407b34(int player_id)

{
  int val_1;
  int arg_4;
  int event_type;
  int card_slot;
  int local_458;
  void *local_454;
  int32_t local_450;
  int32_t local_44c;
  int32_t auStack_448 [6];
  int32_t auStack_430 [4];
  uint32_t local_420;
  int32_t auStack_41c [6];
  int32_t local_404;
  int32_t auStack_400 [3];
  char local_3f4 [1000];
  void *match_count;
  int32_t slot_idx;
  
  if (*(int *)(&DAT_00701944 + arg_1 * 8) == -1) {
    strcpy(&g_OverworldWorldState,s_The_card_seller_notes___If_you_b_005165fc);
    val_1 = Pic_Subsystem_0045268f(*(int *)(&DAT_00701940 + arg_1 * 8));
    strcat(&g_OverworldWorldState,s_Swamp_0051aea9 + val_1 * 0x34);
    strcat(&g_OverworldWorldState,s___you_can_00516628);
  }
  else {
    val_1 = FUN_00407747(*(int *)(&DAT_00701940 + arg_1 * 8));
    local_420 = (uint32_t)(val_1 != 0);
    strcpy(&g_OverworldWorldState,s_The_card_seller_suggests___If_yo_005165a0);
    val_1 = Pic_Subsystem_0045268f(*(int *)(&DAT_00701940 + local_420 * 4 + arg_1 * 8));
    strcat(&g_OverworldWorldState,s_Swamp_0051aea9 + val_1 * 0x34);
    strcat(&g_OverworldWorldState,s_with_the_005165d4);
    val_1 = Pic_Subsystem_0045268f(*(int *)(&DAT_00701940 + (local_420 ^ 1) * 4 + arg_1 * 8));
    strcat(&g_OverworldWorldState,s_Swamp_0051aea9 + val_1 * 0x34);
    strcat(&g_OverworldWorldState,s_you_already_have__you_can_005165e0);
  }
  Hints_GetNext_0040741b(arg_1);
  strcat(&g_OverworldWorldState,&DAT_00516634);
  Sprite_LoadAll(&local_454,s_BuyButtons_spr_00516638);
  match_count = local_454;
  slot_idx = local_450;
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
  val_1 = Ai_Util_004c3bc4(0x10f);
  arg_4 = Ai_Util_004c3bc4(0xc5);
  arg_3 = Ai_Util_004c3bc4(0x34);
  arg_2 = Ai_Util_004c3bc4(0xdc);
  Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,arg_2,arg_3,arg_4,val_1,(int)local_454);
  val_1 = Ai_Util_004c3bc4(0x85);
  FUN_00407843(&g_OverworldWorldState,local_3f4,val_1);
  Font_DrawTextInRect((int)g_DisplaySurfaceScreen,0xfe,0x140,0xbc);
  Ai_Subsystem_004cd1d1();
  Mem_AllocOrFree_0050fc50(match_count);
  return;
}

/*
 * Decompiled function: Castle_Process_0040b7fa
 * Entry Point: 0040b7fa
 * Size: 1193 bytes
 */


int Castle_Process_0040b7fa(int player_id)

{
  int val_1;
  char *mode_str;
  uint32_t uval_2;
  uint32_t target_idx;
  uint32_t player_idx;
  
  if (arg_1 < 0) {
    arg_1 = 0;
  }
  if (DAT_005384d8 < arg_1) {
    arg_1 = DAT_005384d8;
  }
  if (arg_1 == DAT_005384d4) {
    val_1 = 0;
  }
  else {
    g_OverworldWorldState = '\0';
    while (g_OverworldWorldState == '\0') {
      val_1 = *(int *)(&DAT_0067a9a0 + arg_1 * 0x10);
      uval_2 = *(uint32_t *)(&DAT_0067a9a4 + arg_1 * 0x10);
      player_idx = *(uint32_t *)(&DAT_0067a9a8 + arg_1 * 0x10);
      target_idx = *(uint32_t *)(&DAT_0067a9ac + arg_1 * 0x10);
      if (*(int *)(&DAT_0067a9a0 + arg_1 * 0x10) == 0) {
        return 0;
      }
      Surface_BlitToDevice((int *)g_DisplaySurfaceBackBuffer,0,0,g_AiManaColorCost_Red,g_AiManaColorCost_Green,
                   (int *)g_DisplaySurfaceScreen,0,0);
      g_OverworldWorldState = '\0';
      switch(val_1) {
      case 1:
        if ((uval_2 & 0x80) == 0) {
          strcat(&g_OverworldWorldState,s_Visited_00517354);
        }
        else {
          strcat(&g_OverworldWorldState,s_Completed_quest_at_00517340);
        }
        Ai_TownEncounter_004c3b19(uval_2 & 0x7f);
        break;
      case 2:
        if ((uval_2 & 0x80) == 0) {
          strcat(&g_OverworldWorldState,s_Lost_to_0051737c);
        }
        else {
          strcat(&g_OverworldWorldState,s_Defeated_00517370);
        }
        Glue_Subsystem_004eaa19(uval_2 & 0x7f,1,0);
        break;
      case 3:
        strcat(&g_OverworldWorldState,s_Explored_00517388);
        FUN_0048e2b0(uval_2 & 0x7f);
        break;
      case 4:
        if ((uval_2 & 0x80) == 0) {
          strcat(&g_OverworldWorldState,s_Entered_005173a0);
        }
        else {
          strcat(&g_OverworldWorldState,s_Defeated_00517394);
        }
        FUN_0048e2b0(uval_2 & 0x7f);
        strcat(&g_OverworldWorldState,&DAT_005173ac);
        str_2 = (char *)Mem_AllocOrFree_00473d7e((uval_2 & 0x7f) + 1);
        strcat(&g_OverworldWorldState,str_2);
        strcat(&g_OverworldWorldState,s_Castle__005173b0);
        break;
      case 5:
        strcat(&g_OverworldWorldState,s_Discovered_a_005173bc);
        FUN_0040eb04(uval_2);
        if ((int)uval_2 < 5) {
          g_OverworldWorldState = '\0';
        }
        break;
      case 6:
        strcat(&g_OverworldWorldState,s_Bought_WM__005173cc);
        strcat(&g_OverworldWorldState,(&PTR_s_Sleight_of_hand_005225d0)[uval_2]);
        break;
      case 7:
        strcat(&g_OverworldWorldState,s_Freed_00517360);
        Ai_TownEncounter_004c3b19(uval_2);
        break;
      case 8:
      case 9:
      case 10:
      case 0xb:
      case 0xc:
        val_1 = (val_1 + -8) * 0x100 + uval_2;
        strcat(&g_OverworldWorldState,s_Acquired_005173d8);
        Glue_Subsystem_004eaa9c((int)s_Swamp_0051aea9[val_1 * 0x34],0);
        strcat(&g_OverworldWorldState,s_Swamp_0051aea9 + val_1 * 0x34);
        strcat(&g_OverworldWorldState,s_spell_005173e4);
        break;
      case 0xd:
        strcat(&g_OverworldWorldState,s_Saved_00517368);
        Glue_Subsystem_004f0a4a(player_idx,target_idx);
        break;
      case 0x12:
        switch(uval_2 & 0xffff) {
        case 1:
        case 2:
          strcat(&g_OverworldWorldState,s_JUMP__005173ec);
          break;
        case 3:
          strcat(&g_OverworldWorldState,s_SPEED__005173f4);
          break;
        case 4:
          strcat(&g_OverworldWorldState,s_THUNDERED_on_005173fc);
          Glue_Subsystem_004eaa19((int)uval_2 >> 0x10,1,0);
          strcat(&g_OverworldWorldState,&DAT_0051740c);
          break;
        case 5:
          strcat(&g_OverworldWorldState,s_Went_to_aid_of_00517410);
          uval_2 = Glue_Subsystem_004f0a4a(player_idx,target_idx);
          Ai_TownEncounter_004c3b19(uval_2);
        }
      }
      arg_1 = arg_1 + 1;
    }
    DAT_005384e0 = 0xffffffff;
    DAT_005384dc = 0xffffffff;
    if (arg_1 + -1 == DAT_005384d4) {
      val_1 = 0;
    }
    else {
      FUN_0040bcff(player_idx,target_idx);
      val_1 = arg_1 + -1;
      DAT_005384d4 = val_1;
    }
  }
  return val_1;
}

/*
 * Decompiled function: Dungeon_Process_0040fcfd
 * Entry Point: 0040fcfd
 * Size: 3913 bytes
 */


int32_t Dungeon_Process_0040fcfd(int player_id,int card_slot,int event_type)

{
  int val_1;
  int val_2;
  int val_3;
  char *pcVar4;
  int32_t uval_5;
  uint32_t uval_6;
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
  uint32_t local_7d4 [500];
  
  local_7e8 = 0;
  FUN_0040a95d(s_wiseman3_pic_0051933c);
  if ((arg_2 == 0) && (local_7e8 = 1, DAT_00538608 != 0)) {
    if (DAT_00538608 == 1) goto LAB_0040ff03;
    if (DAT_00538608 == 2) goto LAB_004102e4;
  }
  while( true ) {
    val_1 = Util_GetRandomNumber(5);
    if (((val_1 == 0) || (local_7e8 != 0)) || (arg_2 == 0)) {
      if ((DAT_005175c0 == -1) || (arg_2 != 0)) {
        val_1 = rand();
        DAT_005175c0 = val_1 % 0xc;
      }
      local_7ec = (int *)(&PTR_s_Shandalar_was_not_always_as_it_i_00517560)[DAT_005175c0];
      val_1 = FUN_0040f681(local_7ec,local_818);
      local_820 = val_1 + -1;
      for (local_81c = 0; local_81c < local_820; local_81c = local_81c + 1) {
        local_7ec = (int *)local_818[local_81c];
        *(uint8_t *)(local_818[local_81c + 1] + -3) = 0;
        local_7f0 = FUN_0040f636((char *)local_7ec);
        *(int32_t *)(g_DisplaySurfaceScreen + 0x20) = 1;
        val_1 = Ai_Util_004c3bc4(0x13c);
        val_2 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
        val_1 = val_1 - val_2 * local_7f0;
        val_2 = Ai_Util_004c3bc4(0x50);
        FUN_0040d1cd((int)g_DisplaySurfaceScreen,0xc1,val_2,val_1);
        App_ProcessPendingMessages();
        Ai_Subsystem_004cd1d1();
        *(uint8_t *)(local_818[local_81c + 1] + -3) = 10;
        FUN_0040a883(s_wiseman3_pic_0051934c);
      }
      DAT_00538608 = 0;
      return 1;
    }
LAB_0040ff03:
    val_1 = Util_GetRandomNumber(5);
    if ((val_1 == 0) || (local_7e8 != 0)) break;
    DAT_00538608 = 2;
LAB_004102e4:
    val_1 = Util_GetRandomNumber(5);
    if ((val_1 < 2) || (local_7e8 != 0)) {
      if (g_AiManaColorCost_White != 0xffffffff) {
        if (((g_AiHandEvaluationBuffer == 0) || (g_AiHandEvaluationBuffer == 2)) ||
           ((g_AiHandEvaluationBuffer == 1 &&
            (val_1 = FUN_0050b0fc((uint8_t)DAT_0067b9a0,(uint8_t)(1 << ((uint8_t)g_AiManaColorCost_White & 3))),
            val_1 != 0)))) {
          strcpy(&g_OverworldWorldState,s_If_you_seek_the_00519398);
          if (g_AiHandEvaluationBuffer == 0) {
            strcat(&g_OverworldWorldState,s_mana_link__travel_005193c0);
          }
          else {
            pcVar4 = (char *)Mem_AllocOrFree_00473d7e(DAT_0067b9a0);
            strcat(&g_OverworldWorldState,pcVar4);
            strcat(&g_OverworldWorldState,s_amulet__travel_005193ac);
          }
          g_CampaignCompassHeading = FUN_0050aef6(*(int *)(&g_DungeonMapTileX + g_AiManaColorCost_White * 100),
                                      *(int *)(&g_DungeonMapTileY + g_AiManaColorCost_White * 100));
          strcat(&g_OverworldWorldState,&DAT_005193d4);
          Ai_TownEncounter_004c3b19(g_AiManaColorCost_White);
          strcat(&g_OverworldWorldState,&DAT_005193dc);
          *(int32_t *)(g_DisplaySurfaceScreen + 0x20) = 1;
          val_1 = Ai_Util_004c3bc4(0x13c);
          val_2 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
          val_1 = val_1 + val_2 * -2;
          val_2 = Ai_Util_004c3bc4(0x50);
          FUN_0040d1cd((int)g_DisplaySurfaceScreen,0xc1,val_2,val_1);
          App_ProcessPendingMessages();
          Ai_Subsystem_004cd1d1();
          return 0;
        }
        if (g_AiHandEvaluationBuffer == 1) {
          strcpy(&g_OverworldWorldState,s_I_see_that_the_people_of_005193e0);
          Ai_TownEncounter_004c3b19(g_AiManaColorCost_White);
          strcat(&g_OverworldWorldState,s_have_asked_for_a_005193fc);
          FUN_0050b1a0();
          strcat(&g_OverworldWorldState,&DAT_00519410);
          *(int32_t *)(g_DisplaySurfaceScreen + 0x20) = 1;
          val_1 = Ai_Util_004c3bc4(0x13c);
          val_2 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
          val_1 = val_1 + val_2 * -3;
          val_2 = Ai_Util_004c3bc4(0x50);
          FUN_0040d1cd((int)g_DisplaySurfaceScreen,0xc1,val_2,val_1);
          App_ProcessPendingMessages();
          Ai_Subsystem_004cd1d1();
          return 0;
        }
        if (g_AiHandEvaluationBuffer < 0) {
          if (g_AiHandEvaluationBuffer < -99) {
            strcpy(&g_OverworldWorldState,s_You_should_travel_00519414);
            g_CampaignCompassHeading = FUN_0050aef6(*(int *)(&g_DungeonMapTileX + g_AiManaColorCost_White * 100),
                                        *(int *)(&g_DungeonMapTileY + g_AiManaColorCost_White * 100));
            strcat(&g_OverworldWorldState,&DAT_00519428);
            Ai_TownEncounter_004c3b19(g_AiManaColorCost_White);
            strcat(&g_OverworldWorldState,s_to_claim_your_reward__00519430);
          }
          else {
            strcpy(&g_OverworldWorldState,s_I_see_that_the_people_of_00519448);
            Ai_TownEncounter_004c3b19(g_AiManaColorCost_White);
            strcat(&g_OverworldWorldState,s_have_asked_you_to_defeat_00519464);
            Glue_Subsystem_004eaa19(-g_AiHandEvaluationBuffer,1,0);
            strcat(&g_OverworldWorldState,&DAT_00519480);
          }
          *(int32_t *)(g_DisplaySurfaceScreen + 0x20) = 1;
          val_1 = Ai_Util_004c3bc4(0x13c);
          val_2 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
          val_1 = val_1 + val_2 * -3;
          val_2 = Ai_Util_004c3bc4(0x50);
          FUN_0040d1cd((int)g_DisplaySurfaceScreen,0xc1,val_2,val_1);
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
    uval_6 = (int)*(uint32_t *)(&g_DungeonMapTileX + arg_3 * 100) >> 0x1f;
    switch((*(int *)(&g_DungeonMapTileY + arg_3 * 100) % 3 - uval_6) +
           ((*(uint32_t *)(&g_DungeonMapTileX + arg_3 * 100) ^ uval_6) - uval_6 & 1 ^ uval_6)) {
    case 0:
      strcat(&g_OverworldWorldState,s_tell_you_a_tale_of_long_long_ago_00519514);
      *(int32_t *)(g_DisplaySurfaceScreen + 0x20) = 1;
      val_1 = Ai_Util_004c3bc4(0x13c);
      val_2 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
      val_1 = val_1 + val_2 * -7;
      val_2 = Ai_Util_004c3bc4(0x50);
      FUN_0040d1cd((int)g_DisplaySurfaceScreen,0xc1,val_2,val_1);
      App_ProcessPendingMessages();
      Ai_Subsystem_004cd1d1();
      local_7e8 = 1;
      FUN_0040a883(s_wiseman3_pic_00519538);
      break;
    case 1:
      local_7d8 = FUN_0050b00c();
      if (local_7d8 != -1) {
        strcat(&g_OverworldWorldState,s_tell_you_of_the_dungeons_which_h_00519548);
        *(int32_t *)(g_DisplaySurfaceScreen + 0x20) = 1;
        val_1 = Ai_Util_004c3bc4(0x13c);
        val_2 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
        val_1 = val_1 + val_2 * -7;
        val_2 = Ai_Util_004c3bc4(0x50);
        FUN_0040d1cd((int)g_DisplaySurfaceScreen,0xc1,val_2,val_1);
        App_ProcessPendingMessages();
        Ai_Subsystem_004cd1d1();
        FUN_0048ea81(local_7d8);
        uval_5 = Overworld_LoadAdventureInterface800();
        return uval_5;
      }
    case 2:
      if (g_AiManaColorCost_Blue == -1) {
        strcat(&g_OverworldWorldState,s_strengthen_you_with_two_extra_li_00519580);
        g_AiManaColorCost_Blue = 2;
      }
      else {
        strcat(&g_OverworldWorldState,s_fortify_you_with_extra_food_for_y_005195bc);
        DAT_00522448 = DAT_00522448 + 0x19;
      }
      *(int32_t *)(g_DisplaySurfaceScreen + 0x20) = 1;
      val_1 = Ai_Util_004c3bc4(0x13c);
      val_2 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
      val_1 = val_1 + val_2 * -7;
      val_2 = Ai_Util_004c3bc4(0x50);
      FUN_0040d1cd((int)g_DisplaySurfaceScreen,0xc1,val_2,val_1);
      App_ProcessPendingMessages();
      uval_5 = Ai_Subsystem_004cd1d1();
      return uval_5;
    case 4:
      if (g_AiManaColorCost_Blue == -1) {
        val_1 = Util_GetRandomNumber(2);
        g_AiManaColorCost_Blue = Pic_Subsystem_0045268f
                                 (*(int *)(&DAT_00517598 + (val_1 + -2 + arg_1 * 2) * 4));
        strcat(&g_OverworldWorldState,s_provide_you_a_00519624);
        strcat(&g_OverworldWorldState,s_Swamp_0051aea9 + g_AiManaColorCost_Blue * 0x34);
        strcat(&g_OverworldWorldState,s_companion_in_your_next_duel___00519634);
        *(int32_t *)(g_DisplaySurfaceScreen + 0x20) = 1;
        val_1 = Ai_Util_004c3bc4(0x13c);
        val_2 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
        val_1 = val_1 + val_2 * -7;
        val_2 = Ai_Util_004c3bc4(0x50);
        FUN_0040d1cd((int)g_DisplaySurfaceScreen,0xc1,val_2,val_1);
        App_ProcessPendingMessages();
        uval_5 = Ai_Subsystem_004cd1d1();
        return uval_5;
      }
    case 3:
      strcat(&g_OverworldWorldState,s_reveal_to_you_the_secret_deck_of_005195ec);
      pcVar4 = (char *)Mem_AllocOrFree_00473d7e(arg_1);
      strcat(&g_OverworldWorldState,pcVar4);
      strcat(&g_OverworldWorldState,s_creature____00519614);
      *(int32_t *)(g_DisplaySurfaceScreen + 0x20) = 1;
      val_1 = Ai_Util_004c3bc4(0x13c);
      val_2 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
      val_1 = val_1 + val_2 * -7;
      val_2 = Ai_Util_004c3bc4(0x50);
      FUN_0040d1cd((int)g_DisplaySurfaceScreen,0xc1,val_2,val_1);
      App_ProcessPendingMessages();
      Ai_Subsystem_004cd1d1();
      UI_PromptDeckInspection((uint8_t)arg_1);
      uval_5 = Overworld_LoadAdventureInterface800();
      return uval_5;
    default:
      strcat(&g_OverworldWorldState,s_fashion_3_00519654);
      Mem_AllocOrFree_00473d7e(arg_1);
      strcat(&g_OverworldWorldState,s_amulets_into_a_duplicate_of_any_s_00519660);
      *(int32_t *)(g_DisplaySurfaceScreen + 0x20) = 1;
      val_1 = Ai_Util_004c3bc4(0x13c);
      val_2 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
      val_1 = val_1 + val_2 * -7;
      val_2 = Ai_Util_004c3bc4(0x50);
      FUN_0040d1cd((int)g_DisplaySurfaceScreen,0xc1,val_2,val_1);
      App_ProcessPendingMessages();
      Ai_Subsystem_004cd1d1();
      *(int *)(&DAT_0067bdbc + arg_1 * 4) = *(int *)(&DAT_0067bdbc + arg_1 * 4) + -3;
      for (local_7dc = 0; local_7dc < 500; local_7dc = local_7dc + 1) {
        local_7d4[local_7dc] = *(uint32_t *)(&deck + local_7dc * 4);
        if (local_7d4[local_7dc] != 0xffffffff) {
          local_7d4[local_7dc] = local_7d4[local_7dc] & 0xfff;
        }
      }
      local_7e4 = UI_DeckSelectionMenu(g_CurrentTurnPhase,(int)local_7d4,500,s_Pick_a_spell_0051969c,1)
      ;
      if ((local_7e4 != -1) &&
         (local_7e0 = Pic_Subsystem_00451e40(local_7d4[local_7e4]), local_7e0 != -1)) {
        *(uint32_t *)(&deck + local_7e0 * 4) = *(uint32_t *)(&deck + local_7e0 * 4) | 0x4000;
      }
      uval_5 = Overworld_LoadAdventureInterface800();
      return uval_5;
    }
  }
  if ((DAT_005175c4 == -1) || (arg_2 != 0)) {
    val_1 = rand();
    DAT_005175c4 = val_1 % 3;
    DAT_00538500 = FUN_0040f6e9();
    DAT_00538720 = FUN_0040fbe2();
    FUN_0040fa39(&DAT_00538508,&DAT_00538620,1);
  }
  local_824 = (int *)(&PTR_s_I_see_you_have_not_yet_defeated_t_00517550)[DAT_005175c4];
  val_1 = FUN_0040f681(local_824,local_850);
  *(int32_t *)(g_DisplaySurfaceScreen + 0x20) = 1;
  local_854 = 0;
  do {
    if (val_1 + -1 <= local_854) {
      DAT_00538608 = 1;
      return 1;
    }
    local_824 = (int *)local_850[local_854];
    *(uint8_t *)(local_850[local_854 + 1] + -3) = 0;
    local_828 = FUN_0040f636((char *)local_824);
    if (val_1 + -2 == local_854) {
      if (DAT_005175c4 == 0) {
        FUN_0040f9b7((uint8_t)DAT_00538500);
        FUN_0040f78d(DAT_00538500);
        Mem_AllocOrFree_00473d7e(DAT_00538500);
        val_2 = Ai_Util_004c3bc4(0x13c);
        val_3 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
        val_2 = val_2 - val_3 * local_828;
        val_3 = Ai_Util_004c3bc4(0x50);
        FUN_0040d1cd((int)g_DisplaySurfaceScreen,0xc1,val_3,val_2);
      }
      else if (DAT_005175c4 == 1) {
LAB_00410182:
        val_2 = Ai_Util_004c3bc4(0x13c);
        val_3 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
        val_2 = val_2 - val_3 * local_828;
        val_3 = Ai_Util_004c3bc4(0x50);
        FUN_0040d1cd((int)g_DisplaySurfaceScreen,0xc1,val_3,val_2);
      }
      else if (DAT_005175c4 == 2) {
        if (DAT_00538720 == -1) goto LAB_00410182;
        FUN_0040fc9a(DAT_00538720,&DAT_00538508,&DAT_00538620);
        val_2 = Ai_Util_004c3bc4(0x13c);
        val_3 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
        val_2 = val_2 - val_3 * local_828;
        val_3 = Ai_Util_004c3bc4(0x50);
        FUN_0040d1cd((int)g_DisplaySurfaceScreen,0xc1,val_3,val_2);
      }
    }
    else {
      val_2 = Ai_Util_004c3bc4(0x13c);
      val_3 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
      val_2 = val_2 - val_3 * local_828;
      val_3 = Ai_Util_004c3bc4(0x50);
      FUN_0040d1cd((int)g_DisplaySurfaceScreen,0xc1,val_3,val_2);
    }
    App_ProcessPendingMessages();
    Ai_Subsystem_004cd1d1();
    *(uint8_t *)(local_850[local_854 + 1] + -3) = 10;
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

int32_t Castle_Process_00421b32(void)

{
  int val_1;
  int val_2;
  int val_3;
  int val_4;
  DWORD arg_5;
  uint32_t arg_4;
  uint32_t arg_2;
  int32_t arg_2_00;
  int arg_2_01;
  int *arg_6;
  char *str_6;
  char *str_7;
  int local_374;
  uint32_t local_368;
  int32_t local_364 [200];
  int local_44;
  int local_40 [9];
  int *color_idx;
  int target_idx;
  int player_idx;
  int match_count;
  uint32_t slot_idx;
  
  local_40[0] = 4;
  local_40[1] = 0;
  local_40[2] = 0;
  local_40[3] = 800;
  local_40[4] = 600;
  local_40[5] = 1;
  local_40[6] = 0xf;
  local_40[7] = 4;
  local_40[8] = 0;
  color_idx = local_40;
  player_idx = 0xb7;
  match_count = 0x1c;
  Surface_TransformPoint(0,(short)g_MidiMusicTrackId);
  *(int32_t *)(g_DisplaySurfaceBackBuffer + 0x20) = 4;
  *(int32_t *)(g_DisplaySurfaceWork + 0x20) = 4;
  Surface_FillRect((int *)g_DisplaySurfaceScreen,0,0,g_AiManaColorCost_Red,g_AiManaColorCost_Green,0);
  LoadPalNoPic(s_advfac64_pic_0051ac9c);
  Sprite_LoadAll(local_364,s_statbutt_spr_0051acac);
  local_44 = 0;
  for (local_368 = 0; local_368 < 5; local_368 = local_368 + 1) {
    (&DAT_00538a10)[local_368] = (void *)local_364[local_44];
    local_44 = local_44 + 1;
  }
  for (local_368 = 0; local_368 < 3; local_368 = local_368 + 1) {
    *(int32_t *)(&DAT_00538a88 + local_368 * 4) = local_364[local_44];
    local_44 = local_44 + 1;
  }
  for (local_368 = 0; local_368 < 3; local_368 = local_368 + 1) {
    *(int32_t *)(&DAT_00538a98 + local_368 * 4) = local_364[local_44];
    local_44 = local_44 + 1;
  }
  for (local_368 = 0; val_1 = local_44, local_368 < 3; local_368 = local_368 + 1) {
    *(int32_t *)(&DAT_00538aa8 + local_368 * 4) = local_364[local_44];
    local_44 = local_44 + 1;
  }
  _DAT_00538ac0 = local_364[local_44];
  local_44 = local_44 + 1;
  DAT_00538ac4 = local_364[local_44];
  local_44 = val_1 + 2;
  FUN_0040b441((int *)&DAT_0051a4e8,10);
  _DAT_0051a678 = 3;
  DAT_00538ac8 = 0;
LAB_00421d4c:
  DAT_0070a860 = DAT_0067bdd4;
  SelectObject(*(HDC *)(DAT_0067bdd4 + 4),DAT_0067bdd8);
  if (DAT_0070a880 == 8) {
    FileIO_OpenFileStream(1,0,g_AiManaColorCost_Green - 0x1e0,s_statbak_pic_0051acbc,(short *)0x1);
  }
  else {
    FileIO_OpenFileStream(1,0,g_AiManaColorCost_Green - 0x1e0,s_statbak_pic_0051acc8,(short *)0x1);
  }
  FUN_004219e1(g_DisplaySurfaceBackBuffer,0x26,g_AiManaColorCost_Green - 0x1d1,0x8c,0xac,
               *(int32_t *)(&DAT_0051ac18 + DAT_006410d8 * 8));
  FUN_004219e1(g_DisplaySurfaceBackBuffer,0x27,g_AiManaColorCost_Green - 0x1d0,0x8a,0xaa,
               *(int32_t *)(&DAT_0051ac1c + DAT_006410d8 * 8));
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,g_AiManaColorCost_Green - 0x1e0,0x280,0x1e0,
                     (int *)g_DisplaySurfaceBackBuffer,0,0,g_AiManaColorCost_Red,g_AiManaColorCost_Green);
  val_1 = Ai_Util_004c3bc4(0xa9);
  val_2 = Ai_Util_004c3bc4(0x89);
  val_3 = Ai_Util_004c3bc4(0x11);
  val_4 = Ai_Util_004c3bc4(0x28);
  Surface_StretchBlt(color_idx,0,0,0x89,0xa9,(int *)g_DisplaySurfaceBackBuffer,val_4,val_3,val_2,
                     val_1);
  val_3 = 0x154;
  val_2 = 0;
  arg_6 = (int *)g_DisplaySurfaceWork;
  arg_5 = Ai_Util_004c3bc4(0x7f);
  arg_4 = Ai_Util_004c3bc4(0x173);
  val_1 = Ai_Util_004c3bc4(0x43);
  arg_2 = Ai_Util_004c3bc4(0xf7);
  Surface_BlitToDevice((int *)g_DisplaySurfaceBackBuffer,arg_2,val_1,arg_4,arg_5,arg_6,val_2,val_3);
  str_7 = s_advfac64_pic_0051acd4;
  str_6 = s_prdblk_pic_0051ace4;
  val_1 = Ai_Util_004c3bc4(0xa9);
  val_2 = Ai_Util_004c3bc4(0x89);
  val_3 = Ai_Util_004c3bc4(0x11);
  arg_2_00 = Ai_Util_004c3bc4(0x28);
  FUN_00488fdb((int32_t *)g_DisplaySurfaceBackBuffer,arg_2_00,val_3,val_2,val_1,str_6,str_7);
  SelectObject(*(HDC *)(DAT_0070a860 + 4),*(HGDIOBJ *)(DAT_0070a860 + 0xc));
  DAT_0070a860 = 0;
  Font_DrawTextInRect((int)g_DisplaySurfaceBackBuffer,player_idx,0x4f,0x102);
  Font_DrawTextInRect((int)g_DisplaySurfaceBackBuffer,player_idx,0xb7,0x102);
  Engine_CountActiveCreatures();
  Font_DrawTextInRect((int)g_DisplaySurfaceBackBuffer,player_idx,0x4f,0x138);
  Font_DrawTextInRect((int)g_DisplaySurfaceBackBuffer,player_idx,0xb7,0x138);
  Font_DrawTextInRect((int)g_DisplaySurfaceBackBuffer,player_idx,0x29,0x161);
  Font_DrawTextInRect((int)g_DisplaySurfaceBackBuffer,player_idx,0x4e,0x161);
  Font_DrawTextInRect((int)g_DisplaySurfaceBackBuffer,player_idx,0x73,0x161);
  Font_DrawTextInRect((int)g_DisplaySurfaceBackBuffer,player_idx,0x98,0x161);
  Font_DrawTextInRect((int)g_DisplaySurfaceBackBuffer,player_idx,0xbd,0x161);
  Font_DrawTextInRect((int)g_DisplaySurfaceBackBuffer,match_count,0x69,0xc6);
  Font_DrawTextInRect((int)g_DisplaySurfaceBackBuffer,match_count,0x69,0xd6);
  Font_DrawTextInRect((int)g_DisplaySurfaceBackBuffer,match_count,0x10e,0x16c);
  for (slot_idx = 0; (int)slot_idx < 5; slot_idx = slot_idx + 1) {
    if (*(int *)(&DAT_006410c0 + slot_idx * 4) != 0) {
      val_1 = (int)(&DAT_00538a10)[slot_idx];
      val_2 = Ai_Util_004c3bc4(0x30);
      val_3 = Ai_Util_004c3bc4(0x30);
      val_4 = Ai_Util_004c3bc4(0x154);
      arg_2_01 = Ai_Util_004c3bc4(slot_idx * 0x39 + 0x14d);
      Sprite_DrawScaled((int *)g_DisplaySurfaceBackBuffer,arg_2_01,val_4,val_3,val_2,val_1);
    }
  }
  Font_DrawTextInRect((int)g_DisplaySurfaceBackBuffer,match_count,0x118,0xeb);
  for (slot_idx = 0; (int)slot_idx < 0xc; slot_idx = slot_idx + 1) {
    *(int32_t *)(&DAT_0051a528 + (slot_idx + 10) * 0x54) = 3;
    *(int32_t *)(&DAT_00538a30 + slot_idx * 4) = 0;
    if (((int)slot_idx < 2) || ((slot_idx & 1) != 0)) {
      if ((int)slot_idx < 2) {
        local_374 = slot_idx * 0x35;
      }
      else {
        local_374 = ((int)(slot_idx - 2) / 2) * 0x35 + 0x6a;
      }
      *(int *)(&DAT_0051a4f8 + (slot_idx + 10) * 0x54) = local_374 + 0xee;
      *(int32_t *)(&DAT_0051a4e8 + (slot_idx + 10) * 0x54) =
           *(int32_t *)(&DAT_0051a4f8 + (slot_idx + 10) * 0x54);
      *(int32_t *)(&DAT_0051a4fc + (slot_idx + 10) * 0x54) = 0x10e;
      *(int32_t *)(&DAT_0051a4ec + (slot_idx + 10) * 0x54) =
           *(int32_t *)(&DAT_0051a4fc + (slot_idx + 10) * 0x54);
      if ((g_OverworldMovementFlags & 1 << ((uint8_t)slot_idx & 0x1f)) != 0) {
        *(int32_t *)(&DAT_0051a528 + (slot_idx + 10) * 0x54) = 0;
        *(int32_t *)(&DAT_00538a30 + slot_idx * 4) = 1;
      }
    }
    else {
      *(int *)(&DAT_0051a4f8 + (slot_idx + 10) * 0x54) = ((int)(slot_idx - 2) / 2) * 0x35 + 0x16b;
      *(int32_t *)(&DAT_0051a4e8 + (slot_idx + 10) * 0x54) =
           *(int32_t *)(&DAT_0051a4f8 + (slot_idx + 10) * 0x54);
      *(int32_t *)(&DAT_0051a4fc + (slot_idx + 10) * 0x54) = 0xd2;
      *(int32_t *)(&DAT_0051a4ec + (slot_idx + 10) * 0x54) =
           *(int32_t *)(&DAT_0051a4fc + (slot_idx + 10) * 0x54);
      if ((g_OverworldMovementFlags & 1 << ((uint8_t)slot_idx & 0x1f)) != 0) {
        *(int32_t *)(&DAT_0051a528 + (slot_idx + 10) * 0x54) = 0;
        *(int32_t *)(&DAT_00538a30 + slot_idx * 4) = 1;
      }
    }
    *(int32_t *)(&DAT_0051a504 + (slot_idx + 10) * 0x54) = 0x35;
    *(int32_t *)(&DAT_0051a4f4 + (slot_idx + 10) * 0x54) =
         *(int32_t *)(&DAT_0051a504 + (slot_idx + 10) * 0x54);
    *(int32_t *)(&DAT_0051a500 + (slot_idx + 10) * 0x54) =
         *(int32_t *)(&DAT_0051a4f4 + (slot_idx + 10) * 0x54);
    *(int32_t *)(&DAT_0051a4f0 + (slot_idx + 10) * 0x54) =
         *(int32_t *)(&DAT_0051a500 + (slot_idx + 10) * 0x54);
    *(int32_t *)(&DAT_0051a52c + (slot_idx + 10) * 0x54) =
         *(int32_t *)(&DAT_006782a0 + slot_idx * 4);
    *(int32_t *)(&DAT_0051a534 + (slot_idx + 10) * 0x54) =
         *(int32_t *)(&DAT_006782d0 + slot_idx * 4);
    *(int32_t *)(&DAT_0051a530 + (slot_idx + 10) * 0x54) =
         *(int32_t *)(&DAT_0051a534 + (slot_idx + 10) * 0x54);
  }
  FUN_0040b441((int *)&DAT_0051a830,0xc);
  FUN_00422f06();
  FUN_0040d49d((int)g_DisplaySurfaceBackBuffer,match_count,0x14,0x184);
  Font_DrawTextInRect((int)g_DisplaySurfaceBackBuffer,player_idx,0xb2,0x184);
  FUN_0040d49d((int)g_DisplaySurfaceBackBuffer,match_count,0x14,0x196);
  Font_DrawTextInRect((int)g_DisplaySurfaceBackBuffer,player_idx,0xb2,0x196);
  FUN_0040d49d((int)g_DisplaySurfaceBackBuffer,match_count,0x14,0x1a8);
  Font_DrawTextInRect((int)g_DisplaySurfaceBackBuffer,player_idx,0xb2,0x1a8);
  FUN_0040d49d((int)g_DisplaySurfaceBackBuffer,match_count,0x14,0x1ba);
  Font_DrawTextInRect((int)g_DisplaySurfaceBackBuffer,player_idx,0xb2,0x1ba);
  FUN_0040d49d((int)g_DisplaySurfaceBackBuffer,match_count,0xe9,0x19a);
  for (slot_idx = 0; (int)slot_idx < 5; slot_idx = slot_idx + 1) {
    FUN_0040d49d((int)g_DisplaySurfaceBackBuffer,player_idx,slot_idx * 0x39 + 0x165,0x19a);
  }
  FUN_0040d49d((int)g_DisplaySurfaceBackBuffer,match_count,0xe9,0x1c0);
  Font_DrawTextInRect((int)g_DisplaySurfaceBackBuffer,player_idx,0x1a1,0x1c0);
  Font_DrawTextInRect((int)g_DisplaySurfaceBackBuffer,match_count,0x1b0,0x36);
  if (DAT_0070a880 == 8) {
    memset((void *)((int)&DAT_0070a134 + 2),0,0x300);
    FUN_0050e8b0((short *)&DAT_0070a130);
  }
  if (DAT_0070a880 == 8) {
    FileIO_OpenFileStream(-1,0,0,s_advfac64_pic_0051ae08,(short *)&DAT_0070a130);
  }
  else {
    LoadPalNoPic(s_advfac64_pic_0051ae18);
  }
  Surface_BlitToDevice((int *)g_DisplaySurfaceBackBuffer,0,0,g_AiManaColorCost_Red,g_AiManaColorCost_Green,
               (int *)g_DisplaySurfaceScreen,0,0);
  FUN_005115a0(0,(short)g_MidiMusicTrackId);
  if (g_AiManaColorCost_Red == 0x280) {
    Mem_AllocOrFree_00510de0(1,s_creatures640_pic_0051ae28);
    DAT_0051a4c8 = 0;
  }
  else if (g_AiManaColorCost_Red == 800) {
    Mem_AllocOrFree_00510de0(1,s_creatures800_pic_0051ae3c);
    DAT_0051a4c8 = 1;
  }
  else if (g_AiManaColorCost_Red == 0x400) {
    Mem_AllocOrFree_00510de0(1,s_creatures1024_pic_0051ae50);
    DAT_0051a4c8 = 2;
  }
  DAT_00538ac8 = 0;
  FUN_00422b04(0);
  FUN_0042192b(0x51a638);
LAB_004228ce:
  target_idx = FUN_0041f354();
  Mem_AllocOrFree_0041f12b(target_idx);
  FUN_0041f17e(0x51a4e8,0x16,target_idx);
  g_MouseCaptureFlag = 1;
  for (slot_idx = 0; (int)slot_idx < 3; slot_idx = slot_idx + 1) {
    FUN_004212f0((int)(&DAT_0051a4e8 + slot_idx * 0x54),0);
  }
  for (slot_idx = 10; (int)slot_idx < 0x16; slot_idx = slot_idx + 1) {
    FUN_0041e370((int)(&DAT_0051a4e8 + slot_idx * 0x54),0);
  }
  g_MouseCaptureFlag = 0;
  DAT_00538a28 = -1;
  while (DAT_00538a28 == -1) {
    Pic_Subsystem_0044b84b();
    FUN_0041f3ea(g_MouseScreenCoordX,g_MouseScreenCoordY,g_MouseCursorButtonState);
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
    Surface_TransformPoint(0,(short)g_MidiMusicTrackId);
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
    Surface_TransformPoint(0,(short)g_MidiMusicTrackId);
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
  char *char_ptr_1;
  int val_2;
  uint32_t uval_3;
  int local_fdc;
  int32_t local_fd8 [200];
  int local_cb8;
  int32_t local_cb4 [200];
  int local_994;
  int local_990;
  int local_98c;
  int32_t local_988 [13];
  uint8_t auStack_954 [748];
  int local_668;
  int local_664;
  int local_660;
  int32_t local_65c [200];
  int local_33c;
  int32_t local_338 [201];
  int player_idx;
  int match_count;
  int slot_idx;
  
  Mem_AllocOrFree_0050fc00();
  Mem_AllocOrFree_00510e20(1,s_endtop_pic_005250b0);
  DAT_00678514 = Sprite_EncodeFromSurface(1,0,0,0x95,0x13);
  FUN_0050fc20();
  Sprite_LoadAll((int32_t *)&DAT_00677f44,s_gsprite_spr_005250bc);
  Sprite_LoadAll(&DAT_00677e10,s_questnew_spr_005250c8);
  Sprite_LoadAll((int32_t *)&DAT_00678500,s_compnew_spr_005250d8);
  local_33c = 0;
  Sprite_LoadAll(local_338,s_worlds_spr_005250e4);
  for (match_count = 0; match_count < 4; match_count = match_count + 1) {
    for (slot_idx = 0; slot_idx < 0xc; slot_idx = slot_idx + 1) {
      *(int32_t *)(&DAT_006782a0 + slot_idx * 4 + match_count * 0x30) = local_338[local_33c];
      local_33c = local_33c + 1;
    }
  }
  for (slot_idx = 0; val_2 = local_33c, slot_idx < 4; slot_idx = slot_idx + 1) {
    *(int32_t *)(&DAT_0067f730 + slot_idx * 4) = local_338[local_33c];
    local_33c = local_33c + 1;
    *(int32_t *)(&DAT_0067f740 + slot_idx * 4) = local_338[local_33c];
    local_33c = val_2 + 2;
  }
  for (slot_idx = 0; slot_idx < 4; slot_idx = slot_idx + 1) {
    (&DAT_00677fa0)[slot_idx] = local_338[local_33c];
    local_33c = local_33c + 1;
  }
  Sprite_LoadAll((int32_t *)&DAT_00677e20,s_asprite_spr_005250f0);
  local_668 = 0;
  Sprite_LoadAll(local_65c,s_ttsprite_spr_005250fc);
  for (local_664 = 0; local_664 < 3; local_664 = local_664 + 1) {
    for (local_660 = 0; local_660 < 0x10; local_660 = local_660 + 1) {
      *(int32_t *)(&DAT_00678560 + local_660 * 4 + local_664 * 0x40) = local_65c[local_668];
      local_668 = local_668 + 1;
    }
  }
  for (local_660 = 0; local_660 < 6; local_660 = local_660 + 1) {
    *(int32_t *)(&DAT_00677970 + local_660 * 4) = local_65c[local_668];
    local_668 = local_668 + 1;
  }
  for (local_660 = 0; local_660 < 8; local_660 = local_660 + 1) {
    *(int32_t *)(&DAT_00677800 + local_660 * 4) = local_65c[local_668];
    local_668 = local_668 + 1;
  }
  for (local_660 = 0; val_2 = local_668, local_660 < 10; local_660 = local_660 + 1) {
    *(int32_t *)(&DAT_0067f390 + local_660 * 4) = local_65c[local_668];
    local_668 = local_668 + 1;
  }
  DAT_00677690 = local_65c[local_668];
  local_668 = local_668 + 1;
  DAT_006784f0 = local_65c[local_668];
  local_668 = val_2 + 2;
  _DAT_006784f4 = local_65c[local_668];
  local_668 = val_2 + 3;
  Sprite_LoadAll(&g_AiBackupBoardRegister,s_amsprite_spr_0052510c);
  uval_3 = 0x54;
  char_ptr_1 = (char *)Sprite_SelectResolutionFolder(s_cstline1_spr_0052511c);
  slot_idx = Sprite_LoadCount((int32_t *)&DAT_00677820,char_ptr_1,uval_3);
  uval_3 = 0x10;
  char_ptr_1 = (char *)Sprite_SelectResolutionFolder(s_landtile_spr_0052512c);
  slot_idx = Sprite_LoadCount(&DAT_00677650,char_ptr_1,uval_3);
  uval_3 = 0x37;
  char_ptr_1 = (char *)Sprite_SelectResolutionFolder(s_land_spr_0052513c);
  slot_idx = Sprite_LoadCount((int32_t *)&DAT_00677450,char_ptr_1,uval_3);
  uval_3 = 0x37;
  char_ptr_1 = (char *)Sprite_SelectResolutionFolder(s_sland_spr_00525148);
  slot_idx = Sprite_LoadCount((int32_t *)&DAT_00678010,char_ptr_1,uval_3);
  uval_3 = 0x37;
  char_ptr_1 = (char *)Sprite_SelectResolutionFolder(s_land2_spr_00525154);
  slot_idx = Sprite_LoadCount((int32_t *)&DAT_0067752c,char_ptr_1,uval_3);
  uval_3 = 0x37;
  char_ptr_1 = (char *)Sprite_SelectResolutionFolder(s_sland2_spr_00525160);
  slot_idx = Sprite_LoadCount((int32_t *)&DAT_006780ec,char_ptr_1,uval_3);
  uval_3 = 0xc;
  char_ptr_1 = (char *)Sprite_SelectResolutionFolder(s_roads_spr_0052516c);
  slot_idx = Sprite_LoadCount((int32_t *)&DAT_00677350,char_ptr_1,uval_3);
  char_ptr_1 = (char *)Sprite_SelectResolutionFolder(s_locatn01_spr_00525178);
  slot_idx = Sprite_LoadAll((int32_t *)&DAT_00677a10,char_ptr_1);
  char_ptr_1 = (char *)Sprite_SelectResolutionFolder(s_locatn02_spr_00525188);
  val_2 = Sprite_LoadAll((int32_t *)(&DAT_00677a10 + slot_idx * 4),char_ptr_1);
  slot_idx = slot_idx + val_2;
  char_ptr_1 = (char *)Sprite_SelectResolutionFolder(s_locatn03_spr_00525198);
  player_idx = Sprite_LoadAll((int32_t *)(&DAT_00677a10 + slot_idx * 4),char_ptr_1);
  player_idx = slot_idx + player_idx;
  slot_idx = player_idx;
  char_ptr_1 = (char *)Sprite_SelectResolutionFolder(s_locatn04_spr_005251a8);
  val_2 = Sprite_LoadAll((int32_t *)(&DAT_00677a10 + slot_idx * 4),char_ptr_1);
  slot_idx = slot_idx + val_2;
  _DAT_00677ff4 = *(int32_t *)(&DAT_00677a18 + player_idx * 4);
  _DAT_00678000 = *(int32_t *)(&DAT_00677a1c + player_idx * 4);
  _DAT_00677ff8 = *(int32_t *)(&DAT_00677a30 + player_idx * 4);
  _DAT_00677ff0 = *(int32_t *)(&DAT_00677a38 + player_idx * 4);
  DAT_006784f8 = *(int32_t *)(&DAT_00677a28 + player_idx * 4);
  char_ptr_1 = (char *)Sprite_SelectResolutionFolder(s_locatn05_spr_005251b8);
  player_idx = Sprite_LoadAll((int32_t *)(&DAT_00677a10 + slot_idx * 4),char_ptr_1);
  player_idx = slot_idx + player_idx;
  slot_idx = player_idx;
  char_ptr_1 = (char *)Sprite_SelectResolutionFolder(s_locatn06_spr_005251c8);
  val_2 = Sprite_LoadAll((int32_t *)(&DAT_00677a10 + slot_idx * 4),char_ptr_1);
  slot_idx = slot_idx + val_2;
  _DAT_00677ffc = *(int32_t *)(&DAT_00677a10 + player_idx * 4);
  local_98c = 0;
  Sprite_LoadAll(local_988,s_tsprite2_spr_005251d8);
  for (slot_idx = 0; slot_idx < 6; slot_idx = slot_idx + 1) {
    for (match_count = 0; match_count < 2; match_count = match_count + 1) {
      *(int32_t *)(&DAT_00677620 + slot_idx * 8 + match_count * 4) = local_988[local_98c];
      local_98c = local_98c + 1;
    }
  }
  memcpy(&DAT_00677f10,local_988 + local_98c,0x34);
  memcpy(&DAT_00678540,auStack_954 + local_98c * 4,0x18);
  for (slot_idx = 0; slot_idx < 0x20; slot_idx = slot_idx + 1) {
    *(int32_t *)(&g_OverworldFoodAmount + slot_idx * 0xb4) = 0;
  }
  char_ptr_1 = (char *)Sprite_SelectResolutionFolder(s_ego_f_spr_005251e8 +
                                ((*(int *)(&DAT_00525070 + DAT_006ff678 * 4) != 0) - 1 & 0xc));
  slot_idx = Sprite_LoadAll(&DAT_00679370,char_ptr_1);
  local_990 = DAT_00679370;
  DAT_00678430 = (int)*(short *)(DAT_00679370 + 4);
  DAT_006784b0 = (int)*(short *)(DAT_00679370 + 6);
  DAT_006779d0 = (int)*(short *)(DAT_00679370 + 10);
  if (DAT_006784b0 < DAT_006779d0) {
    DAT_006779d0 = (DAT_006784b0 * 2) / 3;
  }
  char_ptr_1 = (char *)Sprite_SelectResolutionFolder(s_sego_f_spr_00525200);
  slot_idx = Sprite_LoadAll(&DAT_00679424,char_ptr_1);
  local_994 = DAT_00679424;
  DAT_00678434 = (int)*(short *)(DAT_00679424 + 4);
  DAT_006784b4 = (int)*(short *)(DAT_00679424 + 6);
  DAT_006779d4 = (int)*(short *)(DAT_00679424 + 10);
  if (DAT_006784b4 < DAT_006779d4) {
    DAT_006779d4 = (DAT_006784b4 * 2) / 3;
  }
  char_ptr_1 = (char *)Sprite_SelectResolutionFolder(s_castles1_spr_0052520c);
  slot_idx = Sprite_LoadAll((int32_t *)&DAT_00678660,char_ptr_1);
  uval_3 = 8;
  char_ptr_1 = (char *)Sprite_SelectResolutionFolder(s_castles2_spr_0052521c);
  slot_idx = Sprite_LoadCount((int32_t *)&DAT_00678690,char_ptr_1,uval_3);
  uval_3 = 0xc;
  char_ptr_1 = (char *)Sprite_SelectResolutionFolder(s_locatn07_spr_0052522c);
  slot_idx = Sprite_LoadCount((int32_t *)&DAT_00677420,char_ptr_1,uval_3);
  local_cb8 = 0;
  Sprite_LoadAll(local_cb4,s_dbox_spr_0052523c);
  for (slot_idx = 0; slot_idx < 4; slot_idx = slot_idx + 1) {
    for (match_count = 0; match_count < 9; match_count = match_count + 1) {
      (&DAT_006781d0)[slot_idx * 9 + match_count] = local_cb4[local_cb8];
      local_cb8 = local_cb8 + 1;
    }
  }
  Sprite_LoadAll((int32_t *)&DAT_00678390,s_icons_spr_00525248);
  local_fdc = 0;
  Sprite_LoadAll(local_fd8,s_iconb_spr_00525254);
  for (slot_idx = 0; slot_idx < 4; slot_idx = slot_idx + 1) {
    *(int32_t *)(&DAT_00678260 + slot_idx * 0x10) = local_fd8[local_fdc];
    *(int32_t *)(&DAT_00678264 + slot_idx * 0x10) = local_fd8[local_fdc + 1];
    local_fdc = local_fdc + 2;
    for (match_count = 0; match_count < 2; match_count = match_count + 1) {
      *(int32_t *)(&DAT_00678268 + match_count * 4 + slot_idx * 0x10) = local_fd8[local_fdc];
      local_fdc = local_fdc + 1;
    }
  }
  if (DAT_0052f008 == 0) {
    Sprite_LoadAll(&DAT_00677fc0,s_clocknew_spr_00525260);
    Sprite_LoadAll((int32_t *)&DAT_00678360,s_daysnew_spr_00525270);
    Sprite_LoadAll((int32_t *)&DAT_00677f50,s_Sunmoon_spr_0052527c);
  }
  Mem_AllocOrFree_00510e20(1,s_tips_pic_00525288);
  Mem_AllocOrFree_0050fc00();
  if (g_AiManaColorCost_Red == 0x280) {
    DAT_00677fb0 = Sprite_EncodeFromSurface(1,1,1,5,0x10);
    DAT_00677fe4 = Sprite_EncodeFromSurface(1,10,1,3,2);
  }
  else if (g_AiManaColorCost_Red == 800) {
    DAT_00677fb0 = Sprite_EncodeFromSurface(1,1,0x1d,6,0x14);
    DAT_00677fe4 = Sprite_EncodeFromSurface(1,10,0x1d,5,3);
  }
  else if (g_AiManaColorCost_Red == 0x400) {
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

int Dungeon_Process_004856b0(uint32_t arg1,int arg2)

{
  char cVar1;
  uint8_t flag_2;
  int val_3;
  int val_4;
  int val_5;
  int val_6;
  int val_7;
  int val_8;
  int iVar9;
  char *pcVar10;
  int32_t uVar11;
  void *pvVar12;
  uint32_t uVar13;
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
  uint32_t local_8c4;
  int local_8c0;
  uint32_t local_8bc;
  uint32_t local_8b8;
  uint8_t *local_8b4;
  uint32_t auStack_8b0 [10];
  int local_888;
  int local_884;
  uint32_t local_880;
  uint32_t local_87c;
  LPVOID local_878;
  uint32_t local_874;
  uint32_t local_870;
  int local_86c;
  int local_868;
  uint32_t local_864;
  uint32_t local_860;
  uint32_t local_85c;
  int local_850;
  int local_84c;
  int local_848;
  int local_844;
  int local_840;
  int local_83c;
  int local_838;
  int32_t local_834;
  int local_830;
  uint32_t local_82c [518];
  LPVOID player_idx;
  uint32_t card_idx;
  int match_count;
  int slot_idx;
  
  local_8b4 = PTR_FUN_00527b3c;
  Glue_Subsystem_004ebebf();
  if (*(int *)(&g_TownBuildingCoordinates + arg1 * 0x14) == 0) {
    Sound_LoadWav_x_DuelSounds_artifact_0040de30(*(int *)(&DAT_0067f2dc + arg1 * 0x14));
    DAT_0067f384 = DAT_0067f384 + 1;
    Glue_Subsystem_004eadb7(0);
  }
  else {
    FUN_0046f21e(s_dbox2_spr_00527110,0xd5,0xd2);
    player_idx = *(LPVOID *)(&g_TownBuildingCoordinates + arg1 * 0x14);
    DAT_006b2d64 = arg2;
    DAT_00695df0 = (int)(char)(&DAT_00522629)[(int)player_idx * 0x44];
    local_880 = DAT_00695df0 + (int)(char)(&DAT_00522628)[(int)player_idx * 0x44] / 2;
    if ('\n' < (char)(&DAT_0052262a)[(int)player_idx * 0x44]) {
      local_880 = 0;
    }
    Glue_Subsystem_004ebfef(0);
    if ((&DAT_0052262a)[(int)player_idx * 0x44] == '\v') {
      local_8bc = Glue_Subsystem_004f0de8(DAT_00531590);
    }
    else {
      local_8bc = Pic_Subsystem_0045268f(*(int *)(&DAT_0052262c + (int)player_idx * 0x44));
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
    Deck_LoadPreconstructedDeck((int)player_idx,0xffffffff,0,-1);
    if ((&DAT_0052262a)[(int)player_idx * 0x44] != '\v') {
      do {
        do {
          DAT_006b2dd0 = FUN_0040a02a(DAT_0052eff8);
        } while (DAT_006b2dd0 < 5);
      } while (((((&g_MasterCardFlagsTable)[DAT_006b2dd0 * 0x34] & 1) != 0) ||
               (val_3 = FUN_00485005(DAT_006b2dd0), val_3 == 0)) ||
              (*(int *)(&g_MasterCardTypeTable + DAT_006b2dd0 * 0x34) ==
               *(int *)(&DAT_0052262c + (int)player_idx * 0x44)));
    }
    if ((&DAT_0052262a)[(int)player_idx * 0x44] == '\f') {
      local_840 = 3;
    }
    else {
      local_840 = 1;
    }
    Glue_Subsystem_004eccd7();
    for (local_874 = 0; (int)local_874 < local_840; local_874 = local_874 + 1) {
      do {
        do {
          local_878 = (LPVOID)Util_GetRandomNumber(500);
        } while (*(int *)(&deck + (int)local_878 * 4) == -1);
      } while ((((&DAT_00702151)[(int)local_878 * 4] & 0x40) != 0) ||
              ((*(uint32_t *)(&deck + (int)local_878 * 4) & 0xfff) < 5));
      (&DAT_006b2d90)[local_874] = *(uint32_t *)(&deck + (int)local_878 * 4) & 0xfff;
    }
    local_834 = 2;
    local_910 = s_prdblk_pic_00527128;
    local_90c = s_prdblu_pic_00527140;
    local_908 = s_prdgrn_pic_00527158;
    local_904 = s_prdrd_pic_00527170;
    local_900 = s_prdwt_pic_00527188;
    Surface_TransformPoint(0,(short)g_MidiMusicTrackId);
    FileIO_OpenFileStream(1,0,0,(char *)(&local_914)[arg2],
                 (short *)((int)&DAT_0070a130 + ((DAT_0070a880 == 8) - 1 & 0xff8f5ed1)));
    Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,
                       (int *)g_DisplaySurfaceScreen,0,0,g_AiManaColorCost_Red,g_AiManaColorCost_Green);
    FUN_005115a0(0,(short)g_MidiMusicTrackId);
    GDI_RealizeAndFlushPalette_Magic(_hdcScreen);
    Mem_AllocOrFree_00510e20(1,s_prdfrma_pic_00527194);
    Mem_AllocOrFree_0050fc00();
    local_8f4 = (void *)Sprite_EncodeFromSurface(1,1,1,0x68,0x2c);
    local_914 = Sprite_EncodeFromSurface(1,1,0x2e,0x67,0x31);
    local_8cc = Sprite_EncodeFromSurface(1,1,0x60,0x66,0x2c);
    local_8fc = Sprite_EncodeFromSurface(1,1,0x8d,0x79,0x2c);
    local_8c8 = Sprite_EncodeFromSurface(1,1,0xba,0x91,0x72);
    pvVar12 = local_8f4;
    val_3 = Ai_Util_004c3bc4((int)*(short *)((int)local_8f4 + 6));
    val_4 = Ai_Util_004c3bc4((int)*(short *)((int)local_8f4 + 4));
    val_5 = Ai_Util_004c3bc4(0x173);
    val_6 = Ai_Util_004c3bc4(0x14);
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,val_6,val_5,val_4,val_3,(int)pvVar12);
    val_3 = local_914;
    val_4 = Ai_Util_004c3bc4((int)*(short *)(local_914 + 6));
    val_5 = Ai_Util_004c3bc4((int)*(short *)(local_914 + 4));
    val_6 = Ai_Util_004c3bc4(0x16d);
    val_7 = Ai_Util_004c3bc4((int)*(short *)((int)local_8f4 + 4));
    val_8 = Ai_Util_004c3bc4(0x14);
    iVar9 = Ai_Util_004c3bc4(8);
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,(val_7 + val_8) - iVar9,val_6,val_5,val_4,val_3)
    ;
    val_3 = Ai_Util_004c3bc4((int)*(short *)(local_914 + 4));
    val_4 = Ai_Util_004c3bc4((int)*(short *)((int)local_8f4 + 4));
    val_5 = Ai_Util_004c3bc4(8);
    local_8f8 = Ai_Util_004c3bc4(0x14);
    local_8f8 = ((val_3 + val_4) - val_5) / 2 + local_8f8;
    val_3 = Ai_Util_004c3bc4((int)*(short *)(local_8fc + 4));
    val_4 = Ai_Util_004c3bc4((int)*(short *)(local_8cc + 4));
    val_5 = Ai_Util_004c3bc4(8);
    local_8f8 = local_8f8 - ((val_3 + val_4) - val_5) / 2;
    val_3 = local_8fc;
    val_4 = Ai_Util_004c3bc4((int)*(short *)(local_8fc + 6));
    val_5 = Ai_Util_004c3bc4((int)*(short *)(local_8fc + 4));
    val_6 = Ai_Util_004c3bc4((int)*(short *)((int)local_8f4 + 6));
    val_7 = Ai_Util_004c3bc4(0x173);
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,local_8f8,val_6 + val_7,val_5,val_4,val_3);
    val_3 = local_8cc;
    val_4 = Ai_Util_004c3bc4((int)*(short *)(local_8cc + 6));
    val_5 = Ai_Util_004c3bc4((int)*(short *)(local_8cc + 4));
    val_6 = Ai_Util_004c3bc4((int)*(short *)((int)local_8f4 + 6));
    val_7 = Ai_Util_004c3bc4(0x173);
    val_6 = val_6 + val_7;
    val_7 = Ai_Util_004c3bc4((int)*(short *)(local_8fc + 4));
    val_7 = local_8f8 + val_7;
    val_8 = Ai_Util_004c3bc4(8);
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,val_7 - val_8,val_6,val_5,val_4,val_3);
    *(int32_t *)(g_DisplaySurfaceScreen + 0x20) = 4;
    Font_DrawTextInRect((int)g_DisplaySurfaceScreen,0xd2,0x5b,0x188);
    Font_DrawTextInRect((int)g_DisplaySurfaceScreen,0xd2,0xbd,0x188);
    Font_DrawTextInRect((int)g_DisplaySurfaceScreen,0xd2,0x5b,0x1b5);
    Engine_CountActiveCreatures();
    Font_DrawTextInRect((int)g_DisplaySurfaceScreen,0xd2,0xc3,0x1b5);
    *(int32_t *)(g_DisplaySurfaceScreen + 0x20) = 2;
    val_3 = local_8c8;
    val_4 = Ai_Util_004c3bc4((int)*(short *)(local_8c8 + 6));
    val_5 = Ai_Util_004c3bc4((int)*(short *)(local_8c8 + 4));
    val_6 = Ai_Util_004c3bc4(0x15e);
    val_7 = Ai_Util_004c3bc4(0x1d4);
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,val_7,val_6,val_5,val_4,val_3);
    Ai_CalcManaRequirement_004c003d();
    Font_DrawTextInRect((int)g_DisplaySurfaceScreen,0xd2,0x21f,0x199);
    FUN_0050fc20();
    Mem_AllocOrFree_0050fc50(local_8f4);
    val_6 = 0;
    val_5 = 0;
    val_3 = Ai_Util_004c3bc4(10);
    val_4 = Ai_Util_004c3bc4(0x140);
    Pic_Load_advfac64_00489188(player_idx,val_4,val_3,val_5,val_6);
    Mem_AllocOrFree_00510e20(1,s_prdfrmb_pic_005271b4);
    *(int32_t *)(g_DisplaySurfaceBackBuffer + 0x20) = 4;
    *(int32_t *)(g_DisplaySurfaceScreen + 0x20) = 4;
    Mem_AllocOrFree_0050fc00();
    local_8ec = (void *)Sprite_EncodeFromSurface(1,1,0x17e,0x98,0x23);
    local_918 = Sprite_EncodeFromSurface(1,1,0x1a2,0x80,0x23);
    FUN_0050fc20();
    pvVar12 = local_8ec;
    val_3 = Ai_Util_004c3bc4((int)*(short *)((int)local_8ec + 6));
    val_4 = Ai_Util_004c3bc4((int)*(short *)((int)local_8ec + 4));
    val_5 = Ai_Util_004c3bc4(5);
    val_6 = Ai_Util_004c3bc4(0x220 - (int)*(short *)((int)local_8ec + 4) / 2);
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,val_6,val_5,val_4,val_3,(int)pvVar12);
    val_3 = Ai_Util_004c3bc4((int)*(short *)((int)local_8ec + 6) / 2 + 5);
    val_4 = Ai_Util_004c3bc4(0x220);
    FUN_0040d009((int)g_DisplaySurfaceScreen,0xe6,val_4,val_3);
    val_3 = local_918;
    val_4 = Ai_Util_004c3bc4((int)*(short *)(local_918 + 6));
    val_5 = Ai_Util_004c3bc4((int)*(short *)(local_918 + 4));
    val_6 = Ai_Util_004c3bc4(5);
    val_7 = Ai_Util_004c3bc4(100 - (int)*(short *)(local_918 + 4) / 2);
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,val_7,val_6,val_5,val_4,val_3);
    val_3 = Ai_Util_004c3bc4((int)*(short *)(local_918 + 6) / 2 + 5);
    val_4 = Ai_Util_004c3bc4(100);
    FUN_0040d009((int)g_DisplaySurfaceScreen,0xe6,val_4,val_3);
    *(int32_t *)(g_DisplaySurfaceScreen + 0x20) = 1;
    Mem_AllocOrFree_0050fc50(local_8ec);
    g_OverworldWorldState = 0;
    Glue_Subsystem_004eaa19((int)player_idx,0,0);
    strcat(&g_OverworldWorldState,s__s_ANTE__005271dc);
    if ((g_IsAiThinking == 0) && ((&DAT_0052262a)[(int)player_idx * 0x44] != '\v')) {
      FUN_0050b206(DAT_006b2dd0,0xe8,0x18,1,&DAT_005271e8);
    }
    local_83c = Math_Clamp(local_880 * 10, 10, local_880 * 0x32);
    if ((&DAT_0052262a)[(int)player_idx * 0x44] != '\v') {
      local_86c = 0;
      local_838 = 0;
      local_924 = (int)(*(int *)(&g_AiCardEvaluationScore + arg1 * 0x14) +
                       (*(int *)(&g_AiCardEvaluationScore + arg1 * 0x14) >> 0x1f & 0x1fU)) >> 5;
      local_928 = (int)(*(int *)(&g_AiCardSynergyScore + arg1 * 0x14) +
                       (*(int *)(&g_AiCardSynergyScore + arg1 * 0x14) >> 0x1f & 0x1fU)) >> 5;
      local_91c = *(int *)(&DAT_0067f000 + (arg2 + -1) * 0x30);
      local_920 = *(int *)(&DAT_0067f004 + (arg2 + -1) * 0x30);
      val_3 = abs(local_924 - local_91c);
      if ((val_3 <= g_CampaignDifficultyLevel / 2 + 2) &&
         (val_3 = abs(local_928 - local_920), val_3 <= g_CampaignDifficultyLevel / 2 + 2)) {
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
        if (((&DAT_0052262a)[(int)player_idx * 0x44] == ((&DAT_0067b9b0)[local_874] & 0xf)) &&
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
        Glue_Subsystem_004eaa19((int)player_idx,1,0);
        strcat(&g_OverworldWorldState,&DAT_00527268);
      }
      else if (local_838 == 2) {
        strcpy(&g_OverworldWorldState,s_Those_who_would_challenge_the_Gr_0052726c);
        pcVar10 = (char *)Mem_AllocOrFree_00473d7e(arg2);
        strcat(&g_OverworldWorldState,pcVar10);
        strcat(&g_OverworldWorldState,s_Wizard_for_Supremacy_of_00527294);
        uVar13 = Glue_Subsystem_004f0a4a
                           ((int)(*(int *)(&g_AiCardEvaluationScore + arg1 * 0x14) +
                                 (*(int *)(&g_AiCardEvaluationScore + arg1 * 0x14) >> 0x1f & 0x1fU)) >> 5,
                            (int)(*(int *)(&g_AiCardSynergyScore + arg1 * 0x14) +
                                 (*(int *)(&g_AiCardSynergyScore + arg1 * 0x14) >> 0x1f & 0x1fU)) >> 5);
        Ai_TownEncounter_004c3b19(uVar13);
        strcat(&g_OverworldWorldState,s_must____Duel_005272b0);
        Glue_Subsystem_004eaa19((int)player_idx,1,0);
        strcat(&g_OverworldWorldState,&DAT_005272c0);
      }
      else if (local_850 < 5) {
        strcpy(&g_OverworldWorldState,s_Those_who_enter_the_domain_of_th_005272c4);
        pcVar10 = (char *)Mem_AllocOrFree_00473d7e(arg2);
        strcat(&g_OverworldWorldState,pcVar10);
        strcat(&g_OverworldWorldState,s_Wizard_must_pay_for_the_privileg_005272f0);
        strcat(&g_OverworldWorldState,s_Will_you____Duel_00527318);
        Glue_Subsystem_004eaa19((int)player_idx,1,0);
        strcat(&g_OverworldWorldState,&DAT_0052732c);
      }
      else {
        strcpy(&g_OverworldWorldState,&DAT_00527330);
        strcat(&g_OverworldWorldState,s_Lairs_00522614 + (int)player_idx * 0x44);
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
      if (((local_850 < g_CampaignDifficultyLevel * 2 + 2) || (local_838 != 0)) || (4 < local_850)) {
        local_860 = 0xffffffff;
      }
      else {
        strcat(&g_OverworldWorldState,s_Answer_a_riddle__005273cc);
        local_860 = local_8c4;
        local_8c4 = local_8c4 + 1;
      }
      if ((((g_OverworldMovementFlags & 1) == 0) || (local_86c != 0)) || (local_840 != 1)) {
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
          val_3 = g_AiManaColorCost_Red / 2;
          val_4 = FUN_0050f440((int *)g_DisplaySurfaceScreen,&g_OverworldWorldState);
          local_870 = FUN_00489710(&g_OverworldWorldState,(val_3 - val_4 / 2) + -2,uVar11);
        } while (local_870 == 0xffffffff);
      }
      if (((((int)local_870 < 1) && (4 < local_850)) && (-(int)player_idx != g_AiHandEvaluationBuffer)) &&
         (local_838 == 0)) {
        local_964[10] = Util_GetRandomNumber(3);
        local_938 = Util_GetRandomNumber(3);
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
          cVar1 = (&DAT_00522628)[(int)player_idx * 0x44];
          val_3 = Util_GetRandomNumber(10 - g_CampaignDifficultyLevel);
          local_930 = (cVar1 + val_3) * 10;
          pcVar10 = _itoa(local_930,&DAT_00539d50,10);
          strcat(&g_OverworldWorldState,pcVar10);
          strcat(&g_OverworldWorldState,s_Gold_00527490);
        }
        else if (local_938 == 1) {
          strcat(&g_OverworldWorldState,s_40_Food_00527498);
        }
        else if (local_938 == 2) {
          strcat(&g_OverworldWorldState,&DAT_005274a4);
          local_934 = Util_GetRandomNumber(3);
          local_934 = local_934 + 1;
          local_92c = Util_GetRandomNumber(5);
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
          Deck_LoadPreconstructedDeck((int)player_idx,0xffffffff,0,-1);
          for (arg1 = 0; (int)arg1 < 500; arg1 = arg1 + 1) {
            uVar11 = FUN_0040a02a(DAT_0052eff8);
            *(int32_t *)(&DAT_0069ef00 + arg1 * 4) = uVar11;
            if (((&g_MasterCardFlagsTable)[*(int *)(&DAT_0069ef00 + arg1 * 4) * 0x34] & 1) != 0) {
              *(int32_t *)(&DAT_0069ef00 + arg1 * 4) = 0xffffffff;
            }
          }
          SelectPalette(_hdcScreen,DAT_00626834,0);
          Surface_TransformPoint(0,(short)g_MidiMusicTrackId);
          FUN_0046f21e(s_dbox_spr_005274cc,0x71,0xe3);
          local_8bc = UI_DeckSelectionMenu(g_CurrentTurnPhase,0x69ef00,500,s_Pick_a_spell_005274dc,1);
          if ((*(int *)(&DAT_0069ef00 + local_8bc * 4) != -1) &&
             (local_878 = (LPVOID)Pic_Subsystem_00451e40(*(uint32_t *)(&DAT_0069ef00 + local_8bc * 4)),
             local_878 != (LPVOID)0xffffffff)) {
            *(uint32_t *)(&deck + (int)local_878 * 4) = *(uint32_t *)(&deck + (int)local_878 * 4) | 0x4000;
          }
        }
        if ((local_870 == 0) && (local_964[10] == 1)) {
          strcpy(&g_OverworldWorldState,s_Which_WM_spell_do_you_seek____005274ec);
          local_84c = 0;
          for (arg1 = 0; (int)arg1 < 0xc; arg1 = arg1 + 1) {
            if ((g_OverworldMovementFlags & 1 << ((uint8_t)arg1 & 0x1f)) == 0) {
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
              local_874 = *(uint32_t *)(&DAT_005224e8 + local_82c[local_870] * 0x10);
              *(uint32_t *)(&g_CardSlot_StatusFlags + local_874 * 100) =
                   *(uint32_t *)(&g_CardSlot_StatusFlags + local_874 * 100) | 2;
              FUN_0040c81c(0x80,*(int *)(&g_DungeonMapTileX + local_874 * 100),
                           *(int *)(&g_DungeonMapTileY + local_874 * 100));
              strcpy(&g_OverworldWorldState,(&PTR_s_Sleight_of_hand_005225d0)[local_82c[local_870]])
              ;
              strcat(&g_OverworldWorldState,s_may_be_found_in_0052754c);
              Ai_TownEncounter_004c3b19(local_874);
              strcat(&g_OverworldWorldState,&DAT_00527560);
              FUN_00489710(&g_OverworldWorldState,0x5a,0x6e);
              Glue_Subsystem_004ead96(0);
              Glue_Subsystem_004eadb7(0);
              SelectPalette(_hdcScreen,DAT_00626834,0);
              Surface_TransformPoint(0,(short)g_MidiMusicTrackId);
              Ai_CastleEncounter_004c24b3(0);
            }
          }
        }
        if ((local_870 == 0) && (local_964[10] == 2)) {
          if (*(int *)(&DAT_006410bc + arg2 * 4) == 0) {
            if (((uint8_t)*(int32_t *)(&DAT_0067f010 + (arg2 + -1) * 0x30) & 7) == 7) {
              Castle_Process_00492ddf(arg2 + -1);
            }
            else {
              SelectPalette(_hdcScreen,DAT_00626834,0);
              Surface_TransformPoint(0,(short)g_MidiMusicTrackId);
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
          val_3 = Palette_Subsystem_00498a18();
          if (val_3 == 0) {
            Glue_Subsystem_004ebfef(2);
            strcpy(&g_OverworldWorldState,s_Lost_this_card_00527590);
            Mem_AllocOrFree_00510e20(1,s_losedul2_pic_005275a0);
            Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,
                               (int *)g_DisplaySurfaceScreen,0,0,g_AiManaColorCost_Red,g_AiManaColorCost_Green);
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
          Surface_TransformPoint(0,(short)g_MidiMusicTrackId);
          FUN_0050d560(0,0);
          LoadPalNoPic(s_advfac64_pic_005275bc);
          FUN_0046f21e(s_dbox_spr_005275cc,0x71,0xe3);
          return 0;
        }
        if (local_864 == local_870) {
          Gold = Gold - local_83c;
          SelectPalette(_hdcScreen,DAT_00626834,0);
          Surface_TransformPoint(0,(short)g_MidiMusicTrackId);
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
    Glue_Subsystem_004eaa19((int)player_idx,1,0);
    strcat(&g_OverworldWorldState,&DAT_00527660);
    App_ProcessPendingMessages();
    uVar11 = Ai_Util_004c3bc4(0x100);
    val_3 = g_AiManaColorCost_Red / 2;
    val_4 = FUN_0050f440((int *)g_DisplaySurfaceScreen,&g_OverworldWorldState);
    FUN_00489710(&g_OverworldWorldState,(val_3 - val_4 / 2) + -2,uVar11);
    Glue_Subsystem_004ebebf();
LAB_00487364:
    match_count = 0;
    for (local_874 = 0; (int)local_874 < 1000; local_874 = local_874 + 1) {
      if ((&DAT_0067b9b0)[local_874] != '\0') {
        match_count = match_count + 1;
      }
    }
    local_878 = *(LPVOID *)(&DAT_006a48f0 + arg2 * 4);
    if ('\n' < (char)(&DAT_0052262a)[(int)player_idx * 0x44]) {
      local_878 = DAT_0052f000;
    }
    local_848 = *(int *)(&DAT_006a4908 + arg2 * 4);
    if ('\n' < (char)(&DAT_0052262a)[(int)player_idx * 0x44]) {
      local_848 = DAT_00626804;
    }
    val_3 = Math_Clamp(3 - match_count / 3,0,3);
    DAT_0063ee24 = -val_3;
    if ((g_CampaignDifficultyLevel == 3) || ('\n' < (char)(&DAT_0052262a)[(int)player_idx * 0x44])) {
      DAT_0063ee24 = 0;
    }
    if ((&DAT_0052262a)[(int)player_idx * 0x44] == '\v') {
      DAT_0063ee24 = *(int *)(&DAT_005224e4 + DAT_00531590 * 0x10) / 500 + -1;
    }
    if (-g_CampaignDifficultyLevel < DAT_0063ee24) {
      local_878 = DAT_0052f000;
    }
    local_8b8 = (uint32_t)((int)(CONCAT44(DAT_0067f37c >> 0x1f,DAT_0067f37c >> 2) % 3) == 0);
    if (local_8b8 != 0) {
      Glue_Subsystem_004ebcdc(s_x_sound_dsummon_wav_00527664,0xf,100,100,0);
      if ((((&DAT_00522638)[(int)player_idx * 0x44] & 4) != 0) &&
         (val_3 = Util_GetRandomNumber(3), val_3 == 0)) {
        val_3 = Util_GetRandomNumber(0x23);
        local_878 = (LPVOID)(val_3 + 1);
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
        g_OverworldPlayerDirection = 0;
        strcpy(&g_OverworldWorldState,s_Why_don_t_you_try_this_deck__00527690);
        FUN_00489710(&g_OverworldWorldState,0xa0,0xa0);
      }
      if ((((*(uint32_t *)(&DAT_00522638 + (int)player_idx * 0x44) & 0x110) != 0) &&
          (val_3 = Util_GetRandomNumber(3), val_3 == 0)) && (-(int)player_idx != g_AiHandEvaluationBuffer)) {
        do {
          do {
            val_3 = Util_GetRandomNumber(3);
            local_878 = (LPVOID)((int)player_idx + val_3 + 1);
          } while (local_878 == (LPVOID)0x37);
        } while (((int)local_878 < 0x24) && ((int)local_878 % 7 == 0));
        val_6 = 1;
        val_5 = 0;
        val_3 = Ai_Util_004c3bc4(10);
        val_4 = Ai_Util_004c3bc4(0x140);
        Pic_Load_advfac64_00489188(local_878,val_4,val_3,val_5,val_6);
        g_OverworldWorldState = 0;
        Glue_Subsystem_004eaa19((int)player_idx,0,0);
        strcat(&g_OverworldWorldState,s_summons_005276b0);
        Glue_Subsystem_004eaa19((int)local_878,1,0);
        strcat(&g_OverworldWorldState,&DAT_005276bc);
        FUN_00489710(&g_OverworldWorldState,0xa0,0x78);
        player_idx = local_878;
        local_880 = DAT_00695df0 + (int)(char)(&DAT_00522628)[(int)local_878 * 0x44] / 2;
      }
      if (((&DAT_00522638)[(int)player_idx * 0x44] & 0xc1) != 0) {
        DAT_006b2fe0 = Pic_Subsystem_0045268f(*(int *)(&DAT_00522640 + (int)player_idx * 0x44));
      }
      if (((&DAT_00522638)[(int)player_idx * 0x44] & 0xcb) != 0) {
        g_OverworldWorldState = 0;
        Glue_Subsystem_004eaa19((int)player_idx,0,0);
        strcat(&g_OverworldWorldState,s_has_005276c0);
        local_888 = 1;
        if (((&DAT_00522638)[(int)player_idx * 0x44] & 2) != 0) {
          if (DAT_0067f37c % 3 == 0) {
            strcat(&g_OverworldWorldState,s_Mind_Control_005276c8);
          }
          else {
            local_888 = 0;
          }
        }
        if (((&DAT_00522638)[(int)player_idx * 0x44] & 8) != 0) {
          DAT_0067a6b4 = 1;
          strcat(&g_OverworldWorldState,s_First_Strike_005276d8);
        }
        if (((&DAT_00522638)[(int)player_idx * 0x44] & 0xc1) != 0) {
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
      if (((local_874 != arg1) && (*(int *)(&g_TownBuildingCoordinates + local_874 * 0x14) != 0)) &&
         ((val_3 = FUN_0040a36f(g_OverworldMapPixelX - *(int *)(&g_AiCardEvaluationScore + local_874 * 0x14),
                                g_OverworldMapPixelY - *(int *)(&g_AiCardSynergyScore + local_874 * 0x14)),
          val_3 < 0x40 && (*(int *)(&g_TownBuildingCoordinates + local_874 * 0x14) != -1)))) {
        FUN_0046e70d(local_874,local_874 + 8);
        *(int32_t *)(&g_TownBuildingCoordinates + local_874 * 0x14) = 0xffffffff;
      }
    }
    Deck_LoadPreconstructedDeck((int)player_idx,local_8bc,(uint32_t)local_878,local_848);
    Palette_Subsystem_00496eaf();
    Surface_TransformPoint(0,(short)g_MidiMusicTrackId);
    SelectPalette(_hdcScreen,DAT_00626834,0);
    FUN_0046f21e(s_dbox_spr_005276ec,0x71,0xe3);
    Pic_Subsystem_00423c82(0);
    local_964[9] = -1;
    while (local_964[9] != 0) {
      Pic_Subsystem_00424020(0,local_964 + 9);
    }
    slot_idx = Deck_LoadOneDeckProfile(local_8bc,player_idx);
    LoadPalNoPic(s_advfac64_pic_005276f8);
    if (slot_idx == 1) {
      local_964[7] = 0xca;
      local_964[6] = 0x8c;
      local_964[8] = 0x118;
      Glue_Subsystem_004f0d90((&DAT_0052262a)[(int)player_idx * 0x44],(uint8_t)arg2);
      FUN_0040b3c2(2,(uint32_t)player_idx | 0x80);
      Glue_Subsystem_004ec98e(2,DAT_006b2d64 << 0x10 | (uint32_t)player_idx);
      if (-(int)player_idx == g_AiHandEvaluationBuffer) {
        g_AiHandEvaluationBuffer = g_AiHandEvaluationBuffer + -100;
      }
      if ((char)(&DAT_0052262a)[(int)player_idx * 0x44] < '\v') {
        local_830 = FUN_0050b00c();
        local_874 = local_880;
        local_8c4 = 0;
        do {
          do {
            do {
              uVar13 = 1;
              flag_2 = Util_GetRandomNumber(6);
              local_8bc = Pic_Subsystem_00451d90(1 << (flag_2 & 0x1f),uVar13);
              val_3 = Pic_Subsystem_004521a6
                                (1 << ((uint8_t)arg2 & 0x1f),
                                 (int)(char)(&g_MasterCardColorTable)[local_8bc * 0x34],
                                 (-(uint32_t)((local_8c4 & 1) == 0) & 2) + 1);
            } while (val_3 == 0);
            val_3 = Glue_Subsystem_004f0b50(local_8bc);
          } while (((val_3 < 1) || (((&g_MasterCardFlagsTable)[local_8bc * 0x34] & 9) != 0)) ||
                  (val_3 = FUN_00485005(local_8bc), val_3 == 0));
          if (((int)local_8c4 < 3) && ((&DAT_006b2dd0)[local_8c4] != -1)) {
            local_8bc = (&DAT_006b2dd0)[local_8c4];
          }
          auStack_8b0[local_8c4] = local_8bc;
          local_8c4 = local_8c4 + 1;
          uVar13 = *(uint32_t *)(&g_MasterCardSubtypeTable + local_8bc * 0x34);
          val_3 = File_Load_Info(local_8bc);
          local_874 = local_874 - (((uVar13 & 0x400) >> 10) + val_3);
        } while (0 < (int)local_874);
        Glue_Subsystem_004ebfef(1);
        Mem_AllocOrFree_00510de0(1,s_winbak01_pic_00527708);
        Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,
                           (int *)g_DisplaySurfaceScreen,0,0,g_AiManaColorCost_Red,g_AiManaColorCost_Green);
        local_8c0 = (int)(300 / (longlong)(int)(local_8c4 + 1));
        for (arg1 = 0; (int)arg1 < (int)local_8c4; arg1 = arg1 + 1) {
          val_3 = File_Load_Info(auStack_8b0[arg1]);
          strcpy(&g_OverworldWorldState,(char *)(&DAT_0052b73c)[val_3]);
          pcVar10 = &g_OverworldWorldState;
          val_4 = 1;
          val_3 = Util_GetRandomNumber(10);
          FUN_0050b206(auStack_8b0[arg1],
                       (local_8c0 * arg1 + 0x6f) - (int)((local_8c4 - 1) * local_8c0) / 2,
                       val_3 + 0x10,val_4,pcVar10);
        }
        if (local_830 == -1) {
          *(int32_t *)(g_DisplaySurfaceScreen + 0x20) = 5;
          Font_DrawTextInRect((int)g_DisplaySurfaceScreen,0xff,0x140,0x15e);
          Ai_Subsystem_004cd1d1();
          for (arg1 = 0; (int)arg1 < (int)local_8c4; arg1 = arg1 + 1) {
            local_878 = (LPVOID)Pic_Subsystem_00451e40(auStack_8b0[arg1]);
            if (local_878 != (LPVOID)0xffffffff) {
              *(uint32_t *)(&deck + (int)local_878 * 4) = *(uint32_t *)(&deck + (int)local_878 * 4) | 0x4000
              ;
            }
          }
        }
        else {
          local_868 = 0xcb;
          Mem_AllocOrFree_00510e20(1,s_endplak_pic_00527718);
          val_3 = Ai_Util_004c3bc4(0x36);
          val_4 = Ai_Util_004c3bc4(0x128);
          val_5 = Ai_Util_004c3bc4(0x195);
          val_6 = Ai_Util_004c3bc4(0x34);
          Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x128,0x36,
                             (int *)g_DisplaySurfaceScreen,val_6,val_5,val_4,val_3);
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
            if ((*(uint32_t *)(&DAT_0067f010 + local_830 * 0x30) & 1 << ((uint8_t)local_874 & 0x1f)) != 0)
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
          Glue_Subsystem_004eaa19((int)player_idx,0,0);
          strcat(&g_OverworldWorldState,s___Will_you____Take_the_cards__Ta_00527778);
          FUN_0050afbd();
          val_3 = FUN_004896be(&g_OverworldWorldState,0x40,0x7c);
          if (val_3 == 0) {
            if (local_830 != -1) {
              *(uint32_t *)(&g_TownBuildingFlagsTable + local_830 * 0x30) =
                   *(uint32_t *)(&g_TownBuildingFlagsTable + local_830 * 0x30) | 0x200;
            }
            for (arg1 = 0; (int)arg1 < (int)local_8c4; arg1 = arg1 + 1) {
              local_878 = (LPVOID)Pic_Subsystem_00451e40(auStack_8b0[arg1]);
              if (local_878 != (LPVOID)0xffffffff) {
                *(uint32_t *)(&deck + (int)local_878 * 4) =
                     *(uint32_t *)(&deck + (int)local_878 * 4) | 0x4000;
              }
            }
          }
          else {
            FUN_0048ea81(local_830);
          }
        }
        App_ProcessPendingMessages();
        card_idx = *(uint32_t *)(&DAT_0052263c + (int)player_idx * 0x44);
        if (local_8b8 == 0) {
          card_idx = 0;
        }
        val_3 = Util_GetRandomNumber(0x28);
        if (val_3 < (int)local_880) {
          local_964[1] = 2;
          local_964[2] = 1;
          local_964[3] = 4;
          local_964[4] = 3;
          local_964[5] = 0;
          *(int *)(&DAT_0067bdbc + arg2 * 4) = *(int *)(&DAT_0067bdbc + arg2 * 4) + 1;
          Mem_AllocOrFree_00510e20(1,s_winbak02_pic_005277c4);
          Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,
                             (int *)g_DisplaySurfaceScreen,0,0,g_AiManaColorCost_Red,g_AiManaColorCost_Green);
          App_ProcessPendingMessages();
          strcpy(&g_OverworldWorldState,s_Won_this_Amulet__005277d4);
          local_964[0] = FUN_0050f440((int *)g_DisplaySurfaceScreen,&g_OverworldWorldState);
          val_7 = 0;
          val_3 = Ai_Util_004c3bc4(0x30);
          val_3 = val_3 + 0xe;
          val_4 = local_964[0] + 0x10;
          val_5 = Ai_Util_004c3bc4(0xa0);
          val_6 = Ai_Util_004c3bc4(0xa0);
          FUN_0048a3cc((val_6 - local_964[0] / 2) + -8,val_5,val_4,val_3,val_7);
          val_3 = Ai_Util_004c3bc4(0xae);
          val_4 = Ai_Util_004c3bc4(0xa0);
          FUN_0040d269((int)g_DisplaySurfaceScreen,0xff,val_4,val_3);
          val_3 = (&g_AiBackupBoardRegister)[local_964[arg2]];
          val_4 = Ai_Util_004c3bc4(0x22);
          val_5 = Ai_Util_004c3bc4(0x1a);
          val_6 = Ai_Util_004c3bc4(0xbd);
          val_7 = Ai_Util_004c3bc4(0xa0);
          val_8 = Ai_Util_004c3bc4(0xd);
          Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,val_7 - val_8,val_6,val_5,val_4,val_3);
          if (card_idx == 0) {
            App_ProcessPendingMessages();
            Ai_Subsystem_004cd1d1();
          }
        }
        else if ((card_idx == 0) && (local_8b8 != 0)) {
          flag_2 = Util_GetRandomNumber(0xc);
          card_idx = 1 << (flag_2 & 0x1f) & 0x1a19;
        }
        if (card_idx != 0) {
          Glue_Subsystem_004ebcdc(s_x_sound_treasure_wav_0052783c,0xf,100,100,0);
          Mem_AllocOrFree_00510e20(1,s_winbak02_pic_00527854);
          Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,
                             (int *)g_DisplaySurfaceScreen,0,0,g_AiManaColorCost_Red,g_AiManaColorCost_Green);
          val_6 = 0;
          val_5 = 1;
          val_3 = Ai_Util_004c3bc4(0x23);
          val_4 = Ai_Util_004c3bc4(local_964[6]);
          Pic_Load_advfac64_00489188(player_idx,val_4,val_3,val_5,val_6);
          *(int32_t *)(g_DisplaySurfaceScreen + 0x20) = 4;
          g_OverworldWorldState = 0;
          strcpy(&g_OverworldWorldState,s_You_are_00527864);
          strcat(&g_OverworldWorldState,(&PTR_s_an_Adequate_Apprentice_00527100)[g_CampaignDifficultyLevel]);
          strcat(&g_OverworldWorldState,&DAT_00527870);
          strcat(&g_OverworldWorldState,s_says_the_00527874);
          Glue_Subsystem_004eaa19((int)player_idx,0,0);
          strcat(&g_OverworldWorldState,&DAT_00527880);
          Font_DrawTextInRect((int)g_DisplaySurfaceScreen,local_964[7],local_964[6],local_964[8]);
          local_964[8] = local_964[8] + 0x28;
          strcpy(&g_OverworldWorldState,s_You_get_00527884);
        }
        if (((card_idx & 1) != 0) && (g_PlayerCreatureCount != DAT_00627868)) {
          g_AiCombatLookaheadTarget = g_PlayerCreatureCount - DAT_00627868;
          strcat(&g_OverworldWorldState,s_your_lives___00527890);
          pcVar10 = _itoa(g_PlayerCreatureCount,&DAT_00539d50,10);
          strcat(&g_OverworldWorldState,pcVar10);
          strcat(&g_OverworldWorldState,s___carried_over_to_the_next_duel__005278a0);
          Font_DrawTextInRect((int)g_DisplaySurfaceScreen,local_964[7],local_964[6],local_964[8]);
        }
        if ((card_idx & 0x800) != 0) {
          val_3 = Util_GetRandomNumber(4);
          g_AiManaColorCost_Blue = (LPVOID)(val_3 + 1);
          strcat(&g_OverworldWorldState,&DAT_005278c4);
          pcVar10 = _itoa((int)g_AiManaColorCost_Blue,&DAT_00539d50,10);
          strcat(&g_OverworldWorldState,pcVar10);
          strcat(&g_OverworldWorldState,s_lives_in_next_duel__005278c8);
          Font_DrawTextInRect((int)g_DisplaySurfaceScreen,local_964[7],local_964[6],local_964[8]);
        }
        if ((card_idx & 0x402) != 0) {
          do {
            local_844 = Util_GetRandomNumber(0x40);
            local_868 = Util_GetRandomNumber(0x40);
            val_3 = Surface_GetPixelColor(local_844, local_868);
          } while (val_3 == 0);
          g_OverworldMapPixelX = local_844 * 0x20 + 0x10;
          g_OverworldMapPixelY = local_868 * 0x20 + 0x10;
          DAT_00641884 = 0;
          Font_DrawTextInRect((int)g_DisplaySurfaceScreen,local_964[7],local_964[6],local_964[8]);
        }
        if ((card_idx & 4) != 0) {
          g_AiManaColorCost_Blue = (LPVOID)Pic_Subsystem_0045268f
                                           (*(int *)(&DAT_00522640 + (int)player_idx * 0x44));
          local_878 = (LPVOID)Pic_Subsystem_00451e40((uint32_t)g_AiManaColorCost_Blue);
          if (local_878 != (LPVOID)0xffffffff) {
            *(uint32_t *)(&deck + (int)local_878 * 4) = *(uint32_t *)(&deck + (int)local_878 * 4) | 0x4000;
          }
          strcpy(&g_OverworldWorldState,s_You_won_005278ec);
          Glue_Subsystem_004eaa9c((int)s_Swamp_0051aea9[(int)g_AiManaColorCost_Blue * 0x34],0);
          strcat(&g_OverworldWorldState,s_Swamp_0051aea9 + (int)g_AiManaColorCost_Blue * 0x34);
          FUN_0050b206((int)g_AiManaColorCost_Blue,0xa0,0x70,1,&g_OverworldWorldState);
          g_AiManaColorCost_Blue = (LPVOID)0xffffffff;
        }
        if ((card_idx & 0x10) != 0) {
          g_AiManaColorCost_Blue = (LPVOID)0x0;
          Font_DrawTextInRect((int)g_DisplaySurfaceScreen,local_964[7],local_964[6],local_964[8]);
        }
        if ((card_idx & 0x20) != 0) {
          g_AiManaColorCost_Blue = (LPVOID)Pic_Subsystem_0045268f
                                           (*(int *)(&DAT_00522640 + (int)player_idx * 0x44));
          strcat(&g_OverworldWorldState,s_Swamp_0051aea9 + (int)g_AiManaColorCost_Blue * 0x34);
          strcat(&g_OverworldWorldState,s_in_the_next_duel__00527920);
          FUN_0050b206((int)g_AiManaColorCost_Blue,0xa0,0x70,1,&g_OverworldWorldState);
        }
        if ((card_idx & 0x180) != 0) {
          do {
            do {
              local_878 = (LPVOID)Util_GetRandomNumber(g_MasterCardCount + -0x29);
            } while (((&g_MasterCardColorTable)[(int)local_878 * 0x34] & 0x42) != 0x40);
          } while (((int)local_878 < 5) || (val_3 = FUN_00485005((int)local_878), val_3 == 0));
          g_AiManaColorCost_Blue = local_878;
          Glue_Subsystem_004eaa9c((int)s_Swamp_0051aea9[(int)local_878 * 0x34],0);
          strcat(&g_OverworldWorldState,s_Swamp_0051aea9 + (int)g_AiManaColorCost_Blue * 0x34);
          strcat(&g_OverworldWorldState,s_in_the_next_duel__00527934);
          FUN_0050b206((int)g_AiManaColorCost_Blue,0xa0,0x70,1,&g_OverworldWorldState);
        }
        if ((card_idx & 0x200) != 0) {
          val_3 = Util_GetRandomNumber(0x1e);
          DAT_00522448 = DAT_00522448 + val_3 + 0x14;
          strcat(&g_OverworldWorldState,s_Extra_FOOD__00527948);
          Font_DrawTextInRect((int)g_DisplaySurfaceScreen,local_964[7],local_964[6],local_964[8]);
        }
        if ((card_idx & 0x40) != 0) {
          strcat(&g_OverworldWorldState,s_any_card_of_your_choice__00527954);
          Font_DrawTextInRect((int)g_DisplaySurfaceScreen,local_964[7],local_964[6],local_964[8]);
          Ai_Subsystem_004cd1d1();
          Glue_Subsystem_004ead96(1);
          local_8bc = Palette_Color_0049716e(s_Pick_a_card_00527970,0,0xffffffff,1,0);
          while (local_8bc == 0xffffffff) {
            local_8bc = Palette_Color_0049716e(s_Pick_a_card_0052797c,0,0xffffffff,0,0);
          }
          if (local_8bc != 0xffffffff) {
            val_3 = Pic_Subsystem_00451e40(local_8bc);
            *(uint32_t *)(&deck + val_3 * 4) = *(uint32_t *)(&deck + val_3 * 4) | 0x4000;
          }
          card_idx = 0;
        }
        if ((card_idx & 0x1000) != 0) {
          strcat(&g_OverworldWorldState,s_a_duplicate_card_of_your_choice__00527988);
          Font_DrawTextInRect((int)g_DisplaySurfaceScreen,local_964[7],local_964[6],local_964[8]);
          Ai_Subsystem_004cd1d1();
          Glue_Subsystem_004ead96(1);
          for (arg1 = 0; (int)arg1 < 500; arg1 = arg1 + 1) {
            local_82c[arg1] = *(uint32_t *)(&deck + arg1 * 4);
            if (local_82c[arg1] != 0xffffffff) {
              local_82c[arg1] = local_82c[arg1] & 0xfff;
            }
          }
          local_8bc = UI_DeckSelectionMenu(g_CurrentTurnPhase,(int)local_82c,500,s_Pick_a_card_005279b0
                                        ,1);
          if (local_8bc != 0xffffffff) {
            val_3 = Pic_Subsystem_00451e40(local_82c[local_8bc]);
            *(uint32_t *)(&deck + val_3 * 4) = *(uint32_t *)(&deck + val_3 * 4) | 0x4000;
          }
          card_idx = 0;
        }
        if ((card_idx & 8) != 0) {
          strcat(&g_OverworldWorldState,s_Extra_GOLD__005279bc);
          Font_DrawTextInRect((int)g_DisplaySurfaceScreen,local_964[7],local_964[6],local_964[8]);
          Gold = Gold + 100;
        }
        App_ProcessPendingMessages();
        if (card_idx != 0) {
          Ai_Subsystem_004cd1d1();
        }
        val_3 = Util_GetRandomNumber((int)(0x40 / (longlong)(g_CampaignDifficultyLevel + 1)));
        if (val_3 < (int)local_880) {
          *(LPVOID *)(&DAT_006a48f0 + arg2 * 4) = DAT_0052f000;
        }
        val_3 = Util_GetRandomNumber((int)(0x80 / (longlong)(g_CampaignDifficultyLevel + 1)));
        if (val_3 < (int)local_880) {
          *(int *)(&DAT_006a4908 + arg2 * 4) = DAT_00626804;
        }
      }
    }
    if (slot_idx == 0) {
      Glue_Subsystem_004ebfef(2);
      Mem_AllocOrFree_00510e20(1,s_losedul2_pic_005279c8);
      Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,
                         (int *)g_DisplaySurfaceScreen,0,0,g_AiManaColorCost_Red,g_AiManaColorCost_Green);
      FUN_0040b3c2(2,player_idx);
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
    if (slot_idx == -1) {
      Mem_AllocOrFree_00510e20(1,s_losedul2_pic_005279f8);
      Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,
                         (int *)g_DisplaySurfaceScreen,0,0,g_AiManaColorCost_Red,g_AiManaColorCost_Green);
      val_5 = 0;
      val_4 = 1;
      val_3 = Ai_Util_004c3bc4(0x3c);
      Pic_Load_advfac64_00489188
                (player_idx,(int)(g_AiManaColorCost_Red + (g_AiManaColorCost_Red >> 0x1f & 3U)) >> 2,val_3,val_4,val_5);
      *(int32_t *)(g_DisplaySurfaceScreen + 0x20) = 4;
      strcpy(&g_OverworldWorldState,s_The_people_are_disappointed_you_c_00527a08);
      Glue_Subsystem_004eaa19((int)player_idx,0,0);
      val_3 = Ai_Util_004c3bc4(300);
      FUN_0040d201((int)g_DisplaySurfaceScreen,0xca,
                   (int)(g_AiManaColorCost_Red + (g_AiManaColorCost_Red >> 0x1f & 3U)) >> 2,val_3);
      val_3 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
      val_3 = Ai_Util_004c3bc4(val_3 * 4 + 300);
      FUN_0040d201((int)g_DisplaySurfaceScreen,0xca,
                   (int)(g_AiManaColorCost_Red + (g_AiManaColorCost_Red >> 0x1f & 3U)) >> 2,val_3);
      App_ProcessPendingMessages();
      Ai_Subsystem_004cd1d1();
    }
  }
LAB_00488f4b:
  FUN_0046f21e(s_dbox_spr_00527a78,0x71,0xe3);
  SelectPalette(_hdcScreen,DAT_00626834,0);
  LoadPalNoPic(s_advfac64_pic_00527a84);
  App_ProcessPendingMessages();
  return slot_idx;
LAB_00486fd1:
  do {
    do {
      local_878 = (LPVOID)Util_GetRandomNumber(500);
    } while (*(int *)(&deck + (int)local_878 * 4) == -1);
  } while ((((&DAT_00702151)[(int)local_878 * 4] & 0x40) != 0) ||
          ((*(uint32_t *)(&deck + (int)local_878 * 4) & 0xfff) < 5));
  DAT_006b2d90 = *(uint32_t *)(&deck + (int)local_878 * 4) & 0xfff;
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
  uint8_t flag_1;
  int32_t uval_2;
  void *buf_ptr_3;
  char *pcVar4;
  int val_5;
  int val_6;
  uint32_t uval_7;
  int val_8;
  DWORD arg_5;
  uint32_t arg_2;
  int iVar9;
  void **ppvVar10;
  bool bVar11;
  int local_1528;
  int local_14c8;
  int local_14c0;
  int local_14bc;
  int local_14b0;
  void *local_14ac [50];
  uint32_t auStackY_13e4 [15];
  uint32_t auStackY_13a8 [50];
  int32_t local_12e0;
  uint32_t local_12dc;
  uint32_t local_12d4;
  int local_12d0;
  uint32_t local_12cc;
  int local_12c8;
  char acStackY_12c4 [4744];
  int32_t uStackY_3c;
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
    uval_2 = Sprite_EncodeFromSurface(1,local_14b0 * 0x3c + 0x10,1,0x3b,0x1a);
    *(int32_t *)(&DAT_00676bc0 + local_14b0 * 4) = uval_2;
  }
  for (local_14bc = 0; local_14bc < 2; local_14bc = local_14bc + 1) {
    for (local_14b0 = 0; local_14b0 < 4; local_14b0 = local_14b0 + 1) {
      uval_2 = Sprite_EncodeFromSurface
                        (1,local_14bc * 0x80 + local_14b0 * 0x20 + 0x10,0x1c,0x1f,0x24);
      *(int32_t *)(&DAT_00676ba0 + local_14b0 * 4 + local_14bc * 0x10) = uval_2;
    }
  }
  FUN_0050fc20();
  if (DAT_00528000 == DAT_00527ff0) {
    for (local_14b0 = 0; local_14b0 < 3; local_14b0 = local_14b0 + 1) {
      uval_2 = Ai_Util_004c3bc4((&DAT_00528000)[local_14b0 * 0x15]);
      (&DAT_00528000)[local_14b0 * 0x15] = uval_2;
      uval_2 = Ai_Util_004c3bc4(*(int *)(&DAT_00528004 + local_14b0 * 0x54));
      *(int32_t *)(&DAT_00528004 + local_14b0 * 0x54) = uval_2;
      uval_2 = Ai_Util_004c3bc4(*(int *)(&DAT_00528008 + local_14b0 * 0x54));
      *(int32_t *)(&DAT_00528008 + local_14b0 * 0x54) = uval_2;
      uval_2 = Ai_Util_004c3bc4(*(int *)(&DAT_0052800c + local_14b0 * 0x54));
      *(int32_t *)(&DAT_0052800c + local_14b0 * 0x54) = uval_2;
    }
  }
  FileIO_OpenFileStream(1,0,g_AiManaColorCost_Green - 0x1e0,s_dung_bd_pic_00528568,(short *)0x0);
  uStackY_3c = 0x48f7d7;
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,g_AiManaColorCost_Green - 0x1e0,0x280,0x1e0,
                     (int *)g_DisplaySurfaceBackBuffer,0,0,g_AiManaColorCost_Red,g_AiManaColorCost_Green);
  Surface_BlitToDevice((int *)g_DisplaySurfaceBackBuffer,0,0,g_AiManaColorCost_Red,g_AiManaColorCost_Green,
               (int *)g_DisplaySurfaceScreen,0,0);
  Mem_AllocOrFree_0050fc00();
  for (local_12cc = 0; (int)local_12cc < 0xf; local_12cc = local_12cc + 1) {
    local_12e0 = 0;
    if (((*(int *)(&DAT_0067f010 + local_12cc * 0x30) != 0) || (g_CardSlot_ToughnessBonus != 0)) &&
       (((int)local_12cc < 5 ||
        ((*(int *)(&DAT_0067eff0 + local_12cc * 0x30) != -1 || (g_CardSlot_ToughnessBonus != 0)))))) {
      auStackY_13a8[local_12c8] = local_12cc;
      if ((((&DAT_0067f010)[local_12cc * 0x30] & 1) != 0) || (g_CardSlot_ToughnessBonus != 0)) {
        if ((int)local_12cc < 5) {
          Ai_Util_004c3bc4(0x3e);
          Ai_Util_004c3bc4(0x3e);
          buf_ptr_3 = (void *)FUN_0048ee42();
          local_14ac[local_12c8] = buf_ptr_3;
        }
        else {
          Ai_Util_004c3bc4(0x3e);
          Ai_Util_004c3bc4(0x3e);
          buf_ptr_3 = (void *)FUN_0048ee42();
          local_14ac[local_12c8] = buf_ptr_3;
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
    FileIO_OpenFileStream(1,0,g_AiManaColorCost_Green - 0x1e0,s_dung_bd_pic_00528574,(short *)0x0);
    uStackY_3c = 0x48fa87;
    Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,g_AiManaColorCost_Green - 0x1e0,0x280,0x1e0,
                       (int *)g_DisplaySurfaceBackBuffer,0,0,g_AiManaColorCost_Red,g_AiManaColorCost_Green);
    Surface_BlitToDevice((int *)g_DisplaySurfaceBackBuffer,0,0,g_AiManaColorCost_Red,g_AiManaColorCost_Green,
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
    FileIO_OpenFileStream(1,0,g_AiManaColorCost_Green - 0x1e0,s_dung_bd_pic_00528580,(short *)0x0);
    uStackY_3c = 0x48fbaf;
    Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,g_AiManaColorCost_Green - 0x1e0,0x280,0x1e0,
                       (int *)g_DisplaySurfaceBackBuffer,0,0,g_AiManaColorCost_Red,g_AiManaColorCost_Green);
    *(int32_t *)g_DisplaySurfaceScreen = 1;
    local_12dc = 0;
    *(int32_t *)(g_DisplaySurfaceScreen + 0x20) = 1;
    local_14bc = local_14c8;
    while( true ) {
      iVar9 = local_14c8 + 0xc;
      if (local_12c8 <= local_14c8 + 0xc) {
        iVar9 = local_12c8;
      }
      if (iVar9 <= local_14bc) break;
      local_12cc = auStackY_13a8[local_14bc];
      local_12e0 = 0;
      if (((*(int *)(&DAT_0067f010 + local_12cc * 0x30) != 0) || (g_CardSlot_ToughnessBonus != 0)) &&
         (((int)local_12cc < 5 ||
          ((*(int *)(&DAT_0067eff0 + local_12cc * 0x30) != -1 || (g_CardSlot_ToughnessBonus != 0)))))) {
        auStackY_13e4[local_12dc] = local_12cc;
        g_OverworldWorldState = 0;
        FUN_0048e2b0(local_12cc);
        if ((int)local_12cc < 5) {
          strcat(&g_OverworldWorldState,&DAT_0052858c);
          pcVar4 = (char *)Mem_AllocOrFree_00473d7e(local_12cc + 1);
          strcat(&g_OverworldWorldState,pcVar4);
          strcat(&g_OverworldWorldState,s_Castle__00528590);
        }
        iVar9 = Ai_Util_004c3bc4((-(uint32_t)((local_12dc & 1) == 0) & 0xfffffef9) + 0x19b);
        val_5 = Ai_Util_004c3bc4(((int)local_12dc / 2) * 0x3e + 0x69);
        val_6 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
        FUN_0040cf6d((int)g_DisplaySurfaceScreen,0xff,iVar9,val_5 - val_6 / 2);
        strcpy(acStackY_12c4 + local_12dc * 0x30,&g_OverworldWorldState);
        g_OverworldWorldState = 0;
        if ((((&DAT_0067f010)[local_12cc * 0x30] & 1) != 0) || (g_CardSlot_ToughnessBonus != 0)) {
          if (*(int *)(&DAT_0067f004 + local_12cc * 0x30) -
              *(int *)(&g_DungeonMapTileY + *(int *)(&DAT_0067f008 + local_12cc * 0x30) * 100) < 1) {
            strcpy(&g_OverworldWorldState,
                   &DAT_005285a4 +
                   ((0 < *(int *)(&DAT_0067f000 + local_12cc * 0x30) -
                         *(int *)(&g_DungeonMapTileX + *(int *)(&DAT_0067f008 + local_12cc * 0x30) * 100)
                    ) - 1 & 4));
          }
          else {
            strcpy(&g_OverworldWorldState,
                   &DAT_0052859c +
                   ((0 < *(int *)(&DAT_0067f000 + local_12cc * 0x30) -
                         *(int *)(&g_DungeonMapTileX + *(int *)(&DAT_0067f008 + local_12cc * 0x30) * 100)
                    ) - 1 & 4));
          }
          strcat(&g_OverworldWorldState,&DAT_005285ac);
          Ai_TownEncounter_004c3b19(*(uint32_t *)(&DAT_0067f008 + local_12cc * 0x30));
          strcat(&g_OverworldWorldState,&DAT_005285b0);
          uval_7 = FUN_0040c7c0(*(int *)(&g_DungeonMapTileX +
                                       *(int *)(&DAT_0067f008 + local_12cc * 0x30) * 100),
                               *(int *)(&g_DungeonMapTileY +
                                       *(int *)(&DAT_0067f008 + local_12cc * 0x30) * 100));
          if ((uval_7 & 0x80) != 0) {
            local_12e0 = 1;
          }
          if ((int)local_12cc < 5) {
            iVar9 = Ai_Util_004c3bc4((-(uint32_t)((local_12dc & 1) == 0) & 0xfffffef9) + 0x15b);
            val_5 = Ai_Util_004c3bc4(((int)local_12dc / 2) * 0x3e + 0x49);
            buf_ptr_3 = local_14ac[local_14bc];
            val_6 = Ai_Util_004c3bc4(0x3e);
            val_8 = Ai_Util_004c3bc4(0x3e);
            FUN_0048efc7(g_DisplaySurfaceScreen,iVar9,val_5,val_8,val_6,(int)buf_ptr_3);
          }
          else {
            iVar9 = Ai_Util_004c3bc4((-(uint32_t)((local_12dc & 1) == 0) & 0xfffffef9) + 0x15b);
            val_5 = Ai_Util_004c3bc4(((int)local_12dc / 2) * 0x3e + 0x49);
            buf_ptr_3 = local_14ac[local_14bc];
            val_6 = Ai_Util_004c3bc4(0x3e);
            val_8 = Ai_Util_004c3bc4(0x3e);
            FUN_0048efc7(g_DisplaySurfaceScreen,iVar9,val_5,val_8,val_6,(int)buf_ptr_3);
          }
        }
        local_12dc = local_12dc + 1;
        if ((((&DAT_0067f010)[local_12cc * 0x30] & 2) != 0) || (g_CardSlot_ToughnessBonus != 0)) {
          if ((int)local_12cc < 5) {
            flag_1 = FUN_0049094c();
            (&DAT_0067f00d)[local_12cc * 0x30] = flag_1 | 0x80;
          }
          strcat(&g_OverworldWorldState,
                 &DAT_005285b4 + ((((&DAT_0067f00d)[local_12cc * 0x30] & 0x80) != 0) - 1 & 4));
          pcVar4 = (char *)Mem_AllocOrFree_00473d7e((int)(char)(&DAT_0067f00c)[local_12cc * 0x30]);
          strcat(&g_OverworldWorldState,pcVar4);
          strcat(&g_OverworldWorldState,&DAT_005285bc);
        }
        if ((((&DAT_0067f010)[local_12cc * 0x30] & 4) != 0) || (g_CardSlot_ToughnessBonus != 0)) {
          if (((&g_TownBuildingFlagsTable)[local_12cc * 0x30] & 0x10) != 0) {
            strcat(&g_OverworldWorldState,s_xColor_005285c0);
          }
          if (((&g_TownBuildingFlagsTable)[local_12cc * 0x30] & 0x20) != 0) {
            strcat(&g_OverworldWorldState,s_1deck_005285c8);
          }
          if (((&g_TownBuildingFlagsTable)[local_12cc * 0x30] & 0x40) != 0) {
            strcat(&g_OverworldWorldState,s_xArtifacts_005285d0);
          }
          if (((&g_TownBuildingFlagsTable)[local_12cc * 0x30] & 0x80) != 0) {
            strcat(&g_OverworldWorldState,s_xInstants_005285dc);
          }
          if (((&g_TownBuildingFlagsTable)[local_12cc * 0x30] & 1) != 0) {
            strcat(&g_OverworldWorldState,s__Life_005285e8);
          }
          if (((&g_TownBuildingFlagsTable)[local_12cc * 0x30] & 2) != 0) {
            strcat(&g_OverworldWorldState,s__Life_005285f0);
          }
          if (*(int *)(&DAT_0067effc + local_12cc * 0x30) == -1) {
            if (*(int *)(&g_TownBuildingFlagsTable + local_12cc * 0x30) == 0) {
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
    *(int32_t *)g_DisplaySurfaceScreen = 0;
    iVar9 = Ai_Util_004c3bc4(0x46);
    val_5 = Ai_Util_004c3bc4(0x50);
    arg_6 = (int *)g_DisplaySurfaceScreen;
    arg_5 = Ai_Util_004c3bc4(0x17a);
    uval_7 = Ai_Util_004c3bc4(0x208);
    val_6 = Ai_Util_004c3bc4(0x46);
    arg_2 = Ai_Util_004c3bc4(0x50);
    Surface_BlitToDevice((int *)g_DisplaySurfaceBackBuffer,arg_2,val_6,uval_7,arg_5,arg_6,val_5,iVar9);
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
        if (g_MouseCursorButtonState == 0) {
          iVar9 = (g_MouseScreenCoordY * 0x1e0) / (int)g_AiManaColorCost_Green;
          val_5 = (g_MouseScreenCoordX * 0x280) / (int)g_AiManaColorCost_Red;
          val_6 = FUN_0048edeb(val_5,iVar9,0x54,0x49,0xfb,0x174);
          if (val_6 == 0) {
            val_5 = FUN_0048edeb(val_5,iVar9,0x15b,0x49,0xfd,0x174);
            if (val_5 != 0) {
              local_12cc = ((iVar9 + -0x49) / 0x3e) * 2 + 1;
            }
          }
          else {
            local_12cc = ((iVar9 + -0x49) / 0x3e) * 2;
          }
          if (((-1 < (int)local_12cc) && ((int)local_12cc < (int)local_12dc)) &&
             (local_12cc != local_12d4)) {
            if (local_12d4 != 0xffffffff) {
              iVar9 = Ai_Util_004c3bc4((-(uint32_t)((local_12d4 & 1) == 0) & 0xfffffef9) + 0x19b);
              val_5 = Ai_Util_004c3bc4(((int)local_12d4 / 2) * 0x3e + 0x69);
              val_6 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
              FUN_0040cf6d((int)g_DisplaySurfaceScreen,0xff,iVar9,val_5 - val_6 / 2);
            }
            iVar9 = Ai_Util_004c3bc4((-(uint32_t)((local_12cc & 1) == 0) & 0xfffffef9) + 0x19b);
            val_5 = Ai_Util_004c3bc4(((int)local_12cc / 2) * 0x3e + 0x69);
            val_6 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
            FUN_0040cf6d((int)g_DisplaySurfaceScreen,0xe3,iVar9,val_5 - val_6 / 2);
            local_12d4 = local_12cc;
          }
        }
        else {
          iVar9 = (g_MouseScreenCoordY * 0x1e0) / (int)g_AiManaColorCost_Green;
          val_5 = (g_MouseScreenCoordX * 0x280) / (int)g_AiManaColorCost_Red;
          val_6 = FUN_0048edeb(val_5,iVar9,0x54,0x49,0xfb,0x174);
          if (val_6 == 0) {
            val_5 = FUN_0048edeb(val_5,iVar9,0x15b,0x49,0xfd,0x174);
            if (val_5 != 0) {
              local_12cc = ((iVar9 + -0x49) / 0x3e) * 2 + 1;
            }
          }
          else {
            local_12cc = ((iVar9 + -0x49) / 0x3e) * 2;
          }
          if ((-1 < (int)local_12cc) && ((int)local_12cc < (int)local_12dc)) {
            iVar9 = Ai_Util_004c3bc4((-(uint32_t)((local_12cc & 1) == 0) & 0xfffffef9) + 0x19b);
            val_5 = Ai_Util_004c3bc4(((int)local_12cc / 2) * 0x3e + 0x69);
            val_6 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
            FUN_0040cf6d((int)g_DisplaySurfaceScreen,0xbe,iVar9,val_5 - val_6 / 2);
            App_ProcessPendingMessages();
            Castle_Process_00492ddf(auStackY_13e4[local_12cc]);
            goto LAB_0048fa24;
          }
        }
        local_14c0 = -1;
        FUN_0041f3ea(g_MouseScreenCoordX,g_MouseScreenCoordY,g_MouseCursorButtonState);
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
      val_5 = (local_12c8 + 2U & 0xfffffffe) - 0xc;
      if (iVar9 <= val_5) {
        val_5 = iVar9;
      }
      bVar11 = local_14c8 != val_5;
      local_14c8 = val_5;
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
  int32_t uval_1;
  int val_2;
  uint32_t arg_2;
  uint32_t arg_4;
  DWORD arg_5;
  int val_3;
  DWORD DVar4;
  uint32_t uval_5;
  int *piVar6;
  uint32_t uval_7;
  DWORD local_45c;
  int local_444;
  int local_43c;
  int local_434;
  DWORD local_430;
  int local_42c;
  int local_424;
  int aiStack_418 [10];
  int aiStack_3f0 [247];
  int player_idx;
  int card_idx;
  int slot_idx;
  
  player_idx = 0;
  local_444 = 0;
  Mem_AllocOrFree_00510e20(1,s_infobar_pic_00528650);
  Mem_AllocOrFree_0050fc00();
  for (local_43c = 0; local_43c < 4; local_43c = local_43c + 1) {
    if (*(int *)(&DAT_005281f0 + local_43c * 0x54) == *(int *)(&DAT_005281e0 + local_43c * 0x54)) {
      uval_1 = Ai_Util_004c3bc4(*(int *)(&DAT_005281f0 + local_43c * 0x54));
      *(int32_t *)(&DAT_005281f0 + local_43c * 0x54) = uval_1;
      uval_1 = Ai_Util_004c3bc4(*(int *)(&DAT_005281f4 + local_43c * 0x54));
      *(int32_t *)(&DAT_005281f4 + local_43c * 0x54) = uval_1;
      uval_1 = Ai_Util_004c3bc4(*(int *)(&DAT_005281f8 + local_43c * 0x54));
      *(int32_t *)(&DAT_005281f8 + local_43c * 0x54) = uval_1;
      uval_1 = Ai_Util_004c3bc4(*(int *)(&DAT_005281fc + local_43c * 0x54));
      *(int32_t *)(&DAT_005281fc + local_43c * 0x54) = uval_1;
    }
    for (local_42c = 0; local_42c < 4; local_42c = local_42c + 1) {
      uval_1 = Sprite_EncodeFromSurface(1,local_42c * 0x12 + 0x2b,local_43c * 0x31 + 0x1c,0x11,0x2f);
      (&DAT_00676c40)[local_43c * 4 + local_42c] = (void *)uval_1;
    }
  }
  if (DAT_00528340 == DAT_00528330) {
    DAT_00528340 = Ai_Util_004c3bc4(DAT_00528340);
    DAT_00528344 = Ai_Util_004c3bc4(DAT_00528344);
    DAT_00528348 = Ai_Util_004c3bc4(DAT_00528348);
    DAT_0052834c = Ai_Util_004c3bc4(DAT_0052834c);
  }
  for (local_42c = 0; local_42c < 3; local_42c = local_42c + 1) {
    uval_1 = Sprite_EncodeFromSurface(1,local_42c * 0x3c + 0x2b,1,0x3a,0x18);
    *(int32_t *)(&DAT_00676be0 + local_42c * 4) = uval_1;
  }
  FUN_0050fc20();
  val_2 = FUN_0041f354();
  Mem_AllocOrFree_0041f12b(val_2);
  FUN_0041f17e(0x5281e0,5,val_2);
  Mem_AllocOrFree_0041f159(0);
  DAT_00641884 = 1;
  Glue_Subsystem_004eadb7(1);
  *(int32_t *)(g_DisplaySurfaceScreen + 0x20) = 1;
  *(int32_t *)(g_DisplaySurfaceBackBuffer + 0x20) = 1;
  FileIO_OpenFileStream(1,0,g_AiManaColorCost_Green - 0x1e0,s_cityinfo_pic_0052865c,(short *)0x0);
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,g_AiManaColorCost_Green - 0x1e0,0x280,0x1e0,
                     (int *)g_DisplaySurfaceBackBuffer,0,0,g_AiManaColorCost_Red,g_AiManaColorCost_Green);
  FileIO_OpenFileStream(2,0,*(int *)(g_DisplaySurfaceWork + 0x10) + -0x46,s_cinfopce_pic_0052866c,
               (short *)0x0);
  arg_2 = (int)((int)g_AiManaColorCost_Red / 2 + g_AiManaColorCost_Red * 0x30) / 0x280;
  slot_idx = Ai_Util_004c3bc4(0x52);
  arg_4 = Ai_Util_004c3bc4(0x231);
  arg_5 = Ai_Util_004c3bc4(0x2a);
  val_2 = Ai_Util_004c3bc4(0x19);
  uval_5 = arg_4;
  val_3 = Ai_Util_004c3bc4(0x38);
  Surface_StretchBlt((int *)g_DisplaySurfaceWork,0,*(int *)(g_DisplaySurfaceWork + 0x10) + -0x46,
                     0x231,0x19,(int *)g_DisplaySurfaceBackBuffer,arg_2,val_3,uval_5,val_2);
  Surface_StretchBlt((int *)g_DisplaySurfaceWork,0,*(int *)(g_DisplaySurfaceWork + 0x10) + -0x2c,
                     0x231,0x2a,(int *)g_DisplaySurfaceWork,0,0x80,arg_4,arg_5);
  for (local_42c = 0; local_42c < 9; local_42c = local_42c + 1) {
    FUN_0050e040((int *)g_DisplaySurfaceWork,0,0x80,arg_4,arg_5,(int *)g_DisplaySurfaceBackBuffer,
                 arg_2,local_42c * arg_5 + slot_idx);
  }
  FUN_0050e040((int *)g_DisplaySurfaceBackBuffer,0,0,g_AiManaColorCost_Red,g_AiManaColorCost_Green,
               (int *)g_DisplaySurfaceScreen,0,0);
  for (card_idx = 0; card_idx < 0x80; card_idx = card_idx + 1) {
    if (((((&g_CardSlot_StatusFlags)[card_idx * 100] & 2) != 0) || (g_CardSlot_ToughnessBonus != 0)) &&
       (*(int *)(&g_CardSlot_CreatureType + card_idx * 100) != 1)) {
      aiStack_418[player_idx + 1] = card_idx;
      player_idx = player_idx + 1;
    }
  }
  for (local_42c = 0; local_42c < 5; local_42c = local_42c + 1) {
    Font_DrawTextInRect((int)g_DisplaySurfaceScreen,0xfe,local_42c * 0x2a + 0xcc,0x2a);
  }
LAB_00491326:
  do {
    for (local_42c = 0; local_42c < 9; local_42c = local_42c + 1) {
      FUN_0050e040((int *)g_DisplaySurfaceWork,0,0x80,arg_4,arg_5,(int *)g_DisplaySurfaceBackBuffer,
                   arg_2,local_42c * arg_5 + slot_idx);
    }
    local_424 = local_444;
    local_43c = 0;
    while( true ) {
      val_2 = player_idx - local_444;
      if (8 < val_2) {
        val_2 = 9;
      }
      if (val_2 <= local_43c) break;
      card_idx = aiStack_418[local_424 + 1];
      val_2 = Ai_Util_004c3bc4(0x68);
      Castle_Process_00491d8f(g_DisplaySurfaceBackBuffer,card_idx,0x30,val_2 + local_43c * arg_5);
      local_43c = local_43c + 1;
      local_424 = local_424 + 1;
    }
    FUN_0050e040((int *)g_DisplaySurfaceBackBuffer,arg_2,slot_idx,arg_4,arg_5 * 9,
                 (int *)g_DisplaySurfaceScreen,arg_2,slot_idx);
    if (9 < player_idx) {
      local_45c = arg_5;
      if (local_444 == 0) {
        local_45c = 0;
      }
      FUN_0050e040((int *)g_DisplaySurfaceBackBuffer,arg_2,slot_idx,arg_4,arg_5 * 9,
                   (int *)g_DisplaySurfaceBackBuffer,arg_2,local_45c);
      if (local_444 == 0) {
        FUN_0050e040((int *)g_DisplaySurfaceWork,0,0x80,arg_4,arg_5,
                     (int *)g_DisplaySurfaceBackBuffer,arg_2,arg_5 * 9);
        val_2 = Ai_Util_004c3bc4(0x15);
        Castle_Process_00491d8f(g_DisplaySurfaceBackBuffer,aiStack_3f0[0],0x30,val_2 + arg_5 * 9);
        FUN_0050e040((int *)g_DisplaySurfaceWork,0,0x80,arg_4,arg_5,
                     (int *)g_DisplaySurfaceBackBuffer,arg_2,arg_5 * 10);
        if (10 < player_idx) {
          val_2 = Ai_Util_004c3bc4(0x15);
          Castle_Process_00491d8f(g_DisplaySurfaceBackBuffer,aiStack_3f0[1],0x30,val_2 + arg_5 * 10)
          ;
        }
      }
      else {
        FUN_0050e040((int *)g_DisplaySurfaceWork,0,0x80,arg_4,arg_5,
                     (int *)g_DisplaySurfaceBackBuffer,arg_2,0);
        val_2 = Ai_Util_004c3bc4(0x15);
        Castle_Process_00491d8f(g_DisplaySurfaceBackBuffer,aiStack_418[local_444],0x30,val_2);
        if (local_444 + 10 < player_idx) {
          FUN_0050e040((int *)g_DisplaySurfaceWork,0,0x80,arg_4,arg_5,
                       (int *)g_DisplaySurfaceBackBuffer,arg_2,arg_5 * 10);
        }
        if (local_444 + 10 < player_idx) {
          val_2 = Ai_Util_004c3bc4(0x15);
          Castle_Process_00491d8f
                    (g_DisplaySurfaceBackBuffer,aiStack_3f0[local_444],0x30,val_2 + arg_5 * 10);
        }
      }
    }
    local_430 = arg_5;
    if (local_444 == 0) {
      local_430 = 0;
    }
switchD_004918ce_default:
    if (player_idx < 10) {
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
      if (player_idx + -9 == local_444) {
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
      FUN_0041f3ea(g_MouseScreenCoordX,g_MouseScreenCoordY,g_MouseCursorButtonState);
      if (DAT_0054aae0 != -5) break;
      val_2 = Mem_AllocOrFree_00408089();
    } while (val_2 == 0);
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
    if (player_idx < 10) {
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
        for (local_42c = 0; val_2 = Ai_Util_004c3bc4(0x2b), local_42c < val_2;
            local_42c = local_42c + 3) {
          val_2 = Ai_Util_004c3bc4(3);
          val_2 = slot_idx + val_2;
          piVar6 = (int *)g_DisplaySurfaceScreen;
          uval_7 = arg_2;
          val_3 = Ai_Util_004c3bc4(5);
          DVar4 = arg_5 * 9 - val_3;
          uval_5 = arg_4;
          val_3 = Ai_Util_004c3bc4(3);
          FUN_0050e040((int *)g_DisplaySurfaceBackBuffer,arg_2,val_3 + (local_430 - local_42c),uval_5
                       ,DVar4,piVar6,uval_7,val_2);
        }
        piVar6 = (int *)g_DisplaySurfaceScreen;
        uval_5 = arg_2;
        val_2 = slot_idx;
        val_3 = Ai_Util_004c3bc4(5);
        FUN_0050e040((int *)g_DisplaySurfaceBackBuffer,arg_2,0,arg_4,arg_5 * 9 - val_3,piVar6,uval_5,
                     val_2);
        if (local_444 < 1) {
          local_430 = 0;
        }
        else {
          FUN_0050e040((int *)g_DisplaySurfaceBackBuffer,arg_2,0,arg_4,arg_5 * 10,
                       (int *)g_DisplaySurfaceBackBuffer,arg_2,arg_5);
          FUN_0050e040((int *)g_DisplaySurfaceWork,0,0x80,arg_4,arg_5,
                       (int *)g_DisplaySurfaceBackBuffer,arg_2,0);
          val_2 = Ai_Util_004c3bc4(0x15);
          Castle_Process_00491d8f(g_DisplaySurfaceBackBuffer,aiStack_418[local_444],0x30,val_2);
          local_430 = arg_5;
        }
      }
      goto switchD_004918ce_default;
    }
    if (local_434 == 0x5000) {
      if (player_idx + -9 != local_444) {
        for (local_42c = 0; val_2 = Ai_Util_004c3bc4(0x2b), local_42c < val_2;
            local_42c = local_42c + 3) {
          val_2 = Ai_Util_004c3bc4(3);
          val_2 = slot_idx + val_2;
          piVar6 = (int *)g_DisplaySurfaceScreen;
          uval_7 = arg_2;
          val_3 = Ai_Util_004c3bc4(5);
          DVar4 = arg_5 * 9 - val_3;
          uval_5 = arg_4;
          val_3 = Ai_Util_004c3bc4(3);
          FUN_0050e040((int *)g_DisplaySurfaceBackBuffer,arg_2,local_42c + val_3 + local_430,uval_5,
                       DVar4,piVar6,uval_7,val_2);
        }
        piVar6 = (int *)g_DisplaySurfaceScreen;
        uval_5 = arg_2;
        val_2 = slot_idx;
        val_3 = Ai_Util_004c3bc4(5);
        FUN_0050e040((int *)g_DisplaySurfaceBackBuffer,arg_2,local_430 + arg_5,arg_4,
                     arg_5 * 9 - val_3,piVar6,uval_5,val_2);
        local_430 = arg_5;
        if ((0 < local_444) && (local_444 < player_idx + -9)) {
          FUN_0050e040((int *)g_DisplaySurfaceBackBuffer,arg_2,arg_5,arg_4,arg_5 * 10,
                       (int *)g_DisplaySurfaceBackBuffer,arg_2,0);
          if (local_444 + 10 < player_idx) {
            FUN_0050e040((int *)g_DisplaySurfaceWork,0,0x80,arg_4,arg_5,
                         (int *)g_DisplaySurfaceBackBuffer,arg_2,arg_5 * 10);
          }
          if (local_444 + 10 < player_idx) {
            val_2 = Ai_Util_004c3bc4(0x15);
            Castle_Process_00491d8f
                      (g_DisplaySurfaceBackBuffer,aiStack_3f0[local_444 + 1],0x30,val_2 + arg_5 * 10
                      );
          }
        }
      }
      local_444 = local_444 + 1;
      if (player_idx + -9 < local_444) {
        local_444 = player_idx + -9;
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
    val_2 = local_444 + 8;
    local_444 = player_idx + -9;
    if (val_2 <= player_idx + -9) {
      local_444 = val_2;
    }
  } while( true );
}

/*
 * Decompiled function: Castle_Process_00491d8f
 * Entry Point: 00491d8f
 * Size: 1320 bytes
 */


int32_t Castle_Process_00491d8f(int32_t arg_1,int y,int width,int height)

{
  size_t len_1;
  int32_t uval_2;
  int val_3;
  int arg_4;
  int val_4;
  int val_5;
  char *mode_str;
  int local_3c [7];
  int32_t loop_idx;
  int color_idx;
  uint32_t target_idx;
  int player_idx;
  int card_idx;
  int match_count;
  int slot_idx;
  
  if (*(int *)(&g_CardSlot_CreatureType + y * 100) == 4) {
    strcpy(&g_OverworldWorldState,s_Castle_00528680);
  }
  else {
    g_OverworldWorldState = 0;
    Ai_TownEncounter_004c3b19(y);
  }
  target_idx = 0;
  while (len_1 = strlen(&g_OverworldWorldState), target_idx < len_1) {
    if ((&g_OverworldWorldState)[target_idx] == ' ') {
      (&g_OverworldWorldState)[target_idx] = 10;
    }
    target_idx = target_idx + 1;
  }
  strcat(&g_OverworldWorldState,&DAT_00528688);
  uval_2 = Surface_GetPixelColor(*(int *)(&g_DungeonMapTileX + y * 100),*(int *)(&g_DungeonMapTileY + y * 100));
  local_3c[6] = Glue_Subsystem_004ea7a6(uval_2);
  if (((&g_CardSlot_StatusFlags)[y * 100] & 1) == 0) {
    match_count = 0xe3;
  }
  else {
    match_count = 0xff;
  }
  if ((&DAT_0067be01)[y * 100] != '\0') {
    match_count = *(int *)(&DAT_00526e48 + ((int)(*(uint32_t *)(&g_CardSlot_StatusFlags + y * 100) & 0xffffff00) >> 6)
                      );
  }
  val_5 = height;
  val_3 = Ai_Util_004c3bc4(width + 0x2a);
  FUN_0040d269((int)g_DisplaySurfaceBackBuffer,match_count,val_3,val_5);
  if (((&g_CardSlot_StatusFlags)[y * 100] & 1) != 0) {
    val_5 = height;
    val_3 = Ai_Util_004c3bc4(width + 0x20c);
    FUN_0040d269((int)g_DisplaySurfaceBackBuffer,match_count,val_3,val_5);
  }
  uval_2 = Surface_GetPixelColor(*(int *)(&g_DungeonMapTileX + y * 100),*(int *)(&g_DungeonMapTileY + y * 100));
  local_3c[6] = Glue_Subsystem_004ea7a6(uval_2);
  slot_idx = 0;
  for (target_idx = 1; (int)target_idx < 6; target_idx = target_idx + 1) {
    if ((local_3c[6] & 1 << ((uint8_t)target_idx & 0x1f)) != 0) {
      slot_idx = slot_idx + 1;
    }
  }
  card_idx = (int)*(short *)(g_AiBackupBoardRegister + 4);
  player_idx = (int)*(short *)(g_AiBackupBoardRegister + 6);
  color_idx = Ai_Util_004c3bc4(((width + 0x80) - (card_idx * slot_idx) / 2) - (slot_idx * 5 + -5));
  for (target_idx = 1; (int)target_idx < 6; target_idx = target_idx + 1) {
    local_3c[1] = 2;
    local_3c[2] = 1;
    local_3c[3] = 4;
    local_3c[4] = 3;
    local_3c[5] = 0;
    if ((local_3c[6] & 1 << ((uint8_t)target_idx & 0x1f)) != 0) {
      val_5 = (&g_AiBackupBoardRegister)[local_3c[target_idx]];
      val_3 = Ai_Util_004c3bc4(player_idx);
      arg_4 = Ai_Util_004c3bc4(card_idx);
      val_4 = Ai_Util_004c3bc4(player_idx / 2);
      Sprite_DrawScaled((int *)g_DisplaySurfaceBackBuffer,color_idx,height - val_4,arg_4,val_3,val_5)
      ;
      val_5 = Ai_Util_004c3bc4(card_idx + 5);
      color_idx = color_idx + val_5;
    }
  }
  local_3c[6] = Rules_CalculateManaCostReduction((uint8_t)*(int32_t *)(&DAT_0067bdfc + y * 100));
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
  val_5 = height;
  val_3 = Ai_Util_004c3bc4(width + 0xff);
  FUN_0040d269((int)g_DisplaySurfaceBackBuffer,match_count,val_3,val_5);
  g_OverworldWorldState = 0;
  for (target_idx = 0; (int)target_idx < 0xc; target_idx = target_idx + 1) {
    if ((y != 0) && (*(int *)(&DAT_005224e8 + target_idx * 0x10) == y)) {
      loop_idx = Glue_Subsystem_004f0de8(target_idx);
      strcat(&g_OverworldWorldState,(&PTR_s_Sleight_of_hand_005225d0)[target_idx]);
    }
  }
  val_5 = Ai_Util_004c3bc4(width + 0x19c);
  FUN_0040d269((int)g_DisplaySurfaceBackBuffer,match_count,val_5,height);
  return 0;
}

/*
 * Decompiled function: Castle_Process_00492ddf
 * Entry Point: 00492ddf
 * Size: 2808 bytes
 */


void Castle_Process_00492ddf(int player_id)

{
  uint8_t flag_1;
  int32_t uval_2;
  DWORD arg_5;
  uint32_t arg_4;
  int val_3;
  uint32_t arg_2;
  char *pcVar4;
  int val_5;
  int *piVar6;
  int val_7;
  int val_8;
  int local_88 [4];
  int local_78 [4];
  int local_68 [4];
  int local_58 [4];
  int32_t local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int loop_idx;
  int color_idx;
  int target_idx;
  int player_idx;
  int card_idx;
  int match_count;
  int32_t slot_idx;
  
  slot_idx = 0x98;
  target_idx = 0xab;
  player_idx = 0x3a;
  Surface_TransformPoint(0,(short)g_MidiMusicTrackId);
  LoadPalNoPic(s_advfac64_pic_005289ec);
  Mem_AllocOrFree_00510e20(1,s_cluebutn_pic_005289fc);
  Mem_AllocOrFree_0050fc00();
  for (match_count = 0; match_count < 3; match_count = match_count + 1) {
    uval_2 = Sprite_EncodeFromSurface(1,match_count * 0x5a + 1,1,0x59,0x23);
    (&DAT_00676b90)[match_count] = (void *)uval_2;
    uval_2 = Sprite_EncodeFromSurface(1,match_count * 0x15 + 1,0x25,0x14,0x24);
    *(int32_t *)(&DAT_00676c80 + match_count * 4) = uval_2;
  }
  if (DAT_00527fa8 == DAT_00527f98) {
    DAT_00527fa8 = Ai_Util_004c3bc4(DAT_00527fa8);
    DAT_00527fac = Ai_Util_004c3bc4(DAT_00527fac);
    DAT_00527fb0 = Ai_Util_004c3bc4(DAT_00527fb0);
    DAT_00527fb4 = Ai_Util_004c3bc4(DAT_00527fb4);
  }
  loop_idx = FUN_0041f354();
  Mem_AllocOrFree_0041f12b(loop_idx);
  FUN_0041f17e(0x527f98,1,loop_idx);
  FUN_0050fc20();
  FileIO_OpenFileStream(1,0,g_AiManaColorCost_Green - 0x1e0,s_clueback_pic_00528a0c,(short *)0x0);
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,g_AiManaColorCost_Green - 0x1e0,0x280,0x1e0,
                     (int *)g_DisplaySurfaceBackBuffer,0,0,g_AiManaColorCost_Red,g_AiManaColorCost_Green);
  FUN_0050e040((int *)g_DisplaySurfaceBackBuffer,0,0,g_AiManaColorCost_Red,g_AiManaColorCost_Green,
               (int *)g_DisplaySurfaceScreen,0,0);
  val_8 = 0;
  val_7 = 0;
  piVar6 = (int *)g_DisplaySurfaceBackBuffer;
  arg_5 = Ai_Util_004c3bc4(0x24);
  arg_4 = Ai_Util_004c3bc4(0x5a);
  val_3 = Ai_Util_004c3bc4(0x1a2);
  arg_2 = Ai_Util_004c3bc4(0x16);
  Surface_BlitToDevice((int *)g_DisplaySurfaceBackBuffer,arg_2,val_3,arg_4,arg_5,piVar6,val_7,val_8);
  FUN_0041f213();
  *(int32_t *)(g_DisplaySurfaceScreen + 0x20) = 4;
  g_OverworldWorldState = 0;
  FUN_0048e2b0(arg_1);
  if (arg_1 < 5) {
    strcat(&g_OverworldWorldState,s___00528a1c);
    pcVar4 = (char *)Mem_AllocOrFree_00473d7e(arg_1 + 1);
    strcat(&g_OverworldWorldState,pcVar4);
    strcat(&g_OverworldWorldState,s_Castle__00528a28);
    FUN_0040d1cd((int)g_DisplaySurfaceScreen,player_idx,0x12,0x1c);
    card_idx = Ai_Util_004c3ba3(0x24);
  }
  else {
    card_idx = FUN_00492cb1(0x10,player_idx);
    card_idx = Ai_Util_004c3ba3(0x1c);
  }
  for (match_count = 0; match_count < 3; match_count = match_count + 1) {
    if (*(int *)(&DAT_0067eff0 + match_count * 4 + arg_1 * 0x30) != -1) {
      FUN_0050b206(*(int *)(&DAT_0067eff0 + match_count * 4 + arg_1 * 0x30),match_count * 0x29 + 0xa0,
                   (-(uint32_t)(match_count == 0) & 8) + match_count * 4 + 0x76,1,&DAT_00528a34);
    }
  }
  if ((((&DAT_0067f010)[arg_1 * 0x30] & 2) != 0) || (g_CardSlot_ToughnessBonus != 0)) {
    val_3 = card_idx;
    uval_2 = slot_idx;
    val_7 = Ai_Util_004c3ba3(0xc);
    FUN_0040c1ad(s_Creatures__00528a38,val_7,val_3,uval_2);
    val_3 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
    card_idx = card_idx + val_3;
    if (arg_1 < 5) {
      flag_1 = FUN_0049094c();
      (&DAT_0067f00d)[arg_1 * 0x30] = flag_1 | 0x80;
    }
    strcpy(&g_OverworldWorldState,s__Contains_00528a44);
    strcat(&g_OverworldWorldState,
           s_large_00528a50 + ((((&DAT_0067f00d)[arg_1 * 0x30] & 0x80) != 0) - 1 & 8));
    pcVar4 = (char *)Mem_AllocOrFree_00473d7e((int)(char)(&DAT_0067f00c)[arg_1 * 0x30]);
    strcat(&g_OverworldWorldState,pcVar4);
    strcat(&g_OverworldWorldState,s_creatures__00528a60);
    card_idx = FUN_00492cb1(card_idx,target_idx);
  }
  val_3 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
  val_3 = card_idx + val_3;
  card_idx = val_3;
  if ((((&DAT_0067f010)[arg_1 * 0x30] & 4) != 0) || (g_CardSlot_ToughnessBonus != 0)) {
    uval_2 = slot_idx;
    val_7 = Ai_Util_004c3ba3(0xc);
    FUN_0040c1ad(s_Dungeon_Rules__00528a6c,val_7,val_3,uval_2);
    val_3 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
    card_idx = card_idx + val_3;
    if (((&g_TownBuildingFlagsTable)[arg_1 * 0x30] & 0x10) != 0) {
      strcpy(&g_OverworldWorldState,&DAT_00528a7c);
      pcVar4 = (char *)Mem_AllocOrFree_00473d7e((int)(char)(&DAT_0067f00c)[arg_1 * 0x30]);
      strcat(&g_OverworldWorldState,pcVar4);
      strcat(&g_OverworldWorldState,s_cards_allowed__00528a84);
      card_idx = FUN_00492cb1(card_idx,target_idx);
    }
    if (((&g_TownBuildingFlagsTable)[arg_1 * 0x30] & 0x20) != 0) {
      strcpy(&g_OverworldWorldState,s__One_deck_for_all_duels__00528a94);
      card_idx = FUN_00492cb1(card_idx,target_idx);
    }
    if (((&g_TownBuildingFlagsTable)[arg_1 * 0x30] & 0x40) != 0) {
      strcpy(&g_OverworldWorldState,s__No_artifacts_allowed__00528ab0);
      card_idx = FUN_00492cb1(card_idx,target_idx);
    }
    if (((&g_TownBuildingFlagsTable)[arg_1 * 0x30] & 0x80) != 0) {
      strcpy(&g_OverworldWorldState,s__No_instants_or_interrupts_allow_00528ac8);
      card_idx = FUN_00492cb1(card_idx,target_idx);
    }
    if (((&g_TownBuildingFlagsTable)[arg_1 * 0x30] & 1) != 0) {
      strcpy(&g_OverworldWorldState,s__Life_losses_carried_over__00528aec);
      card_idx = FUN_00492cb1(card_idx,target_idx);
    }
    if (((&g_TownBuildingFlagsTable)[arg_1 * 0x30] & 2) != 0) {
      strcpy(&g_OverworldWorldState,s__Remaining_life_added_to_next_du_00528b08);
      card_idx = FUN_00492cb1(card_idx,target_idx);
    }
    if (*(int *)(&DAT_0067effc + arg_1 * 0x30) == -1) {
      if (*(int *)(&g_TownBuildingFlagsTable + arg_1 * 0x30) == 0) {
        strcpy(&g_OverworldWorldState,s__No_special_rules__00528b48);
        card_idx = FUN_00492cb1(card_idx,target_idx);
      }
    }
    else {
      strcpy(&g_OverworldWorldState,&DAT_00528b2c);
      val_3 = Pic_Subsystem_0045268f(*(int *)(&DAT_0067effc + arg_1 * 0x30));
      strcat(&g_OverworldWorldState,s_Swamp_0051aea9 + val_3 * 0x34);
      strcat(&g_OverworldWorldState,s_permanently_in_effect__00528b30);
      card_idx = FUN_00492cb1(card_idx,target_idx);
    }
    val_3 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
    card_idx = card_idx + val_3;
  }
  if ((((&DAT_0067f010)[arg_1 * 0x30] & 1) != 0) || (g_CardSlot_ToughnessBonus != 0)) {
    val_3 = card_idx;
    uval_2 = slot_idx;
    val_7 = Ai_Util_004c3ba3(0xc);
    FUN_0040c1ad(s_Location__00528b5c,val_7,val_3,uval_2);
    val_3 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
    card_idx = card_idx + val_3;
    color_idx = *(int *)(&DAT_0067f000 + arg_1 * 0x30) -
               *(int *)(&g_DungeonMapTileX + *(int *)(&DAT_0067f008 + arg_1 * 0x30) * 100);
    local_24 = *(int *)(&DAT_0067f004 + arg_1 * 0x30) -
               *(int *)(&g_DungeonMapTileY + *(int *)(&DAT_0067f008 + arg_1 * 0x30) * 100);
    if (local_24 < 1) {
      strcpy(&g_OverworldWorldState,s__North_00528b78 + ((0 < color_idx) - 1 & 8));
    }
    else {
      strcpy(&g_OverworldWorldState,s__East_00528b68 + ((0 < color_idx) - 1 & 8));
    }
    strcat(&g_OverworldWorldState,&DAT_00528b88);
    Ai_TownEncounter_004c3b19(*(uint32_t *)(&DAT_0067f008 + arg_1 * 0x30));
    strcat(&g_OverworldWorldState,&DAT_00528b90);
    card_idx = FUN_00492cb1(card_idx,target_idx);
  }
  if ((((&DAT_0067f010)[arg_1 * 0x30] & 1) != 0) || (g_CardSlot_ToughnessBonus != 0)) {
    FUN_0040c550(g_DisplaySurfaceWork,0,0,0x50,0x32,g_DisplaySurfaceWork,0x50,0);
    uval_2 = 0;
    val_3 = Ai_Util_004c3bc4(0xe1);
    val_3 = val_3 + -0x18;
    val_7 = Ai_Util_004c3bc4(0x17e);
    val_7 = val_7 + -0x18;
    val_8 = Ai_Util_004c3bc4(0xc);
    val_8 = val_8 + 10;
    val_5 = Ai_Util_004c3bc4(0xf4);
    (*(code *)PTR_FUN_00527b3c)(val_5 + 10,val_8,val_7,val_3,uval_2);
    *(int32_t *)g_DisplaySurfaceScreen = *(int32_t *)g_DisplaySurfaceBackBuffer;
    Ai_Util_004be240();
    local_48 = *(int32_t *)g_DisplaySurfaceBackBuffer;
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
    *(int32_t *)g_DisplaySurfaceBackBuffer = local_48;
    *(int32_t *)g_DisplaySurfaceScreen = 0;
    FUN_0040c550(g_DisplaySurfaceBackBuffer,0x40,g_AiHeuristicWeight_CardAdvantage,0xb3,100,g_DisplaySurfaceScreen,0x7f,
                 0xb);
    FUN_0040c550(g_DisplaySurfaceWork,0x50,0,0x50,0x32,g_DisplaySurfaceWork,0,0);
  }
  DAT_0054aae0 = -1;
  while (DAT_0054aae0 == -1) {
    Pic_Subsystem_0044b84b();
    FUN_0041f3ea(g_MouseScreenCoordX,g_MouseScreenCoordY,g_MouseCursorButtonState);
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

int Town_Process_00506580(uint32_t arg_1)

{
  uint8_t flag_1;
  char *char_ptr_2;
  int val_3;
  int32_t uval_4;
  int val_5;
  int arg_5;
  int arg_4;
  int event_type;
  int card_slot;
  uint32_t local_94;
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
  uint32_t local_40;
  int local_3c;
  int local_38;
  uint32_t local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int loop_idx;
  int color_idx;
  LPVOID target_idx;
  int player_idx;
  int card_idx;
  int match_count;
  int slot_idx;
  
  DAT_0061e0d4 = arg_1;
  App_ProcessPendingMessages();
  if ((&DAT_0067be01)[arg_1 * 100] == '\0') {
    if (*(int *)(&g_CardSlot_CreatureType + arg_1 * 100) == 4) {
      local_64[1] = s_0246_pic_00531a34;
      local_64[2] = s_0364_pic_00531a4c;
      local_64[3] = s_0335_pic_00531a64;
      local_54 = s_0737_pic_00531a7c;
      local_50 = s_0028_pic_00531a94;
      uval_4 = Surface_GetPixelColor(*(int *)(&g_DungeonMapTileX + arg_1 * 100),
                           *(int *)(&g_DungeonMapTileY + arg_1 * 100));
      flag_1 = Glue_Subsystem_004ea7a6(uval_4);
      DAT_006b2d64 = Rules_CalculateManaCostReduction(flag_1);
      FUN_0040aaf1(local_64[DAT_006b2d64]);
      *(int32_t *)(g_DisplaySurfaceScreen + 0x20) = 1;
      strcpy(&g_OverworldWorldState,s_Who_dares_to_challenge_the_Might_00531aa0);
      char_ptr_2 = (char *)Mem_AllocOrFree_00473d7e(DAT_006b2d64);
      strcat(&g_OverworldWorldState,char_ptr_2);
      strcat(&g_OverworldWorldState,s_Wizard__Are_you_brave_enough_to_e_00531ac4);
      strcat(&g_OverworldWorldState,s_Well____No__Yes__enter_the_castl_00531af8);
      val_3 = FUN_004896be(&g_OverworldWorldState,0x2a,0x1a);
      if (val_3 == 1) {
        Pic_Subsystem_00423c82(0x10);
        FUN_004909a0(DAT_006b2d64 + -1);
        if (((DAT_0067bdb4 & 1 << ((uint8_t)DAT_006b2d64 & 0x1f)) == 0) && (g_CampaignDifficultyLevel == 3)) {
          Glue_Sound_004eb2f9(DAT_006b2d64);
        }
      }
      Palette_Subsystem_00496eaf();
      val_3 = 0;
    }
    else if (*(int *)(&g_CardSlot_CreatureType + arg_1 * 100) == 5) {
      local_74 = s_0246_pic_00531b2c;
      local_70 = s_0364_pic_00531b44;
      local_6c = s_0335_pic_00531b5c;
      local_68 = s_0737_pic_00531b74;
      local_64[0] = s_0028_pic_00531b8c;
      uval_4 = Surface_GetPixelColor(*(int *)(&g_DungeonMapTileX + arg_1 * 100),
                           *(int *)(&g_DungeonMapTileY + arg_1 * 100));
      flag_1 = Glue_Subsystem_004ea7a6(uval_4);
      DAT_006b2d64 = Rules_CalculateManaCostReduction(flag_1);
      FUN_0040aaf1((&local_78)[DAT_006b2d64]);
      strcpy(&g_OverworldWorldState,s_The_Mighty_00531b98);
      char_ptr_2 = (char *)Mem_AllocOrFree_00473d7e(DAT_006b2d64);
      strcat(&g_OverworldWorldState,char_ptr_2);
      strcat(&g_OverworldWorldState,s_Wizard_was_crushed_in_epic_comba_00531ba4);
      FUN_004896be(&g_OverworldWorldState,0x2a,0x1a);
      Pic_Subsystem_00423c82(0x10);
      Palette_Subsystem_00496eaf();
      val_3 = 0;
    }
    else {
      if ((g_AiManaColorCost_White == arg_1) && ((-1 < g_AiHandEvaluationBuffer || (g_AiHandEvaluationBuffer < -100)))) {
        FUN_0040a95d(s_village_pic_00531c0c +
                     ((*(int *)(&g_CardSlot_CreatureType + arg_1 * 100) == 1) - 1 & 0xc));
        match_count = 0;
        FUN_0040b3c2(0x10,g_AiHandEvaluationBuffer);
        if ((g_AiHandEvaluationBuffer == 0) || (g_AiHandEvaluationBuffer == 2)) {
          strcpy(&g_OverworldWorldState,s_The_keeper_is_pleased_to_receive_00531c24);
          if (g_AiHandEvaluationBuffer == 0) {
            strcat(&g_OverworldWorldState,s_You_create_a_mana_link_here__00531c5c);
            Pic_Subsystem_00423b93(0xf);
            Glue_Subsystem_004ec5be(s_x_sound_manalink_wav_00531c7c,0xf,0);
            Glue_Subsystem_004ebd62(0xf,100,100,0);
            *(uint32_t *)(&g_CardSlot_StatusFlags + g_AiManaColorCost_White * 100) =
                 *(uint32_t *)(&g_CardSlot_StatusFlags + g_AiManaColorCost_White * 100) | 1;
          }
          if (g_AiHandEvaluationBuffer == 2) {
            strcat(&g_OverworldWorldState,s_You_are_rewarded_with_a_fine_00531c94);
            char_ptr_2 = (char *)Mem_AllocOrFree_00473d7e(DAT_0067b9a0);
            strcat(&g_OverworldWorldState,char_ptr_2);
            strcat(&g_OverworldWorldState,s_amulet__00531cb4);
            Pic_Subsystem_00423b93(0xf);
            Glue_Subsystem_004ec5be(s_x_sound_reward_wav_00531cc0,0xf,0);
            Glue_Subsystem_004ebd62(0xf,100,100,0);
            *(int *)(&DAT_0067bdbc + DAT_0067b9a0 * 4) =
                 *(int *)(&DAT_0067bdbc + DAT_0067b9a0 * 4) + 1;
          }
          *(int32_t *)(g_DisplaySurfaceScreen + 0x20) = 1;
          FUN_004896be(&g_OverworldWorldState,0x50,0x50);
          match_count = 1;
          g_AiManaColorCost_White = 0xffffffff;
          Overworld_LoadAdventureInterface800();
          Ai_Subsystem_004c3c5c(1);
        }
        if ((g_AiHandEvaluationBuffer == 1) &&
           (val_3 = FUN_0050b0fc((uint8_t)DAT_0067b9a0,(uint8_t)(1 << ((uint8_t)g_AiManaColorCost_White & 3))),
           val_3 != 0)) {
          local_30 = FUN_0050b0fc((uint8_t)DAT_0067b9a0,(uint8_t)(1 << ((uint8_t)g_AiManaColorCost_White & 3)));
          *(int *)(&DAT_0067bdbc + DAT_0067b9a0 * 4) =
               *(int *)(&DAT_0067bdbc + DAT_0067b9a0 * 4) + 1;
          strcpy(&g_OverworldWorldState,s_The_people_are_pleased_to_receiv_00531cd4);
          strcat(&g_OverworldWorldState,
                 s_Swamp_0051aea9 + ((&DAT_0070214c)[local_30] & 0xfff) * 0x34);
          strcat(&g_OverworldWorldState,s_spell__You_are_rewarded_with_a_f_00531cfc);
          char_ptr_2 = (char *)Mem_AllocOrFree_00473d7e(DAT_0067b9a0);
          strcat(&g_OverworldWorldState,char_ptr_2);
          strcat(&g_OverworldWorldState,s_amulet_and_a_mana_link__00531d24);
          *(int32_t *)(g_DisplaySurfaceScreen + 0x20) = 1;
          DAT_00676d3c = 1;
          FUN_004896be(&g_OverworldWorldState,0x50,0x50);
          *(uint32_t *)(&g_CardSlot_StatusFlags + g_AiManaColorCost_White * 100) =
               *(uint32_t *)(&g_CardSlot_StatusFlags + g_AiManaColorCost_White * 100) | 1;
          match_count = 1;
          Pic_Subsystem_00452065(local_30 + -1);
          Ai_Subsystem_004cd1d1();
          g_AiManaColorCost_White = 0xffffffff;
          Overworld_LoadAdventureInterface800();
          Ai_Subsystem_004c3c5c(1);
        }
        if (g_AiHandEvaluationBuffer < -100) {
          if (*(int *)(&g_CardSlot_CreatureType + g_AiManaColorCost_White * 100) < 2) {
            g_AiHandEvaluationBuffer = g_AiHandEvaluationBuffer + 100;
            loop_idx = (int)(char)(&DAT_00522628)[g_AiHandEvaluationBuffer * -0x44] / 7 + 1;
            strcpy(&g_OverworldWorldState,s_The_village_is_glad_to_be_rid_of_00531de0);
            Glue_Subsystem_004eaa19(-g_AiHandEvaluationBuffer,0,0);
            strcat(&g_OverworldWorldState,s_You_are_rewarded_with_00531e0c);
            char_ptr_2 = _itoa(loop_idx,&DAT_0061e0f0,10);
            strcat(&g_OverworldWorldState,char_ptr_2);
            strcat(&g_OverworldWorldState,s_fine_00531e24);
            char_ptr_2 = (char *)Mem_AllocOrFree_00473d7e(DAT_0067b9a0);
            strcat(&g_OverworldWorldState,char_ptr_2);
            strcat(&g_OverworldWorldState,s_amulet_00531e2c);
            strcat(&g_OverworldWorldState,&DAT_00531e34 + ((loop_idx == 1) - 1 & 4));
            FUN_004896be(&g_OverworldWorldState,0x50,0x50);
            *(int *)(&DAT_0067bdbc + DAT_0067b9a0 * 4) =
                 *(int *)(&DAT_0067bdbc + DAT_0067b9a0 * 4) + loop_idx;
            *(uint32_t *)(&g_CardSlot_StatusFlags + g_AiManaColorCost_White * 100) =
                 *(uint32_t *)(&g_CardSlot_StatusFlags + g_AiManaColorCost_White * 100) | 1;
          }
          else {
            local_78 = 1;
            g_AiHandEvaluationBuffer = g_AiHandEvaluationBuffer + 100;
            loop_idx = (int)(char)(&DAT_00522628)[g_AiHandEvaluationBuffer * -0x44] / 7 + 1;
            strcpy(&g_OverworldWorldState,s_The_people_are_glad_to_be_rid_of_00531d40);
            Glue_Subsystem_004eaa19(-g_AiHandEvaluationBuffer,0,0);
            strcat(&g_OverworldWorldState,s_You_are_rewarded_with_00531d6c);
            FUN_0050a73e(g_AiManaColorCost_White);
            strcat(&g_OverworldWorldState,s_of_your_choice__00531d88);
            FUN_004896be(&g_OverworldWorldState,0x50,0x50);
            PTR_FUN_00527b3c = Mem_AllocOrFree_0040eea2;
            local_40 = 0xffffffff;
            while (local_40 == 0xffffffff) {
              local_40 = Palette_Color_0049716e
                                   (s_Which_card_do_you_seek__00531d9c,
                                    *(uint32_t *)(&DAT_0067bdfc + arg_1 * 100) & 0xff,
                                    (*(int *)(&DAT_0067bdfc + arg_1 * 100) >> 8) - 1,local_78,0);
              local_78 = 0;
              if (local_40 != 0xffffffff) {
                strcpy(&g_OverworldWorldState,s_Will_you_take_this_card____Yes_N_00531db4);
                do {
                  val_3 = Ai_Util_004c3bc4(0x15c);
                  val_3 = val_3 + 10;
                  val_5 = Ai_Util_004c3bc4(0xf4);
                  val_3 = FUN_00489710(&g_OverworldWorldState,val_5 + 10,val_3);
                } while (val_3 < 0);
                if (val_3 == 0) {
                  local_30 = Pic_Subsystem_00451e40(local_40);
                  if (local_30 != -1) {
                    *(uint32_t *)(&deck + local_30 * 4) = *(uint32_t *)(&deck + local_30 * 4) | 0x4000;
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
          match_count = 1;
          if (g_AiManaColorCost_White == DAT_00531594) {
            DAT_00531594 = 0xffffffff;
          }
          g_AiManaColorCost_White = 0xffffffff;
          Overworld_LoadAdventureInterface800();
          Ai_Subsystem_004c3c5c(1);
        }
        if (match_count == 0) {
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
      *(uint32_t *)(&g_CardSlot_StatusFlags + arg_1 * 100) = *(uint32_t *)(&g_CardSlot_StatusFlags + arg_1 * 100) | 2;
      *(int *)(&DAT_0067be4c + arg_1 * 100) = *(int *)(&DAT_0067be4c + arg_1 * 100) + 1;
      FUN_0040a95d(s_village_pic_00531e3c + ((*(int *)(&g_CardSlot_CreatureType + arg_1 * 100) == 1) - 1 & 0xc)
                  );
      Town_Process_00507c86(arg_1);
      *(int *)(&DAT_0067be50 + arg_1 * 100) = DAT_00641020;
      if ((*(int *)(&g_CardSlot_CreatureType + arg_1 * 100) == 3) ||
         (*(int *)(&g_CardSlot_CreatureType + arg_1 * 100) == 2)) {
        card_idx = -1;
        local_38 = 999;
        for (local_28 = 0; local_28 < 0xc; local_28 = local_28 + 1) {
          if ((*(int *)(&DAT_005224e8 + local_28 * 0x10) != 0) &&
             (player_idx = FUN_0040a36f(*(int *)(&g_DungeonMapTileX + arg_1 * 100) -
                                      *(int *)(&g_DungeonMapTileX +
                                              *(int *)(&DAT_005224e8 + local_28 * 0x10) * 100),
                                      *(int *)(&g_DungeonMapTileY + arg_1 * 100) -
                                      *(int *)(&g_DungeonMapTileY +
                                              *(int *)(&DAT_005224e8 + local_28 * 0x10) * 100)),
             player_idx < local_38)) {
            card_idx = local_28;
            local_38 = player_idx;
          }
        }
        if ((card_idx != -1) && ((g_OverworldMovementFlags & 1 << ((uint8_t)card_idx & 0x1f)) == 0)) {
          Mem_AllocOrFree_00510e20(1,s_worlbak1_pic_00531e54);
          Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,
                             (int *)g_DisplaySurfaceScreen,0,0,g_AiManaColorCost_Red,g_AiManaColorCost_Green);
          local_30 = Glue_Subsystem_004f0de8(card_idx);
          val_3 = *(int *)(&DAT_006782a0 + card_idx * 4);
          local_24 = (0x4e - *(short *)(val_3 + 6)) / 2 + 0x4c;
          color_idx = (0x4f - *(short *)(val_3 + 4)) / 2 + 0x14f;
          val_5 = *(int *)(&DAT_006782a0 + card_idx * 4);
          arg_5 = Ai_Util_004c3bc4((int)*(short *)(val_3 + 6));
          arg_4 = Ai_Util_004c3bc4((int)*(short *)(val_3 + 4));
          arg_3 = Ai_Util_004c3bc4(local_24);
          arg_2 = Ai_Util_004c3bc4(color_idx);
          Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,arg_2,arg_3,arg_4,arg_5,val_5);
          local_24 = (local_24 + *(short *)(val_3 + 6) + 0x10) / 2;
          color_idx = (color_idx + (int)*(short *)(val_3 + 4) / 2) / 2;
          *(int32_t *)(g_DisplaySurfaceScreen + 0x20) = 4;
          Font_DrawTextInRect((int)g_DisplaySurfaceScreen,0x7b,0x176,0x4b);
          g_OverworldWorldState = 0;
          local_24 = local_24 + -5;
          strcat(&g_OverworldWorldState,(&PTR_s_Sleight_of_hand_005225d0)[card_idx]);
          FUN_0040c336(&g_OverworldWorldState,color_idx,local_24,0x40);
          local_24 = local_24 + 8;
          strcpy(&g_OverworldWorldState,s_costs_00531e70);
          char_ptr_2 = _itoa(*(int *)(&DAT_005224e4 + card_idx * 0x10) / 2,&DAT_0061e0f0,10);
          strcat(&g_OverworldWorldState,char_ptr_2);
          strcat(&g_OverworldWorldState,s_gold_pieces__00531e78);
          FUN_0040c336(&g_OverworldWorldState,color_idx,local_24,0x7b);
          local_24 = local_24 + 8;
          strcpy(&g_OverworldWorldState,&DAT_00531e88);
          strcat(&g_OverworldWorldState,(&PTR_s_A_clever_duelist_can_switch_ante_005225a0)[card_idx]
                );
          strcat(&g_OverworldWorldState,&DAT_00531e8c);
          val_3 = Ai_Util_004c3ba3(local_24);
          val_5 = Ai_Util_004c3ba3(color_idx);
          FUN_0040d201((int)g_DisplaySurfaceScreen,0x7b,val_5,val_3);
          if (local_38 == 0) {
            if (Gold < *(int *)(&DAT_005224e4 + card_idx * 0x10) / 2) {
              local_24 = local_24 + 0x18;
              strcpy(&g_OverworldWorldState,s_Insufficient_Funds_00531f1c);
              FUN_0040c336(&g_OverworldWorldState,color_idx,local_24,0xbe);
              local_24 = local_24 + 8;
              App_ProcessPendingMessages();
              Ai_Subsystem_004cd1d1();
            }
            else {
              local_24 = local_24 + 0x10;
              strcpy(&g_OverworldWorldState,s_To_release_the_WORLDMAGIC_spell___00531ea4);
              strcat(&g_OverworldWorldState,(&PTR_s_Sleight_of_hand_005225d0)[card_idx]);
              strcat(&g_OverworldWorldState,s___from_00531ec8);
              Ai_TownEncounter_004c3b19(*(uint32_t *)(&DAT_005224e8 + card_idx * 0x10));
              strcat(&g_OverworldWorldState,s___you_must_pay_00531ed4);
              char_ptr_2 = _itoa(*(int *)(&DAT_005224e4 + card_idx * 0x10) / 2,&DAT_0061e0f0,10);
              strcat(&g_OverworldWorldState,char_ptr_2);
              strcat(&g_OverworldWorldState,s_gold_pieces__00531ee4);
              strcat(&g_OverworldWorldState,s_Will_you____Never_mind_Pay_the_g_00531ef4);
              App_ProcessPendingMessages();
              local_30 = FUN_004896be(&g_OverworldWorldState,
                                      (-(uint32_t)(g_AiManaColorCost_Red == 0x280) & 0xffffffce) + 0xbe,0x88);
              DAT_00531590 = card_idx;
              val_3 = DAT_00531590;
              if (local_30 == 1) {
                Gold = Gold - *(int *)(&DAT_005224e4 + card_idx * 0x10) / 2;
                DAT_00531590._0_1_ = (uint8_t)card_idx;
                g_OverworldMovementFlags = g_OverworldMovementFlags | 1 << ((uint8_t)DAT_00531590 & 0x1f);
                DAT_00531590 = val_3;
                *(int32_t *)(&DAT_005224e8 + card_idx * 0x10) = 0;
                FUN_0040b3c2(6,card_idx);
              }
              DAT_00531590 = -1;
            }
          }
          else {
            local_48 = *(int *)(&g_DungeonMapTileX + *(int *)(&DAT_005224e8 + card_idx * 0x10) * 100) -
                       *(int *)(&g_DungeonMapTileX + arg_1 * 100);
            local_4c = *(int *)(&g_DungeonMapTileY + *(int *)(&DAT_005224e8 + card_idx * 0x10) * 100) -
                       *(int *)(&g_DungeonMapTileY + arg_1 * 100);
            local_24 = local_24 + 0x10;
            strcpy(&g_OverworldWorldState,s_Travel_00531e90);
            FUN_0050aef6(*(int *)(&g_DungeonMapTileX + *(int *)(&DAT_005224e8 + card_idx * 0x10) * 100),
                         *(int *)(&g_DungeonMapTileY + *(int *)(&DAT_005224e8 + card_idx * 0x10) * 100));
            strcat(&g_OverworldWorldState,&DAT_00531e98);
            Ai_TownEncounter_004c3b19(*(uint32_t *)(&DAT_005224e8 + card_idx * 0x10));
            strcat(&g_OverworldWorldState,&DAT_00531ea0);
            local_24 = local_24 + 8;
            FUN_0040c336(&g_OverworldWorldState,color_idx,local_24,0x8d);
            local_24 = local_24 + 8;
            DAT_00531590 = card_idx;
            App_ProcessPendingMessages();
            Ai_Subsystem_004cd1d1();
          }
        }
      }
      Palette_Subsystem_00496eaf();
      val_3 = DAT_0067bddc;
      if (DAT_0067bddc < DAT_00641020) {
        g_AiManaColorCost_White = 0xffffffff;
      }
    }
  }
  else {
    FUN_0040a95d(s_village_pic_0053193c + ((*(int *)(&g_CardSlot_CreatureType + arg_1 * 100) == 1) - 1 & 0xc));
    Glue_Subsystem_004eadb7(1);
    for (local_2c = 0; local_2c < 0x10; local_2c = local_2c + 1) {
      (&DAT_006b2dd0)[local_2c] = -1;
      (&DAT_006b2d90)[local_2c] = (&DAT_006b2dd0)[local_2c];
    }
    Glue_Subsystem_004eccd7();
    local_44 = *(int *)(&g_DungeonMapTileY + arg_1 * 100);
    for (local_2c = 0; local_2c < *(int *)(&g_DungeonMapTileX + arg_1 * 100) % 3 + 1;
        local_2c = local_2c + 1) {
      do {
        do {
          local_30 = local_44 % 500;
          local_44 = local_44 + 7;
        } while (*(int *)(&deck + local_30 * 4) == -1);
      } while ((((&DAT_00702151)[local_30 * 4] & 0x40) != 0) ||
              ((*(uint32_t *)(&deck + local_30 * 4) & 0xfff) < 5));
      (&DAT_006b2d90)[local_2c] = *(uint32_t *)(&deck + local_30 * 4) & 0xfff;
      FUN_0050b206(*(uint32_t *)(&deck + local_30 * 4) & 0xfff,local_2c * 0x28 + 0x60,
                   local_2c * 3 + 0x80,1,s_Your_ANTE_00531954);
    }
    local_3c = *(int *)(&g_CardSlot_StatusFlags + arg_1 * 100) >> 8;
    switch((int)(DAT_0052f004 + (DAT_0052f004 >> 0x1f & 0x7fU)) >> 7) {
    case 0:
      target_idx = (LPVOID)0x4;
      break;
    case 1:
      target_idx = (LPVOID)0x6;
      break;
    case 2:
      target_idx = (LPVOID)0x8;
      break;
    case 3:
      target_idx = (LPVOID)0xc;
      break;
    case 4:
      target_idx = (LPVOID)0x10;
      break;
    default:
      if (((&g_DungeonMapTileY)[arg_1 * 100] & 1) == 0) {
        target_idx = (LPVOID)0xe;
      }
      else {
        target_idx = (LPVOID)0x12;
      }
    }
    target_idx = (LPVOID)Glue_Subsystem_004ea97c(local_3c,(int)target_idx);
    Deck_LoadPreconstructedDeck((int)target_idx,0xffffffff,0,-1);
    do {
      do {
        DAT_006b2dd0 = FUN_0040a02a(DAT_0052eff8);
      } while (DAT_006b2dd0 < 5);
    } while (((&g_MasterCardFlagsTable)[DAT_006b2dd0 * 0x34] & 1) != 0);
    FUN_0050b206(DAT_006b2dd0,0xe0,0x40,1,s_Wizard_s_ANTE_00531960);
    Pic_Load_advfac64_00489188(target_idx,0xa0,0x20,1,2);
    strcpy(&g_OverworldWorldState,s_This_place_is_ruled_by_the_00531970);
    char_ptr_2 = (char *)Mem_AllocOrFree_00473d7e(local_3c);
    strcat(&g_OverworldWorldState,char_ptr_2);
    strcat(&g_OverworldWorldState,s_Wizard_You_must_duel_0053198c);
    Glue_Subsystem_004eaa19((int)target_idx,1,0);
    strcat(&g_OverworldWorldState,s_to_free_the_city__Never_mind__Du_005319a4);
    val_3 = FUN_004896be(&g_OverworldWorldState,0x78,0x38);
    if (val_3 == 1) {
      val_3 = Util_GetRandomNumber(3);
      g_GlobalEnchantmentCardId = Pic_Subsystem_0045268f
                               (*(int *)(&DAT_00527f10 + val_3 * 4 + (local_3c * 3 + -3) * 4));
      _DAT_0067f354 = local_3c;
      _DAT_0067f348 = target_idx;
      local_40 = Pic_Subsystem_0045268f(*(int *)(&DAT_0052262c + (int)target_idx * 0x44));
      Deck_LoadPreconstructedDeck((int)target_idx,local_40,0,-1);
      DAT_006b2d64 = local_3c;
      DAT_0063ee24 = 0;
      DAT_00695df0 = 3;
      slot_idx = Deck_LoadOneDeckProfile(local_40,target_idx);
      if (slot_idx == 1) {
        Glue_Subsystem_004ebfef(1);
        *(uint32_t *)(&g_CardSlot_StatusFlags + arg_1 * 100) = *(uint32_t *)(&g_CardSlot_StatusFlags + arg_1 * 100) & 0xffff00ff
        ;
        Mem_AllocOrFree_00510de0(1,s_celeb_pic_005319dc);
        Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,
                           (int *)g_DisplaySurfaceScreen,0,0,g_AiManaColorCost_Red,g_AiManaColorCost_Green);
        g_OverworldWorldState = 0;
        Ai_TownEncounter_004c3b19(arg_1);
        strcat(&g_OverworldWorldState,s_is_freed__The_people_rejoice__005319e8);
        FUN_004896be(&g_OverworldWorldState,0x14,0x14);
        FUN_0040b3c2(7,arg_1);
      }
      if (slot_idx == 0) {
        Glue_Subsystem_004ebfef(2);
        for (local_2c = 0; local_2c < 3; local_2c = local_2c + 1) {
          local_34 = (&DAT_006b2d90)[local_2c];
          if (local_34 != 0xffffffff) {
            Mem_AllocOrFree_00510de0(1,s_losedul2_pic_00531a08);
            Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,
                               (int *)g_DisplaySurfaceScreen,0,0,g_AiManaColorCost_Red,g_AiManaColorCost_Green);
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
    val_3 = 0;
  }
  return val_3;
}

/*
 * Decompiled function: Town_Process_00507c86
 * Entry Point: 00507c86
 * Size: 4024 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int32_t Town_Process_00507c86(uint32_t arg_1)

{
  uint8_t flag_1;
  int32_t uval_2;
  int val_3;
  int32_t uval_4;
  int local_a4;
  int aiStack_a0 [16];
  int local_60;
  uint32_t local_58;
  uint32_t local_50;
  int local_4c;
  uint32_t local_48;
  uint32_t local_44;
  uint32_t local_3c;
  int local_34;
  int local_30;
  int local_24;
  int loop_idx;
  int color_idx;
  int target_idx;
  uint32_t player_idx;
  int32_t match_count;
  int slot_idx;
  
  App_ProcessPendingMessages();
  DAT_0062680c = arg_1;
  uval_2 = Surface_GetPixelColor(*(int *)(&g_DungeonMapTileX + arg_1 * 100),*(int *)(&g_DungeonMapTileY + arg_1 * 100));
  local_50 = Glue_Subsystem_004ea7a6(uval_2);
  loop_idx = *(int *)(&g_CardSlot_CreatureType + DAT_0062680c * 100) + 3;
  if (DAT_005224f8 == 0) {
    loop_idx = *(int *)(&g_CardSlot_CreatureType + DAT_0062680c * 100) + 4;
  }
  if (7 < loop_idx) {
    loop_idx = 8;
  }
  player_idx = 0xffffffff;
  for (local_3c = 0; (int)local_3c < 199; local_3c = local_3c + 1) {
    val_3 = Util_GetRandomNumber(5);
    local_44 = val_3 + 1;
    if (((*(int *)(&DAT_0067bdbc + local_44 * 4) != 0) || (0x50 < (int)local_3c)) &&
       ((local_50 & 1 << ((uint8_t)local_44 & 0x1f)) != 0)) {
      player_idx = local_44;
    }
  }
  DAT_00626604 = player_idx;
  DAT_006265f8 = -1;
  DAT_0061e0fc = arg_1;
  if (arg_1 == DAT_00531594) goto LAB_005085a9;
  val_3 = Util_GetRandomNumber(3);
  if (((val_3 == 0) && (((&g_CardSlot_StatusFlags)[arg_1 * 100] & 1) == 0)) ||
     (*(int *)(&g_CardSlot_CreatureType + arg_1 * 100) != 1)) {
LAB_00507faa:
    local_44 = Util_GetRandomNumber(6);
    if (*(int *)(&g_TownBuildingCoordinates + local_44 * 0x14) < 1) {
      DAT_0061e100 = 0xffffffff;
    }
    else {
      DAT_0061e100 = arg_1;
      DAT_0061e05c = -*(int *)(&g_TownBuildingCoordinates + local_44 * 0x14);
    }
    val_3 = Util_GetRandomNumber(4);
    if ((val_3 == 0) || (DAT_0061e100 == 0xffffffff)) {
      DAT_0061e100 = arg_1;
      val_3 = Util_GetRandomNumber(8);
      val_3 = Glue_Subsystem_004ea97c(player_idx,val_3 * 2 + 4);
      DAT_0061e05c = -val_3;
      FUN_0046e70d(0,8);
      g_TownBuildingCoordinates = 0xffffffff;
    }
  }
  else {
    color_idx = 0;
    do {
      DAT_0061e100 = Util_GetRandomNumber(0x80);
      target_idx = FUN_0040a36f(*(int *)(&g_DungeonMapTileX + arg_1 * 100) -
                              *(int *)(&g_DungeonMapTileX + DAT_0061e100 * 100),
                              *(int *)(&g_DungeonMapTileY + arg_1 * 100) -
                              *(int *)(&g_DungeonMapTileY + DAT_0061e100 * 100));
      color_idx = color_idx + 1;
      if (999 < color_idx) break;
    } while (((*(int *)(&g_CardSlot_CreatureType + DAT_0061e100 * 100) < 2) ||
             (*(int *)(&g_CardSlot_CreatureType + DAT_0061e100 * 100) == 4)) ||
            ((*(int *)(&g_CardSlot_CreatureType + DAT_0061e100 * 100) == 5 ||
             (((target_idx < 8 ||
               (((int)(color_idx + (color_idx >> 0x1f & 0xfU)) >> 4) + 0x10 < target_idx)) ||
              ((*(uint32_t *)(&g_CardSlot_StatusFlags + DAT_0061e100 * 100) & 0xff01) != 0))))));
    val_3 = Util_GetRandomNumber(2);
    if (val_3 == 0) {
      DAT_0061e05c = 2;
    }
    else {
      DAT_0061e05c = 0;
    }
    if (999 < color_idx) {
      if (((&g_CardSlot_StatusFlags)[arg_1 * 100] & 1) == 0) goto LAB_00507faa;
      DAT_0061e100 = 0xffffffff;
    }
    val_3 = Util_GetRandomNumber(5);
    local_44 = val_3 + 1;
    val_3 = Pic_Subsystem_004521a6(1 << ((uint8_t)local_44 & 0x1f),1 << ((uint8_t)player_idx & 0x1f),3);
    if ((val_3 == 0) && (val_3 = Util_GetRandomNumber(2), val_3 != 0)) {
      DAT_0061e05c = 1;
      _DAT_0061e058 = local_44;
    }
  }
  if (DAT_0061e05c != 1) {
    uval_2 = Surface_GetPixelColor(*(int *)(&g_DungeonMapTileX + DAT_0061e100 * 100),
                         *(int *)(&g_DungeonMapTileY + DAT_0061e100 * 100));
    local_44 = Glue_Subsystem_004ea7a6(uval_2);
    do {
      val_3 = Util_GetRandomNumber(5);
      _DAT_0061e058 = val_3 + 1;
    } while ((local_44 & 1 << (DAT_0061e058 & 0x1f)) == 0);
  }
  if ((DAT_0061e05c == 0) && (*(int *)(&DAT_0067bdbc + _DAT_0061e058 * 4) == 0)) {
    DAT_0061e05c = 2;
  }
  if (((&g_CardSlot_StatusFlags)[arg_1 * 100] & 8) == 0) {
    for (local_3c = 0; (int)local_3c < 8; local_3c = local_3c + 1) {
      *(int32_t *)(&DAT_0061e060 + local_3c * 4) = 0xffffffff;
    }
  }
  else {
    for (local_3c = 0; (int)local_3c < loop_idx; local_3c = local_3c + 1) {
      if (DAT_00641020 - *(int *)(&DAT_0067be24 + local_3c * 4 + arg_1 * 100) <
          g_CampaignDifficultyLevel * 5 + 0xf) {
        *(int32_t *)(&DAT_0061e060 + local_3c * 4) = 0xffffffff;
      }
      else {
        *(int32_t *)(&DAT_0061e060 + local_3c * 4) =
             *(int32_t *)(&DAT_0067be04 + local_3c * 4 + arg_1 * 100);
      }
    }
  }
  local_44 = Util_GetRandomNumber(loop_idx);
  for (local_3c = 0; (int)local_3c < loop_idx; local_3c = local_3c + 1) {
    if ((*(int *)(&DAT_0061e060 + local_3c * 4) == -1) &&
       (g_CampaignDifficultyLevel * 5 + 0xf <=
        DAT_00641020 - *(int *)(&DAT_0067be24 + local_3c * 4 + arg_1 * 100))) {
      flag_1 = Util_GetRandomNumber(7);
      local_34 = 1 << (flag_1 & 0x1f);
      do {
        if (local_3c == local_44) {
          local_58 = Util_GetRandomNumber(5);
          *(uint32_t *)(&DAT_0061e060 + local_3c * 4) = local_58;
        }
        else {
          local_58 = Util_GetRandomNumber(g_MasterCardCount + -0x29);
          *(uint32_t *)(&DAT_0061e060 + local_3c * 4) = local_58;
        }
        local_4c = 0;
        for (local_48 = 1; (int)local_48 < 6; local_48 = local_48 + 1) {
          if (((local_50 & 1 << ((uint8_t)local_48 & 0x1f)) != 0) &&
             (val_3 = Pic_Subsystem_004521a6
                                (1 << ((uint8_t)local_48 & 0x1f),
                                 (int)(char)(&g_MasterCardColorTable)[local_58 * 0x34],
                                 (-(uint32_t)((local_48 & 1) == 0) & 2) + 1), val_3 != 0)) {
            local_4c = 1;
          }
        }
        if (((local_3c & 1) != 0) && (((&g_MasterCardColorTable)[local_58 * 0x34] & 0x40) != 0)) {
          local_4c = 0;
        }
        if (((&g_MasterCardFlagsTable)[local_58 * 0x34] & 9) != 0) {
          local_4c = 0;
        }
        if (((&DAT_0051aed6)[local_58 * 0x34] & 0xc1) == 0) {
          local_4c = 0;
        }
        val_3 = File_Load_Info(local_58);
        if ((int)local_3c % 3 + 1 < val_3) {
          local_4c = 0;
        }
        val_3 = Glue_Subsystem_004f0b50(local_58);
      } while (((val_3 < 1) || (local_4c == 0)) ||
              ((*(uint32_t *)(&g_MasterCardSubtypeTable + local_58 * 0x34) & 0x180) != 0));
    }
  }
  local_a4 = 0;
  for (local_3c = 0; (int)local_3c < loop_idx; local_3c = local_3c + 1) {
    local_24 = FUN_00407499(*(int *)(&DAT_0061e060 + local_3c * 4));
    if (local_24 != -1) {
      aiStack_a0[local_a4 * 2] = local_24;
      aiStack_a0[local_a4 * 2 + 1] = local_3c;
      local_a4 = local_a4 + 1;
    }
  }
  if (local_a4 != 0) {
    val_3 = Util_GetRandomNumber(local_a4);
    DAT_006265f8 = aiStack_a0[val_3 * 2];
    DAT_00626808 = aiStack_a0[val_3 * 2];
  }
  for (local_3c = 0; (int)local_3c < 8; local_3c = local_3c + 1) {
    local_58 = *(uint32_t *)(&DAT_0061e060 + local_3c * 4);
    if (local_58 != 0xffffffff) {
      local_30 = FUN_0050a9bf(local_58);
      local_30 = (*(int *)(&g_CardSlot_CreatureType + arg_1 * 100) + 2) * local_30;
      if (((local_50 & (int)(char)(&g_MasterCardColorTable)[local_58 * 0x34]) == 0) &&
         ((&g_MasterCardColorTable)[local_58 * 0x34] != '\0')) {
        val_3 = Pic_Subsystem_004521a6(local_50,(int)(char)(&g_MasterCardColorTable)[local_58 * 0x34],3);
        if (val_3 == 0) {
          local_30 = local_30 << 1;
        }
        else {
          local_30 = (local_30 * 3) / 2;
        }
      }
      uval_2 = Math_Clamp((local_30 / 0x32) * 5,5,1000);
      *(int32_t *)(&DAT_0061e0a0 + local_3c * 4) = uval_2;
    }
  }
  *(uint32_t *)(&g_CardSlot_StatusFlags + arg_1 * 100) = *(uint32_t *)(&g_CardSlot_StatusFlags + arg_1 * 100) | 8;
LAB_005085a9:
  DAT_006265f4 = *(int *)(&g_CardSlot_CreatureType + arg_1 * 100) * 5 + 10;
  slot_idx = DAT_006265f4;
  Pic_Subsystem_00423b93(0x12);
  Glue_Subsystem_004ec5be(s_x_sound_button_wav_00531f44,0x12,0);
  do {
    if (loop_idx == 0) {
      val_3 = Rules_CalculateManaCostReduction((uint8_t)local_50);
      *(int *)(&DAT_0061e060 + loop_idx * 4) = val_3 + -1;
      *(int32_t *)(&DAT_0061e0a0 + loop_idx * 4) = 0x28;
      loop_idx = loop_idx + 1;
    }
    *(int32_t *)(g_DisplaySurfaceScreen + 0x20) = 4;
    g_OverworldWorldState = 0;
    Ai_TownEncounter_004c3b19(arg_1);
    FUN_0040c336(&g_OverworldWorldState,0xa0,0x1c,
                 (-(uint32_t)(*(int *)(&g_CardSlot_CreatureType + arg_1 * 100) == 1) & 0x1e) + 0xe0);
    *(int32_t *)(g_DisplaySurfaceScreen + 0x20) = 1;
    for (local_3c = 0; (int)local_3c < 4; local_3c = local_3c + 1) {
      *(int32_t *)(&DAT_005315dc + local_3c * 0x54) =
           *(int32_t *)(&DAT_0067f730 + local_3c * 4);
      *(int32_t *)(&DAT_005315e0 + local_3c * 0x54) =
           *(int32_t *)(&DAT_0067f740 + local_3c * 4);
      *(int32_t *)(&DAT_005315e4 + local_3c * 0x54) =
           *(int32_t *)(&DAT_0067f740 + local_3c * 4);
      *(int32_t *)(&DAT_005315e8 + local_3c * 0x54) =
           *(int32_t *)(&DAT_0067f730 + local_3c * 4);
    }
    if (DAT_005316f8 == DAT_005316e8) {
      for (local_3c = 0; (int)local_3c < 4; local_3c = local_3c + 1) {
        uval_2 = Ai_Util_004c3bc4(*(int *)(&DAT_00531598 + local_3c * 0x54));
        *(int32_t *)(&DAT_005315a8 + local_3c * 0x54) = uval_2;
        uval_2 = Ai_Util_004c3bc4(*(int *)(&DAT_0053159c + local_3c * 0x54));
        *(int32_t *)(&DAT_005315ac + local_3c * 0x54) = uval_2;
        uval_2 = Ai_Util_004c3bc4(*(int *)(&DAT_005315a0 + local_3c * 0x54));
        *(int32_t *)(&DAT_005315b0 + local_3c * 0x54) = uval_2;
        uval_2 = Ai_Util_004c3bc4(*(int *)(&DAT_005315a4 + local_3c * 0x54));
        *(int32_t *)(&DAT_005315b4 + local_3c * 0x54) = uval_2;
      }
      for (local_3c = 0; (int)local_3c < 5; local_3c = local_3c + 1) {
        val_3 = Ai_Util_004c3bc4((&DAT_005316e8)[local_3c * 0x15]);
        (&DAT_005316f8)[local_3c * 0x15] = val_3;
        uval_2 = Ai_Util_004c3bc4(*(int *)(&DAT_005316ec + local_3c * 0x54));
        *(int32_t *)(&DAT_005316fc + local_3c * 0x54) = uval_2;
        uval_2 = Ai_Util_004c3bc4(*(int *)(&DAT_005316f0 + local_3c * 0x54));
        *(int32_t *)(&DAT_00531700 + local_3c * 0x54) = uval_2;
        uval_2 = Ai_Util_004c3bc4(*(int *)(&DAT_005316f4 + local_3c * 0x54));
        *(int32_t *)(&DAT_00531704 + local_3c * 0x54) = uval_2;
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
    match_count = 0;
    PTR_Town_Process_00508cd7_00531860 = Town_Process_00508cd7;
    if (*(int *)(&g_CardSlot_CreatureType + arg_1 * 100) == 1) {
      if (((g_AiManaColorCost_White == -1) && (DAT_0061e100 != 0xffffffff)) &&
         ((g_CampaignDifficultyLevel + 3) * 0x10 < DAT_00641020 - *(int *)(&DAT_0067be44 + arg_1 * 100))) {
        sprintf(&DAT_006267a0,s_Begin_a_Quest_00531ff8);
      }
      else {
        sprintf(&DAT_006267a0,s_Speak_to_Wise_Man_00532008);
      }
    }
    else if ((((player_idx == 0xffffffff) || (*(int *)(&DAT_0067bdbc + player_idx * 4) == 0)) ||
             (*(int *)(&DAT_0067bdfc + arg_1 * 100) == 0)) ||
            (DAT_00641020 - *(int *)(&DAT_0067be48 + arg_1 * 100) <= (g_CampaignDifficultyLevel * 2 + 6) * 9)) {
      if (((g_AiManaColorCost_White == -1) && (DAT_0061e100 != 0xffffffff)) &&
         ((g_CampaignDifficultyLevel + 3) * 0x10 < DAT_00641020 - *(int *)(&DAT_0067be44 + arg_1 * 100))) {
        sprintf(&DAT_006267a0,s_Begin_a_Quest_00531fd4);
        match_count = 1;
      }
      else {
        sprintf(&DAT_006267a0,s_Speak_to_Wise_Man_00531fe4);
      }
    }
    else {
      g_OverworldWorldState = 0;
      uval_2 = FUN_0050a73e(arg_1);
      uval_4 = Mem_AllocOrFree_00473d7e(player_idx);
      sprintf(&DAT_006267a0,s_Trade__s_Amulets_for__s__00531fb8,uval_4,uval_2);
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
      FUN_0041f3ea(g_MouseScreenCoordX,g_MouseScreenCoordY,g_MouseCursorButtonState);
    }
    FUN_0041f391();
  } while (DAT_006265fc == -2);
  for (local_3c = 0; (int)local_3c < 8; local_3c = local_3c + 1) {
    *(int32_t *)(&DAT_0067be04 + local_3c * 4 + arg_1 * 100) =
         *(int32_t *)(&DAT_0061e060 + local_3c * 4);
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
  *(int32_t *)g_DisplaySurfaceScreen = 1;
  FUN_0040a883(s_village_pic_0053201c +
               ((*(int *)(&g_CardSlot_CreatureType + DAT_0061e0d4 * 100) == 1) - 1 & 0xc));
  *(int32_t *)g_DisplaySurfaceScreen = 0;
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
  uint8_t *u_ptr_1;
  int player_id;
  int val_2;
  int val_3;
  char *pcVar4;
  bool bVar5;
  uint32_t target_idx;
  int slot_idx;
  
  arg_1 = DAT_0062680c;
  u_ptr_1 = PTR_FUN_00527b3c;
  if (((&g_CardSlot_StatusFlags)[DAT_0062680c * 100] & 4) == 0) {
    if (((g_AiManaColorCost_White == 0xffffffff) && (DAT_0061e100 != 0xffffffff)) &&
       ((g_CampaignDifficultyLevel + 3) * 0x10 < DAT_00641020 - *(int *)(&DAT_0067be44 + DAT_0062680c * 100))) {
      FUN_0040a95d(s_wiseman3_pic_005320c0);
      g_AiManaColorCost_White = DAT_0061e100;
      DAT_0067b9a0 = _DAT_0061e058;
      g_AiHandEvaluationBuffer = DAT_0061e05c;
      if ((DAT_0061e05c == 0) || (DAT_0061e05c == 2)) {
        strcpy(&g_OverworldWorldState,s_Take_this_message_005320d0);
        g_CampaignCompassHeading = FUN_0050aef6(*(int *)(&g_DungeonMapTileX + g_AiManaColorCost_White * 100),
                                    *(int *)(&g_DungeonMapTileY + g_AiManaColorCost_White * 100));
        FUN_0040c81c(0x80,*(int *)(&g_DungeonMapTileX + g_AiManaColorCost_White * 100),
                     *(int *)(&g_DungeonMapTileY + g_AiManaColorCost_White * 100));
        strcat(&g_OverworldWorldState,s_to_my_brother__the_keeper_of_005320e4);
        Ai_TownEncounter_004c3b19(g_AiManaColorCost_White);
        strcat(&g_OverworldWorldState,s___He_will_reward_you_with_00532104);
        bVar5 = g_AiHandEvaluationBuffer != 0;
        if (!bVar5) {
          strcat(&g_OverworldWorldState,s_a_mana_link__00532120);
        }
        target_idx = (uint32_t)bVar5;
        slot_idx = 0x20;
      }
      if (g_AiHandEvaluationBuffer == 1) {
        strcpy(&g_OverworldWorldState,s_Take_a_00532130);
        FUN_0050b1a0();
        strcat(&g_OverworldWorldState,&DAT_00532138);
        FUN_0050aef6(*(int *)(&g_DungeonMapTileX + g_AiManaColorCost_White * 100),
                     *(int *)(&g_DungeonMapTileY + g_AiManaColorCost_White * 100));
        FUN_0040c81c(0x80,*(int *)(&g_DungeonMapTileX + g_AiManaColorCost_White * 100),
                     *(int *)(&g_DungeonMapTileY + g_AiManaColorCost_White * 100));
        strcat(&g_OverworldWorldState,s_to_the_keeper_of_0053213c);
        Ai_TownEncounter_004c3b19(g_AiManaColorCost_White);
        strcat(&g_OverworldWorldState,s___He_will_give_you_a_mana_link_a_00532150);
        target_idx = 1;
        pcVar4 = _itoa(1,&DAT_0061e0f0,10);
        strcat(&g_OverworldWorldState,pcVar4);
        strcat(&g_OverworldWorldState,&DAT_00532174);
        slot_idx = 0x28;
      }
      if (g_AiHandEvaluationBuffer < 0) {
        target_idx = (int)(char)(&DAT_00522628)[g_AiHandEvaluationBuffer * -0x44] / 7 + 1;
        strcpy(&g_OverworldWorldState,s_Defeat_the_00532178);
        Glue_Subsystem_004eaa19(-g_AiHandEvaluationBuffer,0,0);
        if ((&DAT_00522628)[g_AiHandEvaluationBuffer * -0x44] == '\x12') {
          strcat(&g_OverworldWorldState,s_Dragon_00532184);
        }
        strcat(&g_OverworldWorldState,s_which_has_been_menacing_our_vill_0053218c);
        if (*(int *)(&g_CardSlot_CreatureType + arg_1 * 100) == 1) {
          pcVar4 = _itoa(target_idx,&DAT_0061e0f0,10);
          strcat(&g_OverworldWorldState,pcVar4);
          strcat(&g_OverworldWorldState,&DAT_005321dc);
        }
        else {
          FUN_0050a73e(arg_1);
          strcat(&g_OverworldWorldState,&DAT_005321e0);
          target_idx = 0;
        }
        slot_idx = 0x18;
      }
      if (target_idx != 0) {
        pcVar4 = (char *)Mem_AllocOrFree_00473d7e(DAT_0067b9a0);
        strcat(&g_OverworldWorldState,pcVar4);
        strcat(&g_OverworldWorldState,s_amulet__005321e4 + ((target_idx == 1) - 1 & 0xc));
      }
      strcat(&g_OverworldWorldState,s_Accept_the_Quest_Never_mind__005321fc);
      PTR_FUN_00527b3c = Mem_AllocOrFree_0040eea2;
      val_2 = FUN_004896be(&g_OverworldWorldState,0x2d,0x24);
      if (val_2 == 0) {
        FUN_0040a883(s_wiseman3_pic_00532220);
        DAT_0067f370 = arg_1;
        DAT_0067bddc = slot_idx * 2 + DAT_00641020 + -1;
        *(int *)(&DAT_0067be44 + arg_1 * 100) = DAT_00641020;
        strcpy(&g_OverworldWorldState,s_You_have_00532230);
        pcVar4 = _itoa((int)(slot_idx + (slot_idx >> 0x1f & 7U)) >> 3,&DAT_0061e0f0,10);
        strcat(&g_OverworldWorldState,pcVar4);
        strcat(&g_OverworldWorldState,s_days_to_complete_the_quest__0053223c);
        FUN_004896be(&g_OverworldWorldState,0x48,0x48);
        FUN_0040c81c(0x80,*(int *)(&g_DungeonMapTileX + arg_1 * 100),
                     *(int *)(&g_DungeonMapTileY + arg_1 * 100));
        FUN_0040b3c2(0xf,g_AiHandEvaluationBuffer);
        PTR_FUN_00527b3c = u_ptr_1;
      }
      else {
        g_AiManaColorCost_White = 0xffffffff;
        g_AiHandEvaluationBuffer = 0;
        PTR_FUN_00527b3c = u_ptr_1;
      }
    }
    else {
      Dungeon_Process_0040fcfd(DAT_00626604,(uint32_t)(DAT_0062680c != DAT_00531594),DAT_0062680c);
    }
    DAT_00531594 = arg_1;
    Ai_Subsystem_004c3c5c(1);
    FUN_0040a95d(s_village_pic_0053225c + ((*(int *)(&g_CardSlot_CreatureType + arg_1 * 100) == 1) - 1 & 0xc));
  }
  else {
    FUN_0040a95d(s_wiseman3_pic_00532034);
    strcpy(&g_OverworldWorldState,s_You_failed_to_complete_your_last_00532044);
    strcat(&g_OverworldWorldState,s_The_people_have_no_new_quest_for_00532080);
    *(int32_t *)(g_DisplaySurfaceScreen + 0x20) = 1;
    val_2 = Ai_Util_004c3bc4(0x13c);
    val_3 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
    val_2 = val_2 + val_3 * -4;
    val_3 = Ai_Util_004c3bc4(0x50);
    FUN_0040d1cd((int)g_DisplaySurfaceScreen,0xc1,val_3,val_2);
    App_ProcessPendingMessages();
    Ai_Subsystem_004cd1d1();
    FUN_0040a95d(s_village_pic_005320a8 + ((*(int *)(&g_CardSlot_CreatureType + arg_1 * 100) == 1) - 1 & 0xc));
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
  int32_t arg_1;
  int val_1;
  int val_2;
  int val_3;
  int val_4;
  char *pcVar5;
  void *arg_6;
  int local_100;
  void *local_fc;
  int local_f8;
  int32_t local_f4;
  int32_t auStack_f0 [6];
  int32_t auStack_d8 [4];
  int local_c8;
  int local_c4;
  int local_c0;
  int32_t local_bc;
  int local_b8;
  int local_b4;
  int local_b0;
  int local_ac;
  int local_a8;
  int local_a4 [40];
  
  local_a8 = DAT_0062680c;
  local_ac = 0;
  App_ProcessPendingMessages();
  arg_1 = Surface_GetPixelColor(*(int *)(&g_DungeonMapTileX + local_a8 * 100),
                       *(int *)(&g_DungeonMapTileY + local_a8 * 100));
  local_bc = Glue_Subsystem_004ea7a6(arg_1);
  local_ac = *(int *)(&g_CardSlot_CreatureType + local_a8 * 100) + 3;
  if (DAT_005224f8 == 0) {
    local_ac = *(int *)(&g_CardSlot_CreatureType + local_a8 * 100) + 4;
  }
  if (local_ac == 0) {
    val_1 = Rules_CalculateManaCostReduction((uint8_t)local_bc);
    *(int *)(&DAT_0061e060 + local_ac * 4) = val_1 + -1;
    *(int32_t *)(&DAT_0061e0a0 + local_ac * 4) = 0x28;
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
    *(int32_t *)(&DAT_0061e0c8 + local_100 * 4) = auStack_f0[local_100 + 3];
  }
  for (local_100 = 0; local_100 < 3; local_100 = local_100 + 1) {
    *(int32_t *)(&DAT_0061e0e0 + local_100 * 4) = auStack_f0[local_100 + 6];
  }
  FileIO_OpenFileStream(1,0,g_AiManaColorCost_Green + -0x118,s_buycards_pic_00532284,(short *)0x0);
  val_1 = Ai_Util_004c3ba3(0x8c);
  val_2 = Ai_Util_004c3ba3(0x100);
  val_3 = Ai_Util_004c3ba3(0x18);
  val_4 = Ai_Util_004c3ba3(0x20);
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,g_AiManaColorCost_Green + -0x118,0x200,0x118,
                     (int *)g_DisplaySurfaceScreen,val_4,val_3,val_2,val_1);
  val_1 = Ai_Util_004c3ba3(0x8c);
  val_2 = Ai_Util_004c3ba3(0x100);
  val_3 = Ai_Util_004c3ba3(0x18);
  val_4 = Ai_Util_004c3ba3(0x20);
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,g_AiManaColorCost_Green + -0x118,0x200,0x118,
                     (int *)g_DisplaySurfaceBackBuffer,val_4,val_3,val_2,val_1);
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
  val_1 = Ai_Util_004c3ba3(0x8c);
  val_2 = Ai_Util_004c3ba3(0x100);
  val_3 = Ai_Util_004c3ba3(0x18);
  val_4 = Ai_Util_004c3ba3(0x20);
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x200,0x118,(int *)g_DisplaySurfaceScreen
                     ,val_4,val_3,val_2,val_1);
  FUN_0050b9d5(g_DisplaySurfaceScreen);
  FUN_0041f213();
  FUN_0041f3ea(g_MouseScreenCoordX,g_MouseScreenCoordY,g_MouseCursorButtonState);
  *(int32_t *)(g_DisplaySurfaceScreen + 0x20) = 4;
  val_1 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
  val_2 = FUN_0040c465(s_Cards_for_Sale_005322a4);
  Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,(g_AiManaColorCost_Red / 2 - val_2 / 2) + -0x14,
                    (g_AiManaColorCost_Green * 0x1f) / 0xf0 - val_1,val_2 + 0x28,val_1 * 3,DAT_0061e114);
  FUN_0040c336(s_Cards_for_Sale_005322b4,0xa0,0x1f,0x1b);
  local_b0 = 0x40;
  local_c4 = (int)(0xf4 / (longlong)local_ac);
  memset(local_a4,0xff,0xa0);
  local_b4 = local_ac;
  while (local_b4 = local_b4 + -1, -1 < local_b4) {
    if (*(int *)(&DAT_0061e060 + local_b4 * 4) != -1) {
      FUN_0040c6c7(g_DisplaySurfaceScreen,local_c4 * local_b4 + 0x2c,
                   (*(uint32_t *)(&DAT_0061e060 + local_b4 * 4) & 7) + local_b0 + -0xc,local_c4 + -4,0xc
                   ,DAT_0061e0c0);
      g_OverworldWorldState = 0;
      pcVar5 = _itoa(*(int *)(&DAT_0061e0a0 + local_b4 * 4),&DAT_0061e0f0,10);
      strcat(&g_OverworldWorldState,pcVar5);
      strcat(&g_OverworldWorldState,s_gold_005322c4);
      *(int32_t *)(g_DisplaySurfaceScreen + 0x20) = 1;
      FUN_0040c336(&g_OverworldWorldState,local_c4 * local_b4 + local_c4 / 2 + 0x29,
                   (*(uint32_t *)(&DAT_0061e060 + local_b4 * 4) & 7) + local_b0 + -8,0x1b);
      pcVar5 = &DAT_005322cc;
      val_3 = 0;
      val_1 = (*(uint32_t *)(&DAT_0061e060 + local_b4 * 4) & 7) + local_b0 + 4;
      val_2 = Math_Clamp(local_c4 * local_b4 + local_c4 / 2 + 0x12,0,g_AiManaColorCost_Red + -0x62);
      FUN_0050b206(*(int *)(&DAT_0061e060 + local_b4 * 4),val_2,val_1,val_3,pcVar5);
      val_1 = Math_Clamp(local_c4 * local_b4 + local_c4 / 2 + 0x12,0,g_AiManaColorCost_Red + -0x62);
      val_1 = Ai_Util_004c3ba3(val_1);
      local_a4[local_b4 * 4] = val_1;
      val_1 = Ai_Util_004c3ba3((*(uint32_t *)(&DAT_0061e060 + local_b4 * 4) & 7) + local_b0 + 4);
      local_a4[local_b4 * 4 + 1] = val_1;
      val_1 = local_a4[local_b4 * 4];
      val_2 = Ai_Util_004c3ba3(0x30);
      local_a4[local_b4 * 4 + 2] = val_1 + val_2;
      val_1 = local_a4[local_b4 * 4 + 1];
      val_2 = Ai_Util_004c3ba3(0x30);
      local_a4[local_b4 * 4 + 3] = val_1 + val_2;
    }
  }
  DAT_00626600 = 0;
  do {
    while( true ) {
      if (DAT_00626600 != 0) {
        FUN_0041f391();
        Overworld_LoadAdventureInterface800();
        Ai_Subsystem_004c3c5c(1);
        FUN_0040a95d(s_village_pic_005322f0 +
                     ((*(int *)(&g_CardSlot_CreatureType + local_a8 * 100) == 1) - 1 & 0xc));
        DAT_006265fc = 0xfffffffe;
        Mem_AllocOrFree_0050fc50(DAT_0061e0d8);
        return;
      }
      local_c0 = -1;
      Pic_Subsystem_0044b84b();
      if (g_MouseCursorButtonState != 0) break;
      FUN_0041f3ea(g_MouseScreenCoordX,g_MouseScreenCoordY,0);
    }
    for (local_b4 = 0; local_b4 < local_ac; local_b4 = local_b4 + 1) {
      if ((((local_a4[local_b4 * 4] <= g_MouseScreenCoordX) && (g_MouseScreenCoordX <= local_a4[local_b4 * 4 + 2])
           ) && (local_a4[local_b4 * 4 + 1] <= g_MouseScreenCoordY)) &&
         (g_MouseScreenCoordY <= local_a4[local_b4 * 4 + 3])) {
        local_c0 = local_b4;
        break;
      }
    }
    if (local_c0 != -1) break;
    FUN_0041f3ea(g_MouseScreenCoordX,g_MouseScreenCoordY,g_MouseCursorButtonState);
  } while( true );
  sprintf(&g_OverworldWorldState,s_Buy_for__d_gold___Y_N__005322d0,
          *(int32_t *)(&DAT_0061e0a0 + local_b4 * 4));
  arg_6 = DAT_0061e0d8;
  val_1 = Ai_Util_004c3ba3(0x10f);
  val_1 = val_1 / 2;
  val_2 = Ai_Util_004c3ba3(0xc5);
  val_2 = val_2 / 2;
  val_3 = Ai_Util_004c3ba3(0x34);
  val_3 = val_3 / 2;
  val_4 = Ai_Util_004c3ba3(0xdc);
  Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,val_4 / 2,val_3,val_2,val_1,(int)arg_6);
  FUN_0050b3de(*(int *)(&DAT_0061e060 + local_b4 * 4),0x7a,0x29,0x4b,0x70,1,&DAT_005322ec);
  FUN_0040d339((int)g_DisplaySurfaceScreen,0x1b,0x140,0x47);
  App_ProcessPendingMessages();
  local_b8 = FUN_0048ac2f();
  if (((local_b8 == 0x79) || (local_b8 == 0x59)) && (*(int *)(&DAT_0061e0a0 + local_b4 * 4) <= Gold)
     ) {
    Gold = Gold - *(int *)(&DAT_0061e0a0 + local_b4 * 4);
    val_1 = Pic_Subsystem_00451e40(*(uint32_t *)(&DAT_0061e060 + local_b4 * 4));
    *(uint32_t *)(&deck + val_1 * 4) = *(uint32_t *)(&deck + val_1 * 4) | 0x4000;
    *(int32_t *)(&DAT_0061e060 + local_b4 * 4) = 0xffffffff;
    *(int32_t *)(&DAT_0061e0a0 + local_b4 * 4) = 0;
    if (DAT_00626808 == local_b4) {
      DAT_006265f8 = -1;
    }
    val_1 = Util_GetRandomNumber(5);
    *(int *)(&DAT_0067be24 + local_b4 * 4 + local_a8 * 100) =
         val_1 * (g_CampaignDifficultyLevel + 2) + DAT_00641020;
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
  int val_1;
  
  val_1 = DAT_0062680c;
  Bazaar_TradeCardDialogue(DAT_00626604,DAT_0062680c);
  *(int32_t *)(&DAT_0067be48 + val_1 * 100) = DAT_00641020;
  Overworld_LoadAdventureInterface800();
  FUN_0040a566();
  Ai_Subsystem_004c3c5c(1);
  FUN_0040a95d(s_village_pic_00532308 + ((*(int *)(&g_CardSlot_CreatureType + val_1 * 100) == 1) - 1 & 0xc));
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
  int val_1;
  
  val_1 = DAT_0062680c;
  Glue_Subsystem_004ebcdc(s_x_sound_button2_wav_00532320,0xf,100,100,0);
  Surface_TransformPoint(0,(short)g_MidiMusicTrackId);
  DeckBuilderMain(_hwndScreen,1,3);
  Pic_Load_advfac64_0040a4fc();
  Overworld_LoadAdventureInterface800();
  Ai_Subsystem_004c3c5c(1);
  FUN_0040a95d(s_village_pic_00532334 + ((*(int *)(&g_CardSlot_CreatureType + val_1 * 100) == 1) - 1 & 0xc));
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
  int val_1;
  
  val_1 = DAT_0062680c;
  Glue_Subsystem_004ebcdc(s_x_sound_button2_wav_0053234c,0xf,100,100,0);
  Ai_CastleEncounter_004c24b3(0);
  Overworld_LoadAdventureInterface800();
  Ai_Subsystem_004c3c5c(1);
  FUN_0040a95d(s_village_pic_00532360 + ((*(int *)(&g_CardSlot_CreatureType + val_1 * 100) == 1) - 1 & 0xc));
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
  int val_1;
  
  val_1 = DAT_0062680c;
  Glue_Subsystem_004ebcdc(s_x_sound_button2_wav_00532378,0xf,100,100,0);
  Castle_Process_0048f523(1);
  Overworld_LoadAdventureInterface800();
  Ai_Subsystem_004c3c5c(1);
  FUN_0040a95d(s_village_pic_0053238c + ((*(int *)(&g_CardSlot_CreatureType + val_1 * 100) == 1) - 1 & 0xc));
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
  int val_1;
  
  val_1 = DAT_0062680c;
  Town_Process_00490d7b(1);
  Overworld_LoadAdventureInterface800();
  Ai_Subsystem_004c3c5c(1);
  FUN_0040a95d(s_village_pic_005323a4 + ((*(int *)(&g_CardSlot_CreatureType + val_1 * 100) == 1) - 1 & 0xc));
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
  int val_1;
  
  val_1 = DAT_0062680c;
  Glue_Subsystem_004ebcdc(s_x_sound_button2_wav_005323bc,0xf,100,100,0);
  App_ProcessPendingMessages();
  Castle_Process_00421b32();
  Overworld_LoadAdventureInterface800();
  Ai_Subsystem_004c3c5c(1);
  FUN_0040a95d(s_village_pic_005323d0 + ((*(int *)(&g_CardSlot_CreatureType + val_1 * 100) == 1) - 1 & 0xc));
  DAT_006265fc = 0xfffffffe;
  return;
}

/*
 * Decompiled function: SellPrice
 * Entry Point: 0050a8ae
 * Size: 273 bytes
 */


int SellPrice(int player_id)

{
  int32_t arg_1_00;
  int val_1;
  int slot_idx;
  
                    /* 0x10a8ae  7  SellPrice */
  arg_1_00 = Surface_GetPixelColor(*(int *)(&g_DungeonMapTileX + DAT_0061e0fc * 100),
                          *(int *)(&g_DungeonMapTileY + DAT_0061e0fc * 100));
  val_1 = Glue_Subsystem_004ea7a6(arg_1_00);
  slot_idx = FUN_0050a9bf(arg_1);
  slot_idx = (*(int *)(&g_CardSlot_CreatureType + DAT_0061e0fc * 100) + 2) * slot_idx;
  if (((char)(&g_MasterCardColorTable)[arg_1 * 0x34] != val_1) && ((&g_MasterCardColorTable)[arg_1 * 0x34] != '\0')) {
    val_1 = Pic_Subsystem_004521a6(val_1,(int)(char)(&g_MasterCardColorTable)[arg_1 * 0x34],3);
    if (val_1 == 0) {
      slot_idx = (slot_idx * 3) / 2;
    }
    else {
      slot_idx = (slot_idx * 4) / 3;
    }
  }
  return (slot_idx / 0x32) * 5;
}

