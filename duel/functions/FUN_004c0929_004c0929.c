/*
 * Decompiled function: FUN_004c0929
 * Entry Point: 004c0929
 * Size: 502 bytes
 */
#include "duel.h"


undefined4 FUN_004c0929(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  int local_10;
  int local_c;
  
  if (arg_3 == 0x73) {
    if ((((*(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x20010) == 0) &&
        (((&DAT_0066aad0)[(1 - arg_1) * 4] & 0x40) != 0)) &&
       ((iVar1 = FUN_0049b309(arg_1,7,3), iVar1 != 0 &&
        (iVar1 = FUN_0049b309(arg_1,4,2), iVar1 != 0)))) {
      uVar2 = 1;
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    if (arg_3 == 0x6d) {
      DAT_0068ece0 = 1;
      Ai_CalcManaRequirement_004ba890(arg_1,4,2);
      if (local_10 == -1) {
        DAT_00681ea4 = 1;
      }
      else {
        iVar1 = FUN_004bf853(DAT_0068eef0,local_10);
        *(uint *)(&DAT_006826f8 + iVar1 * 0x120 + (1 - DAT_0068eef0) * 0x5b20) =
             *(uint *)(&DAT_006826f8 + iVar1 * 0x120 + (1 - DAT_0068eef0) * 0x5b20) | 0x400;
      }
      *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
    }
    if (((arg_3 == 0x77) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1)) {
      for (local_c = 0; local_c < (int)(&DAT_00666408)[1 - arg_1]; local_c = local_c + 1) {
        if (((&DAT_006826f9)[local_c * 0x120 + (1 - arg_1) * 0x5b20] & 4) != 0) {
          iVar1 = FUN_004bf853(1 - arg_1,local_c);
          *(uint *)(&DAT_006826f8 + iVar1 * 0x120 + arg_1 * 0x5b20) =
               *(uint *)(&DAT_006826f8 + iVar1 * 0x120 + arg_1 * 0x5b20) & 0xfffffbff;
        }
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}


