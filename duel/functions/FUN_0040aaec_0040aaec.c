/*
 * Decompiled function: FUN_0040aaec
 * Entry Point: 0040aaec
 * Size: 268 bytes
 */
#include "duel.h"


undefined4 FUN_0040aaec(int arg_1,int arg_2,int arg_3)

{
  int local_8;
  
  if ((arg_3 == 0x1f) &&
     ((((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0 ||
      (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34] & 2) != 0))
     )) {
    if (((&DAT_006826cd)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0) {
      local_8 = DAT_00676504;
    }
    else {
      local_8 = DAT_00676510;
    }
    if ((DAT_00666458 == local_8) && (4 < (int)(&DAT_0068ee78)[DAT_00666458])) {
      DAT_0066642c = DAT_0066642c | 1;
      while (4 < (int)(&DAT_0068ee78)[DAT_00666458]) {
        Palette_Color_0049ae00(DAT_00666458,0,0);
      }
    }
  }
  return 0;
}


