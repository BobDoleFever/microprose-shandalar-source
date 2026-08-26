/*
 * Decompiled function: FUN_004d7946
 * Entry Point: 004d7946
 * Size: 390 bytes
 */
#include "duel.h"


void FUN_004d7946(int arg_1)

{
  undefined4 uVar1;
  DWORD DVar2;
  int iVar3;
  int local_10;
  int local_c;
  int local_8;
  
  if (DAT_0066aaf4 != 1) {
    FUN_0048d00c(0x21);
    FUN_00446da2(arg_1);
  }
  local_8 = 500;
  local_c = 0;
  do {
    if (499 < local_c) {
LAB_004d79c5:
      local_c = 0;
      while( true ) {
        DVar2 = GetTickCount();
        if ((int)(DVar2 >> 0x10) <= local_c) break;
        _rand();
        local_c = local_c + 1;
      }
      for (local_10 = 0; local_10 < 100; local_10 = local_10 + 1) {
        for (local_c = 0; local_c < local_8; local_c = local_c + 1) {
          iVar3 = FUN_00439892(local_8);
          if (*(int *)(&DAT_006669f0 + iVar3 * 4 + arg_1 * 2000) != -1) {
            uVar1 = *(undefined4 *)(&DAT_006669f0 + iVar3 * 4 + arg_1 * 2000);
            *(undefined4 *)(&DAT_006669f0 + iVar3 * 4 + arg_1 * 2000) =
                 *(undefined4 *)(&DAT_006669f0 + local_c * 4 + arg_1 * 2000);
            *(undefined4 *)(&DAT_006669f0 + local_c * 4 + arg_1 * 2000) = uVar1;
          }
        }
      }
      return;
    }
    if (*(int *)(&DAT_006669f0 + local_c * 4 + arg_1 * 2000) == -1) {
      local_8 = local_c;
      goto LAB_004d79c5;
    }
    local_c = local_c + 1;
  } while( true );
}


