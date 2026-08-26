/*
 * Decompiled function: FUN_004f7869
 * Entry Point: 004f7869
 * Size: 529 bytes
 */
#include "magic.h"


undefined4 FUN_004f7869(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (arg_3 == 0x6c) {
      g_SpellStackDepth = g_SpellStackDepth - ((&DAT_006b3008)[arg_1] * -0x18 + 0x30);
    }
    if (arg_3 == 0x71) {
      local_1c = 0;
      local_14 = g_DefendingPlayer;
      while (local_1c < 2) {
        local_20 = 0;
        for (local_8 = 0; local_8 < (int)(&g_PlayerActiveCardCount)[local_14]; local_8 = local_8 + 1
            ) {
          iVar2 = FUN_00471bc0(local_14,local_8);
          if (iVar2 != 0) {
            local_20 = local_20 + 1;
          }
        }
        for (local_18 = 0; local_18 < local_20; local_18 = local_18 + 1) {
          Prompts_Load_0046fa40(local_14,1,0);
        }
        local_1c = local_1c + 1;
        if (g_DefendingPlayer == 0) {
          local_14 = local_14 + 1;
        }
        else {
          local_14 = local_14 + -1;
        }
      }
      Ai_Subsystem_004cc9c5(0,0x30);
      local_10 = 0;
      local_c = 0;
      for (local_18 = 0; local_18 < 500; local_18 = local_18 + 1) {
        if (*(int *)(&DAT_0069e730 + local_18 * 4) != -1) {
          local_c = local_c + 1;
        }
        if (*(int *)(&DAT_0069ef00 + local_18 * 4) != -1) {
          local_10 = local_10 + 1;
        }
      }
      if ((local_c < 7) && (local_10 < 7)) {
        if (g_IsAiThinking == 1) {
          g_PlayerCreatureCount = 0;
          DAT_006a4a04 = 0;
        }
        else {
          Ai_Util_004cc42d(s_Neither_player_has_enough_librar_0053035c);
          Sleep(0x9c4);
          Ai_Util_004cc42d(&DAT_005303a0);
          Pic_Util_00450975(2);
        }
      }
      else {
        FUN_004f823a(0,7);
        FUN_004f823a(1,7);
      }
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


