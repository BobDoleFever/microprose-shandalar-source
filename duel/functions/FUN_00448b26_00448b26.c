/*
 * Decompiled function: FUN_00448b26
 * Entry Point: 00448b26
 * Size: 73 bytes
 */
#include "duel.h"


void FUN_00448b26(undefined4 *arg1,undefined4 *arg2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  if (arg1 != (undefined4 *)0x0) {
    *arg1 = DAT_0060cc74;
  }
  if (arg2 != (undefined4 *)0x0) {
    *arg2 = DAT_0060d490;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  return;
}


