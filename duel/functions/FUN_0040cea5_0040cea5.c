/*
 * Decompiled function: FUN_0040cea5
 * Entry Point: 0040cea5
 * Size: 306 bytes
 */
#include "duel.h"


int FUN_0040cea5(int arg1,int arg2)

{
  int iVar1;
  int local_14;
  int local_c;
  int local_8;
  
  local_c = 0;
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    for (local_14 = 0; local_14 < (int)(&DAT_00666408)[local_8]; local_14 = local_14 + 1) {
      iVar1 = FUN_0048a33f(local_8,local_14);
      if ((((iVar1 != 0) &&
           (*(int *)(&DAT_004ff590 +
                    *(int *)(&DAT_006826c4 + local_14 * 0x120 + local_8 * 0x5b20) * 0x34) == 0x37b))
          && ((char)(&DAT_006826d3)[local_14 * 0x120 + local_8 * 0x5b20] == arg1)) &&
         ((*(int *)(&DAT_006826ec + local_14 * 0x120 + local_8 * 0x5b20) == arg2 &&
          (*(int *)(&DAT_006826e4 + local_14 * 0x120 + local_8 * 0x5b20) == 0)))) {
        local_c = local_c + 1;
      }
    }
  }
  return local_c;
}


