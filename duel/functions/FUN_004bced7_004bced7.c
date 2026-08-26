/*
 * Decompiled function: FUN_004bced7
 * Entry Point: 004bced7
 * Size: 243 bytes
 */
#include "duel.h"


void FUN_004bced7(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  int iVar2;
  
  if (((arg_3 == 0x7f) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1)) {
    iVar1 = FUN_004af7bb(arg_1,arg_2,5);
    *(int *)(&DAT_00676150 + iVar1 * 4) = *(int *)(&DAT_00676150 + iVar1 * 4) + 3;
  }
  if ((((arg_3 != 0x74) && ((arg_3 == 0x6c || (arg_3 == 199)))) && (DAT_00690c48 == arg_2)) &&
     (DAT_0068ecb0 == arg_1)) {
    iVar1 = FUN_004af7bb(arg_1,arg_2,5);
    iVar1 = *(int *)(&DAT_0068ef50 + iVar1 * 4 + (1 - arg_1) * 0x20);
    iVar2 = FUN_004af7bb(arg_1,arg_2,5);
    DAT_0068f2d4 = DAT_0068f2d4 +
                   ((iVar1 + *(int *)(&DAT_0068ef50 + iVar2 * 4 + arg_1 * 0x20) * -2) * 3 + 3) * 4;
  }
  return;
}


