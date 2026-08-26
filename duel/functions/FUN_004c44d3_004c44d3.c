/*
 * Decompiled function: FUN_004c44d3
 * Entry Point: 004c44d3
 * Size: 756 bytes
 */
#include "duel.h"


undefined4 FUN_004c44d3(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  if ((arg_3 == 199) && (((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 2) != 0)) {
    iVar1 = FUN_004af74c(arg_1,arg_2,1);
    if (*(int *)(&DAT_0068ef50 + iVar1 * 4 + DAT_00676510 * 0x20) != 0) {
      iVar1 = 0x18 - (int)(&DAT_00681ea8)[DAT_00676510] /
                     *(int *)(&DAT_0068ef50 + iVar1 * 4 + DAT_00676510 * 0x20);
      if (iVar1 < 2) {
        iVar1 = 1;
      }
      DAT_0068f2d4 = DAT_0068f2d4 + iVar1 * 0x18;
    }
    iVar1 = FUN_004af74c(arg_1,arg_2,1);
    if (*(int *)(&DAT_0068ef50 + iVar1 * 4 + DAT_00676504 * 0x20) != 0) {
      iVar1 = 0x18 - (int)(&DAT_00681ea8)[DAT_00676504] /
                     *(int *)(&DAT_0068ef50 + iVar1 * 4 + DAT_00676504 * 0x20);
      if (iVar1 < 2) {
        iVar1 = 1;
      }
      DAT_0068f2d4 = DAT_0068f2d4 + iVar1 * -0x18;
    }
  }
  if (arg_3 == 0x74) {
    uVar2 = 1;
  }
  else if (arg_3 == 0x73) {
    if (((DAT_0068f2c4 == 4) && (((&DAT_006826e4)[arg_2 * 0x120 + arg_1 * 0x5b20] & 1) == 0)) &&
       ((DAT_00666458 == DAT_00681eb4 &&
        (iVar1 = FUN_004af74c(arg_1,arg_2,1),
        *(int *)(&DAT_0068ef50 + iVar1 * 4 + DAT_00681eb4 * 0x20) != 0)))) {
      *(uint *)(&DAT_006827d4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&DAT_006827d4 + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x101;
      DAT_00676500 = DAT_00676500 | 3;
      return 1;
    }
    uVar2 = 0;
  }
  else {
    if (((arg_3 == 4) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1)) {
      *(uint *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) | 1;
      DAT_006664ec = 1;
      DAT_0066642c = DAT_0066642c | 1;
    }
    if (arg_3 == 0x86) {
      iVar1 = arg_1;
      iVar4 = arg_2;
      iVar3 = FUN_004af74c(arg_1,arg_2,1);
      Mem_AllocOrFree_004afd1c
                (DAT_00666458,*(int *)(&DAT_0068ef50 + iVar3 * 4 + DAT_00666458 * 0x20),iVar1,iVar4)
      ;
    }
    if (arg_3 == 0x22) {
      *(uint *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xfffffffe;
    }
    if (arg_3 == 199) {
      iVar1 = 1 - DAT_00666458;
      iVar4 = FUN_004af74c(arg_1,arg_2,1);
      Mem_AllocOrFree_004afd1c(iVar1,*(int *)(&DAT_0068ef50 + iVar4 * 4 + iVar1 * 0x20),arg_1,arg_2)
      ;
    }
    uVar2 = 0;
  }
  return uVar2;
}


