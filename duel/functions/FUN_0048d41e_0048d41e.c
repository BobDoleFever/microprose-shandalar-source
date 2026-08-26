/*
 * Decompiled function: FUN_0048d41e
 * Entry Point: 0048d41e
 * Size: 1114 bytes
 */
#include "duel.h"


undefined4 FUN_0048d41e(undefined4 arg_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  
  iVar6 = DAT_006764b8 + -1;
  iVar1 = (&DAT_0068efb0)[iVar6 * 2];
  iVar2 = *(int *)(&DAT_0068efb4 + iVar6 * 8);
  if (*(int *)(&DAT_006826c4 + iVar2 * 0x120 + iVar1 * 0x5b20) == DAT_0068eee0) {
    uVar3 = *(undefined4 *)(&DAT_006827b4 + iVar2 * 0x120 + iVar1 * 0x5b20);
    uVar4 = *(undefined4 *)(&DAT_006827b0 + iVar2 * 0x120 + iVar1 * 0x5b20);
    uVar5 = *(undefined4 *)(&DAT_006826f4 + iVar2 * 0x120 + iVar1 * 0x5b20);
    FID_conflict__memcpy
              (&DAT_006826c0 + iVar1 * 0x5b20 + iVar2 * 0x120,
               &DAT_006826c0 +
               *(int *)(&DAT_006827b0 + iVar2 * 0x120 + iVar1 * 0x5b20) * 0x5b20 +
               *(int *)(&DAT_006827b4 + iVar2 * 0x120 + iVar1 * 0x5b20) * 0x120,0x120);
    *(int *)(&DAT_006826c4 + iVar2 * 0x120 + iVar1 * 0x5b20) = DAT_0068eee0;
    *(undefined4 *)(&DAT_00682710 + iVar2 * 0x120 + iVar1 * 0x5b20) = 0;
    (&DAT_006826e0)[iVar2 * 0x120 + iVar1 * 0x5b20] = 0;
    *(uint *)(&DAT_006826cc + iVar2 * 0x120 + iVar1 * 0x5b20) =
         *(uint *)(&DAT_006826cc + iVar2 * 0x120 + iVar1 * 0x5b20) | 2;
    *(undefined4 *)(&DAT_006827b0 + iVar2 * 0x120 + iVar1 * 0x5b20) = uVar4;
    *(undefined4 *)(&DAT_006827b4 + iVar2 * 0x120 + iVar1 * 0x5b20) = uVar3;
    *(undefined4 *)(&DAT_006826f4 + iVar2 * 0x120 + iVar1 * 0x5b20) = uVar5;
    if (*(int *)(&DAT_006826c4 +
                *(int *)(&DAT_006827b4 + iVar2 * 0x120 + iVar1 * 0x5b20) * 0x120 +
                *(int *)(&DAT_006827b0 + iVar2 * 0x120 + iVar1 * 0x5b20) * 0x5b20) != -1) {
      *(undefined4 *)(&DAT_006826c0 + iVar2 * 0x120 + iVar1 * 0x5b20) =
           *(undefined4 *)
            (&DAT_006826c4 +
            *(int *)(&DAT_006827b4 + iVar2 * 0x120 + iVar1 * 0x5b20) * 0x120 +
            *(int *)(&DAT_006827b0 + iVar2 * 0x120 + iVar1 * 0x5b20) * 0x5b20);
    }
    if ((*(int *)(&DAT_006826c0 + iVar2 * 0x120 + iVar1 * 0x5b20) < DAT_0068f104) ||
       (DAT_0068f104 + 0x1d <= *(int *)(&DAT_006826c0 + iVar2 * 0x120 + iVar1 * 0x5b20))) {
      *(undefined4 *)(&DAT_00682704 + iVar2 * 0x120 + iVar1 * 0x5b20) =
           *(undefined4 *)
            (&DAT_004ff590 +
            *(int *)(&DAT_006826c0 +
                    *(int *)(&DAT_006827b4 + iVar2 * 0x120 + iVar1 * 0x5b20) * 0x120 +
                    *(int *)(&DAT_006827b0 + iVar2 * 0x120 + iVar1 * 0x5b20) * 0x5b20) * 0x34);
    }
  }
  if (DAT_0066aaf4 != 1) {
    *(undefined4 *)(&DAT_00666460 + iVar6 * 4) = arg_1;
  }
  *(int *)(&DAT_0068f120 + iVar6 * 8) = (int)(char)(&DAT_006826d2)[iVar2 * 0x120 + iVar1 * 0x5b20];
  *(undefined4 *)(&DAT_0068f124 + iVar6 * 8) =
       *(undefined4 *)(&DAT_006826e8 + iVar2 * 0x120 + iVar1 * 0x5b20);
  return 0;
}


