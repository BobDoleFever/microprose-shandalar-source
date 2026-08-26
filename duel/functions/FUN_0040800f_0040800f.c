/*
 * Decompiled function: FUN_0040800f
 * Entry Point: 0040800f
 * Size: 274 bytes
 */
#include "duel.h"


int FUN_0040800f(int arg1,uint arg2)

{
  int iVar1;
  int iVar2;
  int local_18;
  int local_14;
  int local_10;
  
  local_14 = 0;
  local_10 = -1;
  if (arg1 == -1) {
    local_10 = -1;
  }
  else {
    local_18 = 0;
    while ((local_18 < 500 && (*(int *)(&DAT_0068f370 + local_18 * 4 + arg1 * 2000) != -1))) {
      iVar1 = *(int *)(&DAT_0068f370 + local_18 * 4 + arg1 * 2000);
      if ((arg2 == 0xffffffff) || ((arg2 & (byte)(&DAT_004ff594)[iVar1 * 0x34]) != 0)) {
        iVar2 = Mem_AllocOrFree_004d9810((int)(char)(&DAT_004ff598)[iVar1 * 0x34]);
        iVar1 = (char)(&DAT_004ff597)[iVar1 * 0x34] * 3 + iVar2 * 2;
        if (local_14 < iVar1) {
          local_10 = local_18;
          local_14 = iVar1;
        }
      }
      local_18 = local_18 + 1;
    }
  }
  return local_10;
}


