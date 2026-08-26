/*
 * Decompiled function: FUN_00464d69
 * Entry Point: 00464d69
 * Size: 332 bytes
 */
#include "duel.h"


void FUN_00464d69(int arg_1,int arg_2,int arg_3)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  int local_c;
  int local_8;
  
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    for (local_c = 0; local_c < (int)(&DAT_00666408)[local_8]; local_c = local_c + 1) {
      iVar3 = FUN_0048a33f(local_8,local_c);
      if (((iVar3 != 0) && ((char)(&DAT_006826d2)[local_c * 0x120 + local_8 * 0x5b20] == arg_1)) &&
         (*(int *)(&DAT_006826e8 + local_c * 0x120 + local_8 * 0x5b20) == arg_2)) {
        cVar1 = (&DAT_006826dd)[local_c * 0x120 + local_8 * 0x5b20];
        bVar2 = FUN_004af7bb(arg_1,arg_2,arg_3);
        if (((1 << (bVar2 & 0x1f) & (int)cVar1) != 0) &&
           (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + local_c * 0x120 + local_8 * 0x5b20) * 0x34] &
            4) != 0)) {
          FUN_0046e571(local_8,local_c,1);
        }
      }
    }
  }
  return;
}


