/*
 * Decompiled function: FUN_004f589e
 * Entry Point: 004f589e
 * Size: 72 bytes
 */
#include "magic.h"


bool FUN_004f589e(HWND hwnd)

{
  int iVar1;
  CHAR local_68 [100];
  
  GetClassNameA(hwnd,local_68,100);
  iVar1 = strcmp(local_68,s_Button_0053025c);
  return iVar1 == 0;
}


