/*
 * Decompiled function: FUN_00466d59
 * Entry Point: 00466d59
 * Size: 568 bytes
 */
#include "duel.h"


undefined4 FUN_00466d59(int arg_1,int arg_2,int arg_3)

{
  char cVar1;
  int arg1;
  int iVar2;
  int local_10;
  
  arg1 = 1 - arg_1;
  if (((arg_3 == 0x77) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
    if ((arg_1 == DAT_00666458) && (((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x44) != 0))
    {
      for (local_10 = 0; local_10 < 0x50; local_10 = local_10 + 1) {
        if (((char)(&DAT_006826de)[local_10 * 0x120 + arg1 * 0x5b20] == arg_2) &&
           (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + local_10 * 0x120 + arg1 * 0x5b20) * 0x34] & 2)
            != 0)) {
          FUN_0046e571(arg1,local_10,4);
        }
      }
    }
    if ((arg_1 != DAT_00666458) && ((&DAT_006826de)[arg_2 * 0x120 + arg_1 * 0x5b20] != -1)) {
      cVar1 = (&DAT_006826de)
              [arg1 * 0x5b20 + (char)(&DAT_006826de)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x120];
      if (cVar1 == -1) {
        FUN_0046e571(arg1,(int)(char)(&DAT_006826de)[arg_2 * 0x120 + arg_1 * 0x5b20],4);
      }
      else {
        for (local_10 = 0; local_10 < 0x50; local_10 = local_10 + 1) {
          iVar2 = FUN_0048a33f(arg1,local_10);
          if ((iVar2 != 0) && ((&DAT_006826de)[local_10 * 0x120 + arg1 * 0x5b20] == cVar1)) {
            FUN_0046e571(arg1,local_10,4);
          }
        }
      }
    }
  }
  return 0;
}


