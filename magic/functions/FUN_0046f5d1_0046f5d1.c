/*
 * Decompiled function: FUN_0046f5d1
 * Entry Point: 0046f5d1
 * Size: 1130 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0046f5d1(int arg_1)

{
  int iVar1;
  int iVar2;
  int local_10;
  int local_c;
  byte local_8;
  
  DAT_006fe408 = 0;
  FUN_0047624f(arg_1,0xcf,s_Draw_a_card_Phase_00525af8,1);
  if (DAT_006fe408 == 0) {
    if (g_CurrentTurnPhase == arg_1) {
      if (DAT_0052effc == -1) {
        local_c = *(int *)(&DAT_0069e730 + arg_1 * 2000);
        if (local_c != -1) {
          Pic_Subsystem_004523fd(arg_1,0);
          local_c = Pic_Subsystem_00451291(arg_1,local_c);
        }
      }
      else {
        iVar1 = FUN_0040a02a(DAT_0052effc);
        local_c = Pic_Subsystem_00451291(arg_1,iVar1);
      }
      if ((local_c == -1) || (*(int *)(&g_CardSlot_CardId + local_c * 0x120 + arg_1 * 0x5b20) == -1)
         ) {
        if (g_IsAiThinking == 1) {
          (&g_PlayerCreatureCount)[g_CurrentTurnPhase] = 0;
          (&g_PlayerCreatureCount)[1 - g_CurrentTurnPhase] = 0x14;
        }
        else {
          Ai_Util_004cc42d(s_No_more_cards__you_lose__00525b24);
          Sleep(0x9c4);
          Ai_Util_004cc42d(&DAT_00525b40);
          Pic_Util_00450975(0);
        }
      }
      else {
        Ai_Subsystem_004cc9c5(0,0x30);
        if (g_IsAiThinking != 1) {
          if (DAT_0063ee18 == 0) {
            Ai_Subsystem_004cc50a
                      (*(undefined4 *)(&g_CardSlot_CardId + local_c * 0x120 + arg_1 * 0x5b20),0xf6,
                       s_Draw_Card_00525b18);
          }
          else {
            Ai_Subsystem_004b137d
                      (*(undefined4 *)(&g_CardSlot_CardId + local_c * 0x120 + arg_1 * 0x5b20),arg_1,
                       local_c);
          }
        }
      }
    }
    else {
      if (DAT_0052eff8 == -1) {
        iVar1 = FUN_0040a1d2(3);
        if (iVar1 == 0) {
          local_8 = 1;
        }
        else if (iVar1 == 1) {
          local_8 = 2;
        }
        else if (iVar1 == 2) {
          local_8 = 0x3c;
        }
        do {
          iVar1 = FUN_0040a1d2(g_MasterCardCount);
          local_10 = Pic_Subsystem_004521a6
                               ((int)(char)(&DAT_0051aebe)[iVar1 * 0x34],DAT_006b2d64,DAT_00696a18);
          if ((local_10 != 0) && (iVar2 = Pic_Subsystem_00452551(iVar1), DAT_00695df0 < iVar2)) {
            local_10 = 0;
          }
        } while (((local_10 == 0) || ((local_8 & (&g_MasterCardColorTable)[iVar1 * 0x34]) == 0)) ||
                (((&DAT_0051aed0)[iVar1 * 0x34] & 0x40) != 0));
        local_c = Pic_Subsystem_00451291(arg_1,iVar1);
      }
      else if (*(int *)(&DAT_0069e730 + arg_1 * 2000) == -1) {
        local_c = -1;
      }
      else {
        local_c = Pic_Subsystem_00451291(arg_1,*(int *)(&DAT_0069e730 + arg_1 * 2000));
        if (local_c != -1) {
          Pic_Subsystem_004523fd(arg_1,0);
        }
      }
      if (local_c == -1) {
        if (g_IsAiThinking == 1) {
          (&g_PlayerCreatureCount)[1 - g_CurrentTurnPhase] = 0;
          (&g_PlayerCreatureCount)[g_CurrentTurnPhase] = 0x14;
        }
        else {
          Ai_Util_004cc42d(s_No_more_cards__opponent_loses__00525b44);
          Sleep(0x9c4);
          Ai_Util_004cc42d(&DAT_00525b64);
          Pic_Util_00450975(1);
        }
      }
      Ai_Subsystem_004cc9c5(0,0x30);
    }
    (&DAT_006b3008)[arg_1] = (&DAT_006b3008)[arg_1] + 1;
    _DAT_006b3038 = _DAT_006b3038 + 1;
    if ((g_IsAiThinking != 1) && (local_c != -1)) {
      Magic_UpkeepPhase(2);
    }
    if (local_c != -1) {
      *(uint *)(&g_CardSlot_Flags + local_c * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + local_c * 0x120 + arg_1 * 0x5b20) | 1;
    }
  }
  else {
    local_c = 0;
  }
  return local_c;
}


