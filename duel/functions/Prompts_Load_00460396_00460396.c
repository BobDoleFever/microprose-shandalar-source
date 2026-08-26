/*
 * Decompiled function: Prompts_Load_00460396
 * Entry Point: 00460396
 * Size: 610 bytes
 */
#include "duel.h"


undefined4 Prompts_Load_00460396(int spell_id,int target_id,int flags)

{
  int iVar1;
  undefined4 uVar2;
  int aiStack_20 [7];
  
  iVar1 = FUN_004af74c(spell_id,target_id,2);
  aiStack_20[6] = iVar1 + -1;
  aiStack_20[5] = 0;
  while ((aiStack_20[5] < 2 && (DAT_00681ea4 != 1))) {
    FUN_00434660(s_prompts_txt_004f8b68,s_LEVIATHAN_004f8b5c);
    if (aiStack_20[6] == 4) {
      FUN_004718de(&DAT_006679f0,s_island_004f8b7c,0,s_PLAINS_004f8b74);
    }
    else if (aiStack_20[6] == 0) {
      FUN_004718de(&DAT_006679f0,s_island_004f8b8c,0,s_SWAMP_004f8b84);
    }
    else if (aiStack_20[6] == 3) {
      FUN_004718de(&DAT_006679f0,s_island_004f8ba0,0,s_MOUNTAIN_004f8b94);
    }
    else if (aiStack_20[6] == 2) {
      FUN_004718de(&DAT_006679f0,s_island_004f8bb0,0,s_FOREST_004f8ba8);
    }
    iVar1 = Action_ValidateTarget_0041e2a2
                      (spell_id,spell_id,spell_id,0x200,0,0,0,0,0,0,aiStack_20[6],-1,0xffffffff,
                       0xffffffff,0,0,0,&DAT_006679f0,(uint)(flags != 0),
                       aiStack_20 + aiStack_20[5] * 2);
    if (iVar1 == 0) {
      for (aiStack_20[4] = 0; aiStack_20[4] < aiStack_20[5]; aiStack_20[4] = aiStack_20[4] + 1) {
        *(uint *)(&DAT_006826cc +
                 aiStack_20[aiStack_20[4] * 2] * 0x5b20 + aiStack_20[aiStack_20[4] * 2 + 1] * 0x120)
             = *(uint *)(&DAT_006826cc +
                        aiStack_20[aiStack_20[4] * 2] * 0x5b20 +
                        aiStack_20[aiStack_20[4] * 2 + 1] * 0x120) & 0xffcfffff;
      }
      FUN_00451482(0,0x20);
      DAT_00681ea4 = 1;
    }
    else {
      *(uint *)(&DAT_006826cc +
               aiStack_20[aiStack_20[5] * 2] * 0x5b20 + aiStack_20[aiStack_20[5] * 2 + 1] * 0x120) =
           *(uint *)(&DAT_006826cc +
                    aiStack_20[aiStack_20[5] * 2] * 0x5b20 +
                    aiStack_20[aiStack_20[5] * 2 + 1] * 0x120) | 0x300000;
      FUN_00451482(0,0x20);
    }
    aiStack_20[5] = aiStack_20[5] + 1;
  }
  if (DAT_00681ea4 == 1) {
    DAT_00681ea4 = -1;
    uVar2 = 0;
  }
  else {
    for (aiStack_20[5] = 0; aiStack_20[5] < 2; aiStack_20[5] = aiStack_20[5] + 1) {
      if (DAT_0066aaf4 != 1) {
        FUN_0048d00c(0xf);
      }
      FUN_0046e571(aiStack_20[aiStack_20[5] * 2],aiStack_20[aiStack_20[5] * 2 + 1],3);
    }
    uVar2 = 1;
  }
  return uVar2;
}


