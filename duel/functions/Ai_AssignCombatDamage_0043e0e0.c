/*
 * Decompiled function: Ai_AssignCombatDamage
 * Entry Point: 0043e0e0
 * Size: 538 bytes
 */
#include "duel.h"


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
      iVar2 = FUN_004491fe(s_Start_of_duel_004f79bc);
      local_10 = (uint)(iVar2 == 0);
    }
    if (DAT_0066aaf0 == 0) {
      local_c = 1;
    }
    else {
      if (local_10 == 0) {
        FUN_0043753a(1,1);
        UpdateWindow(DAT_00617438);
      }
      local_8 = DialogBoxParamA(DAT_00664680,(LPCSTR)0xf4,DAT_00618990,Ai_DuelDialogProc,
                                (LPARAM)&local_10);
      FUN_0043753a(1,0);
    }
    FUN_004d7946(1);
    FUN_004d7946(0);
    FUN_00451482(0,0x30);
    if (((local_10 == 1) && (local_c != 0)) || ((local_10 == 0 && (local_c == 0)))) {
      local_2c = 1;
    }
    else {
      local_2c = 0;
    }
    local_28 = CardIDFromType(arg_5);
    local_24 = CardIDFromType(arg_6);
    local_20 = arg_7;
    local_1c = arg_8;
    local_18 = arg_9;
    if (arg_8 != 0) {
      DAT_0060cc60 = 1;
      FUN_004baa8b(DAT_00663df4);
    }
    local_8 = DialogBoxParamA(DAT_00664680,(LPCSTR)0xe3,DAT_00618990,Ai_StartDuelWndProc,
                              (LPARAM)&local_2c);
    local_30 = (uint)(local_8 != 0);
    *arg_1 = local_2c;
    *arg_2 = local_30;
    DAT_0060cc60 = 0;
    FUN_004baa8b(DAT_00663df4);
    if (local_30 != 0) {
      PostMessageA(DAT_006152b0,0x40c,0,0);
    }
    UpdateWindow(DAT_00618990);
    uVar1 = 1;
  }
  return uVar1;
}


