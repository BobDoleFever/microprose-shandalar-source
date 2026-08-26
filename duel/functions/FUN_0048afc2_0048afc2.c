/*
 * Decompiled function: FUN_0048afc2
 * Entry Point: 0048afc2
 * Size: 261 bytes
 */
#include "duel.h"


undefined4 FUN_0048afc2(int arg_1)

{
  int iVar1;
  undefined4 uVar2;
  int local_8;
  
  DAT_006826b0 = 0;
  DAT_006c1218 = 0;
  for (local_8 = 0; local_8 < (int)(&DAT_00666408)[arg_1]; local_8 = local_8 + 1) {
    iVar1 = FUN_0048a33f(arg_1,local_8);
    if (iVar1 != 0) {
      if (((&DAT_006826cc)[local_8 * 0x120 + arg_1 * 0x5b20] & 4) == 0) {
        if (((&DAT_006826cd)[local_8 * 0x120 + arg_1 * 0x5b20] & 0x80) != 0) {
          iVar1 = FUN_0048ad82(arg_1,local_8);
          if (iVar1 != 0) {
            DAT_006c1218 = DAT_006c1218 + 1;
          }
        }
      }
      else {
        DAT_006826b0 = 1;
      }
    }
  }
  if ((DAT_006826b0 == 0) && (DAT_006c1218 == 0)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


