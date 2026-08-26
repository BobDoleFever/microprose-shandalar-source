/*
 * Decompiled function: Card_Leviathan_PromptLandSacrifice
 * Entry Point: 004dec09
 * Size: 610 bytes
 */
#include "magic.h"


undefined4 Card_Leviathan_PromptLandSacrifice(int spell_id,int target_id,int flags)

{
  int iVar1;
  undefined4 uVar2;
  int aiStack_20 [7];
  
  iVar1 = FUN_0041d963(spell_id,target_id,2);
  aiStack_20[6] = iVar1 + -1;
  aiStack_20[5] = 0;
  while ((aiStack_20[5] < 2 && (g_ActivePlayer != 1))) {
    Pic_Subsystem_00424500(s_prompts_txt_0052ecd4,s_LEVIATHAN_0052ecc8);
    if (aiStack_20[6] == 4) {
      FUN_004f4a92(&g_OverworldGoldAmount,s_island_0052ece8,0,s_PLAINS_0052ece0);
    }
    else if (aiStack_20[6] == 0) {
      FUN_004f4a92(&g_OverworldGoldAmount,s_island_0052ecf8,0,s_SWAMP_0052ecf0);
    }
    else if (aiStack_20[6] == 3) {
      FUN_004f4a92(&g_OverworldGoldAmount,s_island_0052ed0c,0,s_MOUNTAIN_0052ed00);
    }
    else if (aiStack_20[6] == 2) {
      FUN_004f4a92(&g_OverworldGoldAmount,s_island_0052ed1c,0,s_FOREST_0052ed14);
    }
    iVar1 = Action_ValidateTarget_00405802
                      (spell_id,spell_id,spell_id,0x200,0,0,0,0,0,0,aiStack_20[6],-1,0xffffffff,
                       0xffffffff,0,0,0,&g_OverworldGoldAmount,(uint)(flags != 0),
                       aiStack_20 + aiStack_20[5] * 2);
    if (iVar1 == 0) {
      for (aiStack_20[4] = 0; aiStack_20[4] < aiStack_20[5]; aiStack_20[4] = aiStack_20[4] + 1) {
        *(uint *)(&g_CardSlot_Flags +
                 aiStack_20[aiStack_20[4] * 2] * 0x5b20 + aiStack_20[aiStack_20[4] * 2 + 1] * 0x120)
             = *(uint *)(&g_CardSlot_Flags +
                        aiStack_20[aiStack_20[4] * 2] * 0x5b20 +
                        aiStack_20[aiStack_20[4] * 2 + 1] * 0x120) & 0xffcfffff;
      }
      Ai_Subsystem_004cc9c5(0,0x20);
      g_ActivePlayer = 1;
    }
    else {
      *(uint *)(&g_CardSlot_Flags +
               aiStack_20[aiStack_20[5] * 2] * 0x5b20 + aiStack_20[aiStack_20[5] * 2 + 1] * 0x120) =
           *(uint *)(&g_CardSlot_Flags +
                    aiStack_20[aiStack_20[5] * 2] * 0x5b20 +
                    aiStack_20[aiStack_20[5] * 2 + 1] * 0x120) | 0x300000;
      Ai_Subsystem_004cc9c5(0,0x20);
    }
    aiStack_20[5] = aiStack_20[5] + 1;
  }
  if (g_ActivePlayer == 1) {
    g_ActivePlayer = -1;
    uVar2 = 0;
  }
  else {
    for (aiStack_20[5] = 0; aiStack_20[5] < 2; aiStack_20[5] = aiStack_20[5] + 1) {
      if (g_IsAiThinking != 1) {
        Magic_UpkeepPhase(0xf);
      }
      Pic_Subsystem_0044867e(aiStack_20[aiStack_20[5] * 2],aiStack_20[aiStack_20[5] * 2 + 1],3);
    }
    uVar2 = 1;
  }
  return uVar2;
}


