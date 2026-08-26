/*
 * Decompiled function: FUN_004b8160
 * Entry Point: 004b8160
 * Size: 209 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_004b8160(undefined4 arg_1,int arg_2,int arg_3)

{
  INT_PTR IVar1;
  int local_10;
  int local_c;
  
  _DAT_005070e0 = arg_1;
  if (arg_2 != -1) {
    _DAT_005070d8 = arg_2;
  }
  if (arg_3 != -1) {
    _DAT_005070dc = arg_3;
  }
  IVar1 = DialogBoxParamA(DAT_00664680,(LPCSTR)0xe0,DAT_00618990,UI_DialogProc_004b8231,0x5070d8);
  if (IVar1 == -1) {
    local_c = -1;
  }
  else {
    local_c = -1;
    local_10 = 0;
    while ((local_10 < DAT_00665ed0 && (local_c == -1))) {
      if (*(int *)(&DAT_004ff590 + local_10 * 0x34) == IVar1) {
        local_c = local_10;
      }
      local_10 = local_10 + 1;
    }
  }
  return local_c;
}


