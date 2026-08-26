/*
 * Decompiled function: FUN_004769a5
 * Entry Point: 004769a5
 * Size: 388 bytes
 */
#include "duel.h"


void FUN_004769a5(undefined4 arg1,int arg2)

{
  int iVar1;
  int local_c;
  
  if (arg2 == DAT_00522a04) {
    iVar1 = FUN_00476b29();
    if (DAT_00522ef0 < iVar1) {
      DAT_00522ef0 = iVar1;
      FID_conflict__memcpy(&DAT_005226a8,&DAT_00522840,0x1c);
      DAT_00522880 = DAT_00522e68;
    }
  }
  else {
    iVar1 = (&DAT_00522f38)[arg2] * 0x120 + DAT_00522908 * 0x5b20;
    if ((((&DAT_006826cd)[iVar1] & 0x80) == 0) || ((&DAT_006826de)[iVar1] == -1)) {
      *(undefined4 *)(&DAT_00522840 + arg2 * 4) = 0xffffffff;
      FUN_004769a5(arg1,arg2 + 1);
    }
    for (local_c = 0; local_c < DAT_0052297c; local_c = local_c + 1) {
      if (((*(int *)(&DAT_00522a28 + local_c * 4) < DAT_00522770) &&
          (((&DAT_00522778)[local_c] & 1 << ((byte)arg2 & 0x1f)) != 0)) &&
         ((((&DAT_006826cd)[iVar1] & 0x80) == 0 ||
          ((int)(char)(&DAT_006826de)[iVar1] == (&DAT_005225a0)[local_c])))) {
        *(int *)(&DAT_00522a28 + local_c * 4) = *(int *)(&DAT_00522a28 + local_c * 4) + 1;
        *(undefined4 *)(&DAT_00522840 + arg2 * 4) = (&DAT_005225a0)[local_c];
        FUN_004769a5(arg1,arg2 + 1);
        *(int *)(&DAT_00522a28 + local_c * 4) = *(int *)(&DAT_00522a28 + local_c * 4) + -1;
      }
    }
  }
  return;
}


