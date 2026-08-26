/*
 * Decompiled function: FUN_004a99f4
 * Entry Point: 004a99f4
 * Size: 221 bytes
 */
#include "duel.h"


undefined4 FUN_004a99f4(int arg1,int arg2)

{
  int iVar1;
  
  if (((&DAT_006826de)[arg2 * 0x120 + arg1 * 0x5b20] != -1) &&
     (((&DAT_006826cc)[arg2 * 0x120 + arg1 * 0x5b20] & 4) == 0)) {
    iVar1 = FUN_004a2b00(DAT_005dcd78,DAT_005dcd74,DAT_0066aaec,arg1,arg2);
    if (iVar1 != -1) {
      *(undefined2 *)(&DAT_006826d8 + DAT_005dcd78 * 0x5b20 + iVar1 * 0x120) = 0;
      *(undefined2 *)(&DAT_006826da + DAT_005dcd78 * 0x5b20 + iVar1 * 0x120) = 3;
    }
  }
  return 0;
}


