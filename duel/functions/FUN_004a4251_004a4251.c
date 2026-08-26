/*
 * Decompiled function: FUN_004a4251
 * Entry Point: 004a4251
 * Size: 371 bytes
 */
#include "duel.h"


undefined4 FUN_004a4251(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  
  if ((((arg_3 == 0x32) &&
       (*(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) == DAT_00690c48)) &&
      ((char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] == DAT_0068ecb0)) &&
     (DAT_00690c48 != -1)) {
    iVar1 = FUN_0048a33f((int)(char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20],
                         *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20));
    if ((iVar1 != 0) &&
       (((&DAT_004ff594)
         [*(int *)(&DAT_006826c4 +
                  *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                  (char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) * 0x34] & 2) != 0)
       ) {
      DAT_0066642c = DAT_0066642c + -2;
    }
  }
  if ((arg_3 == 0x22) || (arg_3 == 199)) {
    FUN_0046e571(arg_1,arg_2,1);
  }
  return 0;
}


