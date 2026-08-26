/*
 * Decompiled function: FUN_004bb61e
 * Entry Point: 004bb61e
 * Size: 1340 bytes
 */
#include "duel.h"


undefined4 FUN_004bb61e(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (arg_3 == 0x71) {
      iVar2 = FUN_004af74c(arg_1,arg_2,1);
      iVar2 = FUN_004af68f(iVar2 + -1);
      if (iVar2 != -1) {
        *(int *)(&DAT_006826c8 + arg_2 * 0x120 + arg_1 * 0x5b20) = iVar2;
        *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
             (int)(char)(&DAT_006827c0)[arg_2 * 0x120 + arg_1 * 0x5b20];
        (&DAT_004ff594)[*(int *)(&DAT_006826c8 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34] =
             (&DAT_004ff594)[*(int *)(&DAT_006826c8 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34] | 2;
        *(uint *)(&DAT_004ff5a8 + *(int *)(&DAT_006826c8 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34) =
             *(uint *)(&DAT_004ff5a8 +
                      *(int *)(&DAT_006826c8 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34) | 0x8000;
        *(undefined2 *)
         (&DAT_004ff59a + *(int *)(&DAT_006826c8 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34) = 1;
        *(undefined2 *)
         (&DAT_004ff59c + *(int *)(&DAT_006826c8 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34) = 1;
        (&DAT_004ff597)[*(int *)(&DAT_006826c8 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34] = 1;
      }
    }
    if ((int)(char)(&DAT_006827c0)[arg_2 * 0x120 + arg_1 * 0x5b20] !=
        *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20)) {
      Mem_AllocOrFree_004af72b(*(int *)(&DAT_006826c8 + arg_2 * 0x120 + arg_1 * 0x5b20));
      iVar2 = FUN_004af74c(arg_1,arg_2,1);
      iVar2 = FUN_004af68f(iVar2 + -1);
      if (iVar2 != -1) {
        *(int *)(&DAT_006826c8 + arg_2 * 0x120 + arg_1 * 0x5b20) = iVar2;
        *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
             (int)(char)(&DAT_006827c0)[arg_2 * 0x120 + arg_1 * 0x5b20];
        (&DAT_004ff594)[*(int *)(&DAT_006826c8 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34] =
             (&DAT_004ff594)[*(int *)(&DAT_006826c8 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34] | 2;
        *(uint *)(&DAT_004ff5a8 + *(int *)(&DAT_006826c8 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34) =
             *(uint *)(&DAT_004ff5a8 +
                      *(int *)(&DAT_006826c8 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34) | 0x8000;
        *(undefined2 *)
         (&DAT_004ff59a + *(int *)(&DAT_006826c8 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34) = 1;
        *(undefined2 *)
         (&DAT_004ff59c + *(int *)(&DAT_006826c8 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34) = 1;
        (&DAT_004ff597)[*(int *)(&DAT_006826c8 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34] = 1;
      }
    }
    if ((arg_3 == 0x3c) && (iVar2 = FUN_0048a33f(arg_1,arg_2), iVar2 != 0)) {
      if ((DAT_00681eb0 & 0x20000) == 0) {
        DAT_00681eb0 = DAT_00681eb0 | 0x10000;
      }
      else {
        iVar2 = FUN_0048a33f(DAT_0068ecb0,DAT_00690c48);
        if (((iVar2 != 0) &&
            (iVar3 = DAT_00690c48 * 0x120, iVar4 = DAT_0068ecb0 * 0x5b20,
            iVar2 = FUN_004af74c(arg_1,arg_2,1),
            *(int *)(&DAT_006826c4 + iVar4 + iVar3) == iVar2 + -1)) &&
           ((((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0 ||
            (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34] & 2)
             != 0)))) {
          DAT_0066642c = *(undefined4 *)(&DAT_006826c8 + arg_2 * 0x120 + arg_1 * 0x5b20);
          *(uint *)(&DAT_006826f8 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) =
               *(uint *)(&DAT_006826f8 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) | 0x40;
        }
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}


