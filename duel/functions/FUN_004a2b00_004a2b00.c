/*
 * Decompiled function: FUN_004a2b00
 * Entry Point: 004a2b00
 * Size: 561 bytes
 */
#include "duel.h"


int FUN_004a2b00(int arg_1,int arg_2,int arg_3,int arg_4,int arg_5)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = Pic_Subsystem_00451291(arg_1,arg_3);
  if (iVar2 != -1) {
    *(uint *)(&DAT_006826cc + arg_1 * 0x5b20 + iVar2 * 0x120) =
         CONCAT31((uint3)((arg_1 == 0) - 1 >> 8) & 0x10,2);
    (&DAT_006826dc)[arg_1 * 0x5b20 + iVar2 * 0x120] =
         (&DAT_006826dc)[arg_2 * 0x120 + arg_1 * 0x5b20];
    (&DAT_006826dd)[arg_1 * 0x5b20 + iVar2 * 0x120] =
         (&DAT_006826dd)[arg_2 * 0x120 + arg_1 * 0x5b20];
    (&DAT_006826d3)[arg_1 * 0x5b20 + iVar2 * 0x120] = (undefined1)arg_1;
    *(int *)(&DAT_006826ec + arg_1 * 0x5b20 + iVar2 * 0x120) = arg_2;
    uVar1 = *(uint *)(&DAT_004ff590 +
                     *(int *)(&DAT_006826c4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34);
    iVar3 = FUN_00486c12(*(int *)(&DAT_004ff590 +
                                 *(int *)(&DAT_006826c4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34),
                         arg_1,arg_2);
    *(uint *)(&DAT_00682704 + arg_1 * 0x5b20 + iVar2 * 0x120) = uVar1 | iVar3 << 0x10;
    (&DAT_006826d2)[arg_1 * 0x5b20 + iVar2 * 0x120] = (undefined1)arg_4;
    *(int *)(&DAT_006826e8 + arg_1 * 0x5b20 + iVar2 * 0x120) = arg_5;
    if ((arg_4 != -1) && (arg_5 != -1)) {
      *(uint *)(&DAT_006826fc + arg_4 * 0x5b20 + arg_5 * 0x120) =
           *(uint *)(&DAT_006826fc + arg_4 * 0x5b20 + arg_5 * 0x120) | 0xf000000;
    }
  }
  return iVar2;
}


