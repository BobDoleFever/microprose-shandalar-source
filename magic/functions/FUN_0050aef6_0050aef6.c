/*
 * Decompiled function: FUN_0050aef6
 * Entry Point: 0050aef6
 * Size: 199 bytes
 */
#include "magic.h"


undefined4 FUN_0050aef6(int arg1,int arg2)

{
  int iVar1;
  undefined4 local_8;
  
  iVar1 = arg1 - DAT_00641010;
  if (arg2 - DAT_00641014 < 1) {
    strcat(&g_OverworldWorldState,s_North_005324d0 + ((0 < iVar1) - 1 & 8));
    if (iVar1 < 1) {
      local_8 = 3;
    }
    else {
      local_8 = 0;
    }
  }
  else {
    strcat(&g_OverworldWorldState,&DAT_005324c0 + ((0 < iVar1) - 1 & 8));
    if (iVar1 < 1) {
      local_8 = 2;
    }
    else {
      local_8 = 1;
    }
  }
  return local_8;
}


