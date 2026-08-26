/*
 * Decompiled function: FUN_00486a4e
 * Entry Point: 00486a4e
 * Size: 373 bytes
 */
#include "duel.h"


void FUN_00486a4e(int arg1,int arg2)

{
  bool bVar1;
  int local_10;
  int local_c;
  
  if (arg1 != -1) {
    local_c = 0;
    bVar1 = false;
    while ((local_c < DAT_005f76d4 && (!bVar1))) {
      if (((&DAT_00664880)[local_c * 6] == arg1) && ((&DAT_00664884)[local_c * 6] == arg2)) {
        bVar1 = true;
        if (*(int *)(&DAT_00664870 + local_c * 0x18) != 0) {
          DeleteObject(*(HGDIOBJ *)(&DAT_00664870 + local_c * 0x18));
        }
        DAT_005f76d4 = DAT_005f76d4 + -1;
        for (local_10 = local_c; local_10 < DAT_005f76d4; local_10 = local_10 + 1) {
          *(undefined4 *)(&DAT_00664870 + local_10 * 0x18) =
               *(undefined4 *)(&DAT_00664870 + (local_10 * 3 + 3) * 8);
          *(undefined4 *)(&DAT_00664874 + local_10 * 0x18) =
               *(undefined4 *)(&DAT_00664874 + (local_10 * 3 + 3) * 8);
          *(undefined4 *)(&DAT_00664878 + local_10 * 0x18) =
               *(undefined4 *)(&DAT_00664878 + (local_10 * 3 + 3) * 8);
          *(undefined4 *)(&DAT_0066487c + local_10 * 0x18) =
               *(undefined4 *)(&DAT_0066487c + (local_10 * 3 + 3) * 8);
          (&DAT_00664880)[local_10 * 6] = (&DAT_00664880)[(local_10 * 3 + 3) * 2];
          (&DAT_00664884)[local_10 * 6] = (&DAT_00664884)[(local_10 * 3 + 3) * 2];
        }
      }
      local_c = local_c + 1;
    }
  }
  return;
}


