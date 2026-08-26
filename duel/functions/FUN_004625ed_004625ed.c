/*
 * Decompiled function: FUN_004625ed
 * Entry Point: 004625ed
 * Size: 368 bytes
 */
#include "duel.h"


undefined4 FUN_004625ed(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  int local_8;
  
  if (arg_3 == 0x73) {
    if (((*(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x20010) == 0) &&
       (iVar1 = FUN_00467cce(arg_1,0x40), iVar1 != 0)) {
      uVar2 = 1;
    }
    else {
      uVar2 = 0;
    }
  }
  else if (arg_3 == 0x90) {
    FUN_0043071d(0);
    uVar2 = 0;
  }
  else {
    if (arg_3 == 0x6d) {
      iVar1 = FUN_00468a84(arg_1);
      if (iVar1 != 0) {
        if (local_8 == -1) {
          DAT_00681ea4 = 1;
        }
        else {
          *(short *)(&DAT_006826d8 + local_8 * 0x120 + DAT_0068eef0 * 0x5b20) =
               *(short *)(&DAT_006826d8 + local_8 * 0x120 + DAT_0068eef0 * 0x5b20) + 1;
          *(short *)(&DAT_006826da + local_8 * 0x120 + DAT_0068eef0 * 0x5b20) =
               *(short *)(&DAT_006826da + local_8 * 0x120 + DAT_0068eef0 * 0x5b20) + 1;
        }
      }
      *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
    }
    uVar2 = 0;
  }
  return uVar2;
}


