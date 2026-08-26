/*
 * Decompiled function: FUN_0048ed18
 * Entry Point: 0048ed18
 * Size: 377 bytes
 */
#include "duel.h"


undefined4 FUN_0048ed18(int arg1,int arg2)

{
  undefined4 uVar1;
  int iVar2;
  int local_c;
  uint local_8;
  
  if (((&DAT_006826cc)[arg2 * 0x120 + arg1 * 0x5b20] & 0x10) == 0) {
    uVar1 = 0;
  }
  else {
    local_c = 0;
    for (local_8 = 1; (int)local_8 < 7; local_8 = local_8 + 1) {
      if ((&DAT_006827cc)[local_8 + arg1 * 0x5b20 + arg2 * 0x120] != '\0') {
        iVar2 = FUN_0049b309(arg1,local_8,
                             (int)(char)(&DAT_006827cc)[local_8 + arg1 * 0x5b20 + arg2 * 0x120]);
        if (iVar2 == 0) {
          return 0;
        }
        local_c = local_c + (char)(&DAT_006827cc)[local_8 + arg1 * 0x5b20 + arg2 * 0x120];
      }
    }
    iVar2 = FUN_0049b309(arg1,7,(char)(&DAT_006827cc)[arg2 * 0x120 + arg1 * 0x5b20] + local_c);
    if (iVar2 == 0) {
      uVar1 = 0;
    }
    else {
      FUN_0048c907(arg1,arg2,0x88,1 - arg1,0xffffffff);
      if (DAT_0068edd8 == 0) {
        uVar1 = 1;
      }
      else {
        uVar1 = 0;
      }
    }
  }
  return uVar1;
}


