/*
 * Decompiled function: FUN_004c1a69
 * Entry Point: 004c1a69
 * Size: 314 bytes
 */
#include "duel.h"


undefined4 FUN_004c1a69(int arg1,int arg2)

{
  *(int *)(&DAT_0068270c +
          *(int *)(&DAT_006826e8 + arg1 * 0x5b20 + arg2 * 0x120) * 0x120 +
          (char)(&DAT_006826d2)[arg1 * 0x5b20 + arg2 * 0x120] * 0x5b20) =
       *(int *)(&DAT_0068270c +
               *(int *)(&DAT_006826e8 + arg1 * 0x5b20 + arg2 * 0x120) * 0x120 +
               (char)(&DAT_006826d2)[arg1 * 0x5b20 + arg2 * 0x120] * 0x5b20) + 0x100;
  if (DAT_0066aaf4 != 1) {
    FUN_0048d00c(0x1b);
  }
  *(short *)(&DAT_006826da +
            *(int *)(&DAT_006826e8 + arg1 * 0x5b20 + arg2 * 0x120) * 0x120 +
            (char)(&DAT_006826d2)[arg1 * 0x5b20 + arg2 * 0x120] * 0x5b20) =
       *(short *)(&DAT_006826da +
                 *(int *)(&DAT_006826e8 + arg1 * 0x5b20 + arg2 * 0x120) * 0x120 +
                 (char)(&DAT_006826d2)[arg1 * 0x5b20 + arg2 * 0x120] * 0x5b20) + -2;
  return 0;
}


