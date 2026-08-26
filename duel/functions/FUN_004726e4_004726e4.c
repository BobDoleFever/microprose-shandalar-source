/*
 * Decompiled function: FUN_004726e4
 * Entry Point: 004726e4
 * Size: 72 bytes
 */
#include "duel.h"


bool FUN_004726e4(HWND hwnd)

{
  int iVar1;
  CHAR local_68 [100];
  
  GetClassNameA(hwnd,local_68,100);
  iVar1 = _strcmp(local_68,s_Button_004f985c);
  return iVar1 == 0;
}


