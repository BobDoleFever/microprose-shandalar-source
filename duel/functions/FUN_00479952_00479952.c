/*
 * Decompiled function: FUN_00479952
 * Entry Point: 00479952
 * Size: 467 bytes
 */
#include "duel.h"


void FUN_00479952(void)

{
  int iVar1;
  int local_8;
  
  for (local_8 = 0; local_8 < 4; local_8 = local_8 + 1) {
    *(undefined4 *)(&DAT_00666730 + local_8 * 4) = 0;
  }
  local_8 = 0;
  while( true ) {
    iVar1 = (&DAT_00666408)[DAT_00676504];
    if ((int)(&DAT_00666408)[DAT_00676504] <= (int)(&DAT_00666408)[DAT_00676510]) {
      iVar1 = (&DAT_00666408)[DAT_00676510];
    }
    if (iVar1 <= local_8) break;
    if ((*(int *)(&DAT_006826c4 + local_8 * 0x120 + DAT_00676510 * 0x5b20) != -1) &&
       (((&DAT_006826cc)[local_8 * 0x120 + DAT_00676510 * 0x5b20] & 2) != 0)) {
      (**(code **)(&DAT_004ff5a0 +
                  *(int *)(&DAT_006826c4 + local_8 * 0x120 + DAT_00676510 * 0x5b20) * 0x34))
                (DAT_00676510,local_8,0x3b);
    }
    if ((*(int *)(&DAT_006826c4 + local_8 * 0x120 + DAT_00676504 * 0x5b20) != -1) &&
       ((((&DAT_006826cc)[local_8 * 0x120 + DAT_00676510 * 0x5b20] & 2) != 0 ||
        (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + local_8 * 0x120 + DAT_00676504 * 0x5b20) * 0x34]
         & 0x10) != 0)))) {
      (**(code **)(&DAT_004ff5a0 +
                  *(int *)(&DAT_006826c4 + local_8 * 0x120 + DAT_00676504 * 0x5b20) * 0x34))
                (DAT_00676504,local_8,0x3b);
    }
    local_8 = local_8 + 1;
  }
  return;
}


