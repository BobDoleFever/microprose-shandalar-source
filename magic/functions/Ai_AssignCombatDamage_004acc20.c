/*
 * Decompiled function: Ai_AssignCombatDamage
 * Entry Point: 004acc20
 * Size: 538 bytes
 */
#include "magic.h"


undefined4
Ai_AssignCombatDamage
          (undefined4 *arg_1,uint *arg_2,uint arg_3,int arg_4,uint arg_5,uint arg_6,undefined4 arg_7
          ,int arg_8,undefined4 arg_9)

{
  undefined4 uVar1;
  int iVar2;
  uint local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  undefined4 local_18;
  uint local_10;
  int local_c;
  INT_PTR local_8;
  
  if ((arg_1 == (undefined4 *)0x0) || (arg_2 == (uint *)0x0)) {
    uVar1 = 0;
  }
  else {
    if (arg_4 == 0) {
      local_10 = arg_3;
    }
    else {
      iVar2 = Ai_Subsystem_004b7d38(s_Start_of_duel_0052ce9c);
      local_10 = (uint)(iVar2 == 0);
    }
    if (DAT_006a2858 == 0) {
      local_c = 1;
    }
    else {
      if (local_10 == 0) {
        FUN_00409b2c(1,1);
        UpdateWindow(DAT_006a49f0);
      }
      local_8 = DialogBoxParamA(g_AppHInstance,(LPCSTR)0xf4,g_MainAppHwnd,Ai_DuelDialogProc,
                                (LPARAM)&local_10);
      FUN_00409b2c(1,0);
    }
    Pic_Subsystem_00452276(1);
    Pic_Subsystem_00452276(0);
    Ai_Subsystem_004cc9c5(0,0x30);
    if (((local_10 == 1) && (local_c != 0)) || ((local_10 == 0 && (local_c == 0)))) {
      local_2c = 1;
    }
    else {
      local_2c = 0;
    }
    local_28 = Ai_Subsystem_004cbd67(arg_5);
    local_24 = Ai_Subsystem_004cbd67(arg_6);
    local_20 = arg_7;
    local_1c = arg_8;
    local_18 = arg_9;
    if (arg_8 != 0) {
      DAT_00695e90 = 1;
      Pic_Subsystem_0044cfe4(DAT_006fe400);
    }
    local_8 = DialogBoxParamA(g_AppHInstance,(LPCSTR)0xe3,g_MainAppHwnd,Ai_StartDuelWndProc,
                              (LPARAM)&local_2c);
    local_30 = (uint)(local_8 != 0);
    *arg_1 = local_2c;
    *arg_2 = local_30;
    DAT_00695e90 = 0;
    Pic_Subsystem_0044cfe4(DAT_006fe400);
    if (local_30 != 0) {
      PostMessageA(DAT_0069e720,0x40c,0,0);
    }
    UpdateWindow(g_MainAppHwnd);
    uVar1 = 1;
  }
  return uVar1;
}


