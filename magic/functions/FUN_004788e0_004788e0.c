/*
 * Decompiled function: FUN_004788e0
 * Entry Point: 004788e0
 * Size: 374 bytes
 */
#include "magic.h"


void FUN_004788e0(int arg1,int arg2)

{
  bool bVar1;
  int local_10;
  int local_c;
  
  if (arg1 != -1) {
    local_c = 0;
    bVar1 = false;
    while ((local_c < DAT_00680778 && (!bVar1))) {
      if (((&DAT_006fefc0)[local_c * 6] == arg1) && ((&DAT_006fefc4)[local_c * 6] == arg2)) {
        bVar1 = true;
        if (*(int *)(&DAT_006fefb0 + local_c * 0x18) != 0) {
          DeleteObject(*(HGDIOBJ *)(&DAT_006fefb0 + local_c * 0x18));
        }
        DAT_00680778 = DAT_00680778 + -1;
        for (local_10 = local_c; local_10 < DAT_00680778; local_10 = local_10 + 1) {
          *(undefined4 *)(&DAT_006fefb0 + local_10 * 0x18) =
               *(undefined4 *)(&DAT_006fefb0 + (local_10 * 3 + 3) * 8);
          *(undefined4 *)(&DAT_006fefb4 + local_10 * 0x18) =
               *(undefined4 *)(&DAT_006fefb4 + (local_10 * 3 + 3) * 8);
          *(undefined4 *)(&DAT_006fefb8 + local_10 * 0x18) =
               *(undefined4 *)(&DAT_006fefb8 + (local_10 * 3 + 3) * 8);
          *(undefined4 *)(&DAT_006fefbc + local_10 * 0x18) =
               *(undefined4 *)(&DAT_006fefbc + (local_10 * 3 + 3) * 8);
          (&DAT_006fefc0)[local_10 * 6] = (&DAT_006fefc0)[(local_10 * 3 + 3) * 2];
          (&DAT_006fefc4)[local_10 * 6] = (&DAT_006fefc4)[(local_10 * 3 + 3) * 2];
        }
      }
      local_c = local_c + 1;
    }
  }
  return;
}


