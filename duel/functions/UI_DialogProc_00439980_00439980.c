/*
 * Decompiled function: UI_DialogProc_00439980
 * Entry Point: 00439980
 * Size: 246 bytes
 */
#include "duel.h"


undefined4 UI_DialogProc_00439980(uint *arg_1,uint *arg_2,undefined4 *arg_3)

{
  INT_PTR IVar1;
  undefined4 local_21c;
  uint local_214 [65];
  uint local_10f [65];
  undefined4 local_8;
  
  local_8 = *arg_3;
  IVar1 = DialogBoxParamA(DAT_00664680,(LPCSTR)0xdd,DAT_00618990,Palette_Subsystem_00496497,
                          (LPARAM)local_214);
  if (IVar1 == -1) {
    MessageBoxA(DAT_00618990,s_Couldn_t_bring_up_the_Load_Decks_004f76f0,&DAT_004f76ec,0);
    local_21c = 0;
  }
  else if (IVar1 == 1) {
    Mem_AllocOrFree_004d9630(arg_1,local_214);
    Mem_AllocOrFree_004d9630(arg_2,local_10f);
    *arg_3 = local_8;
    DAT_00601578 = 0;
    local_21c = 1;
  }
  else if (IVar1 == 0) {
    DAT_00601578 = 1;
    local_21c = 1;
  }
  return local_21c;
}


