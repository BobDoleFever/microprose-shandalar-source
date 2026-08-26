/*
 * Decompiled function: FUN_0048f123
 * Entry Point: 0048f123
 * Size: 142 bytes
 */
#include "duel.h"


void FUN_0048f123(void)

{
  int iVar1;
  int local_c;
  int local_8;
  
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    for (local_c = 0; local_c < (int)(&DAT_00666408)[local_8]; local_c = local_c + 1) {
      iVar1 = FUN_0048a33f(local_8,local_c);
      if (iVar1 != 0) {
        *(undefined4 *)(&DAT_006827d4 + local_c * 0x120 + local_8 * 0x5b20) = 0;
      }
    }
  }
  return;
}


