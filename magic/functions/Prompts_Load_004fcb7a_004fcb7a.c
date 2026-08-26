/*
 * Decompiled function: Prompts_Load_004fcb7a
 * Entry Point: 004fcb7a
 * Size: 880 bytes
 */
#include "magic.h"


undefined4 Prompts_Load_004fcb7a(int spell_id,int target_id,int flags)

{
  bool bVar1;
  undefined4 uVar2;
  int arg2;
  int local_14;
  int local_c;
  
  if (flags == 0x74) {
    uVar2 = 1;
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      g_SpellStackDepth = g_SpellStackDepth + 0x18;
    }
    if (flags == 0x71) {
      if (((spell_id == g_CurrentTurnPhase) && (g_IsAiThinking != 1)) && (DAT_006fedc0 == 0)) {
        Pic_Subsystem_00424500(s_prompts_txt_0053068c,s_UNTAMED_WILDS_0053067c);
        bVar1 = false;
        local_14 = 0;
        while (((local_14 < 500 && (!bVar1)) &&
               (*(int *)(&DAT_0069e730 + local_14 * 4 + spell_id * 2000) != -1))) {
          if (*(int *)(&DAT_0069e730 + local_14 * 4 + spell_id * 2000) < 5) {
            bVar1 = true;
          }
          local_14 = local_14 + 1;
        }
        if (bVar1) {
          do {
            local_c = Pic_Load_004509e8(spell_id,(int)(&DAT_0069e730 + spell_id * 2000),500,
                                        &g_OverworldGoldAmount,1);
            if (local_c == -1) break;
          } while (4 < *(int *)(&DAT_0069e730 + local_c * 4 + spell_id * 2000));
        }
        else {
          local_c = -1;
          Pic_Load_004509e8(spell_id,(int)(&DAT_0069e730 + spell_id * 2000),500,
                            &g_OverworldGoldAmount,0);
        }
      }
      else {
        local_c = FUN_004fdad2(spell_id,spell_id,1);
        if ((local_c != -1) && (4 < *(int *)(&DAT_0069e730 + local_c * 4 + spell_id * 2000))) {
          local_c = -1;
          local_14 = 0;
          while (((local_14 < 500 && (local_c == -1)) &&
                 (*(int *)(&DAT_0069e730 + local_14 * 4 + spell_id * 2000) != -1))) {
            if (*(int *)(&DAT_0069e730 + local_14 * 4 + spell_id * 2000) < 5) {
              local_c = local_14;
            }
            local_14 = local_14 + 1;
          }
        }
      }
      if ((local_c != -1) &&
         ((*(int *)(&DAT_0069e730 + local_c * 4 + spell_id * 2000) == -1 ||
          (4 < *(int *)(&DAT_0069e730 + local_c * 4 + spell_id * 2000))))) {
        local_c = -1;
      }
      if (((local_c != -1) && (*(int *)(&DAT_0069e730 + local_c * 4 + spell_id * 2000) != -1)) &&
         (arg2 = Pic_Subsystem_00451291
                           (spell_id,*(int *)(&DAT_0069e730 + local_c * 4 + spell_id * 2000)),
         arg2 != -1)) {
        Pic_Subsystem_004523fd(spell_id,local_c);
        Pic_Subsystem_0042ac1f(spell_id,arg2);
        Ai_Subsystem_004cc9c5(0,0x30);
      }
      Pic_Subsystem_00452276(spell_id);
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}


