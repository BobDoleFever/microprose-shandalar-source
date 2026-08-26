/*
 * Decompiled function: FUN_004a2a87
 * Entry Point: 004a2a87
 * Size: 112 bytes
 */
#include "duel.h"


bool FUN_004a2a87(void)

{
  BOOL BVar1;
  BOOL BVar2;
  
  BVar1 = IsWindowVisible(DAT_005dcd10);
  if ((BVar1 != 0) && (BVar2 = IsWindowVisible(DAT_00663df0), BVar2 == 0)) {
    SendMessageA(DAT_00663df0,0x111,0x66,0);
  }
  return BVar1 == 0;
}


