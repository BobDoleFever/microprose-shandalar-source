/*
 * Decompiled function: Palette_Subsystem_004a62a0
 * Entry Point: 004a62a0
 * Size: 208 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int Palette_Subsystem_004a62a0(undefined4 arg_1,int arg_2,int arg_3)

{
  INT_PTR IVar1;
  int local_10;
  int local_c;
  
  _DAT_0052c638 = arg_1;
  if (arg_2 != -1) {
    _DAT_0052c630 = arg_2;
  }
  if (arg_3 != -1) {
    _DAT_0052c634 = arg_3;
  }
  IVar1 = DialogBoxParamA(g_AppHInstance,(LPCSTR)0xe0,g_MainAppHwnd,Palette_Subsystem_004a6370,
                          0x52c630);
  if (IVar1 == -1) {
    local_c = -1;
  }
  else {
    local_c = -1;
    local_10 = 0;
    while ((local_10 < g_MasterCardCount && (local_c == -1))) {
      if (*(int *)(&g_MasterCardTypeTable + local_10 * 0x34) == IVar1) {
        local_c = local_10;
      }
      local_10 = local_10 + 1;
    }
  }
  return local_c;
}


