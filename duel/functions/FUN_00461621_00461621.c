/*
 * Decompiled function: FUN_00461621
 * Entry Point: 00461621
 * Size: 244 bytes
 */
#include "duel.h"


undefined4 FUN_00461621(int arg_1,int arg_2,int arg_3)

{
  bool bVar1;
  int arg1;
  int iVar2;
  int local_8;
  
  if ((arg_3 == 0x1a) && (((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 4) != 0)) {
    bVar1 = true;
    arg1 = 1 - arg_1;
    for (local_8 = 0; local_8 < (int)(&DAT_00666408)[arg1]; local_8 = local_8 + 1) {
      iVar2 = FUN_0048a33f(arg1,local_8);
      if ((iVar2 != 0) && ((char)(&DAT_006826de)[local_8 * 0x120 + arg1 * 0x5b20] == arg_2)) {
        bVar1 = false;
        break;
      }
    }
    if (bVar1) {
      (&DAT_00681ea8)[arg_1] = (&DAT_00681ea8)[arg_1] + 2;
    }
  }
  FUN_00461715(arg_1,arg_2,arg_3);
  return 0;
}


