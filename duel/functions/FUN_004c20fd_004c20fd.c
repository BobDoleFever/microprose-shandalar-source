/*
 * Decompiled function: FUN_004c20fd
 * Entry Point: 004c20fd
 * Size: 915 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_004c20fd(int arg_1,int arg_2,int arg_3)

{
  uint uVar1;
  int local_8;
  
  if (arg_3 == 0x74) {
    if (DAT_00676510 == arg_1) {
      uVar1 = (DAT_0066aad4 | _DAT_0066aad0) & 0x40;
    }
    else {
      uVar1 = *(uint *)(&DAT_0066aad0 + DAT_00676510 * 4) & 0x40;
    }
  }
  else {
    if (((arg_3 == 0x6c) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1)) {
      if (local_8 == -1) {
        DAT_00681ea4 = 1;
      }
      else {
        *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) = local_8;
        (&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] = (undefined1)DAT_0068eef0;
      }
    }
    if ((arg_3 == 0x71) && (*(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) != -1)) {
      if (((&DAT_006826cc)
           [*(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
            (char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20] & 0x10) == 0) {
        *(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 1;
      }
      else {
        *(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
      }
    }
    if (((arg_3 == 0x7c) &&
        (*(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) == DAT_00690c48)) &&
       (((char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] == DAT_0068ecb0 &&
        ((DAT_00690c48 != -1 && (*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) != 0))))))
    {
      Mem_AllocOrFree_004afd1c(DAT_0068ecb0,2,arg_1,arg_2);
      *(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
    }
    if (*(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) != -1) {
      if (((&DAT_006826cc)
           [*(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
            (char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20] & 0x10) == 0) {
        *(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 1;
      }
      else if (*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) != 0) {
        Mem_AllocOrFree_004afd1c(DAT_0068ecb0,2,arg_1,arg_2);
        *(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}


