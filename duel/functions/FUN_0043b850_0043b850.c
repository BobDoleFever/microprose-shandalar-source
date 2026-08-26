/*
 * Decompiled function: FUN_0043b850
 * Entry Point: 0043b850
 * Size: 83 bytes
 */
#include "duel.h"


undefined4 FUN_0043b850(int arg_1)

{
  undefined4 uVar1;
  int local_7d8;
  undefined1 local_7d4 [2000];
  
  local_7d8 = FUN_00448653(local_7d4,arg_1);
  if (local_7d8 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = *(undefined4 *)(local_7d4 + local_7d8 * 4 + -4);
  }
  return uVar1;
}


