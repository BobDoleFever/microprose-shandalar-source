/*
 * Decompiled function: FUN_004a2f9f
 * Entry Point: 004a2f9f
 * Size: 162 bytes
 */
#include "duel.h"


undefined4 FUN_004a2f9f(int arg_1,int arg_2,int arg_3)

{
  if (((arg_3 == 0x78) && (*(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) == DAT_0068ecfc)
      ) && ((char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] == DAT_00690310)) {
    DAT_0066642c = DAT_0066642c + 1;
  }
  if ((arg_3 == 0x22) || (arg_3 == 199)) {
    FUN_0046e571(arg_1,arg_2,1);
  }
  return 0;
}


