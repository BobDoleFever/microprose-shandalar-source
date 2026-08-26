/*
 * Decompiled function: FUN_00451760
 * Entry Point: 00451760
 * Size: 565 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00451760(void)

{
  int local_c;
  int local_8;
  
  for (local_c = 0; local_c < 8; local_c = local_c + 1) {
    *(undefined4 *)(&DAT_00676150 + local_c * 4) = 0;
    *(undefined4 *)(&DAT_0068ed30 + local_c * 4) = *(undefined4 *)(&DAT_00676150 + local_c * 4);
    *(undefined4 *)(&DAT_0068ed10 + local_c * 4) = *(undefined4 *)(&DAT_0068ed30 + local_c * 4);
  }
  DAT_0066663c = 0xffffffff;
  _DAT_00666570 = 0xffffffff;
  DAT_0066692c = 0xffffffff;
  _DAT_00666900 = 0xffffffff;
  DAT_0068f364 = 0;
  _DAT_0068f360 = 0;
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    for (local_c = 0; local_c < (int)(&DAT_00666408)[local_8]; local_c = local_c + 1) {
      if ((((&DAT_004ff5a9)[*(int *)(&DAT_006826c4 + local_c * 0x120 + local_8 * 0x5b20) * 0x34] &
           0x10) != 0) && (((&DAT_006826cc)[local_c * 0x120 + local_8 * 0x5b20] & 2) != 0)) {
        FUN_0048c50b(local_8,local_c,0x7f);
      }
      if ((*(int *)(&DAT_004ff590 +
                   *(int *)(&DAT_006826c4 + local_c * 0x120 + local_8 * 0x5b20) * 0x34) == 0xee) &&
         (((&DAT_006826cc)[local_c * 0x120 + local_8 * 0x5b20] & 2) != 0)) {
        FUN_0048c907(local_8,local_c,0x7f,0xffffffff,0xffffffff);
      }
      if ((*(int *)(&DAT_004ff590 +
                   *(int *)(&DAT_006826c4 + local_c * 0x120 + local_8 * 0x5b20) * 0x34) == 100) &&
         (((&DAT_006826cc)[local_c * 0x120 + local_8 * 0x5b20] & 2) != 0)) {
        FUN_0048c907(local_8,local_c,0x7f,0xffffffff,0xffffffff);
      }
    }
  }
  return;
}


