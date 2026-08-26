/*
 * Decompiled function: FUN_0048c8b2
 * Entry Point: 0048c8b2
 * Size: 180 bytes
 */
#include "magic.h"


uint FUN_0048c8b2(char *str_1,int arg2)

{
  uint uVar1;
  
  strcpy(str_1 + 9,&DAT_00527c90);
  if (arg2 == 0) {
    uVar1 = FUN_0048ce07(str_1);
  }
  else {
    DAT_0054aab8 = _open(str_1,0x8000);
    if (DAT_0054aab8 == -1) {
      strcat(&g_OverworldWorldState,s__EMPTY__00527c98);
    }
    else {
      strcat(&g_OverworldWorldState,&DAT_00527c94);
    }
    _close(DAT_0054aab8);
    uVar1 = (uint)(DAT_0054aab8 != -1);
  }
  return uVar1;
}


