/*
 * Decompiled function: FUN_0048b0c7
 * Entry Point: 0048b0c7
 * Size: 391 bytes
 */
#include "duel.h"


undefined4 FUN_0048b0c7(int arg_1)

{
  int x;
  uint arg_5;
  int iVar1;
  int local_18;
  uint local_14;
  uint local_10;
  int local_c;
  uint local_8;
  
  x = 1 - arg_1;
  FUN_00431f41(&local_8,&local_10);
  if (arg_1 == 1) {
    local_14 = local_8;
  }
  else {
    local_14 = local_10;
  }
  local_c = 0;
  do {
    if ((int)(&DAT_00666408)[x] <= local_c) {
      return 0;
    }
    if ((*(int *)(&DAT_006826c4 + local_c * 0x120 + x * 0x5b20) != -1) &&
       (((&DAT_006826cc)[local_c * 0x120 + x * 0x5b20] & 4) != 0)) {
      arg_5 = FUN_0048b81a(x,local_c,0x34,0xffffffff);
      for (local_18 = 0; local_18 < (int)(&DAT_00666408)[arg_1]; local_18 = local_18 + 1) {
        if (((*(int *)(&DAT_006826c4 + local_c * 0x120 + x * 0x5b20) != -1) &&
            (((byte)*(undefined4 *)(&DAT_006826cc + arg_1 * 0x5b20 + local_18 * 0x120) & 0x1a) == 2)
            ) && (iVar1 = FUN_0048b2c9(arg_1,local_18,x,local_c,arg_5,local_14), iVar1 != 0)) {
          return 1;
        }
      }
    }
    local_c = local_c + 1;
  } while( true );
}


