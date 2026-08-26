/*
 * Decompiled function: FUN_0042db54
 * Entry Point: 0042db54
 * Size: 522 bytes
 */
#include "duel.h"


undefined4 FUN_0042db54(int arg_1,int arg_2,byte arg_3)

{
  int iVar1;
  undefined4 local_c;
  
  iVar1 = *(int *)(&DAT_006826c4 + arg_2 * 0x120 + arg_1 * 0x5b20);
  local_c = 1;
  if (((((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 2) == 0) ||
      (((&DAT_004ff5a9)[iVar1 * 0x34] & 0x10) == 0)) || (((&DAT_004ff5aa)[iVar1 * 0x34] & 1) != 0))
  {
    local_c = 0;
  }
  else {
    if (((arg_3 & 1) != 0) &&
       (((iVar1 < 5 || (*(int *)(&DAT_004ff590 + iVar1 * 0x34) == 0x366)) ||
        ((&DAT_006826dc)[arg_2 * 0x120 + arg_1 * 0x5b20] == '@')))) {
      local_c = 0;
    }
    if ((((arg_3 & 2) != 0) && (((&DAT_004ff594)[iVar1 * 0x34] & 1) != 0)) &&
       ((4 < iVar1 &&
        ((*(int *)(&DAT_004ff590 + iVar1 * 0x34) != 0x366 &&
         ((&DAT_006826dc)[arg_2 * 0x120 + arg_1 * 0x5b20] != '@')))))) {
      local_c = 0;
    }
    if (((arg_3 & 4) != 0) && (((&DAT_006826ce)[arg_2 * 0x120 + arg_1 * 0x5b20] & 4) != 0)) {
      local_c = 0;
    }
    if (((arg_3 & 8) != 0) && (((&DAT_004ff594)[iVar1 * 0x34] & 0x40) != 0)) {
      local_c = 0;
    }
    if (((arg_3 & 0x10) != 0) && (((&DAT_004ff594)[iVar1 * 0x34] & 2) != 0)) {
      local_c = 0;
    }
  }
  return local_c;
}


