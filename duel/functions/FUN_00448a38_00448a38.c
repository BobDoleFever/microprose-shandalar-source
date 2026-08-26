/*
 * Decompiled function: FUN_00448a38
 * Entry Point: 00448a38
 * Size: 53 bytes
 */
#include "duel.h"


void FUN_00448a38(undefined4 *arg_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  if (arg_1 != (undefined4 *)0x0) {
    *arg_1 = DAT_00601584;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  return;
}


