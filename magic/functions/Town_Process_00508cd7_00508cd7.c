/*
 * Decompiled function: Town_Process_00508cd7
 * Entry Point: 00508cd7
 * Size: 1671 bytes
 */
#include "magic.h"


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
        Adventure_FormatNewsString(-DAT_0067f2c0,0,0);
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
    FUN_0040a3e1();
    Ai_Subsystem_004cd1d1();
    FUN_0040a95d(s_village_pic_005320a8 + ((*(int *)(&DAT_0067bdf0 + arg_1 * 100) == 1) - 1 & 0xc));
  }
  DAT_006265fc = 0xfffffffe;
  return;
}


