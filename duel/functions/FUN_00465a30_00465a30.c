/*
 * Decompiled function: FUN_00465a30
 * Entry Point: 00465a30
 * Size: 604 bytes
 */
#include "duel.h"


undefined4 FUN_00465a30(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  
  if (((arg_3 == 0x6c) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
    iVar1 = FUN_00468130(arg_1,0xffffffff,arg_2);
    if (iVar1 == 0) {
      FUN_0046e571(arg_1,arg_2,1);
      DAT_00681ea4 = 1;
    }
  }
  if ((arg_3 == 0x71) && (*(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) != -1)) {
    (&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] =
         (&DAT_00682718)[arg_2 * 0x120 + arg_1 * 0x5b20];
    *(undefined4 *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(undefined4 *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20);
    *(undefined4 *)(&DAT_006826c4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(undefined4 *)
          (&DAT_006826c4 +
          *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
          (char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20);
    (&DAT_006826dc)[arg_2 * 0x120 + arg_1 * 0x5b20] =
         (&DAT_004ff596)[*(int *)(&DAT_006826c4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34];
    *(undefined4 *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0xffffffff;
    (&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] =
         (&DAT_006826e8)[arg_2 * 0x120 + arg_1 * 0x5b20];
    FUN_0048c907(arg_1,arg_2,0x6c,1 - arg_1,0xffffffff);
  }
  return 0;
}


