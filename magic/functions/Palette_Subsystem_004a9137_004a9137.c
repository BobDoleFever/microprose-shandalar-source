/*
 * Decompiled function: Palette_Subsystem_004a9137
 * Entry Point: 004a9137
 * Size: 2076 bytes
 */
#include "magic.h"


undefined4 Palette_Subsystem_004a9137(int arg_1,int arg_2,undefined4 arg_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_14;
  
  iVar3 = *(int *)(&g_CardSlot_CombatTarget + arg_2 * 0x120 + arg_1 * 0x5b20);
  iVar4 = *(int *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20);
  switch(arg_3) {
  case 0:
    Ai_Subsystem_004cc56d
              (arg_1,arg_1,arg_2,iVar3,iVar4,s_activates_Time_Elemental_effect__0052cbe8,0);
    FUN_0041da41(iVar3,iVar4);
    break;
  case 1:
    iVar2 = FUN_0040a1d2(2);
    strcpy(&g_OverworldWorldState,s_casts_Twiddle_to_0052cc0c);
    if (iVar2 == 0) {
      strcat(&g_OverworldWorldState,&DAT_0052cc28);
    }
    else {
      strcat(&g_OverworldWorldState,s_untap__0052cc20);
    }
    Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,iVar3,iVar4,&g_OverworldWorldState,0);
    if (iVar2 == 0) {
      if (((&g_CardSlot_Flags)[iVar3 * 0x5b20 + iVar4 * 0x120] & 0x10) == 0) {
        *(uint *)(&g_CardSlot_Flags + iVar3 * 0x5b20 + iVar4 * 0x120) =
             *(uint *)(&g_CardSlot_Flags + iVar3 * 0x5b20 + iVar4 * 0x120) | 0x10;
        if (((&g_MasterCardColorTable)
             [*(int *)(&g_CardSlot_CardId + iVar3 * 0x5b20 + iVar4 * 0x120) * 0x34] & 1) != 0) {
          DAT_006ff2d4 = 0xffffffff;
        }
        FUN_00473e69(iVar3,iVar4,0x81);
      }
    }
    else {
      *(uint *)(&g_CardSlot_Flags + iVar3 * 0x5b20 + iVar4 * 0x120) =
           *(uint *)(&g_CardSlot_Flags + iVar3 * 0x5b20 + iVar4 * 0x120) & 0xffffffef;
    }
    break;
  case 2:
    Ai_Subsystem_004cc56d
              (arg_1,arg_1,arg_2,iVar3,iVar4,s_activates_Aladdin_s_Ring_effect__0052cc30,0);
    Card_DirectDamage_PromptAndDealDamage(arg_1,arg_2,0x71,4);
    break;
  case 3:
    Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,iVar3,iVar4,s_casts_Ancestral_Recall__0052cc54,0);
    FUN_0046f5d1(iVar3);
    FUN_0046f5d1(iVar3);
    FUN_0046f5d1(iVar3);
    break;
  case 4:
    Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,-1,-1,s_activates_Pandora_s_Box_effect__0052cd80,0);
    Minit_Subsystem_0046758c();
    break;
  case 5:
    Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,iVar3,iVar4,s_casts_Crumble__0052cc70,0);
    cVar1 = (&DAT_0051aebf)[*(int *)(&g_CardSlot_CardId + iVar3 * 0x5b20 + iVar4 * 0x120) * 0x34];
    iVar2 = FUN_0040a305((int)(char)(&DAT_0051aec0)
                                    [*(int *)(&g_CardSlot_CardId + iVar3 * 0x5b20 + iVar4 * 0x120) *
                                     0x34],0,99);
    (&g_PlayerCreatureCount)[iVar3] = (&g_PlayerCreatureCount)[iVar3] + cVar1 + iVar2;
    Pic_Subsystem_0044867e(iVar3,iVar4,2);
    break;
  case 6:
    Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,-1,-1,s_activates_Bottle_of_Suleiman_eff_0052cd20,0);
    iVar3 = Ai_Subsystem_004cc56d
                      (arg_1,arg_1,arg_2,-1,-1,s_Call_the_coin_flip__Heads_Tails_0052cd48,1);
    iVar4 = Ai_Subsystem_004b7d38(s_Bottle_of_Suleiman_0052cd6c);
    if (iVar4 == iVar3) {
      iVar3 = Pic_Subsystem_0045268f(0x37a);
      iVar3 = Pic_Subsystem_00451291(arg_1,iVar3);
      if (iVar3 != -1) {
        Pic_Subsystem_0042ac1f(arg_1,iVar3);
        *(uint *)(&g_CardSlot_Abilities1 + arg_1 * 0x5b20 + iVar3 * 0x120) =
             *(uint *)(&g_CardSlot_Abilities1 + arg_1 * 0x5b20 + iVar3 * 0x120) | 0x10;
      }
    }
    else {
      Mem_AllocOrFree_0041df33(arg_1,5,arg_1,arg_2);
    }
    break;
  case 7:
    Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,iVar3,iVar4,s_casts_Disenchant__0052cc80,0);
    Pic_Subsystem_0044867e(iVar3,iVar4,1);
    break;
  case 8:
    Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,iVar3,iVar4,s_casts_Healing_Salve__0052cc94,0);
    (&g_PlayerCreatureCount)[iVar3] = (&g_PlayerCreatureCount)[iVar3] + 3;
    break;
  case 9:
    Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,iVar3,iVar4,s_casts_Fissure__0052ccac,0);
    Pic_Subsystem_0044867e(iVar3,iVar4,1);
    break;
  case 10:
    Ai_Subsystem_004cc56d
              (arg_1,arg_1,arg_2,iVar3,iVar4,s_activates_Disrupting_Sceptre_eff_0052cda4,0);
    Prompts_Load_0046fa40(iVar3,0,0);
    break;
  case 0xb:
    Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,iVar3,iVar4,s_activates_Millstone_effect__0052ccbc,0);
    for (local_14 = 0; local_14 < 2; local_14 = local_14 + 1) {
      iVar4 = *(int *)(&DAT_0069e730 + iVar3 * 2000);
      if (iVar4 != -1) {
        Pic_Subsystem_004523fd(iVar3,0);
        iVar4 = Pic_Subsystem_00451291(iVar3,iVar4);
        if (iVar4 != -1) {
          Pic_Subsystem_0044913a(iVar3,iVar4);
          *(undefined4 *)(&g_CardSlot_CardId + iVar4 * 0x120 + iVar3 * 0x5b20) = 0xffffffff;
        }
      }
      if (g_IsAiThinking != 1) {
        Magic_UpkeepPhase(0x18);
      }
    }
    break;
  case 0xc:
    Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,-1,-1,s_activates_The_Hive_effect__0052ccdc,0);
    iVar3 = FUN_0040a1d2(2);
    iVar4 = Pic_Subsystem_0045268f(0x375);
    iVar4 = Pic_Subsystem_00451291(iVar3,iVar4);
    if (iVar4 != -1) {
      Pic_Subsystem_0042ac1f(iVar3,iVar4);
      *(uint *)(&g_CardSlot_Abilities1 + iVar4 * 0x120 + iVar3 * 0x5b20) =
           *(uint *)(&g_CardSlot_Abilities1 + iVar4 * 0x120 + iVar3 * 0x5b20) | 0x10;
    }
    break;
  case 0xd:
    Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,-1,-1,s_activates_Nevinyrral_s_Disk_effe_0052ccf8,0);
    CardQuery_ForEachPermanent(Minit_Subsystem_00463c10,-1);
    break;
  case 0xe:
    Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,-1,-1,s_casts_Fog_effect__0052cdcc,0);
    iVar3 = FUN_00410cc0(arg_1,arg_2,DAT_0068a670,-1,-1);
    if (iVar3 != -1) {
      *(undefined4 *)(&DAT_006a5f74 + arg_1 * 0x5b20 + iVar3 * 0x120) = DAT_0052caf0;
    }
    break;
  case 0xf:
    Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,iVar3,iVar4,s_activates_Sinbad_effect__0052cde0,0);
    iVar4 = FUN_0046f5d1(iVar3);
    Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,iVar3,iVar4,s_Sinbad_draws____0052cdfc,0);
    if (((&g_MasterCardColorTable)
         [*(int *)(&g_CardSlot_CardId + iVar4 * 0x120 + iVar3 * 0x5b20) * 0x34] & 1) == 0) {
      Pic_Subsystem_0044913a(iVar3,iVar4);
      *(undefined4 *)(&g_CardSlot_CardId + iVar4 * 0x120 + iVar3 * 0x5b20) = 0xffffffff;
      (&DAT_006b3008)[iVar3] = (&DAT_006b3008)[iVar3] + -1;
      if (g_IsAiThinking != 1) {
        Magic_UpkeepPhase(0x18);
      }
    }
    break;
  default:
    Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,iVar3,iVar4,s_made_an_error__0052ce0c,0);
  }
  return 0;
}


