/*
 * Decompiled function: FUN_00448aa1
 * Entry Point: 00448aa1
 * Size: 81 bytes
 */
#include "duel.h"


bool FUN_00448aa1(undefined4 *arg_1)

{
  if (arg_1 != (undefined4 *)0x0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    *arg_1 = DAT_00615458;
    arg_1[1] = DAT_0061545c;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  }
  return arg_1 != (undefined4 *)0x0;
}


