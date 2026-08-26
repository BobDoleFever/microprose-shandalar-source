/*
 * Decompiled function: FUN_004fd9c0
 * Entry Point: 004fd9c0
 * Size: 274 bytes
 */
#include "magic.h"


int FUN_004fd9c0(int arg1,uint arg2)

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
    while ((local_18 < 500 && (*(int *)(&DAT_006ff710 + local_18 * 4 + arg1 * 2000) != -1))) {
      iVar1 = *(int *)(&DAT_006ff710 + local_18 * 4 + arg1 * 2000);
      if ((arg2 == 0xffffffff) || ((arg2 & (byte)(&g_MasterCardColorTable)[iVar1 * 0x34]) != 0)) {
        iVar2 = abs((int)(char)(&DAT_0051aec0)[iVar1 * 0x34]);
        iVar1 = (char)(&DAT_0051aebf)[iVar1 * 0x34] * 3 + iVar2 * 2;
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


