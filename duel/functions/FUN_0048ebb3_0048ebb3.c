/*
 * Decompiled function: FUN_0048ebb3
 * Entry Point: 0048ebb3
 * Size: 357 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0048ebb3(void)

{
  int local_c;
  int local_8;
  
  for (local_8 = 0; local_8 < 500; local_8 = local_8 + 1) {
    while ((*(int *)(&DAT_00690320 + local_8 * 4) != -1 &&
           ((local_c = local_8,
            *(int *)(&DAT_006826c4 +
                    *(int *)(&DAT_00681ee0 + local_8 * 4) * 0x120 +
                    *(int *)(&DAT_00690320 + local_8 * 4) * 0x5b20) == -1 ||
            (*(int *)(&DAT_006826f4 +
                     *(int *)(&DAT_00681ee0 + local_8 * 4) * 0x120 +
                     *(int *)(&DAT_00690320 + local_8 * 4) * 0x5b20) != local_8))))) {
      while (local_c = local_c + 1, local_c < 500) {
        *(undefined4 *)(&DAT_0069031c + local_c * 4) = *(undefined4 *)(&DAT_00690320 + local_c * 4);
        *(undefined4 *)(&DAT_00681edc + local_c * 4) = *(undefined4 *)(&DAT_00681ee0 + local_c * 4);
        if (*(int *)(&DAT_006826f4 +
                    *(int *)(&DAT_00681ee0 + local_c * 4) * 0x120 +
                    *(int *)(&DAT_00690320 + local_c * 4) * 0x5b20) == local_c) {
          *(int *)(&DAT_006826f4 +
                  *(int *)(&DAT_00681ee0 + local_c * 4) * 0x120 +
                  *(int *)(&DAT_00690320 + local_c * 4) * 0x5b20) =
               *(int *)(&DAT_006826f4 +
                       *(int *)(&DAT_00681ee0 + local_c * 4) * 0x120 +
                       *(int *)(&DAT_00690320 + local_c * 4) * 0x5b20) + -1;
        }
      }
      _DAT_00690aec = 0xffffffff;
    }
  }
  return;
}


