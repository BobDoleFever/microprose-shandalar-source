/*
 * Decompiled function: FUN_004393a2
 * Entry Point: 004393a2
 * Size: 372 bytes
 */
#include "duel.h"


void FUN_004393a2(int arg1,int arg2)

{
  bool bVar1;
  int local_10;
  int local_c;
  
  if (arg1 != -1) {
    local_c = 0;
    bVar1 = false;
    while ((local_c < DAT_00663df8 && (!bVar1))) {
      if ((*(int *)(&DAT_00616a20 + local_c * 0x18) == arg1) &&
         (*(int *)(&DAT_00616a24 + local_c * 0x18) == arg2)) {
        bVar1 = true;
        if (*(int *)(&DAT_00616a10 + local_c * 0x18) != 0) {
          DeleteObject(*(HGDIOBJ *)(&DAT_00616a10 + local_c * 0x18));
        }
        DAT_00663df8 = DAT_00663df8 + -1;
        for (local_10 = local_c; local_10 < DAT_00663df8; local_10 = local_10 + 1) {
          *(undefined4 *)(&DAT_00616a10 + local_10 * 0x18) =
               *(undefined4 *)(&DAT_00616a10 + (local_10 * 3 + 3) * 8);
          *(undefined4 *)(&DAT_00616a14 + local_10 * 0x18) =
               *(undefined4 *)(&DAT_00616a14 + (local_10 * 3 + 3) * 8);
          *(undefined4 *)(&DAT_00616a18 + local_10 * 0x18) =
               *(undefined4 *)(&DAT_00616a18 + (local_10 * 3 + 3) * 8);
          *(undefined4 *)(&DAT_00616a1c + local_10 * 0x18) =
               *(undefined4 *)(&DAT_00616a1c + (local_10 * 3 + 3) * 8);
          *(undefined4 *)(&DAT_00616a20 + local_10 * 0x18) =
               *(undefined4 *)(&DAT_00616a20 + (local_10 * 3 + 3) * 8);
          *(undefined4 *)(&DAT_00616a24 + local_10 * 0x18) =
               *(undefined4 *)(&DAT_00616a24 + (local_10 * 3 + 3) * 8);
        }
      }
      local_c = local_c + 1;
    }
  }
  return;
}


