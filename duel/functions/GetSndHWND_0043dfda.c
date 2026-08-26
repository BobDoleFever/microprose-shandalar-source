/*
 * Decompiled function: GetSndHWND
 * Entry Point: 0043dfda
 * Size: 55 bytes
 */
#include "duel.h"


undefined4 GetSndHWND(void)

{
  undefined4 uVar1;
  
  if ((DAT_004f79a4 == 0) || (DAT_004f79a4 == 2)) {
    uVar1 = 0;
  }
  else {
    uVar1 = (*DAT_00694530)();
  }
  return uVar1;
}


