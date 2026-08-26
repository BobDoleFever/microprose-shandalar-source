/*
 * Decompiled function: Card_HypnoticSpecter_RandomDiscard
 * Entry Point: 004d9afd
 * Size: 1153 bytes
 */
#include "magic.h"


void Card_HypnoticSpecter_RandomDiscard(int arg_1,int arg_2,int arg_3)

{
  int arg_4;
  int local_94;
  int local_90;
  int local_88;
  int local_80 [30];
  int local_8;
  
  if (arg_3 == 1) {
    *(int *)(&DAT_006ff694 + arg_1 * 0x20) = *(int *)(&DAT_006ff694 + arg_1 * 0x20) + 1;
  }
  if (arg_3 == 0x73) {
    FUN_0040d949(arg_1,1,3);
  }
  else {
    if (((arg_3 == 0x6d) &&
        ((*(uint *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + arg_2 * 0x120) & 0x20010) == 0)) &&
       (Ai_CalcManaRequirement_004ba890(arg_1,1,3), g_ActivePlayer != 1)) {
      *(uint *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + arg_2 * 0x120) =
           *(uint *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + arg_2 * 0x120) | 0x10;
    }
    if (arg_3 == 0x72) {
      arg_4 = 1 - arg_1;
      if (((g_IsAiThinking != 1) && (arg_1 == 0)) && (DAT_006fedc0 == 0)) {
        local_90 = 0;
        for (local_88 = 0; local_88 < DAT_006808bc; local_88 = local_88 + 1) {
          if ((*(int *)(&DAT_006aba54 + local_88 * 0x120) != -1) &&
             (((&DAT_006aba5c)[local_88 * 0x120] & 2) == 0)) {
            local_80[local_90] = *(int *)(&DAT_006aba54 + local_88 * 0x120);
            local_90 = local_90 + 1;
          }
        }
        if (g_IsAiThinking != 1) {
          Pic_Load_004509e8(0,(int)local_80,local_90,s_Opponent_s_Hand_0052eb04,0);
        }
      }
      local_90 = 0;
      do {
        local_94 = FUN_0040a1d2((&g_PlayerActiveCardCount)[arg_4]);
        local_90 = local_90 + 1;
        if (0x3e6 < local_90) break;
      } while (((*(int *)(&g_CardSlot_CardId + arg_4 * 0x5b20 + local_94 * 0x120) == -1) ||
               (((&g_MasterCardColorTable)
                 [*(int *)(&g_CardSlot_CardId + arg_4 * 0x5b20 + local_94 * 0x120) * 0x34] & 2) == 0
               )) || (((&g_CardSlot_Flags)[arg_4 * 0x5b20 + local_94 * 0x120] & 2) != 0));
      if (local_90 < 999) {
        local_8 = 1;
      }
      else {
        local_8 = 0;
        local_88 = 0;
        while ((local_88 < (int)(&g_PlayerActiveCardCount)[arg_4] && (local_8 == 0))) {
          if ((*(int *)(&g_CardSlot_CardId + local_88 * 0x120 + arg_4 * 0x5b20) != -1) &&
             ((((&g_MasterCardColorTable)
                [*(int *)(&g_CardSlot_CardId + local_88 * 0x120 + arg_4 * 0x5b20) * 0x34] & 2) != 0
              && (((&g_CardSlot_Flags)[local_88 * 0x120 + arg_4 * 0x5b20] & 2) == 0)))) {
            local_8 = 1;
            local_94 = local_88;
          }
          local_88 = local_88 + 1;
        }
      }
      if (local_8 != 0) {
        if (g_IsAiThinking != 1) {
          Magic_UpkeepPhase(0x19);
        }
        if (g_IsAiThinking != 1) {
          Ai_Subsystem_004cc56d
                    (arg_1,arg_1,arg_2,arg_4,local_94,s_Randomly_chose_this_creature_to_d_0052eb14,0
                    );
        }
        Pic_Subsystem_0044913a(arg_4,local_94);
        *(undefined4 *)(&g_CardSlot_CardId + arg_4 * 0x5b20 + local_94 * 0x120) = 0xffffffff;
        (&DAT_006b3008)[arg_4] = (&DAT_006b3008)[arg_4] + -1;
      }
    }
  }
  return;
}


