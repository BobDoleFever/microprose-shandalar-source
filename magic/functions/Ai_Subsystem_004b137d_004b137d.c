/*
 * Decompiled function: Ai_Subsystem_004b137d
 * Entry Point: 004b137d
 * Size: 137 bytes
 */
#include "magic.h"


void Ai_Subsystem_004b137d(uint arg_1,int arg_2,int arg_3)

{
  BOOL BVar1;
  WPARAM WVar2;
  int *lParam;
  LPARAM lParam_00;
  int local_c;
  int local_8;
  
  local_c = arg_2;
  local_8 = arg_3;
  BVar1 = IsWindowVisible(DAT_0069f744);
  if (BVar1 != 0) {
    if ((arg_2 == -1) || (arg_3 == -1)) {
      lParam_00 = 0;
      WVar2 = Ai_Subsystem_004cbd67(arg_1);
      SendMessageA(DAT_0069f744,0x401,WVar2,lParam_00);
    }
    else {
      lParam = &local_c;
      WVar2 = Ai_Subsystem_004cbd67(arg_1);
      SendMessageA(DAT_0069f744,0x401,WVar2,(LPARAM)lParam);
    }
  }
  return;
}


