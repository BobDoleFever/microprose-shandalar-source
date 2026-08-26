/*
 * Decompiled function: FUN_00476868
 * Entry Point: 00476868
 * Size: 317 bytes
 */
#include "duel.h"


void FUN_00476868(int arg_1)

{
  undefined4 uVar1;
  int local_c;
  
  uVar1 = DAT_005ef980;
  DAT_005ef980 = 2;
  FUN_00473a32(arg_1);
  DAT_005226a0 = (uint)(DAT_00676510 != arg_1);
  DAT_00522ef0 = 0xffffd8f1;
  for (local_c = 0; local_c < 0x10; local_c = local_c + 1) {
    *(undefined4 *)(&DAT_00522620 + local_c * 4) = 0;
  }
  FUN_004769a5(arg_1,0);
  if ((DAT_0066aaf4 == 1) || (DAT_00666458 == DAT_00676510)) {
    for (local_c = 0; local_c < DAT_00522a04; local_c = local_c + 1) {
      (&DAT_006826de)[DAT_00522908 * 0x5b20 + (&DAT_00522f38)[local_c] * 0x120] =
           (&DAT_005226a8)[local_c * 4];
      if (DAT_0066aaf4 != 1) {
        FUN_00450eb8(DAT_00522908,(&DAT_00522f38)[local_c],5,2);
      }
    }
  }
  DAT_005ef980 = uVar1;
  return;
}


