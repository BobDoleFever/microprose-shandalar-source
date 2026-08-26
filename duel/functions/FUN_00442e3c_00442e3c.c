/*
 * Decompiled function: FUN_00442e3c
 * Entry Point: 00442e3c
 * Size: 87 bytes
 */
#include "duel.h"


INT_PTR FUN_00442e3c(int arg_1,undefined4 arg_2,INT_PTR arg_3)

{
  undefined4 local_10;
  INT_PTR local_c;
  
  if (arg_1 == 0) {
    local_10 = arg_2;
    local_c = arg_3;
    arg_3 = DialogBoxParamA(DAT_00664680,(LPCSTR)0xe5,DAT_00618990,UI_DialogProc_00442e98,
                            (LPARAM)&local_10);
  }
  return arg_3;
}


