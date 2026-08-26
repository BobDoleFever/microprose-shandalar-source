/*
 * Decompiled function: FUN_00443000
 * Entry Point: 00443000
 * Size: 94 bytes
 */
#include "duel.h"


INT_PTR FUN_00443000(int arg_1,undefined4 arg_2,INT_PTR arg_3)

{
  undefined4 local_14;
  INT_PTR local_10;
  undefined4 local_c;
  
  if (arg_1 == 0) {
    local_14 = arg_2;
    local_10 = arg_3;
    local_c = 0;
    arg_3 = DialogBoxParamA(DAT_00664680,(LPCSTR)0xdc,DAT_00618990,UI_DialogProc_00443063,
                            (LPARAM)&local_14);
  }
  return arg_3;
}


