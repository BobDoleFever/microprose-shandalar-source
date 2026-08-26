/*
 * Decompiled function: FUN_004a59e6
 * Entry Point: 004a59e6
 * Size: 343 bytes
 */
#include "duel.h"


undefined4 FUN_004a59e6(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  int arg1;
  int iVar2;
  int local_c;
  
  if (arg_3 == 0x89) {
    FUN_00467d65(FUN_004a5b3d,-1);
  }
  if ((((arg_3 == 0x22) || (arg_3 == 199)) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1)) {
    arg1 = 1 - arg_1;
    for (local_c = 0; local_c < (int)(&DAT_00666408)[arg1]; local_c = local_c + 1) {
      iVar1 = *(int *)(&DAT_006826c4 + local_c * 0x120 + arg1 * 0x5b20);
      iVar2 = FUN_0048a33f(arg1,local_c);
      if (((iVar2 != 0) && (((&DAT_004ff594)[iVar1 * 0x34] & 2) != 0)) &&
         (((&DAT_004ff595)[iVar1 * 0x34] != '\0' &&
          ((*(uint *)(&DAT_006826cc + local_c * 0x120 + arg1 * 0x5b20) & 0x30040) == 0)))) {
        FUN_0046e571(arg1,local_c,2);
      }
    }
    FUN_0046e571(arg_1,arg_2,2);
  }
  return 0;
}


