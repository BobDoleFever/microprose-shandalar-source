/*
 * Decompiled function: FUN_0045d064
 * Entry Point: 0045d064
 * Size: 339 bytes
 */
#include "duel.h"


undefined4 FUN_0045d064(int arg_1,int arg_2,int arg_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int local_8;
  
  if (((arg_3 == 0x1a) && (DAT_00666458 == arg_1)) &&
     (((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 4) != 0)) {
    iVar2 = 1 - arg_1;
    bVar1 = true;
    for (local_8 = 0; local_8 < (int)(&DAT_00666408)[iVar2]; local_8 = local_8 + 1) {
      iVar3 = FUN_0048a33f(iVar2,local_8);
      if ((iVar3 != 0) && ((char)(&DAT_006826de)[local_8 * 0x120 + iVar2 * 0x5b20] == arg_2)) {
        bVar1 = false;
        break;
      }
    }
    if (bVar1) {
      iVar2 = FUN_004a2b00(arg_1,arg_2,DAT_0066aaec,arg_1,arg_2);
      if (iVar2 != -1) {
        *(undefined2 *)(&DAT_006826d8 + arg_1 * 0x5b20 + iVar2 * 0x120) = 2;
        *(undefined2 *)(&DAT_006826da + arg_1 * 0x5b20 + iVar2 * 0x120) = 0;
      }
    }
  }
  return 0;
}


