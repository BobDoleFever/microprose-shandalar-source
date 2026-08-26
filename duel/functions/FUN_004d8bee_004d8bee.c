/*
 * Decompiled function: FUN_004d8bee
 * Entry Point: 004d8bee
 * Size: 272 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_004d8bee(undefined4 *arg_1,undefined4 arg_2,undefined4 arg_3)

{
  int iVar1;
  int local_10;
  int local_c;
  int local_8;
  
  local_10 = 0;
  DAT_005ddaa8 = arg_2;
  _DAT_005ddaac = arg_2;
  DAT_005ddab0 = arg_3;
  DAT_005093c8 = 0;
  local_8 = DAT_005ddab4 + -1;
  do {
    do {
      iVar1 = FUN_004d9080();
      if (iVar1 == -1) {
        return local_10;
      }
      if (iVar1 == 0) {
        local_c = *(int *)(&DAT_005ddac4 + local_8 * 8);
      }
      else {
        local_c = *(int *)(&DAT_005ddac0 + local_8 * 8);
      }
      local_8 = local_c - _DAT_005ddab8;
    } while (-1 < local_8);
    if (local_c == 0) {
      iVar1 = FUN_004d8f90(10);
      if (iVar1 < 0) {
        return local_10;
      }
      _memset(arg_1,0,iVar1 << 2);
      arg_1 = arg_1 + iVar1;
      local_10 = local_10 + iVar1;
    }
    else {
      *arg_1 = *(undefined4 *)(DAT_005ddabc + local_c * 4);
      arg_1 = arg_1 + 1;
      local_10 = local_10 + 1;
    }
    local_8 = DAT_005ddab4 + -1;
  } while( true );
}


