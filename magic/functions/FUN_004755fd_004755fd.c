/*
 * Decompiled function: FUN_004755fd
 * Entry Point: 004755fd
 * Size: 164 bytes
 */
#include "magic.h"


undefined4 FUN_004755fd(void)

{
  int iVar1;
  int local_c;
  
  for (local_c = 0; local_c < DAT_006a3f78; local_c = local_c + 1) {
    iVar1 = (&DAT_006fecc0)[local_c * 2];
    *(int *)(&DAT_006ff390 + local_c * 8) =
         (int)(char)(&g_CardSlot_Toughness)
                    [iVar1 * 0x5b20 + *(int *)(&DAT_006fecc4 + local_c * 8) * 0x120];
    *(undefined4 *)(&DAT_006ff394 + local_c * 8) =
         *(undefined4 *)
          (&g_CardSlot_OriginalCardId +
          iVar1 * 0x5b20 + *(int *)(&DAT_006fecc4 + local_c * 8) * 0x120);
  }
  return 0;
}


