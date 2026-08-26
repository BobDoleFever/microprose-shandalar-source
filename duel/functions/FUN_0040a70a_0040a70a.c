/*
 * Decompiled function: FUN_0040a70a
 * Entry Point: 0040a70a
 * Size: 566 bytes
 */
#include "duel.h"


undefined4 FUN_0040a70a(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  int local_c;
  
  if ((arg_3 == 199) && (((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 2) != 0)) {
    if (((&DAT_006826cd)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0) {
      local_c = DAT_00676504;
    }
    else {
      local_c = DAT_00676510;
    }
    iVar1 = 3 - (&DAT_0068ee78)[local_c];
    if (iVar1 < 1) {
      iVar1 = 0;
    }
    if (iVar1 != 0) {
      if (local_c == 0) {
        iVar1 = 0x18 - (int)(&DAT_00681ea8)[local_c] / iVar1;
        if (iVar1 < 2) {
          iVar1 = 1;
        }
        DAT_0068f2d4 = DAT_0068f2d4 + iVar1 * 0x18;
      }
      else {
        iVar1 = 0x18 - (int)(&DAT_00681ea8)[local_c] / iVar1;
        if (iVar1 < 2) {
          iVar1 = 1;
        }
        DAT_0068f2d4 = DAT_0068f2d4 + iVar1 * -0x18;
      }
    }
  }
  if ((((DAT_0068f230 == 0xcb) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) &&
     ((((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0 ||
      (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34] & 2) != 0))
     )) {
    if (((&DAT_006826cd)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0) {
      local_c = DAT_00676504;
    }
    else {
      local_c = DAT_00676510;
    }
    if ((local_c == DAT_00666458) && ((int)(&DAT_0068ee78)[local_c] < 3)) {
      if (arg_3 == 0x7d) {
        DAT_0066642c = DAT_0066642c | 2;
      }
      if (arg_3 == 0x7e) {
        Mem_AllocOrFree_004afd1c(local_c,3 - (&DAT_0068ee78)[local_c],arg_1,arg_2);
      }
    }
  }
  return 0;
}


