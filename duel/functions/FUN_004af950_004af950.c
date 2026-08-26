/*
 * Decompiled function: FUN_004af950
 * Entry Point: 004af950
 * Size: 972 bytes
 */
#include "duel.h"


int FUN_004af950(int arg_1,int arg_2,int arg_3,int arg_4,int arg_5)

{
  int iVar1;
  int iVar2;
  int local_10;
  int local_8;
  
  if (((arg_1 == -1) || (arg_4 == -1)) || (arg_3 < 1)) {
    iVar1 = -1;
  }
  else {
    if (arg_2 == -1) {
      local_8 = arg_1;
    }
    else {
      local_8 = arg_4;
    }
    iVar1 = Pic_Subsystem_00451291(local_8,DAT_0068f104);
    if (iVar1 != -1) {
      *(uint *)(&DAT_006826cc + iVar1 * 0x120 + local_8 * 0x5b20) =
           *(uint *)(&DAT_006826cc + iVar1 * 0x120 + local_8 * 0x5b20) |
           CONCAT31((uint3)((local_8 == 0) - 1 >> 8) & 0x10,2);
      (&DAT_006826d2)[iVar1 * 0x120 + local_8 * 0x5b20] = (undefined1)arg_1;
      *(int *)(&DAT_006826e8 + iVar1 * 0x120 + local_8 * 0x5b20) = arg_2;
      *(int *)(&DAT_006826e4 + iVar1 * 0x120 + local_8 * 0x5b20) = arg_3;
      (&DAT_006826d3)[iVar1 * 0x120 + local_8 * 0x5b20] = (undefined1)arg_4;
      *(int *)(&DAT_006826ec + iVar1 * 0x120 + local_8 * 0x5b20) = arg_5;
      if (arg_5 == -1) {
        *(undefined4 *)(&DAT_00682704 + iVar1 * 0x120 + local_8 * 0x5b20) = 0xef;
      }
      else {
        if ((*(int *)(&DAT_006826c4 + arg_5 * 0x120 + arg_4 * 0x5b20) == -1) ||
           (*(int *)(&DAT_006826c4 + arg_5 * 0x120 + arg_4 * 0x5b20) == DAT_0068eee0)) {
          local_10 = *(int *)(&DAT_006826c0 + arg_5 * 0x120 + arg_4 * 0x5b20);
        }
        else {
          local_10 = *(int *)(&DAT_006826c4 + arg_5 * 0x120 + arg_4 * 0x5b20);
        }
        (&DAT_006826dd)[iVar1 * 0x120 + local_8 * 0x5b20] =
             (&DAT_006826dd)[arg_5 * 0x120 + arg_4 * 0x5b20];
        if (((&DAT_004ff594)[local_10 * 0x34] & 0x40) != 0) {
          (&DAT_006826dd)[iVar1 * 0x120 + local_8 * 0x5b20] =
               (&DAT_006826dd)[iVar1 * 0x120 + local_8 * 0x5b20] | 0x40;
        }
        *(uint *)(&DAT_006826f0 + iVar1 * 0x120 + local_8 * 0x5b20) =
             (uint)(byte)(&DAT_004ff594)[local_10 * 0x34];
        if ((*(int *)(&DAT_004ff590 + local_10 * 0x34) == DAT_00666444) ||
           (*(int *)(&DAT_004ff590 + local_10 * 0x34) == DAT_0066aae8)) {
          *(undefined4 *)(&DAT_00682704 + iVar1 * 0x120 + local_8 * 0x5b20) =
               *(undefined4 *)(&DAT_00682704 + arg_5 * 0x120 + arg_4 * 0x5b20);
        }
        else {
          iVar2 = FUN_00486c12(*(int *)(&DAT_004ff590 + local_10 * 0x34),arg_4,arg_5);
          *(uint *)(&DAT_00682704 + iVar1 * 0x120 + local_8 * 0x5b20) =
               iVar2 << 0x10 | *(uint *)(&DAT_004ff590 + local_10 * 0x34);
        }
      }
      DAT_00681eb0 = DAT_00681eb0 | 2;
    }
  }
  return iVar1;
}


