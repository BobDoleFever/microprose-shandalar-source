/*
 * Decompiled function: FUN_004cb223
 * Entry Point: 004cb223
 * Size: 1143 bytes
 */
#include "duel.h"


undefined4 FUN_004cb223(int arg_1,int arg_2,int arg_3)

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
    if (((arg_3 == 0x6c) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1)) {
      iVar2 = FUN_00404b06(arg_1,*(int *)(&DAT_006826c4 + arg_2 * 0x120 + arg_1 * 0x5b20),-1);
      if (iVar2 == 0) {
        DAT_0068f2d4 = DAT_0068f2d4 +
                       (*(int *)(&DAT_0068edfc + (1 - arg_1) * 0x20) -
                       *(int *)(&DAT_0068edfc + arg_1 * 0x20));
      }
      (&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] = (undefined1)arg_1;
    }
    if (((arg_3 == 0x85) && (DAT_00690c48 == arg_2)) &&
       ((DAT_0068ecb0 == arg_1 && ((DAT_00666458 == arg_1 && (DAT_00666458 == DAT_00681eb4)))))) {
      *(uint *)(&DAT_006827d4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&DAT_006827d4 + arg_2 * 0x120 + arg_1 * 0x5b20) | 1;
      (&DAT_006827da)[arg_2 * 0x120 + arg_1 * 0x5b20] =
           (&DAT_006827da)[arg_2 * 0x120 + arg_1 * 0x5b20] + '\x01';
    }
    if (arg_3 == 0x86) {
      FUN_0046e571(DAT_00690af0,DAT_0068efa0,1);
    }
    if (arg_3 == 199) {
      if ((int)(&DAT_0068ef58)[arg_1 * 8] < 1) {
        FUN_0046e571(arg_1,arg_2,1);
      }
      else {
        iVar2 = (&DAT_00666408)[DAT_00676504];
        if ((int)(&DAT_00666408)[DAT_00676504] <= (int)(&DAT_00666408)[DAT_00676510]) {
          iVar2 = (&DAT_00666408)[DAT_00676510];
        }
        local_c = 0;
        for (local_8 = 0; local_8 < iVar2; local_8 = local_8 + 1) {
          if (((*(int *)(&DAT_006826c4 + local_8 * 0x120 + DAT_00676510 * 0x5b20) != -1) &&
              (((&DAT_006826cc)[local_8 * 0x120 + DAT_00676510 * 0x5b20] & 2) != 0)) &&
             (((&DAT_004ff594)
               [*(int *)(&DAT_006826c4 + local_8 * 0x120 + DAT_00676510 * 0x5b20) * 0x34] & 2) != 0)
             ) {
            if (((&DAT_006826cc)[local_8 * 0x120 + DAT_00676510 * 0x5b20] & 0x10) == 0) {
              iVar3 = FUN_0048af80(DAT_00676510,local_8);
              if (iVar3 == 0) {
                local_c = local_c + *(short *)(&DAT_006826d4 +
                                              local_8 * 0x120 + DAT_00676510 * 0x5b20);
              }
            }
            else {
              local_c = local_c + *(short *)(&DAT_006826d4 + local_8 * 0x120 + DAT_00676510 * 0x5b20
                                            ) * 2;
            }
          }
          if (((*(int *)(&DAT_006826c4 + local_8 * 0x120 + DAT_00676504 * 0x5b20) != -1) &&
              (((&DAT_006826cc)[local_8 * 0x120 + DAT_00676504 * 0x5b20] & 2) != 0)) &&
             (((&DAT_004ff594)
               [*(int *)(&DAT_006826c4 + local_8 * 0x120 + DAT_00676504 * 0x5b20) * 0x34] & 2) != 0)
             ) {
            if (((&DAT_006826cc)[local_8 * 0x120 + DAT_00676504 * 0x5b20] & 0x10) == 0) {
              iVar3 = FUN_0048af80(DAT_00676504,local_8);
              if (iVar3 == 0) {
                local_c = local_c - *(short *)(&DAT_006826d4 +
                                              local_8 * 0x120 + DAT_00676504 * 0x5b20);
              }
            }
            else {
              local_c = local_c + *(short *)(&DAT_006826d4 + local_8 * 0x120 + DAT_00676504 * 0x5b20
                                            ) * -2;
            }
          }
        }
        DAT_0068f2d4 = DAT_0068f2d4 + local_c * 0xc;
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}


