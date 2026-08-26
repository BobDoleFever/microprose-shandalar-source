/*
 * Decompiled function: FUN_00408121
 * Entry Point: 00408121
 * Size: 334 bytes
 */
#include "duel.h"


int FUN_00408121(int arg_1,int arg_2,uint arg_3)

{
  int iVar1;
  int local_18;
  int local_14;
  int local_10;
  int local_8;
  
  local_14 = -99;
  local_10 = -1;
  if (arg_2 == -1) {
    local_10 = -1;
  }
  else {
    local_18 = 0;
    while ((local_18 < 500 && (*(int *)(&DAT_006669f0 + local_18 * 4 + arg_2 * 2000) != -1))) {
      iVar1 = *(int *)(&DAT_006669f0 + local_18 * 4 + arg_2 * 2000);
      if ((arg_3 == 0xffffffff) || ((arg_3 & (byte)(&DAT_004ff594)[iVar1 * 0x34]) != 0)) {
        local_8 = Mem_AllocOrFree_004d9810((int)(char)(&DAT_004ff598)[iVar1 * 0x34]);
        local_8 = local_8 + (char)(&DAT_004ff597)[iVar1 * 0x34] * 2;
        if (*(int *)(&DAT_0068ef6c + arg_1 * 0x20) < local_8) {
          local_8 = -local_8;
        }
        if (local_8 == 0) {
          local_8 = 99;
        }
        iVar1 = Pic_Subsystem_00452551(iVar1);
        local_8 = local_8 + iVar1 * 2;
        if (local_14 < local_8) {
          local_10 = local_18;
          local_14 = local_8;
        }
      }
      local_18 = local_18 + 1;
    }
  }
  return local_10;
}


