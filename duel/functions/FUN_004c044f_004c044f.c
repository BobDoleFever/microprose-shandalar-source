/*
 * Decompiled function: FUN_004c044f
 * Entry Point: 004c044f
 * Size: 1242 bytes
 */
#include "duel.h"


undefined4 FUN_004c044f(int arg_1,int arg_2,int arg_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int local_c;
  
  if (arg_3 == 0x73) {
    if (((*(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x20010) == 0) &&
       (((&DAT_0066aad0)[(1 - arg_1) * 4] & 2) != 0)) {
      return 1;
    }
    return 0;
  }
  if (arg_3 != 0x6d) goto LAB_004c056f;
  if (local_c == -1) {
LAB_004c0545:
    DAT_00681ea4 = 1;
  }
  else {
    iVar2 = FUN_0048b81a(arg_1,arg_2,0x32,0xffffffff);
    iVar3 = FUN_0048b81a(DAT_0068eef0,local_c,0x32,0xffffffff);
    if (iVar2 < iVar3) goto LAB_004c0545;
    *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) = local_c;
    (&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] = (undefined1)DAT_0068eef0;
  }
  *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
       *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
LAB_004c056f:
  if ((arg_3 == 0x72) && (*(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) != -1)) {
    uVar4 = FUN_004bf853((int)(char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20],
                         *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20));
    *(undefined4 *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) = uVar4;
    (&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] = (undefined1)arg_1;
  }
  if (((((&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] != -1) && (DAT_00690c48 == arg_2)) &&
      (DAT_0068ecb0 == arg_1)) && (*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) == 0)) {
    *(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 1;
    bVar1 = true;
    if (((arg_3 == 0x77) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1)) {
      bVar1 = false;
    }
    if (((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0) {
      bVar1 = false;
    }
    iVar2 = FUN_0048b81a(arg_1,arg_2,0x32,0xffffffff);
    iVar3 = FUN_0048b81a((int)(char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20],
                         *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20),0x32,0xffffffff);
    if (iVar2 < iVar3) {
      bVar1 = false;
    }
    if (!bVar1) {
      iVar2 = *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20);
      *(undefined4 *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0xffffffff;
      (&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] =
           (&DAT_006826e8)[arg_2 * 0x120 + arg_1 * 0x5b20];
      FUN_004bf853(arg_1,iVar2);
    }
    *(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
  }
  if (((arg_3 == 0x77) && (*(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) == DAT_00690c48)
      ) && (((char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] == DAT_0068ecb0 &&
            (DAT_00690c48 != -1)))) {
    *(undefined4 *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0xffffffff;
    (&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] =
         (&DAT_006826e8)[arg_2 * 0x120 + arg_1 * 0x5b20];
  }
  return 0;
}


