/*
 * Decompiled function: FUN_00482d6f
 * Entry Point: 00482d6f
 * Size: 103 bytes
 */
#include "magic.h"


void FUN_00482d6f(HWND hwnd)

{
  char local_6c [100];
  int local_8;
  
  Ai_Subsystem_004b74b1(&local_8,(undefined4 *)0x0);
  if (local_8 == 0) {
    strcpy(local_6c,s_Your_attack_00526de8);
  }
  else {
    Ai_Subsystem_004b6f49(local_6c);
    strcat(local_6c,s__s_attack_00526df4);
  }
  SetWindowTextA(hwnd,local_6c);
  return;
}


