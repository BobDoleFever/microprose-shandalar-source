/*
 * Decompiled function: FUN_004d1597
 * Entry Point: 004d1597
 * Size: 1054 bytes
 */
#include "duel.h"


undefined4 FUN_004d1597(int arg_1,int arg_2,int arg_3)

{
  short sVar1;
  char cVar2;
  char cVar3;
  short sVar4;
  undefined4 uVar5;
  int iVar6;
  
  if (arg_3 == 0x74) {
    uVar5 = 1;
  }
  else if (arg_3 == 0x73) {
    iVar6 = FUN_004680fc(arg_1,arg_2);
    if ((iVar6 != 0) && (iVar6 = FUN_0049b68d(arg_1,arg_2,7,5), iVar6 != 0)) {
      if ((arg_1 == DAT_00676504) && (0 < DAT_0068f2c0)) {
        DAT_00676500 = DAT_00676500 | 3;
      }
      return 1;
    }
    uVar5 = 0;
  }
  else {
    if ((((arg_3 == 0x6d) && (iVar6 = FUN_0049b68d(arg_1,arg_2,7,5), iVar6 != 0)) &&
        (FUN_0042ecaf(arg_1,arg_2,0,5), DAT_00681ea4 != 1)) && (0 < DAT_0068f2c0)) {
      DAT_0068f2c0 = DAT_0068f2c0 + -1;
    }
    if (arg_3 == 0x72) {
      if (DAT_0066aaf4 != 1) {
        FUN_0048d00c(0x26);
      }
      iVar6 = FUN_004d7d5e(900);
      iVar6 = Pic_Subsystem_00451291(arg_1,iVar6);
      if (iVar6 != -1) {
        Pic_Subsystem_0042ac1f(arg_1,iVar6);
        cVar2 = FUN_004af7bb(arg_1,arg_2,1);
        (&DAT_006826dd)[iVar6 * 0x120 + arg_1 * 0x5b20] = (char)(2 << (cVar2 - 1U & 0x1f));
        *(uint *)(&DAT_006826f8 + iVar6 * 0x120 + arg_1 * 0x5b20) =
             *(uint *)(&DAT_006826f8 + iVar6 * 0x120 + arg_1 * 0x5b20) | 0x10;
        if (((&DAT_006826f8)[arg_2 * 0x120 + arg_1 * 0x5b20] & 2) != 0) {
          *(uint *)(&DAT_006826f8 + iVar6 * 0x120 + arg_1 * 0x5b20) =
               *(uint *)(&DAT_006826f8 + iVar6 * 0x120 + arg_1 * 0x5b20) | 2;
          (&DAT_006827c0)[iVar6 * 0x120 + arg_1 * 0x5b20] =
               (&DAT_006827c0)[arg_2 * 0x120 + arg_1 * 0x5b20];
        }
        *(undefined4 *)(&DAT_00682704 + iVar6 * 0x120 + arg_1 * 0x5b20) =
             *(undefined4 *)
              (&DAT_004ff590 + *(int *)(&DAT_006826c0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34);
        sVar1 = *(short *)(&DAT_006826d8 + iVar6 * 0x120 + arg_1 * 0x5b20);
        sVar4 = FUN_00439892(3);
        *(short *)(&DAT_006826d8 + iVar6 * 0x120 + arg_1 * 0x5b20) = sVar1 + sVar4;
        sVar1 = *(short *)(&DAT_006826da + iVar6 * 0x120 + arg_1 * 0x5b20);
        sVar4 = FUN_00439892(3);
        *(short *)(&DAT_006826da + iVar6 * 0x120 + arg_1 * 0x5b20) = sVar1 + sVar4;
        FUN_00467eef(DAT_00690af0,DAT_0068efa0);
      }
    }
    if (((arg_3 == 0x77) &&
        (((&DAT_004ff594)
          [*(int *)(&DAT_006826c4 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) * 0x34] & 2) != 0)
        ) && ((((&DAT_006826cc)[DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120] & 0x20) == 0 &&
              (((&DAT_006826e0)[DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120] != '\x04' &&
               (cVar2 = (&DAT_006826dd)[DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120],
               cVar3 = FUN_004af7bb(arg_1,arg_2,1), (2 << (cVar3 - 1U & 0x1f) & (int)cVar2) == 0))))
             )) {
      FUN_00467e37(arg_1,arg_2);
    }
    uVar5 = 0;
  }
  return uVar5;
}


