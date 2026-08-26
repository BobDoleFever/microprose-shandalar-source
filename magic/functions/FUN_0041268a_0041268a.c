/*
 * Decompiled function: FUN_0041268a
 * Entry Point: 0041268a
 * Size: 437 bytes
 */
#include "magic.h"


bool FUN_0041268a(int arg_1,int arg_2,int arg_3)

{
  bool bVar1;
  int local_8;
  
  if (arg_3 == 0x73) {
    if ((g_ActivePlayerPriority == arg_1) && ((&g_PlayerCreatureCount)[arg_1] == 1)) {
      bVar1 = false;
    }
    else {
      bVar1 = 0 < (int)(&g_PlayerCreatureCount)[arg_1];
    }
  }
  else {
    if (arg_3 == 0x6d) {
      bVar1 = false;
      while ((!bVar1 && (g_ActivePlayer != 1))) {
        local_8 = Ai_Subsystem_004cc8de(arg_1,s_Spend_how_much_life_for_generic_m_005196c4,1);
        if (local_8 < 0) {
          g_ActivePlayer = 1;
        }
        else if ((int)(&g_PlayerCreatureCount)[arg_1] < local_8) {
          if (g_IsAiThinking != 1) {
            Ai_Util_004cc42d(s_Illegal_Amount___must_be_between_005196ec);
            Sleep(2000);
            Ai_Util_004cc42d(&DAT_0051971c);
          }
        }
        else {
          bVar1 = true;
        }
      }
      if (g_ActivePlayer != 1) {
        FUN_0040d901(arg_1,0,local_8);
        (&g_PlayerCreatureCount)[arg_1] = (&g_PlayerCreatureCount)[arg_1] - local_8;
      }
    }
    if ((arg_3 == 0x22) || (arg_3 == 199)) {
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
    if (((arg_3 == 0x7f) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
      FUN_0040d7e9(arg_1,0,(&g_PlayerCreatureCount)[arg_1]);
    }
    bVar1 = false;
  }
  return bVar1;
}


