/*
 * Decompiled function: FUN_0048dc9e
 * Entry Point: 0048dc9e
 * Size: 165 bytes
 */
#include "duel.h"


undefined4 FUN_0048dc9e(void)

{
  int iVar1;
  int local_c;
  
  for (local_c = 0; local_c < DAT_006764b8; local_c = local_c + 1) {
    iVar1 = (&DAT_0068efb0)[local_c * 2];
    *(int *)(&DAT_0068f120 + local_c * 8) =
         (int)(char)(&DAT_006826d2)[*(int *)(&DAT_0068efb4 + local_c * 8) * 0x120 + iVar1 * 0x5b20];
    *(undefined4 *)(&DAT_0068f124 + local_c * 8) =
         *(undefined4 *)
          (&DAT_006826e8 + *(int *)(&DAT_0068efb4 + local_c * 8) * 0x120 + iVar1 * 0x5b20);
  }
  return 0;
}


