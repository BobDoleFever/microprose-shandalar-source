/*
 * Decompiled function: FUN_00476510
 * Entry Point: 00476510
 * Size: 357 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00476510(void)

{
  int local_c;
  int local_8;
  
  for (local_8 = 0; local_8 < 500; local_8 = local_8 + 1) {
    while ((*(int *)(&DAT_007006e0 + local_8 * 4) != -1 &&
           ((local_c = local_8,
            *(int *)(&g_CardSlot_CardId +
                    *(int *)(&DAT_007006e0 + local_8 * 4) * 0x5b20 +
                    *(int *)(&DAT_006a5750 + local_8 * 4) * 0x120) == -1 ||
            (*(int *)(&g_CardSlot_DisplayIndex +
                     *(int *)(&DAT_007006e0 + local_8 * 4) * 0x5b20 +
                     *(int *)(&DAT_006a5750 + local_8 * 4) * 0x120) != local_8))))) {
      while (local_c = local_c + 1, local_c < 500) {
        *(undefined4 *)(&DAT_007006dc + local_c * 4) = *(undefined4 *)(&DAT_007006e0 + local_c * 4);
        *(undefined4 *)(&DAT_006a574c + local_c * 4) = *(undefined4 *)(&DAT_006a5750 + local_c * 4);
        if (*(int *)(&g_CardSlot_DisplayIndex +
                    *(int *)(&DAT_006a5750 + local_c * 4) * 0x120 +
                    *(int *)(&DAT_007006e0 + local_c * 4) * 0x5b20) == local_c) {
          *(int *)(&g_CardSlot_DisplayIndex +
                  *(int *)(&DAT_007006e0 + local_c * 4) * 0x5b20 +
                  *(int *)(&DAT_006a5750 + local_c * 4) * 0x120) =
               *(int *)(&g_CardSlot_DisplayIndex +
                       *(int *)(&DAT_007006e0 + local_c * 4) * 0x5b20 +
                       *(int *)(&DAT_006a5750 + local_c * 4) * 0x120) + -1;
        }
      }
      _DAT_00700eac = 0xffffffff;
    }
  }
  return;
}


