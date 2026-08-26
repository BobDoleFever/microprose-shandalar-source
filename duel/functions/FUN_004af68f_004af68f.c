/*
 * Decompiled function: FUN_004af68f
 * Entry Point: 004af68f
 * Size: 156 bytes
 */
#include "duel.h"


int FUN_004af68f(int arg_1)

{
  int local_8;
  
  local_8 = DAT_00665ed0;
  while( true ) {
    if (DAT_00665ed0 + 0x10 <= local_8) {
      FUN_004d7e62(s_AddType_error_00506570);
      return -1;
    }
    if (*(int *)(&DAT_004ff590 + local_8 * 0x34) == -1) break;
    local_8 = local_8 + 1;
  }
  FID_conflict__memcpy(&DAT_004ff580 + local_8 * 0x34,&DAT_004ff580 + arg_1 * 0x34,0x34);
  return local_8;
}


