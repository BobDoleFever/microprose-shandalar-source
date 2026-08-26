/*
 * Decompiled function: FUN_0045962d
 * Entry Point: 0045962d
 * Size: 579 bytes
 */
#include "duel.h"


undefined4 FUN_0045962d(int arg1,int arg2)

{
  bool bVar1;
  int iVar2;
  int local_c;
  int local_8;
  
  local_c = 0;
  bVar1 = false;
  while ((local_c < 2 && (!bVar1))) {
    local_8 = 0;
    while ((local_8 < (int)(&DAT_00666408)[local_c] && (!bVar1))) {
      iVar2 = FUN_0048a33f(local_c,local_8);
      if ((((iVar2 != 0) && ((char)(&DAT_006826d2)[local_8 * 0x120 + local_c * 0x5b20] == arg1)) &&
          (*(int *)(&DAT_006826e8 + local_8 * 0x120 + local_c * 0x5b20) == arg2)) &&
         (((*(int *)(&DAT_006826c4 + local_8 * 0x120 + local_c * 0x5b20) == DAT_00681ec8 &&
           (((&DAT_006826fa)[local_8 * 0x120 + local_c * 0x5b20] & 0x80) != 0)) ||
          (*(int *)(&DAT_006826c4 + local_8 * 0x120 + local_c * 0x5b20) == DAT_00676514)))) {
        bVar1 = true;
      }
      local_8 = local_8 + 1;
    }
    local_c = local_c + 1;
  }
  if (!bVar1) {
    (&DAT_006826e0)[arg2 * 0x120 + arg1 * 0x5b20] = 0;
    *(undefined4 *)(&DAT_00682710 + arg2 * 0x120 + arg1 * 0x5b20) = 0;
    *(undefined2 *)(&DAT_006826d0 + arg2 * 0x120 + arg1 * 0x5b20) = 0;
    FUN_004a7b83(arg1,arg2);
    *(uint *)(&DAT_006826f8 + arg2 * 0x120 + arg1 * 0x5b20) =
         *(uint *)(&DAT_006826f8 + arg2 * 0x120 + arg1 * 0x5b20) & 0xffffff7f;
    (&DAT_006826de)[arg2 * 0x120 + arg1 * 0x5b20] = 0xff;
    *(uint *)(&DAT_006826cc + arg2 * 0x120 + arg1 * 0x5b20) =
         *(uint *)(&DAT_006826cc + arg2 * 0x120 + arg1 * 0x5b20) & 0xfffffff3;
  }
  return 0;
}


