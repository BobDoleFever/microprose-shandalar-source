/*
 * Decompiled function: FUN_0044897a
 * Entry Point: 0044897a
 * Size: 73 bytes
 */
#include "duel.h"


void FUN_0044897a(undefined4 *arg1,undefined4 *arg2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  if (arg1 != (undefined4 *)0x0) {
    *arg1 = DAT_005f77e8;
  }
  if (arg2 != (undefined4 *)0x0) {
    *arg2 = DAT_006152e4;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  return;
}


