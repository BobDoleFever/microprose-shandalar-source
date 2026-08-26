/*
 * Decompiled function: Card_VesuvanDoppelganger_Upkeep
 * Entry Point: 004d2c17
 * Size: 273 bytes
 */
#include "magic.h"


undefined4 Card_VesuvanDoppelganger_Upkeep(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  
  if (((arg_3 == 2) && (arg_2 == g_OverworldMapGrid)) && (arg_1 == g_OverworldPlayerCoordX)) {
    g_ActivePalette = g_ActivePalette | 1;
  }
  if ((((arg_3 == 4) && (arg_2 == g_OverworldMapGrid)) && (arg_1 == g_OverworldPlayerCoordX)) ||
     (arg_3 == 199)) {
    if (g_IsAiThinking != 1) {
      strcpy(&g_OverworldWorldState,s_Mimic_0052e9ac);
      Ai_Subsystem_004b90de(arg_1,arg_2);
      strcat(&g_OverworldWorldState,s___Mimic_different_creature__0052e9b4);
    }
    iVar1 = Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,-1,-1,&g_OverworldWorldState,0);
    if (iVar1 != 0) {
      Card_VesuvanDoppelganger_Copy(arg_1,arg_2,0x6c);
    }
  }
  return 0;
}


