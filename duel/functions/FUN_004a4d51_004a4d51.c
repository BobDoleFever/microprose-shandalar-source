/*
 * Decompiled function: FUN_004a4d51
 * Entry Point: 004a4d51
 * Size: 1617 bytes
 */
#include "duel.h"


undefined4 FUN_004a4d51(int arg_1,int arg_2,int arg_3)

{
  uint uVar1;
  int iVar2;
  int local_14;
  uint local_c;
  int local_8;
  
  if ((((*(int *)(&DAT_006826e8 + arg_1 * 0x5b20 + arg_2 * 0x120) == DAT_00690c48) &&
       ((char)(&DAT_006826d2)[arg_1 * 0x5b20 + arg_2 * 0x120] == DAT_0068ecb0)) &&
      (DAT_00690c48 != -1)) &&
     (((arg_3 == 0x32 && (((&DAT_006826f0)[arg_1 * 0x5b20 + arg_2 * 0x120] & 4) != 0)) ||
      ((arg_3 == 0x33 && (((&DAT_006826f0)[arg_1 * 0x5b20 + arg_2 * 0x120] & 8) != 0)))))) {
    local_c = 0;
    uVar1 = *(uint *)(&DAT_006826f0 + arg_1 * 0x5b20 + arg_2 * 0x120) & 0xf00;
    if (uVar1 < 0x201) {
      if (uVar1 == 0x200) {
        for (local_14 = 0; local_14 < 2; local_14 = local_14 + 1) {
          if (((*(int *)(&DAT_006826e8 + arg_1 * 0x5b20 + arg_2 * 0x120) == local_14) &&
              (((&DAT_006826f0)[arg_1 * 0x5b20 + arg_2 * 0x120] & 1) != 0)) ||
             ((*(int *)(&DAT_006826e8 + arg_1 * 0x5b20 + arg_2 * 0x120) != local_14 &&
              (((&DAT_006826f0)[arg_1 * 0x5b20 + arg_2 * 0x120] & 2) != 0)))) {
            for (local_8 = 0; local_8 < (int)(&DAT_00666408)[local_14]; local_8 = local_8 + 1) {
              if (((*(int *)(&DAT_006826c4 + local_8 * 0x120 + local_14 * 0x5b20) != -1) &&
                  (((&DAT_006826cc)[local_8 * 0x120 + local_14 * 0x5b20] & 2) != 0)) &&
                 (*(int *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120) ==
                  *(int *)(&DAT_006826c4 + local_8 * 0x120 + local_14 * 0x5b20))) {
                local_c = local_c + 1;
              }
            }
          }
        }
      }
      else if (uVar1 == 0x100) {
        if (((&DAT_006826f0)[arg_1 * 0x5b20 + arg_2 * 0x120] & 1) != 0) {
          iVar2 = FUN_004af74c((int)(char)(&DAT_006826d2)[arg_1 * 0x5b20 + arg_2 * 0x120],
                               *(int *)(&DAT_006826e8 + arg_1 * 0x5b20 + arg_2 * 0x120),
                               *(int *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120));
          local_c = *(uint *)(&DAT_0068ef50 +
                             iVar2 * 4 +
                             (char)(&DAT_006826d2)[arg_1 * 0x5b20 + arg_2 * 0x120] * 0x20);
        }
        if (((&DAT_006826f0)[arg_1 * 0x5b20 + arg_2 * 0x120] & 2) != 0) {
          iVar2 = FUN_004af74c((int)(char)(&DAT_006826d2)[arg_1 * 0x5b20 + arg_2 * 0x120],
                               *(int *)(&DAT_006826e8 + arg_1 * 0x5b20 + arg_2 * 0x120),
                               *(int *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120));
          local_c = local_c + *(int *)(&DAT_0068ef50 +
                                      iVar2 * 4 +
                                      (1 - (char)(&DAT_006826d2)[arg_1 * 0x5b20 + arg_2 * 0x120]) *
                                      0x20);
        }
      }
    }
    else if (uVar1 == 0x400) {
      if (arg_3 == 0x32) {
        local_c = *(uint *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120) & 0xff;
      }
      else {
        local_c = (uint)(byte)(&DAT_006826e5)[arg_1 * 0x5b20 + arg_2 * 0x120];
      }
    }
    else if (uVar1 == 0x800) {
      for (local_14 = 0; local_14 < 2; local_14 = local_14 + 1) {
        if ((((char)(&DAT_006826d2)[arg_1 * 0x5b20 + arg_2 * 0x120] == local_14) &&
            (((&DAT_006826f0)[arg_1 * 0x5b20 + arg_2 * 0x120] & 1) != 0)) ||
           (((char)(&DAT_006826d2)[arg_1 * 0x5b20 + arg_2 * 0x120] != local_14 &&
            (((&DAT_006826f0)[arg_1 * 0x5b20 + arg_2 * 0x120] & 2) != 0)))) {
          for (local_8 = 0; local_8 < (int)(&DAT_00666408)[local_14]; local_8 = local_8 + 1) {
            iVar2 = FUN_0048a33f(local_14,local_8);
            if (((iVar2 != 0) &&
                (((&DAT_004ff594)
                  [*(int *)(&DAT_006826c4 + local_8 * 0x120 + local_14 * 0x5b20) * 0x34] & 2) != 0))
               && ((&DAT_004ff595)
                   [*(int *)(&DAT_006826c4 + local_8 * 0x120 + local_14 * 0x5b20) * 0x34] != '\0'))
            {
              local_c = local_c + 1;
            }
          }
        }
      }
    }
    DAT_0066642c = DAT_0066642c + local_c;
    if (arg_3 == 0x32) {
      *(short *)(&DAT_006826d8 + arg_1 * 0x5b20 + arg_2 * 0x120) = (short)local_c;
    }
    else {
      *(short *)(&DAT_006826da + arg_1 * 0x5b20 + arg_2 * 0x120) = (short)local_c;
    }
  }
  return 0;
}


