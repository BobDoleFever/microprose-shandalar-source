/*
 * Decompiled function: UI_DialogProc_004f2e60
 * Entry Point: 004f2e60
 * Size: 246 bytes
 */
#include "magic.h"


undefined4 UI_DialogProc_004f2e60(char *str_1,char *str_2,undefined4 *arg_3)

{
  INT_PTR IVar1;
  undefined4 local_21c;
  char local_214 [261];
  char local_10f [263];
  undefined4 local_8;
  
  local_8 = *arg_3;
  IVar1 = DialogBoxParamA(g_AppHInstance,(LPCSTR)0xdd,g_MainAppHwnd,UI_CreateWindow_004f2f56,
                          (LPARAM)local_214);
  if (IVar1 == -1) {
    MessageBoxA(g_MainAppHwnd,s_Couldn_t_bring_up_the_Load_Decks_00530124,&DAT_00530120,0);
    local_21c = 0;
  }
  else if (IVar1 == 1) {
    strcpy(str_1,local_214);
    strcpy(str_2,local_10f);
    *arg_3 = local_8;
    DAT_0068a648 = 0;
    local_21c = 1;
  }
  else if (IVar1 == 0) {
    DAT_0068a648 = 1;
    local_21c = 1;
  }
  return local_21c;
}


