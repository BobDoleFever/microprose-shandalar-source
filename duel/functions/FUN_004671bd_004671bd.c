/*
 * Decompiled function: FUN_004671bd
 * Entry Point: 004671bd
 * Size: 1026 bytes
 */
#include "duel.h"


undefined4 FUN_004671bd(int arg_1,int arg_2,int arg_3)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  int arg1;
  int iVar5;
  uint uVar6;
  int local_1c;
  int local_14;
  
  arg1 = 1 - arg_1;
  if (arg_3 == 0x3c) {
    bVar4 = (&DAT_006827df)[arg_2 * 0x120 + arg_1 * 0x5b20];
    bVar2 = FUN_004af7bb(arg_1,arg_2,3);
    bVar3 = FUN_004af7bb(arg_1,arg_2,5);
    (&DAT_006827df)[arg_2 * 0x120 + arg_1 * 0x5b20] =
         bVar4 | (byte)(1 << (bVar2 & 0x1f)) | (byte)(1 << (bVar3 & 0x1f)) | 0x80;
  }
  if (arg_3 == 0x1a) {
    bVar4 = FUN_004af7bb(arg_1,arg_2,3);
    bVar2 = FUN_004af7bb(arg_1,arg_2,5);
    uVar6 = 1 << (bVar4 & 0x1f) | 1 << (bVar2 & 0x1f);
    if ((arg_1 == DAT_00666458) && (((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x44) != 0))
    {
      if ((&DAT_006826de)[arg_2 * 0x120 + arg_1 * 0x5b20] == -1) {
        local_1c = arg_2;
      }
      else {
        local_1c = (int)(char)(&DAT_006826de)[arg_2 * 0x120 + arg_1 * 0x5b20];
      }
      for (local_14 = 0; local_14 < (int)(&DAT_00666408)[arg1]; local_14 = local_14 + 1) {
        if ((((char)(&DAT_006826de)[local_14 * 0x120 + arg1 * 0x5b20] == local_1c) &&
            (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + local_14 * 0x120 + arg1 * 0x5b20) * 0x34] & 2
             ) != 0)) &&
           ((uVar6 & (int)(char)(&DAT_006826dd)[local_14 * 0x120 + arg1 * 0x5b20]) != 0)) {
          FUN_004a2b00(arg_1,arg_2,DAT_006764c0,arg1,local_14);
        }
      }
    }
    if ((arg_1 != DAT_00666458) && ((&DAT_006826de)[arg_2 * 0x120 + arg_1 * 0x5b20] != -1)) {
      cVar1 = (&DAT_006826de)
              [arg1 * 0x5b20 + (char)(&DAT_006826de)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x120];
      if (cVar1 == -1) {
        if ((uVar6 & (int)(char)(&DAT_006826dd)
                                [arg1 * 0x5b20 +
                                 (char)(&DAT_006826de)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x120]) !=
            0) {
          FUN_004a2b00(arg_1,arg_2,DAT_006764c0,arg1,
                       (int)(char)(&DAT_006826de)[arg_2 * 0x120 + arg_1 * 0x5b20]);
        }
      }
      else {
        for (local_14 = 0; local_14 < (int)(&DAT_00666408)[arg1]; local_14 = local_14 + 1) {
          iVar5 = FUN_0048a33f(arg1,local_14);
          if (((iVar5 != 0) && ((&DAT_006826de)[local_14 * 0x120 + arg1 * 0x5b20] == cVar1)) &&
             ((uVar6 & (int)(char)(&DAT_006826dd)[local_14 * 0x120 + arg1 * 0x5b20]) != 0)) {
            FUN_004a2b00(arg_1,arg_2,DAT_006764c0,arg1,local_14);
          }
        }
      }
    }
  }
  return 0;
}


