/*
 * Decompiled function: FUN_00433bb6
 * Entry Point: 00433bb6
 * Size: 131 bytes
 */
#include "duel.h"


uint FUN_00433bb6(void *arg1,uint arg2)

{
  uint uVar1;
  uint local_8;
  
  if (DAT_00515e80 == 0) {
    local_8 = FUN_00432c2a(DAT_00515e88,arg1,arg2);
  }
  else {
    uVar1 = __read(DAT_00515e88,arg1,arg2);
    local_8 = (uint)(uVar1 == arg2);
  }
  if (local_8 == 0) {
    OutputDebugStringA(s_SHIT_004f451c);
  }
  return local_8;
}


