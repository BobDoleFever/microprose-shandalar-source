/*
 * Decompiled function: FUN_00403c4c
 * Entry Point: 00403c4c
 * Size: 314 bytes
 */
#include "duel.h"


undefined4 FUN_00403c4c(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int local_c;
  int local_8;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (arg_3 == 0x71) {
      for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
        for (local_c = 0; local_c < (int)(&DAT_00666408)[local_8]; local_c = local_c + 1) {
          iVar2 = FUN_0048a33f(local_8,local_c);
          if ((iVar2 != 0) &&
             (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + local_c * 0x120 + local_8 * 0x5b20) * 0x34]
              & 1) != 0)) {
            iVar2 = *(int *)(&DAT_006826c4 + local_c * 0x120 + local_8 * 0x5b20);
            iVar3 = FUN_004af74c(arg_1,arg_2,2);
            if (*(int *)(&DAT_004ff590 + iVar2 * 0x34) == *(int *)(&DAT_0068f0dc + iVar3 * 4)) {
              FUN_0046e571(local_8,local_c,2);
            }
          }
        }
      }
      FUN_0046e571(arg_1,arg_2,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


