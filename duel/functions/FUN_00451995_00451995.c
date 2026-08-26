/*
 * Decompiled function: FUN_00451995
 * Entry Point: 00451995
 * Size: 631 bytes
 */
#include "duel.h"


void FUN_00451995(void)

{
  int local_10;
  int local_c;
  int local_8;
  
  for (local_c = 0; local_c < 8; local_c = local_c + 1) {
    *(undefined4 *)(&DAT_0068ef70 + local_c * 4) = 0;
    *(undefined4 *)(&DAT_0068ef50 + local_c * 4) = *(undefined4 *)(&DAT_0068ef70 + local_c * 4);
  }
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    for (local_c = 0; local_c < (int)(&DAT_00666408)[local_8]; local_c = local_c + 1) {
      if ((((*(int *)(&DAT_006826c4 + local_c * 0x120 + local_8 * 0x5b20) != -1) &&
           (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + local_c * 0x120 + local_8 * 0x5b20) * 0x34] &
            1) != 0)) && (((&DAT_006826cc)[local_c * 0x120 + local_8 * 0x5b20] & 2) != 0)) &&
         (((&DAT_006826cc)[local_c * 0x120 + local_8 * 0x5b20] & 0x20) == 0)) {
        if (*(int *)(&DAT_006826c4 + local_c * 0x120 + local_8 * 0x5b20) < 5) {
          (&DAT_0068ef54)
          [local_8 * 8 + *(int *)(&DAT_006826c4 + local_c * 0x120 + local_8 * 0x5b20)] =
               (&DAT_0068ef54)
               [local_8 * 8 + *(int *)(&DAT_006826c4 + local_c * 0x120 + local_8 * 0x5b20)] + 1;
        }
        else if ((*(int *)(&DAT_006826c4 + local_c * 0x120 + local_8 * 0x5b20) < DAT_00665ed0) ||
                (DAT_00665ed0 + 0x10 <= *(int *)(&DAT_006826c4 + local_c * 0x120 + local_8 * 0x5b20)
                )) {
          *(int *)(&DAT_0068ef50 + local_8 * 0x20) = *(int *)(&DAT_0068ef50 + local_8 * 0x20) + 1;
        }
        else {
          for (local_10 = 0; local_10 < 5; local_10 = local_10 + 1) {
            if (*(int *)(&DAT_004ff590 +
                        *(int *)(&DAT_006826c4 + local_c * 0x120 + local_8 * 0x5b20) * 0x34) ==
                (&DAT_0068f0e0)[local_10]) {
              (&DAT_0068ef54)[local_8 * 8 + local_10] = (&DAT_0068ef54)[local_8 * 8 + local_10] + 1;
            }
          }
        }
        *(int *)(&DAT_0068ef6c + local_8 * 0x20) = *(int *)(&DAT_0068ef6c + local_8 * 0x20) + 1;
      }
    }
  }
  return;
}


