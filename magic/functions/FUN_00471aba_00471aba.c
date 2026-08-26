/*
 * Decompiled function: FUN_00471aba
 * Entry Point: 00471aba
 * Size: 262 bytes
 */
#include "magic.h"


undefined4 FUN_00471aba(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  
  DAT_0068078c = 1;
  Magic_CombatPhase(arg_1,arg_2,0x7e,arg_3,0);
  if (g_ActivePlayer == 1) {
    Magic_DiscardToHandSize();
    uVar1 = 0;
  }
  else {
    if (g_IsAiThinking != 1) {
      FUN_004755fd();
      if (g_CurrentTurnPhase != DAT_006a4b5c) {
        strcpy(&g_OverworldWorldState,&DAT_00695e10);
        strcat(&g_OverworldWorldState,s_processes____00525c88);
        Ai_Subsystem_004b574d(arg_1,arg_2,-1,-1,&g_OverworldWorldState,0);
      }
    }
    *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x100;
    strcpy(&g_OverworldWorldState,s_Process_00525c98);
    Ai_Subsystem_004b90de(arg_1,arg_2);
    uVar1 = Magic_EndTurnPhase();
  }
  DAT_0068078c = 0;
  return uVar1;
}


