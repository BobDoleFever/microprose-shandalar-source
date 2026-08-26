/*
 * Decompiled function: FUN_00446c16
 * Entry Point: 00446c16
 * Size: 252 bytes
 */
#include "duel.h"


int FUN_00446c16(int arg_1,int arg_2,int arg_3,int arg_4,undefined4 arg_5,undefined4 arg_6)

{
  int iVar1;
  INT_PTR IVar2;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  KillTimer(DAT_00618990,DAT_00663610);
  if (arg_4 == 0xff) {
    arg_4 = -1;
  }
  if ((arg_1 != -1) && (arg_2 != -1)) {
    iVar1 = FUN_00447184(arg_1,arg_2);
    if (iVar1 == -1) {
      FUN_004457a2();
    }
  }
  if ((arg_3 != -1) && (arg_4 != -1)) {
    iVar1 = FUN_00447184(arg_3,arg_4);
    if (iVar1 == -1) {
      FUN_004457a2();
    }
  }
  local_20 = arg_1;
  local_1c = arg_2;
  local_18 = arg_3;
  local_14 = arg_4;
  local_10 = arg_5;
  local_c = arg_6;
  IVar2 = DialogBoxParamA(DAT_00664680,(LPCSTR)0xdf,DAT_00618990,Palette_Subsystem_0049608e,
                          (LPARAM)&local_20);
  if (IVar2 == 0) {
    iVar1 = -1;
  }
  else {
    iVar1 = IVar2 + -1;
  }
  return iVar1;
}


