/*
 * Decompiled function: FUN_00439980
 * Entry Point: 00439980
 * Size: 246 bytes
 */
#include "duel.h"


undefined4 FUN_00439980(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  INT_PTR IVar1;
  undefined4 local_21c;
  undefined1 local_214 [261];
  undefined1 local_10f [263];
  undefined4 local_8;
  
  local_8 = *param_3;
  IVar1 = DialogBoxParamA(DAT_00664680,(LPCSTR)0xdd,DAT_00618990,FUN_00439a76,(LPARAM)local_214);
  if (IVar1 == -1) {
    MessageBoxA(DAT_00618990,s_Couldn_t_bring_up_the_Load_Decks_004f76f0,&DAT_004f76ec,0);
    local_21c = 0;
  }
  else if (IVar1 == 1) {
    FUN_004d9630(param_1,local_214);
    FUN_004d9630(param_2,local_10f);
    *param_3 = local_8;
    DAT_00601578 = 0;
    local_21c = 1;
  }
  else if (IVar1 == 0) {
    DAT_00601578 = 1;
    local_21c = 1;
  }
  return local_21c;
}


