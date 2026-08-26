/*
 * Decompiled function: FUN_0050b0fc
 * Entry Point: 0050b0fc
 * Size: 164 bytes
 */
#include "magic.h"


int FUN_0050b0fc(byte arg1,byte arg2)

{
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (499 < local_c) {
      return 0;
    }
    if (((*(int *)(&deck + local_c * 4) != -1) &&
        ((1 << (arg1 & 0x1f) &
         (int)(char)(&DAT_0051aebe)[(*(uint *)(&deck + local_c * 4) & 0xfff) * 0x34]) != 0)) &&
       ((arg2 & (&g_MasterCardColorTable)[(*(uint *)(&deck + local_c * 4) & 0xfff) * 0x34]) != 0))
    break;
    local_c = local_c + 1;
  }
  return local_c + 1;
}


