/*
 * Decompiled function: FUN_0049e65c
 * Entry Point: 0049e65c
 * Size: 157 bytes
 */
#include "duel.h"


WPARAM FUN_0049e65c(HWND hwnd,char *str_2)

{
  int iVar1;
  char local_34 [40];
  WPARAM local_c;
  WPARAM local_8;
  
  local_c = SendDlgItemMessageA(hwnd,0x462,0x146,0,0);
  for (local_8 = 0; (int)local_8 < (int)local_c; local_8 = local_8 + 1) {
    SendDlgItemMessageA(hwnd,0x462,0x148,local_8,(LPARAM)local_34);
    iVar1 = _strcmp(str_2,local_34);
    if (iVar1 == 0) break;
  }
  if (local_8 == local_c) {
    local_8 = 0;
  }
  return local_8;
}


