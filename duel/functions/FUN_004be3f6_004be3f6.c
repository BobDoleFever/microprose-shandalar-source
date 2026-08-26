/*
 * Decompiled function: FUN_004be3f6
 * Entry Point: 004be3f6
 * Size: 1208 bytes
 */
#include "duel.h"


undefined4 FUN_004be3f6(int arg_1,int arg_2,int arg_3)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int local_10;
  int local_8;
  
  if (arg_3 == 0x74) {
    uVar2 = 1;
  }
  else {
    if (arg_3 == 0x71) {
      FUN_00467d65(FUN_004be8ae,-1);
    }
    if ((arg_3 == 0x3c) && ((DAT_00681eb0._2_1_ & 2) == 0)) {
      iVar3 = FUN_0048a33f(arg_1,arg_2);
      if ((iVar3 != 0) &&
         ((DAT_00690c48 != -1 && (((&DAT_004ff594)[DAT_0066642c * 0x34] & 0x42) == 0x40)))) {
        local_10 = 0;
        bVar1 = false;
        while( true ) {
          iVar3 = (&DAT_00666408)[DAT_00676504];
          if ((int)(&DAT_00666408)[DAT_00676504] <= (int)(&DAT_00666408)[DAT_00676510]) {
            iVar3 = (&DAT_00666408)[DAT_00676510];
          }
          if ((iVar3 <= local_10) || (bVar1)) break;
          if (((*(int *)(&DAT_006826c4 + local_10 * 0x120 + DAT_00676510 * 0x5b20) == DAT_00666750)
              && (((&DAT_006826cc)[local_10 * 0x120 + DAT_00676510 * 0x5b20] & 2) != 0)) &&
             (((char)(&DAT_006826d2)[local_10 * 0x120 + DAT_00676510 * 0x5b20] == DAT_0068ecb0 &&
              (*(int *)(&DAT_006826e8 + local_10 * 0x120 + DAT_00676510 * 0x5b20) == DAT_00690c48)))
             ) {
            bVar1 = true;
          }
          if (((*(int *)(&DAT_006826c4 + local_10 * 0x120 + DAT_00676504 * 0x5b20) == DAT_00666750)
              && (((&DAT_006826cc)[local_10 * 0x120 + DAT_00676504 * 0x5b20] & 2) != 0)) &&
             (((char)(&DAT_006826d2)[local_10 * 0x120 + DAT_00676504 * 0x5b20] == DAT_0068ecb0 &&
              (*(int *)(&DAT_006826e8 + local_10 * 0x120 + DAT_00676504 * 0x5b20) == DAT_00690c48)))
             ) {
            bVar1 = true;
          }
          local_10 = local_10 + 1;
        }
        if (!bVar1) {
          iVar3 = FUN_004af68f(*(int *)(&DAT_006826c4 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120
                                       ));
          if (iVar3 != -1) {
            iVar4 = FUN_004a2b00(arg_1,arg_2,DAT_00666750,DAT_0068ecb0,DAT_00690c48);
            if (iVar4 != -1) {
              *(int *)(&DAT_006826c8 + iVar4 * 0x120 + arg_1 * 0x5b20) = iVar3;
              *(uint *)(&DAT_006826f8 + iVar4 * 0x120 + arg_1 * 0x5b20) =
                   *(uint *)(&DAT_006826f8 + iVar4 * 0x120 + arg_1 * 0x5b20) | 0x10020;
              FUN_0041bcf0(&local_8,0,arg_1,2,2,0x200,0,0,0,0,0,0,
                           *(undefined4 *)(&DAT_006826c4 + arg_2 * 0x120 + arg_1 * 0x5b20),
                           0xffffffff,0xffffffff,0xffffffff,0,0,0);
              *(int *)(&DAT_006826f0 + iVar4 * 0x120 + arg_1 * 0x5b20) = local_8;
            }
            (&DAT_004ff594)[iVar3 * 0x34] = 0x42;
            *(short *)(&DAT_004ff59c + iVar3 * 0x34) =
                 (short)(char)(&DAT_004ff597)
                              [*(int *)(&DAT_006826c4 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120
                                       ) * 0x34] +
                 (short)(char)(&DAT_004ff598)
                              [*(int *)(&DAT_006826c4 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120
                                       ) * 0x34];
            *(undefined2 *)(&DAT_004ff59a + iVar3 * 0x34) =
                 *(undefined2 *)(&DAT_004ff59c + iVar3 * 0x34);
            *(code **)(&DAT_004ff5a0 + iVar3 * 0x34) = Mem_AllocOrFree_004521d0;
            *(undefined4 *)(&DAT_004ff5a8 + iVar3 * 0x34) = 0x8000;
            (&DAT_004ff596)[iVar3 * 0x34] = 1;
          }
        }
      }
    }
    if (((arg_3 == 0x77) && (DAT_00690c48 == arg_2)) && (arg_1 == DAT_0068ecb0)) {
      FUN_00467d65(FUN_004be8ee,-1);
    }
    uVar2 = 0;
  }
  return uVar2;
}


