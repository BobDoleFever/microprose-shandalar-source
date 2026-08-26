/*
 * Decompiled function: FUN_004c6039
 * Entry Point: 004c6039
 * Size: 258 bytes
 */
#include "duel.h"


undefined4 FUN_004c6039(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if ((arg_3 == 0x81) && (DAT_0068ecb0 != arg_1)) {
      iVar3 = *(int *)(&DAT_006826c4 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120);
      iVar2 = FUN_004af74c(arg_1,arg_2,3);
      if (*(int *)(&DAT_004ff590 + iVar3 * 0x34) == *(int *)(&DAT_0068f0dc + iVar2 * 4)) {
        (&DAT_00681ea8)[arg_1] = (&DAT_00681ea8)[arg_1] + 1;
      }
    }
    if ((((arg_3 == 0x6c) || (arg_3 == 199)) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1))
    {
      iVar3 = FUN_004af74c(arg_1,arg_2,3);
      DAT_0068f2d4 = DAT_0068f2d4 +
                     (*(int *)(&DAT_0068ef50 + iVar3 * 4 + DAT_00676510 * 0x20) * 3 + 3) * 8;
    }
    uVar1 = 0;
  }
  return uVar1;
}


