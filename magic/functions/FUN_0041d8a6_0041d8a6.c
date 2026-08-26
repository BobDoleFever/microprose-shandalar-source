/*
 * Decompiled function: FUN_0041d8a6
 * Entry Point: 0041d8a6
 * Size: 156 bytes
 */
#include "magic.h"


int FUN_0041d8a6(int arg_1)

{
  int local_8;
  
  local_8 = g_MasterCardCount;
  while( true ) {
    if (g_MasterCardCount + 0x10 <= local_8) {
      Engine_ReportFatalError(s_AddType_error_00519bfc);
      return -1;
    }
    if (*(int *)(&g_MasterCardTypeTable + local_8 * 0x34) == -1) break;
    local_8 = local_8 + 1;
  }
  memcpy(&g_MasterCardTable + local_8 * 0x34,&g_MasterCardTable + arg_1 * 0x34,0x34);
  return local_8;
}


