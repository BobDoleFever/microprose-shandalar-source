/*
 * Decompiled function: FUN_00478d48
 * Entry Point: 00478d48
 * Size: 243 bytes
 */
#include "duel.h"


undefined4 FUN_00478d48(int arg_1)

{
  int local_8;
  
  for (local_8 = 0; local_8 < DAT_00522a04; local_8 = local_8 + 1) {
    *(uint *)(&DAT_006826cc + (1 - arg_1) * 0x5b20 + (&DAT_00522f38)[local_8] * 0x120) =
         *(uint *)(&DAT_006826cc + (1 - arg_1) * 0x5b20 + (&DAT_00522f38)[local_8] * 0x120) &
         0xfffffff7;
  }
  for (local_8 = 0; local_8 < (int)(&DAT_00666408)[arg_1]; local_8 = local_8 + 1) {
    if (((&DAT_006826cc)[local_8 * 0x120 + arg_1 * 0x5b20] & 4) != 0) {
      *(uint *)(&DAT_006826cc + local_8 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&DAT_006826cc + local_8 * 0x120 + arg_1 * 0x5b20) & 0xfffffffb;
      *(uint *)(&DAT_006826cc + local_8 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&DAT_006826cc + local_8 * 0x120 + arg_1 * 0x5b20) | 0x40;
    }
  }
  return 1;
}


