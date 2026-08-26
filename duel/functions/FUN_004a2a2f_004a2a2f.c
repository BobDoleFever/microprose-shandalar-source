/*
 * Decompiled function: FUN_004a2a2f
 * Entry Point: 004a2a2f
 * Size: 88 bytes
 */
#include "duel.h"


BOOL FUN_004a2a2f(void)

{
  BOOL BVar1;
  BOOL BVar2;
  
  BVar1 = IsWindowVisible(DAT_005dcd10);
  if (BVar1 == 0) {
    BVar2 = IsWindowVisible(DAT_00663df0);
    if (BVar2 != 0) {
      SendMessageA(DAT_00663df0,0x111,0x65,0);
    }
  }
  return BVar1;
}


