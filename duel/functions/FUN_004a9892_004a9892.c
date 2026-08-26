/*
 * Decompiled function: FUN_004a9892
 * Entry Point: 004a9892
 * Size: 178 bytes
 */
#include "duel.h"


undefined4 FUN_004a9892(int arg1,int arg2)

{
  int iVar1;
  
  if (((&DAT_006826cc)[arg2 * 0x120 + arg1 * 0x5b20] & 4) != 0) {
    iVar1 = FUN_004a2b00(DAT_005dcd60,DAT_005dcd64,DAT_0066aaec,arg1,arg2);
    if (iVar1 != -1) {
      *(undefined2 *)(&DAT_006826d8 + iVar1 * 0x120 + DAT_005dcd60 * 0x5b20) = 1;
      *(undefined2 *)(&DAT_006826da + iVar1 * 0x120 + DAT_005dcd60 * 0x5b20) = 1;
    }
  }
  return 0;
}


