/*
 * Decompiled function: FUN_00407747
 * Entry Point: 00407747
 * Size: 103 bytes
 */
#include "magic.h"


undefined4 FUN_00407747(int arg_1)

{
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (499 < local_8) {
      return 0;
    }
    if (*(int *)(&g_MasterCardTypeTable + (*(uint *)(&deck + local_8 * 4) & 0xfff) * 0x34) == arg_1)
    break;
    local_8 = local_8 + 1;
  }
  return 1;
}


