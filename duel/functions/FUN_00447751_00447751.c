/*
 * Decompiled function: FUN_00447751
 * Entry Point: 00447751
 * Size: 206 bytes
 */
#include "duel.h"


uint FUN_00447751(int arg1,int arg2)

{
  int iVar1;
  uint local_8;
  
  iVar1 = FUN_00446de2(arg1,arg2);
  if (iVar1 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    local_8 = *(uint *)(&DAT_0060165c + arg1 * 0x5b20 + arg2 * 0x120);
    if ((((&DAT_0060165e)[arg1 * 0x5b20 + arg2 * 0x120] & 0x20) != 0) &&
       (((&DAT_0060162c)[arg1 * 0x5b20 + arg2 * 0x120] & 4) != 0)) {
      local_8 = local_8 | 0x40;
    }
    if (local_8 == 0xffffffff) {
      local_8 = 0;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  }
  else {
    local_8 = 0;
  }
  return local_8;
}


