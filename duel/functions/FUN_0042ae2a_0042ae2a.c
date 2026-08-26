/*
 * Decompiled function: FUN_0042ae2a
 * Entry Point: 0042ae2a
 * Size: 433 bytes
 */
#include "duel.h"


void FUN_0042ae2a(void)

{
  int iVar1;
  int local_c;
  int local_8;
  
  while (*(int *)(&DAT_0068f2fc + DAT_00676504 * 0x20) != 0) {
    local_c = 0;
    while( true ) {
      if ((int)(&DAT_00666408)[DAT_00676504] <= local_c) goto LAB_0042af29;
      if (((*(int *)(&DAT_006826c4 + DAT_00676504 * 0x5b20 + local_c * 0x120) != -1) &&
          (((byte)*(undefined4 *)(&DAT_006826cc + DAT_00676504 * 0x5b20 + local_c * 0x120) & 0x22)
           == 2)) &&
         (FUN_0048c907(DAT_00676504,local_c,0x8f,1 - DAT_00676504,0xffffffff), DAT_0068edd8 != 0))
      break;
      local_c = local_c + 1;
    }
    iVar1 = FUN_0048974c(DAT_00676504,local_c);
    if (iVar1 != 0) {
      FUN_0048a07d(DAT_00676504,local_c);
    }
  }
LAB_0042af29:
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    if (0 < *(int *)(&DAT_0068f2fc + local_8 * 0x20)) {
      if (DAT_0066aaf4 != 1) {
        FUN_0048d00c(0x20);
        FUN_00448d16(local_8,*(undefined4 *)(&DAT_0068f2fc + local_8 * 0x20));
      }
      (&DAT_00681ea8)[local_8] = (&DAT_00681ea8)[local_8] - *(int *)(&DAT_0068f2fc + local_8 * 0x20)
      ;
      for (local_c = 0; local_c < 8; local_c = local_c + 1) {
        *(undefined4 *)(&DAT_0068f2e0 + local_c * 4 + local_8 * 0x20) = 0;
      }
    }
  }
  return;
}


