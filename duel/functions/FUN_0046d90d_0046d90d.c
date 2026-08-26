/*
 * Decompiled function: FUN_0046d90d
 * Entry Point: 0046d90d
 * Size: 317 bytes
 */
#include "duel.h"


void FUN_0046d90d(void)

{
  short sVar1;
  int iVar2;
  int local_c;
  int local_8;
  
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    for (local_c = 0; local_c < (int)(&DAT_00666408)[local_8]; local_c = local_c + 1) {
      if (((*(int *)(&DAT_006826c4 + local_c * 0x120 + local_8 * 0x5b20) != -1) &&
          (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + local_c * 0x120 + local_8 * 0x5b20) * 0x34] & 2
           ) != 0)) && (((&DAT_006826cc)[local_c * 0x120 + local_8 * 0x5b20] & 2) != 0)) {
        sVar1 = *(short *)(&DAT_006826d0 + local_c * 0x120 + local_8 * 0x5b20);
        iVar2 = FUN_0048b81a(local_8,local_c,0x33,0xffffffff);
        if (iVar2 <= sVar1) {
          if (DAT_0066aaf4 != 1) {
            FUN_0048d00c(0x19);
          }
          FUN_0046e571(local_8,local_c,2);
        }
      }
    }
  }
  return;
}


