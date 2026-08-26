/*
 * Decompiled function: FUN_00442839
 * Entry Point: 00442839
 * Size: 137 bytes
 */
#include "duel.h"


void FUN_00442839(uint arg_1,int arg_2,int arg_3)

{
  BOOL BVar1;
  WPARAM WVar2;
  int *lParam;
  LPARAM lParam_00;
  int local_c;
  int local_8;
  
  local_c = arg_2;
  local_8 = arg_3;
  BVar1 = IsWindowVisible(DAT_006152e0);
  if (BVar1 != 0) {
    if ((arg_2 == -1) || (arg_3 == -1)) {
      lParam_00 = 0;
      WVar2 = CardIDFromType(arg_1);
      SendMessageA(DAT_006152e0,0x401,WVar2,lParam_00);
    }
    else {
      lParam = &local_c;
      WVar2 = CardIDFromType(arg_1);
      SendMessageA(DAT_006152e0,0x401,WVar2,(LPARAM)lParam);
    }
  }
  return;
}


