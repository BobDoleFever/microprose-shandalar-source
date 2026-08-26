/*
 * Decompiled function: FUN_00460999
 * Entry Point: 00460999
 * Size: 264 bytes
 */
#include "duel.h"


bool FUN_00460999(int arg_1,int arg_2,int arg_3)

{
  bool bVar1;
  
  if (arg_3 == 0x73) {
    bVar1 = (*(uint *)(&DAT_006826cc + arg_1 * 0x5b20 + arg_2 * 0x120) & 0x20010) == 0;
  }
  else if (arg_3 == 0x90) {
    FUN_0043071d(1);
    bVar1 = false;
  }
  else {
    if (arg_3 == 0x6d) {
      FUN_00461047(arg_1,arg_2);
    }
    if (arg_3 == 0x72) {
      FUN_004612b0(arg_1,arg_2,0x72,1);
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b0 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x5b20 +
       *(int *)(&DAT_006827b4 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120] = 0;
    }
    bVar1 = false;
  }
  return bVar1;
}


