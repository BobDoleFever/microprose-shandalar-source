/*
 * Decompiled function: Palette_Subsystem_004a99a0
 * Entry Point: 004a99a0
 * Size: 3718 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint Palette_Subsystem_004a99a0(int arg_1)

{
  uint uVar1;
  int iVar2;
  uint local_9c;
  uint auStack_98 [20];
  int local_48;
  uint local_44;
  uint local_40;
  int local_3c;
  int local_38;
  uint local_34;
  int local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  int local_20;
  int local_1c;
  uint local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  if ((g_IsAiThinking == 1) || (DAT_00633434 != 0)) {
    local_30 = 1 - arg_1;
    local_c = 0;
    local_38 = 0;
    local_8 = 0;
    local_28 = 0;
    local_9c = 0;
    local_34 = 2;
    if (((g_PlayerHandCardCount & 1) == 0) && (0 < (&DAT_006b3008)[arg_1] + DAT_00627a14)) {
      for (local_2c = 0; (int)local_2c < (int)(&g_PlayerActiveCardCount)[arg_1];
          local_2c = local_2c + 1) {
        if (*(int *)(&g_CardSlot_CardId + arg_1 * 0x5b20 + local_2c * 0x120) != -1) {
          if ((((&g_CardSlot_Flags)[arg_1 * 0x5b20 + local_2c * 0x120] & 2) != 0) &&
             (((&g_MasterCardColorTable)
               [*(int *)(&g_CardSlot_CardId + arg_1 * 0x5b20 + local_2c * 0x120) * 0x34] & 2) != 0))
          {
            local_34 = local_34 | 0x7c;
          }
          if (((&g_CardSlot_Flags)[arg_1 * 0x5b20 + local_2c * 0x120] & 0x12) == 0) {
            if ((((&g_MasterCardColorTable)
                  [*(int *)(&g_CardSlot_CardId + arg_1 * 0x5b20 + local_2c * 0x120) * 0x34] & 1) !=
                 0) && (local_8 = 1, (&DAT_006a5f4c)[arg_1 * 0x5b20 + local_2c * 0x120] != '\0')) {
              local_38 = local_38 + 1;
            }
            if ((&DAT_0051aec0)
                [*(int *)(&g_CardSlot_CardId + arg_1 * 0x5b20 + local_2c * 0x120) * 0x34] == -1) {
              local_38 = local_38 + 99;
            }
            local_c = local_c + 1;
          }
        }
      }
      if (local_8 != 0) {
        local_10 = 0;
        local_8 = 0;
        for (local_2c = 0; (int)local_2c < (int)(&g_PlayerActiveCardCount)[arg_1];
            local_2c = local_2c + 1) {
          local_20 = *(int *)(&g_CardSlot_CardId + arg_1 * 0x5b20 + local_2c * 0x120);
          if ((local_20 != -1) &&
             (((&g_CardSlot_Flags)[arg_1 * 0x5b20 + local_2c * 0x120] & 0x12) == 0)) {
            local_40 = (uint)(char)(&DAT_0051aebe)[local_20 * 0x34];
            if ((((&g_MasterCardColorTable)[local_20 * 0x34] & 1) != 0) &&
               (local_9c = local_9c | local_40, local_40 == 0)) {
              local_10 = 1;
            }
            if ((local_34 & (byte)(&g_MasterCardColorTable)[local_20 * 0x34]) != 0) {
              for (local_48 = 1; local_48 < 6; local_48 = local_48 + 1) {
                if ((local_40 & 1 << ((byte)local_48 & 0x1f)) != 0) {
                  if (*(int *)(&DAT_0063ee30 + local_48 * 4 + arg_1 * 0x20) + 1 ==
                      (int)(char)(&DAT_0051aebf)[local_20 * 0x34]) {
                    local_28 = local_28 | 1 << ((byte)local_48 & 0x1f);
                  }
                  if (*(int *)(&DAT_0063ee30 + local_48 * 4 + arg_1 * 0x20) + 1 <
                      (int)(char)(&DAT_0051aebf)[local_20 * 0x34]) {
                    local_8 = local_8 | 1 << ((byte)local_48 & 0x1f);
                  }
                  iVar2 = abs((int)(char)(&DAT_0051aec0)[local_20 * 0x34]);
                  if (*(int *)(&DAT_0063ee4c + arg_1 * 0x20) <
                      iVar2 + (char)(&DAT_0051aebf)[local_20 * 0x34]) {
                    local_8 = local_8 | 0xff;
                  }
                }
              }
            }
          }
        }
        local_3c = 999;
        local_24 = local_9c;
        for (local_2c = 0; (int)local_2c < 6; local_2c = local_2c + 1) {
          if (0 < *(int *)(&DAT_006ff690 + local_2c * 4 + arg_1 * 0x20)) {
            local_8 = local_8 | 1 << ((byte)local_2c & 0x1f);
          }
          if (((local_9c & 1 << ((byte)local_2c & 0x1f)) != 0) &&
             (*(int *)(&DAT_0063ee30 + local_2c * 4 + arg_1 * 0x20) -
              *(int *)(&DAT_006ff690 + local_2c * 4 + arg_1 * 0x20) < local_3c)) {
            local_3c = *(int *)(&DAT_0063ee30 + local_2c * 4 + arg_1 * 0x20) -
                       *(int *)(&DAT_006ff690 + local_2c * 4 + arg_1 * 0x20);
            local_24 = 1 << ((byte)local_2c & 0x1f);
          }
        }
        if (local_9c == 0) {
          if ((g_IsAiThinking != 1) && (local_10 != 0)) {
            DAT_0052ce1c = 1;
            Ai_CalcCardAdvantage();
          }
          local_40 = 99;
        }
        else {
          local_18 = local_24;
          if ((local_8 & local_9c) != 0) {
            local_18 = local_8 & local_9c;
          }
          local_34 = local_28 & local_9c;
          uVar1 = local_34;
          if ((local_34 == 0) && (uVar1 = local_18, local_10 != 0)) {
            local_40 = 0xffffffff;
          }
          else {
            do {
              local_18 = uVar1;
              local_40 = FUN_0040a1d2(7);
              uVar1 = local_18;
            } while ((local_18 & 1 << ((byte)local_40 & 0x1f)) == 0);
          }
          if (g_IsAiThinking == 1) {
            g_AiDecisionScore = local_40;
            DAT_006fefa8 = 0xffffffff;
            iVar2 = FUN_0040a1d2(4);
            if ((iVar2 == 0) && (DAT_006a2838 == 0)) {
              g_AiDecisionScore = 0xfffffffe;
            }
            if ((((local_28 == 0) && (local_8 == 0)) && (local_10 == 0)) &&
               ((local_c < 7 && (3 < *(int *)(&DAT_0063ee4c + arg_1 * 0x20) - local_38)))) {
              g_AiDecisionScore = 0xfffffffe;
            }
          }
          else {
            DAT_0052ce1c = 1;
            Ai_CalcCardAdvantage();
            local_40 = g_AiDecisionScore;
          }
        }
        local_44 = 0xffffffff;
        for (local_2c = 0; (int)local_2c < (int)(&g_PlayerActiveCardCount)[arg_1];
            local_2c = local_2c + 1) {
          local_20 = *(int *)(&g_CardSlot_CardId + arg_1 * 0x5b20 + local_2c * 0x120);
          if (((((local_20 != -1) &&
                (((&g_CardSlot_Flags)[arg_1 * 0x5b20 + local_2c * 0x120] & 0x12) == 0)) &&
               (((&g_MasterCardColorTable)[local_20 * 0x34] & 1) != 0)) &&
              ((((local_40 == 0xffffffff &&
                 ((&DAT_006a5f4c)[arg_1 * 0x5b20 + local_2c * 0x120] == '\0')) ||
                ((1 << ((byte)local_40 & 0x1f) &
                 (int)(char)(&DAT_006a5f4c)[arg_1 * 0x5b20 + local_2c * 0x120]) != 0)) ||
               (local_9c == 0)))) && ((local_44 == 0xffffffff || (4 < local_20)))) {
            local_44 = local_2c;
          }
        }
        if ((g_IsAiThinking == 1) && ((local_9c != 0 || (local_10 != 0)))) {
          if (g_AiDecisionScore == 0xfffffffe) {
            DAT_006fefa8 = 0xffffffff;
          }
          else {
            DAT_006fefa8 = arg_1 << 8 | local_44 | 0x1000;
          }
          DAT_0052ce1c = 1;
          Ai_EvaluateCreaturePower();
          if (g_AiDecisionScore != 0xfffffffe) {
            if (0xf < DAT_006a2844) {
              DAT_006a2844 = DAT_006a2844 + -1;
            }
            *(undefined4 *)(&DAT_006fe3b0 + DAT_006a2844 * 4) =
                 *(undefined4 *)(&g_CardSlot_CardId + arg_1 * 0x5b20 + local_44 * 0x120);
            *(uint *)(&DAT_006966f0 + DAT_006a2844 * 4) = local_44;
            DAT_006a2844 = DAT_006a2844 + 1;
          }
        }
        if (g_AiDecisionScore != 0xfffffffe) {
          return local_44;
        }
        if ((local_9c == 0) && (local_10 == 0)) {
          return local_44;
        }
        g_PlayerHandCardCount = g_PlayerHandCardCount | 1;
      }
    }
    local_1c = 0;
    _DAT_0054d640 = 2;
    _DAT_005528c8 = 0x20;
    if (0x16 < g_ScWillyScore) {
      _DAT_0054d640 = 4;
      _DAT_005528c8 = 0x40;
    }
    if (g_ScWillyScore < 0x15) {
      _DAT_0054d640 = 1;
      _DAT_005528c8 = 0x10;
    }
    if (0x1d < g_ScWillyScore) {
      _DAT_0054d640 = 8;
      _DAT_005528c8 = 0xffffff80;
    }
    if (g_ScWillyScore == 0x1f) {
      _DAT_0054d640 = 0xf;
      _DAT_005528c8 = 0xfffffff0;
    }
    for (local_2c = 0; (int)local_2c < (int)(&g_PlayerActiveCardCount)[arg_1];
        local_2c = local_2c + 1) {
      local_20 = *(int *)(&g_CardSlot_CardId + arg_1 * 0x5b20 + local_2c * 0x120);
      if (local_20 != -1) {
        if (((&g_CardSlot_Flags)[arg_1 * 0x5b20 + local_2c * 0x120] & 2) == 0) {
          if (((_DAT_0054d640 & (int)(char)(&DAT_0051aed5)[local_20 * 0x34]) != 0) &&
             (((&g_MasterCardColorTable)[local_20 * 0x34] & 0x7e) != 0)) {
            local_40 = FUN_00473cc5((&DAT_0051aebe)[local_20 * 0x34]);
            iVar2 = FUN_00470ea3(arg_1,arg_1,local_2c);
            if ((iVar2 != 0) &&
               ((((&g_MasterCardColorTable)[local_20 * 0x34] & 0x3c) == 0 ||
                (iVar2 = (**(code **)(&DAT_0051aec8 + local_20 * 0x34))(arg_1,local_2c,0x74),
                iVar2 != 0)))) {
              auStack_98[local_1c] = local_2c;
              local_1c = local_1c + 1;
            }
          }
        }
        else if ((((((&g_CardSlot_Flags)[arg_1 * 0x5b20 + local_2c * 0x120] & 0x34) == 0) &&
                  ((*(uint *)(&DAT_0051aed0 + local_20 * 0x34) & 0x1003) != 0x1000)) &&
                 ((_DAT_005528c8 & (int)(char)(&DAT_0051aed5)[local_20 * 0x34]) != 0)) &&
                (iVar2 = Magic_TriggerCardEvent(arg_1,local_2c,0x73,1 - arg_1,0xffffffff),
                iVar2 != 0)) {
          auStack_98[local_1c] = local_2c;
          local_1c = local_1c + 1;
        }
      }
    }
    if (local_1c == 0) {
      DAT_006a2840 = -1;
      DAT_0052ce20 = 0;
      if (DAT_006a2838 == 1) {
        DAT_006fe40c = -1;
      }
      uVar1 = 0xffffffff;
    }
    else {
      if (g_IsAiThinking == 1) {
        if (DAT_0069f6d8 == -9999) {
          DAT_00680790 = 0;
        }
        if ((DAT_006b1580 == 0x19) && (local_1c < 3)) {
          DAT_00680790 = DAT_00680790 | 1;
        }
      }
      auStack_98[local_1c] = 0xffffffff;
      local_1c = local_1c + 1;
      if (g_IsAiThinking == 1) {
        if ((DAT_006a2840 == -1) || (DAT_006a2838 != 0)) {
          g_AiDecisionScore = FUN_0040a1d2(local_1c);
          if (DAT_006a2838 != 0) {
            g_AiDecisionScore = local_1c - 1;
            if (DAT_006a2838 == 1) {
              iVar2 = FUN_0040a305(local_1c * local_1c,10,0x14);
              DAT_006fe40c = iVar2 * (DAT_0067f380 + 1) * 5;
            }
            DAT_006a2838 = -1;
          }
          DAT_006fefa8 = (-(uint)((*(uint *)(&g_CardSlot_Flags +
                                            arg_1 * 0x5b20 + auStack_98[g_AiDecisionScore] * 0x120)
                                  & 2) == 0) & 0xfffff000) + 0x2000 | auStack_98[g_AiDecisionScore]
                         | (arg_1 == 0) - 1 & 0x100;
          DAT_0052ce1c = 2;
          Ai_EvaluateCreaturePower();
        }
        else {
          local_14 = Ai_Util_004ab510();
          uVar1 = DAT_0052ce20;
          if ((DAT_0052ce20 == 0) && (DAT_006a2840 < local_14)) {
            DAT_006a2840 = local_14;
          }
          if (local_14 == DAT_006a2840) {
            g_AiDecisionScore = DAT_0052ce20;
            DAT_0052ce20 = DAT_0052ce20 + 1;
            if (local_1c + -1 <= (int)uVar1) {
              DAT_006a2840 = DAT_006a2840 + 1;
              DAT_0052ce20 = 0;
            }
          }
          if (DAT_006a2840 < local_14) {
            g_AiDecisionScore = local_1c - 1;
          }
          if (local_14 < DAT_006a2840) {
            DAT_0052ce1c = 2;
            Ai_CalcCardAdvantage();
            Ai_Util_004ab525();
            if (local_1c <= (int)g_AiDecisionScore) {
              g_AiDecisionScore = local_1c - 1;
            }
          }
          DAT_006fefa8 = (-(uint)((*(uint *)(&g_CardSlot_Flags +
                                            arg_1 * 0x5b20 + auStack_98[g_AiDecisionScore] * 0x120)
                                  & 2) == 0) & 0xfffff000) + 0x2000 | auStack_98[g_AiDecisionScore]
                         | (arg_1 == 0) - 1 & 0x100;
          DAT_0052ce1c = 2;
          Ai_EvaluateCreaturePower();
          if ((local_1c - 1U == g_AiDecisionScore) && (local_14 < DAT_006a2840)) {
            DAT_006a2840 = -1;
            DAT_0052ce20 = 0;
          }
        }
      }
      else {
        DAT_0052ce1c = 2;
        Ai_CalcCardAdvantage();
        if (local_1c <= (int)g_AiDecisionScore) {
          g_AiDecisionScore = local_1c - 1;
        }
      }
      if (auStack_98[g_AiDecisionScore] != 0xffffffff) {
        if (0xf < DAT_006a2844) {
          DAT_006a2844 = DAT_006a2844 + -1;
        }
        *(undefined4 *)(&DAT_006fe3b0 + DAT_006a2844 * 4) =
             *(undefined4 *)
              (&g_CardSlot_CardId + arg_1 * 0x5b20 + auStack_98[g_AiDecisionScore] * 0x120);
        *(uint *)(&DAT_006966f0 + DAT_006a2844 * 4) = auStack_98[g_AiDecisionScore];
        DAT_006a2844 = DAT_006a2844 + 1;
      }
      uVar1 = auStack_98[g_AiDecisionScore];
    }
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


