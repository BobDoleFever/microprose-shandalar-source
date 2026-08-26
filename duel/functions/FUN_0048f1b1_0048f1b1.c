/*
 * Decompiled function: FUN_0048f1b1
 * Entry Point: 0048f1b1
 * Size: 361 bytes
 */
#include "duel.h"


void FUN_0048f1b1(void)

{
  int iVar1;
  int local_10;
  int local_c;
  int local_8;
  
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    for (local_10 = 0; local_10 < (int)(&DAT_00666408)[local_8]; local_10 = local_10 + 1) {
      if (((&DAT_006827d4)[local_8 * 0x5b20 + local_10 * 0x120] & 4) == 0) {
        iVar1 = FUN_0048a33f(local_8,local_10);
        if (iVar1 != 0) {
          for (local_c = 0; local_c < 7; local_c = local_c + 1) {
            (&DAT_006827cc)[local_c + local_10 * 0x120 + local_8 * 0x5b20] = 0;
            (&DAT_006827d8)[local_c + local_10 * 0x120 + local_8 * 0x5b20] =
                 (&DAT_006827cc)[local_c + local_10 * 0x120 + local_8 * 0x5b20];
          }
          *(undefined4 *)(&DAT_006827d4 + local_8 * 0x5b20 + local_10 * 0x120) = 0;
          FUN_0048c50b(local_8,local_10,0x85);
          FUN_0048c50b(local_8,local_10,0x84);
        }
      }
    }
  }
  return;
}


