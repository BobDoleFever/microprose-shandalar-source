/*
 * Decompiled function: Ai_ChooseBlockers
 * Entry Point: 004ac940
 * Size: 575 bytes
 */
#include "magic.h"


undefined4 Ai_ChooseBlockers(int arg1,int arg2)

{
  char *pcVar1;
  int local_14;
  int local_10;
  uint local_c;
  int local_8;
  
  strcpy(&g_OverworldWorldState,&DAT_0052ce58);
  pcVar1 = _itoa(arg2,&DAT_00553190,10);
  strcat(&g_OverworldWorldState,pcVar1);
  strcat(&g_OverworldWorldState,&DAT_0052ce5c);
  pcVar1 = _itoa(g_PlayerCreatureCount,&DAT_00553190,10);
  strcat(&g_OverworldWorldState,pcVar1);
  strcat(&g_OverworldWorldState,&DAT_0052ce60);
  pcVar1 = _itoa(DAT_006a4a04,&DAT_00553190,10);
  strcat(&g_OverworldWorldState,pcVar1);
  strcat(&g_OverworldWorldState,s_____0052ce64);
  local_8 = 0;
  while( true ) {
    if (arg1 == 0) {
      local_10 = DAT_0054be44;
    }
    else {
      local_10 = DAT_00556928;
    }
    if (local_10 <= local_8) break;
    if (arg1 == 0) {
      local_c = *(uint *)(&DAT_0054fc38 + local_8 * 4);
    }
    else {
      local_c = *(uint *)(&DAT_0054f838 + local_8 * 4);
    }
    if (local_c != 0xffffffff) {
      if ((local_c & 0x1000) != 0) {
        strcat(&g_OverworldWorldState,s_Cast_0052ce6c);
      }
      if ((local_c & 0x2000) != 0) {
        strcat(&g_OverworldWorldState,&DAT_0052ce74);
      }
      if ((local_c & 0x4000) != 0) {
        strcat(&g_OverworldWorldState,s____target_0052ce7c);
      }
      if ((local_c & 0x100) == 0) {
        strcat(&g_OverworldWorldState,&DAT_0052ce88);
      }
      if ((char)local_c == -1) {
        strcat(&g_OverworldWorldState,s_Player_0052ce8c);
      }
      else {
        if (arg1 == 0) {
          local_14 = *(int *)(&DAT_00553840 + local_8 * 4);
        }
        else {
          local_14 = *(int *)(&DAT_00553440 + local_8 * 4);
        }
        strcat(&g_OverworldWorldState,s_Swamp_0051aea9 + local_14 * 0x34);
      }
      strcat(&g_OverworldWorldState,&DAT_0052ce94);
    }
    local_8 = local_8 + 1;
  }
  Ai_Subsystem_004cc56d(0,0,0,-1,-1,&g_OverworldWorldState,0);
  return 0;
}


