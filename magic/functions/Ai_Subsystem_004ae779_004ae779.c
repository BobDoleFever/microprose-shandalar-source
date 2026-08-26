/*
 * Decompiled function: Ai_Subsystem_004ae779
 * Entry Point: 004ae779
 * Size: 298 bytes
 */
#include "magic.h"


void Ai_Subsystem_004ae779(int arg_1)

{
  int iVar1;
  char local_918 [300];
  undefined4 local_7ec;
  undefined4 local_7e8;
  undefined4 local_7e4;
  undefined4 local_7e0 [500];
  undefined4 local_10;
  undefined4 local_c;
  
  KillTimer(g_MainAppHwnd,DAT_006fdbd4);
  iVar1 = Ai_Subsystem_004b72d0(local_7e0,0);
  if (iVar1 == 0) {
    local_c = 0xffffffff;
  }
  else {
    local_c = local_7e0[0];
  }
  iVar1 = Ai_Subsystem_004b72d0(local_7e0,1);
  if (iVar1 == 0) {
    local_10 = 0xffffffff;
  }
  else {
    local_10 = local_7e0[0];
  }
  if (arg_1 == 0) {
    Ai_Subsystem_004b6f49(local_918);
    strcat(local_918,&DAT_0052d130);
  }
  else if (arg_1 == 1) {
    strcpy(local_918,s_You_won__0052d138);
  }
  else {
    strcpy(local_918,s_The_duel_is_a_draw_0052d144);
  }
  local_7ec = 0;
  local_7e8 = local_c;
  local_7e4 = local_10;
  DialogBoxParamA(g_AppHInstance,(LPCSTR)0xf6,g_MainAppHwnd,Ai_DuelMainWndProc,(LPARAM)local_918);
  return;
}


