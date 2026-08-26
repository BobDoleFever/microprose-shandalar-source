/*
 * Decompiled function: FUN_004550fc
 * Entry Point: 004550fc
 * Size: 960 bytes
 */
#include "duel.h"


undefined4 FUN_004550fc(int arg_1,int arg_2,int arg_3)

{
  char cVar1;
  uint uVar2;
  int arg1;
  int iVar3;
  int iVar4;
  
  if (((((arg_3 == 0x6e) &&
        (*(int *)(&DAT_006826c4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) == DAT_0068f104)) &&
       (*(int *)(&DAT_006826e8 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) == -1)) &&
      (((char)(&DAT_006826d3)[DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20] == arg_1 &&
       (*(int *)(&DAT_006826ec + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) == arg_2)))) &&
     (*(int *)(&DAT_006826e4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) != 0)) {
    (&DAT_006826d3)[arg_1 * 0x5b20 + arg_2 * 0x120] = (undefined1)DAT_0068ecb0;
    *(int *)(&DAT_006826ec + arg_1 * 0x5b20 + arg_2 * 0x120) = DAT_00690c48;
  }
  if (((DAT_0068f230 == 0xd7) && (arg_2 == DAT_00690c48)) &&
     ((arg_1 == DAT_0068ecb0 &&
      (((&DAT_006826d3)[arg_1 * 0x5b20 + arg_2 * 0x120] != -1 && (arg_1 == DAT_00681ec4)))))) {
    if (arg_3 == 0x7d) {
      DAT_0066642c = DAT_0066642c | 2;
    }
    if (arg_3 == 0x7e) {
      cVar1 = (&DAT_006826d3)[arg_1 * 0x5b20 + arg_2 * 0x120];
      arg1 = (int)cVar1;
      iVar3 = Pic_Subsystem_00451291(arg1,DAT_0066aaf8);
      if (iVar3 != -1) {
        *(uint *)(&DAT_006826cc + arg1 * 0x5b20 + iVar3 * 0x120) =
             *(uint *)(&DAT_006826cc + arg1 * 0x5b20 + iVar3 * 0x120) | 2;
        *(uint *)(&DAT_006826f8 + arg1 * 0x5b20 + iVar3 * 0x120) =
             *(uint *)(&DAT_006826f8 + arg1 * 0x5b20 + iVar3 * 0x120) | 8;
        (&DAT_006826dd)[arg1 * 0x5b20 + iVar3 * 0x120] =
             (&DAT_006826dd)[arg_1 * 0x5b20 + arg_2 * 0x120];
        uVar2 = *(uint *)(&DAT_004ff590 +
                         *(int *)(&DAT_006826c4 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x34);
        iVar4 = FUN_00486c12(*(int *)(&DAT_004ff590 +
                                     *(int *)(&DAT_006826c4 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x34
                                     ),arg_1,arg_2);
        *(uint *)(&DAT_00682704 + arg1 * 0x5b20 + iVar3 * 0x120) = uVar2 | iVar4 << 0x10;
        (&DAT_006826d3)[arg1 * 0x5b20 + iVar3 * 0x120] = (undefined1)arg_1;
        *(int *)(&DAT_006826ec + arg1 * 0x5b20 + iVar3 * 0x120) = arg_2;
        (&DAT_006826d2)[arg1 * 0x5b20 + iVar3 * 0x120] = cVar1;
        *(undefined4 *)(&DAT_006826e8 + arg1 * 0x5b20 + iVar3 * 0x120) = 0xffffffff;
      }
      (&DAT_006826d3)[arg_1 * 0x5b20 + arg_2 * 0x120] = 0xff;
    }
  }
  return 0;
}


