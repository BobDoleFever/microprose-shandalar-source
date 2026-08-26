/*
 * Decompiled function: Pic_Subsystem_0042ac1f
 * Entry Point: 004bda20
 * Size: 510 bytes
 */
#include "duel.h"


undefined4 Pic_Subsystem_0042ac1f(int arg1,int arg2)

{
  if ((arg1 != -1) && (arg2 != -1)) {
    if (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + arg1 * 0x5b20 + arg2 * 0x120) * 0x34] & 2) != 0) {
      *(int *)(&DAT_0068ee80 + arg1 * 4) = *(int *)(&DAT_0068ee80 + arg1 * 4) + 1;
    }
    if (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + arg1 * 0x5b20 + arg2 * 0x120) * 0x34] & 0x40) != 0
       ) {
      (&DAT_0068ee88)[arg1] = (&DAT_0068ee88)[arg1] + 1;
    }
    if (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + arg1 * 0x5b20 + arg2 * 0x120) * 0x34] & 4) != 0) {
      *(int *)(&DAT_0068ee90 + arg1 * 4) = *(int *)(&DAT_0068ee90 + arg1 * 4) + 1;
    }
    *(uint *)(&DAT_0066aad0 + arg1 * 4) =
         *(uint *)(&DAT_0066aad0 + arg1 * 4) |
         (uint)(byte)(&DAT_004ff594)[*(int *)(&DAT_006826c4 + arg1 * 0x5b20 + arg2 * 0x120) * 0x34];
    *(uint *)(&DAT_006826cc + arg1 * 0x5b20 + arg2 * 0x120) =
         *(uint *)(&DAT_006826cc + arg1 * 0x5b20 + arg2 * 0x120) | 0x30022;
    FUN_0048c50b(arg1,arg2,0x6c);
    *(uint *)(&DAT_006826cc + arg1 * 0x5b20 + arg2 * 0x120) =
         *(uint *)(&DAT_006826cc + arg1 * 0x5b20 + arg2 * 0x120) |
         CONCAT31((uint3)((arg1 == 0) - 1 >> 8) & 0x4000,0x80);
    FUN_0048c907(arg1,arg2,0x71,1 - arg1,0xffffffff);
    *(uint *)(&DAT_006826cc + arg1 * 0x5b20 + arg2 * 0x120) =
         *(uint *)(&DAT_006826cc + arg1 * 0x5b20 + arg2 * 0x120) & 0xffffffdf;
    DAT_00666754 = arg1;
    DAT_0068edd0 = arg2;
    FUN_0048e8a8(DAT_00666458,0xdb,s_Card_into_play_005088d0,0);
  }
  return 0;
}


