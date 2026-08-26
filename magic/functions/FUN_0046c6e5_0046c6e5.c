/*
 * Decompiled function: FUN_0046c6e5
 * Entry Point: 0046c6e5
 * Size: 372 bytes
 */
#include "magic.h"


void FUN_0046c6e5(int arg1,int arg2)

{
  bool bVar1;
  int local_10;
  int local_c;
  
  if (arg1 != -1) {
    local_c = 0;
    bVar1 = false;
    while ((local_c < DAT_006fe404 && (!bVar1))) {
      if ((*(int *)(&DAT_006a3f90 + local_c * 0x18) == arg1) &&
         (*(int *)(&DAT_006a3f94 + local_c * 0x18) == arg2)) {
        bVar1 = true;
        if (*(int *)(&DAT_006a3f80 + local_c * 0x18) != 0) {
          DeleteObject(*(HGDIOBJ *)(&DAT_006a3f80 + local_c * 0x18));
        }
        DAT_006fe404 = DAT_006fe404 + -1;
        for (local_10 = local_c; local_10 < DAT_006fe404; local_10 = local_10 + 1) {
          *(undefined4 *)(&DAT_006a3f80 + local_10 * 0x18) =
               *(undefined4 *)(&DAT_006a3f80 + (local_10 * 3 + 3) * 8);
          *(undefined4 *)(&DAT_006a3f84 + local_10 * 0x18) =
               *(undefined4 *)(&DAT_006a3f84 + (local_10 * 3 + 3) * 8);
          *(undefined4 *)(&DAT_006a3f88 + local_10 * 0x18) =
               *(undefined4 *)(&DAT_006a3f88 + (local_10 * 3 + 3) * 8);
          *(undefined4 *)(&DAT_006a3f8c + local_10 * 0x18) =
               *(undefined4 *)(&DAT_006a3f8c + (local_10 * 3 + 3) * 8);
          *(undefined4 *)(&DAT_006a3f90 + local_10 * 0x18) =
               *(undefined4 *)(&DAT_006a3f90 + (local_10 * 3 + 3) * 8);
          *(undefined4 *)(&DAT_006a3f94 + local_10 * 0x18) =
               *(undefined4 *)(&DAT_006a3f94 + (local_10 * 3 + 3) * 8);
        }
      }
      local_c = local_c + 1;
    }
  }
  return;
}


