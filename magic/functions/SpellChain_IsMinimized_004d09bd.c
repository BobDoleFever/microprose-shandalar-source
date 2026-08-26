/*
 * Decompiled function: SpellChain_IsMinimized
 * Entry Point: 004d09bd
 * Size: 112 bytes
 */
#include "magic.h"


bool SpellChain_IsMinimized(void)

{
  BOOL BVar1;
  BOOL BVar2;
  
  BVar1 = IsWindowVisible(DAT_00565940);
  if ((BVar1 != 0) && (BVar2 = IsWindowVisible(DAT_006fe3fc), BVar2 == 0)) {
    SendMessageA(DAT_006fe3fc,0x111,0x66,0);
  }
  return BVar1 == 0;
}


