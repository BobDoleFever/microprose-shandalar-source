/*
 * Decompiled function: FUN_0048e01d
 * Entry Point: 0048e01d
 * Size: 132 bytes
 */
#include "magic.h"


uint FUN_0048e01d(void *arg1,uint arg2)

{
  uint uVar1;
  uint local_8;
  
  if (DAT_0054aab0 == 0) {
    local_8 = FUN_0048caf4(DAT_0054aab8,arg1,arg2);
  }
  else {
    uVar1 = _read(DAT_0054aab8,arg1,arg2);
    local_8 = (uint)(uVar1 == arg2);
  }
  if (local_8 == 0) {
    OutputDebugStringA(&DAT_00527e88);
  }
  return local_8;
}


