/*
 * Decompiled function: Action_ValidateTarget_00405802
 * Entry Point: 00405802
 * Size: 1737 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int Action_ValidateTarget_00405802
              (int spell_id,uint target_id,uint flags,uint arg_4,uint arg_5,uint arg_6,uint arg_7,
              uint arg_8,uint arg_9,uint arg_10,int arg_11,int arg_12,uint arg_13,uint arg_14,
              uint arg_15,uint arg_16,uint arg_17,undefined1 *arg_18,undefined4 arg_19,int *arg_20)

{
  int iVar1;
  size_t sVar2;
  char *local_3bc;
  int local_3b8;
  int local_3b4;
  int local_3b0;
  undefined4 local_3ac;
  char local_3a8 [200];
  char local_2e0 [200];
  int local_218;
  int aiStack_214 [60];
  int local_124;
  int local_120;
  int local_11c;
  int aiStack_118 [60];
  int local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  if (((spell_id == 1) || (g_IsAiThinking == 1)) || (DAT_006fedc0 != 0)) {
    if ((((byte)DAT_00680790 & 1) != 0) && ((target_id & 2) != 0)) {
      flags = target_id;
    }
    local_28 = spell_id;
    if ((target_id & 2) == 0) {
      local_18 = target_id & 1;
    }
    else {
      local_18 = 0xffffffff;
    }
    if ((flags & 2) == 0) {
      local_20 = flags & 1;
    }
    else {
      local_20 = 0xffffffff;
    }
    local_1c = arg_5;
    local_24 = arg_9;
    if ((arg_4 == 0) || ((arg_4 & 0x1000) != 0)) {
      if ((flags & 2) == 0) {
        if ((flags & 1) == 0) {
          local_8 = 1;
          local_14 = 0;
        }
        else {
          local_8 = 0;
          local_14 = 1;
        }
      }
      else {
        local_8 = 1;
        local_14 = 1;
      }
    }
    else {
      local_8 = 0;
      local_14 = 0;
    }
    if (g_ActivePlayer == 1) {
      local_10 = 0;
    }
    else {
      local_124 = 0;
      for (local_11c = 0; local_11c < 2; local_11c = local_11c + 1) {
        for (local_120 = 0; local_120 < (int)(&g_PlayerActiveCardCount)[local_11c];
            local_120 = local_120 + 1) {
          if ((*(int *)(&g_CardSlot_CardId + local_120 * 0x120 + local_11c * 0x5b20) != -1) &&
             (iVar1 = Rules_ParseFilter_0040360b
                                (local_11c,local_120,(char *)0x0,spell_id,(byte)target_id,
                                 (byte)flags,arg_4,arg_5,arg_6,arg_7,arg_8,arg_9,arg_10,arg_11,
                                 arg_12,arg_13,arg_14,arg_15,arg_16,arg_17), iVar1 != 0)) {
            aiStack_118[local_124] = local_11c;
            aiStack_214[local_124] = local_120;
            local_124 = local_124 + 1;
          }
        }
      }
      if (local_14 != 0) {
        aiStack_118[local_124] = 1;
        aiStack_214[local_124] = -1;
        local_124 = local_124 + 1;
      }
      if (local_8 != 0) {
        aiStack_118[local_124] = 0;
        aiStack_214[local_124] = -1;
        local_124 = local_124 + 1;
      }
      if (local_124 == 0) {
        local_10 = 0;
      }
      else {
        if (g_IsAiThinking == 1) {
          g_AiDecisionScore = FUN_0040a1d2(local_124);
          DAT_006fefa8 = CONCAT31((int3)((aiStack_118[g_AiDecisionScore] == 0) - 1 >> 8),
                                  (char)aiStack_214[g_AiDecisionScore]) & 0x1ff | 0x4000;
          DAT_0052ce1c = 3;
          Ai_EvaluateCreaturePower();
        }
        else {
          DAT_0052ce1c = 3;
          Ai_CalcCardAdvantage();
          if ((g_AiDecisionScore == 99) || (local_124 <= g_AiDecisionScore)) {
            g_AiDecisionScore = FUN_0040a1d2(local_124);
          }
        }
        _DAT_0063ee20 = aiStack_118[g_AiDecisionScore];
        *arg_20 = aiStack_118[g_AiDecisionScore];
        arg_20[1] = aiStack_214[g_AiDecisionScore];
        local_10 = 1;
      }
    }
  }
  else {
    if ((arg_4 == 0) || ((arg_4 & 0x1000) != 0)) {
      if ((target_id & 2) == 0) {
        if ((target_id & 1) == 0) {
          local_8 = 1;
          local_14 = 0;
        }
        else {
          local_8 = 0;
          local_14 = 1;
        }
      }
      else {
        local_8 = 1;
        local_14 = 1;
      }
    }
    else {
      local_8 = 0;
      local_14 = 0;
    }
    local_c = SpellChain_IsVisible();
    local_218 = 1;
    while (local_218 != 0) {
      if (arg_18 == (undefined1 *)0x0) {
        Action_PromptTarget_00405370(arg_5,arg_9,local_14 | local_8);
      }
      DAT_00627a88 = -1;
      if (arg_18 == (undefined1 *)0x0) {
        local_3bc = &g_OverworldWorldState;
      }
      else {
        local_3bc = arg_18;
      }
      local_10 = Ai_Subsystem_004af765
                           (0xffffffff,local_3bc,arg_19,0xffffffff,0xffffffff,0xffffffff,0xffffffff,
                            &local_3b8,&local_3b4,local_14,local_8);
      if (local_10 == 0) {
        if ((local_3b8 != -3) && (local_3b8 == -2)) {
          if ((DAT_00627a84 == -1) && (DAT_00627a88 == -1)) {
            *arg_20 = local_3b4;
            arg_20[1] = local_3b0;
            local_218 = 0;
          }
          else if ((arg_4 & 0x2000) != 0) {
            *arg_20 = -1;
            arg_20[1] = -3;
            local_218 = 0;
          }
        }
      }
      else {
        iVar1 = Rules_ParseFilter_0040360b
                          (local_3b4,local_3b0,local_2e0,spell_id,(byte)target_id,(byte)flags,arg_4,
                           arg_5,arg_6,arg_7,arg_8,arg_9,arg_10,arg_11,arg_12,arg_13,arg_14,arg_15,
                           arg_16,arg_17);
        if (iVar1 == 0) {
          local_3ac = 1;
          sVar2 = strlen(local_2e0);
          if (sVar2 == 0) {
            strcpy(local_3a8,s_Illegal_target__005163a8);
          }
          else {
            sprintf(local_3a8,s_Illegal_target___s___00516390,local_2e0);
          }
          if (g_IsAiThinking != 1) {
            Ai_Util_004cc42d(local_3a8);
            Sleep(2000);
            Ai_Util_004cc42d(&DAT_005163b8);
          }
        }
        else {
          local_3ac = 0;
          *arg_20 = local_3b4;
          arg_20[1] = local_3b0;
          local_218 = 0;
        }
      }
    }
    if (local_c == 0) {
      SpellChain_IsMinimized();
    }
    if (local_10 != 0) {
      DAT_00633434 = 0;
    }
    Ai_Util_004cc42d(&DAT_005163bc);
    strcpy(&g_OverworldGoldAmount,&DAT_005163c0);
  }
  return local_10;
}


