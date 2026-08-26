/*
 * Decompiled function: FUN_004aee02
 * Entry Point: 004aee02
 * Size: 402 bytes
 */
#include "duel.h"


undefined4 FUN_004aee02(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_c;
  int local_8;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1)) {
      *(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 6;
    }
    if (arg_3 == 0x71) {
      for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
        Mem_AllocOrFree_004afd1c
                  (local_8,*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20),arg_1,arg_2);
        for (local_c = 0; local_c < (int)(&DAT_00666408)[local_8]; local_c = local_c + 1) {
          iVar2 = FUN_0048a33f(local_8,local_c);
          if ((iVar2 != 0) &&
             (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + local_c * 0x120 + local_8 * 0x5b20) * 0x34]
              & 2) != 0)) {
            FUN_004af950(local_8,local_c,*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20),
                         arg_1,arg_2);
          }
        }
      }
      FUN_0046e571(arg_1,arg_2,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


